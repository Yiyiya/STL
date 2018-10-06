#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <bitset>
#include <string>
#include <limits>
#include <deque>
#include <list>
#include <map>
#include <iomanip>
#include <set>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

void printLists(const list<int>& l1, const list<int>& l2)
{
    cout << "list1: ";
    copy(l1.begin(), l1.end(), ostream_iterator<int>(cout," "));
    cout <<endl << "list2: ";
    copy(l2.begin(), l2.end(), ostream_iterator<int>(cout," "));
    cout << endl << endl;
}

int main()
{
    //array1.cpp
    int coll[]={5,6,2,4,1,3};

    transform(coll, coll+6,
              coll,
              coll,
              multiplies<int>());
    sort(coll+1, coll+6);
    copy(coll, coll+6,
         ostream_iterator<int>(cout, " "));
    cout << endl;

    //bitset1.cpp
    enum Color {red, yellow, green, blue, white, black,
                numColors};
    bitset<numColors> usedColors;

    usedColors.set(red);
    usedColors.set(black);

    cout << "bitfield of used colors:  " << usedColors << endl;
    cout << "number of used colors:  " << usedColors.count() << endl;
    cout <<"bitfield of unused colors: " << ~usedColors << endl;

    if (usedColors.any()) {
        for (int c = 0; c < numColors; ++c){
            if (usedColors[(Color)c]){
            }
        }
    }

    //bitset2.cpp
    cout << "267 as binary short:    "
         << bitset<numeric_limits<unsigned short>::digits>(267)
         << endl;
    cout << "267 as binary long:   "
         << bitset<numeric_limits<unsigned long>::digits>(267)
         << endl;
    cout << "10,000,000 with 24 bits: "
         << bitset<24>(1e7) << endl;

    cout << "\"1000101011\" as number: "
         << bitset<100>(string("1000101011")).to_ulong() << endl;

    //deque1.cpp
    deque<string> coll2;

    coll2.assign(3, string("string"));
    coll2.push_back("last string");
    coll2.push_front("first string");

    copy(coll2.begin(), coll2.end(),
         ostream_iterator<string>(cout, "\n"));
    cout << endl;

    coll2.pop_front();
    coll2.pop_back();

    for (unsigned i=1; i<coll2.size(); ++i){
        coll2[i]="another " + coll2[i];
    }

    coll2.resize(4, "resized string");

    copy(coll2.begin(), coll2.end(),
         ostream_iterator<string>(cout, "\n"));

    //list1.cpp
    list<int> list1, list2;
    for (int i=0; i<6; ++i){
        list1.push_back(i);
        list2.push_back(i);
    }
    printLists(list1, list2);

    list2.splice(find(list2.begin(), list2.end(),
                      3),
                 list1);
     printLists(list1, list2);

     list2.splice(list2.end(),
                  list2,
                  list2.begin());
    printLists(list1, list2);

    list2.sort();
    list1 = list2;
    list2.unique();
    printLists(list1, list2);

    list1.merge(list2);
    printLists(list1,list2);

    //map1.cpp
    typedef map<string, float> StringFloatMap;
    StringFloatMap stocks;

    stocks["BASF"]=369.50;
    stocks["VW"]=413.50;
    stocks["Daimler"]=819.00;
    stocks["BMW"]=834.00;
    stocks["Siemens"]=842.20;

    StringFloatMap::iterator pos;
    for (pos = stocks.begin(); pos != stocks.end(); ++pos){
        cout << "stock: " << pos->first << "\t"
           << "price: " << pos->second << endl;
    }
    cout << endl;

    for (pos = stocks.begin(); pos != stocks.end(); ++pos){
        pos->second *= 2;
    }

    for (pos = stocks.begin(); pos != stocks.end(); ++pos){
        cout << "stock:  " << pos->first <<"\t"
             << "value:  " << pos->second <<endl;
    }
    cout << endl;

    stocks["Volkswagen"]=stocks["VW"];
    stocks.erase("VM");

    for (pos = stocks.begin(); pos != stocks.end(); ++pos){
        cout << "stock:  " << pos->first << "\t"
             << "price:  " << pos->second << endl;
    }

    //mmap1.cpp
    typedef multimap<string, string> StrStrMMap;

    StrStrMMap dict;
    dict.insert(make_pair("day", "Tag"));
    dict.insert(make_pair("strange","fremd"));
    dict.insert(make_pair("car","Auto"));
    dict.insert(make_pair("smart","elegant"));
    dict.insert(make_pair("trait","Merkmal"));
    dict.insert(make_pair("strange","seltsam"));
    dict.insert(make_pair("smart","raffiniert"));
    dict.insert(make_pair("smart","klug"));
    dict.insert(make_pair("clever","raffiniert"));

    StrStrMMap::iterator pos2;
    cout.setf(ios::left, ios::adjustfield);
    cout << ' ' << setw(10) << "english "
         << "german " << endl;
    cout << setfill('-') <<setw(20) <<""
         << setfill(' ') << endl;
    for (pos2 = dict.begin(); pos2 != dict.end(); ++pos2){
        cout << ' ' << setw(10) << pos2->first.c_str()
             << pos2->second <<endl;
    }
    cout << endl;

    string word("smart");
    cout << word << ": " << endl;
    for (pos2 = dict.lower_bound(word);
         pos2 != dict.upper_bound(word); ++pos2){
             cout << "   " << pos2->second << endl;
    }
    word = ("raffiniert");
    cout << word << ": " << endl;
    for (pos2 = dict.begin(); pos2 != dict.end(); ++pos2){
        if (pos2->second == word){
            cout <<"    " << pos2->first << endl;
        }
    }

    //mset.cpp
    typedef multiset<int, greater<int>> IntSet;
    IntSet coll3;

    coll3.insert(4);
    coll3.insert(3);
    coll3.insert(5);
    coll3.insert(1);
    coll3.insert(6);
    coll3.insert(2);
    coll3.insert(5);

    IntSet::iterator pos3;
    for(pos3 = coll3.begin(); pos3 != coll3.end(); ++pos3){
        cout << *pos3 << ' ';
    }
    cout << endl;

    IntSet::iterator ipos=coll3.insert(4);
    cout << "4 inserted as element "
         << distance(coll3.begin(), ipos) + 1 << endl;

    multiset<int> coll4(coll3.begin(),
                        coll3.end());

    copy(coll4.begin(), coll4.end(),
         ostream_iterator<int>(cout, " "));
    cout << endl;

    coll4.erase(coll4.begin(), coll4.find(3));

    int num;
    num=coll4.erase(5);
    cout << num <<" element(s) removed" << endl;

    copy(coll4.begin(), coll4.end(),
         ostream_iterator<int>(cout, " "));
    cout << endl;

    //pqueue1.cpp
    priority_queue<float> q;
    q.push(66.6);
    q.push(22.2);
    q.push(44.4);

    cout << q.top() << ' ';
    q.pop();
    cout << q.top() << endl;
    q.pop();

    q.push(11.1);
    q.push(55.5);
    q.push(33.3);

    q.pop();

    while (!q.empty()){
        cout << q.top() << ' ';
        q.pop();
    }
    cout << endl;

    //queue1.cpp
    queue<string> q1;

    q1.push("These ");
    q1.push("are ");
    q1.push("more than ");

    cout << q1.front();
    q1.pop();
    cout << q1.front();
    q1.pop();

    q1.push("four ");
    q1.push("words!");

    q1.pop();

    cout << q1.front();
    q1.pop();
    cout << q1.front() << endl;
    q1.pop();

    cout << "number of elements in the queue: " << q1.size()
         << endl;

    //set1.cpp
    typedef set<int, greater<int>> IntSet2;
    IntSet2 coll5;
    coll5.insert(4);
    coll5.insert(3);
    coll5.insert(5);
    coll5.insert(1);
    coll5.insert(6);
    coll5.insert(2);
    coll5.insert(5);

    IntSet2::iterator pos4;
    for (pos4=coll5.begin(); pos4!=coll5.end(); ++pos4){
        cout << *pos4 << endl;
    }

    pair<IntSet::iterator,bool> status = coll5.insert(4);
    if (status.second){
        cout << "4 inserted as element "
             << distance(coll5.begin(), status.first)+1
             << endl;
    }
    else{
        cout << "4 already exists " << endl;
    }

    set<int> coll6(coll5.begin(),
                   coll5.end());
    copy(coll6.begin(), coll6.end(),
         ostream_iterator<int>(cout, " "));
    cout << endl;

    coll6.erase(coll6.begin(), coll6.find(3));

    int num2;
    num2=coll6.erase(5);
    cout << num2 << " element(s) removed " << endl;

    copy(coll6.begin(), coll6.end(),
         ostream_iterator<int>(cout," "));
    cout << endl;

    //set2.cpp
    set<int> c;

    c.insert(1);
    c.insert(2);
    c.insert(4);
    c.insert(5);
    c.insert(6);

    cout << "lower_bound(3): " << *c.lower_bound(3) << endl;
    cout << "upper_bound(3): " << *c.upper_bound(3) << endl;
    cout << "equal_range(3): " << *c.equal_range(3).first << " "
                               << *c.equal_range(3).second << endl;
    cout << endl;
    cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
    cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
    cout << "equal_range(5): " << *c.equal_range(5).first << " "
                               << *c.equal_range(5).second << endl;

//    //sortset.cpp
//    set<string> coll7((istream_iterator<string>(cin)),
//                     istream_iterator<string>());
//
//    copy(coll7.begin(), coll7.end(),
//         ostream_iterator<string>(cout, "\n"));

//    //sortvec.cpp
//    vector<string> coll8((istream_iterator<string>(cin)),
//                         istream_iterator<string>());
//    sort(coll8.begin(),coll8.end());
//
//    unique_copy(coll8.begin(), coll8.end(),
//                ostream_iterator<string>(cout, "\n"));

    //stack1.cpp
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);

    cout << st.top() << ' ';
    st.pop();
    cout << st.top() << ' ';
    st.pop();

    st.top() = 77;

    st.push(4);
    st.push(5);

    st.pop();

    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << endl;

    //vector1.cpp
    vector<string> sentence;

    sentence.reserve(5);

    sentence.push_back("Hello,");
    sentence.push_back("how");
    sentence.push_back("are");
    sentence.push_back("you");
    sentence.push_back("?");

    copy (sentence.begin(), sentence.end(),
          ostream_iterator<string>(cout," "));
    cout << endl;

    cout << "  max_size(): " << sentence.max_size() << endl;
    cout << "  size():     " << sentence.size()     << endl;
    cout << "  capacity(): " << sentence.capacity() << endl;

    swap (sentence[1], sentence[3]);

    sentence.insert (find(sentence.begin(),sentence.end(),"?"),
                     "always");

    sentence.back() = "!";

    copy (sentence.begin(), sentence.end(),
          ostream_iterator<string>(cout," "));
    cout << endl;

    cout << "  max_size(): " << sentence.max_size() << endl;
    cout << "  size():     " << sentence.size()     << endl;
    cout << "  capacity(): " << sentence.capacity() << endl;
}
