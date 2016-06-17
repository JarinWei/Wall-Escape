
// This function expects the filename of a 24-bit BMP
// with the usual ordering of bytes in memory (B G R)
GLuint load_texture( char *bmp_name )
{
    SDL_Surface *tex = SDL_LoadBMP( bmp_name );
    if( tex == NULL )
    {
        printf( "Error: unable to load bitmap texture: '%s'.\n", bmp_name );
        return 0;
    }



    // Put the BMP data into OpenGL's expected form for textures
    uint8_t *tex_buf = malloc( tex->w * tex->h * 3 );

    /// i = y-coord, j = x-coord;
    /// Flip the 24-bit BMP into a buffer, and put in RGB form instead of BMP's conventional BGR form
    for( int32_t i = 0; i <= tex->h - 1; i++ )
    for( int32_t j = 0; j <= tex->w - 1; j++ )
    {
        tex_buf[ (i*tex->w + j)*3 + 0 ] = ((uint8_t *)tex->pixels)[ ((tex->w - 1 - i)*tex->w + j)*3 + 2 ]; // R
        tex_buf[ (i*tex->w + j)*3 + 1 ] = ((uint8_t *)tex->pixels)[ ((tex->w - 1 - i)*tex->w + j)*3 + 1 ]; // G
        tex_buf[ (i*tex->w + j)*3 + 2 ] = ((uint8_t *)tex->pixels)[ ((tex->w - 1 - i)*tex->w + j)*3 + 0 ]; // B
    };



    GLuint tex_id; // storage for one texture object

    glGenTextures( 1, &tex_id );
    // glBindTexture: all operations on 2D textures that follow are bound to the texture object tex_id
    glBindTexture( GL_TEXTURE_2D, tex_id );
    glTexImage2D( GL_TEXTURE_2D, 0, 3, tex->w,tex->h, 0, GL_RGB, GL_UNSIGNED_BYTE, tex_buf );

    SDL_FreeSurface( tex ); tex = NULL;
    free( tex_buf ); tex_buf = NULL;

    // Note: these parameters are bound to the texture object in question and must be set
    //       again for each created texture
    //
    // Note_2: The default GL_TEXTURE_MIN_FILTER state is GL_NEAREST_MIPMAP_LINEAR so GL will
    //         consider the texture incomplete as long as you don't create mipmaps.
    //         So a texture without mipmaps will not work if a minification & magnification filter
    //         similar to what follows (without mipmaps) is not specified
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	// Linear Filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);	// Linear Filtering

    // Wrapping (note that GL_REPEAT is the default, but we set it anyway to be sure)
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

    // Enable anisotropic texture filtering
    GLfloat largest_supported_anisotropy;
    glGetFloatv( GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &largest_supported_anisotropy );

    if( largest_supported_anisotropy > 8.0f ) // do not allow more than 8x filtering
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 8.0f );
    else
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, largest_supported_anisotropy );


    return tex_id;



    // NOTE:
    // void glDeleteTextures( GLsizei n, const GLuint *textures )
    // should be used to later delete loaded textures
}
