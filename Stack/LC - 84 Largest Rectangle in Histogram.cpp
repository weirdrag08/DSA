class Solution {
public:

    //next smallest on the left
    //stack.top() = NSL for heights[i]
    //stack.empty() = NSL doesn't exist for heights[i]
    vector<int> getNSL(vector<int> &heights){
        vector<int> nsl(heights.size(), 0);
        stack<int> st;
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            nsl[i] = st.empty() ? -1 : st.top();
            //push current element
            st.push(i);
        }
        return nsl;
    }

    vector<int> getNSR(vector<int> &heights){
        vector<int> nsr(heights.size(), 0);
        stack<int> st;

        for(int i = heights.size() - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            nsr[i] = st.empty() ? heights.size() : st.top();
            //push current element
            st.push(i);
        }
        return nsr;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nsl = getNSL(heights);
        vector<int> nsr = getNSR(heights);
        
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int width = nsr[i] - nsl[i] - 1, height = heights[i];
            maxArea = max(maxArea, width * height);
        }
        return maxArea;
    }
};
