#include "mitosis.h"

enum mitosis_mod {
  SHF = 0,
  SYM = 1,
  NAV = 2,
};

enum mitosis_kc {
  MKC_SHF = SAFE_RANGE + SHF,
  MKC_SYM = SAFE_RANGE + SYM,
  MKC_NAV = SAFE_RANGE + NAV,
};

// All layers have the same 2 thumb rows:
//     |   |   |   |   |    |   |   |   |   |
//     |   |   |WIN|CTR|    |SHF|ALT|   |   |
//
// base layer
// | q | w | f | p | b |    | j | l | u | y | x |
// | a | r | s | t | g |    | m | n | e | i | o |
// |NAV| z | c | d | v |    | k | h |spc| . |SYM|
//
// Shift
// | Q | W | F | P | B |    | J | L | U | Y | X |
// | A | R | S | T | G |    | M | N | E | I | O |
// |NAV| Z | C | D | V |    | K | H |spc| , |SYM|
//
// Sym
// | ~ | @ | # | $ | % |    | ^ | & | * |   |xxx|
// | ` | : | ( | ) | - |    | + | " | ! | ? |xxx|
// |NAV| ; | < | > | _ |    | = | ' |spc| / |SYM|
//
// Sym + Shift
// |   |   |   |   |   |    | . | 7 | 8 | 9 |xxx|
// |   |   | { | } | | |    | + | 4 | 5 | 6 |xxx|
// |NAV|   | [ | ] | \ |    | 0 | 1 | 2 | 3 |SYM|
//
// Nav
// |xxx|PSc|esc|   | v+|    |men|hom| aU|end|ins|
// |xxx|   |   |tab| v-|    |pgu| aL| aD| aR|   |
// |NAV|   |bak|fwd|mut|    |pgd|bck|ent|del|SYM|
//
// Nav + Sym
// |xxx| f1| f2| f3| f4|    |   |   |msU|   |   |
// |xxx| f5| f6| f7| f8|    | wu|msL|msD|msR|   |
// |NAV| f9|f10|f11|f12|    | wd|lbm|mbm|rbm|SYM|
//

