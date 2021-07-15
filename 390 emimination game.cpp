class Solution {
public:
    int lastRemaining(int n) {
        int first = 1;
        int diff = 1;
        bool left = true;
        while(n>1){
            if(left){
                first += diff;
            }
            else if(n%2 == 1){
                first += diff;
            }
            diff = diff*2;
            n = n/2;
            left = !left;
        }
        return first;
    }
};