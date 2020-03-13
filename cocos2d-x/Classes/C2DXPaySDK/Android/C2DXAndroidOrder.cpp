#include "C2DXAndroidOrder.h"
#include "JvmJniEnv.h"

using namespace mob::paysdk;


C2DXAndroidOrder::C2DXAndroidOrder()
{

}

C2DXAndroidOrder::~C2DXAndroidOrder()
{

}

C2DXAndroidPayOrder* C2DXAndroidPayOrder::create()
{
    C2DXAndroidPayOrder* p = new C2DXAndroidPayOrder();
    return p;
}

C2DXAndroidPayOrder::C2DXAndroidPayOrder()
{
    JvmJniEnv env;
    jobject javaObject = newJavaInstance(env, "com/mob/paysdk/PayOrder");
    attachJavaObject(env, javaObject);
}

C2DXString C2DXAndroidPayOrder::getOrderNo()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return "";
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getOrderNo", "()Ljava/lang/String;");
    jstring jvalue = (jstring)env->CallObjectMethod(jthiz, jmethod);
    C2DXString ret = env->GetStringUTFChars(jvalue, NULL);
    return ret;
}

void C2DXAndroidPayOrder::setOrderNo(C2DXString orderNo)
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return;
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "setOrderNo", "(Ljava/lang/String;)V");
    jstring jvalue = env->NewStringUTF(orderNo.c_str());
    env->CallVoidMethod(jthiz, jmethod, jvalue);
}

int C2DXAndroidPayOrder::getAmount()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return 0;
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getAmount", "()I");
    int ret = env->CallIntMethod(jthiz, jmethod);
    return ret;
}

void C2DXAndroidPayOrder::setAmount(int amount)
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return;
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "setAmount", "(I)V");
    env->CallVoidMethod(jthiz, jmethod, amount);
}

C2DXString C2DXAndroidPayOrder::getSubject()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return "";
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getSubject", "()Ljava/lang/String;");
    jstring jvalue = (jstring)env->CallObjectMethod(jthiz, jmethod);
    C2DXString ret = env->GetStringUTFChars(jvalue, NULL);
    return ret;
}

void C2DXAndroidPayOrder::setSubject(C2DXString subject)
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return;
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "setSubject", "(Ljava/lang/String;)V");
    jstring jvalue = env->NewStringUTF(subject.c_str());
    env->CallVoidMethod(jthiz, jmethod, jvalue);
}

C2DXString C2DXAndroidPayOrder::getBody()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return "";
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getBody", "()Ljava/lang/String;");
    jstring jvalue = (jstring)env->CallObjectMethod(jthiz, jmethod);
    C2DXString ret = env->GetStringUTFChars(jvalue, NULL);
    return ret;
}

void C2DXAndroidPayOrder::setBody(C2DXString body)
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return;
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "setBody", "(Ljava/lang/String;)V");
    jstring jvalue = env->NewStringUTF(body.c_str());
    env->CallVoidMethod(jthiz, jmethod, jvalue);
}

C2DXString C2DXAndroidPayOrder::getDescription()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return "";
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getDescription", "()Ljava/lang/String;");
    jstring jvalue = (jstring)env->CallObjectMethod(jthiz, jmethod);
    C2DXString ret = env->GetStringUTFChars(jvalue, NULL);
    return ret;
}

void C2DXAndroidPayOrder::setDescription(C2DXString description)
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return;
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "setDescription", "(Ljava/lang/String;)V");
    jstring jvalue = env->NewStringUTF(description.c_str());
    env->CallVoidMethod(jthiz, jmethod, jvalue);
}

C2DXString C2DXAndroidPayOrder::getMetadata()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return "";
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getMetadata", "()Ljava/lang/String;");
    jstring jvalue = (jstring)env->CallObjectMethod(jthiz, jmethod);
    C2DXString ret = env->GetStringUTFChars(jvalue, NULL);
    return ret;
}

void C2DXAndroidPayOrder::setMetadata(C2DXString metadata)
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return;
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "setMetadata", "(Ljava/lang/String;)V");
    jstring jvalue = env->NewStringUTF(metadata.c_str());
    env->CallVoidMethod(jthiz, jmethod, jvalue);
}

C2DXString C2DXAndroidPayOrder::getTicketId()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return "";
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getTicketId", "()Ljava/lang/String;");
    jstring jvalue = (jstring)env->CallObjectMethod(jthiz, jmethod);
    C2DXString ret = env->GetStringUTFChars(jvalue, NULL);
    return ret;
}

C2DXAndroidPayOrder::~C2DXAndroidPayOrder()
{
    JvmJniEnv env;
    detachJavaObject(env, NULL);
}

C2DXAndroidTicketOrder* C2DXAndroidTicketOrder::create()
{
    C2DXAndroidTicketOrder* p = new C2DXAndroidTicketOrder();
    return p;
}


C2DXAndroidTicketOrder::C2DXAndroidTicketOrder()
{
    JvmJniEnv env;
    jobject javaObject = newJavaInstance(env, "com/mob/paysdk/TicketOrder");
    attachJavaObject(env, javaObject);
}

void C2DXAndroidTicketOrder::setTicketId(C2DXString tId)
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return;
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "setTicketId", "(Ljava/lang/String;)V");
    jstring jvalue = env->NewStringUTF(tId.c_str());
    env->CallVoidMethod(jthiz, jmethod, jvalue);
}

C2DXString C2DXAndroidTicketOrder::getTicketId()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return "";
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getTicketId", "()Ljava/lang/String;");
    jstring jvalue = (jstring)env->CallObjectMethod(jthiz, jmethod);
    C2DXString ret = env->GetStringUTFChars(jvalue, NULL);
    return ret;
}



C2DXAndroidTicketOrder::~C2DXAndroidTicketOrder()
{
    JvmJniEnv env;
    detachJavaObject(env, NULL);
}