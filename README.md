# USBPause library for Arduino

Version: 1.0.0<br/>
Release date: 2014 Dec 11<br/>
[www.pololu.com](http://www.pololu.com/)

## Summary

This is a C++ library for the Arduino IDE that makes it easy to temporarily pause USB interrupts and restore them later.

When you program an ATmega32U4 board such as the [Arduino Leonardo](http://www.pololu.com/product/2192) from the Arduino IDE, by default it adds some code that runs in the background and maintains the USB connection using interrupts.  This code is part of the Arduino core, and the main file is [USBCore.cpp](https://github.com/arduino/Arduino/blob/master/hardware/arduino/avr/cores/arduino/USBCore.cpp).  Those USB interrupts call the board's `RXLED0`, `RXLED1`, `TXLED0`, and `TXLED1` macros which are defined in [pins_arduino.h](https://github.com/arduino/Arduino/blob/master/hardware/arduino/avr/variants/leonardo/pins_arduino.h) in order to blink the board's RX LED and TX LED.  This library provides a way to temporarily disable USB interrupts so that those pins can be used for other purposes.

This library is tailored to the Arduino core code; it makes assumptions about which USB interrupts are enabled and how they work.

## Supported platforms

This library is designed to work with the Arduino IDE versions 1.0.x and 1.5.x, and will probably not work with earlier versions.

This library only supports boards based on the ATmega32U4.

## Version history

* 1.0.0 (2014 Dec 11): Original release.