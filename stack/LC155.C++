/*
        PROBLEM STATEMENT:-  155. Min Stack
            Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
            Implement the MinStack class:
                MinStack() initializes the stack object.
                void push(int value) pushes the element value onto the stack.
                void pop() removes the element on the top of the stack.
                int top() gets the top element of the stack.
                int getMin() retrieves the minimum element in the stack.
                You must implement a solution with O(1) time complexity for each function.

        

        Example 1:
            Input
                ["MinStack","push","push","push","getMin","pop","top","getMin"]
                [[],[-2],[0],[-3],[],[],[],[]]
            Output
                 [null,null,null,null,-3,null,0,-2]
            Explanation
                MinStack minStack = new MinStack();
                minStack.push(-2);
                minStack.push(0);
                minStack.push(-3);
                minStack.getMin(); // return -3
                minStack.pop();
                minStack.top();    // return 0
                minStack.getMin(); // return -2
        
        Constraints:
            -231 <= val <= 231 - 1
            Methods pop, top and getMin operations will always be called on non-empty stacks.
            At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int val;
    int minValue;
    Node* next;

    Node(int data) {
        val = data;
        minValue = data;   // Initially, the minimum is the node's own value
        next = NULL;
    }
};

class MinStack {
    Node* head;
    int counter;

public:
    MinStack() {
        head = NULL;       // FIX 1: head points to nothing initially
        counter = 0;
    }

    void push(int value) {

        Node* temp = new Node(value);

        // FIX 2: Handle the first node separately
        if (head == NULL) {
            temp->minValue = value;
        }
        else {
            // FIX 3: Store minimum till this node
            temp->minValue = min(value, head->minValue);
        }

        temp->next = head;
        head = temp;
        counter++;
    }

    void pop() {

        if (head == NULL)
            return;

        Node* temp = head;
        head = head->next;
        delete temp;
        counter--;
    }

    int top() {

        if (head == NULL)
            return -1;

        return head->val;
    }

    int getMin() {

        if (head == NULL)
            return -1;

        return head->minValue;
    }
};