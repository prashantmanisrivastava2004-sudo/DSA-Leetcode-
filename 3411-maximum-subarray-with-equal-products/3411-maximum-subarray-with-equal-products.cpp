      
class Solution {
public:
    int findGCD(int a, int b) {
        while(b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    long long findLCM(int a, int b) {
        return (1LL * a * b) / findGCD(a, b);
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for(int i = 0; i < n; i++) {
            __int128 prod = 1;
            long long g = 0, l = 1;

            for(int j = i; j < n; j++) {
                if(prod > (__int128)LLONG_MAX * LLONG_MAX / nums[j])
                    break;

                prod *= nums[j];
                g = findGCD(g, nums[j]);
                l = findLCM(l, nums[j]);

                if(prod == (__int128)g * l)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};