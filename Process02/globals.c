
/*

GLOBAL VARIABLES

Note: After introducing or changing a global variable in this file, remember we MUST also
introduce or change the prototype in globals.h

*/

SDL_Surface *g_screen = NULL;

uint32_t g_exit_flag = 0;

double
g_ego_x = 1.0 + 0.2,
g_ego_y = 1.0 + 0.2,
g_ego_th = 45.0, // angle in horizontal reference plane
g_ego_phi = 0.0; // angle of elevation

double g_prev_tick, g_curr_tick;

GLuint texture[3];
