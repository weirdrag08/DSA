class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int> > right;

    MedianFinder() {
        
    }
    
    /*
    1) Maintain the 2 halves such that no elements in left half > any element in right half, i.e.
    MAX_ELEMENT(left) <= MIN_ELEMENT(right)
    2) Keep both the heaps balanced (abs(SIZE(left) - SIZE(right) <= 1))
    */
    void addNum(int num) {
        //Add element to left
        left.push(num);
        //Check if property didn't get violated
        if(right.size() > 0){
            //exchange TOP element
            if(left.top() > right.top()){
                int leftTop = left.top(), rightTop = right.top();
                left.pop();
                right.pop();
                left.push(rightTop);
                right.push(leftTop);
            }
        }
        //Check if resize required, Move left to right
        if(left.size() - right.size() > 1){
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        //Median when the heap size is same = Mid value of TOP of both heaps
        if(left.size() == right.size()){
            return (double) (left.top() + right.top()) / 2.0;
        }
        //Median will be top of left heap
        else{
            return (double) left.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
