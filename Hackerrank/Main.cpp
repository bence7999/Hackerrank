#include <iostream>
#include <cstdio>

#include <stdio.h>
#include <string>
#include <sstream>
#include "Introduction.h"
#include "Strings.h"
#include "Classes.h"

void Exit() {
	bool exit = true;
	std::string str;
	while (exit)
	{
		std::cout << "\nDo you want exit: (y/n)";
		getline(std::cin, str);
		const char *cstr = str.c_str();
		if (*cstr == 'y')
			exit = false;
	}
}

int main() {
	AbstractClasses_Polymorphism();

	Exit();
	return 0;
}
