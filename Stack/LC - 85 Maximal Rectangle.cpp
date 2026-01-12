class Solution {
public:
    //For every element in a row, calculate the first smallest on the left
    vector<int> getNSL(int i, vector<vector<int> > &matrix){
        int m = matrix[0].size();
        stack<int> st;
        vector<int> nsl(m);
        for(int j = 0; j < m; j++){
            int element = matrix[i][j];
            while(!st.empty() && matrix[i][st.top()] >= element){
                st.pop();
            }
            //No element on left is smaller than current element
            if(st.empty()){
                nsl[j] = -1;
            }
            //The top element < current element, i.e. first smallest on the left 
            else{
                nsl[j] = st.top();
            }
            //push the current element idx
            st.push(j);
        }
        return nsl;
    }

    //For every element in a row, calculate the first smallest on the right
    vector<int> getNSR(int i, vector<vector<int> > &matrix){
        int m = matrix[0].size();
        stack<int> st;
        vector<int> nsr(m);

        for(int j = m - 1; j >= 0; j--){
            int element = matrix[i][j];
            while(!st.empty() && matrix[i][st.top()] >= element){
                st.pop();
            }
            //If stack is empty, there is no first smallest element on right, otherwise the top element is the first smallest
            nsr[j] = st.empty() ? m : st.top();
            st.push(j);
        }
        return nsr;
    }

    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();

        //Convert the matrix to row wise histogram
        vector<vector<int> > matrix(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                matrix[i][j] = mat[i][j] == '1' ? 1 : 0;
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                //If for ith row, a column value = 0, there is no bar present/bar height = 0
                if(matrix[i][j] == 0){
                    matrix[i][j] = 0;
                }
                else{
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        //Calculate NSL & NSR for each row like we do for Largest Area Histogram
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            //ith row
            vector<int> nsl = getNSL(i, matrix);
            vector<int> nsr = getNSR(i, matrix);

            //For each element 'j' on the ith row with height[j] = matrix[i][j], and width = nsr[j] - nsl[j] - 1;
            for(int j = 0; j < m; j++){
                //Area = h * w
                maxArea = max(maxArea, matrix[i][j] * (nsr[j] - nsl[j] - 1));
            }
        }
        return maxArea;
    }
};
