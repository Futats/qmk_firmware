// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


enum layers {
  BASE,
  SYM,
  NUM,
  NAV,
};

enum keycode_aliases {
  // Short aliases for home row mods and other tap-hold keys.
  HRM_A = LGUI_T(KC_A),
  HRM_S = LALT_T(KC_S),
  HRM_D = LCTL_T(KC_D),
  HRM_F = LSFT_T(KC_F),
  HRM_G = LT(NAV, KC_G),
  HRM_BSPC = LT(NUM, KC_BSPC),
  HRM_SPC = LT(SYM, KC_SPC),

  HRM_SCLN = RGUI_T(KC_SCLN),
  HRM_L = RALT_T(KC_L),
  HRM_K = RCTL_T(KC_K),
  HRM_J = RSFT_T(KC_J),
  HRM_H = LT(NAV, KC_H),
  HRM_ENT = LT(SYM, KC_ENT),
  HRM_TAB = LT(NUM, KC_TAB),

  SY_HASH = LGUI_T(KC_HASH),
  SY_DQUO = LALT_T(KC_DQUO),
  SY_LT = LCTL_T(KC_LT),
  SY_EQL = LSFT_T(KC_EQL),

  SY_COLN = RGUI_T(KC_COLN),
  SY_UNDS = RALT_T(KC_UNDS),
  SY_RPRN = RCTL_T(KC_RPRN),
  SY_LPRN = RSFT_T(KC_LPRN),
  
  N_F5 = LGUI_T(KC_F5),
  N_F6 = LALT_T(KC_F6),
  N_F7 = LCTL_T(KC_F7),
  N_F8 = LSFT_T(KC_F8),
  // Not using the numpad homerow mod for shift/4 because the shift on 4 dumps the Alt+code in buffer, leading to Alt+24 becoming Alt+4. Note that Alt+41-9 are unaffected. 
  N_0 = RGUI_T(KC_P0),
  N_6 = RALT_T(KC_P6),
  N_5 = RCTL_T(KC_P5),
  N_4 = RSFT_T(KC_P4),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │GUI├───┐           ┌───┤Alt│
      *           └───┤Bsp├───┐   ┌───┤Ent├───┘
      *               └───┤   │   │   ├───┘
      *                   └───┘   └───┘
      */
    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,				KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,
        HRM_A,	HRM_S,	HRM_D,	HRM_F,	HRM_G,				HRM_H,	HRM_J,	HRM_K,	HRM_L,	HRM_SCLN,
        KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,				KC_N,	KC_M,	KC_COMM,KC_DOT,	KC_SLSH,
						KC_DEL, HRM_BSPC,HRM_SPC,			HRM_ENT,HRM_TAB,KC_ESC
    ),

	[SYM] = LAYOUT_split_3x5_3(
        KC_PIPE,    KC_QUOT, 	KC_PERC, 	KC_DLR,     KC_EXLM,			KC_PLUS, 	KC_LCBR, 	KC_RCBR, 	KC_QUES, 	KC_PAST,
		SY_HASH,    SY_DQUO, 	SY_LT,      SY_EQL,     KC_GT,				KC_MINS, 	SY_LPRN,	SY_RPRN,	SY_UNDS,	SY_COLN,			
		KC_TILD,    KC_GRV,     KC_AMPR,    KC_CIRC,    KC_BSLS,			KC_AT, 	    KC_LBRC,	KC_RBRC,	KC_PDOT,	KC_PSLS,				
								KC_TRNS,    KC_TRNS, 	KC_TRNS,			KC_TRNS, 	KC_TRNS,	KC_TRNS
    ),

	[NUM] = LAYOUT_split_3x5_3(
		KC_F1, 	KC_F2, 	KC_F3, 	KC_F4, 	KC_HOME,						KC_PLUS, KC_P7, KC_P8, 	KC_P9, 	KC_PAST,
		N_F5, 	N_F6,	N_F7,	N_F8, 	KC_END,							KC_PMNS, N_4,   N_5, 	N_6, 	N_0,
		KC_F9, 	KC_F10, KC_F11, KC_F12, KC_CALC,						KC_COLN, KC_P1, KC_P2,	KC_P3,	KC_PSLS,
						KC_TRNS,KC_TRNS,KC_TRNS,						KC_PDOT, KC_P0, KC_PDOT
	),

	[NAV] = LAYOUT_split_3x5_3(
		KC_MUTE, 	KC_VOLD,	KC_VOLU,	KC_MPLY,	KC_NO,					KC_NO, 		LSFT(KC_Y), KC_END, 	LSFT(KC_I), KC_NO,
		KC_LSFT, 	KC_LOPT,	KC_LCTL,	KC_LSFT,	KC_END,					KC_HOME,	KC_LEFT, 	KC_DOWN, 	KC_UP, 		KC_RGHT,
		KC_NO, 		KC_NO,		KC_MPRV,	KC_MNXT,	KC_NO,					KC_NO,		LSFT(KC_N), LSFT(KC_M), KC_NO, 		KC_NO,
								KC_APP, 	MS_WHLU, 	MS_WHLD,				KC_PGDN, 	KC_PGUP, 	KC_END
	)
};

