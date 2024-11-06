/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* src,unordered_map<int,Node*> &intNode,unordered_map<int,bool> &vis){

        vis[src->val] = true ;
        Node* srcNode ;
           if(intNode.find(src->val) != intNode.end())
                srcNode = intNode[src->val];
            

            else{
                srcNode = new Node(src->val);
                intNode[src->val] = srcNode ;
            }

        for(auto nbr:src->neighbors){

            int value = nbr->val ;
            Node *nbrNode ;
            if(intNode.find(value) != intNode.end())
                nbrNode = intNode[value];
            

            else{
                nbrNode = new Node(value);
                intNode[value] = nbrNode ;
            }

            srcNode->neighbors.push_back(nbrNode);
            if(!vis[value]) dfs(nbr,intNode,vis);
        }
    }

    Node* cloneGraph(Node* node) {

        if(node == NULL)
            return NULL;
        
        unordered_map<int,Node*> intNode ;
        unordered_map<int,bool> vis ;
        dfs(node,intNode,vis);
        
        return intNode[node->val] ;
    }
};