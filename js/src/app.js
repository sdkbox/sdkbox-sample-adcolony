
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
            onAdColonyChange : function (data, available) {
                // Called when AdColony finish loading
                cc.log("onAdColonyChange");
                dump(data);
                cc.log(available);

                self.eventLabel.setString("onAdColonyChange:" + data["name"]);
            },
            onAdColonyReward : function (data, currencyName, amount, success) {
                // Called when AdColony v4vc ad finish playing
                cc.log("onAdColonyReward");
                dump(data);
                cc.log("currencyName: " + currencyName.toString());
                cc.log("amount: " + amount.toString());
                cc.log("success: " + success.toString());

                self.eventLabel.setString("onAdColonyReward");
                self.rewardAmount = self.rewardAmount + amount;
                self.rewardLabel.setString(self.rewardAmount.toString());
            },
            onAdColonyStarted : function (data) {
                // Called when ad starts playing
                cc.log("onAdColonyStarted");
                dump(data);

                self.eventLabel.setString("onAdColonyStarted");
            },
            onAdColonyFinished : function (data) {
                // Called when an ad finish displaying
                cc.log("onAdColonyFinished");
                dump(data);

                self.eventLabel.setString("onAdColonyFinished");
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

