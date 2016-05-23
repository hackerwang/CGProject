#include "stdafx.h"
#include <gl/freeglut.h>
#include <math.h>
#include "Plot3D.h"
#include "teapot.h"
#include "text3d.h"

CcgProjectDlg* handle;

//������
GLuint texKing;

GLfloat light_position[] = { 600.0,600.0,600.0,0.0 };
GLfloat no_mat[] = { 0.0,0.0,0.0,1.0 };
GLfloat mat_grey_ambient[] = { 0.5,0.5,0.5,1.0 };
GLfloat mat_green_ambient[] = { 0.0,1.0,0.0,1.0 };
GLfloat mat_diffuse[] = { 0.2,0.2,0.2,1.0 };
GLfloat mat_specular[] = { 0.2,1.0,0.2,1.0 };
GLfloat no_shininess[] = { 0.0 };
GLfloat low_shininess[] = { 5.0 };
GLfloat high_shininess[] = { 100.0 };
GLfloat mat_emission[] = { 0.2,0.2,0.2,0.0 };

//��ȡ��Ļ�Ŀ��
GLint SCREEN_WIDTH = 0;
GLint SCREEN_HEIGHT = 0;
//���ó���Ĵ��ڴ�С
GLint windowWidth = 800;
GLint windowHeight = 600;
//��x����ת�Ƕ�
GLfloat xRotAngle = 0.0f;
//��y����ת�Ƕ�
GLfloat yRotAngle = 0.0f;
//��֧�ֵĵ��С��Χ
GLfloat sizes[2];
//��֧�ֵĵ��С����
GLfloat step;

GLint iModel = TEAPOT;
bool bManual = true;
bool notquit = true;

void change_model(CcgProjectDlg* phandle, GLint model, bool manual)
{
	handle = phandle;
	iModel = model;
	bManual = manual;
	xRotAngle = 0.0f;
	yRotAngle = 0.0f;
	notquit = true;
}

