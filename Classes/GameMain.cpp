#include "GameMain.h"
#include "GameOver.h"
#include "GameNext.h"
#include "First.h"

USING_NS_CC;

Scene* GameMain::createScene()
{
    auto scene = Scene::create();
    auto layer = GameMain::create();
    scene->addChild(layer);
    return scene;
}

bool GameMain::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    game_round = UserDefault::getInstance()->getIntegerForKey("game_round");
    
    define();
    
    
    //显示动画背景
    //auto pre_bg = Sprite::create(pre_bg_pic);
   // pre_bg->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    //this->addChild(pre_bg, 0);
    
    
    //sleep(10);
    
    
    
    
    //显示背景图片
    auto bg = Sprite::create(bg_pic);
    bg->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(bg, 0);
    
    auto mc = Sprite::create(pre_bg_pic);
    mc->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(mc, 2);
    
    
    if(game_moda==1)
    {
        choosecolor();
        createcolorblock();
        createballcolor();
        
    }else if(game_moda==2)
    {
        createqueue();
        
    }
    
    flower_show();
    
    //帧检测函数，会调用update
    GameMain::scheduleUpdate();

    return true;
}

void GameMain::choosecolor()
{
    cocos2d::ValueMap inarray = random(color_available_team_color_num,color_choose);
    
    for(int iii=1;iii<=points_num;iii++)
    {
        points_color.insert(std::make_pair(Value(iii).asString(),Value(inarray.at(Value((iii-1)%color_choose+1).asString()).asInt())));
        int aaaaa = points_color.at(Value(iii).asString()).asInt();
        log("choosecolor------%d",aaaaa);
    }
    
}

