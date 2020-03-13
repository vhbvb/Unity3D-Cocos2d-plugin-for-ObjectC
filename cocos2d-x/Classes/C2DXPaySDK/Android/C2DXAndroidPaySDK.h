
#ifndef __C2DXPAYSDKBRIDGE__C2DXANDROIDONPAYSDK__
#define __C2DXPAYSDKBRIDGE__C2DXANDROIDONPAYSDK__

#include <stdio.h>
#include "cocos2d.h"
#include "C2DXPaySDK.h"
#include "C2DXAndroidTypeDef.h"

namespace mob {
    namespace paysdk {
        class C2DXAndroidPaySDK {
        public:
            /**
             通过ticketId支付

             @param ticketId 支付
             */
            static void payWithTicketId(C2DXString ticketId, C2DXPayChannel, C2DXPaySDKListener *listener);

            /**
             支付订单

             @param order 通过
             */
            static void
            payWithOrder(C2DXPayOrder *order, C2DXPayChannel channel, C2DXPaySDKListener *listener);


            //callback
            static void onWillPay(C2DXString ticketId);

            static void onPayEnd(C2DXPayStatus status, C2DXString ticketId, int errorCode,
                                 C2DXString errorDes);
        };
    }
}

#endif
