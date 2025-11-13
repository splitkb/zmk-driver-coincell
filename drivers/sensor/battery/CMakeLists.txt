# Copyright (c) 2025 Splitkb.com
# SPDX-License-Identifier: MIT

zephyr_library_sources_ifdef(CONFIG_SPLITKB_BATTERY_COINCELL coincell_battery.c)
zephyr_library_sources_ifdef(CONFIG_SPLITKB_BATTERY_COINCELL coincell_common.c)
