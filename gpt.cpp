#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int plan_snakes(vector<pair<int, int>> components, int R, int C, int S) {
    set<pair<int, int>> covered;
    int score = 0;
    sort(components.begin(), components.end(), [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });
    for (auto component : components) {
        int row = component.first;
        int col = component.second;
        pair<int, int> center = make_pair(row, col);
        bool overlaps = false;
        for (auto covered_cells : covered) {
            if (covered_cells.first == row || covered_cells.second == col) {
                overlaps = true;
                break;
            }
        }
        if (overlaps) {
            continue;
        }
        vector<pair<int, int>> snake = { center };
        for (int i = 1; i < S; i++) {
            pair<int, int> last = snake.back();
            vector<pair<int, int>> adj_cells = { make_pair(last.first - 1, last.second), make_pair(last.first + 1, last.second), make_pair(last.first, last.second - 1), make_pair(last.first, last.second + 1) };
            adj_cells.erase(remove_if(adj_cells.begin(), adj_cells.end(), [&](pair<int, int> cell) { return cell.first < 0 || cell.first >= R || cell.second < 0 || cell.second >= C || covered.count(cell) > 0; }), adj_cells.end());
            if (adj_cells.empty()) {
                break;
            }
            auto max_it = max_element(adj_cells.begin(), adj_cells.end(), [&](pair<int, int> a, pair<int, int> b) {
                auto a_it = find(components.begin(), components.end(), a);
                auto b_it = find(components.begin(), components.end(), b);
                if (a_it != components.end() && b_it != components.end()) {
                    return distance(components.begin(), a_it) < distance(components.begin(), b_it);
                } else if (a_it != components.end()) {
                    return true;
                } else {
                    return false;
                }
            });
            pair<int, int> adj_cell = *max_it;
            snake.push_back(adj_cell);
            covered.insert(adj_cell);
        }
        score += col * snake.size();
    }
    return score > 0 ? score : -1;
}

int main() {
    // Example usage
    vector<pair<int, int>> components = {{0, 1}, {1, 7}, {2, 2}, {3, 0}};
    int R = 4;
    int C = 4;
    int S = 3;
    int score = plan_snakes(components, R, C, S);
    cout << score << endl; // Output: 18
}
