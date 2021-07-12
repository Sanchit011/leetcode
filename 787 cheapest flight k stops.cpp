typedef tuple<int,int,int> ti;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int> >>adj(n);
        for(int i = 0; i<flights.size(); i++){
            adj[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
        }
        priority_queue <ti, vector<ti>, greater<ti> > pq;
        ti temp(0, src, 0); 
        pq.push(temp);
        vector<int> arr(n, INT_MAX);
        while(!pq.empty()){
            auto[cost, city, distance] = pq.top();
            pq.pop();
            if(city == dst){return cost;}
            if(distance > k){continue;}
            if(arr[city] != INT_MAX && arr[city] < distance){
                continue;
            }
            arr[city] = distance;
            for(auto neigh : adj[city]){
                ti x(cost + neigh.second, neigh.first, distance+1);
                pq.push(x);
            }
        }
        return -1;
    }
};