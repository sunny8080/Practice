#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;


struct node {
    int key, val;
    node* prev, * next;
    node(int key, int val) {
        tie(this->key, this->val) = make_tuple(key, val);
        prev = next = NULL;
    }
};



class LRUCache {
public:
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int cap;
    map<int, node*> mpp;
    int size=0;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node* newnode) {
        newnode->next = head->next;
        newnode->prev = head;
        head->next->prev = newnode;
        head->next = newnode;
        size++;
    }

    void deleteNode(node* delnode) {
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
        size--;
        // free(delnode);
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;
        // if (mpp[key] == NULL) return -1;

        node* resnode = mpp[key];
        int res = resnode->val;
        deleteNode(resnode);
        addNode(resnode);
        mpp.erase(key);
        mpp[key] = head->next;
        return res;
    }

    void put(int key, int value) {
        // if (mpp.find(key) != mpp.end()) {
        if (mpp[key] !=0) {
            deleteNode(mpp[key]);
            // mpp.erase(key);
            addNode(new node(key, value));
            mpp[key] = head->next;
            return;
        }

        if (size == cap) {
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new node(key, value));
        mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */







int32_t main() {
    // fastIO();
    // Solution sol;


    return 0;
}

