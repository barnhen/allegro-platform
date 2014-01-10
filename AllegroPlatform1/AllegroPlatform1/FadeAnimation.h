#pragma once
#include "Animation.h"

class FadeAnimation : public Animation
{
public:
	FadeAnimation(void);
	~FadeAnimation(void);

	void LoadContent(ALLEGRO_BITMAP *image, std::string text, float position[2]);
	void UnloadContent();
	void Update(InputManager input);

	void SetAlpha(int value);
	bool GetIncrease();


private:
	float fadeSpeed;
	bool increase;
};

