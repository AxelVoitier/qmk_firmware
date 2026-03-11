# HandyWork 5x3 + Mods + Nav

![handywork/5x3_mods_nav](https://raw.githubusercontent.com/AxelVoitier/keebs/refs/heads/main/Framework/HandyWork-5x3-with-mods-with-nav/HandyWork-5x3-with-mods-with-nav-keymap-full.png)

HandyWork mimics a split ergo but as a unibody fitting on the Framework 16 using One Key Modules

The 5x3 + Mods + Nav variant has 46 keys: 5 columns * 3 rows core keys, plus 3 thumb keys, plus 3 extra keys for modifiers, per hand. Plus 4 dedicated keys for a navigation cluster in the middle.

* Keyboard Maintainer: [Axel Voitier](https://github.com/Axel%20Voitier)
* Hardware Supported: HandyWork keyboards, made to fit on Framework 16 laptops, using a RP2040 microcontroller, and One Key Modules
* Hardware Availability: [PCB ordering directions](https://github.com/AxelVoitier/keebs/releases/tag/HandyWork-5x3-Mods-Nav-v1A)

Make example for this keyboard (after setting up your build environment):

    make handywork/5x3_mods_nav:default

Flashing example for this keyboard:

    make handywork/5x3_mods_nav:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
