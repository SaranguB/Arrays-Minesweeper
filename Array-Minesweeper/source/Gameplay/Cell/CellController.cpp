#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellView.h"

namespace Gameplay
{
	namespace Cell
	{
		CellController::CellController()
		{
			cellView = new CellView(this);
		}
		CellController::~CellController()
		{
			delete(cellView);
		}
		void CellController::Initialzie()
		{
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

		}
	}
}