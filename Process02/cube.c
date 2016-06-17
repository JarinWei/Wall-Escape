
void cube( void )
{

    glBindTexture( GL_TEXTURE_2D, texture[0] );

    glEnable( GL_CULL_FACE ); // back-face culling (anticlockwise winding for front-face)

    glPushAttrib( GL_TRANSFORM_BIT );

    glMatrixMode( GL_TEXTURE );
    glPushMatrix();
    glScaled( 1.0, 3.0, 1.0 ); // tile texture thrice vertically

    glMatrixMode( GL_MODELVIEW );
    glPushMatrix();
    glScaled( 1.0, 1.0, 3.0 ); // stack "blocks" height thrice vertically

    glBegin( GL_QUADS );

        // If don't put this (i.e. if colour = black) textures appear dark.
        // This is because OpenGL multiplies the texture colour with the "colour" specified by glColor
        // -> this allows tinting etc, without modifying the texture itself.
        glColor3f( 1.0f, 1.0f, 1.0f );

        // back face
        glTexCoord2f( 0.0f, 0.0f ); glVertex3f( 0.0f, 1.0f, 0.0f );
        glTexCoord2f( 1.0f, 0.0f ); glVertex3f( 0.0f, 0.0f, 0.0f );
        glTexCoord2f( 1.0f, 1.0f ); glVertex3f( 0.0f, 0.0f, 1.0f );
        glTexCoord2f( 0.0f, 1.0f ); glVertex3f( 0.0f, 1.0f, 1.0f );

        // front face
        glTexCoord2f( 0.0f, 0.0f ); glVertex3f( 1.0f, 0.0f, 0.0f );
        glTexCoord2f( 1.0f, 0.0f ); glVertex3f( 1.0f, 1.0f, 0.0f );
        glTexCoord2f( 1.0f, 1.0f ); glVertex3f( 1.0f, 1.0f, 1.0f );
        glTexCoord2f( 0.0f, 1.0f ); glVertex3f( 1.0f, 0.0f, 1.0f );

        // left face
        glTexCoord2f( 0.0f, 0.0f ); glVertex3f( 0.0f, 0.0f, 0.0f );
        glTexCoord2f( 1.0f, 0.0f ); glVertex3f( 1.0f, 0.0f, 0.0f );
        glTexCoord2f( 1.0f, 1.0f ); glVertex3f( 1.0f, 0.0f, 1.0f );
        glTexCoord2f( 0.0f, 1.0f ); glVertex3f( 0.0f, 0.0f, 1.0f );

        // right face
        glTexCoord2f( 0.0f, 0.0f ); glVertex3f( 1.0f, 1.0f, 0.0f );
        glTexCoord2f( 1.0f, 0.0f ); glVertex3f( 0.0f, 1.0f, 0.0f );
        glTexCoord2f( 1.0f, 1.0f ); glVertex3f( 0.0f, 1.0f, 1.0f );
        glTexCoord2f( 0.0f, 1.0f ); glVertex3f( 1.0f, 1.0f, 1.0f );

/*
        glColor3f( 1.0f, 1.0f, 1.0f );

        // top & bottom not drawn right now...

        glVertex3f( 0.0f, 0.0f, 0.0f );
        glVertex3f( 0.0f, 0.0f, 0.0f );
        glVertex3f( 0.0f, 0.0f, 0.0f );
        glVertex3f( 0.0f, 0.0f, 0.0f );

        glVertex3f( 0.0f, 0.0f, 0.0f );
        glVertex3f( 0.0f, 0.0f, 0.0f );
        glVertex3f( 0.0f, 0.0f, 0.0f );
        glVertex3f( 0.0f, 0.0f, 0.0f );
*/

    glEnd();

    glPopMatrix(); // GL_MODELVIEW mode

    glMatrixMode( GL_TEXTURE );
    glPopMatrix();

    glPopAttrib();

    glDisable( GL_CULL_FACE );

}
