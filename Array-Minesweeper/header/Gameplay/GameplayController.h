#pragma once

namespace Gameplay
{

		class GameplayController
		{
		private:
			float maxDuration = 60.f;
			float remainingTime;

		public:
			GameplayController();
			~GameplayController();

			void Initialize();
			void Update();
			void Render();
			void Reset();

			void UpdateRemainingTime();

			float GetRemainingTime();
		};
	
}