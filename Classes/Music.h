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
	static void loadMusic();//���ر�������

	static void resumeBackgroundMusic();//������������
	static void pauseBackgroundMusic();//��ͣ��������
    static void stopBackgroundMusic();

	static void playExplosionEffect();//��ըʱ����Ч
	static void chooseupEffect();//����ؿ�ʱ����Ч
	static void choosedownEffect();//��ͣ�˵��е���˵�ʱ����Ч
    static void choosewrongEffect();
    static void eatEffect();
    static void timeEffect();
    


	static void playGameLayerMusic();//gameLayer�ı�������
	static void playFlyLayerMusic();//FlyLayer�ı�������
	static void playMenuLayerMusic();//�˵���������

};

#endif
