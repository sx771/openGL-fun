/*
 this is software is implementaed for world window cordinate presentation
 author : sarvesh ameta
 */

#include <iostream>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace::std;

void drawImage()	{	
	glColor3f (0.2, 0.2, 0.2);
	glBegin(GL_LINES);
		glVertex2d (-50, 0);
		glVertex2d (50, 0);

		glVertex2d (-50, 0);
		glVertex2d (-50, 100);

		glVertex2d (-50, 100);
		glVertex2d (50, 100);

		glVertex2d (50, 100);
		glVertex2d (50, 0);

		glVertex2d (-50, 100);
		glVertex2d (0, 150);

		glVertex2d (0, 150);
		glVertex2d (50, 100);

		/*lines*/
		glVertex2d (-100, 50);
		glVertex2d (-100, -50);

		glVertex2d (-120, 50);
		glVertex2d (-120, -50);

		glVertex2d (100, 50);
		glVertex2d (100, -50);

		glVertex2d (120, 50);
		glVertex2d (120, -50);
	glEnd ();

	glColor3f (0.2, 0.3, 0.4);
	glRecti (-150, -150, -60, -60) ;

	glColor3f (0.4, 0.3, 0.1);
	glRecti (+150, -150, 60, -60);

	glColor3f (0.0, 0.3, 0.3);
	glRecti (+150, +150, 60, 60);

	glColor3f (0.2, 0.0, 0.4);
	glRecti (-150, +150, -60, 60);
}

void setWorld (double l, double r, double b, double t)	{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (l, r, b, t);
}

void display ()	{
	cout << "display func \n";
	setWorld (-300.0, 300.0, -300.0, 300.0);
	drawImage ();
	glFlush ();
}

void init ()	{
	cout << "inititaling the screen\n";
	glClearColor (0.1, 0.1, 0.1, 0.0);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | 
			GL_DEPTH_BUFFER_BIT);
	glColor3f (1.0, 0.0, 0.0);
	glLineWidth (3);
}

void reshape (int W, int H)	{
	cout << "reshaping\n";
	init();
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glViewport (0.0, 0.0, W, H);
}

void keyboard (unsigned char key, int x, int y)	{
	static int a = -300;
	static int b = 300;
	switch (key)	{
		case '+' :
			cout << "+ pressed \n";
			glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			a--;
			b++;
			cout <<" a = "<<a<<" b = "<<b<<"\n";
			setWorld (a, b, a, b);
			//setWorld (-110.0, 110.0, -300.0, 300.0);
			drawImage ();
			glFlush ();
			break;
		case '-' :	
			cout << "- pressed \n";
			glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			a++;
			b--;
			cout <<" a = "<<a<<" b = "<<b<<"\n";
			setWorld (a, b, a, b);
			drawImage ();
			glFlush ();
			break ;
		default : 
			break ;
	}
}

int main(int argc, char **argv)	{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(600, 600);
	glutCreateWindow ("worldWindow");
	glutDisplayFunc (display);
	glutReshapeFunc (reshape);
	glutKeyboardFunc (keyboard);
	init ();
	glutMainLoop();

	return 0;
}
