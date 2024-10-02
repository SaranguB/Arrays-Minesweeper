#pragma once
#include "../../header/UI/UIElement/ImageView.h"

namespace Gameplay
{
	namespace Board
	{
		class BoardController;
		class BoardView
		{
		private:
			BoardController* boardController;
			UI::UIElement::ImageView* backgroundImage;
			UI::UIElement::ImageView* boardImage;

			const float backgroundAlpha = 85.f;
			const float boardWidth = 866.f;
			const float boardHeight = 1080.f;

			sf::RenderWindow* gameWindow;

			void InitializeBackgroundImage();
			void InitializeBoardImage();

		public:
			BoardView(BoardController* controller);
			~BoardView();

			void Initialize();
			void Update();
			void Render();
			void Reset();
		};
	}
}