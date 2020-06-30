// class Solution {
// public:
//     string longestDupSubstring(string S) {
//         unordered_map<string, int> umap;
//         int l = S.length()-1;
//         int count = 2;
//         int flag = 0;
//         while(count <= S.length()){
//             umap.clear();
//             for(int i=0; i<count; i++){
//                 string temp = S.substr(i, l);
//                 if(umap.find(temp) == umap.end())
//                     umap.insert(make_pair(temp, 1));
//                 else{
//                     umap[temp] += 1;
//                     flag = 1;
//                     break;
//                 }

//             }
//             if(umap.size() < count || flag == 1){
//                 break;
//             }
//             count++;
//             l--;
//         }
//         string res = "";
//         for(auto i = umap.begin(); i!=umap.end(); i++){
//             if(i->second >= 2)
//                 res = i->first;
//         }
//         return res;
//     }
// };

class Solution {
private:
    unordered_map<long long, int> m;    /* hash table */
    
    #define P 611953    /* picked a large prime number of my choice */
    
    /* 
     * Using the ubiquitous Rabin-Karp algorithm. Here we take the
     * search string, h, and a window size, ws. There's no substring
     * specified. What we do here is keep moving the window and compute
     * a rolling hash. The window hash is kept in a hash table, m.
     * If a hash at a different location matches with that in the hash
     * table, then we know that there are two window sized substrings 
     * that generate the same hash and there's a probability that they
     * are the same. We then do a string compare to be sure.
     */
    int rk(char *h/*aystack*/, int hs, int ws) {
        long long hh = 0;   /* hash */
        long long z = 1;    /* power */
        m.clear();          /* clear map */
        
        /* Compute power for window size ws => 256 ^ (ws - 1) % P
         *
         * Thought: 256 is used because there are 256 letters in the ASCII 
         * set - we can think of it as a base-256 number system with 256 
         * digits. If we were using a string of hexadecimal numbers, then 
         * this number would be 16 and for decimal system, 10. The rolling
         * hash is based on the place value of the "digit" in the window.
         */
        for (int i = 0; i < ws - 1; i++) z = (z * 256) % P;
            /* Improvement: could do some memoization here by keeping track
             * of z in a global map e.g zmap[ws] = z */
        
        /* For first window, compute hash, hh */
        for (int i = 0; i < ws; i++) hh = (256 * hh + h[i]) % P; 
            /* Improvement: could do some memoization here by keeping track
             * of z in a global map e.g hmap[ws] = hh */
             
        /* Store in map */
        m[hh] = 0+1;  /* 1-based offset */
        
        /* Roll through the string ... */
        for (int i = 0; i < hs - ws; i++) {
            
            /* ... and keep computing hash for ns sized window */
            hh = (256 * (hh - h[i] * z) + h[i + ws]) % P; if (hh < 0) hh = hh + P;
            
            /* If a hash for the window (starting at i+1) does not exist, 
             * add it to the map. But if it exists then ... 
             */
            if (!m[hh]) m[hh] = i+1+1;/* 1-based */ else {
                
                /* ... let's compare the one in the map with the current window */
                int x, loff = m[hh] - 1/* back to 0-based */;
                
               /* The compare is necessary because the hash is not strong enough
                * and it does not guarantee zero collisions.
                */
                for (x = 0; x < ws; x++) { 
                    if ((i + 1 + x) >= hs) break; 
                    if (h[loff + x] != h[i + 1 + x]) break;
                }
                
                if (x == ws) return i + 1;
            }
        }
        
        /* 
         * We could not find two ws sized windows that generated 
         * the same hash and even if we did find two hashes, the
         * actual compare of those windows failed.
         */
        return -1;
    }

public:
    string longestDupSubstring(string S) {
        int r[2] = { -1, -1 }, ret, hs = S.size(), l = 0, h = hs - 1, m; 
        char *sp = (char *)S.c_str();
        
        /* Binary search for the highest window size */
        while (l <= h) { 
            m = l + (h - l) / 2;
            if ((ret = rk(sp, hs, m)) != -1) { r[0] = ret, r[1] = m; l = m + 1; } else h = m - 1;
        }
        
        /* If a result exists, return the substring */
        if (r[0] != -1) { sp[r[0] + r[1]] = 0; return &sp[r[0]]; }
        
        /* Bummer! */
        return "";
    }
};
