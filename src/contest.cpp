#include "contest.h"

using namespace std;

ContestEnor::ContestEnor(const string &str){
    _f.open(str);
    if(_f.fail()) throw FILEERROR;
}

void ContestEnor::next(){
    if ( _f.fail() ) _sx = abnorm;
    else _sx = norm;
    _end = _sx == abnorm;
    string line;
    getline(_f , line);
    if(!_end){
        istringstream is(line);
        is >> _cur.angler_name >> _cur.contest_id;
        _cur.counter = 0;
        string fish;
        int size;
        for( is >> fish >> size ; !is.fail(); is >> fish >> size ){
             ++_cur.counter;
        }
    }

}
