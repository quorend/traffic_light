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

#endif /* __TRAFFIC_LIGHT_FSM_H__ */
