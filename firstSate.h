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
	GOTO_SLEEP,
	EVENT_MAX
}event_t;

typedef enum
{
	ON_STATE,
	OFF_STATE,
	IDLE_STATE
	STATE_MAX
}state_t;

typedef enum
{
	ENTRY_STATE_ACTION,
	EXIT_STATE_ACTION,
	STATE_ACTION_MAX
}state_action_t;

typedef struct
{
	state_t current_sate;
	state_t previous_sate;
}current_state_info_t;
