#ifndef GLOBAL_PLANNER_NORMAL_H_
#define GLOBAL_PLANNER_NORMAL_H_

#include "global_planner_base.h"

namespace Planning
{
    class GlobalPlannerNormal: public GlobalPathBase
    {
    public:
        GlobalPlannerNormal();
        Path search_global_path(const PncMap &pnc_map) override;
    private:

    };
}  // namespace Planning
#endif  // GLOBAL_PLANNER_NORMAL_H_
