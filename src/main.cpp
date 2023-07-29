#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Song.cpp"
#include "processData.cpp"

using namespace std;
int main(){
	fstream file;
	file.open("../input/refinedData.csv", ios::in);
	vector<string> row;
	string line, cell, temp;
	getline(file, temp); // get rid of first line (column names)
	while (getline(file,line)) {
		row.clear();
		addSong(row, line);
	}
}