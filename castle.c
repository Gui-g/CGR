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
        yMove -= 0.5f;
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

void buildCastle(){
	
    GLUquadricObj *pObj;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();
	
	glTranslatef(0.0f,yMove,zMove);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	
	pObj = gluNewQuadric();
    gluQuadricDrawStyle(pObj, GLU_FILL);
	gluQuadricNormals(pObj, GLU_SMOOTH);
		
	//Floor
    glColor3f(0.5f, 0.25f, 0.5f);
    glPushMatrix();
        glScalef(6.0f, 0.5f, 6.0f);
        glutSolidCube(2.0f);
    glPopMatrix();

    //Towers
    glColor3f(0.5f, 0.04f, 0.7f);
    glPushMatrix();
        glTranslatef(5.0f, 2.0f, 5.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(pObj, 1.0f, 1.0f, 2.0f, 50, 30);
        glTranslatef(-10.0f, 0.0f, 0.0f);
        gluCylinder(pObj, 1.0f, 1.0f, 2.0f, 50, 30);
        glTranslatef(0.0f, -10.0f, 0.0f);
        gluCylinder(pObj, 1.0f, 1.0f, 2.0f, 50, 30);
        glTranslatef(10.0f, 0.0f, 0.0f);
        gluCylinder(pObj, 1.0f, 1.0f, 2.0f, 50, 30);
    glPopMatrix();

    //Towers Top
    glPushMatrix();
        glTranslatef(5.0f, 3.0f, 5.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(pObj,0.0f, 1.0f, 1.0f, 50, 30);
        glTranslatef(-10.0f, 0.0f, 0.0f);
        gluCylinder(pObj,0.0f, 1.0f, 1.0f, 50, 30);
        glTranslatef(0.0f, -10.0f, 0.0f);
        gluCylinder(pObj,0.0f, 1.0f, 1.0f, 50, 30);
        glTranslatef(10.0f, 0.0f, 0.0f);
        gluCylinder(pObj,0.0f, 1.0f, 1.0f, 50, 30);
    glPopMatrix();

    //Walls
    glColor3f(0.0f, 0.5f, 0.5f);
    //Front Walls
    glPushMatrix();
        glTranslatef(2.5f, 0.5f, 5.0f);
        glScalef(3.5f, 2.0f, 1.0f);
        glutSolidCube(1.0f);
        glTranslatef(-1.5f, 0.0f, 0.0f);
        glutSolidCube(1.0f);
    glPopMatrix();
    //Side Walls
    glPushMatrix();
        glTranslatef(5.0f, 1.0f, 0.5f);
        glScalef(1.0f, 1.0f, 10.0f);
        glutSolidCube(1.0f);
        glTranslatef(-10.0f, 0.0f, 0.0f);
        glutSolidCube(1.0f);
    glPopMatrix();
    //Back Walls
    glPushMatrix();
        glTranslatef(0.0f, 1.0f, -5.5f);
        glScalef(10.0f, 1.0f, 0.0f);
        glutSolidCube(1.0f);
    glPopMatrix();

    //Gate
    glColor3f(0.0f, 0.0f, 0.5f);
    //Gate Side Structure
    glPushMatrix();
        glTranslatef(0.5f, 0.5f, 5.0f);
        glScalef(0.5f, 2.0f, 1.5f);
        glutSolidCube(1.0f);
        glTranslatef(-2.5f, 0.0f, 0.0f);
        glutSolidCube(1.0f);
    glPopMatrix();
    //Gate Top Structure
    glPushMatrix();
        glTranslatef(-0.125f, 1.5f, 5.0f);
        glScalef(1.75f, 0.5f, 1.5f);
        glutSolidCube(1.0f);
    glPopMatrix();

    //Castle
    glColor3f(0.5f, 0.5f, 0.5f);
    //Castle Body
    glPushMatrix();
        glTranslatef(-0.1f, 2.5f, 0.0f);
        glScalef(2.0f, 2.0f, 2.0f);
        glutSolidCube(2.0f);
    glPopMatrix();

    //Castle Tower
    glPushMatrix();
        glTranslatef(-0.1f, 5.5f, 0.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(pObj,1.0f, 1.0f, 1.0f, 50, 30);
    glPopMatrix();

    //Castle Tower Top
    glPushMatrix();
        glTranslatef(-0.1f, 6.5f, 0.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(pObj,0.0f, 1.0f, 1.0f, 50, 30);
    glPopMatrix();
    
    glPopMatrix();
    glutSwapBuffers();
}


int main(int argc, char *argv[]) { 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowSize(800, 600);
    glutCreateWindow("Castle");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(buildCastle);  
    SetupRC();
    glutMainLoop(); 
    return 0;
}