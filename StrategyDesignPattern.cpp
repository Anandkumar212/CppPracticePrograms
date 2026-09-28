#include <iostream>
#include <memory>
using namespace std;

//interface class
class PaymentStrategy{
    
    public:
    
    virtual void pay(double amount) =0;
    
    virtual ~PaymentStrategy() =default;
    
};

//concrete class for interface
class UpiPayment : public PaymentStrategy{
    
    public:
    
    void pay(double amount){
        cout << " amount to be paid using UPI payment " << amount << endl;
    }
};


class CreditCardPayment: public PaymentStrategy{
    
    public:
    
      void pay(double amount){
        cout << " amount to be paid using CreditCardPayment " << amount << endl;
    }

};

class PaytmPayment: public PaymentStrategy{
    
      public:
    
      void pay(double amount){
        cout << " amount to be paid using PaytmPayment " << amount << endl;
    }

};


//Payment Factory 


class PaymentFactory{
    
    public:
    
    static unique_ptr<PaymentStrategy> createPaymentMethod(const string& type){
        if ( type =="UPI"){
            return make_unique<UpiPayment>();
        }
        else if ( type =="CreditCard"){
            return make_unique<CreditCardPayment>();
        }
        else if(type == "Paytm"){
            return make_unique<PaytmPayment>();
        }
        
       return nullptr;
        
    }
    
};


class shoppingCart{
    
    public:
    
    unique_ptr<PaymentStrategy> strategy;
    
   
    
    void setStrategy(unique_ptr<PaymentStrategy>newstrategy){
        
        strategy = move(newstrategy);
        
    }
    void checkout(double amount){
        if(strategy){
            strategy->pay(amount);
        }
        else {
            cout << " strategy- is not Selected " << endl;
        }
    }
    
};

int main(){
    //shoppingCart sc;
    
    auto Payment = PaymentFactory::createPaymentMethod("UPI");
    
    auto Payment1 = PaymentFactory:: createPaymentMethod("CreditCard");
    
    auto Payment2 = PaymentFactory :: createPaymentMethod("Paytm");
    
    
    if(Payment){
        Payment->pay(1000);
    }
    
    // sc.setStrategy(move(Payment));
    // sc.checkout(1000);
    
    //  sc.setStrategy(move(Payment1));
    // sc.checkout(2000);
    //  sc.setStrategy(move(Payment2));
    // sc.checkout(3000);
    
    return 0;
}

