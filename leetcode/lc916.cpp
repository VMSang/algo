#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2 = {"lo", "eo"};

    map<char, int> max_freq;
    for (string w : words2) {
        map<char, int> tmp;
        for (char c : w) {
            tmp[c]++;
        }
        for (auto [x, y] : tmp) {
            max_freq[x] = max(max_freq[x], tmp[x]);
        }
    }

    // for (auto [x, y] : max_freq) {
    //     cout << x << " " << y << " ";
    // }
    // cout << endl;


    vector<string> ans;
    for (auto w : words1) {
        // make freq each words1 to compare with max_freq
        map<char, int> tmp;
        for(char c : w){
            tmp[c]++;
        }

        if(tmp.size() < max_freq.size()) continue;

        int flag = 1;
        for(auto it = max_freq.begin(); it != max_freq.end(); it++){
            auto check = tmp.find(it->first);
            if(check != tmp.end()){
                // compare freq
                if(check->second < it->second){
                    flag = 0;
                    break;
                }
            } else {
                flag = 0;
                break;
            }
        }

        if(flag) ans.push_back(w);
    }

    return 0;
}