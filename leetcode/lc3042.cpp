class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(isPrefixAndSuffix(words[i], words[j])) cnt++;
            }
        }
        return cnt;
    }

    bool isPrefixAndSuffix(string str1, string str2){
        if(str2.size() < str1.size()) return false;

        for(int i = 0; i < str1.size(); i++){
            if(str1[i] != str2[i]) return false;
        }
        string lastStr2 = str2.substr(str2.size() - str1.size(), str1.size());
        if(str1 == lastStr2) return true;
        else return false; 
    }
};