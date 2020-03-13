#include "C2DXAndroidPayApi.h"
#include "C2DXAndroidOrder.h"
#include "JvmJniEnv.h"
#include "C2DXAndroidOnPayListener.h"

C2DXAndroidPayApi::C2DXAndroidPayApi()
{
}

void C2DXAndroidPayApi::pay(C2DXAndroidPayOrder* order, C2DXOnPayListener* callback)
{
    JvmJniEnv env;
    jobject jApi = getLocalJavaObject(env);
    jclass jApiClazz = getJavaClass(env, jApi);
    jmethodID jApiPayMethod = getJavaMethodID(env, jApiClazz, "pay",
                                              "(Lcom/mob/paysdk/Order;Lcom/mob/paysdk/OnPayListener;)V");

    jobject jorder = order->getLocalJavaObject(env);

    C2DXAndroidOnPayListener* cxx = C2DXAndroidOnPayListener::create();
    cxx->setOrder(order); cxx->setPayApi(this);	cxx->setOnPayListener(callback);
    jobject jListener = cxx->getLocalJavaObject(env);

    env->CallVoidMethod(jApi, jApiPayMethod, jorder, jListener);
}


void C2DXAndroidPayApi::pay(C2DXAndroidTicketOrder* order, C2DXOnPayListener* callback)
{
    JvmJniEnv env;
    jobject jApi = getLocalJavaObject(env);
    jclass jApiClazz = getJavaClass(env, jApi);
    jmethodID jApiPayMethod = getJavaMethodID(env, jApiClazz, "pay",
                                              "(Lcom/mob/paysdk/Order;Lcom/mob/paysdk/OnPayListener;)V");

    jobject jorder = order->getLocalJavaObject(env);

    C2DXAndroidOnPayListener* cxx = C2DXAndroidOnPayListener::create();
    cxx->setOrder(order); cxx->setPayApi(this);	cxx->setOnPayListener(callback);
    jobject jListener = cxx->getLocalJavaObject(env);

    env->CallVoidMethod(jApi, jApiPayMethod, jorder, jListener);
}

C2DXAndroidPayApi::~C2DXAndroidPayApi()
{
}

C2DXAndroidAliApi* C2DXAndroidAliApi::create()
{

    return new C2DXAndroidAliApi();
}

C2DXAndroidAliApi::C2DXAndroidAliApi()
{
    JvmJniEnv env;
    jobject javaObject = newJavaInstance(env, "com/mob/paysdk/AliPayAPI");
    attachJavaObject(env, javaObject);
}

C2DXAndroidAliApi::~C2DXAndroidAliApi()
{

}

C2DXAndroidWxApi* C2DXAndroidWxApi::create()
{
    return new C2DXAndroidWxApi();
}

C2DXAndroidWxApi::C2DXAndroidWxApi()
{
    JvmJniEnv env;
    jobject javaObject = newJavaInstance(env, "com/mob/paysdk/WXPayAPI");
    attachJavaObject(env, javaObject);
}

C2DXAndroidWxApi::~C2DXAndroidWxApi()
{
}

C2DXAndroidUnionApi* C2DXAndroidUnionApi::create()
{
    return new C2DXAndroidUnionApi();
}

C2DXAndroidUnionApi::C2DXAndroidUnionApi()
{
    JvmJniEnv env;
    jobject javaObject = newJavaInstance(env, "com/mob/paysdk/UnionPayAPI");
    attachJavaObject(env, javaObject);
}

C2DXAndroidUnionApi::~C2DXAndroidUnionApi()
{
}


