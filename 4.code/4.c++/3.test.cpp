/*************************************************************************
	> File Name: 3.test.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月18日 星期五 10时41分54秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

template <typename T1, typename T2>
class Test {
public :
    void add(T1 a, T2 b) {
        cout << "void add(T1 a, T2 b)" << endl;
        cout << a + b << endl;
    }
};

// 部分特化（偏特化）
template <typename T>
class Test<T, T> {
public :
    void add(T a, T b) {
        cout << "void add(T a, T b)" << endl;
        cout << a + b << endl;
    }
    void print() {
        cout << endl;
    }
};

template <typename T>
class Test<T *, T *> {
public :
    void add(T *a, T *b) {
        cout << "void add(T *a, T *b)" << endl;
        cout << *a + *b << endl;
    }
};
/*
template <typename T>
class Test<T, int> {
public :
    void add(T a, int b) {
        cout << "void add(T a, int b)" << endl;
        cout << a + b << endl;
    }
};
*/
// 完全特化
template <>
class Test<void *, void *> {
public :
    void add(void *a, void *b) {
        cout << "void add(void *a, void *b)" << endl;
        cout << "ERRO!" << endl;
    }
    void print() {
        cout << endl;
    }
};

/*
// 函数模板的完全特化
template <typename T>
bool equal(T a, T b) {
    cout << "bool equal(T a, T b)" << endl;
    return a == b;
}

template < >
bool equal<double>(double a, double b) {
    cout << "bool equal<double>(double, double)" << endl;
    const double x = 1e-7;
    double ret = a - b;
    return ((ret > -x) && (ret < x));
}
*/

int main() {
    /*
    Test<int, double> t;
    t.add(3, 3.16);
    int a = 1, b = 2;
    cout << equal(a, b) << endl;
    cout << equal(3.2, 3.2) << endl;
    */

    Test<int, float> t1;
    t1.add(2, 4.3);
    Test<int, int> t2;
    t2.add(1, 2);
    int a = 1, b = 2;
    Test<int *, int *> t3;
    t3.add(&a, &b);
    Test<void *, void *> t4;
    t4.add(NULL, NULL);

    return 0;
}
