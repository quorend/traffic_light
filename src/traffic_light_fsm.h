#ifndef __TRAFFIC_LIGHT_FSM_H__
#define __TRAFFIC_LIGHT_FSM_H__

/*
 * This file declares the interface for the Traffic Light Finite State Machine.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

enum fsm_states_e
  {
    init_s,
    red_s,
    green_s,
    yellow_s,
    MAX_s
  };

static const char *state_messages[MAX_s] =
  {
    [init_s] = "",
    [red_s] = "Red Light",
    [green_s] = "Green Light",
    [yellow_s] = "Yellow Light",
  };

/*
 * The features of the traffic light FSM are so simple that the context doesn't
 * actually need the previous state or number of states. They remain here as a
 * future optional feature extention.
 */
struct fsm_context
{
  enum fsm_states_e state_current;
  enum fsm_states_e state_previous;
  enum fsm_states_e state_count;
};

/*
 * No events need to be issued to the state machine unless I want to implement
 * some extra functionality like triggering a "blinking red" state or
 * something like that.
 */
enum fsm_events_e
  {
    MAX_e
  };

/*
 * This tick function is designed to be called at some interval from the main
 * program loop. It allows the traffic light to transition from state to state
 * after some number of ticks.
 */
void traffic_light_tick(void);

/*
 * This function initializes the traffic light FSM to the init state.
 *
 * On success 0 is returned, otherwise non-zero.
 */
int8_t init_fsm(void);

/*
 * This function moves the FSM to a new current state.
 */
void transition_state(enum fsm_states_e new_state);

#endif /* __TRAFFIC_LIGHT_FSM_H__ */
