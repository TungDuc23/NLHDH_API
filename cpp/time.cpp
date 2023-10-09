#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SYSTEMTIME currentTime;
    GetLocalTime(&currentTime);

    cout << "Current Time: ";
    cout << currentTime.wYear << "-" << currentTime.wMonth << "-" << currentTime.wDay << " ";
    cout << currentTime.wHour << ":" << currentTime.wMinute << ":" << currentTime.wSecond << endl;

    return 0;
}


