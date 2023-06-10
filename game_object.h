#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "texture.h"
#include "sprite_renderer.h"

//to render each of the objects that are included in the game
class GameObject {
	public:
		glm::vec2 Position, Size, Velocity;
		glm::vec3 Color;
		float Rotation; //the brick is desstroyable or not
		bool IsSolid;
		bool Destroyed;
		
		//render statre
		Texture2D Sprite;
		
		//constrcutor
		GameObject(); 
		GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color = glm::vec3(1.0f), glm::vec2 velocity = glm::vec2(0.0f, 0.0f));
		// draw sprite
		virtual void Draw(SpriteRenderer& renderer);

};

#endif
