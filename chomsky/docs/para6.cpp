// Esport Language (PaRa), first experiments
// This is a rapid prototype for planning Pasigraphy Rhapsody (Paszigráfia Rapszódia, PaRa)
//
// para6.cpp
//
// Copyright (C) 2019 Norbert Bátfai, nbatfa@gmail.com, batfai.norbert@inf.unideb.hu
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
// Version history
//
// Initial hack
//
// g++ para6.cpp -o para -lboost_system -lGL -lGLU -lglut
//./para 3:2:1:1:0:3:2:1:0:2:0:2:1:1:0:3:3:0:2:0:1:1:0:1:0:1:0:1:0:2:2:0:1:1:1:3:2:1:0:2:0:2:1:1:1:2:3:0:1:1:1:1:0:3:3:0:1:0:2:1:0:1:0:2:2:0:0:0:1:3:1:0:1:3:2:1:0:2:0:3:3:0:1:0:2:1:0
//

#include <iostream>
#include <vector>
#include "boost/tokenizer.hpp"
#include <GL/glut.h>
#include <GL/freeglut.h>
//#include <string.h>

class PaRaCube
{
public:
        GLfloat rotx = 0.0f;
        GLfloat roty = 0.0f;
        GLfloat rotz = 0.0f;
        int nn[6]  = {1,2,3,4,8,10};
        std::vector<int> cc[6];
};

int index = 0;
bool transp {false};
GLdouble fovy = 70;
int w = 640;
int h = 480;

std::vector<PaRaCube> cubeLetters;

