#include <gl/glut.h>
#include <stdio.h>

int x1, y1,r;

void myInit()
{

    glClearColor(0.92, 0.53, 0.85, 1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 1.0,0.0);
    glPointSize(7.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400, 400, -400, 400);
}

void line(int x1,int y1,int x2,int y2)
{
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();

}
void draw_pixel_circle(int x, int y,int x1,int y1)
{
    glBegin(GL_POINTS);
    ///1st xy coordinate
    glVertex2i(x+x1, y+y1);
    glVertex2i(y+x1, x+y1);
    ///2nd -xy coordinate
    glVertex2i(-x+x1, y+y1);
    glVertex2i(-y+x1, x+y1);
    ///3rd -x-y coordinate
    glVertex2i(-x+x1, -y+y1);
    glVertex2i(-y+x1, -x+y1);
    ///4th x-y coordinate
    glVertex2i(x+x1,-y+y1);
    glVertex2i(y+x1, -x+y1);
    glEnd();
}

void circle(int r,int x1,int y1)
{

    int x,y,d;
    d=1-r;
    x=0;
    y=r;
    draw_pixel_circle(x,y,x1,y1);
    while(x<=y)
    {
        if(d<0)
        {
            d=d+2*x+3;
            x=x+1;

        }
        else
        {
            d=d+2*(x-y)+5;
            x=x+1;
            y=y-1;
        }
        draw_pixel_circle(x,y,x1,y1);
    }

}
void myDisplay()
{
    glRasterPos2f(-100, 300); /// text position
    char a[100] = "Olympic Logo Drawing";
    int len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[i]);
    }

    glColor3f(0.02,0.47,0.78);
    circle(100,-210,100);
    glColor3f(0.00,0.00,0.00);
    circle(100,0,100);
    glColor3f(0.88,0.01,0.10);
    circle(100,210,100);
    glColor3f(0.93,0.76,0.07);
    circle(100,-110,0);
    glColor3f(0.00,0.62,0.27);
    circle(100,110,0);

    glFlush();

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Olympic Logo Drawing");
    myInit();
    glutDisplayFunc(myDisplay);

    glutMainLoop();
}
