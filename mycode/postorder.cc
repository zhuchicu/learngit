#include <iostream>
#include <stack>
#include <unordered_map>
// #include <map>
#include <vector>
#include<cstdio>
using namespace std;

class Node;
class Solution;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> v;
        stack<Node*> s;
        Node* p = root;
        unordered_map<Node*, int> umap;
        Node* lastvisit = NULL;
        while(!s.empty() || p) {
            if(p) {
                s.push(p);
                int size = p->children.size();
                umap[p] = 0;
                p = size > 0 ? p->children[0] : NULL;
                lastvisit = p;
            } else {
                if(!s.empty()) {
                    p = s.top();
                    int size = p->children.size();
                    int addup = umap[p] + 1;
                    int inx = (size - addup) > 0 ? addup : -1;
                    if (inx > 0) {
                        p = p->children[addup];
                    } else {
                        lastvisit = p;
                        v.push_back(p->val);
                        printf("out: %d\n", p->val);
                        p = NULL;
                        s.pop();
                    }
                }
            }
        }
        return v;
    }
};

Node* buildnaryTree() {
    /**
     *       1
     *    /  |   \
     *   3   2    4
     *  / \
     * 5   6
     *
     */
    
    vector<Node*> v1;
    Node* c1 = new Node(3);
    Node* c2 = new Node(2);
    Node* c3 = new Node(4);
    v1.push_back(c1);
    v1.push_back(c2);
    v1.push_back(c3);

    Node* root = new Node(1, v1);


    vector<Node*> v2;
    Node* c4 = new Node(5);
    Node* c5 = new Node(6);
    v2.push_back(c4);
    v2.push_back(c5);

    c1->children = v2;
    return root;
}



int main() {
    Node* root = buildnaryTree();
    Solution so;
    vector<int> v = so.postorder(root);
    for (int i=0; i<v.size(); i++) {
        printf("%d", v[i]);
    }
    printf("\n");
}