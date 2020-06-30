class RandomizedSet {
private:
    set<int> st;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(st.find(val) == st.end()){
            st.insert(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(st.find(val) != st.end()){
            st.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand()%st.size();
        auto i = st.begin();
        for(int k = 0; k < r; k++)
            i++;
        return *i;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
