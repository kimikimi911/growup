#include "First.h"
#include "GameMain.h"
#include "Music.h"
//#include "GamePause.h"
#include "GameOver.h"
#include "GameNext.h"

USING_NS_CC;

Scene * First::createScene()
{
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = First::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}




// on "init" you need to initialize your instance
bool First::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    
    
    
    //背景图片
    
    Sprite *spriteBGbottom = Sprite::create("first/home_bg1.png");
    spriteBGbottom->setAnchorPoint(Vec2(0.5,0.5));
    spriteBGbottom->setPosition(visibleSize.width/2, visibleSize.height/2);
    this->addChild(spriteBGbottom,-2);
    
    
    
    
    
    //图标
    Sprite *spriteTitle = Sprite::create("first/title.png");
    spriteTitle->setAnchorPoint(Vec2(0.5,0.5));
    spriteTitle->setPosition(visibleSize.width/2, 1650);
    this->addChild(spriteTitle,-2);
    
    
    
    
    //判断出现哪个图标
    for(int i=1;i<=12;i++)
    {
        
        cocos2d::__String* level_stat = String::createWithFormat("game_round_stat%d",i);
        
        if( UserDefault::getInstance()->getIntegerForKey(level_stat->getCString()))
        {
            std::string ee;
            if (UserDefault::getInstance()->getIntegerForKey(level_stat->getCString())== 1) {
                ee = "ready";
            }else if(UserDefault::getInstance()->getIntegerForKey(level_stat->getCString())== 2)
            {
                ee = "done";
            }else if(UserDefault::getInstance()->getIntegerForKey(level_stat->getCString())== 0)
            {
                ee = "no";
            }
            
            level_icon_show.insert(std::make_pair(Value(i).asString(),Value(ee)));
        }else{
            
            level_icon_show.insert(std::make_pair(Value(i).asString(),Value("no")));

            
        }
        
        
    }
    
    
    int big_radis = 420;
    int big_radis_sin30 = 210;
    int big_radis_cos30 = 364;//这里自己算好，就取整了
    
    int center_x = 540;
    int center_y = 700;
    
    
    auto start1Item = MenuItemImage::create(
                                           "first/le1_" + level_icon_show.at(Value(1).asString()).asString() + ".png",
                                           "first/le1_" + level_icon_show.at(Value(1).asString()).asString() + ".png",
                                           CC_CALLBACK_1(First::menuStartCallback, this, 1));
    
    start1Item->setPosition(Vec2(center_x,center_y+big_radis));
    
    auto start2Item = MenuItemImage::create(
                                            "first/le2_" + level_icon_show.at(Value(2).asString()).asString() + ".png",
                                            "first/le2_" + level_icon_show.at(Value(2).asString()).asString() + ".png",
                                            CC_CALLBACK_1(First::menuStartCallback, this,2));
    
    start2Item->setPosition(Vec2(center_x+big_radis_sin30,center_y+big_radis_cos30));
   
    
    
    auto start3Item = MenuItemImage::create(
                                            "first/le3_" + level_icon_show.at(Value(3).asString()).asString() + ".png",
                                            "first/le3_" + level_icon_show.at(Value(3).asString()).asString() + ".png",
                                            CC_CALLBACK_1(First::menuStartCallback, this,3));
    
    start3Item->setPosition(Vec2(center_x+big_radis_cos30,center_y+big_radis_sin30));
 
    
    auto start4Item = MenuItemImage::create(
                                            "first/le4_" + level_icon_show.at(Value(4).asString()).asString() + ".png",
                                            "first/le4_" + level_icon_show.at(Value(4).asString()).asString() + ".png",
                                            CC_CALLBACK_1(First::menuStartCallback, this,4));
    
    start4Item->setPosition(Vec2(center_x+big_radis,center_y));
    
    auto start5Item = MenuItemImage::create(
                                            "first/le5_" + level_icon_show.at(Value(5).asString()).asString() + ".png",
                                            "first/le5_" + level_icon_show.at(Value(5).asString()).asString() + ".png",
                                            CC_CALLBACK_1(First::menuStartCallback, this,5));
    
    start5Item->setPosition(Vec2(center_x+big_radis_cos30,center_y-big_radis_sin30));
    
    auto start6Item = MenuItemImage::create(
                                            "first/le6_" + level_icon_show.at(Value(6).asString()).asString() + ".png",
                                            "first/le6_" + level_icon_show.at(Value(6).asString()).asString() + ".png",
                                            CC_CALLBACK_1(First::menuStartCallback, this,6));
    
    start6Item->setPosition(Vec2(center_x+big_radis_sin30,center_y-big_radis_cos30));
    
    
    auto start7Item = MenuItemImage::create(
                                            "first/le7_" + level_icon_show.at(Value(7).asString()).asString() + ".png",
                                            "first/le7_" + level_icon_show.at(Value(7).asString()).asString() + ".png",
                                            CC_CALLBACK_1(First::menuStartCallback, this,7));
    
    start7Item->setPosition(Vec2(center_x,center_y-big_radis));
    
    auto start8Item = MenuItemImage::create(
                                            "first/le8_" + level_icon_show.at(Value(8).asString()).asString() + ".png",
                                            "first/le8_" + level_icon_show.at(Value(8).asString()).asString() + ".png",
                                            CC_CALLBACK_1(First::menuStartCallback, this,8));
    
    start8Item->setPosition(Vec2(center_x-big_radis_sin30,center_y-big_radis_cos30));

    
    auto start9Item = MenuItemImage::create(
                                            "first/le9_" + level_icon_show.at(Value(9).asString()).asString() + ".png",
                                            "first/le9_" + level_icon_show.at(Value(9).asString()).asString() + ".png",
                                            CC_CALLBACK_1(First::menuStartCallback, this,9));
    
    start9Item->setPosition(Vec2(center_x-big_radis_cos30,center_y-big_radis_sin30));
    
    auto start10Item = MenuItemImage::create(
                                            "first/le10_" + level_icon_show.at(Value(10).asString()).asString() + ".png",
                                            "first/le10_" + level_icon_show.at(Value(10).asString()).asString() + ".png",
                                            CC_CALLBACK_1(First::menuStartCallback, this,10));
    
    start10Item->setPosition(Vec2(center_x-big_radis,center_y));
    
    auto start11Item = MenuItemImage::create(
                                            "first/le11_" + level_icon_show.at(Value(11).asString()).asString() + ".png",
                                            "first/le11_" + level_icon_show.at(Value(11).asString()).asString() + ".png",
                                            CC_CALLBACK_1(First::menuStartCallback, this,11));
    
    start11Item->setPosition(Vec2(center_x-big_radis_cos30,center_y+big_radis_sin30));
    
    auto start12Item = MenuItemImage::create(
                                            "first/le12_" + level_icon_show.at(Value(12).asString()).asString() + ".png",
                                            "first/le12_" + level_icon_show.at(Value(12).asString()).asString() + ".png",
                                            CC_CALLBACK_1(First::menuStartCallback, this,12));
    
    start12Item->setPosition(Vec2(center_x-big_radis_sin30,center_y+big_radis_cos30));
    

  
    
    
    
    auto createbuttonItem = MenuItemImage::create(
                                             "first/create.png",
                                             "first/create.png",
                                             CC_CALLBACK_1(First::menucreatebuttonCallback, this));
    
    createbuttonItem->setPosition(Vec2(center_x,center_y));

    
    
       auto menu = Menu::create(start1Item, start2Item, start3Item,start4Item,start5Item,start6Item,start7Item,start8Item,start9Item,start10Item,start11Item,start12Item,createbuttonItem,NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, -1);
    
    
    
    
    
    

    //if(UserDefault::getInstance()->getBoolForKey("onMusic")==true){
     //   Music::loadMusic();
     //   Music::playGameLayerMusic();
        
    //}
    
    
    
    
    
    /*
    //开始按钮
    auto startItem = MenuItemImage::create(
                                           "setting/start.png",
                                           "setting/start.png",
                                           CC_CALLBACK_1(Choose::menuStartCallback, this));
    
    startItem->setPosition(Vec2(origin.x + visibleSize.width/2-200 ,
                                origin.y + visibleSize.height/2+200));
    
    
    //gamecenter按钮
    auto gameCenterItem = MenuItemImage::create(
                                                "setting/gamecenter.png",
                                                "setting/gamecenter.png",
                                                CC_CALLBACK_1(Choose::menuGamecenterCallback, this));
    
    gameCenterItem->setPosition(Vec2(origin.x + visibleSize.width-185 ,
                                     origin.y + 215));
    
    
    
    
    //宝贝界面按钮
    auto babyItem = MenuItemImage::create(
                                          "setting/baby.png",
                                          "setting/baby.png",
                                          CC_CALLBACK_1(Choose::menuBabyCallback, this));
    
    babyItem->setPosition(Vec2(origin.x + visibleSize.width/2+200 ,
                               origin.y + visibleSize.height/2-300));
    
    
    
    //去除广告按钮
    auto adItem = MenuItemImage::create(
                                        "setting/noad.png",
                                        "setting/noad.png",
                                        CC_CALLBACK_1(Choose::menuAdCallback, this));
    
    adItem->setPosition(Vec2(origin.x + 170 ,
                             origin.y + visibleSize.height-200));
    
    
    
    
    //分享按钮
    auto shareItem = MenuItemImage::create(
                                           "setting/share.png",
                                           "setting/share.png",
                                           CC_CALLBACK_1(Choose::menuShareCallback, this));
    
    shareItem->setPosition(Vec2(origin.x + 185 ,
                                origin.y + 215));
    
    
    
    
    //评价按钮
    auto commentItem = MenuItemImage::create(
                                             "setting/comment.png",
                                             "setting/comment.png",
                                             CC_CALLBACK_1(Choose::menuCommentCallback, this));
    
    commentItem->setPosition(Vec2(origin.x + visibleSize.width/2 ,
                                  origin.y + 215));
    
    
    
    auto menu = Menu::create(startItem, gameCenterItem, babyItem, adItem, shareItem, commentItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    
    
    auto music_pic = "";
    
    if(UserDefault::getInstance()->getBoolForKey("onMusic"))
    {
        
        music_pic = "setting/music.png";
        
    }else{
        //UserDefault::getInstance()->setBoolForKey("onMusic",true);
        //UserDefault::getInstance()->flush();
        music_pic = "setting/nomusic.png";
    }
    
    
    
    
    //去除音乐按钮
    auto musicItem = MenuItemImage::create(
                                           music_pic,
                                           music_pic,
                                           CC_CALLBACK_1(Choose::menuMusicCallback, this));
    
    musicItem->setPosition(Vec2(origin.x + visibleSize.width-170 ,
                                origin.y + visibleSize.height-200));
    
    
    
    menu_music = Menu::create(musicItem, NULL);
    menu_music->setPosition(Vec2::ZERO);
    this->addChild(menu_music, 1);
    
    */
    
    return true;
    
}


