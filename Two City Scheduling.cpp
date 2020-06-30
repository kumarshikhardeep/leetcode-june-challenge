class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]-a[1] < b[0]-b[1])
            return true;
        return false;
       
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), comp);
        
        int n = costs.size();
        int tot = 0;
        for(int i=0; i<n/2; i++){
            tot += costs[i][0] + costs[i+(n/2)][1];
        }
        return tot;
    }
};
