#include "wezel.h"
#include <iostream>
#include <memory>
using namespace std;
int main (){
    for(int i = 0; i < 10; i++){
        shared_ptr<Wezel> w1 = make_shared<Wezel>();
        shared_ptr<Wezel> w2 = make_shared<Wezel>();
        w1-> next = w2;
        w2 -> next = w1;
        // 4: jest usuwany po każdym przebiegu pętli, w przeciwieństwie do javy, gdzie istnieje przez jakiś czas
        // 6: przebieg programu wygląda tak samo
    }
    return 0;
}