#define ___x___ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // base layer
  [0] = {
    {KC_Q      , KC_W      , KC_F      , KC_P      , KC_B      ,       KC_J      , KC_L      , KC_U      , KC_Y      , KC_X       },
    {KC_A      , KC_R      , KC_S      , KC_T      , KC_G      ,       KC_M      , KC_N      , KC_E      , KC_I      , KC_O       },
    {MKC_NAV   , KC_Z      , KC_C      , KC_D      , KC_V      ,       KC_K      , KC_H      , KC_SPC    , KC_DOT    , MKC_SYM    },
    {___x___   , ___x___   , ___x___   , ___x___   , ___x___   ,       ___x___   , ___x___   , ___x___   , ___x___   , ___x___    },
    {___x___   , ___x___   , ___x___   , KC_LGUI   , KC_LCTL   ,       MKC_SHF   , KC_LALT   , ___x___   , ___x___   , ___x___    }},
  // Shift
  [(1 << SHF)] = {
    {S(KC_Q)   , S(KC_W)   , S(KC_F)   , S(KC_P)   , S(KC_B)   ,       S(KC_J)   , S(KC_L)   , S(KC_U)   , S(KC_Y)   , S(KC_X)    },
    {S(KC_A)   , S(KC_R)   , S(KC_S)   , S(KC_T)   , S(KC_G)   ,       S(KC_M)   , S(KC_N)   , S(KC_E)   , S(KC_I)   , S(KC_O)    },
    {MKC_NAV   , S(KC_Z)   , S(KC_C)   , S(KC_D)   , S(KC_V)   ,       S(KC_K)   , S(KC_H)   , KC_SPC    , KC_COMM   , MKC_SYM    },
    {___x___   , ___x___   , ___x___   , ___x___   , ___x___   ,       ___x___   , ___x___   , ___x___   , ___x___   , ___x___    },
    {___x___   , ___x___   , ___x___   , KC_LGUI   , KC_LCTL   ,       MKC_SHF   , KC_LALT   , ___x___   , ___x___   , ___x___    }},
  // Sym
  [(1 << SYM)] = {
    {KC_TILD   , KC_AT   ,   KC_HASH   , KC_DLR   ,  KC_PERC   ,       KC_CIRC   , KC_AMPR   , KC_ASTR   , ___x___   , ___x___    },
    {KC_GRV    , KC_COLN   , KC_LPRN   , KC_RPRN   , KC_MINS   ,       KC_PLUS   , KC_DQUO   , KC_EXLM   , KC_QUES   , ___x___    },
    {MKC_NAV   , KC_SCLN   , KC_LABK   , KC_RABK   , KC_UNDS   ,       KC_PEQL   , KC_QUOT   , KC_SPC   ,  KC_SLSH   , MKC_SYM    },
    {___x___   , ___x___   , ___x___   , ___x___   , ___x___   ,       ___x___   , ___x___   , ___x___   , ___x___   , ___x___    },
    {___x___   , ___x___   , ___x___   , KC_LGUI   , KC_LCTL   ,       MKC_SHF   , KC_LALT   , ___x___   , ___x___   , ___x___    }},
  // Sym + Shift
  [(1 << SYM) | (1 << SHF)] = {
    {___x___   , ___x___   , ___x___   , ___x___   , ___x___   ,       KC_DOT    , KC_7      , KC_8      , KC_9      , ___x___    },
    {___x___   , ___x___   , KC_LCBR   , KC_RCBR   , KC_PIPE   ,       KC_PLUS   , KC_4      , KC_5      , KC_6      , ___x___    },
    {MKC_NAV   , ___x___   , KC_LBRC   , KC_RBRC   , KC_BSLS   ,       KC_0      , KC_1      , KC_2      , KC_3      , MKC_SYM    },
    {___x___   , ___x___   , ___x___   , ___x___   , ___x___   ,       ___x___   , ___x___   , ___x___   , ___x___   , ___x___    },
    {___x___   , ___x___   , ___x___   , KC_LGUI   , KC_LCTL   ,       MKC_SHF   , KC_LALT   , ___x___   , ___x___   , ___x___    }},
  // Nav
  [(1 << NAV)] = {
    {___x___   , KC_PSCR   , KC_ESC    , ___x___   , KC_VOLU   ,       KC_MENU   , KC_HOME   , KC_UP     , KC_END    , KC_INS     },
    {___x___   , ___x___   , ___x___   , KC_TAB    , KC_VOLD   ,       KC_PGUP   , KC_LEFT   , KC_DOWN   , KC_RGHT   , ___x___    }, // TODO 5x acceleration
    {MKC_NAV   , ___x___   , KC_WBAK   , KC_WFWD   , KC_MUTE   ,       KC_PGDN   , KC_BSPC   , KC_ENT    , KC_DEL    , MKC_SYM    }, // TODO more media buttons
    {___x___   , ___x___   , ___x___   , ___x___   , ___x___   ,       ___x___   , ___x___   , ___x___   , ___x___   , ___x___    },
    {___x___   , ___x___   , ___x___   , KC_LGUI   , KC_LCTL   ,       MKC_SHF   , KC_LALT   , ___x___   , ___x___   , ___x___    }},
  // Nav + Shift
  [(1 << NAV) | (1 << SHF)] = {
    {S(___x___), S(KC_PSCR), S(KC_ESC) , S(___x___), S(KC_VOLU),       S(KC_MENU), S(KC_HOME), S(KC_UP)  , S(KC_END) , S(KC_INS)  },
    {S(___x___), S(___x___), S(___x___), S(KC_TAB) , S(KC_VOLD),       S(KC_PGUP), S(KC_LEFT), S(KC_DOWN), S(KC_RGHT), S(___x___) }, // TODO 5x acceleration
    {S(MKC_NAV), S(___x___), S(KC_WBAK), S(KC_WFWD), S(KC_MUTE),       S(KC_PGDN), S(KC_BSPC), S(KC_ENT) , S(KC_DEL) , S(MKC_SYM) }, // TODO more media buttons
    {S(___x___), S(___x___), S(___x___), S(___x___), S(___x___),       S(___x___), S(___x___), S(___x___), S(___x___), S(___x___) },
    {S(___x___), S(___x___), S(___x___), S(KC_LGUI), S(KC_LCTL),       S(MKC_SHF), S(KC_LALT), S(___x___), S(___x___), S(___x___) }},
  // Nav + Sym
  [(1 << NAV) | (1 << SYM)] = {
    {___x___   , KC_F1     , KC_F2     , KC_F3     , KC_F4     ,       ___x___   , ___x___   , KC_MS_U   , ___x___   , ___x___    },
    {___x___   , KC_F5     , KC_F6     , KC_F7     , KC_F8     ,       KC_WH_U   , KC_MS_L   , KC_MS_D   , KC_MS_R   , ___x___    },
    {MKC_NAV   , KC_F9     , KC_F10    , KC_F11    , KC_F12    ,       KC_WH_D   , KC_BTN1   , KC_BTN2   , KC_BTN3   , MKC_SYM    },
    {___x___   , ___x___   , ___x___   , ___x___   , ___x___   ,       ___x___   , KC_ACL2   , KC_ACL1   , ___x___   , ___x___    }, // TODO move ACLx to long press
    {___x___   , ___x___   , ___x___   , KC_LGUI   , KC_LCTL   ,       MKC_SHF   , KC_LALT   , KC_ACL0   , ___x___   , ___x___    }},
  // Nav + Sym + Shift
  [(1 << NAV) | (1 << SYM) | (1 << SHF)] = {
    {S(___x___), S(KC_F1)  , S(KC_F2)  , S(KC_F3)  , S(KC_F4)  ,       S(___x___), S(___x___), S(KC_MS_U), S(___x___), S(___x___) },
    {S(___x___), S(KC_F5)  , S(KC_F6)  , S(KC_F7)  , S(KC_F8)  ,       S(KC_WH_U), S(KC_MS_L), S(KC_MS_D), S(KC_MS_R), S(___x___) },
    {S(MKC_NAV), S(KC_F9)  , S(KC_F10) , S(KC_F11) , S(KC_F12) ,       S(KC_WH_D), S(KC_BTN1), S(KC_BTN2), S(KC_BTN3), S(MKC_SYM) },
    {S(___x___), S(___x___), S(___x___), S(___x___), S(___x___),       S(___x___), S(KC_ACL2), S(KC_ACL1), S(___x___), S(___x___) }, // TODO move ACLx to long press
    {S(___x___), S(___x___), S(___x___), S(KC_LGUI), S(KC_LCTL),       S(MKC_SHF), S(KC_LALT), S(KC_ACL0), S(___x___), S(___x___) }},
};

static bool mod_state[3] = {0, 0, 0};  // indexed with mitosis_mod

uint16_t current_layer(void) {
  return (mod_state[SHF] << SHF) | (mod_state[SYM] << SYM) | (mod_state[NAV] << NAV);
}

bool process_record_user(uint16_t kc, keyrecord_t *record) {
  kc -= SAFE_RANGE;
  if (kc >= 3) return true;
  layer_off(current_layer());
  mod_state[kc] = record->event.pressed;
  layer_on(current_layer());
  return false;
}
