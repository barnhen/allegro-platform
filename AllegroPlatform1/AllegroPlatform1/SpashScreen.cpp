#include "SplashScreen.h"
#include "GameScreen.h"




SplashScreen::SplashScreen()
{
}


SplashScreen::~SplashScreen()
{
}

void SplashScreen::LoadContent()
{
	font = al_load_font("arial.ttf", 30, NULL);
	//FileManager.LoadContent("Load/Splash.cme",attributes, contents );
	FileManager.LoadContent("File.txt",attributes,contents);
}

void SplashScreen::UnloadContent()
{
	al_destroy_font(font);
}

void SplashScreen::Update(ALLEGRO_EVENT ev)
{
	if(input.IsKeyPressed(ev, ALLEGRO_KEY_ENTER))
		ScreenManager::GetInstance().AddScreen(new TitleScreen);
}

void SplashScreen::Draw(ALLEGRO_DISPLAY *display)
{
	al_draw_text(font, al_map_rgb(0,0,255),100,100,NULL, 
					"SplashScreen");
}

