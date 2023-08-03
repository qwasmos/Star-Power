#pragma once
#include "Song.h"

class Hash{
    public:
    size_t operator() (const Song& song) const;
};