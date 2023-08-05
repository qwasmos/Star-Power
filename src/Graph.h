#pragma once
#include "Song.h"
#include <unordered_map>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <iostream>
class Graph{
    
    public:
    std::unordered_map<Song*, std::vector<Song*>> adjList;
    void addEdge(Song* song1, Song* song2);

    void addSong(Song* song);
    Song* BFS(std::unordered_map<Song*, std::vector<Song*>> &adjList, std::string name);
    Song* BFSArtist(std::unordered_map<Song*, std::vector<Song*>>& adjList, std::string artist);
    std::vector<Song*> BFSMood(std::unordered_map<Song*, std::vector<Song*>>& adjList, int mood);
    Song* DFS(std::unordered_map<Song*, std::vector<Song*>> &adjList, std::string name);
    void printMap();

    void getSongByArtist(std::unordered_map<Song*, std::vector<Song*>>& adjList, std::string artist); 
    

};