#pragma once
#include "CellModel.h"

namespace Gameplay
{
	namespace Cell
	{
		class CellView;
		class CellModel;
		
		class CellController
		{
		private:
			CellView* cellView;
			CellModel* cellModel;

		public:
			CellController(int cellIndex);
			~CellController();

			void Initialize(float cellWidth, float cellHeight);
			void Update();
			void Render();

			void Reset();

			void SetCellState(CellState state);
			CellState GetCellState();

			void SetCellValue(CellValue value);
			CellValue GetCellValue();

			sf::Vector2i GetGridPosition();
			int GetCellIndex();
		};

	}
}
