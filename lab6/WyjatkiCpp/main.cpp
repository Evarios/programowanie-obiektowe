#include<iostream>
#include<vector>
#include<string>
using namespace std;


class StackException : public exception{
    public:
        StackException(){}
        virtual const char* what() const noexcept override{
            return "Bledna operacja na stosie!";
        }
};

class StackFullException : public StackException{
    private:
        int element = 0;
        int maxStackSize = 0;
        string message;
    public:
        StackFullException(){}
        StackFullException(string p, int e, int s){
            element = e;
            maxStackSize = s;
            message = p;
        }
        virtual const char* what() const noexcept override{
            string error = "wiadomosc: " + message + " maxStackSize: " + to_string(maxStackSize) + " element " + to_string(element);
            return error.c_str(); 
        }//noexcept zwraca true, jeżeli dane wyrażenie nie wyrzuci wyjątku, 
};

class StackEmptyException : public StackException{
    private:
        string message;
    public:
        StackEmptyException(){}
        StackEmptyException(string p){
            message = p;
        }
        virtual const char* what() const noexcept override{
            return message.c_str(); 
        }
};


class Stack{
private:
    int maxStackSize= 5;
    vector<int> dfs;
    int top = 0;
public:
    Stack(){};
    Stack(int max){
        maxStackSize = max;
    }
    void push(int x){
        if(dfs.size() < maxStackSize){
            dfs.push_back(x);
            top++;
        }
        else{
            throw StackFullException("StackOverflow", x, maxStackSize);
        }
    }
    int pop(){
        if(top>0){
            dfs.pop_back();
            top--;
            return top;
        }        
        else{
            throw StackEmptyException("StackEmpty");
        }
    }
};

void foo(Stack &s){
    try{
        int i = 0;
        while(true){
            s.push(i);
            i++;
        }
    }
    catch(StackException &e){
        cout << "wyjatek  " << e.what() <<endl;
    }
}

void bar(Stack &s){
    try{
        int i = 0;
        while(true){
            s.push(i);
            i++;
        }
    }
    catch(StackException &e){
        cout << e.what() <<endl;
    }
}


int main() {
    Stack s;
    try{
        string cmd;
        while(true){
            cin >> cmd;
            if (cmd == "exit"){
                break;
            }
            else if(cmd == "push"){
                int x;
                cin >> x;
                s.push(x);
            }
            else if(cmd == "pop"){
                s.pop();
            }
        }
        

    }
    catch(StackException &e){
        cout << e.what() <<endl;
    }
    catch(exception &e){
        cout << e.what() <<endl;
    }

    return 0;
}