#ifndef _Music_H_
#define _Music_H_

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;

class Music
{
public :
	//static bool onSound;
	//static bool onEffect;
	//static bool noPlaySound;
	static void loadMusic();//加载背景音乐

	static void resumeBackgroundMusic();//继续背景音乐
	static void pauseBackgroundMusic();//暂停背景音乐
    static void stopBackgroundMusic();

	static void playExplosionEffect();//爆炸时的音效
	static void chooseupEffect();//进入关卡时的音效
	static void choosedownEffect();//暂停菜单中点击菜单时的音效
    static void choosewrongEffect();
    static void eatEffect();
    static void timeEffect();
    


	static void playGameLayerMusic();//gameLayer的背景音乐
	static void playFlyLayerMusic();//FlyLayer的背景音乐
	static void playMenuLayerMusic();//菜单背景音乐

};

#endif
