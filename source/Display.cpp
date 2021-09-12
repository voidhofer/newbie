#include "MicroBit.h"
#include "Tests.h"

bool exitMenu2 = false;

const char * const tick_emoji ="\
    000,000,000,000,000\n\
    000,000,000,000,255\n\
    000,000,000,255,000\n\
    255,000,255,000,000\n\
    000,255,000,000,000\n";

const char * const cross_emoji ="\
    255,000,000,000,255\n\
    000,255,000,255,000\n\
    000,000,255,000,000\n\
    000,255,000,255,000\n\
    255,000,000,000,255\n";

const char * const heart_emoji ="\
    000,255,000,255,000\n\
    255,255,255,255,255\n\
    255,255,255,255,255\n\
    000,255,255,255,000\n\
    000,000,255,000,000\n";

const char * const sensor_emoji ="\
    255,255,255,000,000\n\
    000,000,000,255,000\n\
    255,255,000,000,255\n\
    000,000,255,000,255\n\
    255,000,255,000,255\n";

const char * const speaker_emoji ="\
    000,255,000,255,000\n\
    255,255,000,000,255\n\
    255,255,000,000,255\n\
    255,255,000,000,255\n\
    000,255,000,255,000\n";

const char * const black_emoji ="\
    000,000,000,000,000\n\
    000,000,000,000,000\n\
    000,000,000,000,000\n\
    000,000,000,000,000\n\
    000,000,000,000,000\n";

const char * const red_emoji ="\
    255,255,255,255,255\n\
    255,255,255,255,255\n\
    255,255,255,255,255\n\
    255,255,255,255,255\n\
    255,255,255,255,255\n";

const char * const normal_emoji ="\
    255,255,000,255,255\n\
    255,255,000,255,255\n\
    000,000,000,000,000\n\
    000,255,255,255,000\n\
    000,000,000,000,000\n";

const char * const blink_emoji ="\
    000,000,000,000,000\n\
    255,255,000,255,255\n\
    000,000,000,000,000\n\
    000,255,255,255,000\n\
    000,000,000,000,000\n";

const char * const wink_emoji ="\
    000,000,000,255,255\n\
    255,255,000,255,255\n\
    000,000,000,000,000\n\
    000,255,255,255,000\n\
    000,000,000,000,000\n";

const char * const sad_emoji ="\
    255,255,000,255,255\n\
    255,255,000,255,255\n\
    000,000,000,000,000\n\
    000,255,255,255,000\n\
    255,000,000,000,255\n";

const char * const cry_emoji ="\
    000,255,000,255,000\n\
    255,000,000,000,255\n\
    000,000,000,000,000\n\
    000,255,255,255,000\n\
    255,255,255,255,255\n";

const char * const smile_emoji ="\
    255,255,000,255,255\n\
    255,255,000,255,255\n\
    000,000,000,000,000\n\
    255,000,000,000,255\n\
    000,255,255,255,000\n";

const char * const laugh_emoji ="\
    255,255,000,255,255\n\
    255,255,000,255,255\n\
    000,000,000,000,000\n\
    255,255,255,255,255\n\
    000,255,255,255,000\n";

const char * const dice_one_emoji ="\
    000,000,000,000,000\n\
    000,000,000,000,000\n\
    000,000,255,000,000\n\
    000,000,000,000,000\n\
    000,000,000,000,000\n";

const char * const dice_two_emoji ="\
    000,000,000,000,000\n\
    000,255,000,000,000\n\
    000,000,000,000,000\n\
    000,000,000,255,000\n\
    000,000,000,000,000\n";

const char * const dice_three_emoji ="\
    255,000,000,000,000\n\
    000,000,000,000,000\n\
    000,000,255,000,000\n\
    000,000,000,000,000\n\
    000,000,000,000,255\n";

const char * const dice_four_emoji ="\
    255,000,000,000,255\n\
    000,000,000,000,000\n\
    000,000,000,000,000\n\
    000,000,000,000,000\n\
    255,000,000,000,255\n";

