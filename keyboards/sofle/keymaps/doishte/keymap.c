#include QMK_KEYBOARD_H
#include "oled.c"
#include "encoder.c"

//Default keymap.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[0] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_PIPE,
  KC_ESC,   KC_Q,   KC_D,    KC_R,    KC_W,    KC_B,                      KC_J,    KC_F,    KC_U,    KC_P,   KC_COLN, KC_QUOT,
  KC_TAB,   KC_A,   KC_S,    KC_H,    KC_T,    KC_G,                      KC_Y,    KC_N,    KC_E,    KC_O,   KC_I,    KC_BSPC,
  KC_LCTRL, KC_Z,   KC_X,    KC_M,    KC_C,    KC_V,   KC_MUTE,   KC_MPLY,KC_K,    KC_L,    KC_COMM, KC_DOT, KC_SLSH, KC_RGUI,
                   KC_LGUI,  KC_LCTRL,KC_LALT, KC_ENT, MO(2),     MO(3),  KC_SPC,  KC_RSFT, KC_RCTRL, TG(1)
),
/*
 * WORKMAN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[1] = LAYOUT(
  _______,_______,_______,_______, _______, _______,                      _______,_______,  _______, _______,_______, _______,
  _______,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    _______,
  _______,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, _______,
  _______,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,_______,    _______, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, _______,
                 _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[2] = LAYOUT(
  XXXXXXX, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_F12,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_DEL,  KC_EXLM,KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX,   XXXXXXX, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_BSLS, XXXXXXX,
                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[3] = LAYOUT(
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX,                    KC_PGUP, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_GRV,
  KC_CAPS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_PGDN,  KC_LEFT,KC_DOWN, KC_RGHT, XXXXXXX, KC_DEL,
  XXXXXXX,  KC_UNDO, KC_CUT,  XXXXXXX, KC_COPY, KC_PASTE,XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, XXXXXXX,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)
};
/* UNICODES
alt crtl shift i => Mute microfone
ñ [UTF- 8 "C3 B1"] [Hex/UTF-32 "00F1"]
Ñ [UTF- 8 "C3 91"] [Hex/UTF-32 "00D1"]
ç [UTF- 8 "C3 A7"] [Hex/UTF-32 "00E7"]
Ç [UTF- 8 "C3 87"] [Hex/UTF-32 "00C7"]
¿ [UTF- 8 "C2 BF"] [Hex/UTF-32 "00BF"]
¡ [UTF- 8 "C2 A1"] [Hex/UTF-32 "00A1"]
*/
enum unicode_names {
    ENE_TILDE,
    BANG,
    IRONY,
    SNEK
};
const uint32_t PROGMEM unicode_map[] = {
    [ENE_TILDE] = 0x00f1,
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
};

// Combos

enum combos {
  FJ_ESC
};

const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  [FJ_ESC] = COMBO(fj_combo, KC_ESC)
};
