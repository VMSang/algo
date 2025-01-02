/*
bài này prefixsum, do mình lâu không đụng thuật toán nên làm lâu quá
ngày mai xem solution viết lại ngắn gọn hơn
*/

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        
    vector<long> dp(words.size() + 1);
    dp[0] = 0;

    for (size_t i = 0; i < words.size(); i++) {
        int l = 0;
        // cout << "\ncase: " << i << ": ";
        // cout << words[i][0] << "~~~";
        switch (words[i][0]) {
        case 'a':
            l = 1;
            break;
        case 'e':
            l = 1;
            break;
        case 'i':
            l = 1;
            break;
        case 'o':
            l = 1;
            break;
        case 'u':
            l = 1;
            break;
        }
        int r = 0;
        // cout << words[i].back();
        switch (words[i].back()) {
        case 'a':
            r = 1;
            break;
        case 'e':
            r = 1;
            break;
        case 'i':
            r = 1;
            break;
        case 'o':
            r = 1;
            break;
        case 'u':
            r = 1;
            break;
        }
        if (r == 1 && l == 1) {
            dp[i + 1] = dp[i] + 1;
            // cout<<"true";
        }
        else dp[i + 1] = dp[i];
    }
    vector<int> ans;
    for (size_t i = 0; i < queries.size(); i++) {
        ans.push_back(dp[queries[i][1] + 1] - dp[queries[i][0]]);
    }

        return ans;
    }
};