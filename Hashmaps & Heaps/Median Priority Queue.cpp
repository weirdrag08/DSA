#include <bits/stdc++.h>
using namespace std;

//Maintaining 2 halves, left & right
// Maintain such that NO ELEMENT IN THE LEFT HALF > ANY ELEMENT IN RIGHT HALF, but this could be simplified and we can avoid comparing every pair
// We just need to maintain the condition: MAX_ELEMENT(left) <= MIN_ELEMENT(right)
// As we always require MAX_ELEMENT in left: so left half should be a MAX_HEAP
// As we always require MIN_ELEMENT in right: so right half should be a MIN_HEAP

// We also need to maintain that abs(LEFT_SIZE - RIGHT_SIZE) <= 1, If difference is getting larger, shift element from larger half to smaller half
// Then the median would be: 
//LEFT_SIZE == RIGHT_SIZE, top element of LEFT_HALF
//LEFT_SIZE != RIGHT_SIZE, top element of larger half

//Logically why this works is simple, MEDIAN IS MIDDLE ELEMENT IN THE SORTED ORDER
//PQ SORTS THE ELEMENT
/*
LEFT  (MAX_HEAP) - [8, 4, 2, 1] => top = 8
RIGHT (MIN_HEAP) - [12, 16, 19, 40, 45] => top = 12
RIGHT_SIZE > LEFT_SIZE, so ans = 12

[1, 2, 4, 8* | 12*, 16, 19, 40, 45]

As the left is MAX_HEAP it keeps top = 8, and the right is MIN_HEAP it keeps top = 12
IMPORTANT: So the TOPS of the respective heaps maintain the CLOSEST VALUE on EITHER SIDE of PARTITION, then the ELEMENTS LYING ON THE BOUNDARY / ELEMENTS LYING BETWEEN THE HALVES, is close to median WHEN both the heaps are BALANCED in nature (size difference <= 1)

One heap(left) is keeping track of elements below the median and the other heap(right) is keeping track of elements above the median.

TOP of left half represents the CLOSEST VALUE <= CURRENT MEDIAN
TOP of right half represents the CLOSEST VALUE >= CURRENT MEDIAN

*/

class PQ{
    public:
    //MAX_HEAP
    priority_queue<int> left;
    //MIN_HEAP
    priority_queue<int, vector<int>, greater<int> > right;
    
    PQ(){}
    
    void Add(int element){
        //Add element on the right
        if(right.size() == 0 || element > right.top()){
            //If size of the heaps are same, No shifting is required.
            if(left.size() == right.size()){
                right.push(element);
            }
            //shift the Min element of right to left, then add current element to right
            else{
                if(right.size() > 0){
                 left.push(right.top());
                 right.pop();
                }
                right.push(element);
            }
        }
        //Add element on the left
        else{
            if(left.size() == right.size()){
                left.push(element);
            }            
            else{
                if(left.size() > 0){
                    right.push(left.top());
                    left.pop();
                }
                left.push(element);
            }
        }
    }
    
    //should remove median value and print the median as well
    int Remove(){
        int median = -1;
        if(left.size() == 0 && right.size() == 0){
            cout << "Underflow" << " ";
            return median;
        }
        //Median lies on the top of left half, if size are equal OR left size > right size
        if(left.size() >= right.size()){
            median = left.top();
            left.pop();
        }
        //Otherwise median is the top value of the larger half
        else{
            median = right.top();
            right.pop();
        }
        return median;
    }
    
    //should return the value of median
    int Peek(){
        int median = -1;
        if(left.size() == 0 && right.size() == 0){
            cout << "Underflow" << " ";
            return median;
        }
        if(left.size() >= right.size()){
            median = left.top();
        } 
        else{
            median = right.top();
        }
        return median;
    }
    
};

int main() {
	// your code goes here
	PQ pq;
	string command;
    while(cin >> command){
        if(command == "add"){
            int element;
            cin >> element;
            pq.Add(element);
        }
        else if(command == "remove"){
            cout << pq.Remove() << '\n';
        }
        else{
            cout << pq.Peek() << '\n';
        }
    }
}
