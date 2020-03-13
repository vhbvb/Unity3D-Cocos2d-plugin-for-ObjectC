package com.mob.paysdk.cocos2dx;

import com.mob.paysdk.MobPayAPI;
import com.mob.paysdk.Order;
import com.mob.paysdk.PayResult;

/**
 * OnPayListener for cocos2dx.<br/>
 */
public class OnPayListener<T> extends JavaCxxObject implements com.mob.paysdk.OnPayListener<T> {

	public OnPayListener() {
		super();
	}

	@Override
	public boolean onWillPay(String s, T t, MobPayAPI mobPayAPI) {
		long cxxThis = getCxxObject();
		return nativeOnWillPay(cxxThis, s, t, mobPayAPI);
	}

	@Override
	public void onPayEnd(PayResult payResult, T t, MobPayAPI mobPayAPI) {
		long cxxThis = getCxxObject();
		nativeOnPayEnd(cxxThis, payResult, t, mobPayAPI);
	}

	private native boolean nativeOnWillPay(long cxxThis, String s, T t, MobPayAPI mobPayAPI);
	private native void nativeOnPayEnd(long cxxThis, PayResult payResult, T t, MobPayAPI mobPayAPI);
}
