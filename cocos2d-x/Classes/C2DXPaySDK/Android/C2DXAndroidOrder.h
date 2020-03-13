#ifndef __C2DXPAYSDKBRIDGE__C2DXANDROIDORDER__
#define __C2DXPAYSDKBRIDGE__C2DXANDROIDORDER__

#include <stdio.h>
#include "jni.h"
#include "C2DXCxxJavaObject.h"
#include "C2DXAndroidTypeDef.h"

namespace mob
{
    namespace paysdk
    {
        class C2DXAndroidOrder : public C2DXCxxJavaObject
        {
        protected:
            C2DXAndroidOrder();
        public:
            virtual C2DXString getTicketId() = 0;
        public:
            ~C2DXAndroidOrder();
        };

        class C2DXAndroidPayOrder : public C2DXAndroidOrder
        {
        public:
            CREATE_INSTANCE_FUNC(C2DXAndroidPayOrder);

            /**
             * 获取之前配置的支付订单号
             * @return 订单号
             */
            virtual C2DXString getOrderNo();

            /**
             * 设置支付订单号
             * @param orderNo 订单号
             */
            virtual void setOrderNo(C2DXString orderNo);

            /**
             * 获取之前配置的支付金额, 单位：分.
             * @return 支付金额
             */
            virtual int getAmount();

            /**
             * 设置支付金额, 单位：分.
             * @param amount 支付金额
             */
            virtual void setAmount(int amount);

            /**
             * 获取之前配置的支付标题, 支付时展示
             * @return 支付标题
             */
            virtual C2DXString getSubject();

            /**
             * 设置支付标题, 支付时展示
             * @param subject 支付标题
             */
            virtual void setSubject(C2DXString subject);

            /**
             * 获取之前配置的支付主体, 支付时展示
             * @return 支付主体
             */
            virtual C2DXString getBody();

            /**
             * 设置支付主体, 支付时展示
             * @return 支付主体
             */
            virtual void setBody(C2DXString body);

            virtual C2DXString getDescription();

            virtual void setDescription(C2DXString description);

            virtual C2DXString getMetadata();

            virtual void setMetadata(C2DXString metadata);

            /**
             * 获取ticketId
             * @return ticketId
             */
            virtual C2DXString getTicketId();

        private:
            C2DXAndroidPayOrder();
        public:
            virtual ~C2DXAndroidPayOrder();
        };


        class C2DXAndroidTicketOrder : public C2DXAndroidOrder
        {

        public:
            CREATE_INSTANCE_FUNC(C2DXAndroidTicketOrder);

            /**
             * 设置ticketId
             * @param tId ticketId
             */
            virtual void setTicketId(C2DXString tId);

            /**
             * 获取ticketId
             * @return ticketId
             */
            virtual C2DXString getTicketId();

        private:
            C2DXAndroidTicketOrder();

        public:
            virtual ~C2DXAndroidTicketOrder();
        };
    }
}

#endif
