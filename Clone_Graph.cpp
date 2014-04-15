#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>

using namespace std;

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
			return NULL;
		}
		
//		map<int, UndirectedGraphNode*> nodes;
//		queue<UndirectedGraphNode*> que;
//		que.push(node);
//		
//		while (!que.empty()) {
//			UndirectedGraphNode *tmp = que.front();
//			que.pop();
//			if (nodes.find(tmp->label) == nodes.end()) {
//				UndirectedGraphNode *new_node = new UndirectedGraphNode(tmp->label);
//				nodes.insert(pair<int, UndirectedGraphNode*>(tmp->label, new_node));
//				
//				for (int i = 0; i < tmp->neighbors.size(); i++) {
//					que.push(tmp->neighbors[i]);
//				}
//			}
//		}
//		
//		que.push(node);
//		while (!que.empty()) {
//			UndirectedGraphNode *tmp = que.front();
//			que.pop();
//			UndirectedGraphNode *exist = nodes[tmp->label];
//			if (exist->neighbors.empty() && !tmp->neighbors.empty()) {
//				for (int i = 0; i < tmp->neighbors.size(); i++) {
//					exist->neighbors.push_back(nodes[tmp->neighbors[i]->label]);					que.push(tmp->neighbors[i]);
//				}
//			}
//		}
//		
//		return nodes[node->label];

//		BFS
//		map<UndirectedGraphNode*, UndirectedGraphNode*> nodes;
//		queue<UndirectedGraphNode*> que;
//		nodes[node] = new UndirectedGraphNode(node->label);
//		que.push(node);
//		
//		while (!que.empty()) {
//			UndirectedGraphNode *cur = que.front();
//			que.pop();
//			for (int i = 0; i < cur->neighbors.size(); i++) {
//				UndirectedGraphNode *neighbor = cur->neighbors[i];
//				if (nodes.find(neighbor) == nodes.end()) {
//					nodes[neighbor] = new UndirectedGraphNode(neighbor->label);
//					que.push(neighbor);
//				}
//				nodes[cur]->neighbors.push_back(nodes[neighbor]);
//			}
//		}
//		return nodes[node];

//		DFS
		map<UndirectedGraphNode*, UndirectedGraphNode*> nodes;
		stack<UndirectedGraphNode*> sta;
		nodes[node] = new UndirectedGraphNode(node->label);
		sta.push(node);
		
		while (!sta.empty()) {
			UndirectedGraphNode *cur = sta.top();
			sta.pop();
			for (int i = 0; i < cur->neighbors.size(); i++) {
				UndirectedGraphNode *neighbor = cur->neighbors[i];
				if (nodes.find(neighbor) == nodes.end()) {
					nodes[neighbor] = new UndirectedGraphNode(neighbor->label);
					sta.push(neighbor);
				}
				nodes[cur]->neighbors.push_back(nodes[neighbor]);
			}
		}
		return nodes[node];
    }
};

int main(int argc, char *argv[]) {
	Solution *s = new Solution;
//	UndirectedGraphNode *node = 
}