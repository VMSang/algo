class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int cnt = 0;
        for(int i = 0; i < derived.size(); i++){
            if(derived[i]) cnt++;
        }
        return cnt%2 == 0;
    }
};