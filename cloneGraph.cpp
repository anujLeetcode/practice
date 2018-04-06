/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
*/


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
      if(node == NULL) return NULL;
        
      if(hash.find(node) == hash.end()) {
          UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
          hash[node] = new_node;
      }
        
      for(auto node_neighbor : node->neighbors) {
          if(hash.find(node_neighbor) != hash.end()) {
            hash[node]->neighbors.push_back(hash[node_neighbor]);
          } else {
            hash[node]->neighbors.push_back(cloneGraph(node_neighbor)); 
          }  
      } 
                                        
      return hash[node];   
                                    
    }
};
