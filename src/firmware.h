#ifndef FIRMWARE_H
#define FIRMWARE_H

#define BUILD_VERSION        REPLACE_WITH_CURRENT_VERSION
#define ULR_FIRMWARE_BIN     "http://s3.amazonaws.com/feelflight/firmware/blouse.bin"
#define URL_FIRMWARE_VERSION "http://s3.amazonaws.com/feelflight/firmware/blouse.version"

#define FIRMWARE_SCHEDULE 1000000

void     firmwareSetup      (void);
uint64_t firmwareLoop       (void);
void     firmwarecheckForNew(void);

#endif
