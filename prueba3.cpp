#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class FizzBuzz {
public:
    FizzBuzz(int n) {
        this->n = n;
   }

    void fizzbuzz() {
        
        unique_lock<mutex> lock(mtx);
        if (n % 3 == 0 && n % 5 == 0) {
            cout << "fizzbuzz!" << endl;
        } else if (n % 3 == 0) {
            cout << "fizz!" << endl;
        } else if (n % 5 == 0) {
            cout << "buzz!" << endl;
        } else {
            cout << n << endl;
        }
        
        
    }

private:
    int n;
    mutex mtx;
};

int main() {
    int num; 
    while(true) {
    cout << "ingrese un numero o presiones el numero cero para salir del juego: ";
    cin >> num;
    //cout<< num;
    if (num==0){
        cout << "Game Over";
        return 0;
    }
    else{
        FizzBuzz fb(num);
        thread t(&FizzBuzz::fizzbuzz, &fb);
        t.join();
    }
    }
    
    
}