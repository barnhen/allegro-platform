#pragma once

#include<allegro5\allegro.h>
#include<allegro5\keyboard.h>
#include<vector>

class InputManager
{
private:
	ALLEGRO_KEYBOARD_STATE keyState;
public:
	InputManager(void); //constructor
	~InputManager(void);//destructor

	boolean IsKeyPressed(ALLEGRO_EVENT ev, int key);
	boolean IsKeyPressed(ALLEGRO_EVENT ev, std::vector<int> keys);

	boolean IsKeyReleased(ALLEGRO_EVENT ev,int key);
	boolean IsKeyReleased(ALLEGRO_EVENT ev, std::vector<int> keys);
};

