class Solution {
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(),n=image[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int org=image[sr][sc];
        visited[sr][sc]=1;
        while(!q.empty()){

                pair<int,int>front=q.front();
                int row=front.first,col=front.second;
                image[row][col]=color;
                q.pop();
                 for (auto [dx, dy] : directions) {
                    int newRow = row + dx;
                    int newCol = col + dy;

                    if (newRow >= 0 && newRow < m && newCol >= 0 &&
                        newCol < n && image[newRow][newCol] == org &&
                        visited[newRow][newCol] == -1) {
                        visited[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
                
        }
        return image;
    }
};