/*
 * Copyright (c) 2025 Splitkb.com
 *
 * SPDX-License-Identifier: MIT
 */

#include "coincell_common.h"

uint8_t coincell_mv_to_pct(int16_t bat_mv) {
    if (bat_mv >= 3100) return 100;
    if (bat_mv <= 1800) return 0;

    // Lookup table for coincell battery voltage to percentage based on https://data.energizer.com/pdfs/cr1632.pdf
    int16_t voltages[] = {1800, 2000, 2200, 2400, 2600, 2800, 2900, 2950, 3000, 3100};
    uint8_t percents[] = {0, 1, 3, 4, 7, 25, 43, 71, 95, 100};
    int n = sizeof(voltages) / sizeof(voltages[0]);

    for (int i = 0; i < n - 1; i++) {
        if (bat_mv >= voltages[i] && bat_mv < voltages[i + 1]) {
            int16_t v0 = voltages[i];
            int16_t v1 = voltages[i + 1];
            uint8_t p0 = percents[i];
            uint8_t p1 = percents[i + 1];

            return p0 + (uint8_t)((p1 - p0) * (bat_mv - v0) / (v1 - v0));
        }
    }

    return 0;
}
