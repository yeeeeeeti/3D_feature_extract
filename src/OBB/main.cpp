#include <GL/gl.h>
#include <GL/glu.h>

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Mesh.h"
#include "BoundingBox.h"


int gridX = 600;
int gridY = 600;
int gridZ = 600;

const double fovy = 50.;
const double clipNear = .01;
const double clipFar = 1000.;
double x = 0;
double y = 0;
double z = -2.5;

	// used for mouse motion
	int oldX_, oldY_, newX_, newY_;

	// Mesh orientation variables
	float elevation_;
	float azimuth_;
	float dist_;

	// width, height of window
	int width_;
	int height_;

	// previous window width, height
	int oldWidth_;
	int oldHeight_;

// Model orientation
const float ORIG_ELEVATION = 0.0f;
const float ORIG_AZIMUTH = 0.0f;
const float ORIG_DIST = 3.0f;

const float MIN_DISTANCE = 0.1f;
const float MAX_DISTANCE = 100.0f;

bool mouseLeftDown;
bool mouseRightDown;
bool mouseMiddleDown;
float mouseX, mouseY;
float cameraDistanceX;
float cameraDistanceY;
float cameraAngleX;
float cameraAngleY;
float times=1;


std::vector<std::string> paths =
{"E:/MyProjs/WeNext201901/OBB/models/cube.obj",
 "E:/MyProjs/WeNext201901/OBB/models/bunny.obj"};

Mesh mesh;
bool success = true;
bool drawAABB = true;
BoundingBox boundingBox;

