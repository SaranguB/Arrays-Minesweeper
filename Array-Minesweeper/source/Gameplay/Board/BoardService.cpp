#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Gameplay/Board/BoardController.h"

namespace Gameplay
{
	namespace Board
	{

		BoardService::BoardService()
		{
			boardController = new BoardController();

		}
		BoardService::~BoardService()
		{
			delete(boardController);
		}
		void BoardService::Initialize()
		{

			boardController->Initialize();
		}
		void BoardService::Update()
		{
			boardController->Update();
		}
		void BoardService::Render()
		{
			boardController->Render();
		}
		void BoardService::ResetBoard()
		{
			boardController->Reset();
		}

		int BoardService::GetMineCount()
		{
			return boardController->GetMineCount();;
		}

		void BoardService::Destroy()
		{
			Destroy();

		}
	}
}