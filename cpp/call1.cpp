#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    int msgboxID = MessageBoxA(
		NULL,
		"Nguyen li he dieu hanh",
		"hello, world",
		0
	);
	return msgboxID;
}
