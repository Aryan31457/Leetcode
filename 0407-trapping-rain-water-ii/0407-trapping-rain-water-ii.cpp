class Solution {
public:
   vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
   
   bool isValid(int row, int col, int rows, int cols) {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    int trapRainWater(vector<vector<int>>& height) {

        int ans=0;

      
        int rows=height.size(),cols=height[0].size();

        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;

       for(int i=0;i<rows;i++){
        q.push({height[i][0],i,0});
        q.push({height[i][cols-1],i,cols-1});
        visited[i][0]=true;
        visited[i][cols-1]=true;

        }
        for(int j=0;j<cols;j++){
        q.push({height[0][j],0,j});
        q.push({height[rows-1][j],rows-1,j});
        visited[rows-1][j]=true;
        visited[0][j]=true;
        }

        int level=0;
        while(!q.empty()){
            auto [high, row, col] = q.top();
            q.pop();
            level=max(level,high);

            for (int d = 0; d < 4; d++) {
                int newRow = row + dirs[d][0];
                int newCol = col + dirs[d][1];


                if (isValid(newRow, newCol, rows, cols) && !visited[newRow][newCol]) {
                visited[newRow][newCol]=true;
                q.push({max(height[row][col],height[newRow][newCol]),newRow,newCol});
                if(height[newRow][newCol]<level){
                ans+=level-height[newRow][newCol];
                }
                }
            }
        }
        return ans;
    }
};