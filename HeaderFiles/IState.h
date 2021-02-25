class App;

class IState 
{
	/* Game state with it own game loop */
public:
	IState(App& app);
	virtual void Draw() = 0;
	virtual ~IState();

protected:
	App& mApp;
};