// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


/*! 
 * @file BatteryState.hpp
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */
#ifndef _SENSOR_MSGS_BATTERY_STATE_HPP_
#define _SENSOR_MSGS_BATTERY_STATE_HPP_


#include <topic.hpp>


#include "std_msgs/Header.hpp"

namespace sensor_msgs {

enum BatteryStatus
{
  POWER_SUPPLY_STATUS_UNKNOWN = 0,
  POWER_SUPPLY_STATUS_CHARGING,
  POWER_SUPPLY_STATUS_DISCHARGING,
  POWER_SUPPLY_STATUS_NOT_CHARGING,
  POWER_SUPPLY_STATUS_FULL
};

enum BatteryHealth
{
  POWER_SUPPLY_HEALTH_UNKNOWN = 0,
  POWER_SUPPLY_HEALTH_GOOD,
  POWER_SUPPLY_HEALTH_OVERHEAT,
  POWER_SUPPLY_HEALTH_DEAD,
  POWER_SUPPLY_HEALTH_OVERVOLTAGE,
  POWER_SUPPLY_HEALTH_UNSPEC_FAILURE,
  POWER_SUPPLY_HEALTH_COLD,
  POWER_SUPPLY_HEALTH_WATCHDOG_TIMER_EXPIRE,
  POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE
};

enum BatteryTechnology
{
  POWER_SUPPLY_TECHNOLOGY_UNKNOWN = 0,
  POWER_SUPPLY_TECHNOLOGY_NIMH,
  POWER_SUPPLY_TECHNOLOGY_LION,
  POWER_SUPPLY_TECHNOLOGY_LIPO,
  POWER_SUPPLY_TECHNOLOGY_LIFE,
  POWER_SUPPLY_TECHNOLOGY_NICD,
  POWER_SUPPLY_TECHNOLOGY_LIMN
};


class BatteryState : public ros2::Topic<BatteryState>
{
public: 
    std_msgs::Header header;
    float voltage;
    float current;
    float charge;
    float capacity;
    float design_capacity;
    float percentage;
    uint8_t power_supply_status;
    uint8_t power_supply_health;
    uint8_t power_supply_technology;
    bool present;
    float cell_voltage[10];
    uint32_t cell_voltage_size;
    char location[32];
    char serial_number[32];

  BatteryState():
    Topic("sensor_msgs::msg::dds_::BatteryState_", "BatteryState"),
    header(),
    voltage(0), current(0), charge(0), capacity(0), design_capacity(0), percentage(0),
    power_supply_status(0), power_supply_health(0), power_supply_technology(0),
    present(0), cell_voltage_size(1)
  { 
    memset(cell_voltage, 0, sizeof(cell_voltage));
    memset(location, 0, sizeof(location));
    memset(serial_number, 0, sizeof(serial_number));
  }

  bool serialize(ucdrBuffer* writer, const BatteryState* topic)
  {
    (void) header.serialize(writer, &topic->header);
    (void) ucdr_serialize_float(writer, topic->voltage);
    (void) ucdr_serialize_float(writer, topic->current);
    (void) ucdr_serialize_float(writer, topic->charge);
    (void) ucdr_serialize_float(writer, topic->capacity);
    (void) ucdr_serialize_float(writer, topic->design_capacity);
    (void) ucdr_serialize_float(writer, topic->percentage);
    (void) ucdr_serialize_uint8_t(writer, topic->power_supply_status);
    (void) ucdr_serialize_uint8_t(writer, topic->power_supply_health);
    (void) ucdr_serialize_uint8_t(writer, topic->power_supply_technology);
    (void) ucdr_serialize_bool(writer, topic->present);
    (void) ucdr_serialize_sequence_float(writer, topic->cell_voltage, topic->cell_voltage_size);
    (void) ucdr_serialize_string(writer, topic->location);
    (void) ucdr_serialize_string(writer, topic->serial_number);

    return !writer->error;
  }

  bool deserialize(ucdrBuffer* reader, BatteryState* topic)
  {
    (void) header.deserialize(reader, &topic->header);
    (void) ucdr_deserialize_float(reader, &topic->voltage);
    (void) ucdr_deserialize_float(reader, &topic->current);
    (void) ucdr_deserialize_float(reader, &topic->charge);
    (void) ucdr_deserialize_float(reader, &topic->capacity);
    (void) ucdr_deserialize_float(reader, &topic->design_capacity);
    (void) ucdr_deserialize_float(reader, &topic->percentage);
    (void) ucdr_deserialize_uint8_t(reader, &topic->power_supply_status);
    (void) ucdr_deserialize_uint8_t(reader, &topic->power_supply_health);
    (void) ucdr_deserialize_uint8_t(reader, &topic->power_supply_technology);
    (void) ucdr_deserialize_bool(reader, &topic->present);
    (void) ucdr_deserialize_sequence_float(reader, topic->cell_voltage, sizeof(topic->cell_voltage)/sizeof(float), &topic->cell_voltage_size);
    (void) ucdr_deserialize_string(reader, topic->location, sizeof(topic->location));
    (void) ucdr_deserialize_string(reader, topic->serial_number, sizeof(topic->serial_number));

    return !reader->error;
  }

  uint32_t size_of_topic(const BatteryState* topic, uint32_t size)
  {
    uint32_t previousSize = size;

    size += header.size_of_topic(&topic->header, size);

    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;

    size += ucdr_alignment(size, 1) + 1;
    size += ucdr_alignment(size, 1) + 1;
    size += ucdr_alignment(size, 1) + 1;
    size += ucdr_alignment(size, 1) + 1;

    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + (topic->cell_voltage_size * 4);

    size += ucdr_alignment(size, 4) + 4 + (uint32_t)(strlen(topic->location) + 1);
    size += ucdr_alignment(size, 4) + 4 + (uint32_t)(strlen(topic->serial_number) + 1);

    return size - previousSize;
  }

};

} // namespace sensor_msgs


#endif // _SENSOR_MSGS_BATTERY_STATE_HPP_
