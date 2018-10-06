#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>
#include <vector>
#include <deque>
using namespace std;

void print(int elem)
{
    cout << elem << ' ';
}

int main()
{
//dvance1.cpp
//    list<int> coll;
//    for (int i=1; i<=9; ++i){
//        coll.push_back(i);
//    }
//
//    list<int>::iterator pos = coll.begin();
//    cout << *pos << endl;
//    advance(pos,3);
//    cout << *pos << endl;
//    advance (pos, -1);
//    cout << *pos << endl;

//advance2.cpp
//    istream_iterator<string> cinPos(cin);
//    ostream_iterator<string> coutPos(cout, " ");
//
//    while (cinPos != istream_iterator<string>()) {
//        advance(cinPos, 2);
//        if (cinPos != istream_iterator<string>()){
//            *coutPos++ = *cinPos;
//        }
//    }
//    cout <<endl;

//distance.cpp
//    list<int> coll;
//    for(int i=-3; i<=9; ++i){
//        coll.push_back(i);
//    }
//
//    list<int>::iterator pos;
//    pos=find(coll.begin(), coll.end(),
//             5);
//
//    if (pos != coll.end()){
//        cout << "difference between beginning and 5: "
//             << distance(coll.begin(),pos) << endl;
//    }
//    else {
//        cout << "5 not found" << endl;
//    }

//istriter.cpp
//    istream_iterator<int> intReader(cin);
//    istream_iterator<int> intReaderEOF;
//    while (intReader != intReaderEOF) {
//        cout << "once:       " << *intReader << endl;
//        cout << "once again: " << *intReader << endl;
//        ++intReader;
//    }

//itercat.cpp
//    vector<int> coll;
//    for (int i=-3; i<=9; ++i){
//        coll.push_back(i);
//    }
//
//    cout << "number/distance: " << coll.end() - coll.begin() << endl;
//
//    vector<int>::iterator pos;
//    for (pos=coll.begin(); pos<coll.end(); ++pos){
//        cout << *pos << ' ';
//    }
//    cout << endl;
//
//    for (int i=0; i<coll.size(); ++i){
//        cout << coll.begin()[i]<<' ';
//    }
//    cout << endl;
//
//    for (pos = coll.begin(); pos<coll.end()-1; pos+=2){
//        cout << *pos << ' ';
//    }
//    cout << endl;

//ostriter.cpp
//
//    ostream_iterator<int> intWriter(cout, "\n");
//    *intWriter=42;
//    intWriter++;
//    *intWriter=77;
//    intWriter++;
//    *intWriter=-5;
//
//    vector<int> coll;
//    for(int i=1; i<=9; ++i){
//        coll.push_back(i);
//    }
//    copy(coll.begin(), coll.end(),
//         ostream_iterator<int>(cout));
//    cout << endl;
//
//    copy(coll.begin(), coll.end(),
//        ostream_iterator<int>(cout, "<"));
//    cout << endl;

//reviter1.cpp
//    list<int> coll;
//    for(int i=1; i<=9; ++i){
//        coll.push_back(i);
//    }
//
//    for_each(coll.begin(), coll.end(),
//             print);
//    cout << endl;
//
//    for_each(coll.rbegin(), coll.rend(),
//             print);
//    cout << endl;

//reviter2.cpp
//    vector<int> coll;
//    for(int i=1; i<=9; ++i){
//        coll.push_back(i);
//    }
//    vector<int>::iterator pos;
//    pos=find(coll.begin(), coll.end(),
//             5);
//
//    cout << "pos:  " << *pos << endl;
//
//    vector<int>::reverse_iterator rpos(pos);
//
//    cout << "rpos:  " << *rpos << endl;

//reviter3.cpp
//    deque<int> coll;
//    for (int i=1; i<=9; ++i){
//        coll.push_back(i);
//    }
//    deque<int>::iterator pos1;
//    pos1=find(coll.begin(), coll.end(),
//              2);
//
//    deque<int>::iterator pos2;
//    pos2=find(coll.begin(), coll.end(),
//              7);
//    for_each(pos1, pos2,
//             print);
//    cout << endl;
//
//    deque<int>::reverse_iterator rpos1(pos1);
//    deque<int>::reverse_iterator rpos2(pos2);
//
//    for_each(rpos2, rpos1,
//              print);
//    cout << endl;

//reviter4.cpp
    list<int> coll;
    for(int i=1; i<=9; ++i){
        coll.push_back(i);
    }
    list<int>::iterator pos;
    pos=find(coll.begin(), coll.end(),
             5);
    cout << "pos:  " << *pos << endl;

    list<int>::reverse_iterator rpos(pos);
    cout << "*rpos:  " << *rpos << endl;

    list<int>::iterator rrpos;
    rrpos=rpos.base();

    cout << "rrpos:  " << *rrpos << endl;

}
