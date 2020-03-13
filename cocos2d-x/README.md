# Cocos2dx For PaySDK 快速集成文档

## 下载并导入PaySDK

下载[Cocos2dx-For-PaySDK](https://github.com/MobClub/PaySDK-for-cocos2d-x.git)，clone整个repo可能会很慢，浪费您的时间，最好加上depth=1参数。

```
git clone -b master --depth=1 https://github.com/MobClub/PaySDK-for-cocos2d-x.git
```

下载完成后, 将/Classes/C2DXPaySDK文件夹复制到您的cocos2dx项目/Classes目录下。


## Android端接入

1. 使用Android Studio导入Cocos2dxBridge Module到您的项目中（目录proj.android-studio\Cocos2dxBridge）， 并依赖此module。

2. 在您的Android.mk文件中加入对Cocos2dxBridge module的jni部分(Android.mk文件）的引用，即是引入paysdk_bridge静态库。在您的Android.mk文件中添加如下代码： 
编译需要的cpp源代码(Android.mk)

```
$(call import-add-path,$(LOCAL_PATH)/../../Cocos2dxBridge)
LOCAL_WHOLE_STATIC_LIBRARIES := paysdk_bridge
$(call import-module, jni)
```

如果您不太明白怎么复制这三行配置，可以去参考demo的[Android.mk](https://github.com/MobClub/PaySDK-for-cocos2d-x/blob/SourceCode/proj.android-studio/app/jni/Android.mk)文件。

3. gradle配置

请参考原生Android平台的配置文件中的gradle配置部分或者Demo

[原生MobPaySDK快速集成文档](http://wiki.mob.com/paysdk-%E5%BF%AB%E9%80%9F%E9%9B%86%E6%88%90/)

[demo里gradle的配置](https://github.com/MobClub/PaySDK-for-cocos2d-x/blob/SourceCode/proj.android-studio)

## iOS端接入

#### 配置信息

###### 1. 白名单配置

白名单可参考下图参加

![image.png](https://upload-images.jianshu.io/upload_images/2121032-42e81c4081e61434.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



###### 2. URL Scheme 添加

 URL Schemes 可设置为自己定义的Schemes，也可以使用测试Demo中的，但一定要添加。
 
![image.png](https://upload-images.jianshu.io/upload_images/2121032-dab334384c96e504.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


## 添加代码（伪代码）

###### 1. 创建订单

```
                C2DXPayOrder *order = new C2DXPayOrder();
                order -> subject = "支付subject";
                order -> orderId = "订单ID";
                order -> amount = 支付金额;
                order -> body = "支付主休";
                order -> desc = "支付描述信息";
                order -> metadata = "元数据";
```

###### 2. 创建监听器对象

我这里让当前Scene继承C2DXPaySDKListener接口，在支付的scene里直接使用this就可以了

```
class HelloWorld : public cocos2d::Scene, public C2DXPaySDKListener
{
    bool onWillPay(std::string ticketId);
    void onPayEnd(C2DXPayStatus status, std::string ticketId, int errorCode, std::string errorDes);
}
```

###### 3. 发起支付

调用payWithOrder即可, 第二个参数是枚举类型，表示支付渠道(支付宝、微信、银联等)

```
C2DXPaySDK::payWithOrder(order, C2DXPayChannelAlipay, this);
```


