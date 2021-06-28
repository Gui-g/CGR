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