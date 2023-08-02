#include <unordered_map>
#include <vector>
#include "Song.cpp"

class Graph {
    unordered_map<Song, vector<Song>> adjList; // this is broken, need to create our own hash map and hash function for Songs
    public:
    void addEdge(Song song1, Song song2){       // gets called when the similarity threshold is met
        if (adjList.find(song1) == adjList.end()) adjList[song1] = vector<Song>();
        if (adjList.find(song2) == adjList.end()) adjList[song2] = vector<Song>();
        adjList[song1].push_back(song2);
        adjList[song2].push_back(song1);
    }
    void addSong(Song& song){                    // gets called when a song is added to the graph
        if (adjList.find(song) == adjList.end()) adjList[song] = vector<Song>();
        else return;                             // if the song is already in the graph, do nothing
        for (auto& [key, value] : adjList) {
            if (song.isSimilar(key)) addEdge(song, key);
        }
    }

    void BFS(std::unordered_map<int,std::vector<Song>>& adjList){

    }
    void DFS(std::unordered_map<int,std::vector<Song>>& adjList){
        
    }
};