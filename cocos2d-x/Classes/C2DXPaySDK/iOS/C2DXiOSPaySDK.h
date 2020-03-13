//
//  C2DXiOSPaySDK.hpp
//  Cocos2D-For-PaySDK-mobile
//
//  Created by Max on 2018/1/30.
//

#ifndef C2DXiOSPaySDK_h
#define C2DXiOSPaySDK_h

#include <stdio.h>
#include "cocos2d.h"
#include "C2DXPaySDK.h"

using namespace mob::paysdk;

namespace paysdk
{
    class C2DXiOSPaySDK
    {
        public:
        /**
         通过ticketId支付
         
         @param ticketId 支付
         */
        static void payWithTicketId(std::string ticketId, C2DXPaySDKListener *listener);
        
        /**
         支付订单
         
         @param order 通过
         */
        static void payWithOrder(C2DXPayOrder *order, int channel, C2DXPaySDKListener *listener);
        
        /**
         开启debugLog iOS only
         
         @param enableDebug 是否开启日志
         */
        static void setDebugMode(bool enableDebug);
        
        /**
         获取版本号

         @return 版本号
         */
        static std::string getVersion();
        
        //callback
        static void onWillPay(std::string ticketId);
        static void onPayEnd(C2DXPayStatus status, std::string ticketId, int errorCode, std::string errorDes);
    };
}

#endif /* C2DXiOSPaySDK_hpp */
