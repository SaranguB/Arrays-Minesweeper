#pragma once
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/UI/UIElement/ButtonView.h"

namespace Gameplay
{
	namespace Board
	{
		class BoardView;
		class BoardController
		{
		private:



			BoardView* boardView;

			void CreateBoard();
			void DeleteBoard();
			void Destroy();

			float cellHeight;
			float CellWidth;

			void InitializeCells();

			int flaggedCell;

		public:
			BoardController();
			~BoardController();

			void Initialize();
			void Update();
			void Render();
			void Reset();

			static constexpr int numberOfRows = 9;
			static constexpr int numberOfColumms = 9;
			static constexpr int minesCount = 8;

			Cell::CellController* board[numberOfRows][numberOfColumms];

			void ResetBoard();

			int GetMineCount();

			void OpenCell(sf::Vector2i cellPosition);
			void ProcessCellInput(Cell::CellController* controller, UI::UIElement::ButtonType type);

			void FlagCell(sf::Vector2i cellPosition);

			
		};
	}
}