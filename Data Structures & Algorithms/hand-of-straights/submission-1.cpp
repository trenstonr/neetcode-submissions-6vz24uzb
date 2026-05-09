class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        sort(hand.begin(), hand.end());

        unordered_map<int, int> count;
        for (int card : hand) count[card]++;

        int group = 0;
        for (int card : hand) {
            if (count[card] == 0) continue;
            for (int i = card; i < card + groupSize; i++) {
                if (count[i] == 0) return false;
                count[i]--;
            }
        }

        return true;
    }
};
