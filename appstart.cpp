#include "UI.h"
//#include "Controller.h"
#include "PriorityQueue.cpp"
#include <crtdbg.h>
#include "Tests.h"
#include <unordered_map>

/*
The function which starts the application,initiating the objects and runing the UI
*/
int main()
{
	testAll();

	{
		PriorityQueue queue{};
		Controller controller{ queue };
		UI ui{ controller };
		ui.run();
	}
	_CrtDumpMemoryLeaks();			//we check for memory leaks 
}