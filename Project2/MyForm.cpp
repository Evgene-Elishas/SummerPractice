#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;

#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "User32.lib")
#pragma comment (lib,"opengl32.lib")
//[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project2::MyForm form;
	Application::Run(% form);
	//Application::Exit();
	return 0;
}