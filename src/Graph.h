#pragma once
#include "Song.h"
#include <unordered_map>
#include <vector>
#include <set>
#include <stack>
#include <queue>
class Graph{
    std::unordered_map<Song*, std::vector<Song*>> adjList;
    public:
    
    void addEdge(Song* song1, Song* song2);

    void addSong(Song* song);

};