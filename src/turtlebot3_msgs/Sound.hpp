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
 * @file Sound.hpp
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */
#ifndef _TURTLEBOT3_MSGS_SOUND_HPP_
#define _TURTLEBOT3_MSGS_SOUND_HPP_


#include <topic.hpp>


namespace turtlebot3_msgs {


class Sound : public ros2::Topic<Sound>
{
public: 
    uint8_t value;

  Sound():
    Topic("turtlebot3_msgs::msg::dds_::Sound_", "Sound"),
    value(0)
  { 
  }

  bool serialize(ucdrBuffer* writer, const Sound* topic)
  {
    (void) ucdr_serialize_uint8_t(writer, topic->value);

    return !writer->error;
  }

  bool deserialize(ucdrBuffer* reader, Sound* topic)
  {
    (void) ucdr_deserialize_uint8_t(reader, &topic->value);
    
    return !reader->error;
  }

  uint32_t size_of_topic(const Sound* topic, uint32_t size)
  {
    (void)(topic);

    uint32_t previousSize = size;
    size += ucdr_alignment(size, 1) + 1;

    return size - previousSize;
  }

};

} // namespace turtlebot3_msgs


#endif // _TURTLEBOT3_MSGS_SOUND_HPP_
