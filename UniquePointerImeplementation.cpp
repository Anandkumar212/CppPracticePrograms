//Implement the Unique Pointer

#include <iostream>

#include <utility>

using namespace std;

template<typename T>

class Uniqueptr{
     T* ptr;
     
     public:
     
     Uniqueptr(T* p =nullptr){
         ptr =p;
     }
     Uniqueptr( const Uniqueptr& ) =delete;
     Uniqueptr& operator=(const Uniqueptr& ) =delete;
     
     
     //move Constructor
     
     Uniqueptr( Uniqueptr && t){
         
         ptr =t.ptr;
         
         t.ptr =nullptr;
         
         
     }
     
     Uniqueptr& operator = (Uniqueptr &&t){
         if(this != &t){
             delete ptr;
             
             ptr = t.ptr;
             t.ptr = nullptr;
         }
         return *this ;
     }
     
     T& operator*() const{
         return *ptr;
         
     } 
     T* operator->() const{
         return ptr;
     }
     T* get() const{
         return ptr;
     }
     T* release(){
         T* temp = ptr;
         ptr = nullptr;
         
         return temp;
     }
     T* reset(T*p = nullptr){
         delete ptr;
         ptr =p;
     }
     
      
};


class Car{
    public:
   Car(){
       cout << "car Constructor called" <<endl;
   }
   void drive(){
       cout <<" car is driving" <<endl;
   }
};




int main(){
    
    Uniqueptr<Car> car(new Car());
    car ->drive();
    
    cout << "address " <<car.get() <<endl;
    
}