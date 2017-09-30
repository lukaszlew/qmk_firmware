#include "mitosis.h"

enum layers {
  L_BASE,
  L_SHF,
  L_SYM,
  L_SYM_SHF,
  L_NAV,
  L_SYM_NAV,
};

enum mitosis_keycodes {
  MKC_SYM = SAFE_RANGE,
  MKC_NAV,
  MKC_SHF
};

#define ___x___ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = {
    {KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,          KC_J,    KC_L,    KC_U,    KC_Y,    KC_X    },
    {KC_A,    KC_R,    KC_S,    KC_T,    KC_G,          KC_M,    KC_N,    KC_E,    KC_I,    KC_O    },
    {MKC_NAV, KC_Z,    KC_C,    KC_D,    KC_V,          KC_K,    KC_H,    KC_SPC,  KC_DOT,  MKC_SYM },
    {___x___, ___x___, ___x___, ___x___, ___x___,       ___x___, ___x___, ___x___, ___x___, ___x___ },
    {___x___, ___x___, ___x___, KC_LGUI, KC_LCTL,       MKC_SHF, KC_LALT, ___x___, ___x___, ___x___ }
  },
  // SHIFT
  [L_SHF] = {
    {S(KC_Q), S(KC_W), S(KC_F), S(KC_P), S(KC_B),       S(KC_J), S(KC_L), S(KC_U), S(KC_Y), S(KC_X) },
    {S(KC_A), S(KC_R), S(KC_S), S(KC_T), S(KC_G),       S(KC_M), S(KC_N), S(KC_E), S(KC_I), S(KC_O) },
    {MKC_NAV, S(KC_Z), S(KC_C), S(KC_D), S(KC_V),       S(KC_K), S(KC_H), KC_SPC , KC_COMM, MKC_SYM },
    {___x___, ___x___, ___x___, ___x___, ___x___,       ___x___, ___x___, ___x___, ___x___, ___x___ },
    {___x___, ___x___, ___x___, KC_LGUI, KC_LCTL,       MKC_SHF, KC_LALT, ___x___, ___x___, ___x___ }
  },
  // SYMBOLS
  [L_SYM] = {
    {KC_TILD, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, ___x___, ___x___ },
    {KC_GRV,  KC_COLN, KC_LPRN, KC_RPRN, KC_MINS,       KC_PLUS, KC_DQUO, KC_EXLM, KC_QUES, ___x___ },
    {MKC_NAV, KC_SCLN, ___x___, ___x___, KC_UNDS,       KC_PEQL, KC_QUOT, KC_SPC,  KC_SLSH, MKC_SYM },
    {___x___, ___x___, ___x___, ___x___, ___x___,       ___x___, ___x___, ___x___, ___x___, ___x___ },
    {___x___, ___x___, ___x___, KC_LGUI, KC_LCTL,       MKC_SHF, KC_LALT, ___x___, ___x___, ___x___ }
  },
  // SYMBOL SHIFT
  [L_SYM_SHF] = {
    {___x___, ___x___, KC_LABK, KC_RABK, ___x___,       KC_DOT , KC_7   , KC_8   , KC_9   , ___x___ },
    {___x___, ___x___, KC_LCBR, KC_RCBR, KC_PIPE,       KC_PLUS, KC_4   , KC_5   , KC_6   , ___x___ },
    {MKC_NAV, ___x___, KC_LBRC, KC_RBRC, KC_BSLS,       KC_0   , KC_1   , KC_2   , KC_3   , MKC_SYM },
    {___x___, ___x___, ___x___, ___x___, ___x___,       ___x___, ___x___, ___x___, ___x___, ___x___ },
    {___x___, ___x___, ___x___, KC_LGUI, KC_LCTL,       MKC_SHF, KC_LALT, ___x___, ___x___, ___x___ }
  },
  [L_NAV] = {
    {___x___, KC_PSCR, KC_ESC , ___x___, KC_VOLU,       KC_MENU, KC_HOME, KC_UP  , KC_END , KC_INS  },
    {___x___, ___x___, ___x___, KC_TAB , KC_VOLD,       KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, ___x___ }, // TODO 5x acceleration
    {MKC_NAV, ___x___, KC_WBAK, KC_WFWD, KC_MUTE,       KC_PGDN, KC_BSPC, KC_ENT , KC_DEL , MKC_SYM }, // TODO more media buttons
    {___x___, ___x___, ___x___, ___x___, ___x___,       ___x___, ___x___, ___x___, ___x___, ___x___ },
    {___x___, ___x___, ___x___, KC_LGUI, KC_LCTL,       MKC_SHF, KC_LALT, ___x___, ___x___, ___x___ }
  },
  [L_SYM_NAV] = {
    {___x___, KC_F1  , KC_F2  , KC_F3  , KC_F4  ,       ___x___, ___x___, KC_MS_U, ___x___, ___x___ },
    {___x___, KC_F5  , KC_F6  , KC_F7  , KC_F8  ,       KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, ___x___ },
    {MKC_NAV, KC_F9  , KC_F10 , KC_F11 , KC_F12 ,       KC_WH_D, KC_BTN1, KC_BTN2, KC_BTN3, MKC_SYM },
    {___x___, ___x___, ___x___, ___x___, ___x___,       ___x___, KC_ACL2, KC_ACL1, ___x___, ___x___ }, // TODO move ACLx to long press
    {___x___, ___x___, ___x___, KC_LGUI, KC_LCTL,       MKC_SHF, KC_LALT, KC_ACL0, ___x___, ___x___ }
  },
};

void update_layer_state(enum layers layer, uint32_t is_on) {
  if (is_on) {
    layer_on(layer);
  } else {
    layer_off(layer);
  }
}

static bool shf_pressed = 0;
static bool sym_pressed = 0;
static bool nav_pressed = 0;



void update_all_layers(void) {
  update_layer_state(L_BASE, true);
  update_layer_state(L_SHF, shf_pressed);
  update_layer_state(L_SYM, sym_pressed);
  update_layer_state(L_SYM_SHF, sym_pressed && shf_pressed);
  update_layer_state(L_NAV, nav_pressed);
  update_layer_state(L_SYM_NAV, sym_pressed && nav_pressed);
  // Apply LSFT uniformly to nav layers instead of using S() macro
  if (nav_pressed) {
    if (shf_pressed) {
      register_code(KC_LSFT);
    } else {
      unregister_code(KC_LSFT);
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case MKC_SYM:
    sym_pressed = record->event.pressed;
    break;
  case MKC_NAV:
    nav_pressed = record->event.pressed;
    break;
  case MKC_SHF:
    shf_pressed = record->event.pressed;
    break;
  default:
    return true;
  }
  update_all_layers();
  return false;
}
