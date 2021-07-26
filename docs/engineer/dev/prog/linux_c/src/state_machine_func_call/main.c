// https://github.com/misje/stateMachine
// http://misje.github.io/stateMachine/

#include <stdio.h>
#include <stdbool.h>

typedef enum
{
  ST_IDLE,
  ST_LED_ON,
  ST_LED_OFF
} state_t;

typedef struct
{
  state_t currState;
} stateMachine_t;

/// \brief      All the possible events that can occur for this state machine.
/// \details    Unlike states_t, these do not need to be kept in a special order.
typedef enum
{
  EV_ANY,
  EV_NONE,
  EV_BUTTON_PUSHED,
  EV_TIME_OUT,
} event_t;

typedef struct
{
  const char *name;
  void (*func)(void);
} stateFunctionRow_t;

void Led_Init()
{
  printf("Led_Init() called.\r\n");
}

void Led_On()
{
  printf("LED turned on.\r\n");
}

void Led_Off()
{
  printf("LED turned off.\r\n");
}

void Led_Idle()
{
  printf("LED in idle state.\r\n");
}

/// \brief  Maps a state to it's state transition function, which should be called
///         when the state transitions into this state.
/// \warning    This has to stay in sync with the state_t enum!
static stateFunctionRow_t stateFunctionA[] = {
    // NAME         // FUNC
    {"ST_IDLE", &Led_Idle},   // ST_IDLE
    {"ST_LED_ON", &Led_On},   // ST_LED_ON
    {"ST_LED_OFF", &Led_Off}, // ST_LED_OFF
};

typedef struct
{
  state_t currState;
  event_t event;
  state_t nextState;
} stateTransMatrixRow_t;

static stateTransMatrixRow_t stateTransMatrix[] = {
    // CURR STATE  // EVENT              // NEXT STATE
    {ST_IDLE, EV_BUTTON_PUSHED, ST_LED_ON},
    {ST_LED_ON, EV_TIME_OUT, ST_LED_OFF},
    {ST_LED_ON, EV_BUTTON_PUSHED, ST_IDLE},
    {ST_LED_OFF, EV_TIME_OUT, ST_LED_ON},
    {ST_LED_OFF, EV_BUTTON_PUSHED, ST_IDLE}};

void StateMachine_Init(stateMachine_t *stateMachine)
{
  printf("Initialising state machine.\r\n");
  stateMachine->currState = ST_IDLE;
}

// TIP
void StateMachine_RunIteration(stateMachine_t *stateMachine, event_t event)
{

  // Iterate through the state transition matrix, checking if there is both a match with the current state
  // and the event
  for (int i = 0; i < sizeof(stateTransMatrix) / sizeof(stateTransMatrix[0]); i++)
  {
    if (stateTransMatrix[i].currState == stateMachine->currState)
    {
      if ((stateTransMatrix[i].event == event) || (stateTransMatrix[i].event == EV_ANY))
      {

        // Transition to the next state
        stateMachine->currState = stateTransMatrix[i].nextState;

        // Call the function associated with transition
        (stateFunctionA[stateMachine->currState].func)();
        break;
      }
    }
  }
}

const char *StateMachine_GetStateName(state_t state)
{
  return stateFunctionA[state].name;
}

int main()
{
  printf("main() called.\r\n");

  // Create new state machine object
  stateMachine_t stateMachine;

  StateMachine_Init(&stateMachine);
  printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));

  // Push button to start flasher
  printf("Button pushed.\r\n");
  StateMachine_RunIteration(&stateMachine, EV_BUTTON_PUSHED);
  printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));

  // Timeout
  printf("Timeout.\r\n");
  StateMachine_RunIteration(&stateMachine, EV_TIME_OUT);
  printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));

  // Timeout
  printf("Timeout.\r\n");
  StateMachine_RunIteration(&stateMachine, EV_TIME_OUT);
  printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));

  // Timeout
  printf("Timeout.\r\n");
  StateMachine_RunIteration(&stateMachine, EV_TIME_OUT);
  printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));

  // Push button again to stop flasher
  printf("Button pushed.\r\n");
  StateMachine_RunIteration(&stateMachine, EV_BUTTON_PUSHED);
  printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));

  return 0;
}