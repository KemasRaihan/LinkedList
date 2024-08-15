#include "LinkedList.h"

#include <iostream>

int main()
{
#ifdef _DEBUG
	//  _CrtSetBreakAlloc(154);
	_onexit(_CrtDumpMemoryLeaks);
#endif

	LinkedList<int> list;
	list.addItem(1);
	list.addItem(2);
	list.addItem(3);
	list.display();
	list.deleteItem(3);
	std::cout << "\n";
	list.display();

	return 0;
}