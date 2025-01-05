/*
 * Traffic Light program begins and loops here.
 */

#include <stdio.h>
#include <stdint.h>

#include "traffic_light_fsm.h"
#include "targ.h"

int main()
{
  printf("Traffic light\r\n\r\n");

  /* Initialize the state machine */
  if (init_fsm())
    {
      printf("ERR: failed to initialize FSM\r\n");

      return 0;
    }

  while(1)
    {
      wait(1000);
      traffic_light_tick();
    }

  return 0;
}
