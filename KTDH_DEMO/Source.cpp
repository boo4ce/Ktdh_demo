//#include "glut.h"
//#include<iostream>
//using namespace std;
//int rx = 100, ry = 125;
//int xCenter = 250, yCenter = 250;
//
//void myinit(void)
//{
//    glClearColor(1.0, 1.0, 1.0, 0.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
//}
//
//void setPixel(GLint x, GLint y)
//{
//    glBegin(GL_POINTS);
//    glVertex2i(x, y);
//    glEnd();
//}
//void ellipseMidPoint()
//{
//    float x = 0;
//    float y = ry;
//    float p1 = ry * ry - (rx * rx) * ry + (rx * rx) * (0.25);
//    float dx = 2 * (ry * ry) * x;
//    float dy = 2 * (rx * rx) * y;
//    glColor3ub(rand() % 255, rand() % 255, rand() % 255);
//    while (dx < dy)
//    {
//        setPixel(xCenter + x, yCenter + y);
//        setPixel(xCenter - x, yCenter + y);
//        setPixel(xCenter + x, yCenter - y);
//        setPixel(xCenter - x, yCenter - y);
//        if (p1 < 0)
//        {
//            x = x + 1;
//            dx = 2 * (ry * ry) * x;
//            p1 = p1 + dx + (ry * ry);
//        }
//        else
//        {
//            x = x + 1;
//            y = y - 1;
//            dx = 2 * (ry * ry) * x;
//            dy = 2 * (rx * rx) * y;
//            p1 = p1 + dx - dy + (ry * ry);
//        }
//    }
//    glFlush();
//
//    float p2 = (ry * ry) * (x + 0.5) * (x + 0.5) + (rx * rx) * (y
//        - 1) * (y - 1) - (rx * rx) * (ry * ry);
//    glColor3ub(rand() % 255, rand() % 255, rand() % 255);
//    while (y > 0)
//    {
//        setPixel(xCenter + x, yCenter + y);
//        setPixel(xCenter - x, yCenter + y);
//        setPixel(xCenter + x, yCenter - y);
//        setPixel(xCenter - x, yCenter - y);
//        if (p2 > 0)
//        {
//            x = x;
//            y = y - 1;
//            dy = 2 * (rx * rx) * y;
//            p2 = p2 - dy + (rx * rx);
//        }
//        else
//        {
//            x = x + 1;
//            y = y - 1;
//            dy = dy - 2 * (rx * rx);
//            dx = dx + 2 * (ry * ry);
//            p2 = p2 + dx -
//                dy + (rx * rx);
//        }
//    }
//    glFlush();
//}
//GLuint MakeCube(const float& size)
//{
//    GLuint dp_list;
//    dp_list = glGenLists(1);
//    glNewList(dp_list, GL_COMPILE);
//    glBegin(GL_QUADS);
//    // Front Face
//    glNormal3f(0.0, 0.0, 1.0);
//    glVertex3f(-size, -size, size);
//    glVertex3f(size, -size, size);
//    glVertex3f(size, size, size);
//    glVertex3f(-size, size, size);
//    // Back Face
//    glNormal3f(0.0, 0.0, -1.0);
//    glVertex3f(-size, -size, -size);
//    glVertex3f(-size, size, -size);
//    glVertex3f(size, size, -size);
//    glVertex3f(size, -size, -size);
//    // Top Face
//    glNormal3f(0.0, 1.0, 0.0);
//    glVertex3f(-size, size, -size);
//    glVertex3f(-size, size, size);
//    glVertex3f(size, size, size);
//    glVertex3f(size, size, -size);
//    // Bottom Face
//    glNormal3f(0.0, -1.0, 0.0);
//    glVertex3f(-size, -size, -size);
//    glVertex3f(size, -size, -size);
//    glVertex3f(size, -size, size);
//    glVertex3f(-size, -size, size);
//    // Right face
//    glNormal3f(1.0, 0.0, 0.0);
//    glVertex3f(size, -size, -size);
//    glVertex3f(size, size, -size);
//    glVertex3f(size, size, size);
//    glVertex3f(size, -size, size);
//    // Left Face
//    glNormal3f(-1.0, 0.0, 0.0);
//    glVertex3f(-size, -size, -size);
//    glVertex3f(-size, -size, size);
//    glVertex3f(-size, size, size);
//    glVertex3f(-size, size, -size);
//
//    glEnd();
//    glEndList();
//    return dp_list;
//}
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 0.0, 0.0);
//    glPointSize(2.0);
//    ellipseMidPoint();
//    glFlush();
//}
//
//void printMenu() {
//    cout << "1. Ty le 2d" << endl;
//    cout << "2. Ty le 3d" << endl;
//    cout << "3. Bien dang 2d" << endl;
//    cout << "4. Bien dang 3d" << endl;
//    cout << "5. Quay 2d" << endl;
//    cout << "6. Quay quanh truc toa do" << endl;
//    cout << "7. Quay quanh truc // truc toa do" << endl;
//    cout << "8. Quay quanh truc bat ki" << endl;
//    cout << "Nhap lua chon: ";
//}
//
//void draw1() {
//    glutInitWindowSize(640, 480);
//    glutInitWindowPosition(10, 10);
//    glutCreateWindow("Ty le 2d");
//    myinit();
//    glutDisplayFunc(display);
//    glutMainLoop();
//}
//
//void draw8() {
//
//}
//
//void draw(int menuID) {
//    switch (menuID) {
//    case 1: 
//        draw1();
//        break;
//    }
//}
//
//
////int main(int argc, char** argv)
////{
////    int a;
////
////    glutInit(&argc, argv);
////    while (1) {
////        printMenu();
////        cin >> a;
////        draw(a);
////    }
////
////    return 0;
////}