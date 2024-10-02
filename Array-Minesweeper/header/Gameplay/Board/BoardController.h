#pragma once

namespace Gameplay
{
	namespace Board
	{
		class BoardController
		{
		private:

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