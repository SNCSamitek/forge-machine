#pragma once
#include "constants.h"
#include "sbus.h"

class Radio {
  private:
    static const int FREQUENCY;
    bfs::SbusRx sbus_rx;
    bfs::SbusData data;

  public:
    Radio(HardwareSerial* serial, const int8_t rxpin, const int8_t txpin,
          const bool inv);
    void init();

    bool readControllerData();
    float normalizeControllerValue(int value);
    bool update(float* controllerData);
};