void GameMain::createcolorblock()
{
   
    switch (game_round){
        //time关
        case 1:
        {
            Point points1[] = { Point(540, 960), Point(540-(sin(15*M_PI/180)*180), (960+180)), Point(540+(sin(15*M_PI/180)*180), (960+180))};
            Point points2[] = { Point(540, 960), Point(540+(sin(15*M_PI/180)*180), (960+180)), Point(540+(sin(45*M_PI/180)*180), (960+(sin(45*M_PI/180)*180)))};
            Point points3[] = { Point(540, 960), Point(540+(sin(45*M_PI/180)*180), (960+(sin(45*M_PI/180)*180))), Point(540+(sin(75*M_PI/180)*180), (960+(cos(75*M_PI/180)*180)))};
            Point points4[] = { Point(540, 960), Point(540+(sin(75*M_PI/180)*180), (960+(cos(75*M_PI/180)*180))), Point(540+(sin(75*M_PI/180)*180), (960-(cos(75*M_PI/180)*180)))};
            Point points5[] = { Point(540, 960), Point(540+(sin(75*M_PI/180)*180), (960-(cos(75*M_PI/180)*180))), Point(540+(sin(45*M_PI/180)*180), (960-(sin(45*M_PI/180)*180)))};
            Point points6[] = { Point(540, 960), Point(540+(sin(45*M_PI/180)*180), (960-(sin(45*M_PI/180)*180))), Point(540+(sin(15*M_PI/180)*180), (960-180))};
            Point points7[] = { Point(540, 960), Point(540+(sin(15*M_PI/180)*180), (960-180)), Point(540-(sin(15*M_PI/180)*180), (960-180))};
            Point points8[] = { Point(540, 960), Point(540-(sin(15*M_PI/180)*180), (960-180)), Point(540-(sin(45*M_PI/180)*180), (960-(sin(45*M_PI/180)*180)))};
            Point points9[] = { Point(540, 960), Point(540-(sin(45*M_PI/180)*180), (960-(sin(45*M_PI/180)*180))), Point(540-(sin(75*M_PI/180)*180), (960-(cos(75*M_PI/180)*180)))};
            Point points10[] = { Point(540, 960), Point(540-(sin(75*M_PI/180)*180), (960-(cos(75*M_PI/180)*180))), Point(540-(sin(75*M_PI/180)*180), (960+(cos(75*M_PI/180)*180)))};
            Point points11[] = { Point(540, 960), Point(540-(sin(75*M_PI/180)*180), (960+(cos(75*M_PI/180)*180))), Point(540-(sin(45*M_PI/180)*180), (960+(sin(45*M_PI/180)*180)))};
            Point points12[] = { Point(540, 960), Point(540-(sin(45*M_PI/180)*180), (960+(sin(45*M_PI/180)*180))), Point(540-(sin(15*M_PI/180)*180), (960+180))};
            
            double rr1=color_available_1_r.at(Value(points_color.at(Value(1).asString()).asString()).asString()).asDouble();
            double gg1=color_available_1_g.at(Value(points_color.at(Value(1).asString()).asString()).asString()).asDouble();
            double bb1=color_available_1_b.at(Value(points_color.at(Value(1).asString()).asString()).asString()).asDouble();
            double aa1=color_available_1_a.at(Value(points_color.at(Value(1).asString()).asString()).asString()).asDouble();
            
            double rr2=color_available_1_r.at(Value(points_color.at(Value(2).asString()).asString()).asString()).asDouble();
            double gg2=color_available_1_g.at(Value(points_color.at(Value(2).asString()).asString()).asString()).asDouble();
            double bb2=color_available_1_b.at(Value(points_color.at(Value(2).asString()).asString()).asString()).asDouble();
            double aa2=color_available_1_a.at(Value(points_color.at(Value(2).asString()).asString()).asString()).asDouble();
            
            double rr3=color_available_1_r.at(Value(points_color.at(Value(3).asString()).asString()).asString()).asDouble();
            double gg3=color_available_1_g.at(Value(points_color.at(Value(3).asString()).asString()).asString()).asDouble();
            double bb3=color_available_1_b.at(Value(points_color.at(Value(3).asString()).asString()).asString()).asDouble();
            double aa3=color_available_1_a.at(Value(points_color.at(Value(3).asString()).asString()).asString()).asDouble();
            
            double rr4=color_available_1_r.at(Value(points_color.at(Value(4).asString()).asString()).asString()).asDouble();
            double gg4=color_available_1_g.at(Value(points_color.at(Value(4).asString()).asString()).asString()).asDouble();
            double bb4=color_available_1_b.at(Value(points_color.at(Value(4).asString()).asString()).asString()).asDouble();
            double aa4=color_available_1_a.at(Value(points_color.at(Value(4).asString()).asString()).asString()).asDouble();
            
            double rr5=color_available_1_r.at(Value(points_color.at(Value(5).asString()).asString()).asString()).asDouble();
            double gg5=color_available_1_g.at(Value(points_color.at(Value(5).asString()).asString()).asString()).asDouble();
            double bb5=color_available_1_b.at(Value(points_color.at(Value(5).asString()).asString()).asString()).asDouble();
            double aa5=color_available_1_a.at(Value(points_color.at(Value(5).asString()).asString()).asString()).asDouble();
            
            double rr6=color_available_1_r.at(Value(points_color.at(Value(6).asString()).asString()).asString()).asDouble();
            double gg6=color_available_1_g.at(Value(points_color.at(Value(6).asString()).asString()).asString()).asDouble();
            double bb6=color_available_1_b.at(Value(points_color.at(Value(6).asString()).asString()).asString()).asDouble();
            double aa6=color_available_1_a.at(Value(points_color.at(Value(6).asString()).asString()).asString()).asDouble();
            
            double rr7=color_available_1_r.at(Value(points_color.at(Value(7).asString()).asString()).asString()).asDouble();
            double gg7=color_available_1_g.at(Value(points_color.at(Value(7).asString()).asString()).asString()).asDouble();
            double bb7=color_available_1_b.at(Value(points_color.at(Value(7).asString()).asString()).asString()).asDouble();
            double aa7=color_available_1_a.at(Value(points_color.at(Value(7).asString()).asString()).asString()).asDouble();
            
            double rr8=color_available_1_r.at(Value(points_color.at(Value(8).asString()).asString()).asString()).asDouble();
            double gg8=color_available_1_g.at(Value(points_color.at(Value(8).asString()).asString()).asString()).asDouble();
            double bb8=color_available_1_b.at(Value(points_color.at(Value(8).asString()).asString()).asString()).asDouble();
            double aa8=color_available_1_a.at(Value(points_color.at(Value(8).asString()).asString()).asString()).asDouble();
            
            double rr9=color_available_1_r.at(Value(points_color.at(Value(9).asString()).asString()).asString()).asDouble();
            double gg9=color_available_1_g.at(Value(points_color.at(Value(9).asString()).asString()).asString()).asDouble();
            double bb9=color_available_1_b.at(Value(points_color.at(Value(9).asString()).asString()).asString()).asDouble();
            double aa9=color_available_1_a.at(Value(points_color.at(Value(9).asString()).asString()).asString()).asDouble();
            
            double rr10=color_available_1_r.at(Value(points_color.at(Value(10).asString()).asString()).asString()).asDouble();
            double gg10=color_available_1_g.at(Value(points_color.at(Value(10).asString()).asString()).asString()).asDouble();
            double bb10=color_available_1_b.at(Value(points_color.at(Value(10).asString()).asString()).asString()).asDouble();
            double aa10=color_available_1_a.at(Value(points_color.at(Value(10).asString()).asString()).asString()).asDouble();
            
            double rr11=color_available_1_r.at(Value(points_color.at(Value(11).asString()).asString()).asString()).asDouble();
            double gg11=color_available_1_g.at(Value(points_color.at(Value(11).asString()).asString()).asString()).asDouble();
            double bb11=color_available_1_b.at(Value(points_color.at(Value(11).asString()).asString()).asString()).asDouble();
            double aa11=color_available_1_a.at(Value(points_color.at(Value(11).asString()).asString()).asString()).asDouble();
            
            double rr12=color_available_1_r.at(Value(points_color.at(Value(12).asString()).asString()).asString()).asDouble();
            double gg12=color_available_1_g.at(Value(points_color.at(Value(12).asString()).asString()).asString()).asDouble();
            double bb12=color_available_1_b.at(Value(points_color.at(Value(12).asString()).asString()).asString()).asDouble();
            double aa12=color_available_1_a.at(Value(points_color.at(Value(12).asString()).asString()).asString()).asDouble();
            
            auto dn1 = DrawNode::create();
            dn1->drawPolygon(points1,sizeof(points1)/sizeof(points1[0]),Color4F(rr1,gg1,bb1,aa1),0,Color4F(1,0,0,0.5));
            this->addChild(dn1,1);
            
            auto dn2 = DrawNode::create();
            dn2->drawPolygon(points2,sizeof(points2)/sizeof(points2[0]),Color4F(rr2,gg2,bb2,aa2),0,Color4F(1,0,0,0.5));
            this->addChild(dn2,1);
            
            auto dn3 = DrawNode::create();
            dn3->drawPolygon(points3,sizeof(points3)/sizeof(points3[0]),Color4F(rr3,gg3,bb3,aa3),0,Color4F(1,0,0,0.5));
            this->addChild(dn3,1);
            
            auto dn4 = DrawNode::create();
            dn4->drawPolygon(points4,sizeof(points4)/sizeof(points4[0]),Color4F(rr4,gg4,bb4,aa4),0,Color4F(1,0,0,0.5));
            this->addChild(dn4,1);

            auto dn5 = DrawNode::create();
            dn5->drawPolygon(points5,sizeof(points5)/sizeof(points5[0]),Color4F(rr5,gg5,bb5,aa5),0,Color4F(1,0,0,0.5));
            this->addChild(dn5,1);
            
            auto dn6 = DrawNode::create();
            dn6->drawPolygon(points6,sizeof(points6)/sizeof(points6[0]),Color4F(rr6,gg6,bb6,aa6),0,Color4F(1,0,0,0.5));
            this->addChild(dn6,1);
            
            auto dn7 = DrawNode::create();
            dn7->drawPolygon(points7,sizeof(points7)/sizeof(points7[0]),Color4F(rr7,gg7,bb7,aa7),0,Color4F(1,0,0,0.5));
            this->addChild(dn7,1);
            
            auto dn8 = DrawNode::create();
            dn8->drawPolygon(points8,sizeof(points8)/sizeof(points8[0]),Color4F(rr8,gg8,bb8,aa8),0,Color4F(1,0,0,0.5));
            this->addChild(dn8,1);
            
            auto dn9 = DrawNode::create();
            dn9->drawPolygon(points9,sizeof(points9)/sizeof(points9[0]),Color4F(rr9,gg9,bb9,aa9),0,Color4F(1,0,0,0.5));
            this->addChild(dn9,1);
            
            auto dn10 = DrawNode::create();
            dn10->drawPolygon(points10,sizeof(points10)/sizeof(points10[0]),Color4F(rr10,gg10,bb10,aa10),0,Color4F(1,0,0,0.5));
            this->addChild(dn10,1);
            
            auto dn11 = DrawNode::create();
            dn11->drawPolygon(points11,sizeof(points11)/sizeof(points11[0]),Color4F(rr11,gg11,bb11,aa11),0,Color4F(1,0,0,0.5));
            this->addChild(dn11,1);
            
            auto dn12 = DrawNode::create();
            dn12->drawPolygon(points12,sizeof(points12)/sizeof(points12[0]),Color4F(rr12,gg12,bb12,aa12),0,Color4F(1,0,0,0.5));
            this->addChild(dn12,1);
     
            
            
            
            //不动的
            //auto fg = Sprite::create(fg_pic);
            //fg->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
            //this->addChild(fg, 3);

            
        }
             break;
        case 2:case 3: case 4: case 5: case 6:
        {
            double rr1=color_available_1_r.at(Value(points_color.at(Value(1).asString()).asString()).asString()).asDouble();
            double gg1=color_available_1_g.at(Value(points_color.at(Value(1).asString()).asString()).asString()).asDouble();
            double bb1=color_available_1_b.at(Value(points_color.at(Value(1).asString()).asString()).asString()).asDouble();
            double aa1=color_available_1_a.at(Value(points_color.at(Value(1).asString()).asString()).asString()).asDouble();
            
            double rr2=color_available_1_r.at(Value(points_color.at(Value(2).asString()).asString()).asString()).asDouble();
            double gg2=color_available_1_g.at(Value(points_color.at(Value(2).asString()).asString()).asString()).asDouble();
            double bb2=color_available_1_b.at(Value(points_color.at(Value(2).asString()).asString()).asString()).asDouble();
            double aa2=color_available_1_a.at(Value(points_color.at(Value(2).asString()).asString()).asString()).asDouble();
            
            double rr3=color_available_1_r.at(Value(points_color.at(Value(3).asString()).asString()).asString()).asDouble();
            double gg3=color_available_1_g.at(Value(points_color.at(Value(3).asString()).asString()).asString()).asDouble();
            double bb3=color_available_1_b.at(Value(points_color.at(Value(3).asString()).asString()).asString()).asDouble();
            double aa3=color_available_1_a.at(Value(points_color.at(Value(3).asString()).asString()).asString()).asDouble();
            
            double rr4=color_available_1_r.at(Value(points_color.at(Value(4).asString()).asString()).asString()).asDouble();
            double gg4=color_available_1_g.at(Value(points_color.at(Value(4).asString()).asString()).asString()).asDouble();
            double bb4=color_available_1_b.at(Value(points_color.at(Value(4).asString()).asString()).asString()).asDouble();
            double aa4=color_available_1_a.at(Value(points_color.at(Value(4).asString()).asString()).asString()).asDouble();
            
            double rr5=color_available_1_r.at(Value(points_color.at(Value(5).asString()).asString()).asString()).asDouble();
            double gg5=color_available_1_g.at(Value(points_color.at(Value(5).asString()).asString()).asString()).asDouble();
            double bb5=color_available_1_b.at(Value(points_color.at(Value(5).asString()).asString()).asString()).asDouble();
            double aa5=color_available_1_a.at(Value(points_color.at(Value(5).asString()).asString()).asString()).asDouble();
            
            double rr6=color_available_1_r.at(Value(points_color.at(Value(6).asString()).asString()).asString()).asDouble();
            double gg6=color_available_1_g.at(Value(points_color.at(Value(6).asString()).asString()).asString()).asDouble();
            double bb6=color_available_1_b.at(Value(points_color.at(Value(6).asString()).asString()).asString()).asDouble();
            double aa6=color_available_1_a.at(Value(points_color.at(Value(6).asString()).asString()).asString()).asDouble();

            
            
            auto dn1 = DrawNode::create();
            dn1->drawSolidCircle(Vec2(1080,0), 602, 0, 50, Color4F(rr1,gg1,bb1,aa1));
            this->addChild(dn1,1);
            
            auto dn2 = DrawNode::create();
            dn2->drawSolidCircle(Vec2(1080,0), 527, 0, 50, Color4F(rr2,gg2,bb2,aa2));
            this->addChild(dn2,1);
            auto dn3 = DrawNode::create();
            dn3->drawSolidCircle(Vec2(1080,0), 452, 0, 50, Color4F(rr3,gg3,bb3,aa3));
            this->addChild(dn3,1);
            auto dn4 = DrawNode::create();
            dn4->drawSolidCircle(Vec2(1080,0), 377, 0, 50, Color4F(rr4,gg4,bb4,aa4));
            this->addChild(dn4,1);
            auto dn5 = DrawNode::create();
            dn5->drawSolidCircle(Vec2(1080,0), 302, 0, 50, Color4F(rr5,gg5,bb5,aa5));
            this->addChild(dn5,1);
            auto dn6 = DrawNode::create();
            dn6->drawSolidCircle(Vec2(1080,0), 227, 0, 50, Color4F(rr6,gg6,bb6,aa6));
            this->addChild(dn6,1);

        }
            break;
        case 7:
        {
            
            
        }
             break;
        case 8:
        {
            
        }
             break;
        case 9:
        {
            
        }
    }

}

