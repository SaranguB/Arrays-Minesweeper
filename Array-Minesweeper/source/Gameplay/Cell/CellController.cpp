#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Gameplay/Cell/CellModel.h"

namespace Gameplay
{
	namespace Cell
	{
		CellController::CellController()
		{
			cellModel = new CellModel();
			cellView = new CellView(this);

		}
		CellController::~CellController()
		{
			delete(cellModel);
			delete(cellView);
		}
		void CellController::Initialzie()
		{
			cellModel->Initialzie();
			cellView->Initialzie();
		}
		void CellController::Update()
		{
			cellView->Update();
		}
		void CellController::Render()
		{
			cellView->Render();
		}
		void CellController::Reset()
		{
			cellModel->Reset();
		}
		void CellController::SetCellState(CellState state)
		{
			cellModel->SetCellState(state);
		}
		CellState CellController::GetCellState()
		{
			return cellModel->GetCellState();;
		}
		void CellController::SetCellValue(CellValue value)
		{
			cellModel->SetCellValue(value);
		}
		CellValue CellController::GetCellValue()
		{
			return cellModel->GetCellValue();
		}

		sf::Vector2i CellController::GetGridPosition()
		{
			return cellModel->GetGridPosition();
		}
	}
}