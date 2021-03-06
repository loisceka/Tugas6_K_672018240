#include<windows.h>
#include<gl/glut.h>

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
int z1 = 0;
int x1 = 0;
int y1 = 0;
bool mouseDown = false;
int is_depth;

void init(void){
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y){
    if(mouseDown){
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void idle(){
    if(!mouseDown){
        xrot += 0.0000005f;
        yrot += 0.0000005f;
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
    if (key == 'w' || key == 'W')z1+=2;
    else if(key == 's' || key == 'S')z1-=2;
    else if(key == 'a' || key == 'A')x1-=2;
    else if(key == 'd' || key == 'D')x1+=2;
    else if(key == 't' || key == 'T')y1+=2;
    else if(key == 'g' || key == 'G')y1-=3;
    else if(key == '5')
        if(is_depth){
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        } else {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
}

void ukuran(int lebar, int tinggi){
    if(tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, lebar / tinggi, 1, 500);
    glTranslatef(0, 0, -150);
    glMatrixMode(GL_MODELVIEW);
}

void display(void){
    if(is_depth){
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    } else {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glTranslatef(x1, y1, z1);

    //Depan 1
    glBegin(GL_QUADS);
    glColor3f(1, 1, 40/255.f);
    glVertex3f(10, -12.5, 37.5);
    glVertex3f(10, 12.5, 37.5);
    glVertex3f(30, 12.5, 37.5);
    glVertex3f(30, -12.5, 37.5);
    glEnd();
    //Depan 2
    glBegin(GL_QUADS);
    glColor3f(1, 1, 40/255.f);
    glVertex3f(10, -12.5, 7.5);
    glVertex3f(10, 12.5, 7.5);
    glVertex3f(10, 12.5, 37.5);
    glVertex3f(10, -12.5, 37.5);
    glEnd();
    //Depan 3
    glBegin(GL_QUADS);
    glColor3f(1, 1, 40/255.f);
    glVertex3f(-40, -12.5, 22.5);
    glVertex3f(-40, 12.5, 22.5);
    glVertex3f(10, 12.5, 22.5);
    glVertex3f(10, -12.5, 22.5);
    glEnd();
    //Kanan
    glBegin(GL_QUADS);
    glColor3f(1, 1, 40/255.f);
    glVertex3f(30, -12.5, 37.5);
    glVertex3f(30, 12.5, 37.5);
    glVertex3f(30, 12.5, -37.5);
    glVertex3f(30, -12.5, -37.5);
    glEnd();
    //Kiri
    glBegin(GL_QUADS);
    glColor3f(1, 1, 40/255.f);
    glVertex3f(-40, -12.5, -37.5);
    glVertex3f(-40, 12.5, -37.5);
    glVertex3f(-40, 12.5, 22.5);
    glVertex3f(-40, -12.5, 22.5);
    glEnd();
    //Belakang
    glBegin(GL_QUADS);
    glColor3f(1, 1, 40/255.f);
    glVertex3f(30, -12.5, -37.5);
    glVertex3f(30, 12.5, -37.5);
    glVertex3f(-40, 12.5, -37.5);
    glVertex3f(-40, -12.5, -37.5);
    glEnd();
    //Bawah
    glBegin(GL_QUADS);
    glColor3f(211/255.f, 211/255.f, 211/255.f);
    glVertex3f(30, -12.5, -37.5);
    glVertex3f(10, -12.5, -37.5);
    glVertex3f(10, -12.5, 37.5);
    glVertex3f(30, -12.5, 37.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(211/255.f, 211/255.f, 211/255.f);
    glVertex3f(10, -12.5, -37.5);
    glVertex3f(-40, -12.5, -37.5);
    glVertex3f(-40, -12.5, 22.5);
    glVertex3f(10, -12.5, 22.5);
    glEnd();
    //Atap
    glBegin(GL_QUADS);
    glColor3f(160/255.f, 82/255.f, 45/255.f);
    glVertex3f(-40, 12.5, -37.5);
    glVertex3f(-40, 12.5, 22.5);
    glVertex3f(0, 12+5+20, 0);
    glVertex3f(0, 12+5+20, 0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(160/255.f, 82/255.f, 45/255.f);
    glVertex3f(30, 12.5, -37.5);
    glVertex3f(-40, 12.5, -37.5);
    glVertex3f(0, 12+5+20, 0);
    glVertex3f(0, 12+5+20, 0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(160/255.f, 82/255.f, 45/255.f);
    glVertex3f(30, 12.5, -37.5);
    glVertex3f(30, 12.5, 37.5);
    glVertex3f(0, 12+5+20, 0);
    glVertex3f(0, 12+5+20, 0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(160/255.f, 82/255.f, 45/255.f);
    glVertex3f(-40, 12.5, 22.5);
    glVertex3f(10, 12.5, 22.5);
    glVertex3f(0, 12+5+20, 0);
    glVertex3f(0, 12+5+20, 0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(160/255.f, 82/255.f, 45/255.f);
    glVertex3f(10, 12.5, 22.5);
    glVertex3f(10, 12.5, 37.5);
    glVertex3f(0, 12+5+20, 0);
    glVertex3f(0, 12+5+20, 0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(160/255.f, 82/255.f, 45/255.f);
    glVertex3f(10, 12.5, 37.5);
    glVertex3f(30, 12.5, 37.5);
    glVertex3f(0, 12+5+20, 0);
    glVertex3f(0, 12+5+20, 0);
    glEnd();
    //Pembatas Kamar 1
    glBegin(GL_QUADS);
    glColor3f(1, 1, 40/255.f);
    glVertex3f(10, -12.5, 7.5);
    glVertex3f(10, 12.5, 7.5);
    glVertex3f(30, 12.5, 7.5);
    glVertex3f(30, -12.5, 7.5);
    glEnd();
    //Pembatas Kamar 2-1
    glBegin(GL_QUADS);
    glColor3f(1, 254/255.f, 87/255.f);
    glVertex3f(-40, -12.5, 7.5);
    glVertex3f(-40, 12.5, 7.5);
    glVertex3f(-5, 12.5, 7.5);
    glVertex3f(-5, -12.5, 7.5);
    glEnd();
    //Pembatas Kamar 2-2
    glBegin(GL_QUADS);
    glColor3f(1, 254/255.f, 87/255.f);
    glVertex3f(-5, -12.5, 7.5);
    glVertex3f(-5, 12.5, 7.5);
    glVertex3f(-5, 12.5, -12.5);
    glVertex3f(-5, -12.5, -12.5);
    glEnd();
    //Pembatas Kamar 3-1
    glBegin(GL_QUADS);
    glColor3f(1, 254/255.f, 87/255.f);
    glVertex3f(-40, -12.5, -12.5);
    glVertex3f(-40, 12.5, -12.5);
    glVertex3f(-5, 12.5, -12.5);
    glVertex3f(-5, -12.5, -12.5);
    glEnd();
    //Pembatas Kamar 3-2
    glBegin(GL_QUADS);
    glColor3f(1, 254/255.f, 87/255.f);
    glVertex3f(-5, -12.5, -12.5);
    glVertex3f(-5, 12.5, -12.5);
    glVertex3f(-5, 12.5, -37.5);
    glVertex3f(-5, -12.5, -37.5);
    glEnd();
    //Pembatas RT
    glBegin(GL_QUADS);
    glColor3f(1, 1, 40/255.f);
    glVertex3f(7.5, -12.5, -15);
    glVertex3f(7.5, 12.5, -15);
    glVertex3f(30, 12.5, -15);
    glVertex3f(30, -12.5, -15);
    glEnd();
    //Pembatas DPR
    glBegin(GL_QUADS);
    glColor3f(1, 254/255.f, 87/255.f);
    glVertex3f(7.5, -12.5, -25);
    glVertex3f(7.5, 12.5, -25);
    glVertex3f(30, 12.5, -25);
    glVertex3f(30, -12.5, -25);
    glEnd();
    //Pembatas TL
    glBegin(GL_QUADS);
    glColor3f(1, 254/255.f, 87/255.f);
    glVertex3f(7.5, -12.5, -37.5);
    glVertex3f(7.5, 12.5, -37.5);
    glVertex3f(7.5, 12.5, -25);
    glVertex3f(7.5, -12.5, -25);
    glEnd();
    //Pintu Utama
    glPushMatrix();
    glColor3f(139/255.f, 69/255.f, 19/255.f);
    glTranslatef(2, -4, 22.5);
    glScalef(6, 9, 1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(218/255.f, 165/255.f, 32/255.f);
    glTranslatef(-2, -4, 22.5);
    glScalef(1, 1, 2);
    glutSolidCube(2);
    glPopMatrix();
    //Jendela 1
    glPushMatrix();
    glColor3f(1, 103/255.f, 14/255.f);
    glTranslatef(-22.5, 0, 22.5);
    glScalef(7, 5, 1);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-27.5, 0, 22.5);
    glScalef(2, 3, 1.5);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-17.5, 0, 22.5);
    glScalef(2, 3, 1.5);
    glutSolidCube(3);
    glPopMatrix();
    //Pintu K1
    glPushMatrix();
    glColor3f(139/255.f, 69/255.f, 19/255.f);
    glTranslatef(17, -2, 7.5);
    glScalef(4.5, 9, 1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(218/255.f, 165/255.f, 32/255.f);
    glTranslatef(15, -2, 7.5);
    glScalef(1, 1, 2);
    glutSolidCube(2);
    glPopMatrix();
    //Pintu K2
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-5, -4, -7);
    glRotatef(450, 0, 10, 0);
    glScalef(4.5, 8, 0.5);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(192/255.f, 192/255.f, 192/255.f);
    glTranslatef(-5, -4, -5);
    glRotatef(450, 0, 10, 0);
    glScalef(1, 1, 1);
    glutSolidCube(2);
    glPopMatrix();
    //Pintu K3
    glPushMatrix();
    glColor3f(139/255.f, 69/255.f, 19/255.f);
    glTranslatef(-5, -4, -20);
    glRotatef(450, 0, 10, 0);
    glScalef(4.5, 8, 0.5);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(218/255.f, 165/255.f, 32/255.f);
    glTranslatef(-5, -4, -17);
    glRotatef(450, 0, 10, 0);
    glScalef(1, 1, 1);
    glutSolidCube(2);
    glPopMatrix();
    //Pintu TL
    glPushMatrix();
    glColor3f(139/255.f, 69/255.f, 19/255.f);
    glTranslatef(7.5, -4, -30);
    glRotatef(450, 0, 10, 0);
    glScalef(4.5, 8, 0.5);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(218/255.f, 165/255.f, 32/255.f);
    glTranslatef(7.5, -4, -27);
    glRotatef(450, 0, 10, 0);
    glScalef(1, 1, 1);
    glutSolidCube(2);
    glPopMatrix();
    //Jendela 2
    glPushMatrix();
    glColor3f(1, 103/255.f, 14/255.f);
    glTranslatef(-40, 0, 15);
    glRotatef(450, 0, 10, 0);
    glScalef(3.5, 4, 0.5);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-40, 0, 15);
    glRotatef(450, 0, 10, 0);
    glScalef(2.5, 3, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Jendela K1
    glPushMatrix();
    glColor3f(1, 103/255.f, 14/255.f);
    glTranslatef(30, 0, 30);
    glRotatef(450, 0, 10, 0);
    glScalef(3.5, 4, 0.5);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(30, 0, 30);
    glRotatef(450, 0, 10, 0);
    glScalef(2.5, 3, 1);
    glutSolidCube(3);
    glPopMatrix();

    //Jendela K2
    glPushMatrix();
    glColor3f(1, 103/255.f, 14/255.f);
    glTranslatef(-40, 0, -5);
    glRotatef(450, 0, 10, 0);
    glScalef(3.5, 4, 0.5);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-40, 0, -5);
    glRotatef(450, 0, 10, 0);
    glScalef(2.5, 3, 1);
    glutSolidCube(3);
    glPopMatrix();
    //Jendela K3
    glPushMatrix();
    glColor3f(1, 103/255.f, 14/255.f);
    glTranslatef(-40, 0, -20);
    glRotatef(450, 0, 10, 0);
    glScalef(3.5, 4, 0.5);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-40, 0, -20);
    glRotatef(450, 0, 10, 0);
    glScalef(2.5, 3, 1);
    glutSolidCube(3);
    glPopMatrix();

    //FURNITURE
    //Kasur K1
    glPushMatrix();
    glColor3f(81/255.f, 1, 240/255.f);
    glTranslatef(18, -10, 29.5);
    glRotatef(450, 0, 10, 0);
    glScalef(4.5, 1, 5.2);
    glutSolidCube(3);
    glPopMatrix();
    //Pillow K1
    glPushMatrix();
    glColor3f(114/255.f, 1, 28/255.f);
    glTranslatef(13, -9, 29.5);
    glRotatef(450, 0, 10, 0);
    glScalef(4, 1, 2);
    glutSolidCube(2);
    glPopMatrix();
    //Selimut K1
    glPushMatrix();
    glColor3f(1, 39/255.f, 3/255.f);
    glTranslatef(21, -9, 29.5);
    glRotatef(450, 0, 10, 0);
    glScalef(6.5, 1, 4.5);
    glutSolidCube(2);
    glPopMatrix();
    //Kasur K2
    glPushMatrix();
    glColor3f(8/255.f, 1, 3/255.f);
    glTranslatef(-30, -10, -0.5);
    glRotatef(450, 0, 10, 0);
    glScalef(5, 1, 6);
    glutSolidCube(3);
    glPopMatrix();
    //Pillow K2
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-36, -9, -0.5);
    glRotatef(450, 0, 10, 0);
    glScalef(4, 1, 2);
    glutSolidCube(2);
    glPopMatrix();
    //Selimut K2
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(-26, -9, -0.5);
    glRotatef(450, 0, 10, 0);
    glScalef(6.5, 1, 4.5);
    glutSolidCube(2);
    glPopMatrix();
    //Kasur K3
    glPushMatrix();
    glColor3f(63/255.f, 1, 0);
    glTranslatef(-30, -10, -28);
    glRotatef(450, 0, 10, 0);
    glScalef(5, 1, 6);
    glutSolidCube(3);
    glPopMatrix();
    //Pillow K3
    glPushMatrix();
    glColor3f(240/255.f, 128/255.f, 128/255.f);
    glTranslatef(-36, -9, -28);
    glRotatef(450, 0, 10, 0);
    glScalef(4, 1, 2);
    glutSolidCube(2);
    glPopMatrix();
    //Selimut K3
    glPushMatrix();
    glColor3f(40/255.f, 170/255.f, 178/255.f);
    glTranslatef(-26, -9, -28);
    glRotatef(450, 0, 10, 0);
    glScalef(6.5, 1, 4.5);
    glutSolidCube(2);
    glPopMatrix();
    //Kursi Utama
    glPushMatrix();
    glColor3f(63/255.f, 1, 0);
    glTranslatef(-23, -3, 13.5);
    glRotatef(450, 0, 10, 0);
    glScalef(5, 1, 9);
    glutSolidCube(2);
    glPopMatrix();
    //Penyangga 1
    glPushMatrix();
    glColor3f(250/255.f, 69/255.f, 1);
    glTranslatef(-31.5, -3, 13.5);
    glRotatef(450, 0, 10, 0);
    glScalef(5, 4, 1);
    glutSolidCube(2);
    glPopMatrix();
    //Penyangga 2
    glPushMatrix();
    glColor3f(250/255.f, 69/255.f, 1);
    glTranslatef(-14.5, -3, 13.5);
    glRotatef(450, 0, 10, 0);
    glScalef(5, 4, 1);
    glutSolidCube(2);
    glPopMatrix();
    //Meja Utama
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(20, -10, -3);
    glRotatef(450, 0, 10, 0);
    glScalef(4, 1, 4.5);
    glutSolidCube(3);
    glPopMatrix();
    //Dapur Furniture
    glPushMatrix();
    glColor3f(210/255.f, 105/255.f, 30/255.f);
    glTranslatef(20, -2, -23.5);
    glRotatef(450, 0, 10, 0);
    glScalef(2.5, 1, 18);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(210/255.f, 105/255.f, 30/255.f);
    glTranslatef(20, -2, -17);
    glRotatef(450, 0, 10, 0);
    glScalef(2.5, 1, 18);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(210/255.f, 105/255.f, 30/255.f);
    glTranslatef(28, -2, -20);
    glRotatef(450, 0, 10, 0);
    glScalef(7, 1, 2);
    glutSolidCube(1);
    glPopMatrix();
    //TV UTAMA
    glPushMatrix();
    glColor3f(0/255.f, 20/255.f, 59/255.f);
    glTranslatef(29, 0, -3);
    glRotatef(450, 0, 10, 0);
    glScalef(10, 6, 1);
    glutSolidCube(1);
    glPopMatrix();
    //Lukisan
    glPushMatrix();
    glColor3f(0, 1, 254/255.f);
    glTranslatef(-20, 7, 9);
    glRotatef(450, 0, 10, 0);
    glScalef(1, 6, 10);
    glutSolidCube(1);
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("LOIS CEKA-672018240");
    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    init();

    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}
