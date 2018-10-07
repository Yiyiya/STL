#include <iostream>
#include <locale>
#include <string>
#include <cstdlib>
#include <iterator>
using namespace std;

int main()
{
//    //loc1.cpp
//    cin.imbue(locale::classic());
//
//    cout.imbue(locale("de_De"));
//
//    double value;
//    while (cin >> value){
//        cout << value << endl;
//    }

////loc2.cpp
//    locale langLocale("");
//    cout.imbue(langLocale);
//
//    bool isGerman;
//    if(langLocale.name() == "de_De" ||
//       langLocale.name() == "de" ||
//    langLocale.name() == "german") {
//        isGerman = true;
//    }
//    else {
//        isGerman = false;
//    }
//
//    if (isGerman) {
//        cout <<  "Sprachumgebung fuer Eingaben: ";
//    }
//    else {
//        cout << "Locale for input: ";
//    }
//    string s;
//    cin >> s;
//    if(!cin){
//        if (isGerman){
//            cerr << "FEHLER beim Einlesen der Sprachumgebung"
//                 << endl;
//        }
//        else {
//            cerr << "ERROR while reading the locale" << endl;
//        }
//        return EXIT_FAILURE;
//    }
//    locale cinLocale(s.c_str());
//    cin.imbue(cinLocale);
//
//    double value;
//    while (cin >> value) {
//        cout << value << endl;
//    }

//numget.cpp
    std::locale loc;
    typedef std::istreambuf_iterator<char> InIt;
    InIt beg = InIt(std::cin);
    InIt end = InIt();

    std::ios_base& fmt = std::cin;

    std::ios_base::iostate err;
    float value1;

    std::num_get<char, InIt> const& ng
        =std::use_facet<std::num_get<char, InIt>>(loc);

    ng.get(beg, end,fmt,err,value1);

    if(err == std::ios_base::goodbit) {
        std::cout << "value1: " << value1 <<  '\n';
    }
    else if (err == std::ios_base::eofbit){
        std::cout << "value1: " << value1 <<  " (EOF encountered)\n";
    }
    else if (err & std::ios_base::badbit){
        std::cerr << "fatal error while reading numeric value\n";
        return EXIT_FAILURE;
    }
    else if (err & std::ios_base::failbit){
        std::cerr << "format error while reading numeric value\n";
        return EXIT_FAILURE;
    }



}
