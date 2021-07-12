class Solution {
public:
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> arr(n, vector<int> (n, 0));
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(i == j){arr[i][j] = 0;}
                else{
                    arr[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    arr[j][i] = arr[i][j];
                }
            }
        }
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, 0));
        vector<int> key(n, INT_MAX);
        key[0] = 0;
        int cost = 0;
        vector<bool> vis(n , false);
        while(!pq.empty()){
            int temp = pq.top().second;
            pq.pop();
            vis[temp] = true;
            for(int i = 0; i<n; i++){
                if(!vis[i]){
                    if(arr[temp][i] < key[i]){
                        key[i] = arr[temp][i];
                        pq.push(make_pair(key[i], i));
                    }
                }
            }
        }
        for(int i = 0; i<n; i++){
            cost += key[i];
        }
        return cost;
    }
};