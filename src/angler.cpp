#include "angler.h"

using namespace std;

void AnglerEnor::next()
{
    if( !(_end = _tt.end()) ){
        _cur.name = _tt.current().angler_name;
        _cur.id = _tt.current().contest_id;
        _cur.cnt = 0;
        for( ; !_tt.end() && _tt.current().contest_id == _cur.id; _tt.next() ){
            _cur.cnt = _cur.cnt + _tt.current().counter;;
        }
    }
}
