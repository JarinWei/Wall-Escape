
#include "map.h"

void cube( void );

void render_frame( void )
{
        // DRAWING STARTS HERE

        // Clear colour buffer and depth buffer
        glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
        glClearDepth( 1.0f );
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


        /* note: following matrix is stored in memory in column-major form

        0   1   0   0
        0   0   1   0
        1   0   0   0
        0   0   0   1

        */
        // this matrix is the conversion matrix to more mathematically conventional coordinate orientation
        const double mat[16] =
        {
            0.0,0.0,1.0,0.0,
            1.0,0.0,0.0,0.0,
            0.0,1.0,0.0,0.0,
            0.0,0.0,0.0,1.0
        };

        glMatrixMode( GL_MODELVIEW );
        glLoadMatrixd( mat );

        /* Loading the matrix mat is equivalent to (?? it seems, at least):

        glLoadIdentity();
        glRotated( 90.0, -1.0, 0.0, 0.0 );
        glRotated( 90.0, 0.0, 0.0, -1.0 );

        */

        // Set the camera
        glRotated( -g_ego_phi, 0.0, 1.0, 0.0 );
        glRotated( -(g_ego_th-180.0), 0.0, 0.0, 1.0 );
        glTranslated( -g_ego_x, -g_ego_y, -1.0/2.0 -0.25 );

        // Render the 64 x 64 game map
        for( int32_t i = 0; i <= 63; i++ )
        for( int32_t j = 0; j <= 63; j++ )
        {
            if( get_tile(i,j) == 1 )
            {
                glPushMatrix();

                glTranslated( (GLdouble)i, (GLdouble)j, 0.0 );

                //glCallList( cubeDL );
                cube();

                glPopMatrix();
            }
        };



        // Draw floor & ceiling
        glPushMatrix();

        glScalef( 64.0f, 64.0f, 3.0f ); // z-component determines height (now 3.0 times width of block)

        glBindTexture( GL_TEXTURE_2D, texture[1] );
        glBegin( GL_QUADS );

            // floor
            glColor3f( 1.0f, 1.0f, 1.0f );

            glTexCoord2f( 0.0f, 0.0f );                     glVertex3f( 0.0f, 0.0f, 0.0f );
            glTexCoord2f( 64.0f * 1.0f, 0.0f );             glVertex3f( 1.0f, 0.0f, 0.0f );
            glTexCoord2f( 64.0f * 1.0f, 64.0f * 1.0f );     glVertex3f( 1.0f, 1.0f, 0.0f );
            glTexCoord2f( 0.0f, 64.0f * 1.0f );             glVertex3f( 0.0f, 1.0f, 0.0f );

        glEnd();

        glBindTexture( GL_TEXTURE_2D, texture[2] );
        glBegin( GL_QUADS );

            // ceiling
            glColor3f( 1.0f, 1.0f, 1.0f );

            glTexCoord2f( 0.0f, 0.0f );                     glVertex3f( 0.0f, 0.0f, 1.0f );
            glTexCoord2f( 64.0f * 1.0f, 0.0f );             glVertex3f( 0.0f, 1.0f, 1.0f );
            glTexCoord2f( 64.0f * 1.0f, 64.0f * 1.0f );     glVertex3f( 1.0f, 1.0f, 1.0f );
            glTexCoord2f( 0.0f, 64.0f * 1.0f );             glVertex3f( 1.0f, 0.0f, 1.0f );

        glEnd();

        glPopMatrix();

        // DRAWING ENDS HERE
}
