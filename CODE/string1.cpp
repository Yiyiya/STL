#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <locale>
using namespace std;

bool nocase_compare (char c1, char c2)
{
    return toupper(c1) == toupper(c2);
}

class bothWhiteSpaces{
private:
    const locale& loc;
public:
    bothWhiteSpaces (const locale& l) : loc(l) {
    }
    bool operator()(char elem1, char elem2){
        return isspace(elem1,loc) && isspace(elem2,loc);
    }
};

int main(int argc, char* argv[])
{
    //iter1.cpp
    string s("The zip code of Hondelage in Germany is 38108");
    cout << "original: " << s << endl;

    transform (s.begin(), s.end(),
               s.begin(),
               ::tolower);
    cout << "lowered: " << s << endl;

    transform (s.begin(), s.end(),
              s.begin(),
              ::toupper);
    cout << "uppered: " << s << endl;

    //iter2.cpp
    string s1("This is a string");
    string s2("STRING");

    if (s1.size() == s2.size() &&
        equal (s1.begin(), s1.end(),
               s2.begin(),
               nocase_compare)) {
        cout << "the strings are equal" << endl;
    }
    else {
        cout << "the strings are not equal" << endl;
    }

    string::iterator pos;
    pos = search (s1.begin(), s1.end(),
                  s2.begin(),s2.end(),
                  nocase_compare);

    if(pos == s1.end()) {
        cout << "s2 is not a substring of s1" << endl;
    }
    else{
        cout << '"' << s2 << "\" is a substring of \""
             << s1 << "\" (at index " << pos - s1.begin() <<")"
             <<endl;
    }

//    //iter3.cpp
    const string hello("Hello, how are you?");
    string s(hello.begin(), hello.end());

    string::iterator pos;
    for (pos = s.begin(); pos != s.end(); ++pos){
        cout << *pos;
    }
    cout << endl;

    reverse (s.begin(), s.end());
    cout << "reverse:  " << s << endl;

    sort (s.begin(), s.end());
    cout << "ordered:  " << s << endl;

    s.erase(unique(s.begin(),
                   s.end()),
            s.end());
    cout << "no duplicates: " << s << endl;

//    //string1.cpp
    string filename, basename, extname, tmpname;
    const string suffix("tmp");

    for (int i=1; i<argc; ++i) {
        filename = argv[i];

        string::size_type idx = filename.find('.');
        if(idx == string::npos){
            tmpname = filename + '.' +suffix;
        }
        else {
            basename = filename.substr(0,idx);
            extname = filename.substr(idx+1);
            if (extname.empty()) {
                tmpname = filename;
                tmpname = suffix;
            }
            else if(extname == suffix){
                tmpname = filename;
                tmpname.replace(idx+1, extname.size(), "xxx");
            }
            else {
                tmpname = filename;
                tmpname.replace(idx+1, string::npos, suffix);
            }
        }
        cout << filename << " => " <<tmpname << endl;
    }

//    //string2.cpp
//    const string delims("\t,.;");
//    string line;
//
//    while (getline(cin,line)) {
//        string::size_type begIdx, endIdx;
//        begIdx = line.find_first_not_of(delims);
//
//        while (begIdx != string::npos) {
//            endIdx = line.length();
//
//            for (int i=endIdx-1; i>=static_cast<int>(begIdx); --i){
//                cout << line[i];
//            }
//            cout << ' ';
//            begIdx = line.find_first_not_of(delims, endIdx);
//        }
//        cout << endl;
//    }

//unique.cpp
    string contents;
    cin.unsetf(ios::skipws);
    unique_copy(istream_iterator<char>(cin),
                istream_iterator<char>(),
                back_inserter(contents),
                bothWhiteSpaces(cin.getloc()));

    cout << contents;

}
