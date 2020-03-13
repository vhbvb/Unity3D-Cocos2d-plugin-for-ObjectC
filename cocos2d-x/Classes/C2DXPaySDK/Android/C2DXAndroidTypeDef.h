#ifndef __C2DXPAYSDKBRIDGE__C2DXANDROIDTYPEDEF__
#define __C2DXPAYSDKBRIDGE__C2DXANDROIDTYPEDEF__

#include "C2DXPaySDK.h"

#define CREATE_INSTANCE_FUNC(__TYPE__) \
static __TYPE__* create()

namespace mob
{
    namespace paysdk
    {
        typedef std::string C2DXString;
        typedef C2DXPaySDKListener C2DXOnPayListener;
        typedef int64_t C2DXPointer;
    }
}


#endif
