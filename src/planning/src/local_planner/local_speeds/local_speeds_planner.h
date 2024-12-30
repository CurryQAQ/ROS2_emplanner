#ifndef LOCAL_SPEEDS_PLANNER_H_
#define LOCAL_SPEEDS_PLANNER_H_

#include "rclcpp/rclcpp.hpp"
#include "config_reader.h"
#include "curve.h"
#include "polynomial_curve.h"
#include "decision_center.h"
#include "local_speeds_smoother.h"




namespace Planning
{
class LocalSpeedsPlanner
{
public:
    LocalSpeedsPlanner();

private:

};
}  // namespace Planning
#endif  // LOCAL_SPEEDS_PLANNER_H_
