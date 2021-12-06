# lergo

![lergo](imgur.com image replace me!)

A modular, flexible ergo split platform to figure out which staggering and layout you like before commiting to a fixed build.

* Keyboard Maintainer: [Axel Voitier](https://github.com/Axel Voitier)
* Hardware Supported: Lergo v1.A, Pro-micro and compatible
* Hardware Availability: [PCB & Bottom & Top plates](https://github.com/AxelVoitier/keebs/tree/main/Lergo)

Make example for this keyboard (after setting up your build environment):

    make lergo:default

Flashing example for this keyboard:

    make lergo:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `RESET` if it is available
