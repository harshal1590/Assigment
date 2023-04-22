#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int maxQuality = 0;
        vector<int> bestCoord(2);
        for (int x = 0; x <= 50; x++) {
            for (int y = 0; y <= 50; y++) {
                int quality = 0;
                for (auto& tower : towers) {
                    int tx = tower[0], ty = tower[1], tq = tower[2];
                    double d = sqrt(pow(x - tx, 2) + pow(y - ty, 2));
                    if (d <= radius) {
                        quality += floor(tq / (1 + d));
                    }
                }
                if (quality > maxQuality) {
                    maxQuality = quality;
                    bestCoord = {x, y};
                }
            }
        }
        return bestCoord;
    }
};