// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from base_msgs:msg/ReferlinePoint.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "base_msgs/msg/detail/referline_point__rosidl_typesupport_introspection_c.h"
#include "base_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "base_msgs/msg/detail/referline_point__functions.h"
#include "base_msgs/msg/detail/referline_point__struct.h"


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/pose_stamped.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose_stamped__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void base_msgs__msg__ReferlinePoint__rosidl_typesupport_introspection_c__ReferlinePoint_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  base_msgs__msg__ReferlinePoint__init(message_memory);
}

void base_msgs__msg__ReferlinePoint__rosidl_typesupport_introspection_c__ReferlinePoint_fini_function(void * message_memory)
{
  base_msgs__msg__ReferlinePoint__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember base_msgs__msg__ReferlinePoint__rosidl_typesupport_introspection_c__ReferlinePoint_message_member_array[5] = {
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(base_msgs__msg__ReferlinePoint, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rs",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(base_msgs__msg__ReferlinePoint, rs),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rtheta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(base_msgs__msg__ReferlinePoint, rtheta),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rkappa",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(base_msgs__msg__ReferlinePoint, rkappa),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rdkappa",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(base_msgs__msg__ReferlinePoint, rdkappa),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers base_msgs__msg__ReferlinePoint__rosidl_typesupport_introspection_c__ReferlinePoint_message_members = {
  "base_msgs__msg",  // message namespace
  "ReferlinePoint",  // message name
  5,  // number of fields
  sizeof(base_msgs__msg__ReferlinePoint),
  base_msgs__msg__ReferlinePoint__rosidl_typesupport_introspection_c__ReferlinePoint_message_member_array,  // message members
  base_msgs__msg__ReferlinePoint__rosidl_typesupport_introspection_c__ReferlinePoint_init_function,  // function to initialize message memory (memory has to be allocated)
  base_msgs__msg__ReferlinePoint__rosidl_typesupport_introspection_c__ReferlinePoint_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t base_msgs__msg__ReferlinePoint__rosidl_typesupport_introspection_c__ReferlinePoint_message_type_support_handle = {
  0,
  &base_msgs__msg__ReferlinePoint__rosidl_typesupport_introspection_c__ReferlinePoint_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_base_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, base_msgs, msg, ReferlinePoint)() {
  base_msgs__msg__ReferlinePoint__rosidl_typesupport_introspection_c__ReferlinePoint_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PoseStamped)();
  if (!base_msgs__msg__ReferlinePoint__rosidl_typesupport_introspection_c__ReferlinePoint_message_type_support_handle.typesupport_identifier) {
    base_msgs__msg__ReferlinePoint__rosidl_typesupport_introspection_c__ReferlinePoint_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &base_msgs__msg__ReferlinePoint__rosidl_typesupport_introspection_c__ReferlinePoint_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
