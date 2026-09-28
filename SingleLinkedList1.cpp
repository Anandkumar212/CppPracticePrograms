#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node* next;
    
    
    Node(int value){
        data = value ;
        next = nullptr;
    }
};


class SingleLinkedList{
    Node* head;
    
    public:
      SingleLinkedList(){
          head = nullptr;
      }
      
      void createNode(int value){
         Node* newNode  = new Node(value);
          
          
          newNode->next = head ;
          head = newNode;
      }
      
      void insertAtbegining(int value){
          
          Node* newNode = new Node(value);
          
          if( head == nullptr){
              head = newNode;
              return;
          }
          newNode->next = head;
          
          head = newNode;
      }
      void insertAtEnd(int value){
          
          Node* newNode = new Node(value);
          
          if(head == nullptr){
              cout << " Link is empty";
              head = newNode;
              return;
          }
          
          Node* temp = head;
          
          while(temp->next != nullptr){
              temp = temp->next;
          }
          temp->next= newNode;
          
          temp = newNode;
      }
      
      void insertAtPosition(int value, int pos){
          
          Node* newNode = new Node(value);
          
          if(pos <1){
              cout << "position is invalid \n";
              return;
          }
          if(pos ==1){
              insertAtbegining(value);
              return;
          }
          
          Node *temp = head;
          
          for(int i =0 ; i < pos -1 && temp->next != nullptr; ++i ){
              temp = temp->next;
          }
          
          newNode->next = temp->next;
          
          temp->next = newNode;
          
          
          
          
      }
      
      void display(){
          
          int count =0;
          Node* temp = head ;
          
          while(temp != nullptr){
              cout << " "<<temp->data << "-->" ;
              temp = temp->next;
              count ++;
          }
          cout << "NULL  " <<" count of Nodes " << count << " \n";
          
         
      }
      
      void deleteNodeAtBegining(){
         
         
         if(head == nullptr){
             cout << "there is no list ";
             return;
          }
         cout << "delete Node at Beginingn\n";
         Node* temp = head;
         
      //  temp->next = head;
        //  head = head;
        
       // head= head->next;
        head =temp->next;
          
          delete temp;
      }
      
      void deleteNodeAtLast(){
          
          if( head==nullptr){
              cout<< " No list";
              return;
          }
          
          Node*temp = head;
          
          while(temp->next->next !=nullptr ){
              temp = temp->next;
          }
          cout << temp->next->data <<endl;
          delete temp->next;
          temp->next=nullptr;
          
      }
      void deleteAtPosition(int pos){
          
          if(head == nullptr && pos < 1){
              cout << " List is Empty \n";
              return;
          }
          if(pos ==1){
              deleteNodeAtBegining();
          }
          Node* temp = head;
          for ( int i =1; i < pos -1 && temp != nullptr ; i++){
              
              temp = temp->next;
          }
          
          Node* temp1 = temp->next;
          
          temp->next = temp1->next;
          
          cout << temp1->data << endl;
          
          delete temp1;
      }
      
      int findNode(int value){
          
          Node* temp = head;
          int pos =1;
          while(temp!= nullptr){
              
              if( temp->data == value){
                 // cout << "position of the value " << pos <<" --> " << temp->data << endl;
                  return pos;
              }
              temp = temp->next;
              pos++;
          }
          return -1;
      }
      
      
      void detectLoop(){
          
          Node* slow = head;
          Node* fast = head;
          
          while ( fast != nullptr && fast->next != nullptr){
              slow = slow->next;
              fast = fast->next->next;
              
              if(slow ==fast){
                  cout <<"Loop is detected \n";
                  return;
              }
              else {
                  cout << " there is no Loop \n";
                  return;
              }
          }
      }
      
      void reverseLinkedList(){
          Node* prev=nullptr, *curr=head, *next=nullptr;
          
          while(curr != nullptr){
              next = curr->next;
              curr->next = prev;
              
              prev = curr;
              curr = next;
              
          }
          head = prev;
          
          
         
      }
};

int main(){
    SingleLinkedList sl;
    
    vector<int> v = {10,20,30,40,50};
    
    for(auto i = v.rbegin(); i != v.rend(); i++){
        sl.createNode(*i);
    }
    
    sl.display();
    sl.insertAtbegining(5);
    sl.display();
    sl.insertAtEnd(60);
    sl.display();
    sl.insertAtPosition(15,2);
    sl.display();
    sl.deleteNodeAtBegining();
    sl.display();
    sl.deleteNodeAtLast();
    sl.display();
    sl.deleteAtPosition(2);
    sl.display();
    
    int value =0;
   int pos = sl.findNode(value);
    
    if(pos !=-1 ){
        cout << "value is :" << value  << " position is :" << pos << endl;
    }else{
        cout << " element is not found \n";
    }

    sl.display();
    sl.detectLoop();
    
    sl.reverseLinkedList();
    
    cout <<"*********Reverse Linked List ********************" << endl;
    
    sl.display();
    
    
    
    
    
}