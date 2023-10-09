#include <iostream>
#include <windows.h>
using namespace std;

// Function to run in Thread 1
DWORD WINAPI ThreadFunc1(LPVOID lpParam) {
    for (int i = 0; i < 5; i++) {
        cout << "Thread 1: " << i << endl;
        Sleep(1000); // Sleep for 1 second
    }
    return 0;
}

// Function to run in Thread 2
DWORD WINAPI ThreadFunc2(LPVOID lpParam) {
    WaitForSingleObject(reinterpret_cast<HANDLE>(lpParam), INFINITE); // Wait until Thread 1 finishes
    for (int i = 0; i < 5; i++) {
        cout << "Thread 2: " << i << endl;
        Sleep(1000); // Sleep for 1 second
    }
    return 0;
}

int main() {
    HANDLE hThread1, hThread2;
    
    // Create Thread 1
    hThread1 = CreateThread(NULL, 0, ThreadFunc1, NULL, 0, NULL);
    
    if (hThread1 == NULL) {
        cerr << "Failed to create Thread 1!" << endl;
        return 1;
    }

    // Wait for Thread 1 to finish
    WaitForSingleObject(hThread1, INFINITE);

    // Create Thread 2 and pass the handle of Thread 1
    hThread2 = CreateThread(NULL, 0, ThreadFunc2, hThread1, 0, NULL);

    if (hThread2 == NULL) {
        cerr << "Failed to create Thread 2!" << endl;
        CloseHandle(hThread1);
        return 1;
    }
    
    // Wait for Thread 2 to finish
    WaitForSingleObject(hThread2, INFINITE);
    
    // Close the handles
    CloseHandle(hThread1);
    CloseHandle(hThread2);
    
    cout << "Both threads have finished." << endl;
    
    return 0;
}



