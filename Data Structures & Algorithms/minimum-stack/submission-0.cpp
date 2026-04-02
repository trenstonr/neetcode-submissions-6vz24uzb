class MinStack {
    vector<pair<int, int>> arr; // val, prev_min
public:
    MinStack() {}
    
    void push(int val) {
        if (arr.empty()) {
            arr.push_back({val, INT_MAX});
            return;
        }

        int minv = min(arr.back().first, arr.back().second);
        arr.push_back({val, minv});
    }
    
    void pop() {
        arr.pop_back();
    }
    
    int top() {
        return arr.back().first;
    }
    
    int getMin() {
        return min(arr.back().first, arr.back().second);
    }
};
