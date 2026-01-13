class Solution {
public:
    const double epsilon = 1e-5;

    double possibleY(double yAxis, vector<vector<int> > &squares){
        double areaUp = 0, areaDown = 0;
        for(int i = 0; i < squares.size(); i++){
            int x = squares[i][0], y = squares[i][1], l = squares[i][2];
            //Square above yAxis
            if(y >= yAxis){
                areaUp += 1.00000 * l * l;
            }
            else{
                // Square completely below yAxis
                if(y + l <= yAxis){
                    areaDown += 1.00000 * l * l;
                }
                //Square above and below
                else{
                    double lengthUp = (1.00000 * (y + l) - yAxis), lengthDown = 1.00000 * (yAxis - y);
                    areaUp += lengthUp * l;
                    areaDown += lengthDown * l;
                }
            }
        }
        //If BS is converging to 1 value irrespective to where it should, check if the value being returned is monotonic or not, is it a VALID PREDICATE or not, where BS can flip the direction based on it.
        return areaUp - areaDown;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double l = 0, r = 1e9, res = 1e9;
        while(r - l >= epsilon){
            double mid = (l + r) / 2;
            //Remember: Floating BS, what is acceptable as almost 0 
            if(possibleY(mid, squares) <= epsilon){
                res = mid;
                r = mid;
            }
            else{
                l = mid;
            }
        }
        return res;
    }
};
