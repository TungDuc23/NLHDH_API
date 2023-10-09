#include <iostream>
#include <windows.h>
using namespace std;

int main() {
// Write to file
    HANDLE hOutFile = CreateFileW(
        L"output.txt",
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hOutFile == INVALID_HANDLE_VALUE) {
        cout << "File not found" << endl;
        return 1;
    }
	cout << "Write successfully!" << endl;
    const char* data = "Write to file example\n";
    DWORD bytesWritten;
    WriteFile(hOutFile, data, strlen(data), &bytesWritten, NULL);
    CloseHandle(hOutFile);
    return 0;
    }
    
    
    
