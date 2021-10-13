#include <bits/stdc++.h>

using namespace std;

int nodes;
vector<vector<int>> adj;
vector<bool> visit;
vector<int> component;

void print(vector<int> input){
	for (int i: input) cout <<i <<' ';
	cout <<endl;
}

void dfs(int node){
	visit[node] = true;
	component.push_back(node);
	for (int i: adj[node]) if (!visit[i]) dfs(i);
}

void find_components(){
	visit.assign(nodes,false);
	for (int i=0;i<nodes;i++){
		if (!visit[i]){
			component.clear();
			dfs(i);
			print(component);
		}
	}
}

void input(){
	nodes = 7;
	adj.assign(nodes,vector<int>());
	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[1].push_back(3);
	adj[4].push_back(5);
	adj[4].push_back(6);
}

int main(){
	input();
	find_components();
}
