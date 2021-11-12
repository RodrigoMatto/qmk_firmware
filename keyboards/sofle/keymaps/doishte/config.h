#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define EE_HANDS

//Add RGB underglow
#define RGB_DI_PIN D3
#define RGBLED_NUM 74
//#define RGBLED_SPLIT {37,37}
#define RGBLIGHT_ANIMATIONS
//#define RGBLIGHT_LIMIT_VAL 192
//combos
#define COMBO_COUNT 1
#define COMBO_TERM 200
//Tap dancing
//#define TAPPING_TERM 175
