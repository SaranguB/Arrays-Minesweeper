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
			DeleteBoard();
			delete(boardView);

		}
		void BoardController::Initialize()
		{
			boardView->Initialize();
			InitializeCells();
		}
		void BoardController::Update()
		{
			boardView->Update();
			for (int i = 0;i < numberOfColumms;i++)
			{
				cells[i]->Update();
			}
			
		}
		void BoardController::Render()
		{
			boardView->Render();
			for (int i = 0;i < numberOfColumms;i++)
			{
				cells[i]->Render();
			}
		}

		void BoardController::InitializeCells()
		{
			float cellHeight = boardView->GetCellHeight();
			float CellWidth = boardView->GetCellWidth();
			for (int i = 0;i < numberOfColumms;i++)
			{

				cells[i]->Initialize(CellWidth, cellHeight);
			}
		}

		void BoardController::CreateBoard()
		{
			for (int i = 0;i < numberOfColumms;i++)
			{
				cells[i] = new CellController(i);
			}

		}
		void BoardController::DeleteBoard()
		{
			for (int i = 0;i < numberOfColumms;i++)
			{
				delete(cells[i]);
			}
			
		}

		void BoardController::Reset()
		{
			for (int i = 0;i < numberOfColumms;i++)
			{
				cells[i]->Reset();
			}
		
		}

	}
}