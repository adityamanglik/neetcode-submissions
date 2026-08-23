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
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return node;
        Node* newNode = new Node(node->val);
        Node* root = newNode;
        vector<Node*> dfs1, dfs2;
        dfs1.push_back(node);
        dfs2.push_back(root);
        unordered_map<Node*, Node*> created;
        created[node] = root;
        set<Node*> visited;
        while((dfs1.size() != 0) and (dfs2.size() != 0))
        {
            Node* currOrig = dfs1.back();
            dfs1.pop_back();
            Node* currDup = dfs2.back();
            dfs2.pop_back();
            if(visited.find(currOrig) != visited.end())
                continue;
            visited.insert(currOrig);
            for(Node* child: currOrig->neighbors)
            {
                dfs1.push_back(child);
                // create new Node cloning child
                if(created.find(child) == created.end())
                {
                    Node* newNode = new Node(child->val);
                    currDup->neighbors.push_back(newNode);
                    dfs2.push_back(newNode);
                    created[child] = newNode;
                }
                else // only clone edge
                {
                    dfs2.push_back(created[child]);
                    currDup->neighbors.push_back(created[child]);
                }
            }            
        }
        return root;
    }
};
