class Solution {
public:
      int gcd(int x, int y) {
        while (y != 0) {
            x %= y;
            swap(x, y);
        }
        return x;
    };

    int nthMagicalNumber(int n, int a, int b) {
    const int MOD = 1e9 + 7;

    // Calculate the least common multiple
    int lcm_ab = (a * b) / gcd(a, b);

    // Binary search
    long long left = 1;
    long long right = static_cast<long long>(n) * min(a, b);  //or  n * 1LL * min(a, b);  // Use 1LL for long long conversion

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        // Count the number of magical numbers up to mid
        long long count = mid / a + mid / b - mid / lcm_ab;

        if (count < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left % MOD;
}


};