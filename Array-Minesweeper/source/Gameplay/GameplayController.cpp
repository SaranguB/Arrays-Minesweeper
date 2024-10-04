#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"
#include "../../header/Gameplay/Board/BoardController.h"

namespace Gameplay
{
	using namespace Main;
	using namespace Global;

	GameplayController::GameplayController()
	{
	}
	GameplayController::~GameplayController()
	{
	}
	void GameplayController::Initialize()
	{
	}
	void GameplayController::Update()
	{
		UpdateRemainingTime();
	}
	void GameplayController::Render()
	{
	}
	void GameplayController::Reset()
	{
		ServiceLocator::getInstance()->GetBoardService()->ResetBoard();
		remainingTime = maxDuration;
	}
	void GameplayController::UpdateRemainingTime()
	{
		remainingTime -= ServiceLocator::getInstance()->GetTimeService()->getDeltaTime();
	}
	float GameplayController::GetRemainingTime()
	{
		return remainingTime;
	}
	int GameplayController::GetMineCount()
	{
		return ServiceLocator::getInstance()->GetBoardService()->GetMineCount();;
	}
	void GameplayController::EndGame(GameResult result)
	{
		switch (result)
		{
		case GameResult::WON:
			GameWon();
			break;

		case GameResult::LOST:
			GameLost();
			break;
		}
	}
	void GameplayController::GameWon()
	{

	}
	void GameplayController::GameLost()
	{
		if (gameResult == GameResult::NONE)
		{
			gameResult = GameResult::LOST;
			BeginGameOverTimer();
			ServiceLocator::getInstance()->GetBoardService()->ShowBoard();
			ServiceLocator::getInstance()->GetBoardService()->SetBoardState(Board::BoardState::COMPLETED);

		}
		else
		{
			ShowCredits();
		}

	}
	void GameplayController::BeginGameOverTimer()
	{
		remainingTime = gameOverTime;
	}
	void GameplayController::ShowCredits()
	{
		GameService::setGameState(GameState::CREDITS);
	}
}