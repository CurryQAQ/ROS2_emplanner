// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from base_msgs:msg/LocalPath.idl
// generated code does not contain a copyright notice
#include "base_msgs/msg/detail/local_path__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `local_path`
#include "base_msgs/msg/detail/local_path_point__functions.h"

bool
base_msgs__msg__LocalPath__init(base_msgs__msg__LocalPath * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    base_msgs__msg__LocalPath__fini(msg);
    return false;
  }
  // local_path
  if (!base_msgs__msg__LocalPathPoint__Sequence__init(&msg->local_path, 0)) {
    base_msgs__msg__LocalPath__fini(msg);
    return false;
  }
  return true;
}

void
base_msgs__msg__LocalPath__fini(base_msgs__msg__LocalPath * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // local_path
  base_msgs__msg__LocalPathPoint__Sequence__fini(&msg->local_path);
}

bool
base_msgs__msg__LocalPath__are_equal(const base_msgs__msg__LocalPath * lhs, const base_msgs__msg__LocalPath * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // local_path
  if (!base_msgs__msg__LocalPathPoint__Sequence__are_equal(
      &(lhs->local_path), &(rhs->local_path)))
  {
    return false;
  }
  return true;
}

bool
base_msgs__msg__LocalPath__copy(
  const base_msgs__msg__LocalPath * input,
  base_msgs__msg__LocalPath * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // local_path
  if (!base_msgs__msg__LocalPathPoint__Sequence__copy(
      &(input->local_path), &(output->local_path)))
  {
    return false;
  }
  return true;
}

base_msgs__msg__LocalPath *
base_msgs__msg__LocalPath__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  base_msgs__msg__LocalPath * msg = (base_msgs__msg__LocalPath *)allocator.allocate(sizeof(base_msgs__msg__LocalPath), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(base_msgs__msg__LocalPath));
  bool success = base_msgs__msg__LocalPath__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
base_msgs__msg__LocalPath__destroy(base_msgs__msg__LocalPath * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    base_msgs__msg__LocalPath__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
base_msgs__msg__LocalPath__Sequence__init(base_msgs__msg__LocalPath__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  base_msgs__msg__LocalPath * data = NULL;

  if (size) {
    data = (base_msgs__msg__LocalPath *)allocator.zero_allocate(size, sizeof(base_msgs__msg__LocalPath), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = base_msgs__msg__LocalPath__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        base_msgs__msg__LocalPath__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
base_msgs__msg__LocalPath__Sequence__fini(base_msgs__msg__LocalPath__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      base_msgs__msg__LocalPath__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

base_msgs__msg__LocalPath__Sequence *
base_msgs__msg__LocalPath__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  base_msgs__msg__LocalPath__Sequence * array = (base_msgs__msg__LocalPath__Sequence *)allocator.allocate(sizeof(base_msgs__msg__LocalPath__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = base_msgs__msg__LocalPath__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
base_msgs__msg__LocalPath__Sequence__destroy(base_msgs__msg__LocalPath__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    base_msgs__msg__LocalPath__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
base_msgs__msg__LocalPath__Sequence__are_equal(const base_msgs__msg__LocalPath__Sequence * lhs, const base_msgs__msg__LocalPath__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!base_msgs__msg__LocalPath__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
base_msgs__msg__LocalPath__Sequence__copy(
  const base_msgs__msg__LocalPath__Sequence * input,
  base_msgs__msg__LocalPath__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(base_msgs__msg__LocalPath);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    base_msgs__msg__LocalPath * data =
      (base_msgs__msg__LocalPath *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!base_msgs__msg__LocalPath__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          base_msgs__msg__LocalPath__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!base_msgs__msg__LocalPath__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
