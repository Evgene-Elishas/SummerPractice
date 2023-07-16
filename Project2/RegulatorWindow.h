#pragma once
#include <windows.h>
//#include <Windowsx.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define M_PI        3.14159265358979323846264338327950288   /* pi */

ref class RegulatorWindow : public System::Windows::Forms::NativeWindow
{
private:
	HDC m_hDC;
	HGLRC m_hglrc;
public:
	bool IsStopped = TRUE;
	float time, angle = 0;
	float yaw = 0.0f, pitch = 0.0f, distance = 1.0f, speed = 0.6f;
	float fi0 = 0.342214, mu0 = 0, mu0der = 0, Tr_sqr = 0.25, Tk = 0.5, gamma = 3.5;
	RegulatorWindow(System::Windows::Forms::Form^ parentForm, int iWidth, int iHeight, int iPosX, int iPosY);

	System::Void Render(System::Void);
	~RegulatorWindow(System::Void);
	GLint MySetPixelFormat(HDC hdc);
	bool InitGL(GLvoid);
	GLvoid ReSizeGLScene(GLsizei width, GLsizei height);
};
