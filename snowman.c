#include <GL/glut.h>

static GLfloat yRot = 0.0f;

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

    if(key == GLUT_KEY_LEFT) {
        yRot -= 5.0f;
    }
    if(key == GLUT_KEY_RIGHT) {
        yRot += 5.0f;
    }

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

void buildSnowman(){
	
    GLUquadricObj *pObj;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();
	
	glTranslatef(0.0f,-1.0f,-5.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	
	pObj = gluNewQuadric();
	gluQuadricNormals(pObj, GLU_SMOOTH);
		
	//Body
    glColor3f(1.0f, 1.0f, 1.0f);
    //Bottom Part
	glPushMatrix();        
        gluSphere(pObj, 0.6f, 80, 50);
    glPopMatrix();
    //Mid Part
    glPushMatrix();
        glTranslatef(0.0f, 0.8f, 0.0f);
        gluSphere(pObj, 0.5f, 80, 50);
    glPopMatrix();
    //Head
    glPushMatrix();
        glTranslatef(0.0f, 1.5f, 0.0f);
        gluSphere(pObj, 0.4f, 80, 50);
    glPopMatrix();
    //Button / Eye Color
    glColor3f(0.0f, 0.0f, 0.0f);
    //Bottom Buttons
    glPushMatrix();
        glTranslatef(0.0f, -0.15f, 0.6f);
        gluSphere(pObj, 0.1f, 80, 50);
        glTranslatef(0.0f, 0.25f, 0.02f);
        gluSphere(pObj, 0.1f, 80, 50);
        glTranslatef(0.0f, 0.25f, -0.1f);
        gluSphere(pObj, 0.1f, 80, 50);
    glPopMatrix();
    //Middle Buttons
    glPushMatrix();
        glTranslatef(0.0f, 0.7f, 0.5f);
        gluSphere(pObj, 0.1f, 80, 50);
        glTranslatef(0.0, 0.25f, -0.05f);
        gluSphere(pObj, 0.1f, 80, 50);
    glPopMatrix();
    //Eyes
    glPushMatrix();
        glTranslatef(-0.1f, 1.6f, 0.3f);
        gluSphere(pObj, 0.1f, 80, 50);
        glTranslatef(0.3f, 0.0f, -0.05f);
        gluSphere(pObj, 0.1f, 80, 50);
    glPopMatrix();
    //Nose color
    glColor3f(1.0f, 0.5f, 0.0f);
    //Nose
    glPushMatrix();
        glTranslatef(0.05f, 1.5f, 0.3f);
        gluCylinder(pObj, 0.1f, 0.0f, 0.6f, 80, 50);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}


int main(int argc, char *argv[]) { 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowSize(800, 600);
    glutCreateWindow("Snowman");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(buildSnowman);  
    SetupRC();
    glutMainLoop(); 
    return 0;
}