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
	vector <vector <char>> mazeVect;

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
			vector <char> thisLine;
			for (int i = 0; i < line.length(); ++i) {
				thisLine.push_back(line[i]);
			}
			mazeVect.push_back(thisLine);
			currentLine++;
		}
		rows = mazeVect.size();
		cols = mazeVect[0].size();
		cout << "There are " + to_string(rows) + " rows, and " + to_string(cols) + " columns.\n\n";
		return;
	}

	void printMaze() {
		for (int i = 0; i < mazeVect.size(); i++) {
			for (int j = 0; j < mazeVect[i].size(); j++) {
				cout << mazeVect[i][j];
			}
			cout << endl;
		}
		cout << endl;
		return;
	}
};

int main() {
	Cave myCave;
	myCave.readMaze("cave.txt");
	myCave.printMaze();

	cout << "Press Enter to exit...";
	getchar();
	return 0;
};