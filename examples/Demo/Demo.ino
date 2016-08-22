#include "USBPause.h"

void setup()
{
}

void loop()
{
  // USB interrupts are enabled here at the beginning of the loop
  // until the next line where `u` is constructed.
  USBPause u;
  // USB interrupts are paused until the end of loop() when `u` is
  // automatically destructed.
}
