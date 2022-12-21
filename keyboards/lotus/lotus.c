// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include "lotus.h"

#define BOOT_DONE_GPIO GP5

void keyboard_post_init_user(void) {
  // Enable debug output
  debug_enable = true;
  debug_matrix = true;
  debug_keyboard = true;
}

/**
 * Hook into early keyboard initialization
*/
void keyboard_pre_init_user(void) {
    // Mark boot as done.
    // Before this, when holding down both alt keys QSPI_SS is pulled low to put
    // the RP2040 in bootloader mode during reset.
    setPinOutput(BOOT_DONE_GPIO);
    writePinHigh(BOOT_DONE_GPIO);
}
