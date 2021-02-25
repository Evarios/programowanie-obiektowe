#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class Samochod{
    private:
        float pojemnosc_baku;
        float poziom_paliwa;
        unsigned int liczba_kilometrow;
        string model;
    public:
    Samochod(){
        pojemnosc_baku = 50;
        poziom_paliwa = 15;
        liczba_kilometrow = 263000;
        model = "Mazda 323F";
    }
    Samochod(float pojemnosc, string model_s){
        pojemnosc_baku = pojemnosc;
        model = model_s;
        poziom_paliwa = 50;
        liczba_kilometrow = 0;

    }
    float odczytaj_pojemnosc_baku() const{
        return pojemnosc_baku;
    }
    void setMaxFuel(int maxFuel){
        pojemnosc_baku = maxFuel;
    }

    float readFuelLevel(){
        return poziom_paliwa;
    }

    unsigned int readPrzebieg(){
        return liczba_kilometrow;
    }

    operator bool() const{
        if(model != "" && pojemnosc_baku >0){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator !() const{
        if(model != "" && pojemnosc_baku >0){
            return true;
        }
        else{
            return false;
        }
    }

    friend ostream & operator << (ostream & os, const Samochod & samochod){
        os << samochod.model << " " << samochod.poziom_paliwa << "\n";
        return os;
    } //friend oznacza klasę zaprzyjaźnioną, a klasa zaprzyjaźniona ma dostep do prywatnych pól (w tym wypadku klasa ostream)

    bool operator < (const Samochod & samochod) const{
        return this->model < samochod.model;
    }// dzięki słówu kluczowemu const mamy zagwarantowane to, że funkcja nie zmieni wartości pól klasy

    void operator ++ () {
        pojemnosc_baku = pojemnosc_baku + 1;
    }

    friend void operator , (Samochod & s1, Samochod & s2) {
        float temp = s1.poziom_paliwa;
        s1.poziom_paliwa = s2.poziom_paliwa;
        s2.poziom_paliwa = temp;
    }

    friend void operator |= (Samochod & s, int n) {
        s.liczba_kilometrow += n;
    }

};

struct cmp{
    bool operator() (const Samochod &a, const Samochod &b)
    const{
        return a.odczytaj_pojemnosc_baku() < b.odczytaj_pojemnosc_baku();
    }
 };

int main(){
    Samochod s1(123, "audi");
    Samochod s2(0, "bmw");
    Samochod s3(200, "");
    if(s1){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    if(s2){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    if(s3){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    // test !sx
    if(!s1){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    if(!s2){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    if(!s3){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    cout << s1;

    /*****************************/
    vector <Samochod> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    sort(v.begin(), v.end());
    for(auto it=v.begin(); it!=v.end(); ++it) {
    cout << *it << endl;
    }

    /*****************************/
    set <Samochod, cmp> s;
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);
    for(auto it=s.begin(); it!=s.end(); ++it){
        cout << *it << endl;
    }

    return 0;
}