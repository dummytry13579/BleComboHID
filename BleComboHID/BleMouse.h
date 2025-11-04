#ifndef BLE_MOUSE_H
#define BLE_MOUSE_H

#include <BLEHIDDevice.h>
#include "BleConnectionStatus.h"
#include "MouseButtonConstants.h" // Include the mouse button constants

class BleMouse {
public:
    BleMouse(std::string deviceName = "ESP32 Mouse", std::string deviceManufacturer = "Espressif", uint8_t batteryLevel = 100);
    void begin(void);
    void end(void);
    void click(uint8_t b);
    void move(signed char x, signed char y, signed char wheel = 0, signed char hWheel = 0);
    void buttons(uint8_t b);
    void press(uint8_t b);
    void release(uint8_t b);
    bool isPressed(uint8_t b);
    bool isConnected(void);
    void setBatteryLevel(uint8_t level);
    void setName(const std::string& deviceName);
    void onStarted(BLEServer* pServer); // Placeholder for onStarted method

protected:
    void taskServer(void* pvParameter);
    static void taskServerStatic(void* pvParameter) {
        ((BleMouse*)pvParameter)->taskServer(pvParameter);
    }

private:
    std::string deviceName;
    std::string deviceManufacturer;
    uint8_t batteryLevel;
    uint8_t _buttons;
    BLEHIDDevice* hid;
    BLECharacteristic* inputMouse;
    BleConnectionStatus* connectionStatus;
};

#endif // BLE_MOUSE_H