//void First::menuStartCallback(Ref* pSender)
void First::menuStartCallback(Ref* pSender,int num)
{
    
    
    UserDefault::getInstance()->setIntegerForKey("game_round", num);
    Director::getInstance()->replaceScene(GameMain::createScene());

    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //exit(0);
#endif
}





void First::menucreatebuttonCallback(Ref* pSender)
{
    
    //Director::getInstance()->replaceScene(HelloWorld::createScene());
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //exit(0);
#endif
}
 
 
 
 /*
void First::menuBabyCallback(Ref* pSender)
{
    
    Director::getInstance()->replaceScene(Baby::create());
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //exit(0);
#endif
}
void First::menuAdCallback(Ref* pSender)
{
    
    Director::getInstance()->replaceScene(HelloWorld::createScene());
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //exit(0);
#endif
}
void First::menuMusicCallback(Ref* pSender)
{
    
    
    
    if(UserDefault::getInstance()->getBoolForKey("onMusic"))
    {
        
        UserDefault::getInstance()->setBoolForKey("onMusic",false);
        log("123456789");
        Music::stopBackgroundMusic();
        
    }else{
        UserDefault::getInstance()->setBoolForKey("onMusic",true);
        Music::loadMusic();
        Music::playGameLayerMusic();
        
    }
    
    //UserDefault::getInstance()->flush();
    this->removeChild(menu_music);
    
    
    
    //重新显示音乐按钮
    auto music_pic = "";
    log("%d", UserDefault::getInstance()->getBoolForKey("onMusic"));
    //UserDefault::getInstance()->setBoolForKey("onMusic",true);
    //UserDefault::getInstance()->flush();
    log("%d", UserDefault::getInstance()->getBoolForKey("onMusic"));
    
    if(UserDefault::getInstance()->getBoolForKey("onMusic"))
    {
        music_pic = "setting/music.png";
        log("1----");
        
        
    }else{
        music_pic = "setting/nomusic.png";
        log("2----");
        
    }
    
    
    auto musicItem = MenuItemImage::create(
                                           music_pic,
                                           music_pic,
                                           CC_CALLBACK_1(Choose::menuMusicCallback, this));
    
    musicItem->setPosition(Vec2(origin.x + visibleSize.width-170 ,
                                origin.y + visibleSize.height-200));
    
    
    
    menu_music = Menu::create(musicItem, NULL);
    menu_music->setPosition(Vec2::ZERO);
    this->addChild(menu_music, 1);
    
    
    
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //exit(0);
#endif
}
 
 
void First::menuShareCallback(Ref* pSender)
{
    
    Director::getInstance()->replaceScene(HelloWorld::createScene());
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //exit(0);
#endif
}
 
 
void First::menuCommentCallback(Ref* pSender)
{
    
    Director::getInstance()->replaceScene(HelloWorld::createScene());
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //exit(0);
#endif
}
*/








