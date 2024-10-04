#pragma once
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include <random>

namespace Gameplay
{
	namespace Board
	{
		enum class BoardState
		{
			FIRST_CELL,       
			PLAYING,          
			COMPLETED,   
		};

		class BoardView;
		class BoardController
		{
		private:


			BoardState boardState;
			BoardView* boardView;

			std::default_random_engine randomEngine;
			std::random_device randomDevice;

			void CreateBoard();
			void DeleteBoard();
			void Destroy();

			float cellHeight;
			float CellWidth;

			void InitializeCells();

			int flaggedCell;

			void PopulateBoard(sf::Vector2i cellPosition);

			void PopulateMines(sf::Vector2i cellPosition);
			void PopulateCells();

			int CountMinesAround(sf::Vector2i cellPosition);
			bool IsvalidCellPosition(sf::Vector2i cellPosition);
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

			void SetBoardState(BoardState state);
			BoardState GetBoardState();

			void OpenAllCells();

			
		};
	}
}