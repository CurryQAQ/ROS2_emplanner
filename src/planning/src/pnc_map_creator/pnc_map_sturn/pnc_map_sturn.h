#ifndef PNC_MAP_STURN_H_
#define PNC_MAP_STURN_H_

#include "pnc_map_creator_base.h"

namespace Planning
{
    class PncMapSturn: public PncMapCreatorBase
    {
    public:
        PncMapSturn();
        PNCMap create_pnc_map() override;//生成地图
    private:

    };
}  // namespace Planning
#endif  // PNC_MAP_STURN_H_
