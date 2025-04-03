#include <iostream>
#include <unordered_map>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache; // Hash Map: key → Node*
    Node* head;
    Node* tail;

    // Move node to the front (Most Recently Used)
    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

    // Remove node from the doubly linked list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Add node to the front (Most Recently Used)
    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Remove least recently used node (from the tail)
    Node* removeTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(0, 0); // Dummy head
        tail = new Node(0, 0); // Dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        
        Node* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            if (cache.size() == capacity) {
                Node* tailNode = removeTail();
                cache.erase(tailNode->key);
                delete tailNode;
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToHead(newNode);
        }
    }
};

int main() {
    LRUCache lru(2);
    lru.put(1, 10);
    lru.put(2, 20);
    cout << lru.get(1) << endl; // Returns 10
    lru.put(3, 30); // Removes key 2 (least recently used)
    cout << lru.get(2) << endl; // Returns -1 (not found)
    lru.put(4, 40); // Removes key 1 (least recently used)
    cout << lru.get(1) << endl; // Returns -1 (not found)
    cout << lru.get(3) << endl; // Returns 30
    cout << lru.get(4) << endl; // Returns 40

    return 0;
}
// This code implements an LRU (Least Recently Used) Cache using a doubly linked list and a hash map.