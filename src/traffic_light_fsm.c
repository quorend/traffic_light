/*
 * This file implements the traffic light state actions and transitions.
 */

#include "traffic_light_fsm.h"

static struct fsm_context fsm_context;

void traffic_light_tick(void)
{
  printf("tick\r\n");
  return;
}

int8_t init_fsm(void)
{
  /* Zero the context, then fill it. */

  memset(&fsm_context, '\0', sizeof(struct fsm_context));

  fsm_context.state_current = init_s;
  fsm_context.state_previous = init_s;
  fsm_context.state_count = MAX_s;

  return 0; /* Success */
}
