#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<char> coll;

    for (char c = 'a'; c <= 'z'; ++c){
        coll.push_back(c);
    }

    for (auto pos = coll.begin(); pos != coll.end(); ++pos){
        cout << *pos << ' ';
    }
    cout << endl;
}
