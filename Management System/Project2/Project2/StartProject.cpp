#include "StartProject.h"
#include"AddData.h"
#include"adminVerify.h"
#include"DeleteData.h"
#include"mainMenu.h"
#include"studentVerify.h"
#include"WelcomeAdmin.h"
#include"welcomeStudent.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project2::StartProject form;
	Application::Run(% form);
}