const char * const dice_five_emoji ="\
    255,000,000,000,255\n\
    000,000,000,000,000\n\
    000,000,255,000,000\n\
    000,000,000,000,000\n\
    255,000,000,000,255\n";

const char * const dice_six_emoji ="\
    255,000,000,000,255\n\
    000,000,000,000,000\n\
    255,000,000,000,255\n\
    000,000,000,000,000\n\
    255,000,000,000,255\n";

const char * const coin_heads_emoji ="\
    000,000,000,000,000\n\
    000,255,000,255,000\n\
    000,255,255,255,000\n\
    000,255,000,255,000\n\
    000,000,000,000,000\n";

const char * const coin_tails_emoji ="\
    000,000,000,000,000\n\
    000,255,255,255,000\n\
    000,000,255,000,000\n\
    000,000,255,000,000\n\
    000,000,000,000,000\n";

const char * const menu_emoji ="\
    255,255,000,255,255\n\
    255,255,000,255,255\n\
    000,000,000,000,000\n\
    000,000,000,000,000\n\
    000,000,000,000,000\n";

const char * const charge_empty_emoji ="\
    000,000,255,000,000\n\
    000,255,000,255,000\n\
    000,255,000,255,000\n\
    000,255,000,255,000\n\
    000,255,000,255,000\n";

const char * const charge_low_emoji ="\
    000,000,255,000,000\n\
    000,255,000,255,000\n\
    000,255,000,255,000\n\
    000,255,000,255,000\n\
    000,255,255,255,000\n";

const char * const charge_medium_emoji ="\
    000,000,255,000,000\n\
    000,255,000,255,000\n\
    000,255,000,255,000\n\
    000,255,255,255,000\n\
    000,255,255,255,000\n";

const char * const charge_high_emoji ="\
    000,000,255,000,000\n\
    000,255,000,255,000\n\
    000,255,255,255,000\n\
    000,255,255,255,000\n\
    000,255,255,255,000\n";

const char * const charge_full_emoji ="\
    000,000,255,000,000\n\
    000,255,255,255,000\n\
    000,255,255,255,000\n\
    000,255,255,255,000\n\
    000,255,255,255,000\n";

const char * const hot_emoji ="\
    255,255,000,255,255\n\
    255,255,000,255,255\n\
    000,000,000,000,000\n\
    000,255,255,255,000\n\
    000,000,000,255,000\n";

const char * const cold_emoji ="\
    255,255,000,255,255\n\
    255,255,000,255,255\n\
    000,000,000,000,000\n\
    000,255,000,255,000\n\
    255,000,255,000,255\n";

const char * const freeze_emoji ="\
    000,000,000,000,000\n\
    255,255,000,255,255\n\
    000,000,000,000,000\n\
    000,000,255,000,000\n\
    000,000,000,000,000\n";

Image tick(tick_emoji);
Image cross(cross_emoji);
Image sensor(sensor_emoji);
Image speaker(speaker_emoji);
Image black(black_emoji);
Image red(red_emoji);
Image heart(heart_emoji);
Image dice_one(dice_one_emoji);
Image dice_two(dice_two_emoji);
Image dice_three(dice_three_emoji);
Image dice_four(dice_four_emoji);
Image dice_five(dice_five_emoji);
Image dice_six(dice_six_emoji);
Image coin_heads(coin_heads_emoji);
Image coin_tails(coin_tails_emoji);
Image normal(normal_emoji);
Image blink(blink_emoji);
Image wink(wink_emoji);
Image sad(sad_emoji);
Image cry(cry_emoji);
Image smile(smile_emoji);
Image laugh(laugh_emoji);
Image menu(menu_emoji);
Image hot(hot_emoji);
Image cold(cold_emoji);
Image freezing(freeze_emoji);
Image charge_empty(charge_empty_emoji);
Image charge_low(charge_low_emoji);
Image charge_middle(charge_medium_emoji);
Image charge_high(charge_high_emoji);
Image charge_full(charge_full_emoji);

