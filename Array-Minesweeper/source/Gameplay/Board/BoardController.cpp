#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;
		BoardController::BoardController()
		{
			boardView = new BoardView(this);
			CreateBoard();
		}
		BoardController::~BoardController()
		{
			Destroy();
		}

		void BoardController::Destroy()
		{

			delete(boardView);

		}
		void BoardController::Initialize()
		{
			boardView->Initialize();
			cellController->Initialzie();
		}
		void BoardController::Update()
		{
			boardView->Update();
			cellController->Update();
		}
		void BoardController::Render()
		{
			boardView->Render();
			cellController->Render();
		}

		void BoardController::CreateBoard()
		{
			cellController = new CellController();

		}
		void BoardController::DeleteBoard()
		{
			delete(cellController);
		}

		void BoardController::Reset()
		{
			cellController->Reset();
		}

	}
}