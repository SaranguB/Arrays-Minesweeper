#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Gameplay/Cell/CellModel.h"
#include "../../header/Global/ServiceLocator.h"

namespace Gameplay
{
	namespace Cell
	{
		using namespace Global;

		CellController::CellController(sf::Vector2i position)
		{
			cellModel = new CellModel(position);
			cellView = new CellView(this);

		}
		CellController::~CellController()
		{
			delete(cellModel);
			delete(cellView);
		}

		void CellController::Initialize(float cellWidth, float cellHeight)
		{
			cellModel->Initialzie();
			cellView->Initialize(cellWidth, cellHeight);
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

		sf::Vector2i CellController::GetCellPosition()
		{
			return cellModel->GetCellPosition();
		}

		void CellController::OpenCell()
		{
			SetCellState(CellState::OPEN);
		}

		void CellController::FlagCell()
		{
			switch (cellModel->GetCellState())
			{
			case::Gameplay::Cell::CellState::FLAGGED:
				cellModel->SetCellState(CellState::HIDDEN);
				break;

			case::Gameplay::Cell::CellState::HIDDEN:
				cellModel->SetCellState(CellState::FLAGGED);
				break;

			default:
				break;
			}
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::FLAG);

		}

		bool CellController::CanOpenCell()
		{
			return cellModel->GetCellState() != CellState::FLAGGED && cellModel->GetCellState() != CellState::OPEN;
		}
	}
}