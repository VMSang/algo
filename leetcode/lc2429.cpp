class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x = num1;
        int tg = __builtin_popcount(num2);
        int crrx = __builtin_popcount(x);
        int crr = 0;
        while(crrx < tg){
            if(!isSet(x, crr)){
                setBit(x, crr);
                crrx++;
            }
            crr++;
        }   
        while(crrx > tg){
            if(isSet(x, crr)){
                unSetBit(x, crr);
                crrx--;
            }
            crr++;
        }
        return x;
    }
    private:
        bool isSet(int num, int ith){
            return num & (1<<ith);
        }
        void setBit(int &num, int ith){
            num |= (1<<ith);
        }
        void unSetBit(int &num, int ith){
            num &= ~(1<<ith);
        }
};