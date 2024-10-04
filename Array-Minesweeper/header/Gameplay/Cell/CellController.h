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
			CellController(sf::Vector2i position);
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

			sf::Vector2i GetCellPosition();

			void OpenCell();
			void FlagCell();
		
			bool CanOpenCell();
			
		};

	}
}
