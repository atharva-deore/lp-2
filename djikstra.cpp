#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <climits>
#include<algorithm>

using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<pair<int, int>>> adj, int src, int dest, vector<int> &parent)
    {
        // Create a set ds for storing the nodes as a pair {dist,node}
        // where dist is the distance from source to the node.
        // set stores the nodes in ascending order of the distances
        set<pair<int, int>> st;

        // Initialising dist list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> dist(V, INT_MAX);

        st.insert({0, src});

        // Source initialised with dist=0
        dist[src] = 0;

        // Now, erase the minimum distance node first from the set
        // and traverse for all its adjacent nodes.
        while (!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            // Check for all adjacent nodes of the erased
            // element whether the prev dist is larger than current or not.
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edgW = it.second;

                if (dis + edgW < dist[adjNode])
                {
                    // erase if it was visited previously at
                    // a greater cost.
                    if (dist[adjNode] != INT_MAX)
                        st.erase({dist[adjNode], adjNode});

                    // If current distance is smaller,
                    // push it into the queue
                    dist[adjNode] = dis + edgW;
                    parent[adjNode] = node;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        return dist;
    }

    // Function to reconstruct the path from source to destination
    vector<int> reconstructPath(int src, int dest, const vector<int> &parent)
    {
        vector<int> path;
        for (int v = dest; v != src; v = parent[v])
            path.push_back(v);
        path.push_back(src);
        reverse(path.begin(), path.end());
        return path;
    }
};

int main()
{
    // Driver code.
    int V = 3;
    vector<vector<pair<int, int>>> adj(V);
    vector<pair<int, int>> v1{{1, 1}, {2, 6}}, v2{{2, 3}, {0, 1}}, v3{{1, 3}, {0, 6}};

    adj[0] = v1;
    adj[1] = v2;
    adj[2] = v3;

    int src, dest;
    cout << "Enter source and destination vertices: ";
    cin >> src >> dest;

    Solution obj;
    vector<int> parent(V, -1);
    vector<int> res = obj.dijkstra(V, adj, src, dest, parent);

    int totalDistance = res[dest];
    vector<int> path = obj.reconstructPath(src, dest, parent);

    cout << "Shortest path from vertex " << src << " to vertex " << dest << ": ";
    for (int i = 0; i < path.size(); ++i)
    {
        cout << path[i];
        if (i != path.size() - 1)
            cout << " -> ";
    }
    cout << "\nTotal distance: " << totalDistance << endl;

    return 0;
}
