class Solution {
private:
    vector<int> prefixSum;
    int size = 0;
public:

    Solution(vector<int>& w) {
        prefixSum.push_back(w[0]);
        for(int i=1; i<w.size(); i++){
            prefixSum.push_back(prefixSum[i-1] + w[i]);
        }
        size = w.size();
    }
    
    int pickIndex() {
        float num = (float) rand()/RAND_MAX;
        cout<<num<<" ";
        float prob = num*prefixSum[size-1];
        cout<<prob<<"  ";
        for(int i=0; i<=size; i++){
            if(prob < prefixSum[i])
                return i;
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
