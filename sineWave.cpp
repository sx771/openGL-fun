/*
 this is the sine wave function animation
 author : sarvesh ameta
 */

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

using namespace::std;


double ii=(3.142/180.0);
void drawWave ()
{	
	glColor3f (0.0, 1.0, 0.0);
	glBegin (GL_LINES);
		glVertex2d (-1000, 0);
		glVertex2d (+1000, 0);
	glEnd ();
	
	glColor3f (0.0, 0.0, 0.0);
	glBegin (GL_POINTS);
	for (int i = -400; i <= +400; i++)	{
		cout <<"i, sin = "<<i<<", "<<sin (i)<<"\n";
		glVertex2f (i, sin(i*ii)*100.0);
	}
	glEnd ();
}

void setWorld (double l, double r, double b, double t)	{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (l, r, b, t);
}

void display ()	{
	/*
	setWorld (-250.0, 250.0, -250.0, 250.0);
	drawWave ();
	glFlush ();
	*/
	int a = -250;
	int b = 250;
	int i = 0 ;
	while (1) 	{
		setWorld (a + i, b + i, -250, 250);
		glClear (GL_COLOR_BUFFER_BIT);
		drawWave ();
		glFlush ();
		sleep (0.01);
		i++;
		if (i == 360)
			i=0;
	}

}

void init ()	{
	glClearColor (0.5, 0.1, 0.0, 0.0);
	glClear (GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glViewport (0.0, 0.0, 600.0, 600.0);
	glPointSize (5);
}

void reshape (int W, int H)	{
	cout << "reshape \n";
	init ();
	glViewport (0.0, 0.0, W, H);
}

int main (int argc, char **argv)	{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition (00.0, 00.0);
	glutInitWindowSize (600,600);
	glutCreateWindow ("sine wave");
	glutDisplayFunc (display);
	glutReshapeFunc (reshape);
	init ();
	glutMainLoop ();

	return 0;
}
