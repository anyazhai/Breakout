#ifndef BALL_OBJECT_H
#define BALL_OBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "game_object.h"
#include "texture.h"


//holds the state of the ball
class BallObject : public GameObject {
	public:
		//ball state
		float Radius;
		float Stuck;

		BallObject();
		BallObject(glm::vec2 pos, float radius, glm::vec2 velocity, Texture2D sprite);
		glm::vec2 Move(float dt, unsigned int window_width);
		void Reset(glm::vec2 position, glm::vec2 velocity);
};

#endif