void
display_charge_empty() {
    uBit.display.print(charge_empty);
}

void
display_charge_low() {
    uBit.display.print(charge_low);
}

void
display_charge_middle() {
    uBit.display.print(charge_middle);
}

void
display_charge_high() {
    uBit.display.print(charge_high);
}

void
display_charge_full() {
    uBit.display.print(charge_full);
}

void
clear_display() {
    uBit.display.clear();
}

void display_hot() {
    uBit.display.print(hot);
    uBit.sleep(1000);
    display_mood(get_mood());
}

void display_cold() {
    uBit.display.print(cold);
    uBit.sleep(1000);
    display_mood(get_mood());
}

void display_freezing() {
    uBit.display.print(freezing);
    uBit.sleep(1000);
    display_mood(get_mood());
}

void display_shaken_happy() {
    display_laugh();
    uBit.sleep(1000);
    display_mood(get_mood());
}

void display_shaken_sad() {
    display_cry();
    uBit.sleep(1000);
    display_mood(get_mood());
}

void
display_tick()
{
    uBit.display.print(tick);
    uBit.sleep(1000);
}

void
display_cross()
{
    uBit.display.print(cross);
    uBit.sleep(1000);
}

void
display_red()
{
    uBit.display.print(red);
    uBit.sleep(1000);
}

void
display_black()
{
    uBit.display.print(black);
    uBit.sleep(1000);
}

void
display_sensor()
{
    uBit.display.print(sensor);
    uBit.sleep(1000);
}

void
display_speaker()
{
    uBit.display.print(speaker);
    uBit.sleep(1000);
}

void
display_heart()
{
    uBit.display.print(heart);
    uBit.sleep(1000);
}

void
display_coin_heads()
{
    uBit.display.print(coin_heads);
    uBit.sleep(1000);
}

void
display_coin_tails()
{
    uBit.display.print(coin_tails);
    uBit.sleep(1000);
}

void
display_dice_one()
{
    uBit.display.print(dice_one);
    uBit.sleep(1000);
}

void
display_dice_two()
{
    uBit.display.print(dice_two);
    uBit.sleep(1000);
}

void
display_dice_three()
{
    uBit.display.print(dice_three);
    uBit.sleep(1000);
}

void
display_dice_four()
{
    uBit.display.print(dice_four);
    uBit.sleep(1000);
}

void
display_dice_five()
{
    uBit.display.print(dice_five);
    uBit.sleep(1000);
}

void
display_dice_six()
{
    uBit.display.print(dice_six);
    uBit.sleep(1000);
}

void
display_normal()
{
    uBit.display.print(normal);
    uBit.sleep(1000);
}

void
display_smile()
{
    uBit.display.print(smile);
    uBit.sleep(1000);
}

void
display_laugh()
{
    uBit.display.print(laugh);
    uBit.sleep(1000);
}

void
display_sad()
{
    uBit.display.print(sad);
    uBit.sleep(1000);
}

void
display_cry()
{
    uBit.display.print(cry);
    uBit.sleep(1000);
}

void
display_wink()
{
    uBit.display.print(wink);
    uBit.sleep(500);
    uBit.display.print(normal);
}

void
display_blink()
{
    uBit.display.print(blink);
    uBit.sleep(200);
}

void
display_print(char character) {
    uBit.display.image.print(character);
    uBit.sleep(500);
}

void
display_scroll(char str[])
{
    uBit.display.scroll(str);
    uBit.sleep(2000);
}

void
display_mood(int mood) {
    if (mood == 0) {
        display_sad();
    } else if (mood == 1)
    {
        display_normal();
    } else if (mood == 2)
    {
        display_normal();
    } else if (mood == 3)
    {
        display_normal();
    } else if (mood == 4)
    {
        display_smile();
    }
    uBit.sleep(1000);
}

