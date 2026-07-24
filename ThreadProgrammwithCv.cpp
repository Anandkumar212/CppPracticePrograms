#include <iostream>
#include <thread>

#include <mutex>

#include <condition_variable>




using namespace std;
mutex mtx;

condition_variable cv;

bool value =true;

void print(){
    
    //lock_guard<mutex> lock(mtx);
    
    

    for(int i= 0; i<=10; i++){
        
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] {return value;});
    cout <<" thread programm " << i <<endl ;
    
    value = false;
    
    cv.notify_one();
    
    
}


    
}
void eventNumber(int n){
     
     for(int i =0; i<=n; i++){
         
          unique_lock<mutex> lock(mtx);
         cv.wait(lock, [] {return !value;});
         
         if( i%2 ==0){
             cout << "that is eventNumber " << i << endl;
         }
         else
         cout<< "that is oddNumber " << i <<endl;
          value = true;
    
          cv.notify_one();
         
     }
     
     
}

int main(){
    
    thread t(print);
    
    
    thread t1(eventNumber,10);
    t.join();
    t1.join();
    return 0;
    
}