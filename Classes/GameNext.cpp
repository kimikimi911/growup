#include "GameNext.h"
#include "GameMain.h"
#include "first.h"
//#include "ChooseScene.h"

USING_NS_CC;

Scene* GameNext::scene(std::string sqr,int is_completed,int round,int level) {
    
    Scene *myscene = Scene::create();
    
    picNext = sqr;
    completed= is_completed;
    game_round = round;
    game_level = level;
    GameNext* mylayer = GameNext::create();
    
    
    myscene->addChild(mylayer);
    
    
    
    
    
    
    
    
    
    
    return myscene;
}
//



bool GameNext::init()
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

    
    if(game_round<=9)
    {
        gr_pic = "0" + Value(game_round).asString();
    }else if(game_round>=10)
    {
        gr_pic = Value(game_round).asString();
    }
    
    if((game_level-1)<=9)
    {
        gl_pic = "0" + Value(game_level-1).asString();
    }else if((game_level-1)>=10)
    {
        gl_pic = Value(game_level-1).asString();
    }
    
    
    //被弄成灰色的截图
    auto ac = Sprite::create(picNext);
    ac->setAnchorPoint(Vec2(0,0));
    ac->setPosition(Vec2(0,0));
    ac->setScaleX(visibleSize.width/ac->getTextureRect().getMaxX()); //设置精灵宽度缩放比例
    ac->setScaleY(visibleSize.height/ac->getTextureRect().getMaxY());
    this->addChild(ac,100);
    
    
    //半透明层，在截图之上
    LayerColor* layerColor = CCLayerColor::create();
    layerColor->setColor(cocos2d::Color3B(0, 0, 0));
    layerColor->setOpacity(150);
    layerColor->setContentSize(Size(visibleSize.width, visibleSize.height));
    this->addChild(layerColor,101);
    
    
    //next小方块的背景
    auto gameover = Sprite::create("setting/gamenext.png");
    gameover->setPosition(Vec2(origin.x + visibleSize.width/2,origin.y + visibleSize.height/2));
    this->addChild(gameover,102);
    
    
    scheduleUpdate();
    
    return true;
    
}


void GameNext::update(float dt)
{
    //Director::getInstance()->replaceScene(GameMain::createScene());
    
    //std::string str = Value(game_round-1).asString();
    second = second + 1;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    if(second == 10){

        
        std::string pass_pic = "next/next" + gr_pic + "_" + gl_pic + ".png";
        auto gameover_pass_pic = Sprite::create(pass_pic);
        gameover_pass_pic->setPosition(Vec2(origin.x + visibleSize.width/2-20,
                                            origin.y + visibleSize.height/2+150));
        this->addChild(gameover_pass_pic,103);
        
    }else if (second == 50)
    {
        //if(game_level-1==5)
        if(game_level-1==2)
        {
            Director::getInstance()->replaceScene(First::createScene());
        }
        else if((game_level-1)<=2)
        {
            Director::getInstance()->replaceScene(GameMain::createScene());

        }
    }


    
    
    /*
    if(second == 10)
    {
        auto gameover_bg = Sprite::create("setting/passpic_bg.png");
        gameover_bg->setPosition(Vec2(origin.x + visibleSize.width/2,
                                      origin.y + visibleSize.height/2));
        
        
        
        log("%f",visibleSize.width/2);
        log("%f",visibleSize.height/2);
        
        
        
        this->addChild(gameover_bg,102);
        
        std::string pass_pic = "level/level"+ str +".png";
        auto gameover_pass_pic = Sprite::create(pass_pic);
        gameover_pass_pic->setPosition(Vec2(origin.x + visibleSize.width/2-20,
                                            origin.y + visibleSize.height/2+150));
        this->addChild(gameover_pass_pic,103);
        
    }else if (second == 30)
    {
        
        std::string pass_pic = "level/level"+ str +"_ok.png";
        auto gameover_bg = Sprite::create(pass_pic);
        gameover_bg->setPosition(Vec2(origin.x + visibleSize.width/2+250,
                                      origin.y + visibleSize.height/2+180));
        this->addChild(gameover_bg,103);
    }else if (second == 50)
    {
        
        std::string pass_pic = "level/level"+ str +"_got.png";
        auto gameover_bg = Sprite::create(pass_pic);
        gameover_bg->setPosition(Vec2(origin.x + visibleSize.width/2,
                                      origin.y + visibleSize.height/2-50));
        this->addChild(gameover_bg,103);
        
        
        
        auto feed_this = CCLabelTTF::create("",  "Arial", 50);
        feed_this->setColor(cocos2d::Color3B(100, 60, 60));
        feed_this->retain();
        feed_this->setPosition(origin.x + visibleSize.width/2-10,
                               origin.y + visibleSize.height/2-68);
        char str_1[100];
        sprintf(str_1, " %d ", feed_index);
        feed_this->setString(str_1);
        feed_this->setVisible(true);
        this->addChild(feed_this, 103);
        
    }else if (second == 70)
    {
        std::string pass_pic = "level/level"+ str +"_oh.png";
        auto gameover_bg = Sprite::create(pass_pic);
        gameover_bg->setPosition(Vec2(origin.x + visibleSize.width/2+285,
                                      origin.y + visibleSize.height/2-60));
        this->addChild(gameover_bg,103);
    }else if (second == 120)
    {
        if(baby>0)
        {
            std::string pass_pic = "level/level"+ str +"_gotnew.png";
            auto gameover_bg = Sprite::create(pass_pic);
            gameover_bg->setPosition(Vec2(origin.x + visibleSize.width/2+30,
                                          origin.y + visibleSize.height/2-240));
            this->addChild(gameover_bg,103);
        }else{
            if (completed==1) {
                //全部游戏完成，放恭喜画面
                Director::getInstance()->replaceScene(Baby::create());
            }else{
                Director::getInstance()->replaceScene(HelloWorld::createScene());
                
            }
        }
    }else if (second == 150)
    {
        if(baby>0)
        {
            std::string pass_pic = "level/level"+ str +"_oh.png";
            auto gameover_bg = Sprite::create(pass_pic);
            gameover_bg->setPosition(Vec2(origin.x + visibleSize.width/2+285,
                                          origin.y + visibleSize.height/2-240));
            this->addChild(gameover_bg,103);
        }
    }else if (second == 180)
    {
        if (completed==1) {
            //全部游戏完成，放恭喜画面
            Director::getInstance()->replaceScene(Baby::create());
        }else{
            Director::getInstance()->replaceScene(HelloWorld::createScene());
            
        }
    }
     */
    
}
