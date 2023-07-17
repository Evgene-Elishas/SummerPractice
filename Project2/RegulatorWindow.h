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

	float StableAngVel, DeltaAngVel; // устойчивая угловая скорость и отклонение
	float Fi = DeltaAngVel / StableAngVel;//относительное изменение угловой частоты вращения

	float StableMu, DeltaMu; // устойчивое отклонение муфты(штока) и отклонение
	float Mu = 0;//    DeltaMu / StableMu   //относительное перемещение выходного штока регулятора

	//float MuPrime, MuDoublePrime;


	float Fi0, Mu0, MuPrime0;

	float Tr_sqr; // характеризует инерционные свойства регулятора   (приведенный момент инерции)
	float Tk; // характеризует демпфирующие свойства регулятора      (приведенный коэффициент трения)
	float gamma; // характеризует неравномерность регулятора         (приведенная масса шаров)

	float AngVel;

	float teta, teta2;

	float time, angle;
	float yaw = 0.0f, pitch = 0.0f, distance = 1.0f;
	//float fi0 = 0.342214, mu0 = 0, mu0der = 0, gamma = 3.5;
	RegulatorWindow(System::Windows::Forms::Form^ parentForm, int iWidth, int iHeight, int iPosX, int iPosY);
	System::Void RegulatorWindow::BaseAlgorithm(System::Void);
	System::Void Render(System::Void);
	~RegulatorWindow(System::Void);
	GLint MySetPixelFormat(HDC hdc);
	bool InitGL(GLvoid);
	GLvoid ReSizeGLScene(GLsizei width, GLsizei height);
};
