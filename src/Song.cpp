#pragma once
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#pragma once
using namespace std;

class Song {
    float valence;
    int year;
    float acousticness;
    vector<string> artists;
    float danceability;
    int duration_ms;
    float energy;
    bool explicit_;
    string id;
    float instrumentalness;
    float liveness;
    float loudness;
    int popularity;
    float tempo;
    public:
    string name;
    Song(float _valence, int _year, float _acousticness, vector<string> _artists, float _danceability, int _duration_ms, float _energy, bool _explicit_, string _id, float _instrumentalness,
     float _liveness, float _loudness, string _name, int _popularity, float _tempo){
        valence = _valence;
        year = _year;
        acousticness = _acousticness;
        artists = _artists;
        danceability = _danceability;
        duration_ms = _duration_ms;
        energy = _energy;
        explicit_ = _explicit_;
        id = _id;
        instrumentalness = _instrumentalness;
        liveness = _liveness;
        loudness = _loudness;
        name = _name;
        popularity = _popularity;
        tempo = _tempo;
    }
    string getName(){
        return name;
    }
    bool isSimilar(const Song& other){
        // work in progress
        // decide on which attributes are important, how to come up with a similarity score, and what the threshold for similarity is
        int similarity = 0;
        
        // went with the exponential function 25^(-|x-y|) for each attribute. This gives a value between 0 and 1, with 1 being the most similar. All attributes are weighted equally for now.
        similarity += pow(25, - abs(valence - other.valence));
        similarity += pow(25, ((max(year, other.year) - min(year, other.year)) / 55));
        similarity += pow(25, abs(danceability - other.danceability)) + pow(25, abs(energy - other.energy)) + pow(25, abs(instrumentalness - other.instrumentalness))
         + pow(25, abs(liveness - other.liveness)) + pow(25, abs(loudness - other.loudness)) + pow(25, abs(tempo - other.tempo)) + pow(25, abs(acousticness - other.acousticness));
        similarity /= 9;    // 9 attributes taken into account, so divide by 9 to get average
        cout << similarity << endl; // for testing purposes
        return similarity > .5;
    }

};