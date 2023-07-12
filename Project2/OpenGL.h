#pragma once
#include <windows.h>
//#include <Windowsx.h>
#include <GL/gl.h>
#include <GL/glu.h>


ref class OpenGL : public System::Windows::Forms::NativeWindow
{
private:
	HDC m_hDC;
	HGLRC m_hglrc;
public:
	float yaw = 0.0f, pitch = 0.0f, distance = 2.5f;
	OpenGL(System::Windows::Forms::Form^ parentForm, int iWidth, int iHeight);

	System::Void Render(System::Void);
	~OpenGL(System::Void);
	GLint MySetPixelFormat(HDC hdc);
	bool InitGL(GLvoid);
	GLvoid ReSizeGLScene(GLsizei width, GLsizei height);
};
