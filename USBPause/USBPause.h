// Copyright (C) Pololu Corporation - see LICENSE.txt for details.

/*! \file USBPause.h
 *
 * This is the main file for the USBPause library.
 *
 * For an overview of this library, see
 * https://github.com/pololu/usb-pause-arduino.  That is the main repository for
 * this library, though copies may exist in other repositories. */

#pragma once

/*! This class disables USB interrupts in its constructor when it is created and
 *  restores them to their previous state in its destructor when it is
 *  destroyed.  This class is tailored to the behavior of the Arduino core USB
 *  code, so it might have to change if that code changes.
 *
 * This class assumes that the only USB interrupts enabled are general device
 * interrupts and endpoint 0 interrupts.
 *
 * It also assumes that the endpoint 0 interrupts will not enable or disable any
 * of the general device interrupts.
 */
class USBPause
{
public:
    uint8_t savedUDIEN, savedUENUM, savedUEIENX;

    USBPause()
    {
        // Disable the general USB interrupt.  This must be done
        // first, because the general USB interrupt might change the
        // state of the EP0 interrupt, but not the other way around.
        savedUDIEN = UDIEN;
        UDIEN = 0;

        // Select endpoint 0.
        savedUENUM = UENUM;
        UENUM = 0;

        // Disable endpoint 0 interrupts.
        savedUEIENX = UEIENX;
        UEIENX = 0;
    }

    ~USBPause()
    {
        // Restore endoint 0 interrupts.
        UENUM = 0;
        UEIENX = savedUEIENX;

        // Restore endpoint selection.
        UENUM = savedUENUM;

        // Restore general device interrupt.
        UDIEN = savedUDIEN;
    }

};
