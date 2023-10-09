#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Read file
	ifstream file("example.txt");
	string line;
	while (getline(file, line)) {
	    cout << line << endl;
	}
	
	// Write to file
	ofstream outFile("output.txt");
	outFile << "Call api example" << endl;
	outFile.close();
}


