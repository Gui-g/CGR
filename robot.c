#include <GL/glut.h>

static GLfloat yRot = 0.0f;
static GLfloat zMove = 0.1f;
static GLfloat yMove = -1.0f;

void ChangeSize(int w, int h){
    GLfloat fAspect;

    if(h == 0)
        h = 1;

    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w/(GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(35.0f, fAspect, 1.0, 40.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void SpecialKeys(int key, int x, int y) {

    if(key==GLUT_KEY_UP) {
        yMove += 0.5f;
    };
    if(key==GLUT_KEY_DOWN) {
        zMove -= 0.5f;
    };
    if(key == GLUT_KEY_LEFT) {
        yRot -= 5.0f;
    };
    if(key == GLUT_KEY_RIGHT) {
        yRot += 5.0f;
    };
    yRot = (GLfloat)((const int)yRot % 360);

    glutPostRedisplay();
}

void SetupRC() {
    GLfloat  whiteLight[] = { 0.05f, 0.05f, 0.05f, 1.0f };
    GLfloat  sourceLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };
    GLfloat  lightPos[] = { -10.f, 5.0f, 5.0f, 1.0f };

    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);

    glEnable(GL_LIGHTING);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
    glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void buildRobot(){
	
    GLUquadricObj *pObj;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();
	
	glTranslatef(0.0f,yMove,zMove);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	
	pObj = gluNewQuadric();
    gluQuadricDrawStyle(pObj, GLU_FILL);
	gluQuadricNormals(pObj, GLU_SMOOTH);
	
    //Body
    glPushMatrix();
        glScalef(2.5f, 6.0f, 1.75f);
        glutSolidCube(1.0f);
    glPopMatrix();

    //Shoulders
    glPushMatrix();
        glScalef(1.1f, 0.5f, 1.75f);
        glTranslatef(-1.75f, 5.0f, 0.0f);
        glutSolidCube(1.0f);
        glTranslatef(3.5f, 0.0f, 0.0f);
        glutSolidCube(1.0f);
    glPopMatrix();

    //Arms
    glPushMatrix();
        glScalef(0.6f, 2.25f, 1.0f);
        glTranslatef(-3.0f, 0.445f, 0.0f);
        glutSolidCube(1.0f);
        glTranslatef(6.0f, 0.0f, 0.0f);
        glutSolidCube(1.0f);
    glPopMatrix();

    //Forearms
    glPushMatrix();
        glScalef(0.6f, 2.25f, 1.0f);
        glTranslatef(-3.0f, -0.615f, 0.0f);
        glutSolidCube(1.0f);
        glTranslatef(6.0f, 0.0f, 0.0f);
        glutSolidCube(1.0f);
    glPopMatrix();

    //Thigh
    glPushMatrix();
        glScalef(1.0f, 2.45f, 1.25f);
        glTranslatef(-0.65f, -1.75f, 0.0f);
        glutSolidCube(1.0f);
        glTranslatef(1.3f, 0.0f, 0.0f);
        glutSolidCube(1.0f);
    glPopMatrix();

    //Leg
    glPushMatrix();
        glScalef(1.0f, 2.5f, 1.25f);
        glTranslatef(-0.65f, -2.75f, 0.0f);
        glutSolidCube(1.0f);
        glTranslatef(1.3f, 0.0f, 0.0f);
        glutSolidCube(1.0f);
    glPopMatrix();

    //Hands
    glPushMatrix();
        glScalef(0.5f, 0.75f, 0.75f);
        glTranslatef(-3.6f, -4.05f, 0.0f);
        glutSolidCube(1.0f);
        glTranslatef(7.2f, 0.0f, 0.0f);
        glutSolidCube(1.0f);
    glPopMatrix();

    //Feet
    glPushMatrix();
        glScalef(1.0f, 0.75f, 2.0f);
        glTranslatef(-0.65f, -11.5f, 0.2f);
        glutSolidCube(1.0f);
        glTranslatef(1.3f, 0.0f, 0.0f);
        glutSolidCube(1.0f);
    glPopMatrix();

    //Head
    glPushMatrix();
        glScalef(2.3f, 1.6f, 1.75f);
        glTranslatef(0.0f, 2.5f, 0.0f);
        glutSolidCube(1.0f);
    glPopMatrix();

    //Shoulder Joints
    glPushMatrix();
        glTranslatef(-1.25f, 2.5f, 0.0f);
        gluSphere(pObj, 0.35f, 50, 30);
        glTranslatef(2.5f, 0.0f, 0.0f);
        gluSphere(pObj, 0.35f, 50, 30);
    glPopMatrix();

    //Arm Joints
    glPushMatrix();
        glTranslatef(-1.8f, 2.25f, 0.0f);
        gluSphere(pObj, 0.25f, 50, 30);
        glTranslatef(3.6f, 0.0f, 0.0f);
        gluSphere(pObj, 0.25f, 50, 30);
    glPopMatrix();

    //Forearms Joints
    glPushMatrix();
        glTranslatef(-1.8f, -0.15f, 0.0f);
        gluSphere(pObj, 0.25f, 50, 30);
        glTranslatef(3.6f, 0.0f, 0.0f);
        gluSphere(pObj, 0.25f, 50, 30);
    glPopMatrix();

    //Hip-Thigh Joints
    glPushMatrix();
        glTranslatef(-0.65f, -3.0f, 0.0f);
        gluSphere(pObj, 0.35f, 50, 30);
        glTranslatef(1.3f, 0.0f, 0.0f);
        gluSphere(pObj, 0.35f, 50, 30);
    glPopMatrix();

    //Knee Joints
    glPushMatrix();
        glTranslatef(-0.65f, -5.55f, 0.0f);
        gluSphere(pObj, 0.35f, 50, 30);
        glTranslatef(1.3f, 0.0f, 0.0f);
        gluSphere(pObj, 0.35f, 50, 30);
    glPopMatrix();

    //Hand Joints
    glPushMatrix();
        glTranslatef(-1.8f, -2.55f, 0.0f);
        gluSphere(pObj, 0.25f, 50, 30);
        glTranslatef(3.6f, 0.0f, 0.0f);
        gluSphere(pObj, 0.25f, 50, 30);
    glPopMatrix();

    //Feet Joints
    glPushMatrix();
        glTranslatef(-0.65f, -8.15f, 0.0f);
        gluSphere(pObj, 0.35f, 50, 30);
        glTranslatef(1.3f, 0.0f, 0.0f);
        gluSphere(pObj, 0.35f, 50, 30);
    glPopMatrix();

    //Neck
    glPushMatrix();
        glTranslatef(0.0f, 3.35f, 0.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(pObj, 0.25f, 0.25f, 0.5f, 50, 30);
    glPopMatrix();

    //Eyes
    glPushMatrix();
        glScalef(0.5f, 0.5f, 0.5f);
        glTranslatef(-1.0f, 8.0f, 1.75f);
        glutSolidCube(1.0f);
        glTranslatef(2.0f, 0.0f, 0.0f);
        glutSolidCube(1.0f);
    glPopMatrix();
    
    glPopMatrix();
    glutSwapBuffers();
}


int main(int argc, char *argv[]) { 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowSize(800, 600);
    glutCreateWindow("Robot");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(buildRobot);  
    SetupRC();
    glutMainLoop(); 
    return 0;
}