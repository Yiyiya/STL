#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <bitset>
using namespace std;

void printFileTwice(const char* filename)
{
    std::ifstream file(filename);

    std::cout << file.rdbuf();
    file.seekg(0);
    std::cout << file.rdbuf();
}

void writeCharsetToFile (const string& filename);
void outputFile (const string& filename);

int countLines(std::istream& in);

void hexMultiplicationTable(std::streambuf*buffer, int num)
{
    std::ostream hexout(buffer);
    hexout << std::hex << std::showbase;

    for (int i=1; i<=num; ++i){
        for (int j=1; j<=10; ++j){
            hexout << i*j << ' ';
        }
        hexout << std::endl;
    }
}

void redirect(ostream&);

namespace MyLib {
    double readAndProcessSum (std::istream&);
}

int main(int argc, char* argv[])
{

//cat1.cpp
//    ifstream file;
//
//    for (int i=1; i<argc; ++i){
//        file.open(argv[i]);
//
//        char c;
//        while (file.get(c)) {
//            cout.put(c);
//        }
//        file.clear();
//        file.close();

//cat2.cpp
//        for (int i=1; i<argc; ++i){
//            printFileTwice(argv[i]);
//        }


//charcat1.cpp
//        char c;
//        while (cin.get(c)) {
//            cout.put(c);
//        }


//charcat2.cpp
//    istreambuf_iterator<char> inpos(cin);
//
//    istreambuf_iterator<char> endpos;
//
//    ostreambuf_iterator<char> outpos(cout);
//
//    while (inpos != endpos){
//        *outpos = *inpos;
//        ++inpos;
//        ++outpos;
//    }

//charset.cpp
//    writeCharsetToFile("charset.out");
//    outputFile("charset.out");

//copy1.cpp
//    std::cout << std::cin.rdbuf();

// copy2.cpp
//    std::cin >> std::noskipws >> std::cout.rdbuf();

//coutlines.cpp
//    int count;
//    if (argc == 1){
//        count = countLines(std::cin);
//    }
//    else{
//        std::ifstream in;
//        count = 0;
//        for (int i=1; i<argc; ++i){
//            in.open(argv[i]);
//            if (!in) {
//                std::cerr << "failed to open " << argv[1] << "\n";
//            }
//            else {
//                count +=countLines(in);
//                in.close();
//            }
//        }
//    }
//    std::cout << count << std::endl;

//io1.cpp
//    double x,y;
//    cout << "Multiplication of two floating point values " << endl;
//
//    cout << "first operand:  ";
//    if (!(cin >> x)) {
//        cerr << "error while reading the forst floating value"
//             << endl;
//        return EXIT_FAILURE;
//    }
//
//    cout << "second operand:  ";
//    if (!(cin >> y)){
//        cerr << "error while reading the second floating value"
//             << endl;
//        return EXIT_FAILURE;
//    }
//    cout << x << " times " << y << " equals " << x*y << endl;

//rdbuf.cpp
//    ostream hexout(cout.rdbuf());
//    hexout.setf(ios::hex, ios::basefield);
//    hexout.setf(ios::showbase);
//
//    hexout << "hexout: " << 177 << " ";
//    cout   << "cout: "   << 177 << " ";
//    hexout << "hexout: " << -49 << " ";
//    cout   << "cout: "   << -49 << " ";
//    hexout << endl;

//rdbuf2.cpp
//    int num = 5;
//    cout << "We print " << num
//         << " lines hexadecimal" << endl;
//
//    hexMultiplicationTable(cout.rdbuf(), num);
//    cout << "That was the output of " << num
//         << " hexadecimal lines " << endl;

//redirect.cpp
//    cout << "the first row" << endl;
//    redirect(cout);
//    cout << "the last row" << endl;

//rw1.cpp
//    filebuf buffer;
//    ostream output(&buffer);
//    istream input(&buffer);
//    buffer.open("example.dat", ios::in | ios::out | ios::trunc);
//
//    for (int i=1; i<=4; i++){
//        output << i << ".line" << endl;
//    }
//
//    input.seekg(0);
//    char c;
//    while (input.get(c)){
//        cout.put(c);
//    }
//    cout << endl;
//    input.clear();

//sstr1.cpp
//    ostringstream os;
//    os << "dec; " << 15 << hex << " hex: " <<15 << endl;
//    cout << os.str() << endl;
//
//    bitset<15> b(5789);
//    os << "float: " << 4.67 << " bitset: " << b << endl;
//
//    os.seekp(0);
//    os << "oct: " << oct << 15;
//    cout << os.str() << endl;

    double sum;

    try {
        sum = MyLib::readAndProcessSum(cin);
    }
    catch (const ios::failure& error) {
        cerr << "I/O exception: " << error.what() << endl;
        return EXIT_FAILURE;
    }
    catch (const exception& error) {
        cerr << "standard exception: " << error.what() << endl;
        return EXIT_FAILURE;
    }
    catch (...) {
        cerr << "unknown exception" << endl;
        return EXIT_FAILURE;
    }

}

#include <istream>
namespace MyLib{
    double readAndProcessSum(std::istream& strm)
    {
        double value, sum;
        sum = 0;
        while (strm >> value) {
            sum += value;
        }
        if (!strm.eof()){
            throw std::ios::failure
                    ("input error in readANdProcessSum()");
        }
        return sum;
    }
}

//#include <istream>
//
//namespace MyLib {
//    double readAndProcessSum (std::istream& strm)
//    {
//        using std::ios;
//        double value, sum;
//
//        ios::iostate oldExceptions = strm.exceptions();
//
//        strm.exceptions (ios::failbit | ios::badbit);
//
//        try {
//            sum = 0;
//            while (strm >> value) {
//                sum += value;
//            }
//        }
//        catch (...) {
//            if (!strm.eof()) {
//                strm.exceptions(oldExceptions);
//                throw;
//            }
//        }
//
//        strm.exceptions (oldExceptions);
//        return sum;
//    }
//}
void redirect(ostream& strm)
{
    ofstream file("redirect.txt");
    streambuf* strm_buffer = strm.rdbuf();
    strm.rdbuf(file.rdbuf());

    file << "one row for the file" << endl;
    strm << "one row for the stream" << endl;

    strm.rdbuf(strm_buffer);
}


void writeCharsetToFile(const string& filename)
{
    ofstream file(filename.c_str());

    if (! file) {
        cerr << "can't open output file \"" << filename << "\""
             << endl;
        exit(EXIT_FAILURE);
    }

    for (int i=32; i<256; i++){
        file << "Value: " << setw(3) << i << "  "
             << "char:  " << static_cast<char>(i) << endl;
    }
}

void outputFile(const string& filename)
{
    ifstream file(filename.c_str());

    if (! file){
    cerr << "can't open input file \"" << filename << "\""
         << endl;
    exit(EXIT_FAILURE);
    }

    char c;
    while (file.get(c)){
        cout.put(c);
    }

}

int countLines(std::istream& in)
{
    return std::count(std::istreambuf_iterator<char>(in),
                      std::istreambuf_iterator<char>(),
                      '\n');
}


