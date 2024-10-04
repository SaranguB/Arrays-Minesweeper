#pragma once

namespace Gameplay
{
	enum class GameResult
	{
		NONE,
		WON,
		LOST
	};

	class GameplayController
	{
	private:
		float maxDuration = 60.f;
		float remainingTime;
		const float gameOverTime = 11.f;

		GameResult gameResult = GameResult::NONE;

	public:
		GameplayController();
		~GameplayController();

		void Initialize();
		void Update();
		void Render();
		void Reset();

		void UpdateRemainingTime();

		float GetRemainingTime();

		int GetMineCount();

		void EndGame(GameResult result);

		void GameWon();
		void GameLost();

		void BeginGameOverTimer();
		void ShowCredits();
	};

}