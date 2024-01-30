#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Global/TimeService.h"
#include "../../header/Global/ServiceLocator.h"

namespace Gameplay
{
    using namespace Board;
    using namespace Global;

    GameplayController::GameplayController() {}

    GameplayController::~GameplayController() {  }

    void GameplayController::initialize() {  }

    void GameplayController::update()
    {
        updateRemainingTime();
    }

    void GameplayController::render() {  }

    void GameplayController::updateRemainingTime() { remaining_time -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime(); }

    void GameplayController::restart() 
    { 
        ServiceLocator::getInstance()->getBoardService()->resetBoard();
        remaining_time = max_level_duration;
    }

    int GameplayController::getMinesCount() { return BoardController::mines_count; }

    float GameplayController::getRemainingTime() { return remaining_time; }
}