#include <stdio.h>

typedef (void)(* f_t)(void);

void event1_entry(void);
void event1_exit(void);
void event2_entry(void);
void event2_exit(void);

typedef enum
{
	EVENT1,
	EVENT12,
	EVENT1_MAX
}event_t;

typedef
{
	ENTRY,
	EXIT,
	STATE_ACTION_MAX
}states_action_t;

f_t state [EVENT1_MAX][STATE_ACTION_MAX] = \
{
	[EVENT1] = {event1_entry,event1_exit},
	[EVENT2] = {event2_entry,event2_exit},
};

void postEvent(int event)
{
	state()
}

void main(void)
{

	while(1)
	{
		printf("Enter Event: \n");
	}
}