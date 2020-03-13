#include "C2DXAndroidOnPayListener.h"
#include "JvmJniEnv.h"
#include "C2DXAndroidPayResult.h"
#include <cstdlib>

C2DXAndroidOnPayListener* C2DXAndroidOnPayListener::create()
{
    JvmJniEnv env;
    jobject object = newJavaInstance(env, "com/mob/paysdk/cocos2dx/OnPayListener");
    C2DXAndroidOnPayListener* cxxOjbect = new C2DXAndroidOnPayListener();
    cxxOjbect->attachJavaObject(env, object);
    return cxxOjbect;
}

C2DXAndroidOnPayListener::C2DXAndroidOnPayListener()
{
    order = NULL;
    api = NULL;
    onPayListener = NULL;
}

void C2DXAndroidOnPayListener::setOnPayListener(C2DXOnPayListener* callback)
{
    onPayListener = callback;
}

C2DXOnPayListener* C2DXAndroidOnPayListener::getOnPayListener()
{
    return onPayListener;
}

void C2DXAndroidOnPayListener::setOrder(C2DXAndroidOrder* o)
{
    order = o;
}

C2DXAndroidOrder* C2DXAndroidOnPayListener::getOrder()
{
    return order;
}

void C2DXAndroidOnPayListener::setPayApi(C2DXAndroidPayApi* a)
{
    api = a;
}
C2DXAndroidPayApi* C2DXAndroidOnPayListener::getPayApi()
{
    return api;
}

/**
 * 重写目的是实现强组合关系(双向引用), 父类只实现了单项引用java.<br/>
 * 这里再实现java引用c++.
 * @param env
 * @param lRef
 */
void C2DXAndroidOnPayListener::attachJavaObject(JNIEnv* env, jobject lRef)
{
    C2DXCxxJavaObject::attachJavaObject(env, lRef);
    lRef = getLocalJavaObject(env);
    if (NULL != lRef) {
        jclass jclazz = getJavaClass(env, lRef);
        C2DXPointer cxxObject = (C2DXPointer)((C2DXCxxJavaObject*)this);
        jmethodID jMethod = getJavaMethodID(env, jclazz, "jniAttachCxxObject", "(J)V");
        env->CallVoidMethod(lRef, jMethod, (jlong)cxxObject);
    }
}

/**
 * 拆除强组合关系
 * @param env
 * @param lRef
 */
void C2DXAndroidOnPayListener::detachJavaObject(JNIEnv* env, jobject lRef)
{
    lRef = getLocalJavaObject(env);
    if (NULL != lRef) {
        jclass jclazz = getJavaClass(env, lRef);
        C2DXPointer cxxObject = (C2DXPointer)((C2DXCxxJavaObject*)this);
        jmethodID jMethod = getJavaMethodID(env, jclazz, "jniDetachCxxObject", "(J)V");
        env->CallVoidMethod(lRef, jMethod, (jlong)cxxObject);
    }
    C2DXCxxJavaObject::detachJavaObject(env, lRef);
}

bool C2DXAndroidOnPayListener::onWillPay(JNIEnv *env, jstring jTicketId, jobject jOrder, jobject jApi)
{
    bool handled = false;
    C2DXOnPayListener* callback = getOnPayListener();
    if (NULL != callback) {
        const char* cxxTicketId = env->GetStringUTFChars(jTicketId, NULL);
        C2DXString ticketId = cxxTicketId;
        env->ReleaseStringUTFChars(jTicketId, cxxTicketId);
        return callback->onWillPay(ticketId);
    }
    return handled;
}

void C2DXAndroidOnPayListener::onPayEnd(JNIEnv *env, jobject jResult, jobject jOrder, jobject jApi)
{
    C2DXOnPayListener* callback = getOnPayListener();
    if (NULL != callback) {
        C2DXAndroidPayResult* result = C2DXAndroidPayResult::create(jResult);
        int payCode = result->getPayCode();
        C2DXAndroidOrder* order = getOrder();
        int channelCode = atoi(result->getPayChannelCode().c_str());
        C2DXString channelMessage = result->getPayChannelMessage();
        callback->onPayEnd(toPayStatus(payCode), order->getTicketId(), channelCode, channelMessage);
    }
}

C2DXPayStatus C2DXAndroidOnPayListener::toPayStatus(int payCode)
{
    if (0000 == payCode) {
        return C2DXPayStatusSuccess;
    } else if (1200 == payCode) {
        return C2DXPayStatusCancel;
    } else if (1300 == payCode) {
        return C2DXPayStatusUnknow;
    } else {
        return C2DXPayStatusFail;
    }
}

C2DXAndroidOnPayListener::~C2DXAndroidOnPayListener()
{

}

bool mob::paysdk::androidOnWillPay(JNIEnv *env, void* cxx, jstring jTicketId, jobject jOrder, jobject jApi)
{
    C2DXCxxJavaObject* attachCxxObject = (C2DXCxxJavaObject*)cxx;
    C2DXAndroidOnPayListener* p = dynamic_cast<C2DXAndroidOnPayListener*>(attachCxxObject);
    return p->onWillPay(env, jTicketId, jOrder, jApi);
}

void mob::paysdk::androidOnPayEnd(JNIEnv *env, void* cxx, jobject jResult, jobject jOrder, jobject jApi)
{
    C2DXCxxJavaObject* attachCxxObject = (C2DXCxxJavaObject*)cxx;
    C2DXAndroidOnPayListener* p = dynamic_cast<C2DXAndroidOnPayListener*>(attachCxxObject);
    p->onPayEnd(env, jResult, jOrder, jApi);
}





