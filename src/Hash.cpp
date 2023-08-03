#pragma once
#include "Song.cpp"
#include <string>
#include <functional>
using namespace std;

class Hash {
public: size_t operator() (const Song& song) const {
    return hash<string>()(song.name);
    }
};