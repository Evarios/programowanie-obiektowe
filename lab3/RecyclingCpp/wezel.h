#include <iostream>
#include <memory>
using namespace std;
class Wezel{
    public:
        weak_ptr<Wezel> next;
        ~Wezel();
};