class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        long long n = nums.size();
        vector<long long> pf(n + 1);
        pf[0] = 0;
        pf[1] = nums[0];
        for (int i = 2; i <= n; i++) {
            pf[i] = pf[i - 1] + nums[i - 1];
        }

        // for(int i = 0; i <= n; i++){
        // 	cout << pf[i] << " ";
        // }
        // cout<< endl;
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            // cout << "i = " << i << pf[i] << " " << pf[n]<< " " << pf[i] <<
            // endl;
            if (pf[i] >= (pf[n] - pf[i])) {
                cnt++;
            }
        }

        return cnt;
    }
};