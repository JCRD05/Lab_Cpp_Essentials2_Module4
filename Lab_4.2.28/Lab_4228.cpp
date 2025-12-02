#include <iostream>
#include <array>
#include <string_view>
#include <vector>

class FiniteStateMachine
{

public:
	enum class State
	{
		Start = 1,
		Running,
		Pause,
		End
	};

	FiniteStateMachine() : m_currentState(State::Start)
	{
		m_statesVisited.push_back(m_currentState);
	}

	FiniteStateMachine& operator>>(const State state)
	{
		transitionTo(state);
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& output, const FiniteStateMachine& FSM)
	{
		for (auto state : FSM.m_statesVisited)
		{
			output << state << " ";
		}

		return output;
	}

private:
	State m_currentState;
	std::vector<State> m_statesVisited;

	void transitionTo(const State& state)
	{
		bool validTransition{};

		if (m_currentState == state) { return; }

		switch (m_currentState)
		{
			case State::Start:
				if (state == State::Running) { validTransition = true; }
				break;
			case State::Running:
				if (state == State::Pause || state == State::End) { validTransition = true; }
				break;
			case State::Pause:
				if (state == State::Running) { validTransition = true; }
				break;
			case State::End:
				if (state == State::Start) { validTransition = true; }
				break;
		}

		if (validTransition)
		{
			m_currentState = state;
			m_statesVisited.push_back(state);
		}
	}

	friend std::ostream& operator<<(std::ostream& output, const State& state)
	{
		switch (state)
		{
			case State::Start: output << "Start"; break;
			case State::Running: output << "Running"; break;
			case State::Pause: output << "Pause"; break;
			case State::End: output << "End"; break;
		}

		return output;
	}
};

int main()
{
	using State = FiniteStateMachine::State;

	FiniteStateMachine myFSM{};

	myFSM >> State::Running;
	myFSM >> State::Pause;
	myFSM >> State::Running;
	myFSM >> State::End;

	std::cout << myFSM;
}