//��ʾ�ص�����
void renderScreen(void) {
	//��������ɫ����Ϊ��ɫ
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//��ģ�建����ֵȫ������Ϊ1
	glClearStencil(1);
	//ʹ��ģ�建����
	glEnable(GL_STENCIL_TEST);
	//��������������Ϊ��ǰ������ɫ����ɫ�������Ȼ�������ģ�建����
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	//����ǰMatrix״̬��ջ
	glPushMatrix();
	//����ϵ��x����תxRotAngle
	glRotatef(xRotAngle, 1.0f, 0.0f, 0.0f);
	//����ϵ��y����תyRotAngle
	glRotatef(yRotAngle, 0.0f, 1.0f, 0.0f);
	//����ƽ������
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH, GL_NICEST);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH, GL_NICEST);
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH, GL_NICEST);

	if (iModel == TEAPOT)
	{
		//��ɫ��������ϵ
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_LINES);
		glVertex3f(-3.0f, 0.0f, 0.0f);
		glVertex3f(3.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, -3.0f, 0.0f);
		glVertex3f(0.0f, 3.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, -3.0f);
		glVertex3f(0.0f, 0.0f, 3.0f);
		glEnd();

		glPushMatrix();
		glTranslatef(3.0f, 0.0f, 0.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glutSolidCone(0.1, 0.2, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, 3.0f, 0.0f);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		glutSolidCone(0.1, 0.2, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, 0.0f, 3.0f);
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
		glutSolidCone(0.1, 0.2, 10, 10);
		glPopMatrix();
	}
	else
	{
		//��ɫ��������ϵ
		glColor3f(1.0f, 1.0f, 1.0f);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, no_mat);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, no_mat);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, no_mat);

		glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);//ʹ����ɫ���ٵ�ǰ��ɫ

		glBegin(GL_LINES);
		glVertex3f(-500.0f, 0.0f, 0.0f);
		glVertex3f(500.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, -500.0f, 0.0f);
		glVertex3f(0.0f, 500.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, -500.0f);
		glVertex3f(0.0f, 0.0f, 500.0f);
		glEnd();

		glPushMatrix();
		glTranslatef(500.0f, 0.0f, 0.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glutSolidCone(10, 20, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, 500.0f, 0.0f);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		glutSolidCone(10, 20, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, 0.0f, 500.0f);
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
		glutSolidCone(10, 20, 10, 10);
		glPopMatrix();
	}

	//���û滭��ɫΪ��ɫ
	glColor3f(0.0f, 1.0f, 0.0f);
	switch (iModel) 
	{
		//���
	case TEAPOT:
		DrawTeapot();
		break;
	case TEXT:
		/*Ϊ����ģ��ָ�����ʲ���*/
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, no_shininess);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, no_mat);
		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);//ʹ����ɫ���ٵ�ǰ��ɫ
		glColor3f(0.0f, 1.0f, 0.0f);
		DrawText3D();
		break;
	case TEXTURE:
		DrawText3DTexture();
		break;
	default:
		break;
	}
	//�ָ�ѹ��ջ��Matrix
	glPopMatrix();
	//����������������ָ��
	glutSwapBuffers();
}
//����Redering State 
void setupRederingState(void) {
	//����������ɫΪ��ɫ
	glClearColor(0.0f, 0.0, 0.0, 1.0f);
	if (iModel != TEAPOT)
	{
		//��������
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_COLOR_MATERIAL);
	}
	//���û滭��ɫΪ��ɫ
	glColor3f(0.0f, 1.0f, 0.0f);
	//ʹ����Ȳ���
	glEnable(GL_DEPTH_TEST);
	//2D����
	if (iModel == TEXTURE)
	{
		glEnable(GL_TEXTURE_2D);
		texKing = load_texture("texture.bmp");
	}
	//��ȡ��֧�ֵĵ��С��Χ
	glGetFloatv(GL_POINT_SIZE_RANGE, sizes);
	//��ȡ��֧�ֵĵ��С����
	glGetFloatv(GL_POINT_SIZE_GRANULARITY, &step);
}

//���ڴ�С�仯�ص�����
void changSize(GLint w, GLint h) {
	//������
	GLfloat ratio, coordinatesize;
	//��������ϵΪx(-100.0f,100.0f)��y(-100.0f,100.0f)��z(-100.0f,100.0f)
	if (iModel == TEAPOT)
		coordinatesize = 4.0f;
	else
		coordinatesize = 800.0f;
	//���ڿ��Ϊ��ֱ�ӷ���
	if ((w == 0) || (h == 0))
		return;
	//�����ӿںʹ��ڴ�Сһ��
	glViewport(0, 0, w, h);
	//��ͶӰ����Ӧ�����ľ������
	glMatrixMode(GL_PROJECTION);
	//���õ�ǰָ���ľ���Ϊ��λ����
	glLoadIdentity();
	ratio = (GLfloat)w / (GLfloat)h;
	//����ͶӰ
	if (w<h)
		glOrtho(-coordinatesize, coordinatesize, -coordinatesize / ratio, coordinatesize / ratio, -coordinatesize, coordinatesize);
	else
		glOrtho(-coordinatesize*ratio, coordinatesize*ratio, -coordinatesize, coordinatesize, -coordinatesize, coordinatesize);
	//��ģ����ͼ�����ջӦ�����ľ������
	glMatrixMode(GL_MODELVIEW);
	//���õ�ǰָ���ľ���Ϊ��λ����
	glLoadIdentity();
}

