#ifndef DISPLAY_H
#define DISPLAY_H

#define DISPLAY_SCHEDULE 1000000

void displaySetup    (void                );
void displaySetLine  (uint8_t, const char*);
void displayIntensity(uint8_t             );
void displayInverted (bool                );
void displayPower    (bool state          );

#endif
