//firstLargestElement Programm

#include <iostream>
#include<climits>

using namespace std;


int firstLargestElement(int arr[],int n){
    
    int first = INT_MIN;
    
    // if(n ==0){
    //     cout <<" \n NO Elements \n" ; 
    //   return 1; 
     
        
    // }
    
    for (int i=0; i<n; i++){

        
        if(arr[i]> first ){
            first =arr[i];
        }
    }
    return first;
}

int main(){
    
    int arr[] = {2,4,5,1,6,7,3,9};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    
    cout <<"first largest element " <<firstLargestElement(arr, 0);
}



//SecondLargestElement Programm

#include <iostream>
#include<climits>

using namespace std;


int SecondLargestElement(int arr[],int n){
    
    int first = INT_MIN;
    int second =INT_MIN;
    // if(n ==0){
    //     cout <<" \n NO Elements \n" ; 
    //   return 1; 
     
        
    // }
    
    for (int i=0; i<n; i++){

        
        if(arr[i]> first ){
            second =first;
            first =arr[i];
            
        }
        else if(arr[i] >second){
            second = arr[i];
        }
    }
    return second;
}

int main(){
    
    int arr[] = {2,4,5,1,6,7,3,9};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    
    cout <<"Second largest element " <<SecondLargestElement(arr, n);
}



//ThirdLargestElement Programm

#include <iostream>
#include<climits>

using namespace std;


int ThirdLargestElement(int arr[],int n){
    
    int first = INT_MIN;
    int second =INT_MIN;
    int third = INT_MIN;
    // if(n ==0){
    //     cout <<" \n NO Elements \n" ; 
    //   return 1; 
     
        
    // }
    
    for (int i=0; i<n; i++){

        
        if(arr[i]> first ){
            third =second;
            second =first;
            first =arr[i];
            
        }
        else if(arr[i] >second){
            third =second;
            second =arr[i];
            
        }
        else if( arr[i]> third){
            third =arr[i];
        }
    }
    return third;
}

int main(){
    
    int arr[] = {2,4,5,1,6,7,3,9};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    
    cout <<"Third largest element " <<ThirdLargestElement(arr, n);
}

//Reverse of an array 


#include <iostream>

using namespace std;

int main(){
    
    int arr[] = {10,20,30,40,50};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout <<" n vlaue " << n << endl ;
     cout << "[ ";
    for(int i= n-1; i>=0; i--){
        cout <<  arr[i]  <<", " ;
    }
    cout << "]";
}


//Sort the array 

#include <iostream>

using namespace std;