void return_menu_back(MicroBitEvent) {
    if (exitMenu2) {
        exitMenu2 = true;
        return;
    }
}

void display_menu_one() {
    uBit.display.print(1);
    while(1) {
        uBit.messageBus.listen(DEVICE_ID_BUTTON_AB, DEVICE_BUTTON_EVT_CLICK, return_menu_back);
        if (exitMenu2) {
            exitMenu2 = false;
            return;
        }
    }
}

void display_menu_two() {
    uBit.display.print(2);
    while(1) {
        uBit.messageBus.listen(DEVICE_ID_BUTTON_AB, DEVICE_BUTTON_EVT_CLICK, return_menu_back);
        if (exitMenu2) {
            exitMenu2 = false;
            return;
        }
    }
}

void display_menu_three() {
    uBit.display.print(3);
    while(1) {
        uBit.messageBus.listen(DEVICE_ID_BUTTON_AB, DEVICE_BUTTON_EVT_CLICK, return_menu_back);
        if (exitMenu2) {
            exitMenu2 = false;
            return;
        }
    }
}

void display_menu_four() {
    uBit.display.print(4);
    while(1) {
        uBit.messageBus.listen(DEVICE_ID_BUTTON_AB, DEVICE_BUTTON_EVT_CLICK, return_menu_back);
        if (exitMenu2) {
            exitMenu2 = false;
            return;
        }
    }
}

void display_menu_five() {
    uBit.display.print(5);
    while(1) {
        uBit.messageBus.listen(DEVICE_ID_BUTTON_AB, DEVICE_BUTTON_EVT_CLICK, return_menu_back);
        if (exitMenu2) {
            exitMenu2 = false;
            return;
        }
    }
}

void display_menu_six() {
    uBit.display.print(6);
    while(1) {
        uBit.messageBus.listen(DEVICE_ID_BUTTON_AB, DEVICE_BUTTON_EVT_CLICK, return_menu_back);
        if (exitMenu2) {
            exitMenu2 = false;
            return;
        }
    }
}

void display_menu_seven() {
    uBit.display.print(7);
    while(1) {
        uBit.messageBus.listen(DEVICE_ID_BUTTON_AB, DEVICE_BUTTON_EVT_CLICK, return_menu_back);
        if (exitMenu2) {
            exitMenu2 = false;
            return;
        }
    }
}

void display_menu_eight() {
    uBit.display.print(8);
    while(1) {
        uBit.messageBus.listen(DEVICE_ID_BUTTON_AB, DEVICE_BUTTON_EVT_CLICK, return_menu_back);
        if (exitMenu2) {
            exitMenu2 = false;
            return;
        }
    }
}

void display_menu_nine() {
    uBit.display.print(9);
    while(1) {
        uBit.messageBus.listen(DEVICE_ID_BUTTON_AB, DEVICE_BUTTON_EVT_CLICK, return_menu_back);
        if (exitMenu2) {
            exitMenu2 = false;
            return;
        }
    }
}

void display_menu_ten() {
    uBit.display.print(10);
    while(1) {
        uBit.messageBus.listen(DEVICE_ID_BUTTON_AB, DEVICE_BUTTON_EVT_CLICK, return_menu_back);
        if (exitMenu2) {
            exitMenu2 = false;
            return;
        }
    }
}

void
display_temperature() {
    uBit.display.scroll(uBit.thermometer.getTemperature());
    uBit.sleep(3000);
}

void set_menu_full() {
    uBit.display.image.setPixelValue(0,3,255);
    uBit.display.image.setPixelValue(1,3,255);
    uBit.display.image.setPixelValue(2,3,255);
    uBit.display.image.setPixelValue(3,3,255);
    uBit.display.image.setPixelValue(4,3,255);
    uBit.display.image.setPixelValue(0,4,255);
    uBit.display.image.setPixelValue(1,4,255);
    uBit.display.image.setPixelValue(2,4,255);
    uBit.display.image.setPixelValue(3,4,255);
    uBit.display.image.setPixelValue(4,4,255);
}

