#ifndef __FSM_H__
#define __FSM_H__

/*
 * This file defines the Finite State Machine interface.
 */

#include <stdint.h>

struct fsm_context
{
  uint8_t state_current;
  uint8_t state_previous;
  uint8_t state_count;
};

void transition_state(uint8_t next_state);

void do_state_actions(void);

#endif /* __FSM_H__ */
