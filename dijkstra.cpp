#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using namespace std;



long long distance(vector<vector<int> >& adj, vector<vector<int> >& cost, int s, int t) {
    //write your code her
    vector<long long> dist(adj.size());
    //priority_queue<long long> pq;
    std::priority_queue<long long, std::vector<long long >, std::greater<long long>> pq;

    for (size_t i = 0; i < dist.size(); i++)
    {
        dist[i] = INT64_MAX;
    }

    dist[s] = 0;
    pq.push(s);
    long long v, u;

    while (!pq.empty())
    {
        u = pq.top();
        //  cout << u << endl;
        pq.pop();
        for (size_t j = 0; j < adj[u].size(); j++)
        {
            v = adj[u][j];
            if (dist[v] > dist[u] + cost[u][j])
            {
                dist[v] = dist[u] + cost[u][j];
                pq.push(v);
            }

            // cout <<"u " << u  << " V " << v << " Dist v"<< dist[v]  << "Cost" << cost[u][v]<< endl;

        }



    }

    if (dist[t] == INT64_MAX)
    {
        return -1;
    }

    return dist[t];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }



    int s, t;
    std::cin >> s >> t;
    s--, t--;

    std::cout << distance(adj, cost, s, t);
}
