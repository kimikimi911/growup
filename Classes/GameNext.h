#ifndef __GAME_NEXT_H__
#define __GAME_NEXT_H__

#include "cocos2d.h"

static int baby = 0;
static std::string picNext = "";
static int completed = 0;
static int feed_index = 0;
static int play_index = 0;



class  GameNext: public cocos2d::Scene
{
public:
    static cocos2d::Scene* scene(std::string sqr,int is_completed,int round,int level);
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameNext);
    
    void update(float dt);
    
    int second = 0;
    
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    
    
    std::string gr_pic;
    std::string gl_pic;
    
    
    
};

#endif // __GAME_NEXT_H__