class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());

        int res = -1;
        while (l <= r) {
            int m = midpoint(l, r);

            int total = 0;
            for (int p : piles) {
                total += p / m;
                if (p % m) total++;
            }

            if (total > h) l = m + 1;
            else res = m;
            if (total <= h) r = m - 1;
        }

        return res;
    }
};
