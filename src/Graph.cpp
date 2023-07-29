#include <unordered_map>
#include <vector>
#include "Song.cpp"

class Graph {
    unordered_map<Song, vector<Song>> adjList;
    public:
    void addEdge(Song song1, Song song2){       // gets called when the similarity threshold is met
        if (adjList.find(song1) == adjList.end()) adjList[song1] = vector<Song>();
        if (adjList.find(song2) == adjList.end()) adjList[song2] = vector<Song>();
        adjList[song1].push_back(song2);
        adjList[song2].push_back(song1);
    }
};