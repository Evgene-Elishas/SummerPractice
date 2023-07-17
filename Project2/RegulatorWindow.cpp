#include "RegulatorWindow.h"
//#include <windows.h>
//#include <Windowsx.h>
//#include <GL/gl.h>
//#include <GL/glu.h>

#include <fstream>
using namespace std;
ofstream log_file;

#include "Item.h"
#include "Camera.h"


using namespace System::Windows::Forms;
int Width, Height;
Camera camera(glm::vec3(0.0f, 0.0f, 3.5f)); 
MyTexture WheelTex, Wood, RegulatorTex, Rock;
Mesh Wheel, Pipe1, Pipe2, Pipe3, PipeBend, Damper, Reductor, Shaft, Shutter, Engine;
Mesh RegStand, RegShaft, RegLever, RegLeverHolder, RegClutch, 
	RegHingeLeftDown, RegHingeRightDown, RegHingeRightUp, RegHingeLeftUp, RegSphereLeft, RegSphereRight;

glm::vec3 p1(-0.051272, 0.433437, -0.000027), p2(-0.126626, 0.221905, -0.221905), p3(-0.051844, -0.025269, -0.000312);
glm::vec2 p1f(-0.051272, 0.433437), p2f(-0.126626, 0.221905), p3f(-0.051844, -0.025269);
float leng1 = glm::length(p1f - p2f), h1 = p1f.y - p2f.y, tetazero1 = acosf(h1 / leng1), 
	  leng2 = glm::length(p2f - p3f), h2 = p2f.y - p3f.y, tetazero2 = acosf(h2 / leng2),
	  h0 = p1.y - p3.y;


bool RegulatorWindow::InitGL(GLvoid)// инициализация RegulatorWindow
{
	log_file.open("log.txt");
	
	log_file << leng1 << " " << h1 << " " << glm::degrees(tetazero1) << endl << leng2 << " " << h2 << " " << glm::degrees(tetazero2) << endl << h0 << endl;
	log_file.flush();

	WheelTex.Load("WheelWagon.jpg");
	RegulatorTex.Load("RegulatorTex.png");
	Wood.Load("wood-4_smooth.png");
	Rock.Load("Rock_basecolor.jpg");

	Wheel.Load(".objects/Wheel.obj");
	Pipe1.Load(".objects/Pipe1.obj");
	Pipe2.Load(".objects/Pipe2.obj");
	Pipe3.Load(".objects/Pipe3.obj");
	PipeBend.Load(".objects/PipeBend.obj");
	Damper.Load(".objects/Damper.obj");
	Reductor.Load(".objects/Reductor.obj");
	Shaft.Load(".objects/Shaft.obj");
	Shutter.Load(".objects/Shutter.obj");
	Engine.Load(".objects/Engine.obj");

	RegStand.Load(".objects/RegStand.obj");
	RegShaft.Load(".objects/RegShaft.obj");
	RegLever.Load(".objects/RegLever.obj");
	RegLeverHolder.Load(".objects/RegLeverHolder.obj");
	RegClutch.Load(".objects/RegClutch.obj");
	RegHingeLeftDown.Load(".objects/RegHingeLeftDown.obj");
	RegHingeRightDown.Load(".objects/RegHingeRightDown.obj");
	RegHingeRightUp.Load(".objects/RegHingeRightUp.obj");
	RegHingeLeftUp.Load(".objects/RegHingeLeftUp.obj");
	RegSphereLeft.Load(".objects/RegSphereLeft.obj");
	RegSphereRight.Load(".objects/RegSphereRight.obj");

	//glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glClearColor(0.3, 0.25, 0.3, 0.0);
	glClearDepth(1.0f);
	//glDepthFunc(GL_LEQUAL);
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);//Разрешаем использовать цветной материал
	glEnable(GL_LIGHTING);	//разрешаем освещение
	//glEnable(GL_CULL_FACE);
	float ambient[4] = { 0.1,0.1,0.1, 1.0 };//цвет и интенсивность фонового освещения
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);//режим фонового освещения
	glEnable(GL_LIGHT0);
	float pos0[4] = { 0,0,5,1 };//положение точечного источника света
	float amb[4] = { 0,0,0,0 };//цвет и интенсивность
	float color0[4] = { 1,1,1,1 };//цвет и интенсивность источника света
	float color_sp[4] = { 1,1,1,1 };//цвет зеркального источника света
	glLightfv(GL_LIGHT0, GL_POSITION, pos0);//положение нулевой лампы
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, color0);//тип освещения GL_DIFFUSE, цвет нулевой лампы color0
	glLightfv(GL_LIGHT0, GL_SPECULAR, color_sp);//для GL_LIGHT0 установлено по умолчанию

	/*glEnable(GL_LIGHT1);
	float pos1[4] = { 0,0,-5,1 };//положение точечного источника света
	glLightfv(GL_LIGHT1, GL_POSITION, pos1);//положение нулевой лампы
	glLightfv(GL_LIGHT1, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, color0);//тип освещения GL_DIFFUSE, цвет нулевой лампы color0
	glLightfv(GL_LIGHT1, GL_SPECULAR, color_sp);//для GL_LIGHT0 установлено по умолчанию*/


	return TRUE;
}

