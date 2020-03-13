#include "C2DXAndroidPaySDK.h"
#include "JvmJniEnv.h"
#include "C2DXAndroidOrder.h"
#include "C2DXPaySDK.h"
#include "C2DXAndroidPayApi.h"
#include "C2DXAndroidOnPayListener.h"

using namespace mob::paysdk;

void C2DXAndroidPaySDK::payWithTicketId(std::string ticketId, C2DXPayChannel channel, C2DXPaySDKListener *listener)
{
    C2DXAndroidTicketOrder* dOrder = C2DXAndroidTicketOrder::create();
    dOrder->setTicketId(ticketId);

    if (C2DXPayChannelAlipay == channel) {
        C2DXAndroidAliApi* api = C2DXAndroidAliApi::create();
        api->pay(dOrder, listener);
    } else if (C2DXPayChannelWechat == channel) {
        C2DXAndroidWxApi* api = C2DXAndroidWxApi::create();
        api->pay(dOrder, listener);
    } else if (C2DXPayChannelUnionPay == channel) {
        C2DXAndroidUnionApi* api = C2DXAndroidUnionApi::create();
        api->pay(dOrder, listener);
    }
}

void C2DXAndroidPaySDK::payWithOrder(C2DXPayOrder *order, C2DXPayChannel channel, C2DXPaySDKListener *listener)
{
    C2DXAndroidPayOrder* dOrder = C2DXAndroidPayOrder::create();
    dOrder->setAmount(order->amount);
    dOrder->setBody(order->body);
    dOrder->setSubject(order->subject);
    dOrder->setOrderNo(order->orderId);
    dOrder->setMetadata(order->metadata);
    dOrder->setDescription(order->desc);

    if (C2DXPayChannelAlipay == channel) {
        C2DXAndroidAliApi* api = C2DXAndroidAliApi::create();
        api->pay(dOrder, listener);
    } else if (C2DXPayChannelWechat == channel) {
        C2DXAndroidWxApi* api = C2DXAndroidWxApi::create();
        api->pay(dOrder, listener);
    } else if (C2DXPayChannelUnionPay == channel) {
        C2DXAndroidUnionApi* api = C2DXAndroidUnionApi::create();
        api->pay(dOrder, listener);
    }
}

void C2DXAndroidPaySDK::onWillPay(C2DXString ticketId)
{

}

void C2DXAndroidPaySDK::onPayEnd(paysdk::C2DXPayStatus status, C2DXString ticketId, int errorCode, C2DXString errorDes)
{

}
