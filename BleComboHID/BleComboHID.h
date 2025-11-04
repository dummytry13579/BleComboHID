#ifndef BLECOMBOHID_H
#define BLECOMBOHID_H

#include <BleKeyboard.h>
#include <BleMouse.h>

class BleComboHID : public BleKeyboard, public BleMouse {
public:
    BleComboHID(const std::string& deviceName = "BleComboHID", const std::string& deviceManufacturer = "Arduino", uint8_t batteryLevel = 100);

    void setDeviceName(const std::string& deviceName);
    void begin();
    void pressKey(uint8_t key);
    void releaseKey(uint8_t key);
    void pressMouse(uint8_t button);
    void releaseMouse(uint8_t button);
};

#endif // BLECOMBOHID_H