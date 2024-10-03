#include "../../header/UI/GameplayUI/GameplayUIController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include <sstream>
#include <iomanip>
#include "../../header/Sound/SoundService.h"

namespace UI
{
	namespace GameplayUI
	{
		using namespace UIElement;
		using namespace Global;

		GameplayUIController::GameplayUIController()
		{
			createButton();
			createTexts();
		}

		void GameplayUIController::createTexts()
		{
			time_text = new TextView();
			mine_text = new TextView();
		}

		void GameplayUIController::createButton()
		{
			restart_button = new ButtonView();
		}

		GameplayUIController::~GameplayUIController()
		{
			destroy();
		}

		void GameplayUIController::initialize()
		{
			initializeButton();
			initializeTexts();
		}

		void GameplayUIController::initializeTexts()
		{
			initializeTimeText();
			initializeMineText();
		}

		void GameplayUIController::update()
		{
			restart_button->update();
			updateTimeText();
			updateMineText();
		}

		void GameplayUIController::render()
		{
			//printf("render");
			restart_button->render();
			time_text->render();
			mine_text->render();
		}

		void GameplayUIController::show()
		{
			restart_button->show();
			mine_text->show();
			time_text->show();
		}



		void GameplayUIController::initializeButton()
		{
			restart_button->initialize("Restart Button",
				Config::restart_button_texture_path,
				button_width, button_height,
				sf::Vector2f(restart_button_left_offset, restart_button_top_offset));

			registerButtonCallback();
		}

		void GameplayUIController::initializeMineText()
		{
			mine_text->initialize("000", sf::Vector2f(mine_text_left_offset, mine_text_top_offset),
				FontType::ROBOTO, font_size, text_color);
		}

		void GameplayUIController::initializeTimeText()
		{
			time_text->initialize("000", sf::Vector2f(time_text_left_offset, time_text_top_offset),
				FontType::ROBOTO, font_size, text_color);
		}

		void GameplayUIController::updateMineText()
		{
			int mines_count = ServiceLocator::getInstance()->GetGameplayService()->GetMineCount();

			std::stringstream stream;
			stream << std::setw(3) << std::setfill('0') << mines_count;
			std::string string_mine_count = stream.str();

			mine_text->setText(string_mine_count);
			mine_text->update();

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
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			ServiceLocator::getInstance()->GetGameplayService()->StartGame();
		}
		void GameplayUIController::registerButtonCallback()
		{
			restart_button->registerCallbackFuntion(std::bind(&GameplayUIController::restartButtonCallback, this));
		}
		void GameplayUIController::destroy()
		{
			delete(time_text);
			delete(mine_text);
			delete(restart_button);
		}
	}
}