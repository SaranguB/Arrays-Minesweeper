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
			CellController();
			~CellController();

			void Initialzie();
			void Update();
			void Render();

			void Reset();

			void SetCellState(CellState state);
			CellState GetCellState();

			void SetCellValue(CellValue value);
			CellValue GetCellValue();

			sf::Vector2i GetGridPosition();

		};

	}
}
