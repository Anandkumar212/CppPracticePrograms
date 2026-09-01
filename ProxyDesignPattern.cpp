#include <iostream>


using namespace std;

class Image{
    
    public:
    
    virtual void display() =0;
};

class RealImage: public Image{
    string fileName;
    
    
    public:
    
    RealImage( string fileName){
      this->fileName = fileName;
       // cout <<fileName <<endl;
    }
    void display(){
        cout << "File name" << fileName <<endl;
    }
};

class ImageProxy: public Image{
    
    RealImage *realImage;
    string fileName;
    
    
    public:
    
    ImageProxy(){
        realImage=nullptr;
        fileName =fileName;
    }
    
    void display(){
        
        if(realImage==nullptr){
            realImage= new RealImage(fileName);
        }
        realImage->display();
        
    }
};





int main(){
    Image *image = new RealImage("example.jpg");
    
  image-> display();
    
    
}