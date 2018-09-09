#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    list<int>   coll1;

    // insert elements from 1 to 9
    for (int i=1; i<=9; ++i) {
        coll1.push_back(i);
    }
 // copy the elements of coll1 into coll2 by appending them
    vector<int> coll2;
    copy(coll1.begin(), coll1.end(),    // source
         back_inserter(coll2));         // destination

    // copy the elements of coll1 into coll3 by inserting them at the front
    // - reverses the order of the elements
    deque<int> coll3;
    copy (coll1.begin(), coll1.end(),   // source
          front_inserter(coll3));       // destination

    // copy elements of coll1 into coll4
    // - only inserter that works for associative collections
    set<int> coll4;
    copy (coll1.begin(), coll1.end(),       // source
          inserter(coll4, coll4.begin()));  // destination
}
