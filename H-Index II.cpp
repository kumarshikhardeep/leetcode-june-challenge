class Solution {
public:
    int hIndex(vector<int>& citations) {
        int tot = citations.size();
        for(int i=0; i<citations.size(); i++){
            if(citations[i] >= tot)
                return tot;
            tot--;
        }
        return tot;
    }
};
