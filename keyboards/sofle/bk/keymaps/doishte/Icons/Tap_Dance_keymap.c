#include QMK_KEYBOARD_H
#include "oled.c"
#include "encoder.c"

// Tap dancing definitions
typedef enum {
//    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

// Tap dance enums
enum td_keycodes{
    TD_ALT,
    TD_SFT,
    TD_CTR
};

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Function to determine the current tapdance state
td_state_t cur_dance(qk_tap_dance_state_t *state);
// ALT
void td_alt_finished(qk_tap_dance_state_t *state, void *user_data);
void td_alt_reset(qk_tap_dance_state_t *state, void *user_data);
// Shift
void td_sft_finished(qk_tap_dance_state_t *state, void *user_data);
void td_sft_reset(qk_tap_dance_state_t *state, void *user_data);
// CTRL
void td_ctr_finished(qk_tap_dance_state_t *state, void *user_data);
void td_ctr_reset(qk_tap_dance_state_t *state, void *user_data);
// End Tap Dance definitions

//
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
  KC_1,     KC_2,   KC_3,    KC_4,    KC_5,    KC_6,                      KC_7,    KC_8,    KC_9,    KC_0,   KC_GRV,  KC_PIPE,
  KC_ESC,   KC_Q,   KC_D,    KC_R,    KC_W,    KC_B,                      KC_J,    KC_F,    KC_U,    KC_P,   KC_COLN, KC_QUOT,
  KC_TAB,   KC_A,   KC_S,    KC_H,    KC_T,    KC_G,                      KC_Y,    KC_N,    KC_E,    KC_O,   KC_I,    KC_BSPC,
  XXXXXXX,  KC_Z,   KC_X,    KC_M,    KC_C,    KC_V,   KC_MUTE,   KC_MPLY,KC_K,    KC_L,    KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,
                   TG(1),TD(TD_ALT),TD(TD_SFT), KC_ENT, MO(2),     MO(3),  KC_SPC,TD(TD_CTR),KC_RGUI, KC_F24
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
  KC_1,     KC_2,   KC_3,    KC_4,    KC_5,    KC_6,                       KC_7,    KC_8,    KC_9,    KC_0,   KC_GRV,  KC_PIPE,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_QUOT,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_BSPC,
  XXXXXXX,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   KC_MUTE,    KC_MPLY,KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,
                    _______, _______, _______, KC_ENT, _______,    _______,KC_SPC,  _______, KC_RGUI, KC_F24
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
  KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,    KC_6,                        KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_GRV,
  KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,                     KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, KC_DEL,
  XXXXXXX, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, XXXXXXX,   XXXXXXX, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, XXXXXXX,
                   _______, XXXXXXX, XXXXXXX, XXXXXXX, _______,   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
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
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,KC_F12,
  XXXXXXX,  XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX,                    KC_PGUP, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_GRV,
  KC_CAPS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_PGDN,  KC_LEFT,KC_DOWN, KC_RGHT, XXXXXXX, KC_DEL,
  XXXXXXX,  KC_UNDO, KC_CUT,  XXXXXXX, KC_COPY, KC_PASTE,XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, XXXXXXX,
                     _______, XXXXXXX, XXXXXXX, XXXXXXX, _______,  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)
};

// Tap dance
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        return TD_DOUBLE_SINGLE_TAP;
    } else return TD_UNKNOWN;
}
// ALT
void td_alt_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code16(KC_LPRN); break;
        case TD_SINGLE_HOLD: register_code16(KC_LALT); break;
        case TD_DOUBLE_SINGLE_TAP: register_code16(KC_RPRN); break;
        case TD_UNKNOWN: register_code16(KC_NO);
    }
}

void td_alt_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code16(KC_LPRN); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_RPRN); break;
        case TD_UNKNOWN: unregister_code16(KC_NO);
    }
}
// Shift
void td_sft_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code16(KC_LBRC); break;
        case TD_SINGLE_HOLD: register_code16(KC_LSFT); break;
        case TD_DOUBLE_SINGLE_TAP: register_code16(KC_RBRC); break;
        case TD_UNKNOWN: register_code16(KC_NO);
    }
}

void td_sft_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code16(KC_LBRC); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_LSFT); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_RBRC); break;
        case TD_UNKNOWN: unregister_code16(KC_NO);
    }
}
// Ctrl
void td_ctr_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code16(KC_LCBR); break;
        case TD_SINGLE_HOLD: register_code16(KC_RCTRL); break;
        case TD_DOUBLE_SINGLE_TAP: register_code16(KC_RCBR); break;
        case TD_UNKNOWN: register_code16(KC_NO);
    }
}

void td_ctr_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code16(KC_LCBR); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_RCTRL); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_RCBR); break;
        case TD_UNKNOWN: unregister_code16(KC_NO);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_alt_finished, td_alt_reset),
    [TD_SFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_sft_finished, td_sft_reset),
    [TD_CTR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_ctr_finished, td_ctr_reset)
};
