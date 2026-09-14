/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define QUICK_TAP_TERM 0

#define MASTER_LEFT

/*
original from urob's zmk config https://github.com/urob/zmk-config#timeless-homerow-mods
Timeless Homerow mods in QMK https://www.reddit.com/r/ErgoMechKeyboards/comments/1q1jo3c/urobs_zmk_timeless_home_row_mods_ported_to_native/

- troubleshoot and tune
Noticeable delay when tapping HRMs: Increase FLOW_TAP_TERM.
False negatives (same-hand): Reduce TAPPING_TERM (or disable Chordal Hold)
False negatives (cross-hand): Reduce FLOW_TAP_TERM
False positives (same-hand): Increase TAPPING_TERM
False positives (cross-hand): Increase FLOW_TAP_TERM

*/
#define TAPPING_TERM 250
#define PERMISSIVE_HOLD // Make a dual-role key (tap and hold) work as a hold if another key is tapped within tapping term and the first hold key is also released
#define FLOW_TAP_TERM 150 //During fast typing prevents HRM to fire
#define CHORDAL_HOLD //Same hand roll => Tap / Opposite Hand => Hold
#define SPECULATIVE_HOLD // This will make things like Shift + Mouse Click responsive. Essentially Hold until undecided.

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

/*
https://github.com/qmk/qmk_firmware/compare/master...luckenbach:lily58glow#diff-35211acd31257be675b5a932ac5aca5266308520b57a22697a6f3a76e72185e1R54
https://github.com/PandaKBLab/QMK-firmware-for-keyboards/blob/79099cabbfb6a13a2f3569b044c597ba99eb10f7/lily58/lily58/config.h#L40

Enabling the RBG MATRIX at Lily. Still need to test on ubuntu because for some reason
the kb was going into bootloader mode.

*/
#define MATRIX_ROWS 10
#define MATRIX_COLOS 6

#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }

#define RGB_DI_PIN D3

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_LED_COUNT 70
    #define DRIVER_LED_TOTAL 70
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
    #define RGB_MATRIX_STARTUP_VAL  120
    #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT

    #define RGB_DISABLE_WHEN_USB_SUSPENDED
#endif

#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
