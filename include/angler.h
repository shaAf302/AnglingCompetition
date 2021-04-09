#ifndef ANGLER_H
#define ANGLER_H


#pragma once

#include "contest.h"
#include <string>


//Datatype of anglers
struct Angler {
    std::string name;
    std::string id;
    int cnt;
};


//Datatype of the enumerator of anglers for the second part
class AnglerEnor{
    private:
        ContestEnor _tt;
        Angler _cur;
        bool _end;
    public:
        AnglerEnor(const std::string &str): _tt(str) { }
        void first() { _tt.first(); next(); }
        void next();
        Angler current() const { return _cur; }
        bool end() const { return _end; }
};



#endif // ANGLER_H
