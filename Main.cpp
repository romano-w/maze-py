#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//https://gehrcke.de/2011/06/reading-files-in-c-using-ifstream-dealing-correctly-with-badbit-failbit-eofbit-and-perror/

class Cave {
private:
	int rows = 0;
	int cols = 0;
	vector <vector <char>> mazeList;

public: 
	Cave() {
		cout << "Default constructor called" << endl;
		// Add functionality here
	}

	void readMaze(string fileName) {
		string line;
		ifstream readFile;
		int currentLine = 0;
		readFile.open(fileName);
		if (!readFile.is_open()) {
			cout << "File not opened!" << endl;
		}
		while (getline(readFile, line)) {
			cout << line << endl;
			for (int i = 0; i < line.length(); ++i) {
				
			}
			currentLine++;
		}
		return;
	}

	void drawMaze() {
		return;
	}
};

int main() {
	char endCin;
	Cave myCave;
	myCave.readMaze("cave.txt");

	cout << "Press any key to exit..." << endl;
	cin >> endCin;
	return 0;
};