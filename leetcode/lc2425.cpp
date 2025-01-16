class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long, long long> frq;

        int sz2 = nums2.size();
        for(int x : nums1){
            frq[x] += sz2;
        }
        int sz1 = nums1.size();
        for(int x : nums2){
            frq[x] += sz1;
        }
        
        int ans = 0;
        for(auto [x, y] : frq){
            ans ^= (y & 1) ? x : 0;
        }

        return ans;        
    }
};