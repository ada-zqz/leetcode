class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int n = bloomDay.length;
        if (m * k > n) return -1;
        int l = 1, r = (int)1e9;
        while (l < r) {
            int mid = (l + r) / 2, flower = 0, bouquet = 0;
            for (int j = 0; j < n; j++) {
                if (bloomDay[j] > mid) {
                    flower = 0;
                } else if (++flower == k) {
                    flower = 0;
                    bouquet++;
                }
            }
            if (bouquet < m) l = mid + 1;
            else r = mid;
        }
        return l;
    }
}
