#pragma once
#include "../../header/Gameplay/Cell/CellController.h"


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

			Cell::CellController* cells[numberOfColumms];



		};
	}
}