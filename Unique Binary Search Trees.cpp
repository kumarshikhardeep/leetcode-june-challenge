class Solution {
public:
    int numTrees(int n) {
        if(n<=1)
            return 1;
        int t[n+1];
        t[0] = 1;
        t[1] = 1;
        for(int i=2; i<=n; i++){
            int temp = 0;
            for(int j=0; j<i; j++){
                temp += t[j] * t[i-j-1];
            }
            t[i] = temp;
        }
        return t[n];
    }
};
