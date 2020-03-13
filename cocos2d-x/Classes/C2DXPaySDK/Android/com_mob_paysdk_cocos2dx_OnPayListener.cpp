#include "com_mob_paysdk_cocos2dx_OnPayListener.h"
#include "C2DXAndroidOnPayListener.h"

JNIEXPORT jboolean JNICALL Java_com_mob_paysdk_cocos2dx_OnPayListener_nativeOnWillPay
  (JNIEnv *env, jobject, jlong jcxx, jstring jTicketId, jobject jOrder, jobject jApi)
{
    void * cxx = (void *) jcxx;
    return mob::paysdk::androidOnWillPay(env, cxx, jTicketId, jOrder, jApi);
}


JNIEXPORT void JNICALL Java_com_mob_paysdk_cocos2dx_OnPayListener_nativeOnPayEnd
  (JNIEnv *env, jobject, jlong jcxx, jobject jResult, jobject jOrder, jobject jApi)
{
    void * cxx = (void *) jcxx;
    mob::paysdk::androidOnPayEnd(env, cxx, jResult, jOrder, jApi);
}