void printInstructions()
{
    std::cerr << "space: toggle between meshes\n"
              << "b: toggle between axis aligned and oriented bounding box"
              << "¡ü/¡ý: move in/out\n"
              << "w/s: move up/down\n"
              << "a/d: move left/right\n"
              << "escape: exit program\n"
              << std::endl;
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

void drawBox(const Eigen::Vector3d& b1, const Eigen::Vector3d& b2, const Eigen::Vector3d& b3,
             const Eigen::Vector3d& b4, const Eigen::Vector3d& b5, const Eigen::Vector3d& b6,
             const Eigen::Vector3d& b7, const Eigen::Vector3d& b8)
{
    glColor4f(1.0, 1.0, 1.0, 0.6);

    glBegin(GL_LINE_LOOP);
    glVertex3d(b1.x(), b1.y(), b1.z());
    glVertex3d(b2.x(), b2.y(), b2.z());
    glVertex3d(b3.x(), b3.y(), b3.z());
    glVertex3d(b4.x(), b4.y(), b4.z());
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3d(b5.x(), b5.y(), b5.z());
    glVertex3d(b6.x(), b6.y(), b6.z());
    glVertex3d(b7.x(), b7.y(), b7.z());
    glVertex3d(b8.x(), b8.y(), b8.z());
    glEnd();

    glBegin(GL_LINES);
    glVertex3d(b1.x(), b1.y(), b1.z());
    glVertex3d(b5.x(), b5.y(), b5.z());

    glVertex3d(b2.x(), b2.y(), b2.z());
    glVertex3d(b6.x(), b6.y(), b6.z());

    glVertex3d(b3.x(), b3.y(), b3.z());
    glVertex3d(b7.x(), b7.y(), b7.z());

    glVertex3d(b4.x(), b4.y(), b4.z());
    glVertex3d(b8.x(), b8.y(), b8.z());
    glEnd();
}

void drawFaces()
{
    glColor4f(0.0, 0.0, 1.0, 0.6);
    for (FaceCIter f = mesh.faces.begin(); f != mesh.faces.end(); f++) {

        if (f->isBoundary()) continue;

        glBegin(GL_LINE_LOOP);
        HalfEdgeCIter he = f->he;
        do {
            glVertex3d(he->vertex->position.x(), he->vertex->position.y(), he->vertex->position.z());

            he = he->next;

        } while (he != f->he);

        glEnd();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    double aspect = (double)viewport[2] / (double)viewport[3];
    gluPerspective(fovy, aspect, clipNear, clipFar);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0, 0, z, x, y, 0, 0, 1, 0);

    glRotatef(elevation_,1,0,0);
    glRotatef(azimuth_,0,1,0);

    if (success) {
        drawFaces();

        if (drawAABB) {
            Eigen::Vector3d max = boundingBox.max;
            Eigen::Vector3d min = boundingBox.min;
            Eigen::Vector3d extent = boundingBox.extent;

            Eigen::Vector3d b2(min.x() + extent.x(), min.y(), min.z());
            Eigen::Vector3d b3(min.x() + extent.x(), min.y() + extent.y(), min.z());
            Eigen::Vector3d b4(min.x(), min.y() + extent.y(), min.z());
            Eigen::Vector3d b5(max.x() - extent.x(), max.y() - extent.y(), max.z());
            Eigen::Vector3d b6(max.x(), max.y() - extent.y(), max.z());
            Eigen::Vector3d b8(max.x() - extent.x(), max.y(), max.z());

            drawBox(min, b2, b3, b4, b5, b6, max, b8);

        } else {
            std::vector<Eigen::Vector3d> orientedPoints = boundingBox.orientedPoints;

            Eigen::Vector3d b1 = orientedPoints[0] + orientedPoints[2] + orientedPoints[4];
            Eigen::Vector3d b2 = orientedPoints[1] + orientedPoints[2] + orientedPoints[4];
            Eigen::Vector3d b3 = orientedPoints[1] + orientedPoints[2] + orientedPoints[5];
            Eigen::Vector3d b4 = orientedPoints[0] + orientedPoints[2] + orientedPoints[5];
            Eigen::Vector3d b5 = orientedPoints[0] + orientedPoints[3] + orientedPoints[4];
            Eigen::Vector3d b6 = orientedPoints[1] + orientedPoints[3] + orientedPoints[4];
            Eigen::Vector3d b8 = orientedPoints[0] + orientedPoints[3] + orientedPoints[5];
            Eigen::Vector3d b7 = orientedPoints[1] + orientedPoints[3] + orientedPoints[5];

            drawBox(b1, b2, b3, b4, b5, b6, b7, b8);
        }
    }

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x0, int y0)
{
    switch (key) {
        case 27 :
            exit(0);
        case ' ':
            static int i = 0;
            i++;
            if (i == 2) i = 0;
            mesh.read(paths[i]);
            if (drawAABB) boundingBox.computeAxisAlignedBox(mesh.vertices);
            else boundingBox.computeOrientedBox(mesh.vertices);
            break;
        case 'b':
///            drawAABB = !drawAABB;
///            if (drawAABB) {
///                boundingBox.computeAxisAlignedBox(mesh.vertices);
///                glutSetWindowTitle("Bounding Box - Axis Aligned");
///            } else {
                boundingBox.computeOrientedBox(mesh.vertices);
                glutSetWindowTitle("Bounding Box - Oriented");
 ///           }
            break;
        case 'a':
            x -= 0.03;
            break;
        case 'd':
            x += 0.03;
            break;
        case 'w':
            y += 0.03;
            break;
        case 's':
            y -= 0.03;
            break;
    }

    glutPostRedisplay();
}

void special(int i, int x0, int y0)
{
    switch (i) {
        case GLUT_KEY_UP:
            z += 0.03;
            break;
        case GLUT_KEY_DOWN:
            z -= 0.03;
            break;
    }

    glutPostRedisplay();
}

void mouseCB(int button, int state, int x, int y)
{
    mouseX = x;
    mouseY = y;
    times = 1;

    if(button == GLUT_LEFT_BUTTON)
    {
        if(state == GLUT_DOWN)
        {
            mouseLeftDown = true;
        }
        else if(state == GLUT_UP)
            mouseLeftDown = false;
    }

    else if(button == GLUT_RIGHT_BUTTON)
    {
        if(state == GLUT_DOWN)
        {
            mouseRightDown = true;
        }
        else if(state == GLUT_UP)
            mouseRightDown = false;
    }

    /*
    * 鼠标滚轮控制图形缩放
    */
    else if (state == GLUT_UP && button == GLUT_WHEEL_UP)
    {
        times = 0.008f+1;
        glutPostRedisplay();
    }

    else if (state == GLUT_UP && button == GLUT_WHEEL_DOWN)
    {
        times = -0.008f+1;
        glutPostRedisplay();
    }
}

// Handle mouse motion
void mouseMotionCB(int x, int y)
{
 	oldX_ = newX_;
	oldY_ = newY_;
	newX_ = x;
	newY_ = y;

	if (newX_ & 0x1000) newX_ = -(0xFFFF - newX_); // when move mouse up, turns from 0 to 65535
	if (newY_ & 0x1000) newY_ = -(0xFFFF - newY_); // turn an unsigned value to a signed value so math works

	float RelX = (newX_ - oldX_) / (float)width_;
	float RelY = (newY_ - oldY_) / (float)height_;

	// Change distance
	if (mouseRightDown)
	{
		dist_ += 10 * RelY;

		if (dist_ > MAX_DISTANCE) dist_ = MAX_DISTANCE;
		if (dist_ < MIN_DISTANCE) dist_ = MIN_DISTANCE;
	// Rotation
	}
	else if (mouseLeftDown)
	{ // left button down
		azimuth_ += (RelX*180);
		elevation_ += (RelY*180);
	}

    glutPostRedisplay();
}


int main(int argc, char** argv) {

    success = mesh.read(paths[0]);
    if (success)
        boundingBox.computeAxisAlignedBox(mesh.vertices);

    printInstructions();
    glutInitWindowSize(gridX, gridY);

    width_ = gridX;
	height_ = gridY;


    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInit(&argc, argv);
    glutCreateWindow("Bounding Box - Axis Aligned");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);

    glutMouseFunc(mouseCB);
    glutMotionFunc(mouseMotionCB);

    glutMainLoop();

    return 0;
}

