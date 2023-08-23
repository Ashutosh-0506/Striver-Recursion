//***********************************ASHUTOSH KUMAR***********************************//
/*
कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

Karmanye vadhikaraste Ma Phaleshu Kadachana,
Ma Karmaphalaheturbhurma Te Sangostvakarmani,

The meaning of the verse is :—
You have the right to work only but never to its fruits.
Let not the fruits of action be your motive, nor let your attachment be to
inaction
*/
#include <bits/stdc++.h>
using namespace ::std;

int plan_snakes(vector<pair<int, int>>&components, int R, int C, int S)
{
    set<pair<int, int>> covered;
    int score = 0;
    sort(components.begin(), components.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second > b.second; });
    for (auto component : components)
    {
        int row = component.first;
        int col = component.second;
        pair<int, int> center = make_pair(row, col);
        bool overlaps = false;
        for (auto covered_cells : covered)
        {
            if (covered_cells.first == row || covered_cells.second == col)
            {
                overlaps = true;
                break;
            }
        }
        if (overlaps)
        {
            continue;
        }
        vector<pair<int, int>> snake = {center};
        for (int i = 1; i < S; i++)
        {
            pair<int, int> last = snake.back();
            vector<pair<int, int>> adj_cells = {make_pair(last.first - 1, last.second), make_pair(last.first + 1, last.second), make_pair(last.first, last.second - 1), make_pair(last.first, last.second + 1)};
            adj_cells.erase(remove_if(adj_cells.begin(), adj_cells.end(), [&](pair<int, int> cell)
                                      { return cell.first < 0 || cell.first >= R || cell.second < 0 || cell.second >= C || covered.count(cell) > 0; }),
                            adj_cells.end());
            if (adj_cells.empty())
            {
                break;
            }
            auto max_it = max_element(adj_cells.begin(), adj_cells.end(), [&](pair<int, int> a, pair<int, int> b)
                                      {
                auto a_it = find(components.begin(), components.end(), a);
                auto b_it = find(components.begin(), components.end(), b);
                if (a_it != components.end() && b_it != components.end()) {
                    return distance(components.begin(), a_it) < distance(components.begin(), b_it);
                } else if (a_it != components.end()) {
                    return true;
                } else {
                    return false;
                } });
            pair<int, int> adj_cell = *max_it;
            snake.push_back(adj_cell);
            covered.insert(adj_cell);
        }
        score += col * snake.size();
    }
    return score > 0 ? score : -1;
}
int main()
{

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif

    int s, r, c;
    cin >> c >> r >> s;
    string st;

    vector<int> snake_length(s, 0);
    vector<vector<int>> grid(r, vector<int>(c, -1));
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cin >> st;
            if (st != "*")
            {
                grid[i][j] = stoi(st);
            }
        }
    }
    int score = plan_snakes(components, r, c, s);
    cout << score << endl; 
    return 0;
}