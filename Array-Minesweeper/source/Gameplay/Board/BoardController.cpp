#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Sound/SoundService.h"


namespace Gameplay
{
	namespace Board
	{
		using namespace UI::UIElement;
		using namespace Global;
		using namespace Sound;
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

					board[i][j] = new Cell::CellController(sf::Vector2i(i, j));
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
			flaggedCell = 0;
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

		int BoardController::GetMineCount()
		{
			return minesCount - flaggedCell;
		}

		void BoardController::OpenCell(sf::Vector2i cellPosition)
		{
			if (board[cellPosition.x][cellPosition.y]->CanOpenCell())
			{
				board[cellPosition.x][cellPosition.y]->OpenCell();
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::FLAG);
			}

		}

		void BoardController::ProcessCellInput(Cell::CellController* controller, ButtonType type)
		{
			switch (type)
			{
			case UI::UIElement::ButtonType::LEFT_MOUSE_BUTTON:
				OpenCell(controller->GetCellPosition());

				break;

			case UI::UIElement::ButtonType::RIGHT_MOUSE_BUTTON:
				FlagCell(controller->GetCellPosition());
				break;
			default:
				break;
			}
		}

		void BoardController::FlagCell(sf::Vector2i cellPosition)
		{
			switch (board[cellPosition.x][cellPosition.y]->GetCellState())
			{
			case CellState::FLAGGED:
				ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::FLAG);
				flaggedCell--;
				break;

			case CellState::HIDDEN:
				ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::FLAG);
				flaggedCell++;
				break;
			}
			board[cellPosition.x][cellPosition.y]->FlagCell();
		}



	}
}