//�������봦��ص�����
void specialKey(int key, int x, int y) {

	if (key == GLUT_KEY_UP) {
		xRotAngle -= 5.0f;
	}
	else if (key == GLUT_KEY_DOWN) {
		xRotAngle += 5.0f;
	}
	else if (key == GLUT_KEY_LEFT) {
		yRotAngle -= 5.0f;
	}
	else if (key == GLUT_KEY_RIGHT) {
		yRotAngle += 5.0f;
	}
	//���»���
	glutPostRedisplay();
}
void OnTimer(int value)
{
	if (notquit)
	{
		xRotAngle += 2.5f;
		yRotAngle += 1.5f;
		glutPostRedisplay();
		glutTimerFunc(50, OnTimer, 1);
	}
}
void OnClose()
{
	notquit = false;
	Sleep(100);
}
void plot3d()
{
	int argc = 0;
	//��ʼ��glut 
	glutInit(&argc, NULL);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	//ʹ��˫����������Ȼ�������ģ�建����
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	//��ȡϵͳ�Ŀ�����
	SCREEN_WIDTH = glutGet(GLUT_SCREEN_WIDTH);
	//��ȡϵͳ�ĸ�����
	SCREEN_HEIGHT = glutGet(GLUT_SCREEN_HEIGHT);
	glutCreateWindow("3D Display");
	//���ô��ڴ�С
	glutReshapeWindow(windowWidth, windowHeight);
	//���ھ�����ʾ
	glutPositionWindow((SCREEN_WIDTH - windowWidth) / 2, (SCREEN_HEIGHT - windowHeight) / 2);
	//���ڴ�С�仯ʱ�Ĵ�����
	glutReshapeFunc(changSize);
	//������ʾ�ص����� 
	glutDisplayFunc(renderScreen);
	if (bManual)
	{
		//���ð������봦��ص�����
		glutSpecialFunc(specialKey);
	}
	else
	{
		glutTimerFunc(50, OnTimer, 1);
		glutCloseFunc(OnClose);
	}

	//����ȫ����Ⱦ����
	setupRederingState();
	glutMainLoop();
}

double CalcCoeff(int nn, int k)
{
	int i;
	double sum = 1;
	for (i = 1; i <= k; i++)
		sum = sum * (nn - i + 1) / i;
	return sum;
}

//����Bezier�����ϵ������
Point3 CalcBezierPoint(float points[][2], double t, int n)
{
	double Ber;
	int k;
	Point3 p;
	for (k = 0;k < n;k++)
	{
		Ber = CalcCoeff(n - 1, k)*pow(t, k)*pow(1 - t, n - 1 - k);
		p.x += points[k][0] * Ber;
		p.y += points[k][1] * Ber;
	}
	return p;
}
Point3 CalcBezierPoint(float points[][3], double t, int n)
{
	double Ber;
	int k;
	Point3 p;
	for (k = 0;k < n;k++)
	{
		Ber = CalcCoeff(n - 1, k)*pow(t, k)*pow(1 - t, n - 1 - k);
		p.x += points[k][0] * Ber;
		p.y += points[k][1] * Ber;
		p.z += points[k][2] * Ber;
	}
	return p;
}

//����n�����Ƶ㣬�������ϵ�m+1����
void CalcBezierCurve(float points[][2], int n, int m, Point3 *v)
{
	int i;
	for (i = 0;i <= m;i++)
		v[i] = CalcBezierPoint(points, (double)i / (double)m, n);
}
void CalcBezierCurve(float points[][3], int n, int m, Point3 *v)
{
	int i;
	for (i = 0;i <= m;i++)
		v[i] = CalcBezierPoint(points, (double)i / (double)m, n);
}

/* ����power_of_two
* ���һ�������Ƿ�Ϊ2�������η�������ǣ�����1�����򷵻�0
* ʵ����ֻҪ�鿴�������λ���ж��ٸ������������1��������1�����򷵻�0
* �ڡ��鿴�������λ���ж��ٸ���ʱʹ����һ��С����
* ʹ��n &= (n-1)����ʹ��n�еļ���һ��������ԭ���ҿ����Լ�˼����
*/
bool power_of_two(int n)
{
	if (n <= 0)
		return 0;
	return (n & (n - 1)) == 0;
}

