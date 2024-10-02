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
	}
	void GameplayController::Render()
	{
	}
	void GameplayController::Reset()
	{
		ServiceLocator::getInstance()->GetBoardService()->ResetBoard();
	}
}