#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _MEDIA,
    _CT,
    _LAYERS,
    _NUM,
    _GRV,
    _EMPTY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
 *                         ┌───┬───┬───┬───┬───┬───┬───┐                              ┌───┬───┬───┬───┬───┬───┬───┐
 *                         │ESC│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │                              │ 7 │ 8 │ 9 │ 0 │ - │ = │   │
 *                         ├───┼───┼───┼───┼───┼───┼───┤                              ├───┼───┼───┼───┼───┼───┼───┤
 *                         │tab│ q │ w │ e │ r │ t │FN │                              │ y │ u │ i │ o │ p │ [ │ ] │
 *                         ├───┼───┼───┼───┼───┼───┼───┤                              ├───┼───┼───┼───┼───┼───┼───┤
 *                         │ CT│ a │ s │ d │ f │ g │LAY│                              │ h │ j │ k │ l │ ; │ ' │ \ │
 *                         ├───┼───┼───┼───┼───┼───┼───┤                              ├───┼───┼───┼───┼───┼───┴───┤
 *                         │ sh│ z │ x │ c │ v │ b │num│                              │ n │ m │ , │ . │ / │  <-   │
 *                         ├───┴┬──┴─┬─┴──┬┴─┬─┴──┬┴───┤                              ├───┴┬──┴─┬─┴───┴───┼───────┤
 *                         │ctrl│ Win│menu│  │alt │spac│                              │ent │del │         │       │
 *                         └────┴────┴────┘  └────┴────┘                              └────┴────┘         └───────┘
     */
    [_BASE] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,            KC_7,    KC_8,   KC_9,   KC_0,   KC_MINS,    KC_EQL,    KC_NO,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    MO(_MEDIA),      KC_Y,    KC_U,   KC_I,   KC_O,   KC_P,       KC_LBRC,   KC_RBRC,
        MO(_CT), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    TG(_LAYERS),     KC_H,    KC_J,   KC_K,   KC_L,   KC_SCLN,    KC_QUOT,   KC_BSLS,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    MO(_NUM),        KC_N,    KC_M,   KC_COMM,KC_DOT, KC_SLSH,        KC_BSPC,
        KC_LCTL,  KC_LGUI,  LT(_GRV,KC_APP),     KC_LALT,     KC_SPC,          KC_ENT,  KC_DEL,                                 KC_DEL
    ),

    /*
 *                               ┌────┬───┬───┬───┬───┬───┬───┐               ┌────┬────┬───┬───┬───┬───┬───┐
 *                               │boot│   │   │   │   │   │   │               │vUP │fUP │   │   │   │   │rbt│
 *                               ├────┼───┼───┼───┼───┼───┼───┤               ├────┼────┼───┼───┼───┼───┼───┤
 *                               │    │   │   │   │   │   │FN │               │vDN │fDN │   │   │   │   │   │
 *                               ├────┼───┼───┼───┼───┼───┼───┤               ├────┼────┼───┼───┼───┼───┼───┤
 *                               │    │   │   │   │   │   │   │               │    │    │   │   │   │   │   │
 *                               ├────┼───┼───┼───┼───┼───┼───┤               ├────┼────┼───┼───┼───┼───┴───┤
 *                               │    │   │   │   │   │   │   │               │prev│next│   │   │   │cur del│
 *                               ├────┴┬──┴─┬─┴──┬┴─┬─┴──┬┴───┤               ├────┴┬───┴─┬─┴───┴───┼───────┤
 *                               │     │    │    │  │prev│mute│               │play │next │         │show fb│
 *                               └─────┴────┴────┘  └────┴────┘               └─────┴─────┘         └───────┘
     */
    [_MEDIA] = LAYOUT(
        QK_BOOT, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,           KC_VOLU,      MEH(KC_PPLS),  KC_NO,   KC_NO,  KC_NO,  KC_NO,  QK_RBT,
        KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  TG(_MEDIA),      KC_VOLD,      MEH(KC_PMNS),  KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,           KC_NO,        KC_NO,         KC_CALC, KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,           MEH(KC_LEFT), MEH(KC_RGHT),  KC_NO,   KC_NO,  KC_NO,     MEH(KC_BSPC),
        KC_NO,   KC_NO,   KC_NO,             KC_MPRV,    KC_MUTE,         KC_MPLY,       KC_MNXT,                                  MEH(KC_DEL)
    ),

    /*
 *                         ┌───┬───┬───┬───┬───┬───┬───┐                              ┌───┬────┬────┬────┬────┬───┬───┐
 *                         │esc│F1 │F2 │F3 │F4 │F5 │F6 │                              │F7 │ F8 │ F9 │F10 │F11 │F12│scr│
 *                         ├───┼───┼───┼───┼───┼───┼───┤                              ├───┼────┼────┼────┼────┼───┼───┤
 *                         │tab│   │   │   │   │   │   │                              │   │left│ up │rght│pgUP│   │   │
 *                         ├───┼───┼───┼───┼───┼───┼───┤                              ├───┼────┼────┼────┼────┼───┼───┤
 *                         │ CT│   │   │   │   │   │   │                              │   │left│down│rght│    │   │   │
 *                         ├───┼───┼───┼───┼───┼───┼───┤                              ├───┼────┼────┼────┼────┼───┴───┤
 *                         │ sh│   │   │   │   │   │   │                              │   │home│    │end │pgDW│   <-  │
 *                         ├───┴┬──┴─┬─┴──┬┴─┬─┴──┬┴───┤                              ├───┴┬───┴─┬──┴────┴────┼───────┤
 *                         │ctrl│ Win│menu│  │alt │spac│                              │ent │ del │            │       │
 *                         └────┴────┴────┘  └────┴────┘                              └────┴─────┘            └───────┘
     */
    [_CT] = LAYOUT(
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,  KC_F8,      KC_F9,   KC_F10,     KC_F11,  KC_F12, KC_PSCR,
        KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,  C(KC_LEFT), KC_UP,   C(KC_RGHT), KC_PGUP, KC_NO,  KC_NO,
        TG(_CT),  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,  KC_LEFT,    KC_DOWN, KC_RGHT,    KC_NO,   KC_NO,  KC_NO,
        KC_TRNS,  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,  KC_HOME,    KC_NO,   KC_END,     KC_PGDN,     KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,             KC_TRNS,   KC_TRNS,      KC_TRNS,     KC_TRNS,                                  KC_NO
    ),


    /*
 *                          ┌───┬───┬───┬───┬───┬───┬───┐                            ┌───┬────┬────┬────┬────┬───┬───┐
 *                          │   │   │   │   │   │   │   │                            │   │    │    │    │    │   │scr│
 *                          ├───┼───┼───┼───┼───┼───┼───┤                            ├───┼────┼────┼────┼────┼───┼───┤
 *                          │   │   │   │   │   │   │FN │                            │   │    │ up │    │wh u│   │   │
 *                          ├───┼───┼───┼───┼───┼───┼───┤                            ├───┼────┼────┼────┼────┼───┼───┤
 *                          │ CT│   │   │   │   │   │   │                            │   │left│down│rght│midl│   │   │
 *                          ├───┼───┼───┼───┼───┼───┼───┤                            ├───┼────┼────┼────┼────┼───┴───┤
 *                          │   │   │   │   │   │   │num│                            │   │    │    │    │wh d│   <-  │
 *                          ├───┴┬──┴─┬─┴──┬┴─┬─┴──┬┴───┤                            ├───┴┬───┴─┬──┴────┴────┼───────┤
 *                          │    │    │    │  │    │    │                            │ent │ del │            │       │
 *                          └────┴────┴────┘  └────┴────┘                            └────┴─────┘            └───────┘
     */
    [_LAYERS] = LAYOUT(
        TO(_BASE), KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,             KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,
        KC_NO,     KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  TG(_MEDIA),        KC_NO,  KC_NO,    KC_MS_U,  KC_NO,    KC_WH_U,  KC_NO,  KC_NO,
        TG(_CT),   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  TG(_LAYERS),       KC_NO,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN3,  KC_NO,  KC_NO,
        KC_NO,     KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  TG(_NUM),          KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_WH_D,      KC_NO,
        KC_NO,      KC_NO,   KC_NO,              KC_NO,    KC_NO,             KC_BTN1,  KC_BTN2,                                      KC_NO
    ),



    /*
 *                          ┌───┬───┬───┬───┬───┬───┬───┐                   ┌───┬───┬───┬───┬───┬───┬───┐
 *                          │esc│F1 │F2 │F3 │F4 │F5 │F6 │                   │F7 │F8 │ F9│F10│F11│F12│   │
 *                          ├───┼───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┼───┤
 *                          │tab│   │   │   │   │   │   │                   │   │ 7 │ 8 │ 9 │ * │   │   │
 *                          ├───┼───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┼───┤
 *                          │   │   │   │   │   │   │   │                   │   │ 4 │ 5 │ 6 │ - │ / │   │
 *                          ├───┼───┼───┼───┼───┼───┼───┤                   ├───┼───┼───┼───┼───┼───┴───┤
 *                          │sht│   │   │   │   │   │   │                   │ 0 │ 1 │ 2 │ 3 │ + │  <-   │
 *                          ├───┴┬──┴─┬─┴──┬┴─┬─┴──┬┴───┤                   ├───┴┬──┴─┬─┴───┴───┼───────┤
 *                          │ctrk│win │menu│  │ alt│spac│                   │entr│ .  │         │   ,   │
 *                          └────┴────┴────┘  └────┴────┘                   └────┴────┘         └───────┘
     */
    [_NUM] = LAYOUT(
        KC_ESC,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,       KC_F7,   KC_F8,  KC_F9,  KC_F10, KC_F11,   KC_F12,   KC_NO,
        KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,   KC_P7,  KC_P8,  KC_P9,  KC_PAST,  KC_NO,    KC_NO,
        KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,   KC_P4,  KC_P5,  KC_P6,  KC_PMNS,  KC_PSLS,  KC_NO,
        KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  TG(_NUM),    KC_P0,   KC_P1,  KC_P2,  KC_P3,  KC_PPLS,        KC_BSPC,
        KC_TRNS,  KC_TRNS,   KC_TRNS,        KC_TRNS,   KC_TRNS,       KC_PENT,  KC_PDOT,                               KC_PCMM
    ),


        /*
 *                          ┌───┬───┬───┬───┬───┬───┬───┐                    ┌───┬───┬───┬───┬───┬───┬───┐
 *                          │   │   │   │   │   │   │   │                    │   │   │   │   │   │   │   │
 *                          ├───┼───┼───┼───┼───┼───┼───┤                    ├───┼───┼───┼───┼───┼───┼───┤
 *                          │   │   │   │   │   │   │   │                    │   │   │   │   │   │   │   │
 *                          ├───┼───┼───┼───┼───┼───┼───┤                    ├───┼───┼───┼───┼───┼───┼───┤
 *                          │   │   │   │   │   │   │   │                    │   │   │   │   │   │   │   │
 *                          ├───┼───┼───┼───┼───┼───┼───┤                    ├───┼───┼───┼───┼───┼───┴───┤
 *                          │   │   │   │   │   │   │   │                    │   │   │   │   │   │       │
 *                          ├───┴┬──┴─┬─┴──┬┴─┬─┴──┬┴───┤                    ├───┴┬──┴─┬─┴───┴───┼───────┤
 *                          │    │    │    │  │    │    │                    │    │    │         │       │
 *                          └────┴────┴────┘  └────┴────┘                    └────┴────┘         └───────┘
     */
    [_GRV] = LAYOUT(
        KC_GRV,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,              KC_TRNS,    KC_TRNS,       KC_TRNS,  KC_TRNS,                              KC_TRNS
    ),


    /*
 * ┌───┬───┬───┬───┬───┬───┬───┐  ┌───┬───┬───┬───┬───┬───┬───┐
 * │   │   │   │   │   │   │   │  │   │   │   │   │   │   │   │
 * ├───┼───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │   │   │  │   │   │   │   │   │   │   │
 * ├───┼───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┼───┤
 * │   │   │   │   │   │   │   │  │   │   │   │   │   │   │   │
 * ├───┼───┼───┼───┼───┼───┼───┤  ├───┼───┼───┼───┼───┼───┴───┤
 * │   │   │   │   │   │   │   │  │   │   │   │   │   │       │
 * ├───┴┬──┴─┬─┴──┬┴─┬─┴──┬┴───┤  ├───┴┬──┴─┬─┴───┴───┼───────┤
 * │    │    │    │  │    │    │  │    │    │         │       │
 * └────┴────┴────┘  └────┴────┘  └────┴────┘         └───────┘
     */
    [_EMPTY] = LAYOUT(
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,
        KC_NO,   KC_NO,   KC_NO,              KC_NO,    KC_NO,       KC_NO,  KC_NO,                              KC_NO
    ),
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}



