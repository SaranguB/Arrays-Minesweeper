#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Gameplay
{
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
}