void GameMain::createballcolor()
{
    for(int i=1;i<=(color_available_team_color_num - color_choose);i++)
    {
        

        ball_sprite_color_r_remain[Value(i).asString()] = color_available_1_r[color_remain_array[Value(i).asString()].asString()];
        ball_sprite_color_g_remain[Value(i).asString()] = color_available_1_g[color_remain_array[Value(i).asString()].asString()];
        ball_sprite_color_b_remain[Value(i).asString()] = color_available_1_b[color_remain_array[Value(i).asString()].asString()];
        ball_sprite_color_a_remain[Value(i).asString()] = color_available_1_a[color_remain_array[Value(i).asString()].asString()];
        
    }
    
    for(int i=1;i<=color_choose;i++)
    {
        
        
        ball_sprite_color_r_right[Value(i).asString()] = color_available_1_r[color_right_array[Value(i).asString()].asString()];
        ball_sprite_color_g_right[Value(i).asString()] = color_available_1_g[color_right_array[Value(i).asString()].asString()];
        ball_sprite_color_b_right[Value(i).asString()] = color_available_1_b[color_right_array[Value(i).asString()].asString()];
        ball_sprite_color_a_right[Value(i).asString()] = color_available_1_a[color_right_array[Value(i).asString()].asString()];
        
    }

    
    for(int i =1;i<=available_team;i++)
        
    {
        int need_num = available_rate.at(Value(i).asString()).asInt()*ball_num/100;
        int have_num = available_num.at(Value(i).asString()).asInt();
        
        //随机数因子
        timeval psv;
        gettimeofday(&psv, NULL);
        unsigned rand_seed = psv.tv_sec*1000 + psv.tv_usec/1000;
        srand(rand_seed);
        
        for(int j=1;j<=need_num;j++)
        {
            log("havenum:%d",have_num);
            int a = rand()%have_num+1;
            
        
            if(i==1)
            {
                
                
                ball_sprite_color_r.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(ball_sprite_color_r_right.at(Value(a).asString()))));
                ball_sprite_color_g.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(ball_sprite_color_g_right.at(Value(a).asString()))));
                ball_sprite_color_b.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(ball_sprite_color_b_right.at(Value(a).asString()))));
                ball_sprite_color_a.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(ball_sprite_color_a_right.at(Value(a).asString()))));
                
                
            }else if(i==2)
            {
                ball_sprite_color_r.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(ball_sprite_color_r_remain.at(Value(a).asString()))));
                ball_sprite_color_g.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(ball_sprite_color_g_remain.at(Value(a).asString()))));
                ball_sprite_color_b.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(ball_sprite_color_b_remain.at(Value(a).asString()))));
                ball_sprite_color_a.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(ball_sprite_color_a_remain.at(Value(a).asString()))));
                
            }else if(i==3)
            {
                ball_sprite_color_r.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(color_available_2_r.at(Value(a).asString()))));
                ball_sprite_color_g.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(color_available_2_g.at(Value(a).asString()))));
                ball_sprite_color_b.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(color_available_2_b.at(Value(a).asString()))));
                ball_sprite_color_a.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(color_available_2_a.at(Value(a).asString()))));
                
            }else if(i==4)
            {
                ball_sprite_color_r.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(color_available_3_r.at(Value(a).asString()))));
                ball_sprite_color_g.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(color_available_3_g.at(Value(a).asString()))));
                ball_sprite_color_b.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(color_available_3_b.at(Value(a).asString()))));
                ball_sprite_color_a.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(color_available_3_a.at(Value(a).asString()))));
                
            }
        
            
            
            //标记出球是好是坏
            int insert_ball_kind = available_kind.at(Value(i).asString()).asInt();
            
            ball_sprite_color_kind.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(insert_ball_kind)));
            
            count_ball_sprite =  count_ball_sprite + 1;
            if(insert_ball_kind == 1)
            {
                count_ball_sprite_good = count_ball_sprite_good+1;
            }else if(insert_ball_kind == 2)
            {
                count_ball_sprite_bad = count_ball_sprite_bad+1;
            }
        }
        
    }
    
    //打乱ball_sprite的先后顺序：randomqueue(ball_sprite_name,ball_sprite_name_kind,count_ball_sprite_name-1);
    randomqueuecolor();
    
    //把名字转换成精灵加入精灵队列
    for(int n=1;n<=count_ball_sprite-1;n++)
    {
        auto insert_ball = Sprite::create("ball/01_02_01_0001.png");
        ball_sprite_color.insert(n,insert_ball);
    }
    
    for(int n=1;n<=count_ball_sprite-1;n++)
    {
        
        auto circle = DrawNode::create();
        ball_sprite_color_fake.insert(n,circle);

    }
    
    
}


void GameMain::flower_show()
{
    //场景动画，当时间到达时改变成成功状态；或当gameover时触发改变成失败状态。
    sprite = Sprite::create();
    this->addChild(sprite, 3);
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    Animation* animation = Animation::create();
  
    for( int i=1;i<=act_num;i++)
    {
        char szName[100] = {0};
        
        if(i<=9)
        {
            sprintf(szName, "act/g%d_%d.png",game_round,i);
        }if((i>9) && (i<100))
        {
            int i1 = i/10;
            int i2 = i%10;
            sprintf(szName, "act/g%d_%d%d.png",game_round,i1,i2);
        }
        animation->addSpriteFrameWithFileName(szName); //加载动画的帧
    }
    animation->setDelayPerUnit(1);//变一次多少秒
    animation->setRestoreOriginalFrame(true);
    animation->setLoops(20); //动画循环10次
    Animate *animate = Animate::create(animation);
    action = Sequence::create(animate, animate->reverse(), NULL);
    sprite->runAction(action);

}




std::string GameMain::intto2string(int number)
{
    std::string number_string_2;
    
    if(number<=9)
    {
        number_string_2= "0" + Value(number).asString();
    }else{
        number_string_2= Value(number).asString();
    }
    return number_string_2;
}

std::string GameMain::intto4string(int number)
{
    std::string number_string_4;
    
    if(number<=9)
    {
        number_string_4= "000" + Value(number).asString();
    }else if(number<=99)
    {
        number_string_4= "00" + Value(number).asString();
    }else if(number<=999)
    {
        number_string_4= "0" + Value(number).asString();
    }else{
        number_string_4= Value(number).asString();
    }
    return number_string_4;
}



void GameMain::createqueue()
{
    for(int i =1;i<=available_team;i++)
    {
        int need_num = available_rate.at(Value(i).asString()).asInt()*ball_num/100;
        int have_num = available_num.at(Value(i).asString()).asInt();
        
        //随机数因子
        timeval psv;
        gettimeofday(&psv, NULL);
        unsigned rand_seed = psv.tv_sec*1000 + psv.tv_usec/1000;
        srand(rand_seed);
        
        for(int j=1;j<=need_num;j++)
        {
            int a = rand()%have_num+1;
            
            
            //把game_round转换成四位数字,i转换成2位数字，a转化成4位数字
            std::string game_round_string = intto2string(game_round);
            std::string game_level_string = intto2string(game_level);
            std::string i_string = intto2string(i);
            std::string a_string = intto4string(a);
            
            
            std::string insert_ball_name = "ball/" + game_round_string + "_" + game_level_string + "_" + i_string + "_" + a_string + ".png";
            
            
            ball_sprite_name.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(insert_ball_name)));
            
            //标记出球是好是坏
            int insert_ball_kind = available_kind.at(Value(i).asString()).asInt();
            
            ball_sprite_name_kind.insert(std::make_pair(Value(count_ball_sprite).asString(),Value(insert_ball_kind)));
            
            count_ball_sprite =  count_ball_sprite + 1;
            if(insert_ball_kind == 1)
            {
                count_ball_sprite_good = count_ball_sprite_good+1;
            }else if(insert_ball_kind == 2)
            {
                count_ball_sprite_bad = count_ball_sprite_bad+1;
            }

        }
        
    }
    
    //打乱ball_sprite的先后顺序：randomqueue(ball_sprite_name,ball_sprite_name_kind,count_ball_sprite_name-1);
    randomqueue();
    
    
    std::string aaaaa = ball_sprite_name.at(Value(1).asString()).asString();
    log("%s",aaaaa.c_str());
    std::string bbbb = ball_sprite_name_kind.at(Value(1).asString()).asString();
    log("%s",bbbb.c_str());
    log("%d",count_ball_sprite);
    
    //把名字转换成精灵加入精灵队列
    for(int n=1;n<=count_ball_sprite-1;n++)
    {
        auto insert_ball = Sprite::create(ball_sprite_name.at(Value(n).asString()).asString());
        ball_sprite.insert(n,insert_ball);
    }
    
    
    
    
}


