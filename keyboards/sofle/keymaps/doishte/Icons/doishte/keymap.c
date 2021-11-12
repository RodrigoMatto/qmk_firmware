#include QMK_KEYBOARD_H
#include "oled.c"
#include "encoder.c"

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    ST_M_ñ
};

// Variables
int word_length_count = 0;
int last_word_length=0;


 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * WORKMAN
 *     ,-----------------------------------------.                                    ,-----------------------------------------.
 *     |  `   |   1  |   2  |   3  |   4  |   5  |                                    |   6  |   7  |   8  |   9  |   0  |  `   |
 *     |------+------+------+------+------+------|                                    |------+------+------+------+------+------|
 *     | ESC  |   Q  |   D  |   R  |   W  |   B  |                                    |   J  |   F  |   U  |   P  |   ;  | Bspc |
 *     |------+------+------+------+------+------|                                    |------+------+------+------+------+------|
 *     | Tab  |   A  |   S  |   D  |   T  |   G  |-------.                    ,-------|   Y  |   N  |   E  |   O  |   I  |  \   |
 *     |------+------+------+------+------+------|       |                    |       |------+------+------+------+------+------|
 *     |LShift|   Z  |   X  |   M  |   C  |   V  |-------|                    |-------|   K  |   L  |   ,  |   .  |   /  |  ''  |
 *     `-----------------------------------------/       /                     \      \-----------------------------------------'
 *                | LGUI | LAlt | LCTR |LOWER | /Enter  /                       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *                |      |      |      |      |/       /                         \      \ |      |      |      |      |
 *                `----------------------------------'                            '------''---------------------------'
 */

[_LAYER0] = LAYOUT(
  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,                             KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
  KC_GESC, KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,                               KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_BSPC,
  KC_TAB,  KC_A,    KC_S,    KC_H,    KC_T,    KC_G,                               KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_BSLS,
  KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_MUTE,    C(A(S(KC_I)),  KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
                    KC_LGUI, KC_LALT, KC_LCTL, MO(1),   KC_ENT,           KC_SPC,  MO(2),   KC_RCTL, KC_RALT, KC_RGUI
                   ),
/*
 *     ,-----------------------------------------.                                    ,-----------------------------------------.
 *     |  `   |   1  |   2  |   3  |   4  |   5  |                                    |   6  |   7  |   8  |   9  |   0  |  `   |
 *     |------+------+------+------+------+------|                                    |------+------+------+------+------+------|
 *     | ESC  |   Q  |   D  |   R  |   W  |   B  |                                    |   J  |   F  |   U  |   P  |   ;  | Bspc |
 *     |------+------+------+------+------+------|                                    |------+------+------+------+------+------|
 *     | Tab  |   A  |   S  |   D  |   T  |   G  |-------.                    ,-------|   Y  |   N  |   E  |   O  |   I  |  \   |
 *     |------+------+------+------+------+------|       |                    |       |------+------+------+------+------+------|
 *     |LShift|   Z  |   X  |   M  |   C  |   V  |-------|                    |-------|   K  |   L  |   ,  |   .  |   /  |  ''  |
 *     `-----------------------------------------/       /                     \      \-----------------------------------------'
 *                | LGUI | LAlt | LCTR |LOWER | /Enter  /                       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *                |      |      |      |      |/       /                         \      \ |      |      |      |      |
 *                `----------------------------------'                            '------''---------------------------'
 */

[_LAYER1] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                               KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                                KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,                             KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS,           KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, MO(3),   KC_TRNS, KC_TRNS, KC_TRNS
                  ),
/*
 *     ,-----------------------------------------.                                    ,-----------------------------------------.
 *     |  `   |   1  |   2  |   3  |   4  |   5  |                                    |   6  |   7  |   8  |   9  |   0  |  `   |
 *     |------+------+------+------+------+------|                                    |------+------+------+------+------+------|
 *     | ESC  |   Q  |   D  |   R  |   W  |   B  |                                    |   J  |   F  |   U  |   P  |   ;  | Bspc |
 *     |------+------+------+------+------+------|                                    |------+------+------+------+------+------|
 *     | Tab  |   A  |   S  |   D  |   T  |   G  |-------.                    ,-------|   Y  |   N  |   E  |   O  |   I  |  \   |
 *     |------+------+------+------+------+------|       |                    |       |------+------+------+------+------+------|
 *     |LShift|   Z  |   X  |   M  |   C  |   V  |-------|                    |-------|   K  |   L  |   ,  |   .  |   /  |  ''  |
 *     `-----------------------------------------/       /                     \      \-----------------------------------------'
 *                | LGUI | LAlt | LCTR |LOWER | /Enter  /                       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *                |      |      |      |      |/       /                         \      \ |      |      |      |      |
 *                `----------------------------------'                            '------''---------------------------'
 */

[_LAYER2] = LAYOUT(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,                             KC_PGUP, KC_TRNS, KC_UP,   KC_TRNS, KC_INS,  KC_TRNS,
  KC_TRNS, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                             KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_TRNS,
  KC_TRNS, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_HOME, KC_TRNS, KC_END,  KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, MO(3),   KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
                  ),
