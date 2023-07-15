#pragma once
#include <windows.h>
//#include <Windowsx.h>
#include <GL/gl.h>
#include <GL/glu.h>


ref class RegulatorWindow : public System::Windows::Forms::NativeWindow
{
private:
	HDC m_hDC;
	HGLRC m_hglrc;
public:
	float yaw = 0.0f, pitch = 0.0f, distance = 1.0f, angle = 0.0f, speed = 0.6f;
	RegulatorWindow(System::Windows::Forms::Form^ parentForm, int iWidth, int iHeight, int iPosX, int iPosY);

	System::Void Render(System::Void);
	~RegulatorWindow(System::Void);
	GLint MySetPixelFormat(HDC hdc);
	bool InitGL(GLvoid);
	GLvoid ReSizeGLScene(GLsizei width, GLsizei height);
};
