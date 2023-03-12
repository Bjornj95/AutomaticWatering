// Plant.h
#ifndef Plant_h
#define Plant_h

#include <Arduino.h>

class Plant {
  private:
    int sensor_pin;
    int motor_pin;
    int plant_type; //0 = tomato, 1 = chilly
    int current_hour; // A dumb clock that represent the hour
    int water_at;
    int moist_level;
    int amount_last_24h[24];
    void blink_light(int number_of_blinks);
    void print_status();
  public:
    Plant(const uint8_t& sensor_pin, int motor_pin, int plant_type, int start_time);
    void check_and_water();
    void run_motor_for_seconds(int secs);
    void add_time();
};

#endif
