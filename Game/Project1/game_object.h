#pragma once
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <string>
#include "Input.h"
#include "assets.h"
#include "Vector_2D.h"
#include "Configuration.h"
#include "Circle_2D.h"
#include "Scene.h"


class game_object
{
public :
	game_object(std::string id, std::string texture_id);
	~game_object();

	std::string id();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) = 0;
	virtual void simulate_physics(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene);
	virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene);

	Vector_2D translation();
	Circle_2D collider();


	int height();
	int width();

	void set_translation(Vector_2D translation);

protected:
	std::string _id;
	std::string _texture_id;

	//float _x;
	//float _y;

	Circle_2D _collider;

	Vector_2D _translation;
	Vector_2D _velocity;



	int _width;
	int _height;

	SDL_RendererFlip _flip;

};

