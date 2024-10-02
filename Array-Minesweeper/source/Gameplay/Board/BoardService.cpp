#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Gameplay/Board/BoardController.h"

namespace Gameplay
{
	namespace Board
	{

		BoardService::BoardService()
		{
			boardController = nullptr;
		}

		BoardService::~BoardService()
		{
			delete(boardController);
		}
		void BoardService::Initialize()
		{
			boardController = new BoardController();

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

		void BoardService::Destroy()
		{
			Destroy();

		}
	}
}