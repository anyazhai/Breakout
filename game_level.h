#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include <vector>

#include "game_object.h"


class GameLevel {
	public:
		//level state
		//vector here can be considered as a scalable array. 
		//Syntax: vector<type> var-name; ex: vector<int> a;
		std::vector<GameObject> Bricks;

		//constructor
		GameLevel() {  }

		//load level from text file
		void Load(const char* file, unsigned int levelWidth, unsigned int levelHeight);
		// render level
		void Draw(SpriteRenderer& renderer);
		// check if the level is completed (all non-solid tiles are destroyed)
		bool IsCompleted();

	private:
		//initialise level
		void init(std::vector<std::vector<unsigned int>> tileData,
			unsigned int levelWidth, unsigned int levelHeight);
};

#endif
