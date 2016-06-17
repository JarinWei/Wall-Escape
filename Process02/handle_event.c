
#include "map.h"

static void handle_keydown( SDL_Event *event );
static void handle_keyup( SDL_Event *event );

void handle_event( SDL_Event *event )
{
    switch( event->type )
    {
        case SDL_QUIT:
            g_exit_flag = 1;
            break;

        case SDL_KEYDOWN:
            handle_keydown( event );
            break;

        case SDL_KEYUP:
            handle_keyup( event );
            break;

        case SDL_MOUSEMOTION:

            g_ego_th += -0.5 * (double)event->motion.xrel;
            while( g_ego_th >= 360.0 ) g_ego_th -= 360.0;
            while( g_ego_th < 0.0 ) g_ego_th += 360.0;

            g_ego_phi += -0.25 * (double)event->motion.yrel;
            if( g_ego_phi > 90.0 ) g_ego_phi = 90.0;
            else if( g_ego_phi < -90.0 ) g_ego_phi = -90.0;

            break;

        default:
            break;
    }
}

static void handle_keydown( SDL_Event *event )
{
    switch( event->key.keysym.sym )
    {
        case SDLK_ESCAPE:
            g_exit_flag = 1;
            break;

        // toggle cursor state
        case SDLK_LALT:
            SDL_ShowCursor( SDL_ShowCursor( SDL_QUERY ) == SDL_ENABLE ? SDL_DISABLE : SDL_ENABLE );
            SDL_WM_GrabInput( SDL_WM_GrabInput( SDL_GRAB_QUERY ) == SDL_GRAB_ON ?  SDL_GRAB_OFF : SDL_GRAB_ON );
            break;

#define WALKING_SPEED 0.25

        // sidestep left
        case SDLK_LEFT:
        case SDLK_a:
            g_ego_x += WALKING_SPEED * d_cos(g_ego_th+90.0);
            g_ego_y += WALKING_SPEED * d_sin(g_ego_th+90.0);
            break;

        // sidestep right
        case SDLK_RIGHT:
        case SDLK_d:
            g_ego_x += WALKING_SPEED * d_cos(g_ego_th-90.0);
            g_ego_y += WALKING_SPEED * d_sin(g_ego_th-90.0);
            break;

        // walk forward
        case SDLK_UP:
        case SDLK_w:
            g_ego_x += WALKING_SPEED * d_cos(g_ego_th);
            g_ego_y += WALKING_SPEED * d_sin(g_ego_th);
            break;

        // walk backward
        case SDLK_DOWN:
        case SDLK_s:
            g_ego_x += -WALKING_SPEED * d_cos(g_ego_th);
            g_ego_y += -WALKING_SPEED * d_sin(g_ego_th);
            break;

        default:
            break;
    }
}

static void handle_keyup( SDL_Event *event )
{

}
