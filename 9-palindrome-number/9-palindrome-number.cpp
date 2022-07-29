class Solution {
public:
    bool isPalindrome(int x) {
        int y = x % 10;
        if (y == 0 && x != 0 || x < 0) return false; // return false for negative numbers or numbers with trailing 0s
        while (y < x) {
            x = x / 10;
            if (y < x) y = y * 10 + x % 10;
        }
        return x == y;
    }
};