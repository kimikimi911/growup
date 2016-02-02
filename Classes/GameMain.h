#ifndef __GAME_MAIN_H__
#define __GAME_MAIN_H__

#include "cocos2d.h"

static int game_score = 0; //游戏总分
static int game_round = 1; //游戏场景
static int game_level = 1; //游戏子等级，每个场景6关



class GameMain : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameMain);

    
    //场景大小
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    
    
    //-----------------------------------------------一些公共的元素--------------

    //每帧动画
    void update(float dt);
    
    //定义本关的背景、图片、音乐
    void define();
    
    //中间的动画
    void flower_show();
    
    //点击触发停止的判断及响应
    void stopCallBack(int num);
    
    //把int转化为2、4位字符串
    std::string intto2string(int number);
    std::string intto4string(int number);
    
    //随机数算法，输入一个数组m个数字，输出一个数组n个数字
    cocos2d::ValueMap random(int innum,int outnum);
    
    //截图暂停
    void capture(bool succeed, const std::string& outputFile);
    //截图结束
    void captureOver(bool succeed, const std::string& outputFile);
    //截图下一关
    void captureNext(bool succeed, const std::string& outputFile);
    
    
    //每关用到的前景、背景图片
    std::string pre_bg_pic;
    
    
    std::string bg_pic;
    std::string fg_pic;
    std::string mc_pic;//蒙层
    
    //本关模式:1是颜色模式，2是词语模式，3是颜色+词语（暂不支持）
    int game_moda;
    
    
    //本关将要出现的所有动画
    int act_num;//动画变化种数
    
    
    //时间倒计时
    int time;

    //发射小球总共分为多少个领域、线路
    int area_num;
    
    //每个领域的属性:  1-白色；2-黑色；3-灰色(目前全部置为1)
    cocos2d::ValueMap area_mode;
    
    //总共预设多少球(预计，不一定是最终的)
    int ball_num;
    
    //每个领域的球的速度模式:  1-速度相同；2-速度不同；3-变速（目前全部置为1）
    cocos2d::ValueMap area_ball_speed_mode;
    
    //每个领域的球的速度
    cocos2d::ValueMap area_ball_speed;
    
    //每个领域的球的发射时间间隔模式:  1-间隔相同；2-间隔不同（目前全部置为1）
    cocos2d::ValueMap area_ball_gaptime_mode;
    
    //每个领域的球的发射时间间隔
    cocos2d::ValueMap area_ball_gaptime;
    
    //每个领域的球的起点和终点
    cocos2d::ValueMap area_ball_begin_x;
    cocos2d::ValueMap area_ball_begin_y;
    cocos2d::ValueMap area_ball_end_x;
    cocos2d::ValueMap area_ball_end_y;
    
    
    //本关选球方法
    //本关有几组可以选择
    int available_team;
    //每组共多少球可选
    cocos2d::ValueMap available_num;
    //每组出现概率
    cocos2d::ValueMap available_rate;
    //每组的好坏：1-好，2-坏
    cocos2d::ValueMap available_kind;
    
    //球显示队列当前有多少球，and其中好的多少，坏的多少
    int count_ball_sprite = 1;
    int count_ball_sprite_good = 0;
    int count_ball_sprite_bad = 0;
    //当前发射到第几个
    int count_ball_sprite_now = 1;
    //已经到达的球
    int count_ball_sprite_now_arrive = 0;
    
    //在运行中的小球的动作
    cocos2d::Map<int, cocos2d::ActionInterval *> ball_action;
    
    //中间的动画的序列用到的action和sprite
    cocos2d::Action *action;
    cocos2d::Sprite *sprite;
    
    //-------------------------------------------------颜色匹配关卡--------------
    
    //选择中间块需要显示的颜色
    void choosecolor();
    
    //将颜色序列随机打乱
    void randomqueuecolor();
    
    //根据选择的颜色绘制中间块
    void createcolorblock();
    
    //生成发出的小球数组
    void createballcolor();
    
    //本关中心将会出现的精灵
    cocos2d::Map<int, cocos2d::Sprite *> match_color;
    
    //本关将要出现的所有的球
    cocos2d::ValueMap ball_sprite_name;
    //本关将要出现的所有的球是好是坏的标记
    cocos2d::ValueMap ball_sprite_name_kind;
    //将球放入待发射的队列
    cocos2d::Map<int, cocos2d::Sprite *> ball_sprite;
    
    
    
    //------------------------------------------------词语匹配关卡--------------
    
    //根据预设构建好要发出的球的序列
    void createqueue();
    
    //把序列随机打乱
    void randomqueue();
    
    //本关将要出现的所有的球
    cocos2d::Map<int, cocos2d::Sprite *> ball_sprite_color;
    //覆盖在draw上面的原型精灵数组
    cocos2d::Map<int, cocos2d::DrawNode *> ball_sprite_color_fake;
    //颜色关中需要用到的变量
    cocos2d::ValueMap ball_sprite_color_r;
    cocos2d::ValueMap ball_sprite_color_g;
    cocos2d::ValueMap ball_sprite_color_b;
    cocos2d::ValueMap ball_sprite_color_a;
    //本关将要出现的所有的球是好是坏的标记(颜色关)
    cocos2d::ValueMap ball_sprite_color_kind;
    
    //被random取到的那组（好的）
    cocos2d::ValueMap ball_sprite_color_r_right;
    cocos2d::ValueMap ball_sprite_color_g_right;
    cocos2d::ValueMap ball_sprite_color_b_right;
    cocos2d::ValueMap ball_sprite_color_a_right;
    //被random剩下的那组（坏的）
    cocos2d::ValueMap ball_sprite_color_r_remain;
    cocos2d::ValueMap ball_sprite_color_g_remain;
    cocos2d::ValueMap ball_sprite_color_b_remain;
    cocos2d::ValueMap ball_sprite_color_a_remain;
    //被中间选剩下的颜色序列
    cocos2d::ValueMap color_remain_array;
    //被random取到的那组（好的）的序列号
    cocos2d::ValueMap color_right_array;
    
    //在运行中的小球的动作_覆盖在上面的颜色的
    cocos2d::Map<int, cocos2d::ActionInterval *> ball_action_fake;
    

    //预设n组的rgba值，球是从里面挑选，预定义4组，只能比这个少
    cocos2d::ValueMap color_available_1_r;
    cocos2d::ValueMap color_available_1_g;
    cocos2d::ValueMap color_available_1_b;
    cocos2d::ValueMap color_available_1_a;
    cocos2d::ValueMap color_available_2_r;
    cocos2d::ValueMap color_available_2_g;
    cocos2d::ValueMap color_available_2_b;
    cocos2d::ValueMap color_available_2_a;
    cocos2d::ValueMap color_available_3_r;
    cocos2d::ValueMap color_available_3_g;
    cocos2d::ValueMap color_available_3_b;
    cocos2d::ValueMap color_available_3_a;
    cocos2d::ValueMap color_available_4_r;
    cocos2d::ValueMap color_available_4_g;
    cocos2d::ValueMap color_available_4_b;
    cocos2d::ValueMap color_available_4_a;
    
    //有几组
    int color_available_team_num;
    //每组几个颜色
    int color_available_team_color_num;
    
    //本关好的颜色有几种
    int color_choose;
  
    //本关中间有几块需要颜色
    int points_num;
    
    //每个块展现的颜色序列
    cocos2d::ValueMap points_color;
    

    
};

#endif // __GAME_MAIN_H__
