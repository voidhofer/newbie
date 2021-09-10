#include "MicroBit.h"
#include "Tests.h"

bool exitMenu = false;
int menuItem = 0;

void
choose_menuItem(int mi) {
    switch (mi) {
        case 0:
            display_red();
            uBit.sleep(1000);
            display_black();
            uBit.sleep(1000);
            uBit.display.print(1);
            uBit.sleep(1000);
            break;
        case 1:
            display_red();
            uBit.sleep(1000);
            display_black();
            uBit.sleep(1000);
            uBit.display.print(2);
            break;
        case 2:
            display_red();
            uBit.sleep(1000);
            display_black();
            uBit.sleep(1000);
            uBit.display.print(3);
            break;
        case 3:
            play_coin();
            uBit.sleep(1000);
            break;
        case 4:
            display_red();
            uBit.sleep(1000);
            display_black();
            uBit.sleep(1000);
            uBit.display.print(5);
            break;
        case 5:
            display_red();
            uBit.sleep(1000);
            display_black();
            uBit.sleep(1000);
            uBit.display.print(6);
            break;
        case 6:
            display_red();
            uBit.sleep(1000);
            display_black();
            uBit.sleep(1000);
            uBit.display.print(7);
            break;
        case 7:
            play_dice();
            uBit.sleep(1000);
            break;
        case 8:
            display_red();
            uBit.sleep(1000);
            display_black();
            uBit.sleep(1000);
            uBit.display.print(9);
            break;
        case 9:
            display_red();
            uBit.sleep(1000);
            display_black();
            uBit.sleep(1000);
            uBit.display.print(10);
            break;
        default:
            break;
    }
}

void
menu_onButtonA(MicroBitEvent) {
    if (menuItem < 9) {
        menuItem++;
    } else {
        menuItem = 0;
    }
    return;
}

void
menu_onButtonB(MicroBitEvent) {
    choose_menuItem(menuItem);
    exitMenu = true;
    return;
}

void
menu_onButtonAB(MicroBitEvent) {
    exitMenu = true;
    return;
}

void
display_menu() {
    while(1) {
        uBit.sleep(1);
        if (exitMenu) {
            exitMenu = false;
            return;
        }
        switch (menuItem) {
            case 0:
                uBit.display.print(1);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonA);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonB);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonAB);
                break;
            case 1:
                uBit.display.print(2);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonA);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonB);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonAB);
                break;
            case 2:
                uBit.display.print(3);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonA);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonB);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonAB);
                break;
            case 3:
                uBit.display.print(4);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonA);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonB);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonAB);
                break;
            case 4:
                uBit.display.print(5);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonA);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonB);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonAB);
                break;
            case 5:
                uBit.display.print(6);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonA);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonB);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonAB);
                break;
            case 6:
                uBit.display.print(7);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonA);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonB);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonAB);
                break;
            case 7:
                uBit.display.print(8);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonA);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonB);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonAB);
                break;
            case 8:
                uBit.display.print(9);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonA);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonB);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonAB);
                break;
            case 9:
                uBit.display.print(10);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonA);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonB);
                uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonAB);
                break;
            default:
                break;
        }
    }
}