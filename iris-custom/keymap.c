#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"

#define LA_NAV MO(NAV)
#define LA_SYM MO(SYM)
#define LA_NUM MO(NUM)
#define LA_GAM TG(GAM)
#define LA_HRK TG(HRK)
#define CMD_ENT MT(MOD_LGUI,KC_ENT)

// shortcurts
#define WS_L A(S(KC_LEFT))  // select word left
#define WS_R A(S(KC_RIGHT)) // select word right
#define W_L A(KC_LEFT)      // move word left
#define W_R A(KC_RIGHT)     // move word right
#define BOOT QK_BOOTLOADER
// #define OS_CTRL OSM(MOD_LCTL)
// #define OS_SHFT OSM(MOD_LSFT)
// #define OS_ALT OSM(MOD_LALT)
// #define OS_CMD OSM(MOD_LGUI)

enum layers {
   DEF,
   HRK,
   GAM,
   NAV,
   SYM,
   NUM
};

enum keycodes {
   // Custom oneshot mod implementation with no timers.
   OS_SHFT = SAFE_RANGE,
   OS_CTRL,
   OS_ALT,
   OS_CMD,

   SW_WIN, // Switch to next window (cmd-tab)
};

// Left-hand home row mods
#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define GUI_K RGUI_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [DEF] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LA_HRK,          LA_GAM,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LA_NUM,  LA_NAV,  CMD_ENT,                   KC_SPC,  LA_SYM,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [HRK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  CTL_A,   ALT_S,   GUI_D,   SFT_F,   KC_G,                               KC_H,    SFT_J,   GUI_K,   ALT_L,   CTL_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,          LA_GAM, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LA_NUM,  LA_NAV,  KC_ENT,                   KC_SPC,   LA_SYM,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [GAM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,          _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_SPC,  KC_LCTL,                   KC_SPC,  LA_SYM,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     BOOT,    _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            WS_L,    KC_PGDN, KC_UP,   KC_PGUP, WS_R,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, OS_CTRL, OS_ALT,  OS_CMD,  OS_SHFT, _______,                            W_L,     KC_LEFT, KC_DOWN, KC_RIGHT,W_R,     _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, WS_L,    W_L,     W_R,     WS_R,    _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILDE,KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_LABK, KC_LCBR, KC_LPRN, KC_LBRC,                            KC_EQL,  _______, _______, KC_DQT,  KC_COLN, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_RABK, KC_RCBR, KC_RPRN, KC_RBRC, _______,          _______, KC_PLUS, _______, _______, _______, KC_MINS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,                            _______, KC_7,    KC_8,    KC_9,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MSTP, KC_VOLD, KC_VOLU, KC_MUTE, _______,                            _______, KC_4,    KC_5,    KC_6,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, KC_0,    _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case LA_NAV:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case LA_NAV:
        case KC_LSFT:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
            return true;
        default:
            return false;
    }
}

bool sw_win_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   update_swapper(&sw_win_active, KC_LGUI, KC_TAB, SW_WIN, keycode, record);

   update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
   update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
   update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
   update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode, record);

   return true;
}

// documentation: https://docs.qmk.fm/#/feature_eeprom

void keyboard_post_init_user(void) { // Call the keymap level matrix init.
    // Set default layer
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_BLUE);
    rgblight_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case HRK:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_homerowkeys_effect);
            break;
        // case SYM:
        //     rgblight_sethsv_noeeprom(HSV_RED);
        //     rgblight_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
        //     break;
        // case NUM:
        //     rgblight_sethsv_noeeprom(HSV_GREEN);
        //     rgblight_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
        //     break;
        case GAM:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_gamepad_effect);
            break;
        default: //  for any other layers, or the default layer
            rgblight_sethsv_noeeprom(HSV_CYAN);
            rgblight_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
            break;
    }
  return state;
}

void eeconfig_init_user(void) {  // EEPROM is getting reset!
    // use the non noeeprom versions, to write these values to EEPROM too
    rgblight_enable(); // Enable RGB by default
    rgblight_sethsv(HSV_BLUE);  // Set it to CYAN by default
    rgblight_mode(RGB_MATRIX_SOLID_REACTIVE_SIMPLE); // set to solid by default
}