//不用返回，直接把全局变量改了
void GameMain::randomqueue()
{
    
    //随机数因子
    timeval psv;
    gettimeofday(&psv, NULL);
    unsigned rand_seed = psv.tv_sec*1000 + psv.tv_usec/1000;
    srand(rand_seed);
    //log("%d",innum);
    
    for(int i=0;i<count_ball_sprite-1;i++)
    {
        int rand_a = rand()%(count_ball_sprite-1)+1;
        int rand_b = rand()%(count_ball_sprite-1)+1;
        //rand_b = rand()%20+1;
        //log("%d",rand_a);
        log("%d",rand_b);
        
        
        std::string temp_a = ball_sprite_name.at(Value(rand_a).asString()).asString();
        std::string temp_b = ball_sprite_name.at(Value(rand_b).asString()).asString();
        ball_sprite_name.erase(Value(rand_a).asString());
        ball_sprite_name.erase(Value(rand_b).asString());
        ball_sprite_name.insert(std::make_pair(Value(rand_a).asString(),Value(temp_b)));
        ball_sprite_name.insert(std::make_pair(Value(rand_b).asString(),Value(temp_a)));
        
        int temp_c = ball_sprite_name_kind.at(Value(rand_a).asString()).asInt();
        int temp_d = ball_sprite_name_kind.at(Value(rand_b).asString()).asInt();
        ball_sprite_name_kind.erase(Value(rand_a).asString());
        ball_sprite_name_kind.erase(Value(rand_b).asString());
        ball_sprite_name_kind.insert(std::make_pair(Value(rand_a).asString(),Value(temp_d)));
        ball_sprite_name_kind.insert(std::make_pair(Value(rand_b).asString(),Value(temp_c)));
        
        
    }
   
}

//不用返回，直接把全局变量改了
void GameMain::randomqueuecolor()
{
    
    //随机数因子
    timeval psv;
    gettimeofday(&psv, NULL);
    unsigned rand_seed = psv.tv_sec*1000 + psv.tv_usec/1000;
    srand(rand_seed);
    //log("%d",innum);
    
    for(int i=0;i<count_ball_sprite-1;i++)
    {
        int rand_a = rand()%(count_ball_sprite-1)+1;
        int rand_b = rand()%(count_ball_sprite-1)+1;
        log("%d",rand_b);
        
        
        double temp_a1 = ball_sprite_color_r.at(Value(rand_a).asString()).asDouble();
        double temp_b1 = ball_sprite_color_r.at(Value(rand_b).asString()).asDouble();
        ball_sprite_color_r.erase(Value(rand_a).asString());
        ball_sprite_color_r.erase(Value(rand_b).asString());
        ball_sprite_color_r.insert(std::make_pair(Value(rand_a).asString(),Value(temp_b1)));
        ball_sprite_color_r.insert(std::make_pair(Value(rand_b).asString(),Value(temp_a1)));
        
        double temp_a2 = ball_sprite_color_g.at(Value(rand_a).asString()).asDouble();
        double temp_b2 = ball_sprite_color_g.at(Value(rand_b).asString()).asDouble();
        ball_sprite_color_g.erase(Value(rand_a).asString());
        ball_sprite_color_g.erase(Value(rand_b).asString());
        ball_sprite_color_g.insert(std::make_pair(Value(rand_a).asString(),Value(temp_b2)));
        ball_sprite_color_g.insert(std::make_pair(Value(rand_b).asString(),Value(temp_a2)));
        
        double temp_a3 = ball_sprite_color_b.at(Value(rand_a).asString()).asDouble();
        double temp_b3 = ball_sprite_color_b.at(Value(rand_b).asString()).asDouble();
        ball_sprite_color_b.erase(Value(rand_a).asString());
        ball_sprite_color_b.erase(Value(rand_b).asString());
        ball_sprite_color_b.insert(std::make_pair(Value(rand_a).asString(),Value(temp_b3)));
        ball_sprite_color_b.insert(std::make_pair(Value(rand_b).asString(),Value(temp_a3)));
        
        double temp_a4 = ball_sprite_color_a.at(Value(rand_a).asString()).asDouble();
        double temp_b4 = ball_sprite_color_a.at(Value(rand_b).asString()).asDouble();
        ball_sprite_color_a.erase(Value(rand_a).asString());
        ball_sprite_color_a.erase(Value(rand_b).asString());
        ball_sprite_color_a.insert(std::make_pair(Value(rand_a).asString(),Value(temp_b4)));
        ball_sprite_color_a.insert(std::make_pair(Value(rand_b).asString(),Value(temp_a4)));
        
        
        int temp_c = ball_sprite_color_kind.at(Value(rand_a).asString()).asInt();
        int temp_d = ball_sprite_color_kind.at(Value(rand_b).asString()).asInt();
        ball_sprite_color_kind.erase(Value(rand_a).asString());
        ball_sprite_color_kind.erase(Value(rand_b).asString());
        ball_sprite_color_kind.insert(std::make_pair(Value(rand_a).asString(),Value(temp_d)));
        ball_sprite_color_kind.insert(std::make_pair(Value(rand_b).asString(),Value(temp_c)));
        
        
    }
    
}


ValueMap GameMain::random(int innum,int outnum)
{
    
    //随机数因子
    timeval psv;
    gettimeofday(&psv, NULL);
    unsigned rand_seed = psv.tv_sec*1000 + psv.tv_usec/1000;
    srand(rand_seed);
    
    cocos2d::ValueMap outarray;
    cocos2d::ValueMap inarray;
    int count_out = 0;
    
    for(int i=1;i<=innum;i++)
    {
        inarray.insert(std::make_pair(Value(i).asString(),Value(i)));
    }
    
    for(int i=1;i<=outnum;i++)
    {
        int rand_a = rand()% (innum-count_out)+1;
        log("----suijishu-----%d",rand_a);
        outarray[Value(i).asString()]= inarray[Value(rand_a).asString()];
        
       
        log("--------zhi--------%d",inarray.at(Value(rand_a).asString()).asInt());
        inarray.erase(Value(rand_a).asString());
       
        
        
        for(int j=rand_a;j<=(innum-count_out-1);j++)
        {
       
            inarray.insert(std::make_pair(Value(j).asString(),Value(inarray.at(Value(j+1).asString()).asInt())));
            inarray.erase(Value(j+1).asString());
            
        }
        
        inarray.erase(Value(innum-count_out).asString());
        
        count_out = count_out+1;
        
    }
    
    
    color_remain_array = inarray;
    color_right_array = outarray;
    
    return outarray;
    
    
}


