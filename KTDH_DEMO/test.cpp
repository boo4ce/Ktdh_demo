#include "glut.h"
 
#include <math.h>
#include <iostream>
#include <string>
using namespace std;


 
struct Point {
	float x;
	float y;
	float z;
};
 
 
float angle = 0;
int state = 2;
float cloneAngle = 0;
Point p1,p2,p3,p4;
string axis = "z";


void init(void)
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_FLAT);
 
}


 
void drawTuDien(Point p1,Point p2,Point p3, Point p4){
	glColor3f(1.0,1.0,1.0);
	
	glBegin(GL_LINES);
	glVertex3f(p1.x, p1.y, p1.z);
    glVertex3f(p2.x, p2.y, p2.z);
    glEnd();
    
    glBegin(GL_LINES);
	glVertex3f(p1.x, p1.y, p1.z);
    glVertex3f(p3.x, p3.y, p3.z);
    glEnd();
    
    glBegin(GL_LINES);
	glVertex3f(p2.x, p2.y, p2.z);
    glVertex3f(p3.x, p3.y, p3.z);
    glEnd();
    
    glBegin(GL_LINES);
	glVertex3f(p1.x, p1.y, p1.z);
    glVertex3f(p4.x, p4.y, p4.z);
    glEnd();
    
    glBegin(GL_LINES);
	glVertex3f(p2.x, p2.y, p2.z);
    glVertex3f(p4.x, p4.y, p4.z);
    glEnd();
    
    glBegin(GL_LINES);
	glVertex3f(p3.x, p3.y, p3.z);
    glVertex3f(p4.x, p4.y, p4.z);
    glEnd();
}
 
void drawCoordinates(){
	
 
    // draw 3 lines
    glColor3f(1.0,0.0,0.0); // red x
    glBegin(GL_LINES);
    // x aix
 
    glVertex3f(-100.0, 0.0f, 0.0f);
    glVertex3f(100.0, 0.0f, 0.0f);
 
    glVertex3f(100.0, 0.0f, 0.0f);
    glVertex3f(97.0, 3.0f, 0.0f);
 
    glVertex3f(100.0, 0.0f, 0.0f);
    glVertex3f(97.0, -3.0f, 0.0f);
    glEnd();
 
    // y 
    glColor3f(0.0,1.0,0.0); // green y
    glBegin(GL_LINES);
    glVertex3f(0.0, -100.0f, 0.0f);
    glVertex3f(0.0, 100.0f, 0.0f);
 
    glVertex3f(0.0, 100.0f, 0.0f);
    glVertex3f(3.0, 97.0f, 0.0f);
 
    glVertex3f(0.0, 100.0f, 0.0f);
    glVertex3f(-3.0, 97.0f, 0.0f);
    glEnd();
 
    // z 
    glColor3f(0.0,0.0,1.0); // blue z
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0f ,-100.0f );
    glVertex3f(0.0, 0.0f ,100.0f );
 
 
    glVertex3f(0.0, 0.0f ,100.0f );
    glVertex3f(0.0, 3.0f ,97.0f );
 
    glVertex3f(0.0, 0.0f ,100.0f );
    glVertex3f(0.0, -3.0f ,97.0f );
    glEnd();
    
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 'x':                
        	exit(0);
        	break;
        case '1':
        	state = 0;
        	glutPostRedisplay();
        	break;
        case '2':
        	state = 1;
        	glutPostRedisplay();
        	break;
        case '3':
        	state = 2;
        	glutPostRedisplay();
        	break;

   }
}
 
void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glLoadIdentity ();
	glTranslatef(0.0f, 0, -10.0f);
	
	glRotatef(-90,1,0,0);
	
	glRotatef(20,1,0,0);
	glRotatef(-110,0,0,1);
	glScalef (0.05, 0.05, 0.05);
	
	drawCoordinates();
	  
	glPushMatrix();
	switch (state){
		case 0:
			drawTuDien(p1,p2,p3,p4);
			break;
		case 1:
			if (axis == "x"){
				glRotatef(angle,1,0,0);
				drawTuDien(p1,p2,p3,p4);
			}else if (axis == "y"){
				glRotatef(angle,0,1,0);
				drawTuDien(p1,p2,p3,p4);
			}else if (axis == "z"){
				glRotatef(angle,0,0,1);
				drawTuDien(p1,p2,p3,p4);
			}
			break;
		case 2:
			if (axis == "x"){
				glRotatef(cloneAngle,1,0,0);
				drawTuDien(p1,p2,p3,p4);
			}else if (axis == "y"){
				glRotatef(cloneAngle,0,1,0);
				drawTuDien(p1,p2,p3,p4);
			}else if (axis == "z"){
				glRotatef(cloneAngle,0,0,1);
				drawTuDien(p1,p2,p3,p4);
			}
			break;
				
	}
	
//	glRotatef(angle,0,0,1);
//	drawTuDien(p1,p2,p3,p4);
//	
	glPopMatrix();
	 
	glFlush ();
 
}
 
 
void idleCallback()
{
	if (state == 2){
		cloneAngle += 0.01;
		if (cloneAngle >= angle){
			cloneAngle = 0;
		}
		glutPostRedisplay();
	}
}
 
 
int main(int argc, char** argv)
{
	
	cout<<"Nhap diem thu 1 : ";
  cin>>p1.x>>p1.y>>p1.z;
  
  cout<<"Nhap diem thu 2 : ";
  cin>>p2.x>>p2.y>>p2.z;
  
  cout<<"Nhap diem thu 3 : ";
  cin>>p3.x>>p3.y>>p3.z;
  
  cout<<"Nhap diem thu 4 : ";
  cin>>p4.x>>p4.y>>p4.z;
  
  cout<<"Nhap truc : ";
  cin>>axis;
  
  cout<<"Nhap goc quay : ";
  cin>>angle;

//	p1.x = 0;
//	p1.y = 0;
//	p1.z = 0;
//	  
//	p2.x = 30;
//	p2.y = 0;
//	p2.z = 0;
//	  
//	p3.x = 0;
//	p3.y = 40;
//	p3.z = 0;
//	  
//	p4.x = 0;
//	p4.y = 0;
//	p4.z = 70;
//	
//	axis = "z";
//	angle = 90;
	
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (500, 500);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display);
  glutIdleFunc(idleCallback);
  glutKeyboardFunc(keyboard); 
 
  glViewport (0, 0, (GLsizei) 500, (GLsizei) 500);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
  glMatrixMode (GL_MODELVIEW);
  
  
 
  glutMainLoop();

  return 0;
}

/*
Point p1,p2,p3,p4;
	
	p1.x = 0;
	p1.y = 0;
	p1.z = 0;
	  
	p2.x = 45;
	p2.y = 0;
	p2.z = 0;
	  
	p3.x = 0;
	p3.y = 60;
	p3.z = 0;
	  
	p4.x = 0;
	p4.y = 0;
	p4.z = 90;
*/
