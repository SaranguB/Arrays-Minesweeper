#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Gameplay/GameplayController.h"

namespace Gameplay
{
	GameplayService::GameplayService()
	{
		gameplayController = new GameplayController();
	}
	GameplayService::~GameplayService()
	{
		delete(gameplayController);
	}
	void GameplayService::Initialize()
	{
		gameplayController->Initialize();
	}
	void GameplayService::Update()
	{
		gameplayController->Update();
	}
	void GameplayService::Render()
	{
		gameplayController->Render();
	}

	void GameplayService::StartGame()
	{
		gameplayController->Reset();
	}

	float GameplayService::GetRemainingTime()
	{
		return gameplayController->GetRemainingTime();
	}

	int GameplayService::GetMineCount()
	{
		return gameplayController->GetMineCount();;
	}
	
}