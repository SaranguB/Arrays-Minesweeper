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
			for (int i = 0;i < numberOfRows;i++)
			{
				for (int j = 0;j < numberOfColumms;j++)
				{

					board[i][j]->Update();
				}
			}

		}
		void BoardController::Render()
		{
			boardView->Render();
			for (int i = 0;i < numberOfRows;i++)
			{
				for (int j = 0;j < numberOfColumms;j++)
				{
					board[i][j]->Render();
				}
			}
		}

		void BoardController::InitializeCells()
		{
			float cellHeight = boardView->GetCellHeight();
			float CellWidth = boardView->GetCellWidth();

			for (int i = 0;i < numberOfRows;i++)
			{
				for (int j = 0;j < numberOfColumms;j++)
				{
					board[i][j]->Initialize(CellWidth, cellHeight);
				}
			}
		}

		void BoardController::CreateBoard()
		{
			for (int i = 0;i < numberOfRows;i++)
			{
				for (int j = 0;j < numberOfColumms;j++)
				{

					board[i][j] = new CellController(sf::Vector2i(i,j));
				}
			}

		}
		void BoardController::DeleteBoard()
		{

			for (int i = 0;i < numberOfRows;i++)
			{
				for (int j = 0;j < numberOfColumms;j++)
				{
					delete(board[i][j]);
				}
			}
		}

		void BoardController::Reset()
		{
			ResetBoard();
		}

		void BoardController::ResetBoard()
		{
			for (int i = 0;i < numberOfRows;i++)
			{
				for (int j = 0;j < numberOfColumms;j++)
				{
					board[i][j]->Reset();
				}
			}

		}

	}
}