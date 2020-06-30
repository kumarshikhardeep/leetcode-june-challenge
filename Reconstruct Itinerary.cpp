class Solution {
public:
    vector <string> ret;
    map < string, multiset <string> > graph;
    
    void visit(string airport){
          while(graph[airport].size()){
             string x = *(graph[airport].begin());
             graph[airport].erase(graph[airport].begin());
             visit(x);
          }
          ret.push_back(airport);
       }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {

       
          for(int i = 0; i < tickets.size(); i++){
             string u = tickets[i][0];
             string v = tickets[i][1];
             graph[u].insert(v);
          }
          visit("JFK");
          reverse(ret.begin(), ret.end());
          return ret;
       }
       
       
    
};
