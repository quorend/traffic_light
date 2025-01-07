/*
 * This file implements the traffic light state actions and transitions.
 */

#include <stdint.h>

#include "traffic_light_fsm.h"
#include "CuTest.h"

#define RED_CNT_MAX 20
#define GREEN_CNT_MAX 8
#define YELLOW_CNT_MAX 2

static struct fsm_context fsm_context;

/* Table of state function pointers for use by the fsm module */
void (*function_table[MAX_s])(void);

static void init_state(void);
static void red_state(void);
static void green_state(void);
static void yellow_state(void);

void traffic_light_tick(void)
{
  function_table[fsm_context.state_current]();

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

void transition_state(enum fsm_states_e new_state)
{
  fsm_context.state_previous = fsm_context.state_current;
  fsm_context.state_current = new_state;

  printf("%s\r\n", state_messages[new_state]);

  return;
}

/*
 * State functions.
 */

/* Init State actions */
static void init_state(void)
{
  transition_state(red_s);
}

/* Red State actions */
static void red_state(void)
{
  static uint8_t count = 0;

  if (count <= RED_CNT_MAX)
    {
      count++;
    }
  else
    {
      transition_state(green_s);
      count = 0;
    }

  return;
}

/* Green State Actions */
static void green_state(void)
{
  static uint8_t count = 0;

  if (count <= GREEN_CNT_MAX)
    {
      count++;
    }
  else
    {
      transition_state(yellow_s);
      count = 0;
    }

  return;
}

/* Yellow State actions */
static void yellow_state(void)
{
  static uint8_t count = 0;

  if (count <= YELLOW_CNT_MAX)
    {
      count++;
    }
  else
    {
      transition_state(red_s);
      count = 0;
    }

  return;
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

/* Test that current state is red_s after one tick after init */
void Test_traffic_light_tick_init(CuTest *tc)
{
  init_fsm();

  traffic_light_tick();

  enum fsm_states_e current_expected = red_s;
  enum fsm_states_e current_actual = fsm_context.state_current;

  CuAssertIntEquals(tc, current_expected, current_actual);
}

/* Test that current state is green_s after the appropriate number of ticks */
void Test_traffic_light_tick_green(CuTest *tc)
{
  init_fsm();

  traffic_light_tick();
  for (uint8_t i = 0; i < RED_CNT_MAX; i++)
    {
      traffic_light_tick();
    }

  enum fsm_states_e current_expected = green_s;
  enum fsm_states_e current_actual = fsm_context.state_current;

  CuAssertIntEquals(tc, current_expected, current_actual);
}

/* Test that current state is yellow_s after the appropriate number of ticks */
void Test_traffic_light_tick_yellow(CuTest *tc)
{
  init_fsm();

  traffic_light_tick();
  for (uint8_t i = 0; i < RED_CNT_MAX + GREEN_CNT_MAX; i++)
    {
      traffic_light_tick();
    }

  enum fsm_states_e current_expected = yellow_s;
  enum fsm_states_e current_actual = fsm_context.state_current;

  CuAssertIntEquals(tc, current_expected, current_actual);
}

/* Test that current state is red_s after the appropriate number of ticks */
void Test_traffic_light_tick_red(CuTest *tc)
{
  init_fsm();

  traffic_light_tick();
  for (uint8_t i = 0; i < RED_CNT_MAX + GREEN_CNT_MAX + YELLOW_CNT_MAX; i++)
    {
      traffic_light_tick();
    }

  enum fsm_states_e current_expected = red_s;
  enum fsm_states_e current_actual = fsm_context.state_current;

  CuAssertIntEquals(tc, current_expected, current_actual);
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
  SUITE_ADD_TEST(suite, Test_traffic_light_tick_init);
  SUITE_ADD_TEST(suite, Test_traffic_light_tick_green);
  SUITE_ADD_TEST(suite, Test_traffic_light_tick_yellow);
  SUITE_ADD_TEST(suite, Test_traffic_light_tick_red);
  return suite;
}