void GameMain::update(float dt)
{
    
    if(game_moda == 1)
    {
    
    //发射小球
    
    for(int i=1; i<=area_num; i++)
    {
        if((count_ball_sprite - count_ball_sprite_now > 0) && (time % (area_ball_gaptime.at(Value(i).asString()).asInt()) == 0))
        {
            auto circle_fake = ball_sprite_color_fake.at(count_ball_sprite_now);
            auto circle = ball_sprite_color.at(count_ball_sprite_now);
            
            double rd = ball_sprite_color_r.at(Value(count_ball_sprite_now).asString()).asDouble();
            double gd = ball_sprite_color_g.at(Value(count_ball_sprite_now).asString()).asDouble();
            double bd = ball_sprite_color_b.at(Value(count_ball_sprite_now).asString()).asDouble();
            double ad = ball_sprite_color_a.at(Value(count_ball_sprite_now).asString()).asDouble();
            
            int begin_x = area_ball_begin_x.at(Value(i).asString()).asInt();
            int begin_y = area_ball_begin_y.at(Value(i).asString()).asInt();
            int end_x = area_ball_end_x.at(Value(i).asString()).asInt();
            int end_y = area_ball_end_y.at(Value(i).asString()).asInt();
            
            
            circle->setPosition(Vec2(begin_x,begin_y));
            circle_fake->drawSolidCircle(Vec2(begin_x,begin_y), 100, 0, 50, Color4F(rd,gd,bd,ad));
            this->addChild(circle,3);
            this->addChild(circle_fake, 3);


            
            
            ActionInterval *forward = MoveTo::create(area_ball_speed.at(Value(i).asString()).asInt(), Vec2(end_x,end_y));
            
            //这个球是好是坏
            
            int kind = ball_sprite_color_kind.at(Value(count_ball_sprite_now).asString()).asInt();
            
            auto action = CallFunc::create(CC_CALLBACK_0(GameMain::stopCallBack,this,kind));
            
            auto seq = Sequence::create(forward,action,NULL);
            
            circle->runAction(seq);

            
            ActionInterval *forward2 = MoveTo::create(area_ball_speed.at(Value(i).asString()).asInt(), Vec2(end_x-begin_x,end_y-begin_y));
            circle_fake->runAction(forward2);

            
            //draw画着颜色的球，跟着动

            
            //把每个球的动作记起来，以后要用来判断
            ball_action.insert(count_ball_sprite_now,forward);
            
            int spriteMoveToKind = ball_sprite_color_kind.at(Value(count_ball_sprite_now).asString()).asInt();
            auto this_it = this;
            
            auto listenter = EventListenerTouchOneByOne::create();
            listenter->onTouchBegan = [circle,circle_fake,spriteMoveToKind,this_it](Touch* t, Event * e) {
                if (circle->getBoundingBox().containsPoint(t->getLocation())) {
                    //杀了好的球，则游戏结束
                    if (spriteMoveToKind==1) {
                    //MessageBox("Click Text","Click");
                          //游戏结束
                          utils::captureScreen(CC_CALLBACK_2(GameMain::captureOver, this_it), "screenshot.png");
                          CCTextureCache::getInstance()->removeUnusedTextures();
                    }else if (spriteMoveToKind==2) {
                          //删除这个精灵and取消显示
                        circle->setVisible(false);
                        this_it->removeChild(circle);
                        circle_fake->setVisible(false);
                        this_it->removeChild(circle_fake);
                    }
                    
                    
                }
                return false;
            };
            
            Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenter, circle);
            
            count_ball_sprite_now = count_ball_sprite_now + 1;
            
        }
        

    }
    
    
    //更新时间
    time = time - 1;
    log("%d",time);
        
    }else if (game_moda == 2)
    {
        
        //发射小球
        
        for(int i=1; i<=area_num; i++)
        {
            //if((time > 0) && (time % (area_ball_gaptime.at(Value(i).asString()).asInt()) == 0))
            if((count_ball_sprite - count_ball_sprite_now > 0) && (time % (area_ball_gaptime.at(Value(i).asString()).asInt()) == 0))
            {
                
                auto spriteMoveTo = ball_sprite.at(count_ball_sprite_now);
                
                int begin_x = area_ball_begin_x.at(Value(i).asString()).asInt();
                int begin_y = area_ball_begin_y.at(Value(i).asString()).asInt();
                int end_x = area_ball_end_x.at(Value(i).asString()).asInt();
                int end_y = area_ball_end_y.at(Value(i).asString()).asInt();
                
                spriteMoveTo->setPosition(Vec2(begin_x,begin_y));
                this->addChild(spriteMoveTo, 3);
                
                ActionInterval *forward = MoveTo::create(area_ball_speed.at(Value(i).asString()).asInt(), Vec2(end_x,end_y));
                
                //这个球是好是坏
                
                int kind = ball_sprite_name_kind.at(Value(count_ball_sprite_now).asString()).asInt();
                
                
                auto action = CallFunc::create(CC_CALLBACK_0(GameMain::stopCallBack,this,kind));
           
                
                auto seq = Sequence::create(forward,action,NULL);
                
                spriteMoveTo->runAction(seq);
                
                //把每个球的动作记起来，以后要用来判断
                ball_action.insert(count_ball_sprite_now,forward);
                
                int spriteMoveToKind = ball_sprite_name_kind.at(Value(count_ball_sprite_now).asString()).asInt();
                auto this_it = this;
                
                auto listenter = EventListenerTouchOneByOne::create();
                listenter->onTouchBegan = [spriteMoveTo,spriteMoveToKind,this_it](Touch* t, Event * e) {
                    if (spriteMoveTo->getBoundingBox().containsPoint(t->getLocation())) {
                        //杀了好的球，则游戏结束
                        if (spriteMoveToKind==1) {
                            
                            //MessageBox("Click Text","Click");
                            //游戏结束
                            utils::captureScreen(CC_CALLBACK_2(GameMain::captureOver, this_it), "screenshot.png");
                            CCTextureCache::getInstance()->removeUnusedTextures();
                        }else if (spriteMoveToKind==2) {
                            //删除这个精灵and取消显示
                            spriteMoveTo->setVisible(false);
                            this_it->removeChild(spriteMoveTo);
                        }
                        
                        
                    }
                    return false;
                };
                
                Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenter, spriteMoveTo);
                count_ball_sprite_now = count_ball_sprite_now + 1;
                
            }
            
            
        }
        
        
        //更新时间
        time = time - 1;
        //log("%d",time);
        
    }
}

void GameMain::stopCallBack(int num)
{
    if(num == 2)
    {
        utils::captureScreen(CC_CALLBACK_2(GameMain::captureOver, this), "screenshot.png");
        CCTextureCache::getInstance()->removeUnusedTextures();
    }if(num == 1)
    {
        count_ball_sprite_now_arrive = count_ball_sprite_now_arrive+1;
        
        if(count_ball_sprite_now_arrive == count_ball_sprite_good)
        {
            utils::captureScreen(CC_CALLBACK_2(GameMain::captureNext, this), "screenshot.png");
            CCTextureCache::getInstance()->removeUnusedTextures();
        }
    }
}

void GameMain::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void GameMain::captureNext(bool succeed, const std::string& outputFile)
{
    if (succeed) {
        log("%s", outputFile.c_str());
        
    }
    
    /*
    //本关游戏数据写入userdefault
    //--得到的饲料个数--
    if(UserDefault::getInstance()->getIntegerForKey("feed"))
    {
        int star_new = UserDefault::getInstance()->getIntegerForKey("feed")+star;
        UserDefault::getInstance()->setIntegerForKey("feed", star_new);
    }else{
        int star_new = star;
        UserDefault::getInstance()->setIntegerForKey("feed", star_new);
        
    }
    //--是否得到的新宝贝--
    if(UserDefault::getInstance()->getIntegerForKey("baby_num"))
    {
        if(play_num-1 > UserDefault::getInstance()->getIntegerForKey("baby_num"))
        {
            UserDefault::getInstance()->setIntegerForKey("baby_num", play_num-1);
            baby_show = play_num-1;
        }
    }else{
        UserDefault::getInstance()->setIntegerForKey("baby_num", play_num-1);
        baby_show = play_num-1;
    }
    
    */
    
    
    UserDefault::getInstance()->flush();
    
    //int b = UserDefault::getInstance()->getIntegerForKey("feed");
    //log("b = %d", b);
    
    game_level = game_level + 1;
    
    if(game_level == 3)
    {
        game_level = 1;
        
        //本关变为done
        cocos2d::__String* level_stat = String::createWithFormat("game_round_stat%d",game_round);
        UserDefault::getInstance()->setIntegerForKey(level_stat->getCString(), 2);
        
        //下一关如果是处在没有或者0状态，则变为1
        cocos2d::__String* level_stat_next = String::createWithFormat("game_round_stat%d",game_round+1);
        
        if(UserDefault::getInstance()->getIntegerForKey(level_stat_next->getCString()))
        {
            if(UserDefault::getInstance()->getIntegerForKey(level_stat_next->getCString())==0)
            {
                UserDefault::getInstance()->setIntegerForKey(level_stat_next->getCString(), 1);
            }
        }else{
            UserDefault::getInstance()->setIntegerForKey(level_stat_next->getCString(), 1);
        }

        
    }
    
    //Director::getInstance()->replaceScene(First::createScene());
    
    //判断是否所有关卡完成
    int is_completed;
    if(game_round>=13)
    {
        is_completed = 1;
        
    }else{
        is_completed = 0;
    }
    
    
    Director::getInstance()->replaceScene(GameNext::scene(outputFile.c_str(),is_completed,game_round,game_level));
}









void GameMain::captureOver(bool succeed, const std::string& outputFile)
{
    if (succeed) {
        log("%s", outputFile.c_str());
        
    }
    
    
    //本关游戏数据写入userdefault
    //--已经通过了第几关--
    //if(UserDefault::getInstance()->getIntegerForKey("feed"))
    //{
    //    int star_new = UserDefault::getInstance()->getIntegerForKey("feed")+star;
    //    UserDefault::getInstance()->setIntegerForKey("feed", star_new);
    //}else{
    //    int star_new = star;
    //    UserDefault::getInstance()->setIntegerForKey("feed", star_new);
        
    //}
    //--得到的新的宝贝--
    /*
     if(UserDefault::getInstance()->getIntegerForKey("feed"))
     {
     int star_new = UserDefault::getInstance()->getIntegerForKey("feed")+star;
     UserDefault::getInstance()->setIntegerForKey("feed", star_new);
     }else{
     int star_new = star;
     UserDefault::getInstance()->setIntegerForKey("feed", star_new);
     
     }
     */
    

    
    UserDefault::getInstance()->flush();
    
    //int b = UserDefault::getInstance()->getIntegerForKey("feed");
    //log("b = %d", b);
    
    
    //UserDefault::getInstance()->setBoolForKey("BOOL", true);
    //UserDefault::getInstance()->setFloatForKey("Float", 12.18);
    //UserDefault::getInstance()->setStringForKey("String", "Jacedy");
    
    //保存数据
    // UserDefault::getInstance()->flush();
    
    // bool b = UserDefault::getInstance()->getBoolForKey("BOOL", false);      //第二个参数为初始化内容
    //float f = UserDefault::getInstance()->getFloatForKey("Float", 0.0f);
    // std::string s = UserDefault::getInstance()->getStringForKey("String", "null");
    
    //打印输出
    // log("b = %d", b);
    // log("f = %f", f);
    // log("s = %s", s.c_str());
    
    //获取文件路径
    //FileUtils::getInstance()->getWritablePath();
    
    //判断XML文件是否存在
    //UserDefault::getInstance()->isXMLFileExit();
    
    
    
    
    
    
    //把静态变量初始化
    //game_round = 1;
    game_level = 1;
    //int game_score_now = score;
    game_score = 0;
    
    
    
    Director::getInstance()->replaceScene(GameOver::scene(outputFile.c_str()));
}





