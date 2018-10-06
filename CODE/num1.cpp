#include <iostream>
#include <complex>
#include <cstdlib>
#include <limits>
#include <valarray>
using namespace std;

template<class T>
void printVarray3D(const valarray<T>& va, int dim1, int dim2)
{
    for(int i=0; i<va.size()/(dim1*dim2); ++i){
        for (int j=0; j<dim2; ++j){
            for (int k=0; k<dim1; ++k){
                cout << va[i*dim1*dim2+j*dim1+k] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    cout << endl;
}

//template<class T>
//void printValarry(const valarray<T>& va, int num)
//{
//    for (int i=0; i<va.size()/num; i++){
//        for(int j=0; j<num; j++){
//            cout << va[i*num+j]<< ' ';
//        }
//        cout << endl;
//    }
//    cout << endl;
//}

template<class T>
void printVarray(const valarray<T>& va)
{
    for(int i=0; i<va.size(); i++){
        cout << va[i] << ' ';
    }
    cout << endl;
}

int main()
{
//complex1.cpp
//    complex<double> c1(4.0,3.0);
//    complex<float> c2(polar(5.0,0.75));
//    cout << "c1: " << c1 << endl;
//    cout << "c2: " << c2 << endl;
//
//    cout << "c1 magnitude: " << abs(c1)
//         << " (squared magnitude: " << norm(c1) << " )"
//         << " phase angle: " << arg(c1) << endl;
//    cout << "c2 magnitude: " << abs(c2)
//         << " (squared magnitude: " << norm(c2) << " )"
//         << " phase angle: " << arg(c2) << endl;
//
//    cout << "c1 conjugated: " << conj(c1) << endl;
//    cout << "c2 conjugated: " << conj(c2) << endl;
//
//    cout << "4.4 + c1 * 1.8: " << 4.4+c1*1.8 << endl;
//
//    cout << "c1 + c2:   "
//         << c1 +complex<double>(c2.real(), c2.imag()) << endl;
//
//    cout << "c1 += sqrt(c1): " << (c1 += sqrt(c1)) << endl;


//complex2.cpp
//    complex<long double> c1, c2;
//    while (cin.peek() != EOF){
//        cout << "complex number c1: ";
//        cin >> c1;
//        if (!cin){
//            cerr << "input error" << endl;
//            return EXIT_FAILURE;
//        }
//        cout << "complex number c2: ";
//        cin >> c2;
//        if(!cin) {
//            cerr << "input error" << endl;
//            return EXIT_FAILURE;
//        }
//
//        if (c1 == c2) {
//            cout << "c1 and c2 are equal !" << endl;
//        }
//
//        cout << "c1 raised to the c2: " << pow(c1,c2)
//             << endl << endl;
//
//        cin.ignore(numeric_limits<int>::max(), '\n');
//
//    }

//gslice1.cpp
//    valarray<double> va(24);
//    for(int i=0; i<24; i++){
//        va[i]=i;
//    }
//    printVarray3D(va,3,4);
//
//    size_t lengthvalues[]={2,3};
//    size_t stridevalues[]={12,3};
//    valarray<size_t> length(lengthvalues,2);
//    valarray<size_t> stride(stridevalues,2);
//
//    va[gslice(0,length,stride)]
//        =valarray<double>(va[gslice(1,length,stride)]);
//
//    va[gslice(0,length,stride)]
//        =valarray<double>(va[gslice(1,length,stride)]);
//
//    va[gslice(0,length,stride)]
//        +=valarray<double>(va[gslice(2,length,stride)]);
//
//    printVarray3D(va,3,4);

//indi1.cpp
//    valarray<double> va(12);
//    for (int i=0; i<12; i++){
//        va[i]=(i+1)*1.01;
//    }
//    printValarry(va,4);
//
//    valarray<size_t> idx(4);
//    idx[0]=8;
//    idx[1]=0;
//    idx[2]=3;
//    idx[3]=7;
//
//    printValarry(valarray<double>(va[idx]), 4);
//
//    va[0]=11.11;
//    va[3]=44.44;
//    printValarry(valarray<double>(va[idx]), 4);
//
//    idx[0]=1;
//    idx[1]=2;
//    idx[2]=5;
//    idx[3]=8;
//    va[idx]=99;
//
//    printValarry(va,4);

//masked1.cpp
//    valarray<double> va(12);
//
//    for(int i=0; i<12; i++){
//        va[i]=i;
//    }
//    printValarry(va,3);
//
//    va[va<5.0]=77.0;
//
//    va[va>5.0 && va<9.0]
//        =valarray<double>(va[va>5.0 && va<9.0]) +100.0;
//
//    printValarry(va,3);

//slice1.cpp
//    valarray<double> va(12);
//    for(int i=0; i<12; i++){
//        va[i]=i;
//    }
//
//    printValarry(va,3);
//
//    va[slice(0,4,3)]=pow(valarray<double>(va[slice(1,4,3)]),
//                         valarray<double>(va[slice(2,4,3)]));
//
//    printValarry(va,3);
//
//    valarray<double> vb(va[slice(2,4,0)]);
//
//    va[slice(2,4,3)] *= vb;
//
//    printValarry(va,3);
//
////    printValarry(sqrt(valarray<double>(va[slice(3,3,1)])));
//
//    va[slice(2,4,3)] = valarray<double>(va[slice(2,4,3)]) * 2.0;
//
//    printValarry(va,3);

//val1.cpp
    valarray<double> va1(10), va2(10);
    for(int i=0; i<10; i++){
        va1[i]=i*1.1;
    }
    va2=-1;
    printVarray(va1);
    printVarray(va2);

    cout << "min(): " << va1.min() << endl;
    cout << "max(): " << va1.max() << endl;
    cout << "sum(): " << va1.sum() << endl;

    va2=va1;

    va1.resize(0);

    printVarray(va1);
    printVarray(va2);

//val2.cpp
    valarray<double> va(9);
    for(int i=0; i<va.size(); i++){
        va[i]=i*1.1;
    }

    printVarray(va);

    va *=2.0;

    printVarray(va);

    valarray<double> vb(va+10.0);

    printVarray(vb);

    valarray<double> vc(9);
    vc=sqrt(va)+vb/2.0-1.0;

    printVarray(vc);


}
