#include <iostream>
#include <functional>
using namespace std;
typedef int (*job) (int a, int b);
typedef function<int(int, int)> task;

class MyCls 
{
public:
    MyCls(const int size): SIZE(size){}  // 初始化列表

private:
    int val;
    const int SIZE;
};


typedef struct POINT {
    int x;
    int y;

    void output() {
        cout << x << ", " << y << endl;
    }

} POINT;

POINT SetVal(int a, int b) {
    POINT p;
    p.x = a;
    p.y = b;
    return p;
}

int add(int a, int b) { return a+b; }
void myFunc(int a, int b, int (*p)(int, int)) { cout << p(a, b) << endl; }


int main() {
    // const int a = 10;
    // MyCls mycls(a);
    // POINT p;
    // p.x = 1;
    // p.y = 2;
    // p.output();

    // SetVal(3, 4).output();


    job p;
    // task p;
    p = add;
    cout << p(1, 2) << endl;
    // myFunc(2, 3, add);
    myFunc(2, 3, p);
    return 0;
}