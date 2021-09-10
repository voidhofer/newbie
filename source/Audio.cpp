
#include "MicroBit.h"
#include "ContinuousAudioStreamer.h"
#include "DataStream.h"
#include "MemorySource.h"
#include "CodalUtil.h"
#include "nrf.h"
#include "NRF52PWM.h"
#include "StreamNormalizer.h"
#include "SerialStreamer.h"
#include "Synthesizer.h"
#include "SoundEmojiSynthesizer.h"
#include "SoundSynthesizerEffects.h"
#include "Tests.h"
#include "edge-impulse-sdk/classifier/ei_run_classifier.h"
#include "edge-impulse-sdk/dsp/numpy.hpp"

static MemorySource *sampleSource = NULL;
static NRF52PWM *speaker = NULL;
static StreamNormalizer *normalizer = NULL;
static Synthesizer* synth = NULL;

#define INFERENCING_KEYWORD "newbie"
#define INFERENCING_KEYWORD_HFV "homerseklet"
#define INFERENCING_KEYWORD_DK "dobokocka"
#define INFERENCING_KEYWORD_JTSZ "jatszunk"
#define INFERENCING_KEYWORD_SZ "szeretlek"

static NRF52ADCChannel *mic = NULL;
static ContinuousAudioStreamer *streamer = NULL;
static StreamNormalizer *processor = NULL;

static inference_t inference;

/**
 * Get raw audio signal data
 */
static int microphone_audio_signal_get_data(size_t offset, size_t length, float *out_ptr)
{
    numpy::int8_to_float(&inference.buffers[inference.buf_select ^ 1][offset], out_ptr, length);
    return 0;
}

void
listen_newbie() {
    if (mic == NULL){
        mic = uBit.adc.getChannel(uBit.io.microphone);
        mic->setGain(7,0);          // Uncomment for v1.47.2
        //mic->setGain(7,1);        // Uncomment for v1.46.2
    }

    // alloc inferencing buffers
    inference.buffers[0] = (int8_t *)malloc(EI_CLASSIFIER_SLICE_SIZE * sizeof(int8_t));

    if (inference.buffers[0] == NULL) {
        uBit.serial.printf("Failed to alloc buffer 1\n");
        return;
    }

    inference.buffers[1] = (int8_t *)malloc(EI_CLASSIFIER_SLICE_SIZE * sizeof(int8_t));

    if (inference.buffers[0] == NULL) {
        uBit.serial.printf("Failed to alloc buffer 2\n");
        free(inference.buffers[0]);
        return;
    }

    uBit.serial.printf("Allocated buffers\n");

    inference.buf_select = 0;
    inference.buf_count = 0;
    inference.n_samples = EI_CLASSIFIER_SLICE_SIZE;
    inference.buf_ready = 0;

    mic->output.setBlocking(true);

    if (processor == NULL)
        processor = new StreamNormalizer(mic->output, 0.15f, true, DATASTREAM_FORMAT_8BIT_SIGNED);

    if (streamer == NULL)
        streamer = new ContinuousAudioStreamer(processor->output, &inference);

    uBit.io.runmic.setDigitalValue(1);
    uBit.io.runmic.setHighDrive(true);

    uBit.serial.printf("Allocated everything else\n");

    // number of frames since we heard 'newbie'
    uint8_t last_keywords = 0b0;

    int heard_keyword_x_ago = 5;
    int lc = 0;
    while(lc <= 10000) {
        uBit.sleep(1);

        if (inference.buf_ready) {
            inference.buf_ready = 0;

            static int print_results = -(EI_CLASSIFIER_SLICES_PER_MODEL_WINDOW);

            signal_t signal;
            signal.total_length = EI_CLASSIFIER_SLICE_SIZE;
            signal.get_data = &microphone_audio_signal_get_data;
            ei_impulse_result_t result = { 0 };

            EI_IMPULSE_ERROR r = run_classifier_continuous(&signal, &result, false);
            if (r != EI_IMPULSE_OK) {
                ei_printf("ERR: Failed to run classifier (%d)\n", r);
                return;
            }

            if (++print_results >= 0) {
                // print the predictions
                ei_printf("Predictions (DSP: %d ms., Classification: %d ms.): \n", result.timing.dsp, result.timing.classification);
                for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
                    ei_printf("    %s: ", result.classification[ix].label);
                    ei_printf_float(result.classification[ix].value);
                    ei_printf("\n");
                    if (strcmp(result.classification[ix].label, INFERENCING_KEYWORD) == 0 && result.classification[ix].value > 0.6) {
                        display_wink();
                        say_hello();
                    }
                    if (strcmp(result.classification[ix].label, INFERENCING_KEYWORD_HFV) == 0 && result.classification[ix].value > 0.6) {
                        display_temperature();
                    }
                    if (strcmp(result.classification[ix].label, INFERENCING_KEYWORD_SZ) == 0 && result.classification[ix].value > 0.6) {
                        display_heart();
                    }
                    if (strcmp(result.classification[ix].label, INFERENCING_KEYWORD_DK) == 0 && result.classification[ix].value > 0.6) {
                        play_dice();
                    }
                    if (strcmp(result.classification[ix].label, INFERENCING_KEYWORD_JTSZ) == 0 && result.classification[ix].value > 0.6) {
                        play_coin();
                    }
                }
            }
        }
        lc++;
    }
}