// функция, вызывающаяся при изменении размеров оьласти вывода 
GLvoid RegulatorWindow::ReSizeGLScene(GLsizei width, GLsizei height)// Resize and initialise the gl window
{
	Width = width; Height = height;
	glViewport(0, 0, width, height);
}

// функция, задающая формат пикселя
GLint RegulatorWindow::MySetPixelFormat(HDC hdc)
{
	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),// Size Of This Pixel Format Descriptor
		1,// Version Number
		PFD_DRAW_TO_WINDOW |// Format Must Support Window
		PFD_SUPPORT_OPENGL |// Format Must Support RegulatorWindow
		PFD_DOUBLEBUFFER,// Must Support Double Buffering
		PFD_TYPE_RGBA,// Request An RGBA Format
		16,// Select Our Color Depth
		0, 0, 0, 0, 0, 0,// Color Bits Ignored
		0,// No Alpha Buffer
		0,// Shift Bit Ignored
		0,// No Accumulation Buffer
		0, 0, 0, 0,// Accumulation Bits Ignored
		16,// 16Bit Z-Buffer (Depth Buffer)  
		0,// No Stencil Buffer
		0,// No Auxiliary Buffer
		PFD_MAIN_PLANE,// Main Drawing Layer
		0,// Reserved
		0, 0, 0// Layer Masks Ignored
	};

	GLint  iPixelFormat;
	if ((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0){
		MessageBox::Show("ChoosePixelFormat Failed"); return 0;
	}
	if (SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE){
		MessageBox::Show("SetPixelFormat Failed");	return 0;
	}
	if ((m_hglrc = wglCreateContext(m_hDC)) == NULL){
		MessageBox::Show("wglCreateContext Failed");	return 0;
	}
	if ((wglMakeCurrent(m_hDC, m_hglrc)) == NULL){
		MessageBox::Show("wglMakeCurrent Failed");	return 0;
	}

	return 1;
}

// конструктор
RegulatorWindow::RegulatorWindow(System::Windows::Forms::Form^ parentForm, int iWidth, int iHeight, int iPosX, int iPosY)
{
	Width = iWidth; Height = iHeight;

	CreateParams^ cp = gcnew CreateParams;
	cp->X = iPosX;  cp->Y = iPosY;  cp->Height = iHeight;  cp->Width = iWidth;
	cp->Parent = parentForm->Handle;
	cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	this->CreateHandle(cp);
	m_hDC = GetDC((HWND)this->Handle.ToPointer());
	if (m_hDC) {
		MySetPixelFormat(m_hDC);
		ReSizeGLScene(iWidth, iHeight);
		InitGL();
	}
}

RegulatorWindow::~RegulatorWindow(System::Void) // деструктор

{
	this->DestroyHandle();
}

void SetProjectionMatrix(Camera& cam) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(cam.Perspective, (GLfloat)Width/Height, 0.15, 1000.0);
	glm::vec3 dest = cam.Position + cam.Front;
	gluLookAt(cam.Position.x, cam.Position.y, cam.Position.z, dest.x, dest.y, dest.z, cam.Up.x, cam.Up.y, cam.Up.z);
	glMatrixMode(GL_MODELVIEW);
}