void drawPaRaCube ( int idx )
{

        glPushMatrix();

        int d = cubeLetters.size() /2 ;
        glTranslatef ( ( idx-d ) *2.5f, 0.0f, 0.0f );

        glRotatef ( cubeLetters[idx].rotx, 1.0f, 0.0f, 0.0f );
        glRotatef ( cubeLetters[idx].roty, 0.0f, 1.0f, 0.0f );
        glRotatef ( cubeLetters[idx].rotz, 0.0f, 0.0f, 1.0f );

        glBegin ( GL_QUADS );

        glColor3f ( 0.0f, .20f, 0.824f );

        glVertex3f ( -1.0f, 1.0f, 1.0f );
        glVertex3f ( 1.0f, 1.0f, 1.0f );
        glVertex3f ( 1.0f,-1.0f, 1.0f );
        glVertex3f ( -1.0f,-1.0f, 1.0f );

        glVertex3f ( 1.0f, 1.0f, 1.0f );
        glVertex3f ( 1.0f, 1.0f,-1.0f );
        glVertex3f ( 1.0f,-1.0f,-1.0f );
        glVertex3f ( 1.0f,-1.0f, 1.0f );

        glVertex3f ( -1.0f, 1.0f, 1.0f );
        glVertex3f ( -1.0f, 1.0f,-1.0f );
        glVertex3f ( 1.0f, 1.0f,-1.0f );
        glVertex3f ( 1.0f, 1.0f, 1.0f );

        glVertex3f ( -1.0f, 1.0f, 1.0f );
        glVertex3f ( -1.0f, 1.0f,-1.0f );
        glVertex3f ( -1.0f,-1.0f,-1.0f );
        glVertex3f ( -1.0f,-1.0f, 1.0f );

        glVertex3f ( -1.0f, 1.0f,-1.0f );
        glVertex3f ( 1.0f, 1.0f,-1.0f );
        glVertex3f ( 1.0f,-1.0f,-1.0f );
        glVertex3f ( -1.0f,-1.0f,-1.0f );

        glVertex3f ( -1.0f,-1.0f, 1.0f );
        glVertex3f ( 1.0f,-1.0f, 1.0f );
        glVertex3f ( 1.0f,-1.0f,-1.0f );
        glVertex3f ( -1.0f,-1.0f,-1.0f );

        glEnd();

        glBegin ( GL_LINES );
        glColor3f ( .9188f, 0.209f, 0.6190f );

        for ( int i=0; i<=cubeLetters[idx].nn[0]; i++ ) {

                glVertex3f ( -1.0f, 1.0f-i* ( 2.0/cubeLetters[idx].nn[0] ), 1.005f );
                glVertex3f ( 1.0f, 1.0f-i* ( 2.0/cubeLetters[idx].nn[0] ), 1.005f );
        }
        for ( int i=0; i<=cubeLetters[idx].nn[0]; i++ ) {

                glVertex3f ( 1.0f-i* ( 2.0/cubeLetters[idx].nn[0] ), 1.0f , 1.005f );
                glVertex3f ( 1.0f-i* ( 2.0/cubeLetters[idx].nn[0] ), -1.0f , 1.005f );

        }
        glEnd();


        for ( int i {0}; i<cubeLetters[idx].cc[0].size() /2; ++i ) {
                glBegin ( GL_QUADS );

                glColor3f ( .30f, .13522f, .13350f );

                glVertex3f ( 1.0f- ( cubeLetters[idx].cc[0][2*i]+1 ) * ( 2.0/cubeLetters[idx].nn[0] ),
                             1.0f- ( cubeLetters[idx].cc[0][2*i+1]+1 ) * ( 2.0/cubeLetters[idx].nn[0] ), 1.002f );
                glVertex3f ( 1.0f-cubeLetters[idx].cc[0][2*i]* ( 2.0/cubeLetters[idx].nn[0] ),
                             1.0f- ( cubeLetters[idx].cc[0][2*i+1]+1 ) * ( 2.0/cubeLetters[idx].nn[0] ), 1.002f );
                glVertex3f ( 1.0f-cubeLetters[idx].cc[0][2*i]* ( 2.0/cubeLetters[idx].nn[0] ),
                             1.0f-cubeLetters[idx].cc[0][2*i+1]* ( 2.0/cubeLetters[idx].nn[0] ), 1.002f );
                glVertex3f ( 1.0f- ( cubeLetters[idx].cc[0][2*i]+1 ) * ( 2.0/cubeLetters[idx].nn[0] ),
                             1.0f-cubeLetters[idx].cc[0][2*i+1]* ( 2.0/cubeLetters[idx].nn[0] ), 1.002f );

                glEnd();
        }


        glBegin ( GL_LINES );
        glColor3f ( .6188f, 0.620f, 0.610f );

        for ( int i=0; i<=cubeLetters[idx].nn[1]; i++ ) {

                glVertex3f ( 1.005f, 1.0f-i* ( 2.0/cubeLetters[idx].nn[1] ), 1.0f );
                glVertex3f ( 1.005f, 1.0f-i* ( 2.0/cubeLetters[idx].nn[1] ), -1.0f );
        }
        for ( int i=0; i<=cubeLetters[idx].nn[1]; i++ ) {

                glVertex3f ( 1.005f, 1.0f , 1.0f-i* ( 2.0/cubeLetters[idx].nn[1] ) );
                glVertex3f ( 1.005f, -1.0f , 1.0f-i* ( 2.0/cubeLetters[idx].nn[1] ) );

        }
        glEnd();

        for ( int i {0}; i<cubeLetters[idx].cc[1].size() /2; ++i ) {
                glBegin ( GL_QUADS );

                glColor3f ( 0.1115f, .129f, .812f );

                glVertex3f ( 1.002f, 1.0f-cubeLetters[idx].cc[1][2*i]* ( 2.0/cubeLetters[idx].nn[1] ),
                             1.0f- ( cubeLetters[idx].cc[1][2*i+1]+1 ) * ( 2.0/cubeLetters[idx].nn[1] ) );
                glVertex3f ( 1.002f, 1.0f-cubeLetters[idx].cc[1][2*i]* ( 2.0/cubeLetters[idx].nn[1] ),
                             1.0f-cubeLetters[idx].cc[1][2*i+1]* ( 2.0/cubeLetters[idx].nn[1] ) );
                glVertex3f ( 1.002f, 1.0f- ( cubeLetters[idx].cc[1][2*i]+1 ) * ( 2.0/cubeLetters[idx].nn[1] ),
                             1.0f-cubeLetters[idx].cc[1][2*i+1]* ( 2.0/cubeLetters[idx].nn[1] ) );
                glVertex3f ( 1.002f, 1.0f- ( cubeLetters[idx].cc[1][2*i]+1 ) * ( 2.0/cubeLetters[idx].nn[1] ),
                             1.0f- ( cubeLetters[idx].cc[1][2*i+1]+1 ) * ( 2.0/cubeLetters[idx].nn[1] ) );


                glEnd();
        }

        glBegin ( GL_LINES );
        glColor3f ( .184f, 0.429f, 0.1490f );

        for ( int i=0; i<=cubeLetters[idx].nn[2]; i++ ) {

                glVertex3f ( -1.0f, 1.005f , 1.0f-i* ( 2.0/cubeLetters[idx].nn[2] ) );
                glVertex3f ( 1.0f, 1.005f , 1.0f-i* ( 2.0/cubeLetters[idx].nn[2] ) );
        }
        for ( int i=0; i<=cubeLetters[idx].nn[2]; i++ ) {

                glVertex3f ( 1.0f-i* ( 2.0/cubeLetters[idx].nn[2] ), 1.005f, -1.0f );
                glVertex3f ( 1.0f-i* ( 2.0/cubeLetters[idx].nn[2] ), 1.005f, 1.0f );

        }
        glEnd();

        for ( int i {0}; i<cubeLetters[idx].cc[2].size() /2; ++i ) {
                glBegin ( GL_QUADS );

                glColor3f ( .430f, .82f, .1450f );

                glVertex3f ( 1.0f-cubeLetters[idx].cc[2][2*i]* ( 2.0/cubeLetters[idx].nn[2] ),
                             1.002f , 1.0f-cubeLetters[idx].cc[2][2*i+1]* ( 2.0/cubeLetters[idx].nn[2] ) );
                glVertex3f ( 1.0f- ( cubeLetters[idx].cc[2][2*i]+1 ) * ( 2.0/cubeLetters[idx].nn[2] ),
                             1.002f , 1.0f-cubeLetters[idx].cc[2][2*i+1]* ( 2.0/cubeLetters[idx].nn[2] ) );
                glVertex3f ( 1.0f- ( cubeLetters[idx].cc[2][2*i]+1 ) * ( 2.0/cubeLetters[idx].nn[2] ),
                             1.002f , 1.0f- ( cubeLetters[idx].cc[2][2*i+1]+1 ) * ( 2.0/cubeLetters[idx].nn[2] ) );
                glVertex3f ( 1.0f-cubeLetters[idx].cc[2][2*i]* ( 2.0/cubeLetters[idx].nn[2] ),
                             1.002f , 1.0f- ( cubeLetters[idx].cc[2][2*i+1]+1 ) * ( 2.0/cubeLetters[idx].nn[2] ) );

                glEnd();
        }

        glBegin ( GL_LINES );
        glColor3f ( .88f, 0.2509f, 0.590f );

        for ( int i=0; i<=cubeLetters[idx].nn[3]; i++ ) {

                glVertex3f ( -1.005f, 1.0f-i* ( 2.0/cubeLetters[idx].nn[3] ), 1.0f );
                glVertex3f ( -1.005f, 1.0f-i* ( 2.0/cubeLetters[idx].nn[3] ), -1.0f );
        }
        for ( int i=0; i<=cubeLetters[idx].nn[3]; i++ ) {

                glVertex3f ( -1.005f, 1.0f , 1.0f-i* ( 2.0/cubeLetters[idx].nn[3] ) );
                glVertex3f ( -1.005f, -1.0f , 1.0f-i* ( 2.0/cubeLetters[idx].nn[3] ) );

        }
        glEnd();

        for ( int i {0}; i<cubeLetters[idx].cc[3].size() /2; ++i ) {
                glBegin ( GL_QUADS );
                glColor3f ( .780f, .782f, .150f );

                glVertex3f ( -1.002f, 1.0f- ( cubeLetters[idx].cc[3][2*i]+1 ) * ( 2.0/cubeLetters[idx].nn[3] ),
                             1.0f-cubeLetters[idx].cc[3][2*i+1]* ( 2.0/cubeLetters[idx].nn[3] ) );
                glVertex3f ( -1.002f, 1.0f-cubeLetters[idx].cc[3][2*i]* ( 2.0/cubeLetters[idx].nn[3] ),
                             1.0f-cubeLetters[idx].cc[3][2*i+1]* ( 2.0/cubeLetters[idx].nn[3] ) );
                glVertex3f ( -1.002f, 1.0f-cubeLetters[idx].cc[3][2*i]* ( 2.0/cubeLetters[idx].nn[3] ),
                             1.0f- ( cubeLetters[idx].cc[3][2*i+1]+1 ) * ( 2.0/cubeLetters[idx].nn[3] ) );
                glVertex3f ( -1.002f, 1.0f- ( cubeLetters[idx].cc[3][2*i]+1 ) * ( 2.0/cubeLetters[idx].nn[3] ),
                             1.0f- ( cubeLetters[idx].cc[3][2*i+1]+1 ) * ( 2.0/cubeLetters[idx].nn[3] ) );

                glEnd();
        }

        glBegin ( GL_LINES );
        glColor3f ( .6188f, 0.209f, 0.1690f );

        for ( int i=0; i<=cubeLetters[idx].nn[4]; i++ ) {

                glVertex3f ( -1.0f, 1.0f-i* ( 2.0/cubeLetters[idx].nn[4] ), -1.005f );
                glVertex3f ( 1.0f, 1.0f-i* ( 2.0/cubeLetters[idx].nn[4] ), -1.005f );
        }
        for ( int i=0; i<=cubeLetters[idx].nn[4]; i++ ) {

                glVertex3f ( 1.0f-i* ( 2.0/cubeLetters[idx].nn[4] ), 1.0f , -1.005f );
                glVertex3f ( 1.0f-i* ( 2.0/cubeLetters[idx].nn[4] ), -1.0f , -1.005f );

        }
        glEnd();

        for ( int i {0}; i<cubeLetters[idx].cc[4].size() /2; ++i ) {
                glBegin ( GL_QUADS );
                glColor3f ( .64f, 0.915f, 0.120f );

                glVertex3f ( 1.0f- ( cubeLetters[idx].cc[4][2*i]+1 ) * ( 2.0/cubeLetters[idx].nn[4] ),
                             1.0f-cubeLetters[idx].cc[4][2*i+1]* ( 2.0/cubeLetters[idx].nn[4] ), -1.002f );
                glVertex3f ( 1.0f-cubeLetters[idx].cc[4][2*i]* ( 2.0/cubeLetters[idx].nn[4] ),
                             1.0f-cubeLetters[idx].cc[4][2*i+1]* ( 2.0/cubeLetters[idx].nn[4] ), -1.002f );
                glVertex3f ( 1.0f-cubeLetters[idx].cc[4][2*i]* ( 2.0/cubeLetters[idx].nn[4] ),
                             1.0f- ( cubeLetters[idx].cc[4][2*i+1]+1 ) * ( 2.0/cubeLetters[idx].nn[4] ), -1.002f );
                glVertex3f ( 1.0f- ( cubeLetters[idx].cc[4][2*i]+1 ) * ( 2.0/cubeLetters[idx].nn[4] ),
                             1.0f- ( cubeLetters[idx].cc[4][2*i+1]+1 ) * ( 2.0/cubeLetters[idx].nn[4] ), -1.002f );

                glEnd();
        }

        glBegin ( GL_LINES );
        glColor3f ( .188f, 0.55209f, 0.170f );

        for ( int i=0; i<=cubeLetters[idx].nn[5]; i++ ) {

                glVertex3f ( -1.0f, -1.005f , 1.0f-i* ( 2.0/cubeLetters[idx].nn[5] ) );
                glVertex3f ( 1.0f, -1.005f , 1.0f-i* ( 2.0/cubeLetters[idx].nn[5] ) );
        }
        for ( int i=0; i<=cubeLetters[idx].nn[5]; i++ ) {

                glVertex3f ( 1.0f-i* ( 2.0/cubeLetters[idx].nn[5] ), -1.005f , 1.0f );
                glVertex3f ( 1.0f-i* ( 2.0/cubeLetters[idx].nn[5] ), -1.005f , -1.0f );

        }
        glEnd();

        for ( int i {0}; i<cubeLetters[idx].cc[5].size() /2; ++i ) {
                glBegin ( GL_QUADS );
                glColor3f ( .171f, .18f, .756f );

                glVertex3f ( 1.0f-cubeLetters[idx].cc[5][2*i]* ( 2.0/cubeLetters[idx].nn[5] ),
                             -1.002f , 1.0f-cubeLetters[idx].cc[5][2*i+1]* ( 2.0/cubeLetters[idx].nn[5] ) );
                glVertex3f ( 1.0f-cubeLetters[idx].cc[5][2*i]* ( 2.0/cubeLetters[idx].nn[5] ),
                             -1.002f , 1.0f- ( cubeLetters[idx].cc[5][2*i+1]+1 ) * ( 2.0/cubeLetters[idx].nn[5] ) );
                glVertex3f ( 1.0f- ( cubeLetters[idx].cc[5][2*i]+1 ) * ( 2.0/cubeLetters[idx].nn[5] ),
                             -1.002f , 1.0f- ( cubeLetters[idx].cc[5][2*i+1]+1 ) * ( 2.0/cubeLetters[idx].nn[5] ) );
                glVertex3f ( 1.0f- ( cubeLetters[idx].cc[5][2*i]+1 ) * ( 2.0/cubeLetters[idx].nn[5] ),
                             -1.002f , 1.0f-cubeLetters[idx].cc[5][2*i+1]* ( 2.0/cubeLetters[idx].nn[5] ) );

                glEnd();
        }

        glPopMatrix();

}
void displayText( float x, float y, int r, int g, int b, char *str ) 
   {
    char*c;

    glColor3f( r, g, b );
    glRasterPos2f( x, y );
     for(c=str; *c!=' '; c++ ) {
     glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, *c );
     }
    }

