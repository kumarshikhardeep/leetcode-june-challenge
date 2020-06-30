class Solution {
public:
    
    vector < vector < bool > > vist;
    int n, m, dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
    
    bool check(int x, int y){
        return (x >= 0 && x < n && y >= 0 && y < m && !vist[x][y]);
    }
    
    void propagate(vector < vector < char > >&mat, int x, int y){
        vist[x][y] = true;
        for (int i=0; i<4; i++){
            int a = x + dx[i], b = y + dy[i];
            if(check(a, b) && mat[x][y] == 'O'){
                propagate(mat, a, b);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return ;
        n = board.size();
        m = board[0].size();
        vist.assign(n, vector < bool >(m, false));
        for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				vist[i][j] = false;
        for (int i=0; i<m; i++){
            if(!vist[0][i])
                propagate(board, 0, i);
            if(!vist[n-1][i])
                propagate(board, n-1, i);
        }
        
        for (int i=0; i<n; i++){
            if(!vist[i][0])
                propagate(board, i, 0);
            if(!vist[i][m-1])
                propagate(board, i, m-1);
        }
        
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if(!vist[i][j]) board[i][j] = 'X';
            }   
        }
        
    }
};
