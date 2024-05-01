#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

map<int, list<int>> m;

void addEdge(int x, int y){
    m[x].push_back(y);
    m[y].push_back(x);
}

void dfs_helper(int src, map<int, bool> &visited){
    cout << src << " ";
    visited[src] = true;

    for(auto nbr : m[src]){
        if(!visited[nbr]){
            dfs_helper(nbr, visited);
        }
    }
}

void dfs(int src){
    map<int, bool> visited;
    dfs_helper(src, visited);
}

void bfs_recursive(queue<int> &q, map<int, bool> &visited){
    if(q.empty())
        return;
    
    int front_ele = q.front();
    q.pop();
    cout << front_ele << " ";

    for(auto nbr : m[front_ele]){
        if(!visited[nbr]){
            q.push(nbr);
            visited[nbr] = true;
        }
    }
    bfs_recursive(q, visited);
}

void bfs(int src){
    map<int, bool> visited;
    queue<int> q;
    
    q.push(src);
    visited[src] = true;

    bfs_recursive(q, visited);
}

int main(){
    addEdge(0,1);
    addEdge(0,2);
    addEdge(0,3);
    addEdge(2,4);
    addEdge(2,5);
    addEdge(3,5);

    cout << "DFS Traversal: ";
    dfs(0);
    cout << endl;

    cout << "BFS Traversal: ";
    bfs(0);
    cout << endl;
}