///////////////////////////////////////////////////////////////////////////////
// Combos (https://docs.qmk.fm/features/combo)
///////////////////////////////////////////////////////////////////////////////
//const uint16_t caps_combo[] PROGMEM = {KC_J, KC_COMM, COMBO_END};
const uint16_t h_j_combo[] PROGMEM = {HRM_H, HRM_J, COMBO_END};
const uint16_t j_k_combo[] PROGMEM = {HRM_J, HRM_K, COMBO_END};
const uint16_t k_l_combo[] PROGMEM = {HRM_K, HRM_L, COMBO_END};
//const uint16_t comm_dot_combo[] PROGMEM = {KC_COMM, HRM_DOT, COMBO_END};
//const uint16_t f_n_combo[] PROGMEM = {KC_F, HRM_N, COMBO_END};
// clang-format off
combo_t key_combos[] = {
    //COMBO(caps_combo, CW_TOGG),          // J and , => activate Caps Word.
    COMBO(h_j_combo, KC_HOME),           // H and J => HOME
    COMBO(j_k_combo, KC_SPC),           // J and K => Space
    COMBO(k_l_combo, KC_END),           // K and L => END
    //COMBO(comm_dot_combo, KC_SCLN),      // , and . => ;
    //COMBO(f_n_combo, OSL(FUN)),          // F and N => FUN layer
};
// clang-format on


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // 1. Intercept N_4 if ANY Alt state is active to prevent the Shift-hijack
    if (keycode == RSFT_T(KC_P4)) {
        if (get_mods() & (MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT))) {
            if (record->event.pressed) {
                register_code(KC_P4);
            } else {
                unregister_code(KC_P4);
            }
            return false;
        }
    }

    // 2. Intercept the pinky key collision based on active LAYER status
    if (record->tap.count && record->event.pressed) {
        // If they have the identical 16-bit footprint, look at the active layer
        if (keycode == HRM_SCLN || keycode == SY_COLN) {
            if (IS_LAYER_ON(SYM)) {
                tap_code16(KC_COLN); // Force a clean Colon on your Symbol Layer
            } else {
                tap_code16(KC_SCLN); // Force a clean Semicolon on your Base Layer
            }
            return false; // Bypass default handling entirely
        }
    }

    // 3. Original symbol tap-hold interceptions
    if (record->tap.count && record->event.pressed) {
        switch (keycode) {
            case SY_HASH: tap_code16(KC_HASH);  return false;
            case SY_DQUO: tap_code16(KC_DQUO);  return false;
            case SY_LT:   tap_code16(KC_LT);    return false;
            case SY_EQL:  tap_code16(KC_EQL);   return false;
            case SY_UNDS: tap_code16(KC_UNDS);  return false;
            case SY_RPRN: tap_code16(KC_RPRN);  return false;
            case SY_LPRN: tap_code16(KC_LPRN);  return false;
        }
    }
    return true;
}

bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    return true; // all combos are tap-only
}

bool get_speculative_hold(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case RSFT_T(KC_P4):
            // Disable speculative hold for N_4 to protect Windows Alt-codes
            return false;
        default:
            // Maintain the default behavior (True for Shift/Ctrl mod-taps)
            return (QK_MOD_TAP_GET_MODS(keycode) & (MOD_LALT | MOD_LGUI)) == 0;
    }
}