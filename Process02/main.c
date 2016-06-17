
void init( void );
void handle_event( SDL_Event * );
void cube( void );
void render_frame( void );
GLuint load_texture( char * );

int main( int argc, char **argv )
{
    init();

    // We now have an initialised OpenGL surface in g_screen



    // LOAD TEXTURES
    // GLuint texture[n] defined as global var

    texture[0] = load_texture( "..\\dat\\brick.bmp" );
    texture[1] = load_texture( "..\\dat\\floor.bmp" );
    texture[2] = load_texture( "..\\dat\\ceil.bmp" );

    glEnable( GL_TEXTURE_2D );

    // NOTE:
    // void glDeleteTextures( GLsizei n, const GLuint *textures )
    // should be used to later delete loaded textures

    glBindTexture( GL_TEXTURE_2D, texture[0] );



    // NOTE THIS CODE NEEDS TO BE MOVED, LIST NO. NEEDS TO BE MADE GLOBAL ETC.
    // CREATE THE CUBE DISPLAY LIST
    GLuint cubeDL;
    cubeDL = glGenLists( 1 ); // allocate one display list (returns first id number only since they are contiguous)

    glNewList( cubeDL, GL_COMPILE );
        cube();
    glEndList();

    // glDeleteLists( start_id, range ) deletes a contiguous range of lists



    // Message processing loop
    SDL_Event event;
    char caption_buffer[64];

    while( g_exit_flag == 0 )
    {
        SDL_WaitEvent( &event );

        do {

            handle_event( &event );

        } while( SDL_PollEvent( &event ) );


        render_frame();


        // Finally, update the screen
        SDL_GL_SwapBuffers();

        // "Frames per second" (not that good due to high granularity timer, etc)
        g_prev_tick = g_curr_tick;
        g_curr_tick = (double)SDL_GetTicks();

        // Update the window's caption
        sprintf( caption_buffer, "%.0f fps, x = %.1f, y = %.1f, th = %.1f, phi = %.1f", 1000.0/(g_curr_tick-g_prev_tick), g_ego_x, g_ego_y, g_ego_th, g_ego_phi );
        SDL_WM_SetCaption( caption_buffer, NULL );
    }

    return 0;
}
