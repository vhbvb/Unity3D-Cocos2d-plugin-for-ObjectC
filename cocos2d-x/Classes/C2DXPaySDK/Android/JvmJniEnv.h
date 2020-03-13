#ifndef __C2DXPAYSDKBRIDGE__JVMJNIENV__
#define __C2DXPAYSDKBRIDGE__JVMJNIENV__

#include <stdio.h>
#include "jni/JniHelper.h"

USING_NS_CC;

namespace mob
{
    namespace paysdk
    {
        class JvmJniEnv {
        public:
            JvmJniEnv() {
                env = JniHelper::getEnv();
                env->PushLocalFrame(64);
            };

            operator JNIEnv*() {
                return env;
            };

            JNIEnv* operator->() {
                return env;
            }

            ~JvmJniEnv() {
                env->PopLocalFrame(NULL);
            };
        private:
            JNIEnv* env;
        };



    }
}

#endif
