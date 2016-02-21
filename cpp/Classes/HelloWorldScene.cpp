
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    CCLOG("Sample Startup");
    
    // add logo
    auto winsize = Director::getInstance()->getWinSize();
    auto logo = Sprite::create("Logo.png");
    auto logoSize = logo->getContentSize();
    logo->setPosition(Vec2(logoSize.width / 2,
                           winsize.height - logoSize.height / 2));
    addChild(logo);
    
    // add quit button
    auto label = Label::createWithSystemFont("QUIT", "sans", 32);
    auto quit = MenuItemLabel::create(label, [](Ref*){
        exit(0);
    });
    auto labelSize = label->getContentSize();
    quit->setPosition(Vec2(winsize.width / 2 - labelSize.width / 2 - 16,
                           -winsize.height / 2 + labelSize.height / 2 + 16));
    addChild(Menu::create(quit, NULL));
    
    // add test menu
    createTestMenu();
    
    return true;
}

void HelloWorld::createTestMenu()
{
    MenuItemFont::setFontName("sans");
    Size size = Director::getInstance()->getWinSize();
    
    auto menu = Menu::create(MenuItemFont::create("show video", CC_CALLBACK_1(HelloWorld::onShowVideo, this)),
                             MenuItemFont::create("show v4vc", CC_CALLBACK_1(HelloWorld::onShowV4vc, this)),
                             NULL);
    
    menu->alignItemsVerticallyWithPadding(5);
    menu->setPosition(Vec2(size.width/2, size.height/2));
    addChild(menu);
}

void HelloWorld::onShowVideo(cocos2d::Ref* sender)
{
    sdkbox::PluginAdColony::show("video");
    CCLOG("onShowVideo");
}

void HelloWorld::onShowV4vc(cocos2d::Ref* sender)
{
    sdkbox::PluginAdColony::show("v4vc");
    CCLOG("onShowVideo");
}

void HelloWorld::onAdColonyChange(const sdkbox::AdColonyAdInfo& info, bool available)
{
//    struct AdColonyAdInfo
//    {
//        std::string name;
//        bool shown;
//        std::string zoneID;
//        bool iapEnabled;
//        std::string iapProductID;
//        int iapQuantity;
//        int iapEngagementType;
//    };

    CCLOG("onAdColonyChange");
    CCLOG("info.name: %s", info.name.c_str());
    CCLOG("info.shown: %s", info.shown ? "true" : "false");
    CCLOG("info.zoneID: %s", info.zoneID.c_str());
    CCLOG("info.iapEnabled: %s", info.iapEnabled ? "true" : "false");
    CCLOG("info.iapProductID: %s", info.iapProductID.c_str());
    CCLOG("info.iapQuantity: %d", info.iapQuantity);
    CCLOG("info.iapEngagementType: %d", info.iapEngagementType);
}

void HelloWorld::onAdColonyReward(const sdkbox::AdColonyAdInfo& info,
                                  const std::string& currencyName, int amount, bool success)
{
    
    CCLOG("onAdColonyReward, currencyName: %s, amount: %d, success: %s", currencyName.c_str(), amount, success ? "true" : "false");
    CCLOG("info.name: %s", info.name.c_str());
    CCLOG("info.shown: %s", info.shown ? "true" : "false");
    CCLOG("info.zoneID: %s", info.zoneID.c_str());
    CCLOG("info.iapEnabled: %s", info.iapEnabled ? "true" : "false");
    CCLOG("info.iapProductID: %s", info.iapProductID.c_str());
    CCLOG("info.iapQuantity: %d", info.iapQuantity);
    CCLOG("info.iapEngagementType: %d", info.iapEngagementType);
}

void HelloWorld::onAdColonyStarted(const sdkbox::AdColonyAdInfo& info)
{
    CCLOG("onAdColonyStarted");
    CCLOG("info.name: %s", info.name.c_str());
    CCLOG("info.shown: %s", info.shown ? "true" : "false");
    CCLOG("info.zoneID: %s", info.zoneID.c_str());
    CCLOG("info.iapEnabled: %s", info.iapEnabled ? "true" : "false");
    CCLOG("info.iapProductID: %s", info.iapProductID.c_str());
    CCLOG("info.iapQuantity: %d", info.iapQuantity);
    CCLOG("info.iapEngagementType: %d", info.iapEngagementType);
}

void HelloWorld::onAdColonyFinished(const sdkbox::AdColonyAdInfo& info)
{
    CCLOG("onAdColonyFinished");
    CCLOG("info.name: %s", info.name.c_str());
    CCLOG("info.shown: %s", info.shown ? "true" : "false");
    CCLOG("info.zoneID: %s", info.zoneID.c_str());
    CCLOG("info.iapEnabled: %s", info.iapEnabled ? "true" : "false");
    CCLOG("info.iapProductID: %s", info.iapProductID.c_str());
    CCLOG("info.iapQuantity: %d", info.iapQuantity);
    CCLOG("info.iapEngagementType: %d", info.iapEngagementType);
}