void GameMain::define()
{
    log("%d",game_round);
    switch (game_round){
        case 1:
        {
            if(game_level == 1)
            {
                time = 1000;
                pre_bg_pic = "pre_bg/pre_bg1.png";
                bg_pic = "bg/bg1.png";
                fg_pic = "flower/f1.png";
                mc_pic = "mc/mc1.png";
                act_num = 12;
                
                game_moda = 1;
                area_num = 4;
                ball_num = 10;
                area_mode.insert(std::make_pair(Value(1).asString(), Value(1)));
                area_mode.insert(std::make_pair(Value(2).asString(), Value(1)));
                area_mode.insert(std::make_pair(Value(3).asString(), Value(1)));
                area_mode.insert(std::make_pair(Value(4).asString(), Value(1)));
                
                //多少秒到达，数字越小越快
                area_ball_speed.insert(std::make_pair(Value(1).asString(), Value(5)));
                area_ball_speed.insert(std::make_pair(Value(2).asString(), Value(5)));
                area_ball_speed.insert(std::make_pair(Value(3).asString(), Value(6)));
                area_ball_speed.insert(std::make_pair(Value(4).asString(), Value(5)));
                //每xx帧一个，数字越大间隔越大
                area_ball_gaptime.insert(std::make_pair(Value(1).asString(), Value(300)));
                area_ball_gaptime.insert(std::make_pair(Value(2).asString(), Value(300)));
                area_ball_gaptime.insert(std::make_pair(Value(3).asString(), Value(300)));
                area_ball_gaptime.insert(std::make_pair(Value(4).asString(), Value(300)));
                //起始位置
                area_ball_begin_x.insert(std::make_pair(Value(1).asString(), Value(0)));
                area_ball_begin_y.insert(std::make_pair(Value(1).asString(), Value(0)));
                area_ball_end_x.insert(std::make_pair(Value(1).asString(), Value(500)));
                area_ball_end_y.insert(std::make_pair(Value(1).asString(), Value(900)));
                
                area_ball_begin_x.insert(std::make_pair(Value(2).asString(), Value(1080)));
                area_ball_begin_y.insert(std::make_pair(Value(2).asString(), Value(0)));
                area_ball_end_x.insert(std::make_pair(Value(2).asString(), Value(500)));
                area_ball_end_y.insert(std::make_pair(Value(2).asString(), Value(900)));
                
                area_ball_begin_x.insert(std::make_pair(Value(3).asString(), Value(0)));
                area_ball_begin_y.insert(std::make_pair(Value(3).asString(), Value(1920)));
                area_ball_end_x.insert(std::make_pair(Value(3).asString(), Value(500)));
                area_ball_end_y.insert(std::make_pair(Value(3).asString(), Value(900)));
                
                area_ball_begin_x.insert(std::make_pair(Value(4).asString(), Value(1080)));
                area_ball_begin_y.insert(std::make_pair(Value(4).asString(), Value(1920)));
                area_ball_end_x.insert(std::make_pair(Value(4).asString(), Value(500)));
                area_ball_end_y.insert(std::make_pair(Value(4).asString(), Value(900)));
                
                //本关有几组可以选择
                available_team = 3;
                
                //每组共多少球可选(或多少颜色)
                available_num.insert(std::make_pair(Value(1).asString(), Value(4)));
                available_num.insert(std::make_pair(Value(2).asString(), Value(1)));
                available_num.insert(std::make_pair(Value(3).asString(), Value(5)));
                //available_num.insert(std::make_pair(Value(1).asString(), Value(6)));
                //available_num.insert(std::make_pair(Value(2).asString(), Value(4)));
                //available_num.insert(std::make_pair(Value(3).asString(), Value(1)));
                
                //每组出现概率
                available_rate.insert(std::make_pair(Value(1).asString(), Value(40)));
                available_rate.insert(std::make_pair(Value(2).asString(), Value(30)));
                available_rate.insert(std::make_pair(Value(3).asString(), Value(30)));
                
                //每组的好坏：1-好，2-坏
                available_kind.insert(std::make_pair(Value(1).asString(), Value(1)));
                available_kind.insert(std::make_pair(Value(2).asString(), Value(2)));
                available_kind.insert(std::make_pair(Value(3).asString(), Value(2)));
                
                //可选择的颜色数组初始化
                //color_available_team_num = 2;
                color_available_team_color_num = 5;
                
                color_choose = 4;
                
                //中间有几个色块
                points_num = 12;
                
                
                color_available_1_r.insert(std::make_pair(Value(1).asString(), Value(1)));
                color_available_1_r.insert(std::make_pair(Value(2).asString(), Value(1)));
                color_available_1_r.insert(std::make_pair(Value(3).asString(), Value(0.8)));
                color_available_1_r.insert(std::make_pair(Value(4).asString(), Value(0.2)));
                color_available_1_r.insert(std::make_pair(Value(5).asString(), Value(0.6)));
                
                
                color_available_2_r.insert(std::make_pair(Value(1).asString(), Value(0)));
                color_available_2_r.insert(std::make_pair(Value(2).asString(), Value(0)));
                color_available_2_r.insert(std::make_pair(Value(3).asString(), Value(0)));
                color_available_2_r.insert(std::make_pair(Value(4).asString(), Value(1)));
                color_available_2_r.insert(std::make_pair(Value(5).asString(), Value(0.6)));
                
                
                
                color_available_1_g.insert(std::make_pair(Value(1).asString(), Value(1)));
                color_available_1_g.insert(std::make_pair(Value(2).asString(), Value(0.4)));
                color_available_1_g.insert(std::make_pair(Value(3).asString(), Value(0.2)));
                color_available_1_g.insert(std::make_pair(Value(4).asString(), Value(0)));
                color_available_1_g.insert(std::make_pair(Value(5).asString(), Value(0.6)));
                
                
                color_available_2_g.insert(std::make_pair(Value(1).asString(), Value(0.4)));
                color_available_2_g.insert(std::make_pair(Value(2).asString(), Value(0.2)));
                color_available_2_g.insert(std::make_pair(Value(3).asString(), Value(0.6)));
                color_available_2_g.insert(std::make_pair(Value(4).asString(), Value(0)));
                color_available_2_g.insert(std::make_pair(Value(5).asString(), Value(0.8)));
                
                
                color_available_1_b.insert(std::make_pair(Value(1).asString(), Value(0)));
                color_available_1_b.insert(std::make_pair(Value(2).asString(), Value(0)));
                color_available_1_b.insert(std::make_pair(Value(3).asString(), Value(0.8)));
                color_available_1_b.insert(std::make_pair(Value(4).asString(), Value(0.6)));
                color_available_1_b.insert(std::make_pair(Value(5).asString(), Value(0.6)));
                
                
                color_available_2_b.insert(std::make_pair(Value(1).asString(), Value(0.6)));
                color_available_2_b.insert(std::make_pair(Value(2).asString(), Value(0.8)));
                color_available_2_b.insert(std::make_pair(Value(3).asString(), Value(0.2)));
                color_available_2_b.insert(std::make_pair(Value(4).asString(), Value(0)));
                color_available_2_b.insert(std::make_pair(Value(5).asString(), Value(0.2)));
                
                
                color_available_1_a.insert(std::make_pair(Value(1).asString(), Value(1)));
                color_available_1_a.insert(std::make_pair(Value(2).asString(), Value(1)));
                color_available_1_a.insert(std::make_pair(Value(3).asString(), Value(1)));
                color_available_1_a.insert(std::make_pair(Value(4).asString(), Value(1)));
                color_available_1_a.insert(std::make_pair(Value(5).asString(), Value(1)));
                
                
                color_available_2_a.insert(std::make_pair(Value(1).asString(), Value(1)));
                color_available_2_a.insert(std::make_pair(Value(2).asString(), Value(1)));
                color_available_2_a.insert(std::make_pair(Value(3).asString(), Value(1)));
                color_available_2_a.insert(std::make_pair(Value(4).asString(), Value(1)));
                color_available_2_a.insert(std::make_pair(Value(5).asString(), Value(1)));
                
            }
            if(game_level == 2)
            {
                time = 1000;
                bg_pic = "bg/bg2.png";
                fg_pic = "flower/f1.png";
                mc_pic = "mc/mc1.png";
                act_num = 12;
                
                game_moda = 2;
                area_num = 4;
                ball_num = 10;
                area_mode.insert(std::make_pair(Value(1).asString(), Value(1)));
                area_mode.insert(std::make_pair(Value(2).asString(), Value(1)));
                area_mode.insert(std::make_pair(Value(3).asString(), Value(1)));
                area_mode.insert(std::make_pair(Value(4).asString(), Value(1)));
                
                //多少秒到达，数字越小越快
                area_ball_speed.insert(std::make_pair(Value(1).asString(), Value(5)));
                area_ball_speed.insert(std::make_pair(Value(2).asString(), Value(5)));
                area_ball_speed.insert(std::make_pair(Value(3).asString(), Value(6)));
                area_ball_speed.insert(std::make_pair(Value(4).asString(), Value(5)));
                //每xx帧一个，数字越大间隔越大
                area_ball_gaptime.insert(std::make_pair(Value(1).asString(), Value(300)));
                area_ball_gaptime.insert(std::make_pair(Value(2).asString(), Value(300)));
                area_ball_gaptime.insert(std::make_pair(Value(3).asString(), Value(300)));
                area_ball_gaptime.insert(std::make_pair(Value(4).asString(), Value(300)));
                //起始位置
                area_ball_begin_x.insert(std::make_pair(Value(1).asString(), Value(0)));
                area_ball_begin_y.insert(std::make_pair(Value(1).asString(), Value(0)));
                area_ball_end_x.insert(std::make_pair(Value(1).asString(), Value(500)));
                area_ball_end_y.insert(std::make_pair(Value(1).asString(), Value(900)));
                
                area_ball_begin_x.insert(std::make_pair(Value(2).asString(), Value(1080)));
                area_ball_begin_y.insert(std::make_pair(Value(2).asString(), Value(0)));
                area_ball_end_x.insert(std::make_pair(Value(2).asString(), Value(500)));
                area_ball_end_y.insert(std::make_pair(Value(2).asString(), Value(900)));
                
                area_ball_begin_x.insert(std::make_pair(Value(3).asString(), Value(0)));
                area_ball_begin_y.insert(std::make_pair(Value(3).asString(), Value(1920)));
                area_ball_end_x.insert(std::make_pair(Value(3).asString(), Value(500)));
                area_ball_end_y.insert(std::make_pair(Value(3).asString(), Value(900)));
                
                area_ball_begin_x.insert(std::make_pair(Value(4).asString(), Value(1080)));
                area_ball_begin_y.insert(std::make_pair(Value(4).asString(), Value(1920)));
                area_ball_end_x.insert(std::make_pair(Value(4).asString(), Value(500)));
                area_ball_end_y.insert(std::make_pair(Value(4).asString(), Value(900)));
                
                //本关有几组可以选择
                available_team = 3;
                
                //每组共多少球可选(或多少颜色)
              
                available_num.insert(std::make_pair(Value(1).asString(), Value(6)));
                available_num.insert(std::make_pair(Value(2).asString(), Value(4)));
                available_num.insert(std::make_pair(Value(3).asString(), Value(1)));
                
                //每组出现概率
                available_rate.insert(std::make_pair(Value(1).asString(), Value(40)));
                available_rate.insert(std::make_pair(Value(2).asString(), Value(30)));
                available_rate.insert(std::make_pair(Value(3).asString(), Value(30)));
                
                //每组的好坏：1-好，2-坏
                available_kind.insert(std::make_pair(Value(1).asString(), Value(1)));
                available_kind.insert(std::make_pair(Value(2).asString(), Value(2)));
                available_kind.insert(std::make_pair(Value(3).asString(), Value(2)));
                
                
                
            }

       
            
            
            
   
            
            
        }
            break;
        case 2:
        {
            time = 1000;
            bg_pic = "bg/bg1.png";
            fg_pic = "flower/f2.png";
            mc_pic = "mc/mc2.png";
            act_num = 4;
            game_moda = 1;
            
            
            area_num = 4;
            ball_num = 20;
            area_mode.insert(std::make_pair(Value(1).asString(), Value(1)));
            area_mode.insert(std::make_pair(Value(2).asString(), Value(1)));
            area_mode.insert(std::make_pair(Value(3).asString(), Value(1)));
            area_mode.insert(std::make_pair(Value(4).asString(), Value(1)));
            
            //多少秒到达，数字越小越快
            area_ball_speed.insert(std::make_pair(Value(1).asString(), Value(5)));
            area_ball_speed.insert(std::make_pair(Value(2).asString(), Value(5)));
            area_ball_speed.insert(std::make_pair(Value(3).asString(), Value(6)));
            area_ball_speed.insert(std::make_pair(Value(4).asString(), Value(5)));
            //每xx帧一个，数字越大间隔越大
            area_ball_gaptime.insert(std::make_pair(Value(1).asString(), Value(300)));
            area_ball_gaptime.insert(std::make_pair(Value(2).asString(), Value(300)));
            area_ball_gaptime.insert(std::make_pair(Value(3).asString(), Value(300)));
            area_ball_gaptime.insert(std::make_pair(Value(4).asString(), Value(300)));
            //起始位置
            area_ball_begin_x.insert(std::make_pair(Value(1).asString(), Value(200)));
            area_ball_begin_y.insert(std::make_pair(Value(1).asString(), Value(1920)));
            area_ball_end_x.insert(std::make_pair(Value(1).asString(), Value(200)));
            area_ball_end_y.insert(std::make_pair(Value(1).asString(), Value(800)));
            
            area_ball_begin_x.insert(std::make_pair(Value(2).asString(), Value(450)));
            area_ball_begin_y.insert(std::make_pair(Value(2).asString(), Value(1920)));
            area_ball_end_x.insert(std::make_pair(Value(2).asString(), Value(450)));
            area_ball_end_y.insert(std::make_pair(Value(2).asString(), Value(800)));
            
            area_ball_begin_x.insert(std::make_pair(Value(3).asString(), Value(700)));
            area_ball_begin_y.insert(std::make_pair(Value(3).asString(), Value(1920)));
            area_ball_end_x.insert(std::make_pair(Value(3).asString(), Value(700)));
            area_ball_end_y.insert(std::make_pair(Value(3).asString(), Value(800)));
            
            area_ball_begin_x.insert(std::make_pair(Value(4).asString(), Value(950)));
            area_ball_begin_y.insert(std::make_pair(Value(4).asString(), Value(1920)));
            area_ball_end_x.insert(std::make_pair(Value(4).asString(), Value(950)));
            area_ball_end_y.insert(std::make_pair(Value(4).asString(), Value(800)));
            
            //本关有几组可以选择
            available_team = 3;
            
            //每组共多少球可选(或多少颜色)
            available_num.insert(std::make_pair(Value(1).asString(), Value(6)));
            available_num.insert(std::make_pair(Value(2).asString(), Value(7)));
            available_num.insert(std::make_pair(Value(3).asString(), Value(13)));
            //available_num.insert(std::make_pair(Value(1).asString(), Value(6)));
            //available_num.insert(std::make_pair(Value(2).asString(), Value(4)));
            //available_num.insert(std::make_pair(Value(3).asString(), Value(1)));
            
            //每组出现概率
            available_rate.insert(std::make_pair(Value(1).asString(), Value(40)));
            available_rate.insert(std::make_pair(Value(2).asString(), Value(30)));
            available_rate.insert(std::make_pair(Value(3).asString(), Value(30)));
            
            //每组的好坏：1-好，2-坏
            available_kind.insert(std::make_pair(Value(1).asString(), Value(1)));
            available_kind.insert(std::make_pair(Value(2).asString(), Value(2)));
            available_kind.insert(std::make_pair(Value(3).asString(), Value(2)));
            
            //可选择的颜色数组初始化
            color_available_team_num = 2;
            color_available_team_color_num = 13;
            
            color_choose = 6;
            
            //中间有几个色块
            points_num = 6;
            
            
            color_available_1_r.insert(std::make_pair(Value(1).asString(), Value(0)));
            color_available_1_r.insert(std::make_pair(Value(2).asString(), Value(1)));
            color_available_1_r.insert(std::make_pair(Value(3).asString(), Value(1)));
            color_available_1_r.insert(std::make_pair(Value(4).asString(), Value(0)));
            color_available_1_r.insert(std::make_pair(Value(5).asString(), Value(1)));
            color_available_1_r.insert(std::make_pair(Value(6).asString(), Value(0)));
            color_available_1_r.insert(std::make_pair(Value(7).asString(), Value(0)));
            color_available_1_r.insert(std::make_pair(Value(8).asString(), Value(0.5)));
            color_available_1_r.insert(std::make_pair(Value(9).asString(), Value(0.5)));
            color_available_1_r.insert(std::make_pair(Value(10).asString(), Value(0)));
            color_available_1_r.insert(std::make_pair(Value(11).asString(), Value(0)));
            color_available_1_r.insert(std::make_pair(Value(12).asString(), Value(0.5)));
            color_available_1_r.insert(std::make_pair(Value(13).asString(), Value(0)));
            
            color_available_2_r.insert(std::make_pair(Value(1).asString(), Value(0.25)));
            color_available_2_r.insert(std::make_pair(Value(2).asString(), Value(0.75)));
            color_available_2_r.insert(std::make_pair(Value(3).asString(), Value(0.75)));
            color_available_2_r.insert(std::make_pair(Value(4).asString(), Value(0.25)));
            color_available_2_r.insert(std::make_pair(Value(5).asString(), Value(0.75)));
            color_available_2_r.insert(std::make_pair(Value(6).asString(), Value(0.25)));
            color_available_2_r.insert(std::make_pair(Value(7).asString(), Value(0.25)));
            color_available_2_r.insert(std::make_pair(Value(8).asString(), Value(0.75)));
            color_available_2_r.insert(std::make_pair(Value(9).asString(), Value(0.75)));
            color_available_2_r.insert(std::make_pair(Value(10).asString(), Value(0.25)));
            color_available_2_r.insert(std::make_pair(Value(11).asString(), Value(0.25)));
            color_available_2_r.insert(std::make_pair(Value(12).asString(), Value(0.75)));
            color_available_2_r.insert(std::make_pair(Value(13).asString(), Value(0.25)));
            
            
            color_available_1_g.insert(std::make_pair(Value(1).asString(), Value(1)));
            color_available_1_g.insert(std::make_pair(Value(2).asString(), Value(1)));
            color_available_1_g.insert(std::make_pair(Value(3).asString(), Value(0)));
            color_available_1_g.insert(std::make_pair(Value(4).asString(), Value(0)));
            color_available_1_g.insert(std::make_pair(Value(5).asString(), Value(0)));
            color_available_1_g.insert(std::make_pair(Value(6).asString(), Value(1)));
            color_available_1_g.insert(std::make_pair(Value(7).asString(), Value(0.5)));
            color_available_1_g.insert(std::make_pair(Value(8).asString(), Value(0)));
            color_available_1_g.insert(std::make_pair(Value(9).asString(), Value(0.5)));
            color_available_1_g.insert(std::make_pair(Value(10).asString(), Value(0)));
            color_available_1_g.insert(std::make_pair(Value(11).asString(), Value(0.5)));
            color_available_1_g.insert(std::make_pair(Value(12).asString(), Value(0)));
            color_available_1_g.insert(std::make_pair(Value(13).asString(), Value(0)));
            
            color_available_2_g.insert(std::make_pair(Value(1).asString(), Value(1)));
            color_available_2_g.insert(std::make_pair(Value(2).asString(), Value(1)));
            color_available_2_g.insert(std::make_pair(Value(3).asString(), Value(0)));
            color_available_2_g.insert(std::make_pair(Value(4).asString(), Value(0)));
            color_available_2_g.insert(std::make_pair(Value(5).asString(), Value(0)));
            color_available_2_g.insert(std::make_pair(Value(6).asString(), Value(1)));
            color_available_2_g.insert(std::make_pair(Value(7).asString(), Value(0.5)));
            color_available_2_g.insert(std::make_pair(Value(8).asString(), Value(0)));
            color_available_2_g.insert(std::make_pair(Value(9).asString(), Value(0.5)));
            color_available_2_g.insert(std::make_pair(Value(10).asString(), Value(0)));
            color_available_2_g.insert(std::make_pair(Value(11).asString(), Value(0.5)));
            color_available_2_g.insert(std::make_pair(Value(12).asString(), Value(0)));
            color_available_2_g.insert(std::make_pair(Value(13).asString(), Value(0)));
            
            color_available_1_b.insert(std::make_pair(Value(1).asString(), Value(0)));
            color_available_1_b.insert(std::make_pair(Value(2).asString(), Value(0)));
            color_available_1_b.insert(std::make_pair(Value(3).asString(), Value(0)));
            color_available_1_b.insert(std::make_pair(Value(4).asString(), Value(1)));
            color_available_1_b.insert(std::make_pair(Value(5).asString(), Value(1)));
            color_available_1_b.insert(std::make_pair(Value(6).asString(), Value(1)));
            color_available_1_b.insert(std::make_pair(Value(7).asString(), Value(0.5)));
            color_available_1_b.insert(std::make_pair(Value(8).asString(), Value(0.5)));
            color_available_1_b.insert(std::make_pair(Value(9).asString(), Value(0)));
            color_available_1_b.insert(std::make_pair(Value(10).asString(), Value(0.5)));
            color_available_1_b.insert(std::make_pair(Value(11).asString(), Value(0)));
            color_available_1_b.insert(std::make_pair(Value(12).asString(), Value(0)));
            color_available_1_b.insert(std::make_pair(Value(13).asString(), Value(0)));
            
            color_available_2_b.insert(std::make_pair(Value(1).asString(), Value(0)));
            color_available_2_b.insert(std::make_pair(Value(2).asString(), Value(0)));
            color_available_2_b.insert(std::make_pair(Value(3).asString(), Value(0)));
            color_available_2_b.insert(std::make_pair(Value(4).asString(), Value(1)));
            color_available_2_b.insert(std::make_pair(Value(5).asString(), Value(1)));
            color_available_2_b.insert(std::make_pair(Value(6).asString(), Value(1)));
            color_available_2_b.insert(std::make_pair(Value(7).asString(), Value(0.5)));
            color_available_2_b.insert(std::make_pair(Value(8).asString(), Value(0.5)));
            color_available_2_b.insert(std::make_pair(Value(9).asString(), Value(0)));
            color_available_2_b.insert(std::make_pair(Value(10).asString(), Value(0.5)));
            color_available_2_b.insert(std::make_pair(Value(11).asString(), Value(0)));
            color_available_2_b.insert(std::make_pair(Value(12).asString(), Value(0)));
            color_available_2_b.insert(std::make_pair(Value(13).asString(), Value(0)));
            
            color_available_1_a.insert(std::make_pair(Value(1).asString(), Value(1)));
            color_available_1_a.insert(std::make_pair(Value(2).asString(), Value(1)));
            color_available_1_a.insert(std::make_pair(Value(3).asString(), Value(1)));
            color_available_1_a.insert(std::make_pair(Value(4).asString(), Value(1)));
            color_available_1_a.insert(std::make_pair(Value(5).asString(), Value(1)));
            color_available_1_a.insert(std::make_pair(Value(6).asString(), Value(1)));
            color_available_1_a.insert(std::make_pair(Value(7).asString(), Value(1)));
            color_available_1_a.insert(std::make_pair(Value(8).asString(), Value(1)));
            color_available_1_a.insert(std::make_pair(Value(9).asString(), Value(1)));
            color_available_1_a.insert(std::make_pair(Value(10).asString(), Value(1)));
            color_available_1_a.insert(std::make_pair(Value(11).asString(), Value(1)));
            color_available_1_a.insert(std::make_pair(Value(12).asString(), Value(1)));
            color_available_1_a.insert(std::make_pair(Value(13).asString(), Value(1)));
            
            color_available_2_a.insert(std::make_pair(Value(1).asString(), Value(1)));
            color_available_2_a.insert(std::make_pair(Value(2).asString(), Value(1)));
            color_available_2_a.insert(std::make_pair(Value(3).asString(), Value(1)));
            color_available_2_a.insert(std::make_pair(Value(4).asString(), Value(1)));
            color_available_2_a.insert(std::make_pair(Value(5).asString(), Value(1)));
            color_available_2_a.insert(std::make_pair(Value(6).asString(), Value(1)));
            color_available_2_a.insert(std::make_pair(Value(7).asString(), Value(1)));
            color_available_2_a.insert(std::make_pair(Value(8).asString(), Value(1)));
            color_available_2_a.insert(std::make_pair(Value(9).asString(), Value(1)));
            color_available_2_a.insert(std::make_pair(Value(10).asString(), Value(1)));
            color_available_2_a.insert(std::make_pair(Value(11).asString(), Value(1)));
            color_available_2_a.insert(std::make_pair(Value(12).asString(), Value(1)));
            color_available_2_a.insert(std::make_pair(Value(13).asString(), Value(1)));
           
            
            
            
        }
            break;
        case 3:
        {
            
            
            
        }
            break;
        case 4:
        {
            
            
            
        }
            break;
        case 5:
        {
            
            
            
        }
            break;
            
    }
}












