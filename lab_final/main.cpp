#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>



// angle of rotation for the camera direction
float angle=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
// XZ position of the camera
float x=0.0f,z=60.0f;


void drawStar() {

//white color
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);

	glVertex3f(-10.0f, -3.0f, 0.0f);
	glVertex3f(-12.0f, -3.0f, 0.0f);
	glVertex3f(-14.0f, -3.0f, 0.0f);

	glVertex3f(2.0f, 2.0f, 0.0f);
	glVertex3f(3.0f, 3.0f, 0.0f);
    glVertex3f(3.0f, 4.0f, 0.0f);
    glVertex3f(2.0f, 4.0f, 0.0f);
    glVertex3f(3.0f, 32.0f, 0.0f);
    glVertex3f(3.0f, 5.0f, 0.0f);
    glVertex3f(3.0f, 6.0f, 0.0f);
    glVertex3f(2.0f, 5.0f, 0.0f);
    glVertex3f(3.0f, 4.0f, 0.0f);
    glVertex3f(2.0f, 4.0f, 0.0f);
    glVertex3f(3.0f, 6.0f, 0.0f);
    glVertex3f(4.0f, 1.0f, 0.0f);
    glVertex3f(6.0f, 1.0f, 0.0f);
    glVertex3f(8.0f, .0f, 0.0f);
    glVertex3f(3.0f, 6.0f, 0.0f);
    glVertex3f(4.0f, 1.0f, 0.0f);
    glVertex3f(6.0f, 1.0f, 0.0f);
    glVertex3f(8.0f, .0f, 0.0f);
    glVertex3f(6.0f, -1.0f, 0.0f);
    glVertex3f(8.0f, -1.0f, 0.0f);
    glVertex3f(-10.0f, 3.0f, 0.0f);
	glVertex3f(-12.0f, 3.0f, 0.0f);
	glVertex3f(-14.0f, -3.0f, 0.0f);
	glVertex3f(-10.0f, 4.0f, 0.0f);
	glVertex3f(-12.0f, 5.0f, 0.0f);
	glVertex3f(-14.0f, 6.0f, 0.0f);
	glVertex3f(-15.0f, 4.0f, 0.0f);
	glVertex3f(-13.0f, 5.0f, 0.0f);
	glVertex3f(-11.0f, 6.0f, 0.0f);


glEnd();
angle+=0.1f;
glutSwapBuffers();

}


//for light
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f ,0.0f, 17.0f, 1.0f };

void drawSolar() {

//for light
glEnable(GL_LIGHT0);

    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);



// Draw Sun : color yellow
    glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(3.0f,100,100);
    glEnd();




glRotatef(angle, 0.0f, 1.0f, 0.0f);



//Mercury :  Black Gray
    glColor3f(0.9f,0.9f,0.9f);
	glTranslatef(-14 ,0.60, 0.0f);
	glutSolidSphere(0.75f,60,60);

//Venus : drak yellow
 glColor3f(0.9f, 0.7f, 0.0f);

	glTranslatef(7,0.0f, 4.0f);
	glutSolidSphere(0.60f,40,40);


//Earth : blue
    glColor3f(0.0f, 0.5f, 1.0f);
	glTranslatef(17,0.0f, 8.0f);
	glutSolidSphere(1.5f,40,40);

	//Mars : dark white
   glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef(12,0.0f, -15.0f);
	glutSolidSphere(0.75f,40,40);


//drak yellow :  Jupiter
	  glColor3f(0.9f, 0.5f, 0.0f);
	glTranslatef(14,0.0f, 10.0f);
	glutSolidSphere(1.9f,40,40);



glEnd();

	angle+=0.1f;
	glutSwapBuffers();
}

void renderScene(void) {

	// Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	x, 1.0f, z,
			x+lx, 1.0f,  z+lz,
			0.0f, 1.0f,  0.0f);

        // Draw 1 Solar
	for(int i = 0; i < 1; i++)
		for(int j=0; j < 1; j++) {
			glPushMatrix();
			glTranslatef(i*10.0,0,j * 10.0);
			drawSolar();
			glPopMatrix();
		}

       // for Star
	for(int i = -1; i < 3; i++)
		for(int j=-1; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i*10.0,0,j * 10.0);
			drawStar();
			glPopMatrix();
		}

	glutSwapBuffers();
}


void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT :
			angle += 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP :
			x += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN :
			x -= lx * fraction;
			z -= lz * fraction;
			break;
	}
}


void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;

        // Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

        // Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int x, int y) {

	if (key == 27)
		exit(0);
}



int main(int argc, char **argv) {

	// init GLUT and create window
GLenum type;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("CSE 421 L : Computer Graphics Lab");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

    // OpenGL init
	glEnable(GL_DEPTH_TEST);
    // enter GLUT event processing cycle
	glutMainLoop();

	return 0;
}