// функция рисования
System::Void RegulatorWindow::Render(System::Void)
{
	wglMakeCurrent(m_hDC, m_hglrc);
	//fi = fi + this->speed * 0.01 * 360;
	//float teta = this->angle;
	static float mu, teta, teta2;

	if (!IsStopped) {
		if (Tk * Tk - 4 * gamma * Tr_sqr < 0) {
			float beta = -Tk / (2 * Tr_sqr);
			float omega = sqrt(-Tk * Tk + 4 * gamma * Tr_sqr) / (2 * Tr_sqr);
			float c1 = mu0 - fi0 / gamma;
			float c2 = mu0der / omega - beta / omega * c1;
			mu = exp(beta * time) * (c1 * cos(omega * time) + c2 * sin(omega * time)) + fi0 / gamma;
		}
		else {
			float beta = -Tk / (2 * Tr_sqr);
			float omega = sqrt(Tk * Tk - 4 * gamma * Tr_sqr) / (2 * Tr_sqr);
			float lambda1 = beta + omega, lambda2 = beta - omega;
			float c1 = ((mu0 - fi0 / gamma) * lambda2 - mu0der) * -0.5 / omega; // ((mu0 - fi0 / gamma)*lambda2 - mu0der) / (lambda2 - lambda1)
			float c2 = (mu0der - (mu0 - fi0 / gamma) * lambda1) * -0.5 / omega; // (mu0der - (mu0 - fi0 / gamma)*lambda1) / (lambda2 - lambda1)
			mu = c1 * exp(lambda1 * time) + c2 * exp(lambda2 * time) + fi0 / gamma;
		}

		//float mu = omega;
		//mu *= 0.1;
		float h = h0 - mu;

		float Temph = h0 - fi0 / gamma;
		float tempcos = (h * h + leng1 * leng1 - leng2 * leng2) / (2 * h * leng1);
		float tempcos2 = (Temph * Temph + leng1 * leng1 - leng2 * leng2) / (2 * Temph * leng1);

		if (tempcos > 1 || tempcos < -1 || tempcos2 > 1 || tempcos2 < -1) {
			IsStopped = TRUE;
			MessageBox::Show("Impossible parameters");

		}
		else {
			teta = acos((h * h + leng1 * leng1 - leng2 * leng2) / (2 * h * leng1)) - tetazero1;
			teta2 = acos((h * h - leng1 * leng1 + leng2 * leng2) / (2 * h * leng2)) - tetazero2;

			float teta_star = acos((Temph * Temph + leng1 * leng1 - leng2 * leng2) / (2 * Temph * leng1)) - tetazero1;
			float delta_teta = teta - teta_star;
			angle += speed * 0.01 * 360;
			speed -= 0.1 * delta_teta;
		}
		//speed = 10 * mu;
	}
	//teta = mu;
	

	//float teta2 = teta * (tetazero2/ tetazero1);
	//float deltah = (h1 - leng1 * cos(glm::radians(teta) + tetazero1)) + (h2 - leng2 * cos(glm::radians(teta2) + tetazero2));

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	camera.Yaw = -this->yaw - 90;
	camera.Pitch = -this->pitch;
	camera.Position = normalize(camera.Position) * this->distance;
	camera.updateCameraVectors();
	SetProjectionMatrix(camera);

	glPushMatrix();
	
	WheelTex.Bind();	
	
	glPushMatrix();
	glTranslatef(-0.093914, -0.010673, 0);
	glRotatef(angle, 1, 0, 0);
	glTranslatef(0.093914, 0.010673, 0);
	Wheel.Draw();
	glPopMatrix();
	
	Wood.Bind();

	Pipe1.Draw();
	Pipe2.Draw();
	Pipe3.Draw();
	PipeBend.Draw();
	Damper.Draw();
	Shaft.Draw();

	glPushMatrix();
	glTranslatef(0, -mu, 0);
	Shutter.Draw();
	glPopMatrix();

	Rock.Bind();

	Reductor.Draw();
	Engine.Draw();

	RegulatorTex.Bind();

	RegStand.Draw();

	glPushMatrix();
	glTranslatef(-0.24089, -0.135087, 0.0);
	glRotatef(glm::degrees(/*teta) * cosf(teta)*/atan(mu/ 0.24089))*1.1, 0, 0, 1);
	glTranslatef(0.24089, 0.135087, 0.0);
	RegLever.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, mu, 0);
	RegLeverHolder.Draw();
	glPopMatrix();

	glRotatef(angle, 0, 1, 0);

	glPushMatrix();
	glTranslatef(0, mu, 0);
	RegClutch.Draw();
	glPopMatrix();

	RegShaft.Draw();
	
	glPushMatrix();
	glTranslatef(p1.x, p1.y, p1.z);
	glRotatef(glm::degrees(teta), 0,0,-1);
	glTranslatef(-p1.x, -p1.y, -p1.z);
	RegHingeLeftUp.Draw();
	RegSphereLeft.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(p3.x, p3.y + mu, p3.z);
	glRotatef(glm::degrees(teta2), 0, 0, 1);
	glTranslatef(-p3.x, -p3.y, p3.z);
	RegHingeLeftDown.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-p1.x, p1.y, p1.z);
	glRotatef(glm::degrees(teta), 0, 0, 1);
	glTranslatef(p1.x, -p1.y, -p1.z);
	RegHingeRightUp.Draw();
	RegSphereRight.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-p3.x, p3.y + mu, p3.z);
	glRotatef(glm::degrees(teta2), 0, 0, -1);
	glTranslatef(p3.x, -p3.y, p3.z);
	RegHingeRightDown.Draw();
	glPopMatrix();

	MyTexture::UnBind();
	glPopMatrix();
	SwapBuffers(m_hDC);
	
}
