/*
 * This file implements the traffic light state actions and transitions.
 */

#include "traffic_light_fsm.h"
#include "CuTest.h"

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

/*
 * Unit tests.
 */

/* Test that state_current is initialized correctly */
void Test_init_fsm_current(CuTest *tc)
{
  init_fsm();

  enum fsm_states_e current_expected = init_s;
  enum fsm_states_e current_actual = fsm_context.state_current;

  CuAssertIntEquals(tc, current_expected, current_actual);
}

/* Test that state_previous is initialized correctly */
void Test_init_fsm_previous(CuTest *tc)
{
  init_fsm();

  enum fsm_states_e previous_expected = init_s;
  enum fsm_states_e previous_actual = fsm_context.state_previous;

  CuAssertIntEquals(tc, previous_expected, previous_actual);
}

/* Test that state_count is initialized correctly */
void Test_init_fsm_count(CuTest *tc)
{
  init_fsm();

  enum fsm_states_e count_expected = MAX_s;
  enum fsm_states_e count_actual = fsm_context.state_count;

  CuAssertIntEquals(tc, count_expected, count_actual);
}

/* Aggregate the above tests into a test suite */
CuSuite *traffic_light_fsm_GetSuite()
{
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, Test_init_fsm_current);
  SUITE_ADD_TEST(suite, Test_init_fsm_previous);
  SUITE_ADD_TEST(suite, Test_init_fsm_count);
  return suite;
}
