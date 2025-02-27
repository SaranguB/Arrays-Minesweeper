#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"


namespace Global
{
	using namespace Graphics;
	using namespace Event;
	using namespace Sound;
	using namespace UI;
	using namespace Gameplay::Board;
	using namespace Gameplay;
	using namespace Main;
	using namespace Time;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		sound_service = nullptr;
		ui_service = nullptr;
		boardService = nullptr;
		gameplayService = nullptr;
		timeService = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator() { clearAllServices(); }

	void ServiceLocator::createServices()
	{
		event_service = new EventService();
		graphic_service = new GraphicService();
		sound_service = new SoundService();
		timeService = new TimeService();
		ui_service = new UIService();
		boardService = new BoardService();
		gameplayService = new GameplayService();
		
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		sound_service->initialize();
		event_service->initialize();
		timeService->initialize();
		ui_service->initialize();
		boardService->Initialize();
		gameplayService->Initialize();
	}

	void ServiceLocator::update()
	{
		event_service->update();
		timeService->update();
		graphic_service->update();

		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplayService->Update();
			boardService->Update();
		}
		ui_service->update();

	}

	void ServiceLocator::render()
	{
		graphic_service->render();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplayService->Render();
			boardService->Render();
		}
		ui_service->render();

	}

	void ServiceLocator::clearAllServices()
	{
		delete(ui_service);
		delete(graphic_service);
		delete(sound_service);
		delete(event_service);
		delete(boardService);
		delete(gameplayService);
		delete(timeService);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	EventService* ServiceLocator::getEventService() { return event_service; }

	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }

	SoundService* ServiceLocator::getSoundService() { return sound_service; }

	UIService* ServiceLocator::getUIService() { return ui_service; }

	Gameplay::Board::BoardService* ServiceLocator::GetBoardService()
	{
		return boardService;
	}

	Gameplay::GameplayService* ServiceLocator::GetGameplayService()
	{
		return gameplayService;
	}

	Time::TimeService* ServiceLocator::GetTimeService()
	{
		return timeService;
	}

	void ServiceLocator::deleteServiceLocator() { delete(this); }
}