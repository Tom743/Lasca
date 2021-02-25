class IState;

class StateManager {
public:
	StateManager();
	~StateManager();

	// Returns true if the states stack is empty
	bool IsEmpty();

	// Adds state as active to the stack
	void AddActiveState(IState* state);

	// Adds state as inactive to the stack
	void AddInactiveState(IState* state);

	// Gets the currently active state
	IState& GetActiveState();

	// Deactivate the curretly active state without unloading its assets 
	void InactivateActiveState();

	/**
	 * DropActiveState will cause the current active state to uninitialize
	 * (calls DeInit) and become an inactive state and return to the
	 * previous state on the stack. When a state is uninitialized its
	 * assets are unloaded.
	 */
	void DropActiveState(void);

	/**
	 * ResetActiveState will cause the current active state to be reset
	 * by calling the ReInit method for that state. This is useful for
	 * "Play Again Y/N?" scenarios.
	 */
	void ResetActiveState(void);

	/**
	 * RemoveActiveState will cause the current active state to be removed
	 * and return to the previous state on the stack.  Once a state has
	 * been removed, you must re-add the state.  If you just want to
	 * inactivate the current active state then use DropActiveState instead.
	 */
	void RemoveActiveState(void);

	/**
	 * SetActiveState will find the state specified by theStateID and make
	 * it the current active state and move the previously current active
	 * state as the next state.
	 * @param[in] theStateID is the ID of the State to make active
	 */
	void SetActiveState(typeStateID theStateID);


	void HandleCleanup();

private:

	// Stack to store current and  previously active states
	std::vector<IState*> mStack;

	// Stack to store states to be cleaned up
	std::vector<IState*> mDead;


};