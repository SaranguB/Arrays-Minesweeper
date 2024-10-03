#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Global/Config.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellModel.h"

namespace Gameplay
{
	namespace Cell
	{
		using namespace UI::UIElement;
		using namespace Global;



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

		void CellView::InitialzieButtonImage(float width, float height)
		{
			cellButtom->initialize("cell", Config::cells_texture_path, width * slicecount, height, GetCellScreenPosition());
		}

		void CellView::Initialize(float cellWidth, float cellHeight)
		{
			InitialzieButtonImage(cellWidth, cellHeight);
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

		sf::Vector2f CellView::GetCellScreenPosition()
		{
			float xScreenPosition = cellLeftOffset;
			float YScreenPosition = cellTopOffset;
			return sf::Vector2f(xScreenPosition, YScreenPosition);
		}


	}
}