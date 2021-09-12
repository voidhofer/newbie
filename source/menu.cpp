#include "MicroBit.h"
#include "Tests.h"

bool exitMenu = false;
int menuItem = 0;

void
choose_menuItem() {
    switch (menuItem) {
        case 0:
            beep_yes();
            switch (get_charge()) {
                case 0:
                    display_charge_empty();
                    uBit.sleep(5000);
                    break;
                case 1:
                    display_charge_low();
                    uBit.sleep(5000);
                    break;
                case 2:
                    display_charge_middle();
                    uBit.sleep(5000);
                    break;
                case 3:
                    display_charge_high();
                    uBit.sleep(5000);
                    break;
                case 4:
                    display_charge_full();
                    uBit.sleep(5000);
                    break;
                default:
                    display_black();
                    uBit.sleep(1000);
            }
            display_mood(get_mood());
            uBit.sleep(5000);
            exitMenu = true;
            break;
        case 1:
            beep_happy();
            uBit.display.print("F");
            increase_charge();
            uBit.sleep(3000);
            exitMenu = true;
            break;
        case 2:
            beep_yes();
            uBit.display.print("P");
            increase_mood();
            uBit.sleep(3000);
            exitMenu = true;
            break;
        case 3:
            beep_yes();
            play_coin();
            uBit.sleep(1000);
            exitMenu = true;
            break;
        case 4:
            beep_yes();
            display_red();
            uBit.sleep(1000);
            exitMenu = true;
            break;
        case 5:
            beep_yes();
            display_red();
            uBit.sleep(1000);
            exitMenu = true;
            break;
        case 6:
            beep_yes();
            display_red();
            uBit.sleep(1000);
            exitMenu = true;
            break;
        case 7:
            beep_yes();
            //call_invaders();
            uBit.sleep(1000);
            exitMenu = true;
            break;
        case 8:
            beep_yes();
            display_red();
            uBit.sleep(1000);
            exitMenu = true;
            break;
        case 9:
            beep_yes();
            display_red();
            uBit.sleep(1000);
            exitMenu = true;
            break;
        default:
            break;
    }
}

void
menu_onButtonA(MicroBitEvent) {
    beep_short();
    if (menuItem < 9) {
        menuItem++;
    } else {
        menuItem = 0;
    }
    return;
}

void
menu_onButtonB(MicroBitEvent) {
    exitMenu = true;
    choose_menuItem();
    return;
}

void
menu_onButtonAB(MicroBitEvent) {
    beep_no();
    exitMenu = true;
    return;
}

void
display_menu() {
    menuItem = 0;
    exitMenu = false;
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonA, MESSAGE_BUS_LISTENER_DROP_IF_BUSY);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonB);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonAB);
    while(1) {
        uBit.sleep(1);
        if (exitMenu) {
            exitMenu = false;
            break;
        }
        switch (menuItem) {
            case 0:
                uBit.display.print(1);
                uBit.sleep(100);
                break;
            case 1:
                uBit.display.print(2);
                uBit.sleep(100);
                break;
            case 2:
                uBit.display.print(3);
                uBit.sleep(100);
                break;
            case 3:
                uBit.display.print(4);
                uBit.sleep(100);
                break;
            case 4:
                uBit.display.print(5);
                uBit.sleep(100);
                break;
            case 5:
                uBit.display.print(6);
                uBit.sleep(100);
                break;
            case 6:
                uBit.display.print(7);
                uBit.sleep(100);
                break;
            case 7:
                uBit.display.print(8);
                uBit.sleep(100);
                break;
            case 8:
                uBit.display.print(9);
                uBit.sleep(100);
                break;
            case 9:
                uBit.display.print(10);
                uBit.sleep(100);
                break;
            default:
                break;
        }
    }
    uBit.messageBus.ignore(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonA);
    uBit.messageBus.ignore(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonB);
    uBit.messageBus.ignore(MICROBIT_ID_BUTTON_AB, MICROBIT_BUTTON_EVT_DOWN, menu_onButtonAB);
    return;
}