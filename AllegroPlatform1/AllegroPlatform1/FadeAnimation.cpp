#include "FadeAnimation.h"


FadeAnimation::FadeAnimation(void)
{
}


FadeAnimation::~FadeAnimation(void)
{
}

void FadeAnimation::LoadContent(ALLEGRO_BITMAP *image, std::string text, float position[2])
{
	Animation::LoadContent(image, text, position);
	fadeSpeed = 5.0f;
	increase = false;

}

void FadeAnimation::UnloadContent()
{
	Animation::UnloadContent();
	fadeSpeed = NULL;
}

void FadeAnimation::Update(InputManager input)
{
	if(isActive)
	{
		if(!increase)
			alpha -= fadeSpeed;
		else
			alpha += fadeSpeed;

		if(alpha <= 0)
		{
			alpha=0;
			increase=true;
		}
		else if (alpha >= 255)
		{
			alpha = 255;
			increase = false;
		}
	}
	else
		alpha = 255;
}

void FadeAnimation::SetAlpha(int value)
{
	alpha = value;
	if(alpha ==0)
		increase = true;
	else if (alpha == 255)
		increase = false;
}

bool FadeAnimation::GetIncrease()
{
	return increase;
}