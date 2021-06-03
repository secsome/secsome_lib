#pragma once

#include <SMath.h>

namespace secsome::randomizer {
    
    // @return a float ranged [-1, 1]
    float hash(int x)
    {
        x = (x << 13) ^ x;
        return (1.0 - ((x * (x * x * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0);
    }


}