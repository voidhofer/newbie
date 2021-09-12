#include "MicroBit.h"
#include "Tests.h"

// Create a global instance of the MicroBit model called uBit.
// Allows this singleton to be accessed consistently by tests/programs.

#ifdef MICROBIT_UBIT_AS_STATIC_OBJECT
// A statically allocated model can be simply created using the code below.
// This is the simplest, and ideal for C/C++ programs.
MicroBit uBit;

#else
// Alternatively, we can dynamically allocated the model on te heap.
// This is better for testing builds for environments that do this (such as MakeCode)
MicroBit &uBit = *(new MicroBit());
#endif

// set variables
int stats_mood = 3;
int stats_charge = 4;
int stats_bored = 0;

bool menuOpened = false;

int
get_charge() {
    return stats_charge;
}

void
increase_charge() {
    stats_charge = 4;
}

int
get_mood() {
    return stats_mood;
}

void
increase_mood() {
    if (stats_mood < 4) {
        stats_mood++;
    }
}

void
onEvent(MicroBitEvent e) {
    if (!menuOpened) 
    {
        if (e.value == 1)
        {
            // random chance to gain boredom point every hour
            int rn = rand() % 2; 
            if (rn < 2) {
                stats_bored++;
            }
            // random chance to loose mood depending on boredom
            if (stats_bored == 4)
            {
                rn = rand() % 2; 
                if (rn < 2) {
                    stats_mood--;
                }
            }
            else if (stats_bored == 3)
            {
                rn = rand() % 2; 
                if (rn < 2) {
                    stats_mood--;
                }
            }
            
        } else if (e.value == 2)
        {
            // temperature based reactions
            int temp = uBit.thermometer.getTemperature();
            int rn3 = rand() % 20;
            if (rn3 < 2) {
                if (temp > 35) {
                    // hot
                    display_hot();
                } else if (temp > 18) {
                    // ideal
                    if (rand() % 100 < 2) {
                        stats_mood++;
                    }
                } else if (temp > 10) {
                    // cold
                    display_cold();
                } else {
                    // freezing cold
                    display_freezing();
                }
            } 
            // chance for emotion events depending on mood
            if (stats_mood > 3)
            {
                int rn2 = (rand() % 10);
                if (rn2 < 2) {
                    display_laugh();
                    uBit.sleep(1000);
                    display_normal();
                    uBit.sleep(500);
                    display_normal();
                    uBit.sleep(500);
                    beep_happy();
                }
                
            }
            else if (stats_mood > 2)
            {
                int rn2 = (rand() % 10);
                if (rn2 < 2) {
                    display_smile();
                    beep_happy();
                    uBit.sleep(1000);
                }            
            }
            else if (stats_mood == 1)
            {
                int rn2 = (rand() % 10);
                if (rn2 < 2) {
                    beep_sad();
                    display_sad();
                    uBit.sleep(1000);
                }            
            }
            else
            {
                int rn2 = (rand() % 10);
                if (rn2 < 2) {
                    display_cry();
                    uBit.sleep(1000);
                    display_sad();
                    uBit.sleep(500);
                    display_cry();
                    uBit.sleep(1000);
                    beep_sad();
                }            
            }
            if (stats_mood > 1) {
                // chance for random events depending on boredom
                if (stats_bored == 4)
                {
                    // random chance to sing, play by itself, yawn
                }
                else if (stats_bored == 3)
                {
                    // random chance to sing, yawn
                }
                else if (stats_bored == 2)
                {
                    // random chance to talk
                }
                else if (stats_bored == 1)
                {
                    // random chance to talk (less chance)
                }
                else if (stats_bored == 0)
                {
                    // random chance to talk (the least chance)
                }
            }
            else 
            {
                // random chance to angry mumbling
            }
        } 
        else if (e.value == 3)
        {
            // sec timer
        }
    }
}

void detect_shake(MicroBitEvent) {
    if (rand() % 4 < 3) {
        display_shaken_happy();
        beep_yes();
        stats_mood++;
        stats_bored=stats_bored-1;
    } else {
        beep_no();
        display_shaken_sad();
        stats_mood=stats_mood-1;
        stats_bored=stats_bored-1;
    }
}

void
timer() {
    timer_loop();
}

void
call_menu(MicroBitEvent) {
    beep_short();
    if (!menuOpened) {
        menuOpened = true;
        display_menu();
        menuOpened = false;
    }
    return;
}

int
main()
{
    uBit.sleep(100);
    uBit.init();

    DMESG("---- START ----\n");

    // main loop
    beep_hello();
    create_fiber(timer);
    create_fiber(listen_newbie);
    uBit.messageBus.listen(55005, 1, onEvent, MESSAGE_BUS_LISTENER_DROP_IF_BUSY);
    uBit.messageBus.listen(55005, 2, onEvent, MESSAGE_BUS_LISTENER_DROP_IF_BUSY);
    uBit.messageBus.listen(55005, 3, onEvent, MESSAGE_BUS_LISTENER_DROP_IF_BUSY);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, call_menu);
    uBit.messageBus.listen(MICROBIT_ID_GESTURE, MICROBIT_ACCELEROMETER_EVT_SHAKE, detect_shake);
    while (1) {
        display_mood(stats_mood);
        uBit.sleep(200);
        int randomNumber = rand() % 10; 
        if (randomNumber < 3) {
            display_blink();
            uBit.sleep(200);
            display_mood(stats_mood);
            uBit.sleep(500);
        }
        uBit.sleep(100);
    }
    release_fiber();
}
