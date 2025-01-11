class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for(char c : s){
            letters.insert(c);
        }
        int ans = 0;
        for(char c : letters){
            int i = -1, j = 0;
            //find start and end
            for(int k = 0; k < s.size(); k++){
                if(c == s[k]){
                    if(i == -1){
                        i = k;
                    }
                    j = k;
                }
            }
            // count between
            unordered_set<char> bt;
            for(int k = i + 1; k < j; k++){
                bt.insert(s[k]);
            }

            ans += bt.size();
        }
        return ans;
    }
};