// Combos
/*
enum combos {
    FN_LAYER,
    COMBO_LENGHT
};
uint16_t COMBO_LEN = COMBO_LENGHT;

const uint16_t PROGMEM alt_del_combo[] = {KC_LALT, KC_DEL, COMBO_END};

combo_t key_combos[] = {
    [FN_LAYER] = COMBO_ACTION(alt_del_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    println("FN_LAYER -> Pressed");

  switch(combo_index) {
    case FN_LAYER:

      if (pressed && IS_LAYER_OFF(_FN)) {
        uprintf("FN_LAYER -> %u", IS_LAYER_OFF(_FN));
        layer_on(_FN);
      }
      break;
  }
}
*/


// Custom button behaviour
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

  switch (keycode) {
    case KC_ESC:
      if (!record->event.pressed && IS_LAYER_ON(_NUM)) {
        layer_off(_NUM);
      }
      return true;
    case KC_F1:
      if (!record->event.pressed) {
        layer_off(_NUM);
      }
      return true;
    case KC_F2:
      if (!record->event.pressed) {
        layer_off(_NUM);
      }
      return true;
    case KC_F3:
      if (!record->event.pressed) {
        layer_off(_NUM);
      }
      return true;
    case KC_F4:
      if (!record->event.pressed) {
        layer_off(_NUM);
      }
      return true;
    case KC_F5:
      if (!record->event.pressed) {
        layer_off(_NUM);
      }
      return true;
    case KC_F6:
      if (!record->event.pressed) {
        layer_off(_NUM);
      }
      return true;
    case KC_F7:
      if (!record->event.pressed) {
        layer_off(_NUM);
      }
      return true;
    case KC_F8:
      if (!record->event.pressed) {
        layer_off(_NUM);
      }
      return true;
    case KC_F9:
      if (!record->event.pressed) {
        layer_off(_NUM);
      }
      return true;
    case KC_F10:
      if (!record->event.pressed) {
        layer_off(_NUM);
      }
      return true;
    case KC_F11:
      if (!record->event.pressed) {
        layer_off(_NUM);
      }
      return true;
    case KC_F12:
      if (!record->event.pressed) {
        layer_off(_NUM);
      }
      return true;
    default:
      return true;
  }
}


//
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (biton32(state))
    {
    case _NUM:
    // Enable NumLkock when layer activated
        if (!host_keyboard_led_state().num_lock)
        {
            register_code(KC_NUM_LOCK);
            unregister_code(KC_NUM_LOCK);
        }

        break;
    }
    return state;
}