/* ����load_texture
* ��ȡһ��BMP�ļ���Ϊ����
* ���ʧ�ܣ�����0������ɹ�������������
*/
GLuint load_texture(const char* file_name)
{
	GLint width, height, total_bytes;
	GLubyte* pixels = 0;
	GLuint last_texture_ID, texture_ID = 0;

	// ���ļ������ʧ�ܣ�����
	FILE* pFile = fopen(file_name, "rb");
	if (pFile == 0)
		return 0;

	// ��ȡ�ļ���ͼ��Ŀ�Ⱥ͸߶�
	fseek(pFile, 0x0012, SEEK_SET);
	fread(&width, 4, 1, pFile);
	fread(&height, 4, 1, pFile);
	fseek(pFile, BMP_Header_Length, SEEK_SET);

	// ����ÿ��������ռ�ֽ����������ݴ����ݼ����������ֽ���
	{
		GLint line_bytes = width * 3;
		while (line_bytes % 4 != 0)
			++line_bytes;
		total_bytes = line_bytes * height;
	}

	// �����������ֽ��������ڴ�
	pixels = (GLubyte*)malloc(total_bytes);
	if (pixels == 0)
	{
		fclose(pFile);
		return 0;
	}

	// ��ȡ��������
	if (fread(pixels, total_bytes, 1, pFile) <= 0)
	{
		free(pixels);
		fclose(pFile);
		return 0;
	}

	// �ھɰ汾��OpenGL��
	// ���ͼ��Ŀ�Ⱥ͸߶Ȳ��ǵ������η�������Ҫ��������
	// ���ﲢû�м��OpenGL�汾�����ڶ԰汾�����ԵĿ��ǣ����ɰ汾����
	// ���⣬�����Ǿɰ汾�����°汾��
	// ��ͼ��Ŀ�Ⱥ͸߶ȳ�����ǰOpenGLʵ����֧�ֵ����ֵʱ��ҲҪ��������
	{
		GLint max;
		glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max);
		if (!power_of_two(width)
			|| !power_of_two(height)
			|| width > max
			|| height > max)
		{
			const GLint new_width = 256;
			const GLint new_height = 256; // �涨���ź��µĴ�СΪ�߳���������
			GLint new_line_bytes, new_total_bytes;
			GLubyte* new_pixels = 0;

			// ����ÿ����Ҫ���ֽ��������ֽ���
			new_line_bytes = new_width * 3;
			while (new_line_bytes % 4 != 0)
				++new_line_bytes;
			new_total_bytes = new_line_bytes * new_height;

			// �����ڴ�
			new_pixels = (GLubyte*)malloc(new_total_bytes);
			if (new_pixels == 0)
			{
				free(pixels);
				fclose(pFile);
				return 0;
			}

			// ������������
			gluScaleImage(GL_RGB,
				width, height, GL_UNSIGNED_BYTE, pixels,
				new_width, new_height, GL_UNSIGNED_BYTE, new_pixels);

			// �ͷ�ԭ�����������ݣ���pixelsָ���µ��������ݣ�����������width��height
			free(pixels);
			pixels = new_pixels;
			width = new_width;
			height = new_height;
		}
	}

	// ����һ���µ�������
	glGenTextures(1, &texture_ID);
	if (texture_ID == 0)
	{
		free(pixels);
		fclose(pFile);
		return 0;
	}

	// ���µ������������������������
	// �ڰ�ǰ���Ȼ��ԭ���󶨵������ţ��Ա��������лָ�
	glGetIntegerv(GL_TEXTURE_BINDING_2D, (GLint*)&last_texture_ID);
	glBindTexture(GL_TEXTURE_2D, texture_ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
		GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);
	glBindTexture(GL_TEXTURE_2D, last_texture_ID);

	// ֮ǰΪpixels������ڴ����ʹ��glTexImage2D�Ժ��ͷ�
	// ��Ϊ��ʱ���������Ѿ���OpenGL���б�����һ�ݣ����ܱ����浽ר�ŵ�ͼ��Ӳ���У�
	free(pixels);
	return texture_ID;
}
