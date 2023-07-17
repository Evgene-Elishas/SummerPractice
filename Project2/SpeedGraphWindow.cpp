#include "SpeedGraphWindow.h"
//#include <windows.h>
//#include <Windowsx.h>

#define X_SHIFT  (1.0 / MAX_COORD_COUNT)

void CoordList::Push(float x, float y) {
	if (Tail) {
		Head->next = new node(x, y);
		Head = Head->next;
	}
	else Tail = Head = new node(0, y);
}
void CoordList::Pop() {
	node* temp = Tail;
	Tail = Tail->next;
	delete temp;
}
void CoordList::Update(float y, int time) {
	float x = X_SHIFT * time;
	Push(x, y);
	if (time > MAX_COORD_COUNT) Pop();
}
void CoordList::Draw(int time) {
	glPushMatrix();
	if (time > MAX_COORD_COUNT) glTranslatef(-(time - MAX_COORD_COUNT) * X_SHIFT, 0, 0);
	glBegin(GL_LINE_STRIP);
	node* temp = Tail;
	while (temp) {
		glVertex2f(temp->info.x, temp->info.y);
		temp = temp->next;
	}
	glEnd();
	glPopMatrix();
}
void CoordList::Clear() {
	Head = Tail;
	while (Head) {
		Head = Head->next;
		delete Tail;
		Tail = Head;
	}
	//if (Tail) delete Tail;
	//Head = Tail = NULL;
}


using namespace System::Windows::Forms;

bool SpeedGraphWindow::InitGL(GLvoid)// инициализация SpeedGraphWindow
{
	glClearColor(0.3, 0.25, 0.3, 0.0);
	glClearDepth(1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);

	return TRUE;
}
GLvoid SpeedGraphWindow::ReSizeGLScene(GLsizei width, GLsizei height)// Resize and initialise the gl window
{
	glViewport(0, 0, width, height);
}
GLint SpeedGraphWindow::MySetPixelFormat(HDC hdc)
{
	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),// Size Of This Pixel Format Descriptor
		1,// Version Number
		PFD_DRAW_TO_WINDOW |// Format Must Support Window
		PFD_SUPPORT_OPENGL |// Format Must Support SpeedGraphWindow
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
	if ((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0) {
		MessageBox::Show("ChoosePixelFormat Failed"); return 0;
	}
	if (SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE) {
		MessageBox::Show("SetPixelFormat Failed");	return 0;
	}
	if ((m_hglrc = wglCreateContext(m_hDC)) == NULL) {
		MessageBox::Show("wglCreateContext Failed");	return 0;
	}
	if ((wglMakeCurrent(m_hDC, m_hglrc)) == NULL) {
		MessageBox::Show("wglMakeCurrent Failed");	return 0;
	}

	return 1;
}
SpeedGraphWindow::SpeedGraphWindow(System::Windows::Forms::Form^ parentForm, int iWidth, int iHeight, int iPosX, int iPosY)
{
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
SpeedGraphWindow::~SpeedGraphWindow(System::Void) // деструктор
{
	coordlist.Clear();
	this->DestroyHandle();
}

// функция рисования
System::Void SpeedGraphWindow::Render(System::Void)
{
	wglMakeCurrent(m_hDC, m_hglrc);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (!IsStopped) {
		time++;
		float y = speed - shift;
		coordlist.Update(y, time);

	}
	coordlist.Draw(time);
	SwapBuffers(m_hDC);
}
