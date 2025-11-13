# ZMK Coincell driver

Currently, ZMK is hardcoded to use a Lithium-Ion voltage-to-percentage curve. This module adds support for common 3V coincell batteries. 

This can then be used in place of the `compatible = "zmk,battery-voltage-divider"` as `compatible = "splitkb,coincell-voltage-divider"`
