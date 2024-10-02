#pragma once

namespace Gameplay
{
	namespace Cell
	{
		class CellView;
		class CellController
		{
		private:
			CellView* cellView;

		public:
			CellController();
			~CellController();

			void Initialzie();
			void Update();
			void Render();

			void Reset();
		};

	}
}
