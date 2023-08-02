
#include "Song.cpp"
#include <string>
#include <functional>
using namespace std;
template <>
struct hash<Song> {
public: size_t operator() (const Song& song) const {
    return hash<string>()(song.name);
    }
};