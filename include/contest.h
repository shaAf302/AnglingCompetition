#ifndef CONTEST_H
#define CONTEST_H

#include <fstream>
#include <sstream>
#include <string>

struct Contest {
    std::string angler_name;
    std::string contest_id;
    int counter;
};

enum Status { abnorm, norm };

class ContestEnor{
    public:
        enum Errors { FILEERROR };
        ContestEnor(const std::string &str);
        void first() {next();}
        void next();
        Contest current() const { return _cur;}
        bool end() const { return _end;}
    private:
        std::ifstream _f;
        Status _sx;
        Contest _cur;
        bool _end;
};

#endif // CONTEST_H

