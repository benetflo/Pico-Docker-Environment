#ifndef ONEWIRE_H
#define ONEWIRE_H

#define READ_ROM 0x33
#define MATCH_ROM 0x55
#define SKIP_ROM 0xCC
#define ALARM_SEARCH 0xEC
#define CONVERT_T 0x44
#define WRITE_SCRATCHPAD 0x4E
#define READ_SCRATCHPAD 0xBE
#define COPY_SCRATCHPAD 0x48
#define RECALL_E2 0xB8
#define READ_POWER_SUPPLY 0xB4

bool onewire_reset(const uint PIN);
void onewire_write_bit(const uint PIN, bool bit);
void onewire_write_byte(const uint PIN, uint8_t byte);
uint8_t onewire_read_byte(const uint PIN);
bool ds18b20_start_reading(const uint PIN);
bool ds18b20_is_reading_done(const uint PIN);
float ds18b20_read_temp(const uint PIN);

#endif
