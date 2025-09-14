#include <bits/stdc++.h>
using namespace std;

// bool evaluate(bool operand1, bool operand2, char op){
//     bool ans;
//     if(op == '|'){
//         ans = operand1 | operand2;
//     }
//     else if(op == '&'){
//         ans = operand1 & operand2;
//     }
//     else{
//         ans = operand1 ^ operand2;
//     }
//     return ans;
// }

pair<int, int> booleanParenthesization(int i, int j, string &s, vector<vector<pair<int, int> > > &memo){
    if(i > j){
        return make_pair(0, 0);
    }
    //single character, returns whatever value they have
    if(i == j){
        return s[i] == 'T' ? make_pair(1, 0) : make_pair(0, 1);
    }
    // if(j - i == 2){
    //     char op = s[i + 1];
    //     bool operand1 = s[i] == 'T' ? true : false, operand2 = s[j] == 'T' ? true : false;
    //     return evaluate(operand1, operand2, op) == true ? make_pair(1, 0) : make_pair(0, 1);
    // }
    if(memo[i][j] != make_pair(-1, -1)){
        return memo[i][j];
    }
    pair<int, int> count = {0, 0};
    for(int k = i + 1; k < j; k+=2){
        auto leftWays = booleanParenthesization(i, k - 1, s, memo);
        auto rightWays = booleanParenthesization(k + 1, j, s, memo);
        
            char op = s[k];
            
            if(op == '^'){
                //for true count
                count.first += leftWays.first * rightWays.second + leftWays.second * rightWays.first;
                //for false count
                count.second += leftWays.first * rightWays.first + leftWays.second * rightWays.second;
            }
            
            else if(op == '&'){
                //for true count
                count.first += leftWays.first * rightWays.first;
                //false case
                count.second += leftWays.first * rightWays.second + leftWays.second * rightWays.first + leftWays.second * rightWays.second;
            }
            
            else{
                //true case
                count.first += leftWays.first * rightWays.first + leftWays.first * rightWays.second + leftWays.second * rightWays.first;
                //false case
                count.second += leftWays.second * rightWays.second;
            }
    }
    return memo[i][j] = count;
}

int countWays(string s){
    vector<vector<pair<int, int> > > memo(s.size(), vector<pair<int, int> >(s.size(), make_pair(-1, -1)));
    auto count = booleanParenthesization(0, s.size() - 1, s, memo);
    //only return true cases
    return count.first;
}

int main() {
	// your code goes here
    string s;
    cin >> s;
    cout << countWays(s) << '\n';
}
