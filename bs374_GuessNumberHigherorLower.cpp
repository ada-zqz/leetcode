/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long lo = 1, hi = n;
        while(lo < hi) {
            long long mid = (lo + hi) / 2;
            int gs = guess(mid);
            if(gs == 0) return mid;
            if(gs < 0) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
