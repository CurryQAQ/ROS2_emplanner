#ifndef PNC_MAP_STRAIGHT_H_
#define PNC_MAP_STRAIGHT_H_

#include "pnc_map_creator_base.h"

namespace Planning
{
    class PncMapStraight: public PncMapCreatorBase
    {
    public:
        PncMapStraight();
        PNCMap create_pnc_map() override;//生成地图
        
    private:

    };
}  // namespace Planning
#endif  // PNC_MAP_STRAIGHT_H_
