class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        
        int max_groups = hand.size() / groupSize;
        vector<vector<int>> groups;
        for (int card : hand) {
            bool found = false;
            
            for (auto& group : groups) {
                if (group.size() == groupSize) continue;
                if (!group.empty() && group.back() != card - 1) continue;
                group.push_back(card);
                found = true;
                break;
            }

            if (!found) {
                if (groups.size() == max_groups) return false;
                groups.push_back({card});
            }
        }

        return true;
    }
};
