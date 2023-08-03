#include "Hash.h"
#include "Song.h"
#include <string>
#include <functional>
using namespace std;

 size_t Hash:: operator() (const Song& song) const{
    return hash<string>()(song.getName());
    }
