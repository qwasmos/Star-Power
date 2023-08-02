#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Song.cpp"
#include "processData.cpp"

using namespace std;
int main(){
	Graph graph;
	fstream file;
	file.open("../input/refinedData.csv", ios::in);
	vector<string> row;
	string line, cell, temp;
	getline(file, temp); // get rid of first line (column names)
	int x = 10;	// number of songs to add to graph (only testing with 100 songs right now)
	while (x-- > 0) {
		getline(file,line);
		row.clear();
		Song* song = createSong(row, line);
		graph.addSong(*song);
	}
}