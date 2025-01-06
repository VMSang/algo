class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            long long cal = 0;
            for(int j = 0; j < n; j++){
                if (i != j && boxes[j] >= '1'){
                    cal += abs(j - i);
                }
            }
            ans[i] =  cal;
        }
        return ans;
    }
};