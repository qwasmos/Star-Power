#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Song.h"
#include "processData.h"
#include "Graph.h"
#include "Hash.h"

using namespace std;
int main(){
	Graph graph;
	fstream file;
	file.open("input/refinedData.csv", ios::in);
	vector<string> row;
	string line, cell, temp;
	getline(file, temp); // get rid of first line (column names)
	for(int i =0; i < 10000;i++){
		getline(file,line);
		row.clear();
		Song* song = createSong(row,line);
		graph.addSong(song);
	}
	graph.printMap();
	cout << "~~~~~~~~~~~~~~~~ Welcome to Synth Sync ~~~~~~~~~~~~~~~~" << endl;
    cout << endl;

    cout << "Have you run out of fun music to listen to? Look no further!" << endl;
    cout << "With our expert knowledge and taste we can recommend the best" << endl;
    cout << "songs for you base on whatever you're looking for!" << endl;
    cout << endl;

	int option = 0;
	while(option != -1) {
    
		cout << "~~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~~" << endl;
		cout << "1. Find songs similar to a song you like" << endl;
		cout << "2. Songs based on artist" << endl; // maybe output adjacent songs to that specific artist's songs
		cout << "3. Songs by mood" << endl; 
		cout << "---------- Enter -1 to Exit ----------" << endl << endl;

		cout << "Please enter the corresponding menu option (number) based on what you are looking for: " << endl;
		cin >> option;
		if (option == 1) {
			
			string songName;
			cout << "Please enter the name of a song you like: " << endl;
			std::getline(std::cin, songName);
			std::getline(std::cin, songName);
			Song* song = graph.BFS(graph.adjList, songName); 
			if (song == nullptr) {
				cout << "Sorry, we couldn't find that song." << endl;
			} else {
				cout << "Here are some songs you might like: " << endl;
				vector<Song*> similarSongs;
				for(int i = 0; i < 5; i++) { // only adds 5 similar songs (also might need to check if the song even has 5 similar songs)
					similarSongs.push_back(graph.adjList[song][i]);
				}
				for (Song* song : similarSongs) {
					cout << "- " << song->getName() << ", By: ";
					for(int i = 0; i < song->getArtist().size(); i++) {
						cout << song->getArtist()[i] << " ";
					}
					cout << endl;
				}
				cout << endl; // spacing
			}
			
		} else if (option == 2) {

			
				
			string artistName;
			cout << "Please enter the name of an artist you like: " << endl;
			std::getline(std::cin, artistName);
			std::getline(std::cin, artistName);
			Song* song = graph.BFSArtist(graph.adjList, artistName); 
			if (song == nullptr) {
				cout << "Sorry, we couldn't find that artist." << endl;
			} else {
				cout << "Here are some songs you might like: " << endl;
				vector<Song*> similarSongs;
				for(int i = 0; i < 5; i++) { // only adds 5 similar songs (also might need to check if the song even has 5 similar songs)
					similarSongs.push_back(graph.adjList[song][i]);
				}
				for (Song* song : similarSongs) {
					cout << "- " << song->getName() << " By: ";
					for(int i = 0; i < song->getArtist().size(); i++) {
						cout << song->getArtist()[i] << " ";
					}
					cout << endl;
				}
				cout << endl; // spacing
			}


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
			bool mood;	// true = happy, false = sad
			string userMood;
			cout << "Enter 3 if you are looking for happy songs, and 0 if you are looking for sad songs: " << endl;
			std::getline(std::cin, userMood);
			std::getline(std::cin, userMood);
			mood = bool(stoi(userMood));
			vector<Song*> songs = graph.BFSMood(graph.adjList, mood);
			
			cout << "Here are some songs with that mood: " << endl;
			for (Song* song : songs) {
				cout << "- " << song->getName() << ", By: ";
				for(int i = 0; i < song->getArtist().size(); i++) {
					cout << song->getArtist()[i] << " ";
				}
				cout << endl;
			}
			cout << endl; // spacing
			
		} else if (option < -1 || option > 3){
			cout << "Sorry, that is not a valid option." << endl;
		}
	}

    return 0;
}