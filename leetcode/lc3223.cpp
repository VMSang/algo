class Solution {
public:
    int minimumLength(string s) {
        if(s.size() < 3) return s.size();
        unordered_map<char, int> frq;
        for(char c : s){
            frq[c]++;
        }

        int init = s.size();
        for(auto [x,y] : frq){
            if(y & 1 == 1){
                init -= (y-1);
            } else {
                init -= (y-2);
            }

        }
        return init;
    }
};