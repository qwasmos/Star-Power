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
	while (getline(file,line)) {
		row.clear();
		Song* song = createSong(row, line);	// create a song object with the data from the row
		graph.addSong(song); 
	}
	cout << "~~~~~~~~~~~~~~~~ Welcome to Synth Sync ~~~~~~~~~~~~~~~~" << endl;
    cout << endl;

    cout << "Have you run out of fun music to listen to? Look no further!" << endl;
    cout << "With our expert knowledge and taste we can recommend the best" << endl;
    cout << "songs for you base on whatever you're looking for!" << endl;
    cout << endl;

    int option = 0;
    cout << "~~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~~" << endl;
	cout << "1. Find songs similar to a song you like" << endl;
	cout << "2. Songs based on artist" << endl; // maybe output adjacent songs to that specific artist's songs
	cout << "3. Songs by mood" << endl; // apparently songs with a high valence are more cheerful and songs with a low valence are more sad
    // we could also compare the energy and danceability and stuff
    cout << "Please enter the corresponding menu option (number) based on what you are looking for: " << endl;
    cin >> option;
	if (option == 1) {
		/*
		string songName;
		cout << "Please enter the name of a song you like: " << endl;
		getline(cin, songName);
		Song* song = graph.findSong(songName);
		if (song == nullptr) {
			cout << "Sorry, we couldn't find that song." << endl;
		} else {
			cout << "Here are some songs you might like: " << endl;
			vector<Song*> similarSongs = graph.getSimilarSongs(song);
			for (Song* song : similarSongs) {
				cout << song->getName() << endl;
			}
		}
		*/
	} else if (option == 2) {
		/*
		string artistName;
		cout << "Please enter the name of an artist you like: " << endl;
		getline(cin, artistName);
		vector<Song*> songs = graph.getSongsByArtist(artistName);
		if (songs.size() == 0) {
			cout << "Sorry, we couldn't find that artist." << endl;
		} else {
			cout << "Here are some songs by that artist: " << endl;
			for (Song* song : songs) {
				cout << song->getName() << endl;
			}
		}
		*/
	} else if (option == 3) {
		/*
		bool mood;	// true = happy, false = sad
		cout << "Enter 1 if you are looking for happy songs, and 2 if you are looking for sad songs: " << endl;
		getline(cin, mood);
		vector<Song*> songs = graph.getSongsByMood(mood);
		cout << "Here are some songs with that mood: " << endl;
			for (Song* song : songs) {
				cout << song->getName() << endl;
			}
		*/
	} else {
		cout << "Sorry, that is not a valid option." << endl;
	}
    return 0;
}