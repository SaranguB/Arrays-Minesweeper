#pragma once
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/UI/UIElement/ImageView.h"


namespace Gameplay
{
	namespace Cell
	{
		class CellController;
		class CellView
		{
		private:
			UI::UIElement::ButtonView* cellButtom;
			CellController* cellController;


			void InitialzieButtonImage(float width, float height);
			const int tileSize = 32;

			int slicecount = 12;

			void Destroy();
		public:
			CellView(CellController* controller);
			~CellView();

			void Initialzie();
			void Update();
			void Render();

			void SetCellTexture();


		};

	}
}
