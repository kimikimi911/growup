#ifndef __FIRST_H__
#define __FIRST_H__

#include "cocos2d.h"

class  First: public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuStartCallback(cocos2d::Ref* pSender,int num);
    void menuGamecenterCallback(cocos2d::Ref* pSender);
    void menuBabyCallback(cocos2d::Ref* pSender);
    void menuAdCallback(cocos2d::Ref* pSender);
    void menuMusicCallback(cocos2d::Ref* pSender);
    void menuShareCallback(cocos2d::Ref* pSender);
    void menuCommentCallback(cocos2d::Ref* pSender);
    void menucreatebuttonCallback(cocos2d::Ref* pSender);
    
    
    cocos2d::Menu *menu_music;
    
    
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(First);
    
    
    
    cocos2d::Size bg_sprite_1_s;
    cocos2d::Size bg_sprite_2_s;
    
    
    
    static void updateScore();
    
protected:
    cocos2d::Sprite *bg_sprite_1;
    cocos2d::Sprite *bg_sprite_2;
    
    
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    
    cocos2d::ValueMap level_icon_show;
    
    
    
    
};

#endif // __FIRST_H__
