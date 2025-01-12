class Solution {
public:
    bool canConstruct(string s, int k) {
        // base case
        if(s.size() < k) return false;
        if(s.size() == k) return true;

        map<char, int> frq;
        for(char c : s){
            frq[c]++;
        }  
        int cntodd = 0;
        for(auto [x, y] : frq){
            if(y%2 == 1) cntodd++;
        }

        if(k >= cntodd) return true;
        else return false;
    }
};



/*
so luong palindrome toi da = so luong ki tu trong s (duoc phep trung)
so luong palindrome toi thieu = so luong ki tu le

*/