int main(){
    
    int arr[] = {1,4,5,3,2};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // cout <<" n vlaue " << n << endl ;
    //  cout << "[ ";
    // for(int i= n-1; i>=0; i--){
    //     cout <<  arr[i]  <<", " ;
    // }
    // cout << "]";
    
    for( int i =0; i <n ; i++){
        for( int j =i+1; j <n; j ++){
            if (arr[i] > arr[j]){
               int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i =0 ; i <n ; i++){
        cout << arr[i] ;
    }
    
}


//Move Zeros to END 

//Move all Zeros to End;

#include <iostream>

using namespace std;


void moveZeores(int arr[], int n){
    
    
    int j =0;
    
    for (int i =0; i < n; i++){
        if(arr[i] != 0){
            arr[j++] = arr[i];
        }
    }
    while( j< n){
        arr[j++] =0;
    }
}


int main(){
    
    int arr[]= {1,0,3,4,5,0,6,7};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    moveZeores(arr, n);
    
    
    for(int i=0; i < n; i ++){
        cout << arr[i];
    }
}

//Removed the Duplicate Elements into Sorted Array 
#include <iostream>
using namespace std;


int main(){
    
    
    int arr[] = { 12,3,4,4,5,1,7,7,8,3};
    
    int n =sizeof(arr)/sizeof(arr[0]);
        
        for( int i =0; i<n ; i ++){
            for(int j= i+1; j <n; j ++){
                
                if(arr[i] > arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    for ( int i =0 ; i <n ; i ++){
        cout<< " " << arr[i] ;
    }
    
    cout<<"\n--------------------------------------------------------------------------------\n";
    int x=0;
    
   for (int i =0; i<n ; i++){
       if (arr[i] !=arr[i+1]){
           arr[x]= arr[i];
           x++;
       }
   }
   arr[x] = arr[n-1];
   x++;
   cout<<" After removed Duplicates \n";
    for ( int i =0 ; i <n ; i ++){
        
       cout << " " << arr[i] ;
    }
}


//Left Rotate by one 

#include <iostream>

using namespace std;


void leftrotateArrayByOne(int arr[], int n){
    int j=0;
    
    int first =arr[0];
    int second = arr[1];
    for(int i =2; i<n; i ++ ){
        arr[j++] =arr[i];        
    }
    
    arr[n-2] =first;
    arr[n-1] = second;
}


int main(){
    
    int arr[] ={1,2,3,4,5} ;
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    leftrotateArrayByOne(arr, n);
    
    
    for( int i =0; i<n; i++){
        cout<< arr[i] ;
    }
}

//Binary Search tree

#include <iostream>
using namespace std;

void sortArray(int arr[], int n){
    
    for( int i =0; i <n ; i++){
        for (int j =i+1; j<n;j ++){
            if(arr[i] >arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
}
int binarySearch(int arr[], int n, int target){
    
    int left =0;
    int right = n-1;
    
    while( left <= right){
        
    int mid = left + (right -left)/2;
    if (arr[mid] ==target){
      return mid;
    }
    else if(arr[mid] < target){
        left= mid+1;
    }
    else
    right = mid-1;
    }
    return -1;

}
int main(){
    
    
    int arr[] ={ 12,4,5,3,2,11,10,1};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    sortArray(arr, n);
    
    for( int i =0 ; i<n; i ++){
        cout<<" "<<arr[i];
    }
    
    cout <<"\n-------------------array is Sorted -------------------------------" <<endl;
    
    int target =11;
    int result = binarySearch(arr, n, target);
    
     if( result !=-1){
         cout << "Elememt is found at Index : " <<result <<endl; 
         
     }
     else {
         cout <<"Elememtn is not found" <<endl;
     }
    // for( int i =0 ; i<n; i ++){
    //     cout<<" "<<arr[i];
    // }
    
}


//Two SUm 
#include <iostream>

using namespace std;

void twoSum( int arr[], int n, int target){
    
    for(int i =0; i < n-1; i++ ){
        for(int j = i+1; j <n ; j++){
            if (arr[i]+arr[j]==target){
                cout<< "index of the target is " << i << " " <<j <<endl;
            }
        }
    }
    
}
int main(){
    
    int arr[] ={1,4,5,7,7,9};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int target =9;
    
    twoSum(arr,n, target);
}


//Boyer Moore Vooting alogorithm-- find the Majority Elememt in an Array 

#include <iostream>

using namespace std;

int Majorityelement(int arr[], int n){
    
    int candiates =0;
    int count =0;
    
    
    for (int i =0; i<n ; i ++){
        
        if (count == 0){
            candiates =arr[i];
        }
        if(arr[i]== candiates){
            count ++;
        }
        else 
        count --;
    }
    return candiates;
}

int main(){
    int arr[] = {1,2,2,2,1,2,3};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int result =Majorityelement(arr, n);
    
    cout<<" Majorityelement in an array" <<result << endl;
}



// Merged the two sorted arrays 

#include <iostream>

using  namespace std;

int main(){
    
    int arr1[]= {1,3,5,7,9};
    int arr2[]= {2,4,6,8,10};
    
    
    int n1 =sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    
    int i =0;
    int j=0;
    int k=0;
    
    
    int result[n1+n2];
    
    
    while( i <n1 && j < n2){
        if(arr1[i] < arr2[j]){
            result[k] =arr1[i];
            i++;
        }
        else  {
        result[k] = arr2[j];
        j++;
        }
        
        k++;
    }
    
    while (i < n1){
        result[k] = arr1[i];
        i ++;
        k++;
    }
    while (j< n2){
        result[k] = arr2[j];
        j ++;
        k++;
    }
    
    for(int i =0; i< n1+n2 ; i ++){
        cout <<result[i];
    }
}


//Valid Paranthesis 

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else {
            if (st.empty())
                return false;

            char top = st.top();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }

            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string s = "{[()]}";

    if (isValid(s))
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}


//Largest Number 
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string> arr;

        for (int num : nums) {
            arr.push_back(to_string(num));
        }

        sort(arr.begin(), arr.end(), [](string a, string b) {
            return a + b > b + a;
        });

        // If the largest number is "0"
        if (arr[0] == "0")
            return "0";

        string ans = "";

        for (string s : arr) {
            ans += s;
        }

        return ans;
    }
};


//String to Integer(atoi)
class Solution {
public:
    int myAtoi(string s) {


        int i =0;
        int n = s.length();


        int sign =1;

        while (i <n && s[i] == ' '){
        //if(s[i]== ' ')
        //continue;
        i ++;
        }

        if( i< n &&(s[i] =='-' || s[i]=='+')){
            if(s[i]=='-'){
                sign =-1;
            }
            i++;
        }
       
        long long num =0;
        while(i < n && isdigit(s[i])){

            num =num *10 +(s[i]-'0');
          
          if(num* sign > INT_MAX){
            return INT_MAX;
          }
          if(num* sign < INT_MIN){
            return INT_MIN;
          }


            i++ ;
        }
        return num *sign;
    }
};


//House Robber 
#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums) {

    int prev2 = 0;
    int prev1 = 0;

    for (int money : nums) {

        int rob = prev2 + money;
        int notRob = prev1;

        int current;

        if (rob > notRob)
            current = rob;
        else
            current = notRob;

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main() {

    vector<int> nums = {2, 7, 9, 3, 1};

    int result = rob(nums);

    cout << "Maximum money: " << result << endl;

    return 0;
}


//Roman to Integer
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        int total = 0;

        for (int i = 0; i < s.length(); i++) {

            int current = 0;
            int next = 0;

            if (s[i] == 'I')
                current = 1;
            else if (s[i] == 'V')
                current = 5;
            else if (s[i] == 'X')
                current = 10;
            else if (s[i] == 'L')
                current = 50;
            else if (s[i] == 'C')
                current = 100;
            else if (s[i] == 'D')
                current = 500;
            else if (s[i] == 'M')
                current = 1000;

            if (i + 1 < s.length()) {

                if (s[i + 1] == 'I')
                    next = 1;
                else if (s[i + 1] == 'V')
                    next = 5;
                else if (s[i + 1] == 'X')
                    next = 10;
                else if (s[i + 1] == 'L')
                    next = 50;
                else if (s[i + 1] == 'C')
                    next = 100;
                else if (s[i + 1] == 'D')
                    next = 500;
                else if (s[i + 1] == 'M')
                    next = 1000;
            }

            if (current < next)
                total -= current;
            else
                total += current;
        }

        return total;
    }
};

int main() {

    Solution obj;

    string s = "MCMXCIV";

    cout << obj.romanToInt(s) << endl;

    return 0;
}


//Operator Overloading by cpp Nuts 


#include <iostream>
using namespace std;

class Point{
    
    int x, y;
    
    
    public: 
    
    Point(int x=0, int y =0): x{x},y{y} {}
    
    Point operator + (const Point& rhs){
       Point p;
       
       p.x = x+rhs.x;
       p.y = y+rhs.y;
       
       return p;
    }
    
     Point operator - (const Point& rhs){
       Point p;
       
       p.x = x-rhs.x;
       p.y = y-rhs.y;
       
       return p;
    }
    
    Point add (const Point& rhs){
        
          Point p;
       
       p.x = x+rhs.x;
       p.y = y+rhs.y;
       
       return p;
        
    }
    void print(){
        cout << "x value is :" <<x <<" y value is :" <<y <<endl;
    }
};


int main(){
    
    Point p1(1,2), p2(3,4);
    
    Point p3 =p1+p2;
    Point p4 =p1-p2;
    Point p5 =p1.add(p2);
    
    p3.print();
    p4.print();
    p5.print();
    
}



//Reverse Word of the String


#include <iostream>

using namespace std;


int main(){
    
    
    string s = " the sky is blue";
    string s1 ="anand";
    string result="";
    
    int count =0;
    int j =0;
    while (s1[j] !='\0'){
      count ++;
      j++;
    }
    cout << "count of the String : "<< count << endl;
    
    int i = s.length()-1;
    
    
    cout <<" length of the I value is :" << i << endl;
    
    while ( i >=0){
        
        
        while( i>=0 && s[i]==' '){
            i--;
        }
        
         if (i <0){
             break;
         }
        // int end =i;
        // while(i>=0 && s[i]!=' '){
        //     i--;
        // }
        
        // if(!result.empty()){
        //     result +=" ";
        // }
        // result += s.substr(i+1, end-1);
        
        
        int end = i;

while (i >= 0 && s[i] != ' ') {
    i--;
}

if (!result.empty()) {
    result += " ";
}

result += s.substr(i + 1, end - i);
    }
    cout << "reverse of the word of the String " << result <<endl;
    
}



//String Compression
#include <iostream>

using namespace std;



// void compress(string s){
    
//     string result;
    
//     int count =1;
    
    
//     int n = s.length();
    
    
//     for(int i =1; i <=n; i ++){
        
//         if(i < n && s[i]== s[i-1]){
//             count ++;
            
//         }
//         else{
//         result =s[i-1];
//         result = to_string(count);
//         count =1;
//         }
//     }
    
    
//     cout << "String compress of the string" << result << endl;
// }

void compress(string s) {
    string result;
    int count = 1;

    int n = s.length();

    for (int i = 1; i <= n; i++) {

        if (i < n && s[i] == s[i - 1]) {
            count++;
        }
        else {
            result += s[i - 1];
            result += to_string(count);
            count = 1;
        }
    }

    cout << "String compress of the string: " << result << endl;
}

int main(){
    
    
    string s ;
    
    cin >> s ;
    
    
    compress (s);
}
