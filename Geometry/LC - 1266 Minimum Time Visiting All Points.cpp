class Solution {
public:
/*
GREEDY APPROACH - Move diagonally as much as possible
Because we have to visit each point in ORDER, if we consider each pair of adjacent points as a segment, each segment is entirely independent. 
Our decisions within the current segment do not affect the decisions in other segments. 
Therefore, the optimal solution for this problem consists of the optimal solutions for each individual segment. 
To solve this problem, the first thing we need to determine is the optimal strategy for moving between adjacent points.
*/
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        for(int i = 0; i < points.size() - 1; i++){
            int x1 = points[i][0], y1 = points[i][1], x2 = points[i + 1][0], y2 = points[i + 1][1];

            //check relative distance between (x1, y1), (x2, y2)
            if(abs(x1 - y1) == abs(x2 - y2)){
                time += abs(x1 - x2);
            }
            else{
                //min distance between which pair: |x1 - x2| or |y1 - y2|
                int diagonalMove = 0;
                if(abs(x1 - x2) <= abs(y1 - y2)){
                    diagonalMove = abs(x1 - x2);
                    if(y1 < y2){
                        y1 += diagonalMove;
                    }
                    else{
                        y2 += diagonalMove;
                    }
                    time += diagonalMove + abs(y1 - y2);
                }
                else{
                    diagonalMove = abs(y1 - y2);
                    if(x1 < x2){
                        x1 += diagonalMove;
                    }
                    else{
                        x2 += diagonalMove;
                    }
                    time += diagonalMove + abs(x1 - x2);
                }
            }
        }
        return time;
    }
};
