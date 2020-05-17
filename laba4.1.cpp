#include "RBclass.h"
#include <iostream>
#include <iomanip>

using namespace std;
int main() {
	red_black<int> test;
	test.insert(test.Head, 15, 7);
	test.insert(test.Head, 14, 6);
	test.insert(test.Head, 16, 5);
	test.insert(test.Head, 12, 4);
	test.insert(test.Head, 19, 3);
	test.insert(test.Head, 2, 2);
	test.insert(test.Head, 44, 1);
	test.print(&test.Head, 0);
	cout << endl;
	test.printcolors(&test.Head, 0);
}