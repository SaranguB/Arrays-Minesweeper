#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Global/Config.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellModel.h"
#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Main/GameService.h"
#include <iostream>

namespace Gameplay
{
	namespace Cell
	{
		using namespace UI::UIElement;
		using namespace Global;
		using namespace Main;


		CellView::CellView(CellController* controller)
		{
			cellController = controller;
			cellButtom = new ButtonView();
		}

		CellView::~CellView()
		{
			Destroy();
		}

		void CellView::Destroy()
		{
			delete(cellButtom);
		}

		
		void CellView::Initialize(float cellWidth, float cellHeight)
		{
			InitialzieButtonImage(cellWidth, cellHeight);
			
		}

		void CellView::InitialzieButtonImage(float width, float height)
		{
			cellButtom->initialize("cell", Config::cells_texture_path, width * slicecount, height, GetCellScreenPosition(width, height));
			RegisterButtonCallback();
		}


		void CellView::Update()
		{
			cellButtom->update();
		}

		void CellView::Render()
		{
			cellButtom->render();
			SetCellTexture();

		}

		void CellView::SetCellTexture()
		{
			int index = static_cast<int>(cellController->GetCellValue());

			switch (cellController->GetCellState())
			{
			case CellState::HIDDEN:
				cellButtom->setTextureRect(sf::IntRect(10 * tileSize, 0, tileSize, tileSize));
				break;

			case CellState::OPEN:
				cellButtom->setTextureRect(sf::IntRect(index * tileSize, 0, tileSize, tileSize));
				break;
			case CellState::FLAGGED:
				cellButtom->setTextureRect(sf::IntRect(11 * tileSize, 0, tileSize, tileSize));
				break;
			}


		}

		sf::Vector2f CellView::GetCellScreenPosition(float width, float height)
		{

			sf::Vector2i cellIndex = cellController->GetCellPosition();

			float xScreenPosition = cellLeftOffset + cellIndex.y * width;
			float YScreenPosition = cellTopOffset + cellIndex.x * height;

			return sf::Vector2f(xScreenPosition, YScreenPosition);
		}

		void CellView::RegisterButtonCallback()
		{
			cellButtom->registerCallbackFuntion(std::bind(&CellView::CellButtonCallback, this,std::placeholders::_1));
	
		}

		void CellView::CellButtonCallback(ButtonType type)
		{
			
			switch (type)
			{
			case ButtonType::LEFT_MOUSE_BUTTON:
				cellController->OpenCell();
				break;

			case ButtonType::RIGHT_MOUSE_BUTTON:
				//printf("right Is CLicked");
				cellController->FlagCell();
				break;

			default:
				break;
			}
		}


	}
}