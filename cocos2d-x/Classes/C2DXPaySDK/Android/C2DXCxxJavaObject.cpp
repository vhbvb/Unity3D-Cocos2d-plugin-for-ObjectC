#include "C2DXCxxJavaObject.h"

using namespace mob::paysdk;

jobject C2DXCxxJavaObject::newJavaInstance(JNIEnv* env, const char* clazz)
{
    jclass jclazz = env->FindClass(clazz);
    jmethodID jConstructor = env->GetMethodID(jclazz, "<init>", "()V");
    return env->NewObject(jclazz, jConstructor);
}

jclass C2DXCxxJavaObject::getJavaClass(JNIEnv* env, jobject jo)
{
    return env->GetObjectClass(jo);
}

jmethodID C2DXCxxJavaObject::getJavaMethodID(JNIEnv* env, jclass clazz, const char* name, const char* sig)
{
    return env->GetMethodID(clazz, name, sig);
}

C2DXCxxJavaObject::C2DXCxxJavaObject()
{
    javaObjec = NULL;
}

void C2DXCxxJavaObject::attachJavaObject(JNIEnv* env, jobject lRef)
{
    jobject gRef = javaObjec;
    if (NULL != gRef) {
        detachJavaObject(env, lRef);
    }
    gRef = env->NewGlobalRef(lRef);
	javaObjec = gRef;
}

jobject C2DXCxxJavaObject::getLocalJavaObject(JNIEnv* env)
{
    jobject gRef = javaObjec;
    if (NULL == gRef) {
        return NULL;
    }
    jobject jret = env->NewLocalRef(gRef);
    return jret;

}

void C2DXCxxJavaObject::detachJavaObject(JNIEnv* env, jobject lRef)
{
    jobject gRef = javaObjec;
    if (NULL != gRef) {
        env->DeleteGlobalRef(gRef);
	    javaObjec = NULL;
    }
}

jobject C2DXCxxJavaObject::getJavaObject()
{
    return javaObjec;
}

C2DXCxxJavaObject::~C2DXCxxJavaObject()
{
    JvmJniEnv jniEnv;
    detachJavaObject(jniEnv, NULL);
}






