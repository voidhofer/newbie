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

void
onEvent(MicroBitEvent e) {
    if (e.value == 0)
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
        
    } else if (e.value == 1)
    {
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
            }
            
        }
        else if (stats_mood > 2)
        {
            int rn2 = (rand() % 10);
            if (rn2 < 2) {
                display_smile();
                uBit.sleep(1000);
            }            
        }
        else if (stats_mood == 1)
        {
            int rn2 = (rand() % 10);
            if (rn2 < 2) {
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
    else if (e.value == 2)
    {
        // sec timer
    }
}

void
timer() {
    timer_loop();
}

void call_menu(MicroBitEvent) {
    display_menu();
}

int
main()
{
    uBit.sleep(100);
    uBit.init();

    DMESG("---- START ----\n");

    // main loop
    create_fiber(timer);
    create_fiber(listen_newbie);
    uBit.messageBus.listen(55005, 0, onEvent);
    uBit.messageBus.listen(55005, 1, onEvent);
    uBit.messageBus.listen(55005, 2, onEvent);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, call_menu);
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
