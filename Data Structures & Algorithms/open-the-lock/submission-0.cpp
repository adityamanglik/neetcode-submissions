class Solution {
public:
    struct Node{
        vector<Node*> children;
        bool visitable;
        bool visited;
        int dist;
    };
    int openLock(vector<string>& deadends, string target) {
        vector<Node> graph(10000);
        for(int i = 0; i < 10000; ++i){
            graph[i].visitable = true;
            graph[i].visited = false;
            graph[i].dist = 99999999;
        }
        // construct the graph
        for(int i = 0; i < 10; ++i){
            for(int j = 0; j < 10; ++j){
                for(int k = 0; k < 10; ++k){
                    for(int l = 0; l < 10; ++l){// connect node to 8 neighbors
                        int nodeIndex = (i*1000) + (j*100) + (k*10) + l;
                        int childIndex = (((i+1)%10)*1000) + (j*100) + (k*10) + l;
                        graph[nodeIndex].children.push_back(&graph[childIndex]);
                        if(i == 0)
                            childIndex = (((9)%10)*1000) + (j*100) + (k*10) + l;
                        else
                            childIndex = (((i-1)%10)*1000) + (j*100) + (k*10) + l;
                        graph[nodeIndex].children.push_back(&graph[childIndex]);
                        childIndex = (i*1000) + (((j+1)%10)*100) + (k*10) + l;
                        graph[nodeIndex].children.push_back(&graph[childIndex]);
                        if(j == 0)
                            childIndex = (i*1000) + (((9)%10)*100) + (k*10) + l;
                        else    
                            childIndex = (i*1000) + (((j-1)%10)*100) + (k*10) + l;
                        graph[nodeIndex].children.push_back(&graph[childIndex]);
                        childIndex = (i*1000) + (j*100) + (((k+1)%10)*10) + l;
                        graph[nodeIndex].children.push_back(&graph[childIndex]);
                        if(k == 0)
                            childIndex = (i*1000) + (j*100) + (((9)%10)*10) + l;
                        else
                            childIndex = (i*1000) + (j*100) + (((k-1)%10)*10) + l;
                        graph[nodeIndex].children.push_back(&graph[childIndex]);
                        childIndex = (i*1000) + (j*100) + (k*10) + ((l+1)%10);
                        graph[nodeIndex].children.push_back(&graph[childIndex]);
                        if(l==0)
                            childIndex = (i*1000) + (j*100) + (k*10) + ((9)%10);
                        else
                            childIndex = (i*1000) + (j*100) + (k*10) + ((l-1)%10);
                        graph[nodeIndex].children.push_back(&graph[childIndex]);
                    }
                }
            }
        }
        // mark deadends
        for(auto dead:deadends){
            int index = stoi(dead);
            graph[index].visitable = false;
        }
        // launch BFS from 0000
        queue<Node*> BFS;
        BFS.push(&graph[0]);
        graph[0].dist = 0;
        while(BFS.size() != 0){// pop current node
            Node* curr = BFS.front();
            BFS.pop();
            // check if node already visited, otherwise mark
            if(curr->visited == true or curr->visitable == false)
                continue;
            curr->visited = true;
            // early termination
            if(curr == &graph[stoi(target)])
                return curr->dist;
            // mark distance for all children except deadends
            for(auto child:curr->children){
                if(child->visitable == false)
                    continue;
                child->dist = min(child->dist, curr->dist + 1);
                BFS.push(child);
            }
        }
        if (graph[stoi(target)].dist == 99999999)
            return -1;
        return graph[stoi(target)].dist;
    }
};