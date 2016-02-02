#ifndef __GAME_OVER_H__
#define __GAME_OVER_H__

#include "cocos2d.h"

static std::string picOver = "";

class  GameOver: public cocos2d::Scene
{
public:
    static cocos2d::Scene* scene(std::string sqr);
    
    virtual bool init();
    
    // a selector callback
    
    void menuTryAgainItemCallback(Ref* pSender);
    //void menuWatchBabyItemCallback(Ref* pSender);
    void menuBackItemCallback(Ref* pSender);
    void menuGameoverCommentItemCallback(Ref* pSender);
    void menuGameoverShareItemCallback(Ref* pSender);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameOver);
    
    void update(float dt);
    int second = 0;
    
    
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    
};

#endif // __GAME_OVER_H__