void draw ( void )
{
        glClearColor ( 1.0f, 1.0f, 1.0f, 1.0f );

        if ( transp )
                glDisable ( GL_DEPTH_TEST );
        else
                glEnable ( GL_DEPTH_TEST );

        glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        glMatrixMode ( GL_MODELVIEW );
        glLoadIdentity();
        gluLookAt ( 0.0f, 3.0f, 6.0f ,0.0f ,0.0f ,0.0f ,0.0f ,1.0f ,0.0f );

        for ( int i {0}; i<cubeLetters.size(); ++i )
                if ( i == index ) {
                        drawPaRaCube ( i );
                } else {
                        drawPaRaCube ( i );
                }

	displayText(100, 150,0,0,0, "q/e for z axis");
	displayText(150, 200,0,0,0, "w/s for x axis");
	displayText(150, 200,0,0,0, "a/d for y axis");
	displayText(200, 200,0,0,0, "+/- to zoom in/out");
	
        glutSwapBuffers();
}

void keyboard ( unsigned char key, int x, int y )
{
        if ( key == '0' ) {
                index=0;
        } else if ( key == '1' ) {
                index=1;
        } else if ( key == '2' ) {
                index=2;
        } else if ( key == '3' ) {
                index=3;
        } else if ( key == '4' ) {
                index=4;
        } else if ( key == '5' ) {
                index=5;
        } else if ( key == '6' ) {
                index=6;
        } else if ( key == 't' ) {
                transp = !transp;
        } else if ( key == '-' ) {
                ++fovy;

                glMatrixMode ( GL_PROJECTION );
                glLoadIdentity();
                gluPerspective ( fovy, ( float ) w/ ( float ) h, .1f, 1000.0f );
                glMatrixMode ( GL_MODELVIEW );

        } else if ( key == '+' ) {
                --fovy;

                glMatrixMode ( GL_PROJECTION );
                glLoadIdentity();
                gluPerspective ( fovy, ( float ) w/ ( float ) h, .1f, 1000.0f );
                glMatrixMode ( GL_MODELVIEW );

        }
	else if( key == 'w' ) {
                cubeLetters[index].rotx += 25.0;
        } else if ( key == 's') {
                cubeLetters[index].rotx -= 5.0;
        } else if ( key == 'd' ) {
                cubeLetters[index].roty -= 5.0;
        } else if ( key == 'a' ) {
                cubeLetters[index].roty += 25.0;
        } else if ( key == 'q' ) {
                cubeLetters[index].rotz += 25.0;
        } else if ( key == 'e' ) {
                cubeLetters[index].rotz -= 5.0;
        }

        glutPostRedisplay();

}

