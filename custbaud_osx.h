/*
 * custbaud_osx.h
 *
 * Custom baud rate support for OSX.
 *
 * by Joe Merten (https://github.com/Joe-Merten www.jme.de)
 *
 * ATTENTION: OSX specific stuff!
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */

#ifndef CUSTBAUD_OSX_H
#define CUSTBAUD_OSX_H

#include <termios.h>

/***************************************************************************/

/* OSX termios.h unfortunately just provides constants for baudrates
 * up to 230k, so we add the missing constants here. Regardless, that
 * most of the high baudrates needs special handling (implementation in
 * tcsetattr_custom()), we want to provide the values here to have them
 * available for term_baud_up()/down().
 */

#if defined(HIGH_BAUD)

#ifndef B460800
#define B460800   460800
#endif
#ifndef B500000
#define B500000   500000
#endif
#ifndef B576000
#define B576000   576000
#endif
#ifndef B921600
#define B921600   921600
#endif
#ifndef B1000000
#define B1000000 1000000
#endif
#ifndef B1152000
#define B1152000 1152000
#endif
#ifndef B1500000
#define B1500000 1500000
#endif
#ifndef B2000000
#define B2000000 2000000
#endif
#ifndef B2500000
#define B2500000 2500000
#endif
#ifndef B3000000
#define B3000000 3000000
#endif
#ifndef B3500000
#define B3500000 3500000
#endif
#ifndef B4000000
#define B4000000 4000000
#endif

#endif /* HIGH_BAUD */

/***************************************************************************/

int cfsetospeed_custom(struct termios *tiop, int speed);
int cfsetispeed_custom(struct termios *tiop, int speed);
int cfgetospeed_custom(struct termios *tiop);
int cfgetispeed_custom(struct termios *tiop);

/***************************************************************************/

/* Replace tcsetattr function with our osx specific one */
#define tcsetattr tcsetattr_custom
int tcsetattr_custom(int fd, int optional_actions, const struct termios *tiop);

/***************************************************************************/

#endif /* CUSTBAUD_OSX_H */
