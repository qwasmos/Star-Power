#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Song.cpp"

using namespace std;
int main(){
	fstream file;
	file.open("../input/data.csv", ios::in);
	vector<string> row;
	string line, cell, temp;
	getline(file, temp); // get rid of first line (column names)
	while (getline(file, line)) {
		row.clear();
		stringstream s(line);

		// separate out the row and get rid of commas
		for (int i = 0; i < 19; i++){
			getline(s, cell, ',');
			if (i == 3){ // format artists
				cell.erase(0, 2); // gets rid of the leading quote and bracket in the artists column
				if (cell[0] == '\'') {	// if there are multiple artists (they are separated by commas which throws off the getline function)
					while(getline(s, temp, ',')) {
						cell += "," + temp.substr(1, temp.size() - 1); // add each artist to the cell (substr gets rid of the space after the commas, and we add a comma to separate the artists later)
						if (temp[temp.size() - 1] == '"') {
							cell.erase(cell.size() - 2, 2); // get rid of the trailing quote and bracket
							cell.erase(remove(cell.begin(), cell.end(), '\''), cell.end()); // get rid of the single quotes around the artists
							break;
						}
					}
				} else {
					cell.erase(cell.size() - 2, 2);
				} 
			} else if (i == 14) { // format the song name in case it contains commas
				while (true) {
					getline(s, temp, ',');
					if (temp[0] < '0' || temp[0] > '9') { // if the next cell is a number, then the song name doesn't contain a comma
						cell += "," + temp;
					} else {
						row.push_back(cell);	// when end of song name is reached, add to row and increment i
						cout << cell << endl;
						cell = temp;
						i++;
						break;
					};
				}
			}
			row.push_back(cell);
			cout << cell << endl;
		}
		
	// create a song object with the data from the row
    float valence = stof(row[0]);
    int year = stoi(row[1]);
    float acousticness = stof(row[2]);
    vector<string> artists;
	stringstream a(row[3]);
	for (string artist; getline(a, artist, ',');) {
		artists.push_back(artist);
	}
    float danceability = stof(row[4]);
    int duration_ms = stoi(row[5]);
    float energy = stof(row[6]);
    bool explicit_ = stoi(row[7]) == 1;
    string id = row[8];
    float instrumentalness = stof(row[9]);
    int key = stoi(row[10]);
    float liveness = stof(row[11]);
    float loudness 	= stof(row[12]);
    int mode = stoi(row[13]);
    string name = row[14];
    int popularity = stoi(row[15]);
    string release_date = row[16];
    float speechiness = stof(row[17]);
    float tempo = stof(row[18]);
	Song song(valence, year, acousticness, artists, danceability, duration_ms, energy, explicit_, id, instrumentalness, key, liveness, loudness, mode, name, popularity, release_date, speechiness, tempo);
	}
}
