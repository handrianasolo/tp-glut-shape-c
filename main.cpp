/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

float angle1 = 0.0f, angle2 = 0.0f, angle3 = 0.0f, angle4 = 0.0f;
float red = 1.0f , green = 1.0f, blue = 1.0f;
float x=0.0f, y=0.0f, z=0.0f;

void Keyboard(int key, int x, int y) {
	switch(key) {
        case GLUT_KEY_UP :
                angle1+=(cos(45.0)+sin(45.0));
                break;
        case GLUT_KEY_DOWN :
                angle2+=(cos(45.0)+sin(45.0));
                break;
        case GLUT_KEY_LEFT :
                angle3+=(cos(45.0)+sin(45.0));
                break;
        case GLUT_KEY_RIGHT :
                angle4+=(cos(45.0)+sin(45.0));
                break;
        case GLUT_KEY_F12 :
                exit(0);
                break;
        default :
                cout << " Autre Touche Speciale\n ";
                break;
	}
}

void Tete(){
    // Tete au carrée
    glPushMatrix();
    glColor3d(0,green,0);
    glLineWidth(4);
    glBegin(GL_LINES);
        glVertex3f( 0.5f, 1.0f, 0.0f);
        glVertex3f( 1.5f, 1.0f, 0.0f);

        glVertex3f( 0.5f, 1.0f, 0.0f);
        glVertex3f( 0.5f, 2.0f, 0.0f);

        glVertex3f( 1.5f, 1.0f, 0.0f);
        glVertex3f( 1.5f, 2.0f, 0.0f);

        glVertex3f( 1.5f, 2.0f, 0.0f);
        glVertex3f( 0.5f, 2.0f, 0.0f);
    glEnd();
    glPopMatrix();
}

void Cou(){
    // Cou
    glPushMatrix();
    glColor3f(0,0,blue);
    glLineWidth(4);
    glBegin(GL_LINES);
		glVertex3f( 1.0f, 0.0f, 0.0f);
		glVertex3f( 1.0f, 1.0f, 0.0f);
	glEnd();
	glPopMatrix();
}

void Corps(){
    // Corps
    glPushMatrix();
    glColor3f(0,0,blue);
    glLineWidth(4);
    glBegin(GL_LINES);
		glVertex3f( 1.0f, 0.0f, 0.0f);
		glVertex3f( 1.0f, -2.0f, 0.0f);
	glEnd();
	glPopMatrix();
}

void Bras_gauche(){
    // Bras Gauche
    glPushMatrix();
    glRotatef(angle1, 2.0f, 0.0f, 0.0f);
    glColor3f(0,0,blue);
    glLineWidth(4);
	glBegin(GL_LINES);
		glVertex3f( 1.0f, 0.0f, 0.0f);
		glVertex3f( 0.0f, 1.0f, 0.0f);
	glEnd();

	glPopMatrix();

}

void Bras_droit(){
    // Bras droit
    glPushMatrix();
	glRotatef(angle2, 1.0f, 0.0f, 0.0f);
	glColor3f(0,0,blue);
    glLineWidth(4);
    glBegin(GL_LINES);
		glVertex3f( 1.0f, 0.0f, 0.0f);
		glVertex3f( 2.0f, 1.0f, 0.0f);
	glEnd();

	glPopMatrix();
}

void Hanche(){
    // Hanche
    glPushMatrix();
    glColor3f(0,0,blue);
    glLineWidth(4);
    glBegin(GL_LINES);
		glVertex3f( 0.5f, -2.0f, 0.0f);
		glVertex3f( 1.5f, -2.0f, 0.0f);
	glEnd();
	glPopMatrix();
}

void Cuisse_gauche(){
    // Cuisse Gauche
    glPushMatrix();
    glTranslatef(2.5f,0.0f,0.0f);
	glRotatef(angle4, -2.0f, -2.0f, 0.0f);
    glColor3f(0,0,blue);
    glLineWidth(4);
	glBegin(GL_LINES);
        glVertex3f( -2.0f, -2.0f, 0.0f);
		glVertex3f( -2.0f, -3.0f, 0.0f);
	glEnd();
    glPopMatrix();
}

void Jambe_gauche(){
	// Jambe Gauche
	glPushMatrix();
    glTranslatef(2.5f,0.0f,0.0f);
	glRotatef(angle4, -2.0f, -3.0f, 0.0f);
    glColor3f(0,0,blue);
    glLineWidth(4);
	glBegin(GL_LINES);
        glVertex3f( -2.0f, -3.0f, 0.0f);
		glVertex3f( -2.0f, -4.0f, 0.0f);
    glEnd();
	glPopMatrix();
}

void Cuisse_droite(){
    // Cuisse Droite
    glPushMatrix();
	glRotatef(angle3, 1.5f, -2.0f, 0.0f);
    glColor3f(0,0,blue);
    glLineWidth(4);
	glBegin(GL_LINES);
        glVertex3f( 1.5f, -2.0f, 0.0f);
		glVertex3f( 1.5f, -3.0f, 0.0f);
    glEnd();
	glPopMatrix();
}

void Jambe_droite(){
    // Jambe Droite
    glPushMatrix();
	glRotatef(angle3, 1.5f, -3.0f, 0.0f);
    glColor3f(0,0,blue);
    glLineWidth(4);
	glBegin(GL_LINES);
        glVertex3f( 1.5f, -3.0f, 0.0f);
		glVertex3f( 1.5f, -4.0f, 0.0f);
	glEnd();
	glPopMatrix();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(  0.0f,0.0f,15.0f,
                0.0f,0.0f,0.0f,
                0.0f,1.0f,0.0f
            );
    // Personne entiere
    //glRotated(45.0f,0.0f,1.0f,0.0f);
    Tete();
    Cou();
    Corps();
    Bras_gauche();
    Bras_droit();
    Hanche();
    Cuisse_gauche();
    Jambe_gauche();
    Cuisse_droite();
    Jambe_droite();
	glutSwapBuffers();
}

void resize(int width, int height) {

	if(height == 0)
		height = 1;
	float ratio = 1.0* width / height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(45,ratio,1,1000);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("Glut Personnage");

	glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutIdleFunc(display);
	glutSpecialFunc(Keyboard);

	glutMainLoop();

    return EXIT_SUCCESS;
}
