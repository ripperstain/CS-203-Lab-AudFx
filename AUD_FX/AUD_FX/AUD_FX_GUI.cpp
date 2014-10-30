#include "AUD_FX_GUI.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	AUD_FX::AUD_FX_GUI form;
	Application::Run(%form);

}