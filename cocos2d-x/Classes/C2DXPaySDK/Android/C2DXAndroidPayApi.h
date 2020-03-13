#ifndef __C2DXPAYSDKBRIDGE__C2DXANDROIDALIAPI__
#define __C2DXPAYSDKBRIDGE__C2DXANDROIDALIAPI__

#include "C2DXCxxJavaObject.h"
#include "C2DXPaySDK.h"
#include "C2DXAndroidOrder.h"
#include "C2DXAndroidTypeDef.h"

using namespace mob::paysdk;

namespace mob
{
    namespace paysdk
    {
        class C2DXAndroidPayApi : public C2DXCxxJavaObject {
        protected:
            C2DXAndroidPayApi();
        public:
            virtual void pay(C2DXAndroidPayOrder* order, C2DXOnPayListener* callback);
            virtual void pay(C2DXAndroidTicketOrder* order, C2DXOnPayListener* callback);
            virtual ~C2DXAndroidPayApi();
        };

        class C2DXAndroidAliApi : public C2DXAndroidPayApi {
        private:
            C2DXAndroidAliApi();
        public:
            CREATE_INSTANCE_FUNC(C2DXAndroidAliApi);
        public:
            virtual ~C2DXAndroidAliApi();
        };

        class C2DXAndroidWxApi : public C2DXAndroidPayApi {
        private:
            C2DXAndroidWxApi();
        public:
            CREATE_INSTANCE_FUNC(C2DXAndroidWxApi);
        public:
            virtual ~C2DXAndroidWxApi();
        };

        class C2DXAndroidUnionApi : public C2DXAndroidPayApi {
        private:
            C2DXAndroidUnionApi();
        public:
            CREATE_INSTANCE_FUNC(C2DXAndroidUnionApi);
        public:
            virtual ~C2DXAndroidUnionApi();
        };
    }
}

#endif