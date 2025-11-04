#include "BleComboHID.h"

BleComboHID::BleComboHID(const std::string& deviceName, const std::string& deviceManufacturer, uint8_t batteryLevel)
    : BleKeyboard(deviceName, deviceManufacturer, batteryLevel), BleMouse(deviceName, deviceManufacturer, batteryLevel) {
}

void BleComboHID::setDeviceName(const std::string& deviceName) {
    BleKeyboard::setName(deviceName);
    BleMouse::setName(deviceName);
}

void BleComboHID::begin() {
    BleKeyboard::begin();
    BleMouse::begin();
}

void BleComboHID::pressKey(uint8_t key) {
    BleKeyboard::press(key);
}

void BleComboHID::releaseKey(uint8_t key) {
    BleKeyboard::release(key);
}

void BleComboHID::pressMouse(uint8_t button) {
    BleMouse::press(button);
}

void BleComboHID::releaseMouse(uint8_t button) {
    BleMouse::release(button);
}