void skeyboard ( int key, int x, int y )
{
        if ( key == GLUT_KEY_UP ) {
                cubeLetters[index].rotx += 25.0;
        } else if ( key == GLUT_KEY_DOWN ) {
                cubeLetters[index].rotx -= 5.0;
        } else if ( key == GLUT_KEY_RIGHT ) {
                cubeLetters[index].roty -= 5.0;
        } else if ( key == GLUT_KEY_LEFT ) {
                cubeLetters[index].roty += 25.0;
        } else if ( key == GLUT_KEY_PAGE_UP ) {
                cubeLetters[index].rotz += 25.0;
        } else if ( key == GLUT_KEY_PAGE_DOWN ) {
                cubeLetters[index].rotz -= 5.0;
        }

        glutPostRedisplay();
}

void reshape ( int width, int height )
{
        w = width;
        h = height;
        glMatrixMode ( GL_PROJECTION );
        glLoadIdentity();
        gluPerspective ( fovy, ( float ) w/ ( float ) h, .1f, 1000.0f );
        glViewport ( 0, 0, w, h );
        glMatrixMode ( GL_MODELVIEW );

}
void drawStrokeText(char*string,int x,int y,int z)
{
	  char *c;
	  glPushMatrix();
	  glTranslatef(x, y+8,z);
	 // glScalef(0.09f,-0.08f,z);
  
	  for (c=string; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  }
	  glPopMatrix();
}

