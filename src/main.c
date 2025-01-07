/*
 * Traffic Light program begins and loops here.
 *
 * To run the program normally, execute the program with no command-line
 * arguments. To run the unit tests, execute the program with the command line
 * argument --tests. Alternatively, run the unit tests with any command-line
 * argument.
 */

#include <stdio.h>
#include <stdint.h>

#include "traffic_light_fsm.h"
#include "targ.h"
#include "CuTest.h"

void RunAllTests(void);

int main(int argc, char **argv)
{
  /* Unit testing */
  if (argc > 1)
    {
      RunAllTests();

      return 0;
    }

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

/*
 * Run all unit tests.
 */

CuSuite *traffic_light_fsm_GetSuite();

void RunAllTests(void)
{
  CuString *output = CuStringNew();
  CuSuite *suite = CuSuiteNew();

  CuSuiteAddSuite(suite, traffic_light_fsm_GetSuite());

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\r\n", output->buffer);

  return;
}
