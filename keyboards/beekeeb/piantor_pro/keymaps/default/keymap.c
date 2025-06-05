// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNC,
  BACKLIT,
  //LYR_CAPS,
};

//enum combos {
//  DF_DASH,
//  RS_DASH,
//  SD_DASH,
//  KL_ESC,
//  ST_CTRL_ENTER,
//  JK_CTRL_LEFT,
//  LQUOT_CTRL_RIGHT,
//  EN_CTRL_LEFT,
//  IO_CTRL_RIGHT,
//  EI_ESC
//};
//
//const uint16_t PROGMEM df_combo[]    = {KC_D, KC_F, COMBO_END};
//const uint16_t PROGMEM rs_combo[]    = {KC_R, KC_S, COMBO_END};
//const uint16_t PROGMEM sd_combo[]    = {KC_S, KC_D, COMBO_END};
//const uint16_t PROGMEM kl_combo[]    = {KC_K, KC_L, COMBO_END};
//const uint16_t PROGMEM st_combo[]    = {KC_S, KC_T, COMBO_END};
//const uint16_t PROGMEM jk_combo[]    = {KC_J, KC_K, COMBO_END};
//const uint16_t PROGMEM lquot_combo[] = {KC_L, KC_QUOT, COMBO_END};
//const uint16_t PROGMEM en_combo[]    = {KC_E, KC_N, COMBO_END};
//const uint16_t PROGMEM io_combo[]    = {KC_I, KC_O, COMBO_END};
//const uint16_t PROGMEM ei_combo[]    = {KC_E, KC_I, COMBO_END};

//combo_t key_combos[COMBO_COUNT] = {
//  // Add commonly used dash to home row
//  [SD_DASH]         = COMBO(sd_combo, KC_MINS),
//  [RS_DASH]         = COMBO(rs_combo, KC_MINS),
//  // For Vim, put Escape on the home row
//  //// russian-qwerty
//  [KL_ESC]          = COMBO(kl_combo, KC_ESC),
//  //// english-colemak
//  [EI_ESC]          = COMBO(ei_combo, KC_ESC),
//  // Ctrl + Enter
//  [ST_CTRL_ENTER]   = COMBO(st_combo, LCTL(KC_ENT)),
//  // Shift + Left/Right for russian-qwerty
//  [JK_CTRL_LEFT]   = COMBO(jk_combo, LCTL(LSFT(KC_LEFT))),
//  [LQUOT_CTRL_RIGHT]   = COMBO(lquot_combo, LCTL(LSFT(KC_RIGHT))),
//  // Shift + Left/Right for english-colemak
//  [EN_CTRL_LEFT]   = COMBO(en_combo, LCTL(LSFT(KC_LEFT))),
//  [IO_CTRL_RIGHT]   = COMBO(io_combo, LCTL(LSFT(KC_RIGHT))),
//};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers {
  _COLEMAKDH,
  _LOWER,
  _RAISE,
  _FUNC,
};

// For _QWERTY layer
#define OSM_AGR  OSM(MOD_RALT)
#define OSL_FUN  OSL(_FUNC)
#define GUI_ENT  GUI_T(KC_ENT)
#define LOW_TAB  LT(_LOWER, KC_TAB)
#define LOW_SPC  LT(_LOWER, KC_SPC)
#define RSE_BSP  LT(_RAISE, KC_BSPC)
#define LAL_ENT  MT(MOD_LALT, KC_ENT)
#define OSM_SFT  OSM(MOD_LSFT)
#define GUI_SPC  GUI_T(KC_SPC)
#define GUI_TAB  GUI_T(KC_TAB)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

// Right-hand home row mods
#define HOME_N RCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)


// For _RAISE layer
#define CTL_ESC  LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAKDH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  HOME_A,  HOME_R,  HOME_S,  HOME_T,    KC_G,                         KC_M,  HOME_N,  HOME_E,  HOME_I,  HOME_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_CAPS,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                     KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_SLSH ,OSL_FUN ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_MINS, KC_TAB, LOW_SPC,     RSE_BSP, KC_ENT, KC_ESC
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_RBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1,                      KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS,   LOWER,    KC_TRNS, KC_WH_D, KC_WH_U
                                      //`--------------------------'  `--------------------------'
    ),


  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_DEL , XXXXXXX, KC_UNDS, KC_PLUS, KC_PGUP,                      KC_PSCR, XXXXXXX, XXXXXXX, KC_BSLS, KC_PIPE,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HOME, KC_END , XXXXXXX,  KC_EQL, KC_PGDN,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LT  , KC_GT  , XXXXXXX,S(KC_INS),XXXXXXX,                      KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU,_______ ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, XXXXXXX,    RAISE  , KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_F1  , KC_F2  , KC_F3   , KC_F4 ,  KC_F5 ,                     KC_F6   , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F11 , KC_F12 , XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, FUNC   , XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};
