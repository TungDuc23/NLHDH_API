#include <Windows.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
    // Path to the executable file of the application you want to open
    wstring applicationPath = L"C:\\Path\\To\\Your\\Application.exe";  // Use a wide-character string

    // Create a STARTUPINFO object
    STARTUPINFO si;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    // Create a PROCESS_INFORMATION object
    PROCESS_INFORMATION pi;

    // Open the application
    if (!CreateProcess("C:\\Windows\\System32\\calc.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
    return 1;
	}
    else {
        wcout << L"Open successfully!" << endl;  // Use wcout for wide-character output
    }

    // Wait until the child application exits
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close the handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}


