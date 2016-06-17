
// Make sure SCREEN_W and SCREEN_H are of a floating point type, because they will be used
// to calculate the aspect ratio later and are not individually cast! If they're of
// integer type, this will give SCREEN_W / SCREEN_H = 1 when W >= H, or SCREEN_W / SCREEN_H = 0
// when W < H, which will be a bug.
#define SCREEN_W 1024.0
#define SCREEN_H 768.0
#define SCREEN_FULLSCREEN 0

// Only returns on success, if fails to initialise, then calls exit function
void init( void )
{
    // ********************************************************************************
    // * Initialise SDL
    // ********************************************************************************
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) != 0 )
    {
        printf( "SDL_Init error: %s\n", SDL_GetError() );
        exit( 1 );
    }
    atexit( SDL_Quit );

    // OpenGL attributes
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 32 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    SDL_WM_SetCaption( "Druidia", NULL );
#if SCREEN_FULLSCREEN == 1
    g_screen = SDL_SetVideoMode( SCREEN_W,SCREEN_H, 32, SDL_HWSURFACE | SDL_OPENGL | SDL_FULLSCREEN );
#else
    g_screen = SDL_SetVideoMode( SCREEN_W,SCREEN_H, 32, SDL_HWSURFACE | SDL_OPENGL );
#endif
    // NOTE: SDL_DOUBLEBUF flag not necessary when set SDL_GLDOUBLEBUFFER via SDL_GL_SetAttribute

    if( g_screen == NULL )
    {
        printf( "SDL_SetVideoMode error: '%s'.\n", SDL_GetError() );
        exit( 1 );
    }

    SDL_EnableKeyRepeat( 1, 4 ); // (delay, interval) in milliseconds (ms = thousandth of s)

    SDL_WM_GrabInput( SDL_GRAB_ON );
    SDL_ShowCursor( SDL_DISABLE );

    // ********************************************************************************
    // * Initialise OpenGL
    // ********************************************************************************
    glViewport( 0,0, SCREEN_W,SCREEN_H );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 45.0f, (GLfloat)(SCREEN_W/SCREEN_H), 0.01f, 100.0f ); // set the viewing volume

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );

    // Additional "beauty" settings
    glShadeModel( GL_SMOOTH );
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST ); // really nice perspective calculations
}
