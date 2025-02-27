#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Gameplay/GameplayController.h"


namespace Gameplay
{
	namespace Board
	{
		using namespace UI::UIElement;
		using namespace Global;
		using namespace Sound;
		using namespace Cell;



		BoardController::BoardController() : randomEngine(randomDevice())
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
			boardState = BoardState::FIRST_CELL;
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
				if (boardState == BoardState::FIRST_CELL)
				{
					PopulateBoard(cellPosition);
					boardState = BoardState::PLAYING;
				}
			}
			ProcessCellValue(cellPosition);
			board[cellPosition.x][cellPosition.y]->OpenCell();

		}

		void BoardController::PopulateBoard(sf::Vector2i cellPosition)
		{
			PopulateMines(cellPosition);
			PopulateCells();
		}

		void BoardController::PopulateMines(sf::Vector2i cellPosition)
		{
			std::uniform_int_distribution<int>xDistribution(0, numberOfColumms - 1);
			std::uniform_int_distribution<int>yDistribution(0, numberOfRows - 1);

			for (int a = 0; a < minesCount;a++)
			{
				int i = static_cast<int>(xDistribution(randomEngine));
				int j = static_cast<int>(yDistribution(randomEngine));

				if (board[i][j]->GetCellValue() == CellValue::MINE || (cellPosition.x == i && cellPosition.y == j))a--;
				else board[i][j]->SetCellValue(CellValue::MINE);

			}

		}

		void BoardController::PopulateCells()
		{
			for (int i = 0;i < numberOfRows;i++)
			{
				for (int j = 0;j < numberOfColumms;j++)
				{
					if (board[i][j]->GetCellValue() != CellValue::MINE)
					{
						CellValue value = static_cast<CellValue>(CountMinesAround(sf::Vector2i(i, j)));
						board[i][j]->SetCellValue(value);
					}
				}
			}
		}


		int  BoardController::CountMinesAround(sf::Vector2i cellPosition)
		{
			int minesAround = 0;

			for (int a = -1;a < 2;a++)
			{
				for (int b = -1;b < 2;b++)
				{
					if ((a == 0 && b == 0) || !IsvalidCellPosition(sf::Vector2i(cellPosition.x + a, cellPosition.y + b)))
					{
						continue;
					}
					if (board[a + cellPosition.x][b + cellPosition.y]->GetCellValue() == CellValue::MINE)
					{
						minesAround++;
					}
				}
			}
			return minesAround;
		}
		bool BoardController::IsvalidCellPosition(sf::Vector2i cellPosition)
		{
			return (cellPosition.x >= 0 && cellPosition.y >= 0 &&
				cellPosition.x < numberOfColumms && cellPosition.y < numberOfRows);
		}

		void BoardController::ProcessCellValue(sf::Vector2i cellPosition)
		{
			switch (board[cellPosition.x][cellPosition.y]->GetCellValue())
			{
			case CellValue::EMPTY:
				ProcessEmptyCell(cellPosition);
				break;

			case CellValue::MINE:
				ProcessMineCell(cellPosition);
				break;

			default:
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
				break;
			}
		}

		void BoardController::ProcessEmptyCell(sf::Vector2i cellPosition)
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			OpenEmptyCell(cellPosition);
		}

		void BoardController::OpenEmptyCell(sf::Vector2i cellPosition)
		{
			switch (board[cellPosition.x][cellPosition.y]->GetCellState())
			{
			case CellState::OPEN:
				return;

			case CellState::FLAGGED:
				flaggedCell--;

			default:
				board[cellPosition.x][cellPosition.y]->OpenCell();
			}

			for (int a = -1; a < 2; a++)
			{

				for (int b = -1;b < 2;b++)
				{
					if ((a == 0 && b == 0) || !IsvalidCellPosition(sf::Vector2i(cellPosition.x + a, cellPosition.y + b)))
					{
						continue;
					}
					sf::Vector2i nextCellPosition = sf::Vector2i(a + cellPosition.x, b + cellPosition.y);
					OpenCell(nextCellPosition);
				}
			}

		}

		void BoardController::ProcessMineCell(sf::Vector2i cellPosition)
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::EXPLOSION);
			ServiceLocator::getInstance()->GetGameplayService()->EndGame(GameResult::LOST);
		}

		void BoardController::ProcessCellInput(Cell::CellController* controller, ButtonType type)
		{
			if (boardState == BoardState::COMPLETED)
				return;

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

		void BoardController::SetBoardState(BoardState state)
		{
			boardState = state;
		}

		BoardState BoardController::GetBoardState()
		{
			return boardState;
		}

		void BoardController::OpenAllCells()
		{

			for (int i = 0;i < numberOfRows;i++)
			{
				for (int j = 0;j < numberOfColumms;j++)
				{
					board[i][j]->OpenCell();
				}
			}
		}

		void BoardController::ShowBoard()
		{
			switch (ServiceLocator::getInstance()->GetBoardService()->GetBoardState())
			{
			case BoardState::FIRST_CELL:
				PopulateBoard(sf::Vector2i(0, 0));
				OpenAllCells();
				break;

			case BoardState::PLAYING:
				OpenAllCells();
				break;

			case BoardState::COMPLETED:
				break;

			default:
				break;

			}
		}

		void BoardController::FlagAllMines()
		{
			for(int row = 0;row < numberOfRows;row++)
			{
				for (int col = 0;col < numberOfColumms;col++)
				{
					if (board[row][col]->GetCellValue() == CellValue::MINE &&
						board[row][col]->GetCellState() != CellState::FLAGGED)
					{
						FlagCell(sf::Vector2i(row, col));
					}

				}

				

			}
		}



	}
}