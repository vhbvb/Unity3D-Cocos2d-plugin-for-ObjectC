#ifndef __C2DXPAYSDKBRIDGE__C2DXANDROIDPAYRESULT__
#define __C2DXPAYSDKBRIDGE__C2DXANDROIDPAYRESULT__

#include "C2DXAndroidTypeDef.h"
#include "C2DXCxxJavaObject.h"

using namespace mob::paysdk;

namespace mob
{
    namespace paysdk
    {
        class C2DXAndroidPayResult : C2DXCxxJavaObject {
        protected:
            C2DXAndroidPayResult();
        public:
            static C2DXAndroidPayResult* create(jobject lRef);
        public:
            int getPayCode();
            C2DXString getPayMessage();
            C2DXString getPayChannelCode();
            C2DXString getPayChannelMessage();
        public:
            virtual ~C2DXAndroidPayResult();
        };
    }
}

#endif
