#include "C2DXAndroidPayResult.h"

C2DXAndroidPayResult::C2DXAndroidPayResult()
{

}

C2DXAndroidPayResult* C2DXAndroidPayResult::create(jobject lRef)
{
    C2DXAndroidPayResult* payResult = new C2DXAndroidPayResult();
    JvmJniEnv env;
    payResult->attachJavaObject(env, lRef);
    return payResult;
}


int C2DXAndroidPayResult::getPayCode()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return 0;
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getPayCode", "()I");
    jint jvalue = env->CallIntMethod(jthiz, jmethod);
    return jvalue;
}

C2DXString C2DXAndroidPayResult::getPayMessage()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return "";
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getPayMessage", "()Ljava/lang/String;");
    jstring jvalue = (jstring)env->CallObjectMethod(jthiz, jmethod);
    C2DXString ret = env->GetStringUTFChars(jvalue, NULL);
    return ret;
}

C2DXString C2DXAndroidPayResult::getPayChannelCode()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return "";
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getPayChannelCode", "()Ljava/lang/String;");
    jstring jvalue = (jstring)env->CallObjectMethod(jthiz, jmethod);
    if (NULL != jvalue) {
        const char * cvalue = env->GetStringUTFChars(jvalue, NULL);
        C2DXString ret = cvalue;
        env->ReleaseStringUTFChars(jvalue, cvalue);
        return ret;
    } else {
        return "";
    }
}

C2DXString C2DXAndroidPayResult::getPayChannelMessage()
{
    JvmJniEnv env;
    jobject jthiz = getLocalJavaObject(env);
    if (NULL == jthiz) {
        return "";
    }
    jclass jclazz = env->GetObjectClass(jthiz);
    jmethodID jmethod = env->GetMethodID(jclazz, "getPayChannelMessage", "()Ljava/lang/String;");
    jstring jvalue = (jstring)env->CallObjectMethod(jthiz, jmethod);
    if (NULL != jvalue) {
        const char * cvalue = env->GetStringUTFChars(jvalue, NULL);
        C2DXString ret = cvalue;
        env->ReleaseStringUTFChars(jvalue, cvalue);
        return ret;
    } else {
        return "";
    }
}

C2DXAndroidPayResult::~C2DXAndroidPayResult()
{
}

