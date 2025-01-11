class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> s;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words.size(); j++){
                if(i != j && words[j].find(words[i]) != std::string::npos){
                    s.insert(words[i]);
                }
            }
        }
        vector<string> ans(s.begin(), s.end());
        return ans;
    }
};