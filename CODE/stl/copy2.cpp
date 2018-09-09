#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    list<int>   coll1;
    vector<int> coll2;

    // insert elements from 1 to 9
    for (int i=1; i<=9; ++i) {
        coll1.push_back(i);
    }
     // resize destination to have enough room for the overwriting algorithm
    coll2.resize(coll1.size());

    /* copy elements from first into second collection
     * - overwrites existing elements in destination
     */
     copy(coll1.begin(), coll1.end(),   //source
          coll2.begin());               //destination

    /* create third collection with enough room
     * - initial size is passed as parameter
     */
     deque<int> coll3(coll1.size());

    // copy elements from first into third collection
    copy(coll1.begin(), coll1.end(),    //source
         coll3.begin());                // destination

}
