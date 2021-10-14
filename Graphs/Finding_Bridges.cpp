// Bridge is defined an edge which, when removed, makes the graph disconnected
// Compare two points low, if ancester > descendant then the edge is a bridge
// low[v] = min(visit[v], all visit[p] is back edge, all low[p] is tree edge))

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visit;
vector<int> time_in, low;
int timer;
vector<pair<int,int>> bridges;

void print(){
    for (pair<int,int> i: bridges) cout <<i.first <<' ' <<i.second <<endl;
}

void dfs(int current, int previous=-1){
    visit[current] = true;
    time_in[current] = low[current] = timer++;
    for (int i: adj[current]){
        if (i==previous) continue;
        if (visit[i]){
            low[current] = min(low[current],time_in[i]);
        }else{
            dfs(i,current);
            low[current] = min(low[current],low[i]);
            if (low[i]>time_in[current]) bridges.push_back({current,i});
        }
    }
}

void input(int s, int e){
    adj[s].push_back(e);
    adj[e].push_back(s);
}

void init(int n){
    adj.assign(n,vector<int>());
    visit.assign(n,false);
    time_in.assign(n,-1);
    low.assign(n,-1);
    timer = 0;
    input(0,1);
    input(1,2);
    input(0,3);
    input(3,4);
    input(3,5);
    input(5,6);
    input(3,6);
}

int main(){
    init(7);
    dfs(0);
    print();
}
