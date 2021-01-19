#include <iostream>
#include <string>
using namespace std;

int main(){
    string fellow = "world";
    cout << "Hello " << fellow << endl;
    while(fellow != "exit"){
        cout << "Introduce yourself: ";
        cout.flush();
        getline(cin, fellow);
        if(fellow != "exit"){
            cout << "Hello " << fellow << endl;
        }         
    }
return 0;
}