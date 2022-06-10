#include "MyForm.h"
#include "GameManager.h"
#include <time.h> 

extern GameManager gameManager;


using namespace System;

using namespace System::Windows::Forms;




[STAThreadAttribute]
void main(int argc, char* argv[])

{
	srand(time(NULL));




	//gameManager = new GameManager();

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Detective::MyForm form;

	Application::Run(% form);

	//delete gameManager;

};




