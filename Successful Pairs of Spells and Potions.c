#include <vector>
#include <algorithm>

std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, int success) {
    std::sort(spells.begin(), spells.end());
    std::sort(potions.begin(), potions.end());
    
    int n = spells.size(), m = potions.size();
    std::vector<int> pairs(n, 0);
    
    for (int i = 0; i < n; ++i) {
        int left = 0, right = m - 1, count = 0;
        while (left < m && right >= 0) {
            int product = spells[i] * potions[left];
            if (product < success) {
                ++left;
            } else {
                count += right + 1;
                --right;
            }
        }
        pairs[i] = count;
    }
    
    return pairs;
}
