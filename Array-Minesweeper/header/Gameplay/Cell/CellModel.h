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

            sf::Vector2i position;

		public:
			CellModel(sf::Vector2i position);
			~CellModel();

			void Initialzie();

            void SetCellState(CellState state);
            CellState GetCellState();

            void SetCellValue(CellValue value);
            CellValue GetCellValue();

            sf::Vector2i GetCellPosition();
            void SetCellPosition(sf::Vector2i position);
            void Reset();

            
		};

	}
}
