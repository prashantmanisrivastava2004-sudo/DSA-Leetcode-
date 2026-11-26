class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        int x = 10;
        int turn = 0;

        while (n >= x) {
            n -= x;
            x--;
            turn++;
        }

        return turn % 2 == 1;
    }
};