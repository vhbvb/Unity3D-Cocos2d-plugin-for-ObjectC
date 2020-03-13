/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "C2DXPaySDK.h"
#include "string"
#include <ui/UIButton.h>

//#include <ui/UIButton.h>
//#include "HelloWorldScene.h"
//#include "C2DXPaySDK.h"
//#include "string"

USING_NS_CC;

using namespace cocos2d::ui;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    C2DXPaySDK::setDebugMode(true);
#endif
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto button = Button::create();
    button->setTitleText("支付宝支付");
    button->setPosition(Vec2(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - 100));
    button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED: {
                C2DXPayOrder *order = new C2DXPayOrder();
                order -> subject = "orderSubject";
                order -> orderId = getOutOrderNO();
                order -> amount = 1;
                order -> body = "order_body";
                order -> desc = "order_desc";
                order -> metadata = "order_metaData";
                order -> appUserId = "userId";
                order -> appUserNickname = "nickName";
                C2DXPaySDK::payWithOrder(order, C2DXPayChannelAlipay, this);
                
            }
                break;
            default:
                break;
        }
    });
    this->addChild(button);
    
    button = Button::create();
    button->setTitleText("微信支付");
    button->setPosition(Vec2(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - 150));
    button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED: {
                C2DXPayOrder *order = new C2DXPayOrder();
                order -> subject = "orderSubject";
                order -> orderId = getOutOrderNO();
                order -> amount = 1;
                order -> body = "order_body";
                order -> desc = "order_desc";
                order -> metadata = "order_metaData";
                order -> appUserId = "userId";
                order -> appUserNickname = "nickName";
                C2DXPaySDK::payWithOrder(order, C2DXPayChannelWechat, this);
            }
                break;
            default:
                break;
        }
    });
    this->addChild(button);
    
    //------
    //添加银联支付
    button = Button::create();
    button->setTitleText("银联支付");
    button->setPosition(Vec2(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - 200));
    button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED: {
                C2DXPayOrder *order = new C2DXPayOrder();
                order -> subject = "orderSubject";
//                order -> orderId = "12783755905843";
                order -> orderId = getrandomStr();
                order -> amount = 1;
                order -> body = "order_body";
                order -> desc = "order_desc";
                order -> metadata = "order_metaData";
                order -> appUserId = "userId";
                order -> appUserNickname = "nickName";
                C2DXPaySDK::payWithOrder(order, C2DXPayChannelUnionPay, this);
            }
                break;
            default:
                break;
        }
    });
    this->addChild(button);
    
    return true;
}



void HelloWorld::onPayEnd(mob::paysdk::C2DXPayStatus status, std::string ticketId, int errorCode, std::string errorDes)
{
    switch (status)
    {
        case mob::paysdk::C2DXPayStatusSuccess:
            printf("\n ---> 支付结果：success!,%s\n",ticketId.c_str());
            break;
            
        case mob::paysdk::C2DXPayStatusFail:
            printf("\n ---> 支付结果：fail!,%s,%s\n",ticketId.c_str(),errorDes.c_str());
            break;
            
        default:
            //            printf("\n ---> 支付结果：cancel!,%s\n","ticketId.c_str()");
            break;
    }
}

bool HelloWorld::onWillPay(std::string ticketId)
{
    printf("\n ---> 开始支付%s\n",ticketId.c_str());
    return false;
}


std::string HelloWorld::getOutOrderNO()
{
    return StringUtils::format("%ld", clock());
}

std::string HelloWorld::getrandomStr()
{
    long int m=1234343434334;//最小的十位数
    long int n=9999999998999;//最大的十位数
    long int l;
    l = m + rand()%(n-m+1);
    
    ostringstream os;
    os<<l;
    string result;
    istringstream is(os.str());
    is>>result;
    return result;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
