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
	}

	void readMaze(string fileName) {
		string line;
		ifstream readFile (fileName);
		int lineCount = 0;

		if (!readFile.is_open()) {			// Checking for errors opening the file
			perror("error while opening file");
		}
		while (getline(readFile, line)) {			// Reading file until the end is reached or an error occurs
			vector <char> thisLine;
			for (int i = 0; i < line.length(); ++i) {
				thisLine.push_back(line[i]);
			}
			mazeVect.push_back(thisLine);
			lineCount++;
		}

		if (readFile.bad()) {						// More error checking
			perror("error while reading file");
		}

		rows = mazeVect.size();			// Updating class attributes "rows" and "cols"
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