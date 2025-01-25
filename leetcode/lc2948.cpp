class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> copyNums(nums);
        sort(copyNums.begin(), copyNums.end());

        unordered_map<int, int> numG;
        int crrG = 0;
        numG[nums[0]] = crrG;
        unordered_map<int, list<int>> gr;
        gr[0].push_back(copyNums[0]); 

        for(int i = 1; i < n; i++){
            if(abs(copyNums[i] - copyNums[i-1]) > limit){
                crrG++;
            }
            numG[copyNums[i]] = crrG;
            gr[crrG].push_back(copyNums[i]);
        }

        for(auto &[x, y] : gr){
            y.sort();
        }

        for(int i = 0; i < n; i++){
            nums[i] = gr[numG[nums[i]]].front();
            gr[numG[nums[i]]].pop_front();
        }
        return nums;
    }
};