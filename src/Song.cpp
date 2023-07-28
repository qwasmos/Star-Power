#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Song {
    public:
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
    int key;
    float liveness;
    float loudness;
    int mode;
    string name;
    int popularity;
    string release_date;
    float speechiness;
    float tempo;
    Song(float _valence, int _year, float _acousticness, vector<string> _artists, float _danceability, int _duration_ms, float _energy, bool _explicit_, string _id, float _instrumentalness,
     int _key, float _liveness, float _loudness, int _mode, string _name, int _popularity, string _release_date, float _speechiness, float _tempo){
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
        key = _key;
        liveness = _liveness;
        loudness = _loudness;
        mode = _mode;
        name = _name;
        popularity = _popularity;
        release_date = _release_date;
        speechiness = _speechiness;
        tempo = _tempo;
    }
    bool areSimilar(Song other){
        // work in progress
        // decide on which attributes are important, how to come up with a similarity score, and what the threshold for similarity is
        int similarity = 0;
        int diff = abs(valence - other.valence);
        (diff < .15) ? similarity += pow(1 - diff, 2) : similarity += 0; // if they are within .15 of each other, add 1 - diff to similarity
        diff = abs(acousticness - other.acousticness);
        (diff < .15) ? similarity += pow(1 - diff, 2) : similarity += 0;
        return similarity > 1.5;
    }
};