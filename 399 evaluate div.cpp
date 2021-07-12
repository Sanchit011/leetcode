class Solution {
public:
    double findWeight(string src,string des,set<string>&vis, map<string,map<string,double>>& g)
    {
        if(g[src].find(des)!=g[src].end())return g[src][des];
        for(auto x:g[src])
        {
            if(vis.find(x.first)==vis.end())
            {
                vis.insert(x.first);
            
                double u=findWeight(x.first,des,vis,g);
                if(u)return u*x.second;
            }
        }
        return 0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        map<string,map<string,double>> g;
        int i=0;
        for(auto x:equations)
        {
            g[x[0]][x[1]]=values[i];
            g[x[1]][x[0]]=1/values[i];
            i++;
        }
       
        vector<double> ans(queries.size());
        i=0;
        for(auto x:queries)
        {
            set<string> vis;
            double d=findWeight(x[0],x[1],vis,g);
            ans[i]=d?d:-1;
            i++;
        }
        return ans;
       
    }
};