/*
 *     ,-----------------------------------------.                                    ,-----------------------------------------.
 *     |  `   |   1  |   2  |   3  |   4  |   5  |                                    |   6  |   7  |   8  |   9  |   0  |  `   |
 *     |------+------+------+------+------+------|                                    |------+------+------+------+------+------|
 *     | ESC  |   Q  |   D  |   R  |   W  |   B  |                                    |   J  |   F  |   U  |   P  |   ;  | Bspc |
 *     |------+------+------+------+------+------|                                    |------+------+------+------+------+------|
 *     | Tab  |   A  |   S  |   D  |   T  |   G  |-------.                    ,-------|   Y  |   N  |   E  |   O  |   I  |  \   |
 *     |------+------+------+------+------+------|       |                    |       |------+------+------+------+------+------|
 *     |LShift|   Z  |   X  |   M  |   C  |   V  |-------|                    |-------|   K  |   L  |   ,  |   .  |   /  |  ''  |
 *     `-----------------------------------------/       /                     \      \-----------------------------------------'
 *                | LGUI | LAlt | LCTR |LOWER | /Enter  /                       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *                |      |      |      |      |/       /                         \      \ |      |      |      |      |
 *                `----------------------------------'                            '------''---------------------------'
 */

[_LAYER3] = LAYOUT(
  RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                               KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                               KC_NO,   KC_MUTE, KC_VOLU, KC_MSTP, KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                               KC_NO,   KC_MPRV, KC_VOLD, KC_MNXT, KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
              )

};

// RGB
void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

//RGB colours definition                   hsv             // rgb
#define KM_Light_red        {0,223,252}     // 252,32,31
#define KM_Light_yellow     {31,208,234}    // 234,181,42
#define KM_dirty_green      {97,231,230}    // 21,230,76
#define LM_golden_yellow    {32,191,236}    // 236,191,59
#define LM_Slight_dark_red  {255,246,238}   // 238,8,23
#define LM_Blue             {166,240,228}   // 13,41,228
#define LM_LightOrange      {0,183,238}     // 238,67,66
#define LM_Cyan             {130,255,255}   // 0,249,255
#define LM_Yellow           {42,248,240}    // 240,237,6
#define LM_______           {0,0,0}         // no colour
#define LM_Light_pink       {216,123,238}   // 238,122,235
#define LM_White            {0,0,255}       // 255,255,255
#define LM_Red_Blood        {6,240,224}     // 224,43,13
#define LM_NeonGreen        {82,247,246}    // 28,246,7
#define LM_LighterBlue      {178,231,238}   // 53,22,238
#define LM_darker_Yellow    {36,230,248}    // 248,213,24
#define LM_Light_orange     {31,255,255}    // 255,186,0
#define LM_Blooder_Red      {0,242,205}     // 205,11,10
#define LM_LightBrown       {19,150,185}    // 185,125,75
#define LM_Orange           {13,237,253}    // 253,90,17
#define LM_skyBlue          {124,62,253}    // 190,253,246
#define LM_Toirquise        {115,255,248}   // 0,248,169
#define LM_Purple           {195,255,251}   // 136,0,251
#define LM_Light_blue_purple {178,183,238}  // 92,66,238


#define KM_TEST {214,253,245} //pink


// Combos

/*
enum combo_events {
    COMBO_START_WORD,
    COMBO_DELETE_WORD
};

const uint16_t PROGMEM combo_start_word[] = {KC_N, KC_GESC, COMBO_END};
const uint16_t PROGMEM combo_delete_word[] = {KC_T, KC_BSPC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [COMBO_START_WORD] = COMBO_ACTION(combo_start_word),
    [COMBO_DELETE_WORD] = COMBO_ACTION(combo_delete_word)
};

void process_combo_event(uint16_t combo_index, bool pressed) {

        switch(combo_index) {
        case COMBO_START_WORD:
            if (pressed) {
                last_word_length = last_word_length / 2;
                while (last_word_length > 0){
                    tap_code16(KC_LEFT);
                    last_word_length--;
                }
            }
        break;
        case COMBO_DELETE_WORD:
            if (pressed) {
                last_word_length = last_word_length / 2;
                while (last_word_length > 0){
                    tap_code16(KC_BSPACE);
                    last_word_length--;
                }
            }
        break;
        }
}*/

/* UNICODES
alt crtl shift i => Mute microfone
ñ [UTF- 8 "C3 B1"] [Hex/UTF-32 "00F1"]
Ñ [UTF- 8 "C3 91"] [Hex/UTF-32 "00D1"]
ç [UTF- 8 "C3 A7"] [Hex/UTF-32 "00E7"]
Ç [UTF- 8 "C3 87"] [Hex/UTF-32 "00C7"]
¿ [UTF- 8 "C2 BF"] [Hex/UTF-32 "00BF"]
¡ [UTF- 8 "C2 A1"] [Hex/UTF-32 "00A1"]
*/


// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Word length calculation
    if(keycode >= 4 && keycode <= 39){
        word_length_count++;
    }else{
        last_word_length = word_length_count;
        word_length_count = 0;
    }
switch (keycode) {
case ST_M_ñ:
        if (record->event.pressed) {
            send_unicode_hex_string("00F1");
        } else {
        }
        break;
  }
  return true;
}
