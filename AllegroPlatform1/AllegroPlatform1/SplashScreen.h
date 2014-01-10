#pragma once

#include "ScreenManager.h"
#include "InputManager.h"
#include "TitleScreen.h"
#include "FileManager.h"
#include<allegro5\allegro_font.h>
#include<allegro5\allegro_ttf.h>


class SplashScreen : public GameScreen
{
private:
	ALLEGRO_FONT *font;

	FileManager FileManager;
public:
	SplashScreen(void); //constructor
	~SplashScreen(void); //destructor

	void LoadContent();
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
};

