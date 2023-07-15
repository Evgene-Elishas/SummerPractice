#pragma once
#include <windows.h>
//#include <Windowsx.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "glm/glm.hpp"

#define MAX_COORD_COUNT 1000 // time in seconds(10) * fps(100)

struct node {
	glm::vec2 info;
	node* next;
	node(float x, float y) :info(x, y), next(NULL) {}
};

ref class CoordList {
	node* Head = NULL, * Tail = NULL;
public:
	void Push(float x, float y);
	void Pop();
	void Update(float y, int time);
	void Draw(int time);
};


ref class SpeedGraphWindow : public System::Windows::Forms::NativeWindow
{
private:
	HDC m_hDC;
	HGLRC m_hglrc;
public:
	int time = 0;  // seconds * fps(100)
	CoordList coordlist;
	float speed;
	SpeedGraphWindow(System::Windows::Forms::Form^ parentForm, int iWidth, int iHeight, int iPosX, int iPosY);

	System::Void Render(System::Void);
	~SpeedGraphWindow(System::Void);
	GLint MySetPixelFormat(HDC hdc);
	bool InitGL(GLvoid);
	GLvoid ReSizeGLScene(GLsizei width, GLsizei height);
};
