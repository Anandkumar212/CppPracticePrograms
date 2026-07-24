//CPPnutts youtube Channel

#include <iostream>
#include <vector>


using namespace std;



class Subscriber{
    public:
    
    virtual void notify(const string& videoTitle) =0;
};


class Channel {
    
    vector<Subscriber*> subscibers;
    
    public:
     void subscibe(Subscriber* sub){
    subscibers.push_back(sub);
     }
     
     void uploadVideo(const string& title){
         
         cout << "tile of the video is " << title << endl ;
         for(auto* sub: subscibers ){
             sub->notify(title);
         }
         
     }
};

class User: public Subscriber{
    
    string userName;
    
    public:
    User(const string& name): userName(name){};
    
    void notify(const string& videoTitle) override {
        
        cout <<" new video is uploadedin Channel" << userName << endl;
        
    }
};

int main(){
    
    
    Channel AkVideos;
    
    User user("Satish");
    User user1("Pavanth");
    User user2("Raja");
    
    AkVideos.subscibe(&user);
     AkVideos.subscibe(&user1);
      AkVideos.subscibe(&user2);
      
      
      AkVideos.uploadVideo("Observer Pattern");
    
    
    
    return 0;
    
    
    
    
    
    
}