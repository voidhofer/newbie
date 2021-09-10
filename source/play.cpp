#include "MicroBit.h"
#include "Tests.h"

void
play_dice() {
    int randomNum = (rand() % 60);
    if (randomNum < 10) {
        display_dice_one();
    } 
    else if (randomNum < 20)
    {
        display_dice_two();
    }
    else if (randomNum < 30)
    {
        display_dice_three();
    }
    else if (randomNum < 40)
    {
        display_dice_four();
    }
    else if (randomNum < 50)
    {
        display_dice_five();
    }
    else if (randomNum < 60)
    {
        display_dice_six();
    }
    
}

void
play_coin() {
    bool playerTip = true;
    while (1) {
        if (uBit.buttonA.isPressed()) {
            playerTip = true;
            break;
        }
        if (uBit.buttonB.isPressed()) {
            playerTip = false;
            break;
        }
        uBit.sleep(100);
    }
    if ((rand() % 100) > 50) {
        display_coin_heads();
        if (playerTip) {
            display_tick();
            uBit.sleep(1000);
        } else {
            display_cross();
            uBit.sleep(2000);
        }
    } else {
        display_coin_tails();
        if (!playerTip) {
            display_tick();
            uBit.sleep(1000);
        } else {
            display_cross();
            uBit.sleep(2000);
        }
    }
}