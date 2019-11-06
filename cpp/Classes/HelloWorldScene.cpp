
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
    sdkbox::PluginAdColony::setListener(this);
    
    return true;
}

void HelloWorld::createTestMenu()
{
    Size size = Director::getInstance()->getWinSize();

    // add status label
    _status = Label::createWithSystemFont("No event.", "sans", 32);
    _status->setTextColor(Color4B(0, 255, 0, 255));
    _status->setAnchorPoint(Vec2(0,0));
    _status->setPosition(5,5);
    addChild(_status);

    // reward label
    _reward = Label::createWithSystemFont("0", "sans", 32);
    _reward->setPosition(size.width / 2, 30);
    addChild(_reward);

    MenuItemFont::setFontName("sans");
    
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

void HelloWorld::adColonyInterstitialDidLoad(const std::string& interstitial) {
    CCLOG("adColonyInterstitialDidLoad");
    _status->setString(__FUNCTION__);
}

void HelloWorld::adColonyInterstitialDidFailToLoad(const std::string& error) {
    CCLOG("adColonyInterstitialDidFailToLoad");
    _status->setString(__FUNCTION__);
}

void HelloWorld::adColonyInterstitialWillOpen(const std::string& interstitial) {
    CCLOG("adColonyInterstitialWillOpen");
}

void HelloWorld::adColonyInterstitialDidClose(const std::string& interstitial) {
    CCLOG("adColonyInterstitialDidClose");
}

void HelloWorld::adColonyInterstitialExpired(const std::string& interstitial) {
    CCLOG("adColonyInterstitialExpired");
}

void HelloWorld::adColonyInterstitialWillLeaveApplication(const std::string& interstitial) {
    CCLOG("adColonyInterstitialWillLeaveApplication");
}

void HelloWorld::adColonyInterstitialDidReceiveClick(const std::string& interstitial) {
    CCLOG("adColonyInterstitialDidReceiveClick");
}

void HelloWorld::adColonyInterstitialIapOpportunity(const std::string& interstitial, const std::string& iapProductID, int engagement) {
    CCLOG("adColonyInterstitialIapOpportunity");
}

void HelloWorld::adColonyAdViewDidLoad(const std::string& adView) {
    CCLOG("adColonyAdViewDidLoad");
    _status->setString(__FUNCTION__);
}

void HelloWorld::adColonyAdViewDidFailToLoad(const std::string& error) {
    CCLOG("adColonyAdViewDidFailToLoad");
    _status->setString(__FUNCTION__);
}

void HelloWorld::adColonyAdViewWillLeaveApplication(const std::string& adView) {
    CCLOG("adColonyAdViewWillLeaveApplication");
}

void HelloWorld::adColonyAdViewWillOpen(const std::string& adView) {
    CCLOG("adColonyAdViewWillOpen");
}

void HelloWorld::adColonyAdViewDidClose(const std::string& adView) {
    CCLOG("adColonyAdViewDidClose");
}

void HelloWorld::adColonyAdViewDidReceiveClick(const std::string& adView) {
    CCLOG("adColonyAdViewDidReceiveClick");
}

void HelloWorld::adColonyReward(const std::string name, const std::string& currencyName, int amount, bool success) {
    CCLOG("adColonyReward");
    _reward->setString(StringUtils::toString((int)utils::atof(_reward->getString().c_str()) + amount));
}

void HelloWorld::onAdColonyChange(const sdkbox::AdColonyAdInfo& info, bool available) {
    CCLOG("onAdColonyChange is deprecated");
}

void HelloWorld::onAdColonyReward(const sdkbox::AdColonyAdInfo& info,
                                  const std::string& currencyName, int amount, bool success) {
    CCLOG("onAdColonyReward is deprecated");
}

void HelloWorld::onAdColonyStarted(const sdkbox::AdColonyAdInfo& info) {
    CCLOG("onAdColonyStarted is deprecated");
}

void HelloWorld::onAdColonyFinished(const sdkbox::AdColonyAdInfo& info) {
    CCLOG("onAdColonyFinished is deprecated");
}
