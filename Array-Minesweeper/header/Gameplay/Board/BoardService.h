#pragma once
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/UI/UIElement/ButtonView.h"

namespace Gameplay
{
	namespace Board
	{
		class CellController;
		class BoardController;
		
		class BoardService
		{
		private:
			BoardController* boardController;

			void Destroy();
		public:
			BoardService();
			~BoardService();

			void Initialize();
			void Update();
			void Render();
			void ResetBoard();

			int GetMineCount();

			void ProcessCellInput(Cell::CellController* controller,UI::UIElement::ButtonType type);

		};
	}
}