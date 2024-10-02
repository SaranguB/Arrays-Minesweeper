#pragma once

namespace Gameplay
{
	namespace Board
	{
		class BoardController;
		class BoardService
		{
		private:
			BoardController* boardController;

			void Destroy();
		public:
			BoardService();
			~BoardService();

			void Initialize();
			void Update();
			void Render();
			void ResetBoard();

			

		};
	}
}