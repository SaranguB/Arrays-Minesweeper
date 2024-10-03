#include "../../header/UI/GameplayUI/GameplayUIController.h"
#include "../../header/Global/ServiceLocator.h"
#include <sstream>
#include <iomanip>

namespace UI
{
	namespace GameplayUI
	{
		using namespace UIElement;
		using namespace Global;

		GameplayUIController::GameplayUIController()
		{
			createTexts();
		}

		void GameplayUIController::createTexts()
		{
			time_text = new TextView();
		}

		GameplayUIController::~GameplayUIController()
		{
			destroy();
		}

		void GameplayUIController::initialize()
		{
			initializeTexts();
		}
		void GameplayUIController::update()
		{
			updateTimeText();
		}

		void GameplayUIController::render()
		{
			time_text->render();
		}

		void GameplayUIController::show()
		{
			time_text->show();
		}

		void GameplayUIController::createButton()
		{
		}
		
		void GameplayUIController::initializeButton()
		{
		}
		void GameplayUIController::initializeTexts()
		{
			initializeTimeText();
		}
		void GameplayUIController::initializeMineText()
		{
		}
		void GameplayUIController::initializeTimeText()
		{
			time_text->initialize("000", sf::Vector2f(time_text_left_offset, time_text_top_offset), FontType::ROBOTO, font_size, text_color);
		}
		void GameplayUIController::updateMineText()
		{
		}

		void GameplayUIController::updateTimeText()
		{
			int remaining_time = ServiceLocator::getInstance()->GetGameplayService()->GetRemainingTime();

			std::stringstream stream;
			stream << std::setw(3) << std::setfill('0') << remaining_time;
			std::string string_remaining_time = stream.str();

			time_text->setText(string_remaining_time);
			time_text->update();
		}
		void GameplayUIController::restartButtonCallback()
		{
		}
		void GameplayUIController::registerButtonCallback()
		{
		}
		void GameplayUIController::destroy()
		{
			delete(time_text);
		}
	}
}