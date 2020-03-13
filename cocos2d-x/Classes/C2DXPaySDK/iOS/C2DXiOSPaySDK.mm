//
//  C2DXiOSPaySDK.cpp
//  Cocos2D-For-PaySDK-mobile
//
//  Created by Max on 2018/1/30.
//

#include "C2DXiOSPaySDK.h"
#include "cocos2d.h"
#import <MOBPaySDK/MOBPay.h>

using namespace paysdk;

@interface C2DXPaySDKObserver: NSObject <MOBPayObserverDelegate>

+ (instancetype)defaultObserver;

@end

@implementation C2DXPaySDKObserver

//static C2DXPaySDKListener *_listener;


+ (instancetype)defaultObserver
{
    static C2DXPaySDKObserver *_instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [[C2DXPaySDKObserver alloc] init];
    });
    return _instance;
}

#pragma mark - 支付完成回调
- (void)paymentTransaction:(MPSPaymentTransaction *)transaction statusDidChange:(MPSPayStatus)status
{
    switch (status) {
            
        case MPSPayStatusBegin: //说明已获取到ticketId开始吊起支付
        C2DXiOSPaySDK::onWillPay(std::string(transaction.ticketId.UTF8String));
            break;
            
        case MPSPayStatusSuccess://支付成功
            
            C2DXiOSPaySDK::onPayEnd(C2DXPayStatusSuccess, std::string(transaction.ticketId.UTF8String), 0, std::string(@"".UTF8String));
            break;
            
        case MPSPayStatusCancel://取消支付
        {
            NSString * str = @"";
            if (transaction.error.description != nil)
            {
                str = transaction.error.description;
            }
            
            C2DXiOSPaySDK::onPayEnd(C2DXPayStatusFail, std::string(transaction.ticketId.UTF8String), (int)transaction.error.code, std::string(str.UTF8String));
        }
            break;
            
        default://支付失败
            
            NSString * str = @"";
            if (transaction.ticketId.length > 0)
            {
                str = transaction.ticketId;
            }
            C2DXiOSPaySDK::onPayEnd(C2DXPayStatusCancel, std::string(str.UTF8String), 0, std::string(@"fail".UTF8String));
            
            break;
    }
}

@end


static C2DXPaySDKListener *_listener;

void C2DXiOSPaySDK::payWithTicketId(std::string ticketId, C2DXPaySDKListener *listener)
{
    [MOBPay addObserver:[C2DXPaySDKObserver defaultObserver]];
    _listener = listener;
    
    NSString *ticketStr = [NSString stringWithCString:ticketId.c_str() encoding:NSUTF8StringEncoding];
    if (ticketStr.length)
    {
        [MOBPay payWithTicketId:ticketStr];
    }
    else
    {
        NSLog(@"PaySDKPlugin_Warn: convert ticketId failed!");
    }
}

void C2DXiOSPaySDK::payWithOrder(C2DXPayOrder *order, int channel, C2DXPaySDKListener *listener)
{
    [MOBPay addObserver:[C2DXPaySDKObserver defaultObserver]];
    _listener = listener;
    
    MPSCharge *charge = [[MPSCharge alloc] init];
    charge.amount = order -> amount;
    charge.channel = (MPSChannel)channel;
    
    const char *orderIdCstring = order -> orderId.c_str();
    if (orderIdCstring != NULL)
    {
         charge.orderId = [NSString stringWithCString:orderIdCstring encoding:NSUTF8StringEncoding];
    }

    const char *subjectCstring = order -> subject.c_str();
    if (subjectCstring != NULL)
    {
        charge.subject = [NSString stringWithCString:subjectCstring encoding:NSUTF8StringEncoding];
    }
    
    const char *bodyCstring = order -> body.c_str();
    if (bodyCstring != NULL)
    {
        charge.body = [NSString stringWithCString:bodyCstring encoding:NSUTF8StringEncoding];
    }
    
    const char *descCstring = order -> desc.c_str();
    if (descCstring != NULL)
    {
        charge.desc = [NSString stringWithCString:descCstring encoding:NSUTF8StringEncoding];
    }
    
    const char *metadataCstring = order -> metadata.c_str();
    if (metadataCstring != NULL)
    {
        charge.metadata = [NSString stringWithCString:metadataCstring encoding:NSUTF8StringEncoding];
    }
    
    const char *appUserIdCstring = order -> appUserId.c_str();
    if (appUserIdCstring != NULL)
    {
        charge.appUserId = [NSString stringWithCString:appUserIdCstring encoding:NSUTF8StringEncoding];
    }
    
    const char *appUserNicknameCstring = order -> appUserNickname.c_str();
    if (appUserNicknameCstring != NULL)
    {
        charge.appUserNickname = [NSString stringWithCString:appUserNicknameCstring encoding:NSUTF8StringEncoding];
    }
    
    [MOBPay payWithCharge:charge];
}

void C2DXiOSPaySDK::setDebugMode(bool enableDebug)
{
    [MOBPay setDebugMode:enableDebug];
}

std::string C2DXiOSPaySDK::getVersion()
{
    NSString *version = [MOBPay version];
    
    return std::string(version.UTF8String);
}

void C2DXiOSPaySDK::onWillPay(std::string ticketId)
{
    _listener -> onWillPay(ticketId);
}

void C2DXiOSPaySDK::onPayEnd(C2DXPayStatus status, std::string ticketId, int errorCode, std::string errorDes)
{
    _listener -> onPayEnd(status, ticketId, errorCode, errorDes);
}
