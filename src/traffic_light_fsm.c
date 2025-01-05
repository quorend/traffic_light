/*
 * This file implements the traffic light state actions and transitions.
 */

#include "traffic_light_fsm.h"
#include "CuTest.h"

static struct fsm_context fsm_context;

/* Table of state function pointers for use by the fsm module */
void *function_table[MAX_s];

static void init_state(void);
static void red_state(void);
static void green_state(void);
static void yellow_state(void);

void traffic_light_tick(void)
{
  printf("tick\r\n");
  return;
}

int8_t init_fsm(void)
{
  /* Populate the state function table */
  function_table[init_s] = init_state;
  function_table[red_s] = red_state;
  function_table[green_s] = green_state;
  function_table[yellow_s] = yellow_state;

  /* Zero the context, then fill it. */

  memset(&fsm_context, '\0', sizeof(struct fsm_context));

  fsm_context.state_current = init_s;
  fsm_context.state_previous = init_s;
  fsm_context.state_count = MAX_s;

  return 0; /* Success */
}

/*
 * State functions.
 */

/* Init State actions */
static void init_state(void)
{
}

/* Red State actions */
static void red_state(void)
{
}

/* Green State Actions */
static void green_state(void)
{
}

/* Yellow State actions */
static void yellow_state(void)
{
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

/* Test that the state function table had a non-null value for init_state */
void Test_init_fsm_tbl_init(CuTest *tc)
{
  init_fsm();

  CuAssertPtrNotNull(tc, function_table[init_s]);
}

/* Test that the state function table had a non-null value for red_state */
void Test_init_fsm_tbl_red(CuTest *tc)
{
  init_fsm();

  CuAssertPtrNotNull(tc, function_table[red_s]);
}

/* Test that the state function table had a non-null value for green_state */
void Test_init_fsm_tbl_green(CuTest *tc)
{
  init_fsm();

  CuAssertPtrNotNull(tc, function_table[green_s]);
}

/* Test that the state function table had a non-null value for yellow_state */
void Test_init_fsm_tbl_yellow(CuTest *tc)
{
  init_fsm();

  CuAssertPtrNotNull(tc, function_table[yellow_s]);
}

/* Aggregate the above tests into a test suite */
CuSuite *traffic_light_fsm_GetSuite()
{
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, Test_init_fsm_current);
  SUITE_ADD_TEST(suite, Test_init_fsm_previous);
  SUITE_ADD_TEST(suite, Test_init_fsm_count);
  SUITE_ADD_TEST(suite, Test_init_fsm_tbl_init);
  SUITE_ADD_TEST(suite, Test_init_fsm_tbl_red);
  SUITE_ADD_TEST(suite, Test_init_fsm_tbl_green);
  SUITE_ADD_TEST(suite, Test_init_fsm_tbl_yellow);
  return suite;
}
