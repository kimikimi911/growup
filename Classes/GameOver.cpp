#include "GameOver.h"
#include "GameMain.h"
#include "First.h"
//#include "ChooseScene.h"

USING_NS_CC;

Scene* GameOver::scene(std::string sqr) {
    
    Scene *myscene = Scene::create();
    picOver = sqr;
    GameOver* mylayer = GameOver::create();
    
    
    myscene->addChild(mylayer);
    
    
    return myscene;
}
//



bool GameOver::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
   
    
    
    
    auto ac = Sprite::create(picOver);
    ac->setAnchorPoint(Vec2(0,0));
    ac->setPosition(Vec2(0,0));
    ac->setScaleX(visibleSize.width/ac->getTextureRect().getMaxX()); //设置精灵宽度缩放比例
    ac->setScaleY(visibleSize.height/ac->getTextureRect().getMaxY());
    
    this->addChild(ac,100);
    
    
    
    
    //半透明层
    
    LayerColor* layerColor = CCLayerColor::create();
    
    layerColor->setColor(cocos2d::Color3B(0, 0, 0));
    
    layerColor->setOpacity(150);
    
    layerColor->setContentSize(Size(visibleSize.width, visibleSize.height));
    
    this->addChild(layerColor,101);
    
    
    auto gameover = Sprite::create("setting/gameover.png");
    //gameover->setAnchorPoint(Vec2(0,0));
    gameover->setPosition(Vec2(origin.x + visibleSize.width/2,
                               origin.y + visibleSize.height/2));
    this->addChild(gameover,102);
    

    
    scheduleUpdate();
    
    return true;
    
}




void GameOver::menuTryAgainItemCallback(Ref* pSender)
{
    //重新开始一局按钮
    Director::getInstance()->replaceScene(GameMain::createScene());
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //exit(0);
#endif
}




void GameOver::menuGameoverCommentItemCallback(Ref* pSender)
{
    //评论按钮
    Director::getInstance()->replaceScene(GameMain::createScene());
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //exit(0);
#endif
}


void GameOver::menuGameoverShareItemCallback(Ref* pSender)
{
    //分享按钮
    Director::getInstance()->replaceScene(GameMain::createScene());
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //exit(0);
#endif
}




void GameOver::menuBackItemCallback(Ref* pSender)
{
    //返回首页按钮
    Director::getInstance()->replaceScene(First::create());
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //exit(0);
#endif
}







void GameOver::update(float dt)
{
    
    
    second = second + 1;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
     if(second == 1)
    {
        std::string pass_pic = "over/over.png";
        auto gameover_pass_pic = Sprite::create(pass_pic);
        gameover_pass_pic->setPosition(Vec2(origin.x + visibleSize.width/2-20,
                                            origin.y + visibleSize.height/2+150));
        this->addChild(gameover_pass_pic,103);
        /*
        auto gameover_score = Sprite::create("setting/gameoverscore.png");
        gameover_score->setPosition(Vec2(origin.x + visibleSize.width/2,
                                         origin.y + visibleSize.height/2+200));
        
        
        this->addChild(gameover_score,102);
        
        auto score_all = CCLabelTTF::create("",  "American Typewriter", 60);
        score_all->setColor(cocos2d::Color3B(100, 60, 60));
        score_all->retain();
        score_all->setPosition(origin.x + visibleSize.width/2+33,
                               origin.y + visibleSize.height/2+200);
        char str_1[100];
        sprintf(str_1, " %d ", score_this);
        score_all->setString(str_1);
        score_all->setVisible(true);
        this->addChild(score_all, 103);
        
        */
        
        
    }else if(second == 5)
    {
        auto tryAgainItem = MenuItemImage::create(
                                                  "setting/tryagain.png",
                                                  "setting/tryagain.png",
                                                  CC_CALLBACK_1(GameOver::menuTryAgainItemCallback, this));
        
        tryAgainItem->setPosition(Vec2(origin.x + visibleSize.width/2,
                                       origin.y + visibleSize.height/2));
    
        
        auto gameoverShareItem = MenuItemImage::create(
                                                       "setting/gameovershare.png",
                                                       "setting/gameovershare.png",
                                                       CC_CALLBACK_1(GameOver::menuGameoverShareItemCallback, this));
        
        gameoverShareItem->setPosition(Vec2(origin.x + visibleSize.width/2-250 ,
                                            origin.y + visibleSize.height/2-250));
        
        auto gameoverCommentItem = MenuItemImage::create(
                                                         "setting/gameovercomment.png",
                                                         "setting/gameovercomment.png",
                                                         CC_CALLBACK_1(GameOver::menuGameoverCommentItemCallback, this));
        
        gameoverCommentItem->setPosition(Vec2(origin.x + visibleSize.width/2+250 ,
                                              origin.y + visibleSize.height/2-250));
        
       auto backItem = MenuItemImage::create(
                                             "setting/backtomenu.png",
                                             "setting/backtomenu.png",
                                              CC_CALLBACK_1(GameOver::menuBackItemCallback, this));
        
        backItem->setPosition(Vec2(origin.x + visibleSize.width/2 ,
                                   origin.y + visibleSize.height/2-250));
        
        
        
        //auto menu = Menu::create(tryAgainItem, gameoverShareItem, gameoverCommentItem, backItem, NULL);
        auto menu = Menu::create(tryAgainItem, gameoverShareItem, gameoverCommentItem,backItem, NULL);
        menu->setPosition(Vec2::ZERO);
        this->addChild(menu,103);
        
    }
     
    
}
