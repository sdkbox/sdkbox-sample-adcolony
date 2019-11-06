
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        cc.log("Sample Startup")

        this.createTestMenu();

        var winsize = cc.winSize;

        var logo = new cc.Sprite("res/Logo.png");
        var logoSize = logo.getContentSize();
        logo.x = logoSize.width / 2;
        logo.y = winsize.height - logoSize.height / 2;
        this.addChild(logo);

        var quit = new cc.MenuItemLabel(new cc.LabelTTF("QUIT", "sans", 32), function() {
            cc.log("QUIT");
        });
        var menu = new cc.Menu(quit);
        var size = quit.getContentSize();
        menu.x = winsize.width - size.width / 2 - 16;
        menu.y = size.height / 2 + 16;
        this.addChild(menu);

        return true;
    },

    createTestMenu:function() {

        var self = this;

        // reward amount label
        var rewardLabel = new cc.LabelTTF("0", "sans", 32);
        rewardLabel.x = cc.winSize.width / 2;
        rewardLabel.y = 30;
        this.addChild(rewardLabel)
        self.rewardLabel = rewardLabel;
        self.rewardAmount = 0;

        // event label
        var eventLabel = new cc.LabelTTF("No event", "sans", 32);
        eventLabel.setAnchorPoint(cc.p(0, 0));
        eventLabel.x = 5
        eventLabel.y = 5
        this.addChild(eventLabel)
        self.eventLabel = eventLabel


        cc.MenuItemFont.setFontName("sans");
        var size = cc.Director.getInstance().getWinSize();

        var dump = function (data) {
            cc.log("  dump:");
            for (var key in data) {
                cc.log("  - " + key.toString() + ": " + data[key].toString());
            }
        };

        // init plugin
        sdkbox.PluginAdColony.init();
        sdkbox.PluginAdColony.setListener({

            adColonyInterstitialDidLoad: function(interstitial) {
                cc.log("adColonyInterstitialDidLoad: " + interstitial);
                self.eventLabel.setString("adColonyInterstitialDidLoad");
            },
            
            adColonyInterstitialDidFailToLoad(error) {
                cc.log("adColonyInterstitialDidFailToLoad: " + error);
                self.eventLabel.setString("adColonyInterstitialDidFailToLoad");
            },
            
            adColonyInterstitialWillOpen: function(interstitial) {
                cc.log("adColonyInterstitialWillOpen: " + interstitial);
            },
            
            adColonyInterstitialDidClose: function(interstitial) {
                cc.log("adColonyInterstitialDidClose: " + interstitial);
            },
            
            adColonyInterstitialExpired: function(interstitial) {
                cc.log("adColonyInterstitialExpired: " + interstitial);
            },
            
            adColonyInterstitialWillLeaveApplication: function(interstitial) {
                cc.log("adColonyInterstitialWillLeaveApplication: " + interstitial);
            },
            
            adColonyInterstitialDidReceiveClick: function(interstitial) {
                cc.log("adColonyInterstitialDidReceiveClick: " + interstitial);
            },
            
            adColonyInterstitialIapOpportunity: function(interstitial, iapProductID, engagement) {
                cc.log("adColonyInterstitialIapOpportunity: %s %s %d", interstitial, iapProductID, engagement);
            },
            
            adColonyAdViewDidLoad(adView) {
                cc.log("adColonyAdViewDidLoad: " + adView);
                self.eventLabel.setString("adColonyAdViewDidLoad");
            },
            
            adColonyAdViewDidFailToLoad(error) {
                cc.log("adColonyAdViewDidFailToLoad: " + error);
                self.eventLabel.setString("adColonyAdViewDidFailToLoad");
            },
            
            adColonyAdViewWillLeaveApplication(adView) {
                cc.log("adColonyAdViewWillLeaveApplication:" + adView);
            },
            
            adColonyAdViewWillOpen(adView) {
                cc.log("adColonyAdViewWillOpen:" + adView.c_str());
            },
            
            adColonyAdViewDidClose(adView) {
                cc.log("adColonyAdViewDidClose:" + adView.c_str());
            },
            
            adColonyAdViewDidReceiveClick(adView) {
                cc.log("adColonyAdViewDidReceiveClick:" + adView.c_str());
            },
            
            adColonyReward(name, currencyName, amount, success) {
                cc.log("adColonyReward: %s %s %d %d", name.c_str(), currencyName.c_str(), amount, success);
                self.rewardAmount = self.rewardAmount + amount;
                self.rewardLabel.setString(self.rewardAmount.toString());
            },
            onAdColonyChange : function (data, available) {
                cc.log("onAdColonyChange is deprecated");
            },
            onAdColonyReward : function (data, currencyName, amount, success) {
                cc.log("onAdColonyReward is deprecated");
            },
            onAdColonyStarted : function (data) {
                cc.log("onAdColonyStarted is deprecated");
            },
            onAdColonyFinished : function (data) {
                cc.log("onAdColonyFinished is deprecated");
            }
        });

        var menu = new cc.Menu(
            new cc.MenuItemFont("show video", function() {
                sdkbox.PluginAdColony.show("video");
                cc.log("show video");
            }),
            new cc.MenuItemFont("show v4vc", function() {
                sdkbox.PluginAdColony.show("v4vc");
                cc.log("show v4vc");
            }),
            new cc.MenuItemFont("====gc===", function() {
                cc.log("======gc start=====");
                __jsc__.garbageCollect();
                cc.log("======gc end=====");
            })
        );

        menu.alignItemsVerticallyWithPadding(5);
        menu.x = size.width/2;
        menu.y = size.height/2;
        this.addChild(menu);
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

