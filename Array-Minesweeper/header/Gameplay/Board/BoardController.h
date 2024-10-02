#pragma once

namespace Gameplay
{
	namespace Board
	{
		class BoardView;
		class BoardController
		{
		private:
			BoardView* boardView;

			void CreateBoard();
			void DeleteBoard();
			void Destroy();

		public:
			BoardController();
			~BoardController();

			void Initialize();
			void Update();
			void Render();
			void Reset();

			static const int numberOfRows = 9;
			static const int numberOfColumms = 9;
			static const int minesCount = 8;

			
		};
	}
}