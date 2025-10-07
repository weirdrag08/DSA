#include <bits/stdc++.h>
using namespace std;

//Assumption - itinerary cannot be cyclic & there is atmost 1 ticket from each city
//No cycle guarantees that hashmap will end eventually and not get stuck in parent child loop
//Only 1 ticket from each city, guarantees that recursion is not required, as we can only go to 1 child from a parent(NOT MULTIPLE PATHS)

vector<string> getItinerary(vector<vector<string> > &tickets){
    int n = tickets.size();
    unordered_map<string, bool> cities;
    unordered_map<string, string> frq;
    for(int i = 0; i < n; i++){
        //{key, value}: whatever value appears, they can't be starting point and will act as intermediates, as they were reachable from key
        string source = tickets[i][0], destination = tickets[i][1];
        frq[source] = destination;
        cities[destination] = false;
        if(cities.count(source) == 0){
            cities[source] = true;
        }
    }

    string startCity = "";
    for(auto city : cities){
        if(city.second == true){
            startCity = city.first;
        }
    }
    
    vector<string> res;
    
    res.push_back(startCity);
    for(auto it = frq.find(startCity); it != frq.end();){
        res.push_back(it-> second);
        it = frq.find(it-> second);
    }    
    
    return res;
}

int main() {
	// your code goes here
    int n;
    cin >> n;
    vector<vector<string> > tickets(n, vector<string>(2, ""));
    for(int i = 0; i < n; i++){
        cin >> tickets[i][0] >> tickets[i][1];
    }
    vector<string> itinerary = getItinerary(tickets);
    for(string s : itinerary){
        cout << s << " ";
    }
}
