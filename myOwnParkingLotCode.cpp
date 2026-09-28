/** designing the parking using Mutex and condition Variable 
 * 
 * 
 **/
 
 #include <iostream>
 #include <thread>
 #include <condition_variable>
 #include <mutex>
 #include <vector>
 #include <algorithm>
 
using namespace std;

int n = 6618;
class parkingLot{
    mutex mtx;
    condition_variable cv;
    vector<int> v;
    
    int capacity;
    
    public:
    
    parkingLot(int a){
        capacity= a;
    }
    
    void parkingCars(int cardId){
       
            unique_lock<mutex> lock (mtx);
            cv.wait(lock, [this] {return capacity >0;});
           
            v.push_back(cardId);
             capacity --;
            
            cout << "card is pushed with id " << cardId << endl; 
        
        
        if(capacity==0){
            
        for(int i = 0; i < v.size()-1; i++){
            leaveCar(v[i]);
        }
        }
    }
    
    void leaveCar(int cardId){
        
        auto it = find(v.begin(), v.end(), cardId);
        
        if(*it== cardId){
            cout << "removed carID is :" << *it << endl;
            v.erase(it);
        }
        capacity++;
        cv.notify_one();
        cout << "capacity increased : " << capacity << endl;
    }
    
};



int main(){
    int available =3;
    parkingLot pl(available);
    
    for( int i=0; i <  5;i++ ){
        
    
    thread t1(&parkingLot::parkingCars, &pl,n);
    n++;
    
    t1.join();
    }  
    
}