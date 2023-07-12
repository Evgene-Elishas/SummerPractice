#include "OpenGL.h"

#include <windows.h>
#include <Windowsx.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "OpenGL.h"


#include "Item.h"
#include "Camera.h"
//#include "glaux.h"

#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "User32.lib")


#pragma comment (lib,"opengl32.lib")

using namespace System::Windows::Forms;
int Width, Height;
Camera camera(glm::vec3(0.0f, 0.0f, 3.5f)); 
MyTexture Sun, CellThor, Space;
Mesh Wheel, Pipe1, Pipe2, Pipe3, PipeBend, Damper, Reductor, Shaft, Engine;
Mesh RegStand, RegShaft, RegLever, RegLeverHolder, RegClutch, RegHinge, RegHingeDown, RegSphere;




// инициализация OpenGL
bool OpenGL::InitGL(GLvoid)
{
	Sun.Load("WheelWagon.jpg");
	Space.Load("Space.png");
	CellThor.Load("Cells.jpg");

	Wheel.Load(".objects\\Wheel.obj", "");
	Pipe1.Load(".objects\\Pipe1.obj", "");
	Pipe2.Load(".objects\\Pipe2.obj", "");
	Pipe3.Load(".objects\\Pipe3.obj", "");
	PipeBend.Load(".objects\\PipeBend.obj", "");
	Damper.Load(".objects\\Damper.obj", "");
	Reductor.Load(".objects\\Reductor.obj", "");
	Shaft.Load(".objects\\Shaft.obj", "");
	Engine.Load(".objects\\Engine.obj", "");

	RegStand.Load(".objects\\Reg.Stand.obj", "");
	RegShaft.Load(".objects\\Reg.Shaft.obj", "");
	RegLever.Load(".objects\\Reg.Lever.obj", "");
	RegLeverHolder.Load(".objects\\Reg.LeverHolder.obj", "");
	RegClutch.Load(".objects\\Reg.Clutch.obj", "");
	RegHinge.Load(".objects\\Reg.Hinge.obj", "");
	RegHingeDown.Load(".objects\\Reg.HingeDown.obj", "");
	RegSphere.Load(".objects\\Reg.Sphere.obj", "");

	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);//Разрешаем использовать цветной материал
	glEnable(GL_LIGHTING);	//разрешаем освещение
	//glEnable(GL_CULL_FACE);
	float ambient[4] = { 0.1,0.1,0.1, 1.0 };//цвет и интенсивность фонового освещения
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);//режим фонового освещения

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	float pos0[4] = { 0,5,0,1 };//положение точечного источника света
	float amb[4] = { 0,0,0,0 };//цвет и интенсивность
	float color0[4] = { 1,1,1,1 };//цвет и интенсивность источника света
	float color_sp[4] = { 1,1,1,1 };//цвет зеркального источника света
	glLightfv(GL_LIGHT0, GL_POSITION, pos0);//положение нулевой лампы
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, color0);//тип освещения GL_DIFFUSE, цвет нулевой лампы color0
	glLightfv(GL_LIGHT0, GL_SPECULAR, color_sp);//для GL_LIGHT0 установлено по умолчанию

	//glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	glClearColor(0.3, 0.25, 0.3, 0.0);
	//glClearColor(0.1f, 0.2f, 0.3f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LEQUAL);
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);





	return TRUE;
}

// функция, вызывающаяся при изменении размеров оьласти вывода 
GLvoid OpenGL::ReSizeGLScene(GLsizei width, GLsizei height)// Resize and initialise the gl window
{
	Width = width; Height = height;
	glViewport(0, 0, width, height);
}




// функция, задающая формат пикселя
GLint OpenGL::MySetPixelFormat(HDC hdc)
{
	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),// Size Of This Pixel Format Descriptor
		1,// Version Number
		PFD_DRAW_TO_WINDOW |// Format Must Support Window
		PFD_SUPPORT_OPENGL |// Format Must Support OpenGL
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
OpenGL::OpenGL(System::Windows::Forms::Form^ parentForm, int iWidth, GLsizei iHeight)
{
	Width = iWidth; Height = iHeight;

	CreateParams^ cp = gcnew CreateParams;
	cp->X = 40;  cp->Y = 32;  cp->Height = iHeight;  cp->Width = iWidth;
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

// деструктор
OpenGL::~OpenGL(System::Void)
{
	this->DestroyHandle();
}



void SetProjectionMatrix(Camera& cam) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(cam.Perspective, (GLfloat)Width/Height, 0.001, 1000.0);
	glm::vec3 dest = cam.Position + cam.Front;
	gluLookAt(cam.Position.x, cam.Position.y, cam.Position.z, dest.x, dest.y, dest.z, cam.Up.x, cam.Up.y, cam.Up.z);
	glMatrixMode(GL_MODELVIEW);
}

// функция рисования
System::Void OpenGL::Render(System::Void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//camera.Yaw = this->yaw;
	//camera.Pitch += this->pitch;
	camera.Position = normalize(camera.Position) * this->distance;
	camera.updateCameraVectors();
	SetProjectionMatrix(camera);
	glPushMatrix();
	glTranslatef(0.4, -0.8, 0);
	
	Sun.Bind();
	//glRotated(GetTickCount() % 36000 / 20.f, 0, 1, 0);
	Wheel.Draw();
	Pipe1.Draw();
	Pipe2.Draw();
	Pipe3.Draw();
	PipeBend.Draw();
	Damper.Draw();
	Reductor.Draw();
	Shaft.Draw();
	Engine.Draw();

	RegStand.Draw();
	RegShaft.Draw();
	RegLever.Draw();
	RegLeverHolder.Draw();
	RegClutch.Draw();
	RegHinge.Draw();
	RegHingeDown.Draw();
	RegSphere.Draw();

	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
	SwapBuffers(m_hDC);
}

