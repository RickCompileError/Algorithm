// Bridge is defined an edge which, when removed, makes the graph disconnected
// Compare two points visiting time, if ancester > descendant then the edge is a bridge

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visit;
vector<int> time_in;
int timer;
vector<pair<int,int>> bridges;

void print(){
    for (pair<int,int> i: bridges) cout <<i.first <<' ' <<i.second <<endl;
}

void dfs(int current, int previous=-1){
    visit[current] = true;
    time_in[current] = timer++;
    for (int i: adj[current]){
        if (i==previous) continue;
        if (visit[i]){
            time_in[current] = min(time_in[current],time_in[i]);
        }else{
            dfs(i,current);
            time_in[current] = min(time_in[current],time_in[i]);
            if (time_in[current]<time_in[i]) bridges.push_back({current,i});
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