void render(void)
{ 
	glClear(GL_COLOR_BUFFER_BIT); 
	glLoadIdentity();
 
	glColor3f(1,1,255);
	drawStrokeText("Osama Hosam's OpenGL Tutorials",200,200,0);

	glutSwapBuffers(); 
} 



    

int
main ( int argc, char *argv[] )
{

        for ( int i {1}; i<argc; ++i ) {
                std::string s ( argv[i] );
                std::vector<int> nums;
                boost::char_separator<char> separator ( ":" );
                boost::tokenizer<boost::char_separator<char>> items ( s, separator );

                for ( const auto& token : items )
                        nums.push_back ( atoi ( token.c_str() ) );

                int ii=0;
                for ( int cui {0}; cui<nums[0]; ++cui ) {
                        PaRaCube prc;
                        for ( int s {0}; s<6; ++s ) {
                                ++ii;
                                prc.nn[s]=nums[ii];
                                ++ii;
                                int noc = nums[ii];
                                for ( int coi {0}; coi<noc; ++coi ) {
                                        ++ii;
                                        prc.cc[s].push_back ( nums[ii] );
                                        ++ii;
                                        prc.cc[s].push_back ( nums[ii] );
                                }
                        }

                        cubeLetters.push_back ( prc );

                }

        }

        glutInit ( &argc, argv );
        glutInitWindowSize ( w, h );
        glutInitWindowPosition (
                ( glutGet ( GLUT_SCREEN_WIDTH )-w ) /2,
                ( glutGet ( GLUT_SCREEN_HEIGHT )-h ) /2 );
        glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
        glutCreateWindow ( "Pasigraphy Rhapsody, para6, exp2" );
        glutReshapeFunc ( reshape );
        glutDisplayFunc ( draw );
	//glutIdleFunc(draw);
        glutKeyboardFunc ( keyboard );
        glutSpecialFunc ( skeyboard );

	glutMainLoop();
        return 0;
}

