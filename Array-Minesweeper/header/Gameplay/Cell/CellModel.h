#pragma once
#include <sfml/Graphics.hpp>

namespace Gameplay
{
	namespace Cell
	{
        enum class CellState
        {
            HIDDEN,
            OPEN,
            FLAGGED,
        };

        enum class CellValue
        {
            EMPTY,
            ONE,
            TWO,
            THREE,
            FOUR,
            FIVE,
            SIX,
            SEVEN,
            EIGHT,
            MINE,
        };

		class CellModel
		{
		private:
            CellState cellState;
            CellValue cellValue;

            int cellIndex;

		public:
			CellModel(int cellIndex);
			~CellModel();

			void Initialzie();

            void SetCellState(CellState state);
            CellState GetCellState();

            void SetCellValue(CellValue value);
            CellValue GetCellValue();

            sf::Vector2i GetGridPosition();

            void Reset();

            int GetCellIndex();
		};

	}
}
