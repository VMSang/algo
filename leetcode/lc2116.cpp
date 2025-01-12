class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 == 1 || (s[0] == ')' && locked[0] == '1') 
        || (s[n-1] == '(' && locked[n-1] == '1')) return false;
        
        // xu ly ) 1
        stack<int> o, u;
        for(int i = 0; i < n; i++){
            if(locked[i] == '0') u.push(i);
            else if (s[i] == '(') o.push(i);
            else if (s[i] == ')') {
                if(!o.empty()) o.pop(); // uu tien dung open
                else if(!u.empty()) u.pop();
                else return false;
            }
        }

        // xu ly ( 1 con lai chua dung het
        while(!o.empty() && !u.empty() && o.top() < u.top()){
            o.pop();
            u.pop();
        }
        
        // u co the con, nhung luon chan vi moi lan triet tieu nhau la tung cap (2) va ban dau cung da check s chan
        if(!o.empty()) return false;

        return true;
    }
};