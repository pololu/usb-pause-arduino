# USBPause library for Arduino

Version: 2.0.0 <br>
Release date: 2016-08-22 <br>
[![Build Status](https://travis-ci.org/pololu/usb-pause-arduino.svg?branch=master)](https://travis-ci.org/pololu/usb-pause-arduino) <br>
[www.pololu.com](https://www.pololu.com/)


## Summary

This is a C++ library for the Arduino IDE that makes it easy to temporarily
pause USB interrupts and restore them later.

When you program an ATmega32U4 board such as the
[Arduino Leonardo](https://www.pololu.com/product/2192) from the Arduino IDE, by
default it adds some code that runs in the background and maintains the USB
connection using interrupts.  This code is part of the Arduino core, and the
main file is
[USBCore.cpp](https://github.com/arduino/Arduino/blob/master/hardware/arduino/avr/cores/arduino/USBCore.cpp).
Those USB interrupts call the board's `RXLED0`, `RXLED1`, `TXLED0`, and `TXLED1`
macros which are defined in
[pins_arduino.h](https://github.com/arduino/Arduino/blob/master/hardware/arduino/avr/variants/leonardo/pins_arduino.h)
in order to blink the board's RX LED and TX LED.  This library provides a way to
temporarily disable USB interrupts so that those pins can be used for other
purposes.

This library is tailored to the Arduino core code; it makes assumptions about
which USB interrupts are enabled and how they work.

## Supported platforms

This library is designed to work with the Arduino IDE versions 1.0.x and 1.5.x,
and will probably not work with earlier versions.

This library only supports boards based on the ATmega32U4.

## Getting started

### Software

If you are using version 1.6.2 or later of the
[Arduino software (IDE)](https://www.arduino.cc/en/Main/Software), you can use
the Library Manager to install this library:

1. In the Arduino IDE, open the "Sketch" menu, select "Include Library", then
   "Manage Libraries...".
2. Search for "USBPause".
3. Click the USBPause entry in the list.
4. Click "Install".

If this does not work, you can manually install the library:

1. Download the
   [latest release archive from GitHub](https://github.com/pololu/usb-pause-arduino/releases)
   and decompress it.
2. Rename the folder "usb-pause-arduino-xxxx" to "USBPause".
3. Drag the "USBPause" folder into the "libraries" directory inside your
   Arduino sketchbook directory. You can view your sketchbook location by
   opening the "File" menu and selecting "Preferences" in the Arduino IDE. If
   there is not already a "libraries" folder in that location, you should make
   the folder yourself.
4. After installing the library, restart the Arduino IDE.

## Version history

* 2.0.0 (2016-08-22): Updated library to work with the Arduino Library Manager.
* 1.0.0 (2014-12-11): Original release.
