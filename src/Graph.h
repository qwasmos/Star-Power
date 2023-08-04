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
    void printMap();

    Song* BFS(std::unordered_map<Song*, std::vector<Song*>> &adjList, std::string songName);
    void DFS(std::unordered_map<Song*, std::vector<Song*>> &adjList, std::string songName);

};