#pragma once
#include "GameplayController.h"

namespace Gameplay
{
	class GameplayController;
	class GameplayService
	{
	private:
		GameplayController* gameplayController;

	public:
		GameplayService();
		~GameplayService();

		void Initialize();
		void Update();
		void Render();
		void StartGame();

		float GetRemainingTime();

		int GetMineCount();

		void EndGame(GameResult result);
	};

}