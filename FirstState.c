#include <stdio.h>
#include "FreeRtosConfig.h"
#include "tasks.h"
#include "queue.h"
#include "firstState.h"

f_t state [STATE_MAX][STATE_EVENT_MAX] = \
{
	[ON_STATE] 		= {on_state_entry,on_state_exit},
	[OFF_STATE] 	= {off_state_entry,off_state_exit},
	[IDLE_STATE] 	= {idle_state_entry,idle_state_exit},
};

QueueHandle_t eventQueueHandle = NULL;
QueueHAndle_t stateQueueHandle = NULL; 

void errorHandler(void)
{
	while(1);
}

void rtos_init(void)
{
	if(pdPASS != xTaskCreate(event_task, "event task", 128, NULL, 3, NULL))
	{
		errorHandler();
	}
	if(pdTRUE != xTaskCreate(state_task, "state task",128,NULL,2,NULL))
	{
		errorHandler();
	}
	if(pdPASS != xTaskCreate(periodic_task, "periodic task",NULL, 1, NULL))
	{
		errorHandler();
	}
	eventQueueHandle = xQueueCreate(10, sizeof(event_t));
	if(NULL == eventQueueHandle)
	{
		errorHandler();
	}
	stateQueueHandle = xQueueCreate(10,sizeof(state_t));
	if(NULL == stateQueueHandle)
	{
		errorHandler();
	}
}

void postEvent(event_t event)
{
	state_transition_t state_transition;
	state_transition = state[current_state_info.current_state][event]();
}

void state_task(void* parm)
{
	state_event_t state_event;
	while(1)
	{
		if(pdTRUE == xQueueReceive(stateQueueHandle,&state_event,pdMS_TO_TICKS(portMAX_DELAY)))
		{
			post_state_event(state_event);
		}
	}
	(void*) parm;
}

void event_task(void* parm)
{
	event_t event;
	while(1)
	{
		if(pdTRUE == xQueueReceive(eventQueueHandle, &event,pdMS_TO_TICKS(portMAX_DELAY)))
		{
			post_event(event);//TODO: create post_event fun
		}
	}
	(void*)parm;
}

void periodic_task(void* parm)
{
	while(1);//TODO: impelemtation of periodic task
	(void*)parm;
}

void main(void)
{
	rtos_init();
	vTaskStartScheduler();
	while(1)
	{
		;
	}
}

void event_ISR(event_t event)
{
	if(pdPASS != xQueueSendFromISR(eventQueueHandle,&event,NULL))
	{
		errorHandler();
	}
}