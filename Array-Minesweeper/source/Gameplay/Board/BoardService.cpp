#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Gameplay/Board/BoardController.h"

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;
		using namespace UI::UIElement;

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
			return boardController->GetMineCount();
		}

		void BoardService::ProcessCellInput(Cell::CellController* controller, UI::UIElement::ButtonType type)
		{
			boardController->ProcessCellInput(controller, type);
		}

		

		void BoardService::Destroy()
		{
			Destroy();

		}
	}
}