// Implementation of Stack using Array.
# include <bits/stdc++.h>
using namespace std;
# define max 50
int arr[max];    // let the size of stack be 50 max
int idx;   // it is pointing to the current index of the array

void Stack(){
    idx = -1;
}

// 1. Push operation
void push(int val){
    if( idx<max )   // Check the condition of stack overflow
    {
        idx++;
        arr[idx] = val;
    }else{
        cout << "Stack Overflow!!" << endl;
    }
}

// 2. Pop operation
int pop(){
    if( idx<0)  // check the condition of stack underflow
    {
        cout << "Stack Underflow i.e stack is empty there is no element to pop" << endl ;
        return -1;
    }else{
        return arr[idx--];
    }
}

// 3. Peek( TOP ) operation
int top(){
    if( idx<0)  // check the condition of stack underflow
    {
        cout << "Stack Underflow i.e stack is empty" << endl ;
        return -1;
    }else{
        return arr[idx];
    }
}

// 4. empty
bool empty(){
    if(idx<0)
        return true;
    else    
        return false;
}

// 5. size
int size(){
    return idx+1;
}

int main(){
   Stack();

    for(int i=0; i<6; i++, idx++){
        cin>> arr[i];
    }
    cout << pop() << endl;

    push(53);
    cout << pop() << endl;

        cout << size() << endl;
            cout << top() << endl;
    cout << empty() << endl;


}
