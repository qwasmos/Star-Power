#include <unordered_map>
#include <vector>
#include "Song.cpp"
#include "Hash.cpp"

class Graph {
    unordered_map<string, pair<Song, vector<Song>>> adjList; // this is broken, need to create our own hash map and hash function for Songs
    public:
    void addEdge(Song song1, Song song2){       // gets called when the similarity threshold is met
        string id1 = song1.getID();
        string id2 = song2.getID();
        if (adjList.find(id1) == adjList.end()) adjList[id1] = {song1, vector<Song>()};
        if (adjList.find(id2) == adjList.end()) adjList[id2] = {song2, vector<Song>()};
        adjList[id1].second.push_back(song2);
        adjList[id2].second.push_back(song1);
    }
    void addSong(Song& song){                    // gets called when a song is added to the graph
        string id = song.getID();
        if (adjList.find(id) == adjList.end()) adjList[id] = {song, vector<Song>()};
        else return;                             // if the song is already in the graph, do nothing
        Song* song1 = &adjList[id].first;
        // broken rn
        /*  
        for (auto& [key, value] : adjList) {
            Song* song2 = &value.first;
            if (song.isSimilar(key)) {
                addEdge(song, key);
                cout << "Added edge between " << song.name << " and " << key.name << endl;
            }
        }
        */
    }
};