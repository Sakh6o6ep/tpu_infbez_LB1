#include "MyForm.h"
#include "PasswordGenerator.h"

#include <Windows.h>


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(cli::array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	LB1_form::MyForm form;
	Application::Run(%form);
}
