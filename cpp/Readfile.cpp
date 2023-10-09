#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    // Read file
    HANDLE hFile = CreateFileW(
        L"example.txt",
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        cout << "File not found" << endl;
        return 1;
    }

    char buffer[1024];
    DWORD bytesRead;
    while (ReadFile(hFile, buffer, sizeof(buffer), &bytesRead, NULL) && bytesRead > 0) {
        cout.write(buffer, bytesRead);
    }

    CloseHandle(hFile);
	return 0;
}





