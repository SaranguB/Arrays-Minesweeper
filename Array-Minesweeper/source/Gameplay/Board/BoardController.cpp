#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"

namespace Gameplay
{
	namespace Board
	{

		BoardController::BoardController()
		{
			boardView = new BoardView(this);
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
		}
		void BoardController::Update()
		{
			boardView->Update();
		}
		void BoardController::Render()
		{
			boardView->Render();
		}

		void BoardController::CreateBoard()
		{
		}
		void BoardController::DeleteBoard()
		{

		}

		void BoardController::Reset()
		{

		}

	}
}