/*
void display_menu() {
    uBit.display.print(menu);
    uBit.sleep(3000);
    int menu_selected = 0;
    while(1) {
        if (uBit.buttonA.isPressed()) {
            set_menu_full();
            switch (menu_selected)
            {
            case 0:
                uBit.display.image.setPixelValue(0,3,0);
                while(1) {
                    if (uBit.buttonA.isPressed()) {
                        break;
                    } else if (uBit.buttonA.isPressed())
                    {
                        display_sensor();
                    } else if (uBit.buttonAB.isPressed()) {
                        return;
                    }
                }
                break;

            case 1:
                uBit.display.image.setPixelValue(1,3,0);
                while(1) {
                    if (uBit.buttonA.isPressed()) {
                        break;
                    } else if (uBit.buttonA.isPressed())
                    {
                        display_sensor();
                    } else if (uBit.buttonAB.isPressed()) {
                        return;
                    }
                }
                break;

            case 2:
                uBit.display.image.setPixelValue(2,3,0);
                while(1) {
                    if (uBit.buttonA.isPressed()) {
                        break;
                    } else if (uBit.buttonA.isPressed())
                    {
                        display_sensor();
                    } else if (uBit.buttonAB.isPressed()) {
                        return;
                    }
                }
                break;

            case 3:
                uBit.display.image.setPixelValue(3,3,0);
                while(1) {
                    if (uBit.buttonA.isPressed()) {
                        break;
                    } else if (uBit.buttonA.isPressed())
                    {
                        display_sensor();
                    } else if (uBit.buttonAB.isPressed()) {
                        return;
                    }
                }
                break;

            case 4:
                uBit.display.image.setPixelValue(4,3,0);
                while(1) {
                    if (uBit.buttonA.isPressed()) {
                        break;
                    } else if (uBit.buttonA.isPressed())
                    {
                        display_sensor();
                    } else if (uBit.buttonAB.isPressed()) {
                        return;
                    }
                }
                break;

            case 5:
                uBit.display.image.setPixelValue(0,4,0);
                while(1) {
                    if (uBit.buttonA.isPressed()) {
                        break;
                    } else if (uBit.buttonA.isPressed())
                    {
                        display_sensor();
                    } else if (uBit.buttonAB.isPressed()) {
                        return;
                    }
                }
                break;

            case 6:
                uBit.display.image.setPixelValue(1,4,0);
                while(1) {
                    if (uBit.buttonA.isPressed()) {
                        break;
                    } else if (uBit.buttonA.isPressed())
                    {
                        display_sensor();
                    } else if (uBit.buttonAB.isPressed()) {
                        return;
                    }
                }
                break;

            case 7:
                uBit.display.image.setPixelValue(2,4,0);
                while(1) {
                    if (uBit.buttonA.isPressed()) {
                        break;
                    } else if (uBit.buttonA.isPressed())
                    {
                        display_sensor();
                    } else if (uBit.buttonAB.isPressed()) {
                        return;
                    }
                }
                break;

            case 8:
                uBit.display.image.setPixelValue(3,4,0);
                while(1) {
                    if (uBit.buttonA.isPressed()) {
                        break;
                    } else if (uBit.buttonA.isPressed())
                    {
                        display_sensor();
                    } else if (uBit.buttonAB.isPressed()) {
                        return;
                    }
                }
                break;

            case 9:
                uBit.display.image.setPixelValue(4,4,0);
                while(1) {
                    if (uBit.buttonA.isPressed()) {
                        break;
                    } else if (uBit.buttonA.isPressed())
                    {
                        display_sensor();
                    } else if (uBit.buttonAB.isPressed()) {
                        return;
                    }
                }
                break;
            
            default:
                break;
            }
            if (menu_selected < 10 ) {
                menu_selected++;
            } else {
                menu_selected = 0;
            }
            
        }
        if (uBit.buttonAB.isPressed()) {
            return;
        }
    }
}
*/