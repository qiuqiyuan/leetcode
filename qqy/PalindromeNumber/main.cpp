nclude <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        int reverse = 0;
        int cx = x;
        while(x != 0){
            int r = x%10;
            reverse = reverse*10 + r;
            x /= 10;
        }
        return reverse == cx;
    }
};

int main()
{
    Solution s;
    cout << (s.isPalindrome(-2147447412) == false ? "pass" : "fail") <<endl;
}

