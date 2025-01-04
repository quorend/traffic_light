#ifndef __TARG_H__
#define __TARG_H__

/*
 * This file declares the interface for target-specific functions.
 */

#include <stdint.h>

/*
 * void wait(uint32_t msec)
 *
 * Block for msec microseconds before continuing.
 */
void wait(uint32_t msec);

#endif /* __TARG_H__ */
