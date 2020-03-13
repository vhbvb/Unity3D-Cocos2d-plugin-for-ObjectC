#ifndef __C2DXPAYSDKBRIDGE__C2DXANDROIDONPAYLISTENER__
#define __C2DXPAYSDKBRIDGE__C2DXANDROIDONPAYLISTENER__

#include "C2DXCxxJavaObject.h"
#include "C2DXPaySDK.h"
#include "JvmJniEnv.h"
#include "C2DXAndroidOrder.h"
#include "C2DXAndroidPayApi.h"
#include "C2DXAndroidTypeDef.h"

using namespace mob::paysdk;

namespace mob
{
    namespace paysdk
    {
        class C2DXAndroidOnPayListener : public C2DXCxxJavaObject {
        public:
            CREATE_INSTANCE_FUNC(C2DXAndroidOnPayListener);
        private:
            C2DXAndroidOnPayListener();
        public:
	        virtual void attachJavaObject(JNIEnv* env, jobject lRef);
	        virtual void detachJavaObject(JNIEnv* env, jobject lRef);
        public:
            void setOnPayListener(C2DXOnPayListener* callback);
            C2DXOnPayListener* getOnPayListener();
	        void setOrder(C2DXAndroidOrder* o);
			C2DXAndroidOrder* getOrder();
	        void setPayApi(C2DXAndroidPayApi* a);
			C2DXAndroidPayApi* getPayApi();
        public:
            bool onWillPay(JNIEnv *env, jstring jTicketId, jobject jOrder, jobject jApi);
            void onPayEnd(JNIEnv *env, jobject jResult, jobject jOrder, jobject jApi);
            C2DXPayStatus toPayStatus(int payCode);
        private:
            C2DXOnPayListener* onPayListener;
            C2DXAndroidOrder* order;
            C2DXAndroidPayApi* api;
        public:
            virtual ~C2DXAndroidOnPayListener();
        };

        bool androidOnWillPay(JNIEnv *env, void* cxx, jstring jTicketId, jobject jOrder, jobject jApi);
        void androidOnPayEnd(JNIEnv *env, void* cxx, jobject jResult, jobject jOrder, jobject jApi);
    }
}

#endif