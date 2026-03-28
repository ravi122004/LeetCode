class Solution {
public:
    int minCost(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        queue<array<int,3>>q;
        vector<vector<vector<bool>>>vis(m,vector<vector<bool>>(n,vector<bool>(1024,false)));
        q.push({0,0,g[0][0]});
        vis[0][0][g[0][0]]=1;
        int ans=INT_MAX;
        while(q.size()){
            auto[i,j,x]=q.front(); q.pop();
            if(i==m-1 && j==n-1)ans=min(ans,x);
            if(i+1<m){
                int nx =x^g[i+1][j];
                if(!vis[i+1][j][nx]){
                    vis[i+1][j][nx]=1, q.push({i+1,j,nx});
                }
            }
            if(j+1<n){
                int nx=x^ g[i][j+1];
                if(!vis[i][j+1][nx]){
                    vis[i][j+1][nx]=1,q.push({i,j+1,nx});
                }
            }
        }
        return ans;
        
    }
};