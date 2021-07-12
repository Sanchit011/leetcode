class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
        vector<vector<pair<int,int>>> adj(n);
//here red color is represented with 1 and blue with 0
//we create a directed grpah using red edges along with color    
        for(int i=0;i<r.size();i++){
            adj[r[i][0]].push_back({r[i][1],1});
        }
//add blue edges as well to adj graph along with color
        for(int i=0;i<b.size();i++){
            adj[b[i][0]].push_back({b[i][1],0});
        }
//we initilaize distance vector with INT_MAX value and then we will try to find shorter path
//using bfs, we use bfs bcoz grpah is unweighted 
        vector<int> dis(n,INT_MAX);
        
        queue<pair<int,int>> q; //create a queue to perform bfs
 //push the starting vertex 0 with no color bcoz 0 is connected to itself no color required
        q.push({0,-1});
                        
        dis[0]=0; //distance of vertex to itself is always zero
        int cnt=1;  //it will keep track of length of path traversed til now
//vis matrix will keep track of visited nodes along with color like if there're nodes with 
// two parallel path with blue and red color then in that case we can traverse again if same
//path with diff. color is there
       int vis[n][n][2];
        memset(vis,0,sizeof(vis));//initially all paths is marked unvisited
        
  //Now we perform BFS     
        while(!q.empty()){
            int sz = q.size();//get size of current element in queue & process them 1-by-1
            
            for(int i=0;i<sz;i++){
                auto node = q.front(); //get the first vertex at front of queue
                q.pop();   //remove the first one as it is processed
      //Now we try to improve the distance for all vertices connected to popped node vertex         
                for(auto x : adj[node.first]){
                    int to = x.first;  //vertex to which node vertex is connected
                    int color = x.second;  //color of path
 //Now if the current path with specific color hasn't been visited and the last path color 
//is not same as current, bcoz we want alternating path, then we can move along this path 
                       if(vis[node.first][to][color]==0 && color!=node.second){
                         
                            dis[to]= min(dis[to],cnt);//find shortest path 
                            q.push({to,color});  //push this vetrx to be processed further
                           vis[node.first][to][color]=1; //mark current path with specific color as visited
                           
                        }
                    
                }
            }
            cnt++; //increase path length traversed till now by 1
        }
//Now the vertex that still remain to initialized value i.e INT_MAX can't be reached so set it's distance -1 
        for(int i=0;i<dis.size();i++){
            if(dis[i]==INT_MAX)
                dis[i]=-1;
           
        }
      //  return the shortes path answer vector
        return dis;
    }
    
};