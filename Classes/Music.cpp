#include "Music.h"

//bool Music::onSound = true;
//bool Music::onEffect = true;
//bool Music::noPlaySound = false;

void Music::loadMusic()
{
	//onEffect = UserDefault::getInstance()->getBoolForKey("5",true);
	//onSound = UserDefault::getInstance()->getBoolForKey("6",true);
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(
							"music1.mp3"					//º”‘ÿ±≥æ∞“Ù¿÷
						);
    
    /*
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(
							"menuLoop.mp3"					//º”‘ÿ±≥æ∞“Ù¿÷
						);
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(
							"CantLetGo.mp3"					//º”‘ÿ±≥æ∞“Ù¿÷
						);
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(				//º”‘ÿ“Ù–ß
				"explode_11.mp3"
			);
     
     */
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
				"playSound_01.mp3"
			);
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
				"quitSound_01.mp3"
			);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
                                                                   "time.mp3"
                                                                   );
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
                                                                   "eat.wave"
                                                                   );
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
                                                                   "lose.mp3"
                                                                   );
     

}

void Music::playGameLayerMusic()
{
    if(UserDefault::getInstance()->getBoolForKey("onMusic"))
    {
       
        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic
        (
         "music1.mp3",
         true
         );

    }
    
    return;
    
}

void Music::stopBackgroundMusic()
{
    //onSound = true;
    //UserDefault::getInstance()->setBoolForKey("onMusic",true);
    //UserDefault::getInstance()->flush();
    //ºÃ–¯±≥æ∞“Ù¿÷
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    return;
}

void Music::resumeBackgroundMusic()//ºÃ–¯±≥æ∞“Ù¿÷
{
	//onSound = true;
	//UserDefault::getInstance()->setBoolForKey("onMusic",true);
	//UserDefault::getInstance()->flush();
	//ºÃ–¯±≥æ∞“Ù¿÷
    if(UserDefault::getInstance()->getBoolForKey("onMusic"))
    {
	CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    }
	return;
}
void Music::pauseBackgroundMusic()//‘›Õ£±≥æ∞“Ù¿÷
{
	//onSound = false;
	//UserDefault::getInstance()->setBoolForKey("onMusic",false);
	//UserDefault::getInstance()->flush();
	//‘›Õ£±≥æ∞“Ù¿÷
    if(UserDefault::getInstance()->getBoolForKey("onMusic"))
    {
	CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    }
	return;
}


/*
void Music::playExplosionEffect()//“Ù–ß
{
	if(onEffect == false)
	{
		return;
	}
	//‘›Õ£±≥æ∞“Ù¿÷
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("explode_11.mp3");	//≤•∑≈“Ù–ß
	return;
}
 
 
*/

void Music::chooseupEffect()//Ω¯»Îπÿø® ±µƒ“Ù–ß
{
    
    if(UserDefault::getInstance()->getBoolForKey("onMusic"))
    {
        
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("playSound_01.mp3");
        
    }
   
	return;
}


void Music::choosedownEffect()//‘›Õ£≤Àµ•÷–µ„ª˜≤Àµ• ±µƒ“Ù–ß
{
    if(UserDefault::getInstance()->getBoolForKey("onMusic"))
    {
        
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("quitSound_01.mp3");
    }
    

	return;
}

void Music::choosewrongEffect()//‘›Õ£≤Àµ•÷–µ„ª˜≤Àµ• ±µƒ“Ù–ß
{
    if(UserDefault::getInstance()->getBoolForKey("onMusic"))
    {
        
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("lose.mp3");
    }
    
    
    return;
}

void Music::timeEffect()//‘›Õ£≤Àµ•÷–µ„ª˜≤Àµ• ±µƒ“Ù–ß
{
    if(UserDefault::getInstance()->getBoolForKey("onMusic"))
    {
        
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("time.mp3");
    }
    
    
    return;
}

void Music::eatEffect()//‘›Õ£≤Àµ•÷–µ„ª˜≤Àµ• ±µƒ“Ù–ß
{
    if(UserDefault::getInstance()->getBoolForKey("onMusic"))
    {
        
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("eat.wav");
    }
    
    
    return;
}

/*
void Music::playMenuLayerMusic()//≤Àµ•±≥æ∞“Ù¿÷
{
	if(onSound == false)
	{
		return;
	}
	//≤•∑≈±≥æ∞“Ù¿÷
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic
	(
		"menuLoop.mp3",
		true
	);
	return;
}
void Music::playGameLayerMusic()
{
	if(onSound == false)
	{
		return;
	}
	//≤•∑≈±≥æ∞“Ù¿÷
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic
	(
		"BackOnTrack.mp3",
		true
	);
	return;

}
void Music::playFlyLayerMusic()//FlyLayerµƒ±≥æ∞“Ù¿÷
{
	if(onSound == false)
	{
		return;
	}
	//≤•∑≈±≥æ∞“Ù¿÷
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic
	(
		"CantLetGo.mp3",
		true
	);
	return;
}
 
 */
