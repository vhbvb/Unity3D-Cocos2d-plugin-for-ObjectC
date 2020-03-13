package com.mob.paysdk.cocos2dx;

import com.mob.tools.proguard.EverythingKeeper;

public abstract class JavaCxxObject extends Object implements EverythingKeeper {

    private long cxxObject;

    protected void attachCxxObject(long pointer) {
        cxxObject = pointer;
    }

    protected long getCxxObject() {
        return cxxObject;
    }

    protected void detachCxxObject(long pointer) {
        cxxObject = 0;
    }

    protected void jniAttachCxxObject(long pointer) {
        attachCxxObject(pointer);
    }

    protected long jniGetCxxObject() {
        return getCxxObject();
    }


    protected void jniDetachCxxObject(long pointer) {
        detachCxxObject(pointer);
    }

}
