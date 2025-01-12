class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        queue<pair<pair<int,int>,int>>q;
        int cnt=0;
        //vector<vector<int>>vis;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }else{
                vis[i][j]=0;
                }
                if(grid[i][j]==1)cnt++;
            }
        }
        int tm=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int ans=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 and nrow<n and ncol>=0  and ncol<m and vis[nrow][ncol]!=2 and grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    ans++;
                }
            }
        }
         for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)
                    if(vis[i][j]!=2 and grid[i][j]==1)return -1;
            }
        //if(cnt!=ans)return -1;
        return tm;
    }
};