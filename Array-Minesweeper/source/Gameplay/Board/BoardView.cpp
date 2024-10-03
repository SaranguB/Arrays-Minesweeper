#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include "../../header/Gameplay/Board/BoardController.h"

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
			delete(boardImage);
			delete(backgroundImage);

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

		float BoardView::GetCellWidth()
		{
			return (boardWidth - boardWidthOffset) / static_cast<float>(BoardController::numberOfColumms);
		}
		float BoardView::GetCellHeight()
		{
			return (boardHeight - boardHeightOffset) / static_cast<float>(BoardController::numberOfColumms);
		}

	

	}
}