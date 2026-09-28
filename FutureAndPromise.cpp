#include <iostream>
//#include <promise>
#include <thread>
#include <future>
using namespace std;

class promiseAndFuture{
    
    public:
    
    
    int calculate( int a, int b){
        
        return a+b;
    }
    
    void fun(promise<int> p){
        
        int result=calculate(1,2);
        
        p.set_value(result);
        
    }
};
int main(){
    
    promiseAndFuture pf;
    
    promise<int> p;
    future<int> f = p.get_future();
    
    thread t1(&promiseAndFuture::fun, &pf, move(p) );
    
    
    cout << "Waiting for set value \n" ;
    
    int value= f.get();
    
    
    cout << "value is " << value << endl;
    
    t1.join();
    
    
}

