#include <iostream>
using namespace std;

class MyCls {
public:
    Mycls() { cout << "default" << endl; }
    Mycls(const MyCls &rhs) { cout << "copyConstructor" << endl; }
    Mycls(MyCls &rhs) { cout << "moveConstructor" << endl; }
    // rhs，right hand side
};

MyCls return_urvo_value() {
    return MyCls{};
}

MyCls return_nrvo_value() {
    MyCls local_obj;
    return local_obj;
}

int main() {
    auto x = return_urvo_value();
    auto y = return_nrvo_value();
    return 0;
}