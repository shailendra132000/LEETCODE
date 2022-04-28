class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        // support variables
        int tx = h[0].size() - 1, ty = h.size() - 1, cx = 0, cy = 0, res = 0;
        // frontier data format: {distance, {x, y}}
        set<pair<int, pair<int, int>>> frontier;
        // adding the entrance node
        frontier.insert({0, {0, 0}});
        while (cx != tx || cy != ty) {
            auto currNode = begin(frontier);
            // removing already visited nodes
            while (h[currNode->second.second][currNode->second.first] < 0) {
                frontier.erase(currNode);
                currNode = begin(frontier);
            }
            // updating looping variables
            res = max(res, currNode->first), cx = currNode->second.first, cy = currNode->second.second;
            // updating frontier with potential new neighbours
            if (cx && h[cy][cx - 1] > 0) frontier.insert({abs(h[cy][cx] - h[cy][cx - 1]), {cx - 1, cy}});
            if (cy && h[cy - 1][cx] > 0) frontier.insert({abs(h[cy][cx] - h[cy - 1][cx]), {cx, cy - 1}});
            if (cx < tx && h[cy][cx + 1] > 0) frontier.insert({abs(h[cy][cx] - h[cy][cx + 1]), {cx + 1, cy}});
            if (cy < ty && h[cy + 1][cx] > 0) frontier.insert({abs(h[cy][cx] - h[cy + 1][cx]), {cx, cy + 1}});
            // marking currNode as visited
            h[cy][cx] = -h[cy][cx];
        }
        return res;
    }
};