#include<unordered_map>
int kDistinctChars(int k, string &str)
{
    // Write your code here
    unordered_map<int, int> frq;
    int res = 0;
    for(int i = 0, j = 0; i < str.size(); i++){
        //add element
        frq[str[i]] += 1;
        //IMPORTANT
        //If invalid, make it valid by reducing segment
        //reducing segment will always reduce the number of unique keys, never increase it
        //IT IS A MONOTONIC ACTION, shortening segment always reduces #distinct keys
        //Because it is monotonic, 2 pointer segment method will work
        //Move 'i' => INCREASES segment => INCREASES #distinct keys
        //Move 'j' => DECREASES segment => DECREASES #distinct keys
        //Both pointers are MONOTONIC in nature and INVERSE of each other, that's why 2 pointer segment method works here
        while(frq.size() > k){
            frq[str[j]] -= 1;
            if(frq[str[j]] == 0){
                frq.erase(str[j]);
            }
            j++;
        }
        //Segment is always valid, i.e. #distinct keys <= k, record answer
        res = max(res, i - j + 1);
    }
    return res;
}


