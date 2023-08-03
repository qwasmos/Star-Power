
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
    }




    /*
    void BFS(std::unordered_map<Song*, std::vector<Song*>> &adjList)
    {

        string source = "A";
        std::set<string> visited;
        std::queue<string> q;
        visited.insert(source);
        q.push(source);
        cout << "BFS: ";
        while (!q.empty())
        {
            string u = q.front();
            cout << u;
            q.pop();
            vector<string> neighbors = graph[u];
            for (string v : neighbors)
            {
                if (visited.count(v) == 0)
                {
                    visited.insert(v);
                    q.push(v);
                }
            }
        }
    }
    void DFS(std::unordered_map<Song*, std::vector<Song*>> &adjList)
    {

        string source = "A";
        std::set<string> visited;
        std::stack<string> q;
        visited.insert(source);
        q.push(source);
        cout << "BFS: ";
        while (!q.empty())
        {
            string u = q.front();
            cout << u;
            q.pop();
            vector<string> neighbors = graph[u];
            for (string v : neighbors)
            {
                if (visited.count(v) == 0)
                {
                    visited.insert(v);
                    q.push(v);
                }
            }
        }
    }

    */



