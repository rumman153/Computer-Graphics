#include<stdio.h>
#include <windows.h>
#include <GL/glut.h>
#include <math.h>

float xmin=0.2,ymin=0.4,xmax=0.8 ,ymax=0.8;
float xa=0.1, ya=0.9, xb=0.9, yb=0.1;
float xc, yc, xd, yd;
    int flag1, flag2;
float a0=0.0,a1=0.0,b0=0.0,b1=0.0;
void display(void)
{

    glColor3f(0.5,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(xmin,ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax,ymax);
    glVertex2f(xmin, ymax);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(xa,ya);
    glVertex2f(xb, yb);
    glEnd();
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(a0,a1);
    glVertex2f(b0, b1);
    glEnd();
    glFlush();}



void keypress(unsigned char key,int x,int y){

    switch(key){
        case'r':

    //First End Point
    if(xa>xmin && xa<xmax && ya>ymin && yb<ymax)
    {
        flag1 = 0; //inside
        a0=xa;
        a1= ya;
    }
    else if(xa<=xmin && ya>=ymax)
    {
        flag1 = 5; //up-left
        xc = xmin;
        yc = ya+(yb-ya)*((xmin-xa)/(xb-xa));

        if(xc>=xmin && xc<=xmax && yc>=ymin && yc<=ymax)
        {
            a0=xc;
            a1= yc;
        }

        xd = xa+(xb-xa)*((ymax-yb)/(yb-ya));
        yd = ymax;

        if(xd>=xmin && xd<=xmax && yd>=ymin && yd<=ymax)
        {
            a0=xd;
            a1= yd;
        }
    }
    else if(xa>=xmax && ya>=ymax)
    {
        flag1 = 6; //up-right

        xc = xmax;
        yc = ya+(yb-ya)*((xmax-xa)/(xb-xa));
        if(xc>=xmin && xc<=xmax && yc>=ymin && yc<=ymax)
        {
            a0=xc;
            a1= yc;
        }

        xd = xa+(xb-xa)*((ymax-ya)/(yb-ya));
        yd = ymax;
        if(xd>=xmin && xd<=xmax && yd>=ymin && yd<=ymax)
        {
            a0=xd;
            a1= yd;
        }
    }
    else if(xa<=xmin && ya<=ymin)
    {
        flag1 = 7; //down-left
        xc = xmin;
        yc = ya+(yb-ya)*((xmin-xa)/(xb-xa));
        if(xc>=xmin && xc<=xmax && yc>=ymin && yc<=ymax)
        {
            a0=xc;
            a1=yc;
        }

        xd = xa+(xb-xa)*((ymin-ya)/(yb-ya));
        yd = ymin;
        if(xd>=xmin && xd<=xmax && yd>=ymin && yd<=ymax)
        {
            a0=xd;
            a1= yd;
        }
    }
    else if(xa>=xmax && ya<=ymin)
    {
        flag1 = 8; //down-right
        xc = xmax;
        yc = ya+(yb-ya)*((xmax-xa)/(xb-xa));
        if(xc>=xmin && xc<=xmax && yc>=ymin && yc<=ymax)
        {
            a0=xc;
            a1= yc;
        }

        xd = xa+(xb-xa)*((ymin-ya)/(yb-ya));
        yd = ymin;
        if(xd>=xmin && xd<=xmax && yd>=ymin && yd<=ymax)
        {
            a0=xd;
            a1= yd;
        }
    }
    else if(ya>=ymax)
    {
        flag1 = 1; //up
        xc = xa+(xb-xa)*((ymax-ya)/(yb-ya));
        yc = ymax;
        if(xc>=xmin && xc<=xmax && yc>=ymin && yc<=ymax)
        {
            a0=xc;
            a1= yc;
        }
    }
    else if(ya<=ymin)
    {
        flag1 = 2; //down
        xc = xa+(xb-xa)*((ymin-ya)/(yb-ya));
        yc = ymin;
        if(xc>=xmin && xc<=xmax && yc>=ymin && yc<=ymax)
        {
            a0=xc;
            a1= yc;
        }

    }
    else if(xa>=xmax)
    {
        flag1 = 4; //right
        xc = xmax;
        yc = ya+(yb-ya)*((xmax-xa)/(xb-xa));
        if(xc>=xmin && xc<=xmax && yc>=ymin && yc<=ymax)
        {
            a0=xc;
            a1= yc;
        }
    }
    else if(xa<=xmin)
    {
        flag1 = 3; //left
        xc = xmin;
        yc = ya+(yb-ya)*((xmin-xa)/(xb-xa));
        if(xc>=xmin && xc<=xmax && yc>=ymin && yc<=ymax)
        {
            a0=xc;
            a1= yc;
        }
    }


    //Second End Point

    if(xb>xmin && xb<xmax && yb>ymin && yb<ymax)
    {
        flag2 = 0; //inside
        b0=xb;
        b1=yb;
    }
    else if(xb<=xmin && yb>=ymax)
    {
        flag2 = 5; //up-left
        xc = xmin;
        yc = ya+(yb-ya)*((xmin-xa)/(xb-xa));
        if(xc>=xmin && xc<=xmax && yc>=ymin && yc<=ymax)
        {
            b0=xc;
            b1=yc;
        }

        xd = xa+(xb-xa)*((ymax-ya)/(yb-ya));
        yd = ymax;
        if(xd>=xmin && xd<=xmax && yd>=ymin && yd<=ymax)
        {
            b0=xd;
            b1= yd;
        }
    }
    else if(xb>=xmax && yb>=ymax)
    {
        flag2 = 6; //up-right
        xc = xmax;
        yc = ya+(yb-ya)*((xmax-xa)/(xb-xa));
        if(xc>=xmin && xc<=xmax && yc>=ymin && yc<=ymax)
        {
            b0=xc;
            b1=yc;
        }
        xd = xa+(xb-xa)*((ymax-ya)/(yb-ya));
        yd = ymax;
        if(xd>=xmin && xd<=xmax && yd>=ymin && yd<=ymax)
        {
            b0=xd;
            b1= yd;
        }
    }
    else if(xb<=xmin && yb<=ymin)
    {
        flag2 = 7; //down-left
        xc = xmin;
        yc = ya+(yb-ya)*((xmin-xa)/(xb-xa));
        if(xc>=xmin && xc<=xmax && yc>=ymin && yc<=ymax)
        {
            b0=xc;
            b1= yc;
        }
        xd = xa+(xb-xa)*((ymin-ya)/(yb-ya));
        yd = ymin;
        if(xd>=xmin && xd<=xmax && yd>=ymin && yd<=ymax)
        {
            b0=xd;
            b1= yd;
        }
    }
    else if(xb>=xmax && yb<=ymin)
    {
        flag2 = 8; //down-right
        xc = xmax;
        yc = ya+(yb-ya)*((xmax-xa)/(xb-xa));
        if(xc>=xmin && xc<=xmax && yc>=ymin && yc<=ymax)
        {
            b0=xc;
            b1= yc;
        }
        xd = xa+(xb-xa)*((ymin-ya)/(yb-ya));
        yd = ymin;
        if(xd>=xmin && xd<=xmax && yd>=ymin && yd<=ymax)
        {
            b0=xd;
            b1= yd;
        }
    }
    else if(yb>=ymax)
    {
        flag2 = 1; //up
        xc = xa+(xb-xa)*((ymax-ya)/(yb-ya));
        yc = ymax;
        if(xc>=xmin && xc<=xmax && yc>=ymin && yc<=ymax)
        {
            b0=xc;
            b1 =yc;
        }
    }
    else if(yb<=ymin)
    {
        flag2 = 2; //down
        xc = xa+(xb-xa)*((ymin-ya)/(yb-ya));
        yc = ymin;
        if(xc>=xmin && xc<=xmax && yc>=ymin && yc<=ymax)
        {
            b0=xc;
            b1= yc;
        }
    }
    else if(xb>=xmax)
    {
        flag2 = 4; //right
        xc = xmax;
        yc = ya+(yb-ya)*((xmax-xa)/(xb-xa));
        if(xc>=xmin && xc<=xmax && yc>=ymin && yc<=ymax)
        {
            b0=xc;
            b1= yc;
        }
    }
    else if(xb<=xmin)
    {
        flag2 = 3; //left
         xc = xmin;
        yc = ya+(yb-ya)*((xmin-xa)/(xb-xa));
        if(xc>=xmin && xc<=xmax && yc>=ymin && yc<=ymax)
        {
            b0=xc;
            b1= yc;
        }
    }

    printf("\n%d %d",flag1, flag2);

    glutPostRedisplay();
    break;
}}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("CSE 4-2 A1");
    glutDisplayFunc(display);
    glutKeyboardFunc(keypress);
    glutMainLoop();
    return 0;
}
