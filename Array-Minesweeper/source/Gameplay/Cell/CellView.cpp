#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Global/Config.h"


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

		void CellView::Initialzie()
		{
			InitialzieButtonImage(tileSize * 3, tileSize * 3);
		}
		void CellView::InitialzieButtonImage(float width, float height)
		{
			cellButtom->initialize("cell", Config::cells_texture_path, width, height, sf::Vector2f(0, 0));
		}

		void CellView::Update()
		{
			cellButtom->update();
		}

		void CellView::Render()
		{
			cellButtom->render();

		}


	}
}