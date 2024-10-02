#include "../../header/Gameplay/Cell/CellModel.h"

namespace Gameplay
{
	namespace Cell
	{
		CellModel::CellModel()
		{
		}
		CellModel::~CellModel()
		{
		}
		void CellModel::Initialzie()
		{
		}
		void CellModel::SetCellState(CellState state)
		{
			cellState = state;
		}
		CellState CellModel::GetCellState()
		{
			return cellState;
		}
		void CellModel::SetCellValue(CellValue value)
		{
			cellValue = value;
		}
		CellValue CellModel::GetCellValue()
		{
			return cellValue;
		}
		sf::Vector2i CellModel::GetGridPosition()
		{
			return sf::Vector2i();
		}
		void CellModel::Reset()
		{
			cellState = CellState::HIDDEN;
			cellValue = CellValue::EMPTY;
		}
	}
}