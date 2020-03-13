
前言
---

在游戏开发中，难免会出现与原生平台有交互才能完成一些特定的必要的功能。比如iOS的内购功能，或者你想用一款第三方SDK，但是此SDK却没有对应平台的版本、并且未提供插件的情况下，就会涉及到与第三方平台的交互。

Unity3D
---

**简介**：Unity3D（以下简称U3D）是由Unity Technologies开发的一个让玩家轻松创建诸如三维视频游戏、建筑可视化、实时三维动画等类型互动内容的多平台的综合型游戏开发工具，是一个全面整合的专业游戏引擎。

#### Unity3D调用原生iOS接口

Unity3D 无法直接调用iOS原生的OC或者swift语言，但是Unity3D使用的C#可以和C进行交互。而C是可以和OC进行交互的。从而就可以实现C#调用OC。

以[ShareSDK](http://sharesdk.mob.com/)的Unity桥接为例：

- 先定义 分享的C语言方法


```objc
void __iosShareSDKShare (int reqID, int platType, void *content, void *observer){

    NSMutableDictionary *shareParams = __getShareParamsWithString(contentStr);
    [ShareSDK share:platType
         parameters:shareParams
     onStateChanged:nil];
}
```

- C#中则可以像下面代码一样进行引入和调用：

```c++
using System.Runtime.InteropServices;

[DllImport("__Internal")]
private static extern void __iosShareSDKShare (int reqID, int platType, string content, string observer);
```

其中DllImport为一个Attribute，目的是通过非托管方式将库中的方法导出到C#中进行使用。而传入"__Internal"则是表示这个是一个静态库或者是一个内部方法。通过上面的声明，这个方法就可以在C#里面进行调用了

比如Unity游戏需要分享的时候直接调用下面方法就可以了：

```
void ShareContent (int reqID, PlatformType platform, ShareContent content) 
{
    __iosShareSDKShare (reqID, (int)platform, content.GetShareParamsStr(), _callbackObjectName);
}
```

#### iOS 调用Unity的接口

在特定场景下也会有iOS接口调用Unity的C#接口的情况，比如分享后回调的分享结果就要传递到原生的unity层。最简单的方式是通过**UnitySendMessage**方法来调用Unity所定义的方法。

仍然以ShareSDK的回调为例：

- 在Unity的里ShareSDK.cs定义一个回调方法

```
private void _Callback (string data) {

    Debug.LogFormat ("result string = {0}", data);
}
```

- 挂载ShareSDK.cs到Main Camera中
- 在OC层，在ShareSDK的分享回调block执行UnitySendMessage

```

    void __iosShareSDKShare (int reqID, int platType, void *content, void *observer)
    {
        NSMutableDictionary *shareParams = __getShareParamsWithString(contentStr);
        
        [ShareSDK share:platType
             parameters:shareParams
         onStateChanged:^(SSDKResponseState state, NSDictionary *userData, SSDKContentEntity *contentEntity, NSError *error) {
            
             NSString *resultStr = nil;
             // process resultStr
             // ...
             UnitySendMessage(observer, "_Callback", [resultStr UTF8String]);
             
        }];
    }

```

其中 observer值为挂载的"Main Camera"

**注意**：UnitySendMessage方式无法同步获取返回值，并且必须要挂载到对象后才能调用，复杂需求可以使用 **非托管的方式**进行交互，具体可以参考：https://www.jianshu.com/p/1ab65bee6692

<br/>

Cocos2d
-

是一个基于MIT协议的开源框架，用于构建游戏、应用程序和其他图形界面交互应用。可以让你在创建自己的多平台游戏时节省很多的时间。

由于主流的cocos2d游戏开发语言是C++,而C++ 和OC是可以直接交互的,只需把OC的实现文件.m修改为.mm即可，那么只需要定义一个C++的接口直接调用OC既可


```objc

typedef void(*C2DXShareResultEvent) (int reqID, C2DXResponseState state, C2DXPlatType platType, C2DXDictionary *res);

void C2DXiOSShareSDK::shareContent(int reqID,C2DXPlatType platType, C2DXDictionary *content,bool useClientShare, C2DXShareResultEvent callback) {
    NSMutableDictionary *parameters = convertPublishContent(content);
    [ShareSDK share:(SSDKPlatformType)platType
         parameters:parameters
     onStateChanged:^(SSDKResponseState state, NSDictionary *userData, SSDKContentEntity *contentEntity, NSError *error) {
     
     // process callback ...
     
     //callback
     callback(reqID,(C2DXResponseState)state,(C2DXPlatType)platType,userInfoDict);
    }];
}
```
