#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NAV,
    _SYMB,
    _NUM,
    _FUNC,
    _SYS
};

enum keycode_aliases {
    // Left Hand
    HRM_A = LGUI_T(KC_A),
    HRM_S = LALT_T(KC_S),
    HRM_D = LSFT_T(KC_D),
    HRM_F = LCTL_T(KC_F),

    // Right Hand
    HRM_J    = RCTL_T(KC_J),
    HRM_K    = RSFT_T(KC_K),
    HRM_L    = LALT_T(KC_L),
    HRM_SCLN = RGUI_T(KC_SEMICOLON),
};

// enum combos {
//     ASD_TILDE,
// };

// const uint16_t PROGMEM asd_tilde[] = {KC_A, KC_S, COMBO_END};

// combo_t key_combos[] = {
    //     [ASD_TILDE] = COMBO_ACTION(asd_tilde),
// };

// void process_combo_event(uint16_t combo_index, bool pressed) {
//     switch(combo_index) {
//         case ASD_TILDE:
//             if (pressed) {
//                 tap_code16(S(KC_GRAVE));
//                 tap_code16(KC_A);
//             }
//         break;
//     }
// }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGui | LALT | NAV  | /Space  /       \Enter \  |BackSP| SYMB | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_BASE] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,  HRM_A,  HRM_S,   HRM_D,   HRM_F,   KC_G,                     KC_H,    HRM_J,   HRM_K,   HRM_L,   HRM_SCLN, KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  MO(_SYS),
                        MO(_NUM), KC_LALT, MO(_NAV), KC_SPC, KC_ENTER, KC_BSPC, MO(_SYMB), MO(_FUNC)
),
/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |      | Home |  Up  |  End |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down | Right |     |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|      |Delete|      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NAV] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, KC_PSCR,
  _______, _______, C(KC_W), _______, C(KC_R), C(KC_T),                  KC_PGUP,    KC_HOME, KC_UP,   KC_END,  _______, _______,
  _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                  KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,   _______, _______,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______,_______,  _______,  _______, KC_DELETE, _______,  _______, _______, _______,
                        _______, _______, _______,  _______,   _______,  _______, _______, _______
),
/* SYMB
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   ~  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYMB] = LAYOUT(
  XXXXXXX, _______, _______, _______, _______, _______,                   _______, _______,   S(KC_EQL),_______,   _______, KC_BSLS,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   S(KC_7), S(KC_COMM),KC_EQL, S(KC_DOT), KC_PIPE,  S(KC_3),
  XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                   KC_LBRC, S(KC_9), KC_COLN, S(KC_0), KC_RBRC, S(KC_5),
  _______, _______, _______, _______, _______, _______, _______, _______, S(KC_4), KC_LCBR, S(KC_8), KC_RCBR, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, XXXXXXX
),

[_NUM] = LAYOUT(
UG_NEXT, RGB_M_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, KC_ASTR, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_DOT,  KC_7,    KC_8,    KC_9,    KC_MINS, XXXXXXX,
XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                   KC_COMM, KC_4,    KC_5,    KC_6,    KC_PLUS, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOT, KC_1, KC_2,    KC_3,        _______,  XXXXXXX,
                            _______, _______, _______, KC_SPC, KC_ENTER,  KC_BSPC, KC_0, _______
),

[_FUNC] = LAYOUT(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,                   XXXXXXX, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, XXXXXXX,
XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                            XXXXXXX, XXXXXXX, XXXXXXX, CW_TOGG, XXXXXXX,  XXXXXXX, XXXXXXX, _______
),

[_SYS] = LAYOUT(
QK_BOOT, EE_CLR, QK_RBT, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, RM_NEXT, RM_PREV, QK_RBT, EE_CLR, QK_BOOT,
XXXXXXX, XXXXXXX, XXXXXXX, RM_SATD, RM_SATU, RM_OFF,                   XXXXXXX, RM_HUEU, RM_HUED, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, RM_VALD, RM_VALU, RM_ON,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
)

//     [_FUNC] = LAYOUT(
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
//   ),
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _NAV, _SYMB, _NUM);
// }

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
// const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_write_P("Layer: ", false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln(PSTR("Base"), false);
            break;
        case _NAV:
            oled_write_ln(PSTR("Navigation"), false);
            break;
        case _SYMB:
            oled_write_ln(PSTR("Symbol"), false);
            break;
        case _NUM:
            oled_write_ln(PSTR("Numbers"), false);
            break;
        case _FUNC:
            oled_write_ln(PSTR("Functions"), false);
            break;
        case _SYS:
            oled_write_ln(PSTR("System"), false);
            break;
        default:
            oled_write_ln(PSTR("undfined"), false);
            break;
    }
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_keylog(), false);
    // oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    // oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }

    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
