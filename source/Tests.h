#include "MicroBit.h"
#include "CodalDmesg.h"

#ifndef MB_NEXT_TESTS_H
#define MB_NEXT_TESTS_H

//#define MICROBIT_UBIT_AS_STATIC_OBJECT

#ifdef MICROBIT_UBIT_AS_STATIC_OBJECT
extern MicroBit uBit;
#else
extern MicroBit& uBit;
#endif

void listen_newbie();
void display_cross();
void display_tick();
void display_heart();
void display_print();
void display_scroll(char []);
void display_red();
void display_black();
void display_sensor();
void display_speaker();
void display_normal();
void display_smile();
void display_laugh();
void display_sad();
void display_cry();
void display_blink();
void display_wink();
void display_mood(int);
void display_dice_one();
void display_dice_two();
void display_dice_three();
void display_dice_four();
void display_dice_five();
void display_dice_six();
void display_coin_heads();
void display_coin_tails();
void timer_loop();
void say_hello();
void display_temperature();
void play_dice();
void play_coin();
void synthesizer_test();
void sound_emoji_test();
void say_hello();
void say_beep_1();
void display_menu();

#endif
