/*
 * This file defines the target-specific interface functions.
 */

#include "targ.h"

#if defined(_WIN32) || defined(_WIN64) /* Windows */
#include <Windows.h>
#else /* Linux */
#include <unistd.h>
#endif

void wait(uint32_t msec)
{
#if defined(_WIN32) || defined(_WIN64) /* Windows */
  Sleep(msec);
#else /* Linux */
  if (msec < 1000)
    {
      sleep(1);
    }
  else
    {
      sleep(msec / 1000);
    }
#endif

  return;
}
