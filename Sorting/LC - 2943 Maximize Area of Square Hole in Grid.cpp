class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        //Sort both the arrays, so that consecutive positioned bars are grouped together
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        //hBars.size() >= 1 && vBars.size() >= 1
        //So atleast 1 bar could be removed from each array
        //If both the arrays are atleast of 1 size, then by removing that single bar will create a square of side 2
        //Minimum answer = 1 bar removed from each = 2 * 2 = 4 
        /*
        ##Only consecutive removals matter as that would increase the side length of square
        For eg-
        [2, 4]
        if these two are removed, then a square of side = 2, will be formed at [1 - 3] and [3 - 5]
        [2, 4, 6]
        if these three are removed, then also a square of side = 2 will be formed at [1 - 3], [3 - 5], [5 - 7]
        [2, 4, 7]
        if these are removed, then square of side = 2 will be formed at [1 - 3], [3 - 5], [6 - 8]. square of side = 1, will be formed at [5, 6]
        
        ##So it doesn't matter how many are removed at random, what matters is how many can be removed consecutively. Consecutive removals increase the side length, and hence the area.
        */

        //What is the largest consecutive sequence of bars that could be removed here
        int removalsV = 1, maxRemovalsV = 1;
        for(int i = 0; i < vBars.size() - 1; i++){
            if(vBars[i + 1] - vBars[i] == 1){
                removalsV += 1;
            }
            else{
                removalsV = 1;
            }
            maxRemovalsV = max(maxRemovalsV, removalsV);
        }
        //Search what is the largest consecutive sequence of bars that could be removed here
        int removalsH = 1, maxRemovalsH = 1;
        for(int i = 0; i < hBars.size() - 1; i++){
            if(hBars[i + 1] - hBars[i] == 1){
                removalsH += 1;
            }
            else{
                removalsH = 1;
            }
            maxRemovalsH = max(maxRemovalsH, removalsH);
        }
        //So whatever is the min(VBarsRemovedMax, HBarsRemovedMax), i.e. #bars should be removed from each array
        /*
        //Side Length of square formed = (#bars removed + 1)
        [3] = 3 - 1 = 2
        [2, 3] = 4 - 1 = 3
        [2, 3, 4] = 5 - 1 = 4
        [2, 3, 4, 5] = 6 - 1 = 5
        */
        return (min(maxRemovalsH, maxRemovalsV) + 1) * (min(maxRemovalsH, maxRemovalsV) + 1);
    }
};
