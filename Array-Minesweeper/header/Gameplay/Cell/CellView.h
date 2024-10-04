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

			const float cellTopOffset = 274.f;
			const float cellLeftOffset = 583.f;

			int slicecount = 12;

			void Destroy();
		public:
			CellView(CellController* controller);
			~CellView();

			void Initialize(float cellWidth, float cellHeight);
			void Update();
			void Render();

			void SetCellTexture();

			sf::Vector2f GetCellScreenPosition(float width, float height);

			void RegisterButtonCallback();
			void CellButtonCallback(UI::UIElement::ButtonType type);

		};

	}
}
