// O(n+m) n is number of vertices and m is number of edges

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
vector<bool> used;
vector<int> dis, parent;

void print(vector<int> input){
    for (int i: input) cout <<i <<' ';
    cout <<endl;
}

void bfs(int root){
    queue<int> q;
    q.push(root);
    used[root] = true;
    while (!q.empty()){
        int point = q.front();
        q.pop();
        cout <<point <<' ';
        for (int i: v[point]){
            if (!used[i]){
                q.push(i);
                used[i] = true;
                dis[i] = dis[point] + 1;
                parent[i] = point;
            }
        }
    }
    cout <<endl;
}

void input(){
    v.assign(4,vector<int>());
    used.assign(4,false);
    dis.assign(4,0);
    parent.assign(4,-1);
    pair<int,int> edge[]{{0,1},{0,2},{1,2},{2,0},{2,3},{3,3}};
    for (pair<int,int> i: edge){
        v[i.first].push_back(i.second);
        v[i.second].push_back(i.first);
    }
}

int main(){
    input();
    cout <<"Map:\n";
    for (vector<int> i: v) print(i);
    cout <<"BFS: ", bfs(0);
    cout <<"Distance: ", print(dis);
    cout <<"Parent: ", print(parent);
}