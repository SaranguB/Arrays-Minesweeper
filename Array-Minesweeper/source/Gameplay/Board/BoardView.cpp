#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace UI::UIElement;
		using namespace Global;

		BoardView::BoardView(BoardController* controller)
		{
			boardController = controller;
			backgroundImage = new ImageView();
			boardImage = new ImageView();
		}
		BoardView::~BoardView()
		{
			delete(boardController);
			delete(boardImage);
		}
		void BoardView::Initialize()
		{
			InitializeBackgroundImage();
			InitializeBoardImage();
		}

		void BoardView::InitializeBackgroundImage()
		{
			gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			backgroundImage->initialize(Config::background_texture_path, gameWindow->getSize().x,
				gameWindow->getSize().y, sf::Vector2f(0, 0));
			backgroundImage->setImageAlpha(backgroundAlpha);
		}

		void BoardView::InitializeBoardImage()
		{
			boardImage->initialize(Config::board_texture_path, boardWidth, boardHeight, sf::Vector2f(0, 0));
			boardImage->setCentreAlinged();
		}

		void BoardView::Update()
		{
			backgroundImage->update();
			boardImage->update();
		}
		void BoardView::Render()
		{
			backgroundImage->render();
			boardImage->render();
		}
		void BoardView::Reset()
		{
		}

	}
}