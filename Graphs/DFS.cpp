/*
O(n+m) n is number of vertices and m is number of edges.
Classify:
    Tree Edge: 
        If v is visited after u then edge (u,v) is called a tree edge.
        Tree Edge = All legal dfs edges
    Back Edges: 
        If v is an ancestor of u, then the edge (u,v) is a back edge.
        v is an ancestor exactly if we already entered v, but not exited it yet.
        Cycles can be detected using back edges.
    Forward Edges: 
        If v is a descendant of u, then edge (u,v) is a forward edge.
        If already visited and exited v and entry[u]<entry[v] then the edge (u,v) forms a forward edge.
    Cross Edges:   
        If v is neither an ancestor or descendant of u, then edge (u,v) is a cross edge.
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visit;
vector<int> state;
vector<int> time_in, time_out;
int timer = 0;

void print(vector<int> input){
    for (int i: input) cout <<i <<' ';
    cout <<endl;
}

void input(){
    adj.assign(8,vector<int>());
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(5);
    adj[2].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(6);
    adj[4].push_back(7);
    adj[0].push_back(7);
    adj[5].push_back(1);
    visit.assign(8,false);
    state.assign(8,0);
    time_in.assign(8,0);
    time_out.assign(8,0);
}

void dfs(int node=0){
    visit[node] = true;
    cout <<node <<' ';
    for (int i: adj[node]) if (!visit[i]) dfs(i);
}

// state 1: haven't visited, state 2: visited, state 3: already exited
void advanced_dfs(int node=0){
    time_in[node] = timer++;
    state[node] = 1;
    for (int i: adj[node]) if (state[i]==0) advanced_dfs(i);
    state[node] = 2;
    time_out[node] = timer++;
}

int main(){
    input();
    dfs(); cout <<endl;
    advanced_dfs(); cout <<endl;
    print(state);
    print(time_in);
    print(time_out);
}