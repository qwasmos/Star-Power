#include "Graph.h"

    
    void Graph:: addEdge(Song* song1, Song* song2)
    { // gets called when the similarity threshold is met
        if (adjList.find(song1) == adjList.end())
            adjList[song1] = std::vector<Song*>();
        if (adjList.find(song2) == adjList.end())
            adjList[song2] = std::vector<Song*>();
        adjList[song1].push_back(song2);
        adjList[song2].push_back(song1);
    }
    void Graph:: addSong(Song* song){                    // gets called when a song is added to the graph
        if (adjList.find(song) == adjList.end()) adjList[song] = std::vector<Song*>();
        else return;                             // if the song is already in the graph, do nothing
        for (auto& [key, value] : adjList) {
            if (song->isSimilar(key)) {
                addEdge(song, key);
            }
        }
    }

    void Graph::printMap(){
        for(auto iter = adjList.begin();iter!=adjList.end();iter++){
            std::cout<<iter->first->getName()<<std::endl;
        }
        std::cout<<adjList.size()<<std::endl;
    }
    
    Song* Graph::BFS(std::unordered_map<Song*, std::vector<Song*>> &adjList, std::string songName) // if this returns a pointer to a song
    {

        std::set<Song*> visited;
        std::queue<Song*> q;
        auto iter = adjList.begin();
        visited.insert(iter->first);
        q.push(iter->first);
        std::cout << "BFS: ";
        while (!q.empty())
        {
            Song* s = q.front();
            // std::cout << s->getName(); // probably dont need to print this
            q.pop();
            std::vector<Song*> neighbors = adjList[iter->first];
            for (auto v : neighbors)
            {
                if (visited.count(v) == 0)
                {
                    if (v->getName() == songName) { // if name matches
                        return v;
                    }
                    visited.insert(v);
                    q.push(v);
                }
            }
        }

        return nullptr; // if not found

    }


    void Graph::DFS(std::unordered_map<Song*, std::vector<Song*>> &adjList, std::string songName)
    {

        std::string source = "A";
        std::set<Song*> visited;
        std::stack<Song*> q;
        auto iter = adjList.begin();
        visited.insert(iter->first);
        q.push(iter->first);
        std::cout << "BFS: ";
        while (!q.empty())
        {
            Song* u = q.top();
            std::cout << u->getName();
            q.pop();
            std::vector<Song*> neighbors = adjList[u];
            for (auto v : neighbors)
            {
                if (visited.count(v) == 0)
                {
                    visited.insert(v);
                    q.push(v);
                }
            }
        }
    }

    



