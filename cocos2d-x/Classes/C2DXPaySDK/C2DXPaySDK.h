//
//  C2DXPaySDK.hpp
//  Cocos2D-For-PaySDK-mobile
//
//  Created by Max on 2018/1/26.
//

#ifndef C2DXPaySDK_h
#define C2DXPaySDK_h

#include <stdio.h>
#include "iostream"

using namespace std;

namespace mob {
    namespace paysdk {
        //支付平台
        enum C2DXPayChannel {
            C2DXPayChannelWechat = 22,
            C2DXPayChannelAlipay = 50,
            C2DXPayChannelUnionPay = 53
        };

        //支付状态
        enum C2DXPayStatus {
            C2DXPayStatusSuccess = 0,
            C2DXPayStatusFail = 1,
            C2DXPayStatusCancel = 2,
            C2DXPayStatusUnknow = 3
        };

        //支付订单
        class C2DXPayOrder {
        public:
            /**
             * 设置支付订单号 (必要）
             */
            std::string orderId;

            /**
             * 支付金额, 单位：分.(必要）
             */
            int amount;

            /**
             * 支付标题 (必要）
             */
            std::string subject;

            /**
             * 支付主体 (可选）
             */
            std::string body;

            /**
             * 描述 (可选）
             */
            std::string desc;

            /**
             * 设置元数据 (可选）
             */
            std::string metadata;

            /**
             * 商户用户Id (可选）
             */
            std::string appUserId;

            /**
             * 商户用户昵称 (可选）
             */
            std::string appUserNickname;
        };

        //支付结果监听
        class C2DXPaySDKListener {
        public:

            /**
             获取到ticketId准备支付
             */
            virtual bool onWillPay(std::string ticketId) = 0;

            /**
             支付结果
             */
            virtual void onPayEnd(C2DXPayStatus status, std::string ticketId, int errorCode,
                                  std::string errorDes) = 0;
        };

        //支付接口
        class C2DXPaySDK {
        public:
            /**
             通过ticketId支付

             @param ticketId 支付
             */
            static void payWithTicketId(std::string ticketId, C2DXPayChannel channel,
                                        C2DXPaySDKListener *listener);

            /**
             支付订单

             @param order 通过
             */
            static void
            payWithOrder(C2DXPayOrder *order, C2DXPayChannel channel, C2DXPaySDKListener *listener);

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
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
#endif
        };
    }
}

#endif /* C2DXPaySDK_hpp */
