# Things that broke, and why

Recorded so the same afternoon doesn't happen twice.

## Dongle powers up, halves connect, nothing types
The `studio-rpc-usb-uart` snippet adds USB CDC ACM, turning the dongle into a
composite USB device (keyboard + serial port). Windows caches the descriptor
against the VID/PID and can bind the serial interface while leaving HID
unbound. Remove the snippet, or clear the cached device:
Device Manager → Show hidden devices → uninstall under both Keyboards and
Ports (COM & LPT) → replug into a *different* USB port.

## One half connects and reports battery but sends no keys
A stale or half-written peripheral address slot. The dongle stores peripheral
addresses permanently (`ble/peripheral_addresses/*`) and has exactly two slots.
Fix: `settings_reset` all three, then power on dongle → left → right, one at a
time, ~20s apart. Never both halves together.

## Windows asks for a Bluetooth passkey
`ZMK_BLE_EXPERIMENTAL_FEATURES` implies `ZMK_BLE_PASSKEY_ENTRY`. A dongle has
no keys to type one on. `CONFIG_ZMK_BLE_PASSKEY_ENTRY=n` is set in
config/lily58.conf and config/corne.conf.

## Dongle screen is garbled
It is an SH1106, not an SSD1306. The two share a command set but the SH1106
has a 2-column RAM offset and needs a different write path
(`ssd1306_write_sh1106()` in Zephyr). Hence `width = <129>` and
`segment-offset = <1>` in the dongle overlay.

## Half screens render in bands
`LV_Z_VDB_SIZE`. The nice-oled module wants 100 for a 160x68 nice!view, but
the lily58 shield forces 64 whenever LVGL is on. Pinned to 100 in the
per-half confs.

## Keyboard drops out at random
The dongle was sleeping. It is the central; if it sleeps the whole keyboard
goes with it. `CONFIG_ZMK_SLEEP=n` in the dongle conf.

## Builds fail with KeyError: 'qualifiers'
The workflow and the ZMK source were on different versions. Pin BOTH:
`.github/workflows/build.yml` → `@v0.3`, and `config/west.yml` → `revision: v0.3`.

## Custom shield is not found (Invalid SHIELD)
`zephyr/module.yml` must exist at the repo root with `board_root: .`. ZMK's
workflow only passes `-DZMK_EXTRA_MODULES` when it sees that file.
