
/*

NOTE: THIS HEADER FILE IS PRECOMPILED AND AUTOMATICALLY INCLUDED IN ALL SOURCE FILES

*/

#ifndef INC_COMMON_INCLUDE_H
#define INC_COMMON_INCLUDE_H

#include <SDL.h>

#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glext.h>

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define deg2rad(x) ((x) * M_PI / 180.0)
#define rad2deg(x) ((x) * 180.0 / M_PI)

// Degrees versions of trigonometric functions
#define d_sin(x) sin(deg2rad(x))
#define d_cos(x) cos(deg2rad(x))
#define d_tan(x) tan(deg2rad(x))



#include "globals.h"

#endif /* INC_COMMON_INCLUDE_H */
