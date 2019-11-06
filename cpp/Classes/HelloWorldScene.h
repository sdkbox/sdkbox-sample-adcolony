#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PluginAdColony/PluginAdColony.h"

class HelloWorld : public cocos2d::Layer, public sdkbox::AdColonyListener
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:
    void createTestMenu();

    void onShowVideo(cocos2d::Ref* sender);
    void onShowV4vc(cocos2d::Ref* sender);

    /*
     * Interstitial Callback
     */
    void adColonyInterstitialDidLoad(const std::string& interstitial);
    void adColonyInterstitialDidFailToLoad(const std::string& error);
    void adColonyInterstitialWillOpen(const std::string& interstitial);
    void adColonyInterstitialDidClose(const std::string& interstitial);
    void adColonyInterstitialExpired(const std::string& interstitial);
    void adColonyInterstitialWillLeaveApplication(const std::string& interstitial);
    void adColonyInterstitialDidReceiveClick(const std::string& interstitial);
    void adColonyInterstitialIapOpportunity(const std::string& interstitial, const std::string& iapProductID, int engagement);

    /*
     * Banner Callback
     */
    void adColonyAdViewDidLoad(const std::string& adView);
    void adColonyAdViewDidFailToLoad(const std::string& error);
    void adColonyAdViewWillLeaveApplication(const std::string& adView);
    void adColonyAdViewWillOpen(const std::string& adView);
    void adColonyAdViewDidClose(const std::string& adView);
    void adColonyAdViewDidReceiveClick(const std::string& adView);

    /*
     * Rewards Callback
     */
    void adColonyReward(const std::string name, const std::string& currencyName, int amount, bool success);

    void onAdColonyChange(const sdkbox::AdColonyAdInfo& info, bool available);
    void onAdColonyReward(const sdkbox::AdColonyAdInfo& info,
                          const std::string& currencyName, int amount, bool success);
    void onAdColonyStarted(const sdkbox::AdColonyAdInfo& info);
    void onAdColonyFinished(const sdkbox::AdColonyAdInfo& info);

private:
    cocos2d::Label *_status;
    cocos2d::Label *_reward;
};

#endif // __HELLOWORLD_SCENE_H__
