#pragma once

#include<allegro5\allegro.h>
#include<allegro5\allegro_image.h>
#include<allegro5\allegro_font.h>
#include<string>
#include"InputManager.h"

class Animation
{
public:
	Animation(void); //constructor
	~Animation(void); // destructor

	virtual void LoadContent(ALLEGRO_BITMAP *image, std::string text, float position[2]);
	virtual void UnloadContent();
	virtual void Update(InputManager input);
	void Draw(ALLEGRO_DISPLAY *display);

	virtual void SetAlpha(float value);
	float GetAlpha();

	void SetIsActive(bool value);
	bool GetIsActive();

protected:
	ALLEGRO_BITMAP *image, * sourceRect; //source Rectangle
	std::string text;
	ALLEGRO_FONT *font;
	float position[2]; //x and y
	float alpha;
	bool isActive;

};

