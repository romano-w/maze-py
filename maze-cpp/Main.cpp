#include <iostream>
#include <vector>
using namespace std;

class Cave {
private:
	int rows = 0;
	int cols = 0;
	vector <char> mazeList;

public: 
	Cave() {
		cout << "Default constructor called" << endl;
		// Add functionality here
	}

	void drawMaze() {
		return;
	}
};

int main() {
	Cave myCave;
	return 0;
};