#include <iostream>
#include "contest.h"
#include "angler.h"

using namespace std;

bool MaximumSearch(const string &file, Contest &b){
    int line = 0;
    ContestEnor t (file);
    t.first();
    b = t.current();
    t.next();
    while(!t.end()){
        line++;
        if(t.current().counter > b.counter){
            b = t.current();
        }
        t.next();
    }
    if(line!=0){
        return true;
    }
    else{
        return false;
    }
}

int count(const string &file){
    AnglerEnor t (file);
    t.first();
    int c = 0;
    while(!t.end()){
        if(t.current().cnt == 0){
            c++;
        }
        t.next();
    }
    return c;
}

/*int count(const std::string &file){
    int c = 0;
    AnglerEnor t(file);
    for(t.first(); !t.end(); t.next()){
        if(t.current().cnt == 0){
            c++;
        }
    }
    return c;
}*/
#define NORMAL_MODE
#ifdef NORMAL_MODE


int main()
{

    string filename;
    cout<<"Enter the name of the input file, please: "; cin>>filename;


    try{
        Contest e;
        if(MaximumSearch(filename, e)){
            if(e.counter != 0){
                cout<<e.angler_name<<" has caught "<<e.counter<<" fish(es) on contest "<<e.contest_id<<endl;
            } else{
                cout << "No one has caught fish" << endl;;
            }
            int c = count(filename);
            if(c != 0){
            cout << c << " contests with 0 fish" << endl;;
            } else{
                cout << "There is no contest with 0 fish" << endl;;
            }
        }else{
           cout<<"The file is empty.\n";
        }
    }catch(ContestEnor::Errors err)
    {
        cerr<<"Can't find input file "<<filename<<"!"<<endl;
    }


    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("EMTPY FILE | TASK ONE", "t0.txt") {
    Contest t;
     MaximumSearch("t0.txt",t);
    CHECK(t.angler_name == "");
    CHECK(t.contest_id == "");
    CHECK(t.counter == 0);
}
TEST_CASE("INCORRECT FILE NAME | TASK ONE", "idk.txt"){
    Contest t;
    CHECK_THROWS(MaximumSearch("idk.txt",t));
}
TEST_CASE("CORRECT CASE | TASK ONE", "new.txt") {
   Contest t;
   MaximumSearch("new.txt",t);
    CHECK(t.angler_name == "Peter");
    CHECK(t.contest_id == "Kiliti0512" );
    CHECK(t.counter == 4);
}
TEST_CASE("ALL ANGLERS HAVE CAUGHT SAME NUMBER OF FISH | TASK ONE", "tt4.txt"){
    Contest t;
    MaximumSearch("t14.txt",t);
    CHECK(t.angler_name == "Peter");
    CHECK(t.contest_id == "Gesztes0906" );
    CHECK(t.counter == 3);
}
TEST_CASE("ALL ANGLERS HAVE CAUGHT ZERO FISH | TASK ONE", "tt3.txt"){
    Contest t;
    MaximumSearch("tt3.txt",t);
    CHECK(t.angler_name == "Peter");
    CHECK(t.contest_id == "Gesztes0906" );
    CHECK(t.counter == 0);
}
//task2_cases
//TEST_CASE("EMTPY FILE | TASK TWO", "t0.txt") {
  //  int t=count("t0.txt");

//    CHECK(t == 0);
//}


TEST_CASE("CORRECT CASE | TASK TWO", "new.txt"){
    int t=count("new.txt");
    CHECK(t==0);
}

TEST_CASE("INCORRECT FILE NAME | TASK TWO", "idk.txt"){
    int t;
    CHECK_THROWS(count("idk.txt"));
}

TEST_CASE("ONE ALL CONTESTS, ONE OR MORE FISH WERE CAUGHT | TASK TWO", "tt5.txt"){
    int t = count("new.txt");
    CHECK(t==0);
}


TEST_CASE("ALL THE CONTESTS HAVE NO FISH CAUGHT | TASK TWO", "tt3.txt"){
    int t = count("tt3.txt");
    CHECK(t==3);
}


#endif // NORMAL_MODE
