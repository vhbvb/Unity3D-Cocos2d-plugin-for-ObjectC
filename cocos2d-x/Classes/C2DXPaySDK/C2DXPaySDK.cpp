//
//  C2DXPaySDK.cpp
//  Cocos2D-For-PaySDK-mobile
//
//  Created by Max on 2018/1/26.
//

#include "C2DXPaySDK.h"
#include "cocos2d.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include "C2DXiOSPaySDK.h"
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "C2DXAndroidPaySDK.h"
#endif

using namespace mob::paysdk;

void C2DXPaySDK::payWithTicketId(std::string ticketId, C2DXPayChannel channel, C2DXPaySDKListener *listener)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    C2DXiOSPaySDK::payWithTicketId(ticketId, listener);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    C2DXAndroidPaySDK::payWithTicketId(ticketId, channel, listener);
#endif
}

void C2DXPaySDK::payWithOrder(C2DXPayOrder *order, C2DXPayChannel channel, C2DXPaySDKListener *listener)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    C2DXiOSPaySDK::payWithOrder(order, channel, listener);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    C2DXAndroidPaySDK::payWithOrder(order, channel, listener);
#endif
}

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
void C2DXPaySDK::setDebugMode(bool enableDebug)
{
    C2DXiOSPaySDK::setDebugMode(enableDebug);
}

std::string C2DXPaySDK::getVersion()
{
    return C2DXAndroidPaySDK::getVersion();

}
#endif


