#pragma once
#include<iostream>
#include<string>
#include "GameScreen.h"
#include "SplashScreen.h"
#include "TitleScreen.h"
#include "FadeAnimation.h"

//Allegro Init - to decide if put it on GLOBALS.h
#include<allegro5\allegro.h>
#include<allegro5\allegro_image.h>

#define ScreenWidth 800
#define ScreenHeight 600

class ScreenManager
{
private:
	ScreenManager();
	ScreenManager(ScreenManager const&);//override copy of constructor
	void operator=(ScreenManager const&);

	std::string text;
	GameScreen *currentScreen, *newScreen;;

	ALLEGRO_BITMAP *transitionImage;

	FadeAnimation transition;

	void Transition();

	bool startTransition;

public:
	~ScreenManager(); // this is the destructor because of this ~ sign
	static  ScreenManager &GetInstance();

	void AddScreen(GameScreen *screen);
	void Initialize();
	void LoadContent();
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);




};

