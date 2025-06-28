typedef enum
{
	EVENT_IGNORED,
	EVENT_HANDLED,
	EVENT_TRANSITION
}state_transition_t;
typedef (state_transition_t)(* f_t)(void);

state_transition_t on_state_entry(void);
state_transition_t on_state_exit(void);
state_transition_t off_state_entry(void);
state_transition_t off_state_exit(void);
state_transition_t idle_state_entry(void);
state_transition_t idle_state_exit(void);

typedef enum
{
	LEFT_EVENT,
	RIGHT_EVENT,
	STRAIGHT_EVENT,
	ON_EVENT,
	OFF_EVENT,
	EVENT_MAX
}event_t;

typedef
{
	ENTRY,
	EXIT,
	STATE_ACTION_MAX
}states_action_t;

typedef enum
{
	ON_STATE,
	OFF_STATE,
	IDLE_STATE
	STATE_MAX
}state_t;

typedef enum
{
	ENTRY_STATE_EVENT,
	EXIT_STATE_EVENT,
	STATE_EVENT_MAX
}state_event_t;

struct
{
	state_t current_sate;
	state_t previous_sate;
}current_state_info;
