#include "IState.h"

class GameState : public IState
{
	GameState(App& app);
	void Draw();
	~GameState();
};