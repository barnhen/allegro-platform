#include "ScreenManager.h"



//building this because when deallocating it it will be destroyed for us
ScreenManager &ScreenManager::GetInstance()
{
	static ScreenManager instance;
	return instance;
}

ScreenManager::ScreenManager()
{
}


ScreenManager::~ScreenManager() // this is the destructor because of this ~ sign
{
}

void ScreenManager::Initialize()
{
	currentScreen = new SplashScreen();
}

void ScreenManager::AddScreen(GameScreen *screen)
{
	transition.SetAlpha(0);
	startTransition = true;
	newScreen = screen;
	transition.SetIsActive(true);
	
}

void ScreenManager::LoadContent()
{
	currentScreen->LoadContent();
	transitionImage = al_load_bitmap("transitionImage.png");
	float position[2] = {0,0};
	transition.LoadContent(transitionImage, "", position);
	startTransition = false;
}

void ScreenManager::UnloadContent()
{
	al_destroy_bitmap(transitionImage);
	transition.UnloadContent();
}

void ScreenManager::Update(ALLEGRO_EVENT ev)
{
	if(!startTransition)
		currentScreen->Update(ev);
	else
		Transition();
}

void ScreenManager::Draw(ALLEGRO_DISPLAY *display)
{

	currentScreen-> Draw(display);
	if(startTransition)
	{
		transition.Draw(display);
		//std::stringstream str;
		//str<<transition.GetAlpha();
		//al_draw_text(transition.GetFont(), al_map_rgb(255,0,0),10,10,NULL,str.
	}
}

void ScreenManager::Transition()
{
	transition.Update(currentScreen->GetInput());
	if(transition.GetAlpha() >= 255)
	{
		transition.SetAlpha(255);
		currentScreen->UnloadContent();
		delete currentScreen;
		currentScreen = newScreen;
		currentScreen->LoadContent();
		al_rest(1.0);
	}
	else if(transition.GetAlpha() <=0)
	{
		startTransition = false;
		transition.SetIsActive(false);

	}
	if(transition.GetIncrease() == false)
		al_rest(0.5f);
}