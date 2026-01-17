class Solution {
public:

    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int maxSide = 0;
        for(int i = 0; i < bottomLeft.size(); i++){
            int iblx = bottomLeft[i][0], ibly = bottomLeft[i][1], itrx = topRight[i][0], itry = topRight[i][1];
            for(int j = i + 1; j < bottomLeft.size(); j++){
                if(i != j){
                    int jblx = bottomLeft[j][0], jbly = bottomLeft[j][1], jtrx = topRight[j][0], jtry = topRight[j][1];
                    //take top right point of rectangle[i] and rectangle[j]
                    //as the points are top right corners, min(rec[i].x, rec[j].x) && min(rec[i].y, rec[j].y) will give the top right point of intersection(x, y)
                    int xtr = min(itrx, jtrx), ytr = min(itry, jtry);

                    //Consider bottom left point of rec[i] and rec[j]
                    //As the points are bottom left corners, max(rec[i].x, rec[j].x) && max(rec[i].y, rec[j].y) will give bottom left point of intersection(x, y)
                    int xbl = max(iblx, jblx), ybl = max(ibly, jbly);

                    //2 side length formed  
                    int side1 = xtr - xbl, side2 = ytr - ybl;
                    maxSide = max(maxSide, min(side1, side2));
                }
            }
        }

        long long res = 1LL * maxSide * maxSide;
        return res; 
    }
};
