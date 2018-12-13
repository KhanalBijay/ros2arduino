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
 * @file Duration.hpp
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _BUILTIN_INTERFACES_DURATION_HPP_
#define _BUILTIN_INTERFACES_DURATION_HPP_


#include <topic.hpp>

namespace builtin_interfaces {


/*!
 * @brief This class represents the structure Duration defined by the user in the IDL file.
 * @ingroup DURATION
 */
class Duration : public ros2::Topic<Duration>
{
public: 
  int32_t sec_;
  uint32_t nanosec_;

  Duration():
    Topic("builtin_interfaces::msg::dds_::Duration_", "Duration"),
    sec_(0), nanosec_(0)
  {
  }

  bool serialize(struct MicroBuffer* writer, const Duration* topic)
  {
    (void) serialize_int32_t(writer, topic->sec_);
    (void) serialize_uint32_t(writer, topic->nanosec_);

    return writer->error == BUFFER_OK;
  }

  bool deserialize(struct MicroBuffer* reader, Duration* topic)
  {
    (void) deserialize_int32_t(reader, &topic->sec_);
    (void) deserialize_uint32_t(reader, &topic->nanosec_);

    return reader->error == BUFFER_OK;
  }

  uint32_t size_of_topic(const Duration* topic, uint32_t size)
  {
    (void)(topic);

    size += 4 + get_alignment(size, 4);
    size += 4 + get_alignment(size, 4);

    return size;
  }

};

} // namespace builtin_interfaces


#endif // _BUILTIN_INTERFACES_DURATION_HPP_
