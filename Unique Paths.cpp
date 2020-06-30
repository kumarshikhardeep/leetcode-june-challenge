
class Solution {
public:
    
    long long int fact(int x, int y){
        long long int r = 1;
        while(y--){
            r *= x;
            x--;
        }
        return r;
    }
    
    long long int fact2(int x){
        long long int r = 1;
        while(x>=2){
            r *= x;
            x--;
        }
        return r;
    }
    
    int uniquePaths(int m, int n) {
        // return 0;
        int rows = m-1;
        int cols = n-1;
        long long int u = fact(rows+cols, min(rows,cols));
        long long int w = fact2(min(rows,cols));
        cout<<u<<" "<<w;
        long long int res = (u / w) ;
        return res;
    }
};
