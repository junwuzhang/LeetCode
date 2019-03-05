/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Hard (23.94%)
 * Total Accepted:    263.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * 
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 *
 * LRUCache cache = new LRUCache( 2 (capacity));
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 */
class LRUCache {
private:
    int size;
    list<int> LRU;
    unordered_map<int, list<int>::iterator> keyIt;
    unordered_map<int, int> keyVal;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (keyVal.find(key) == keyVal.end()) return -1;
        updateLRU(key);
        return keyVal[key];
    }
    
    void put(int key, int value) {
        // set or insert value if key not already represent
        // when reaches capacity and this is a new key, invalidate least recently used item before inserting a new item
        if (keyVal.size() == size && keyVal.find(key) == keyVal.end()){
            evict();
        }
        updateLRU(key);
        keyVal[key] = value;
    }

    void updateLRU(int key){
        // this function resets the item that is just used to the front of the LRU
        // if the key DOES exist
        if (keyVal.find(key) != keyVal.end()){
            // erase the iterator corresponding to key
            LRU.erase(keyIt[key]);
        }
        LRU.push_front(key);
        keyIt[key] = LRU.begin();
    }

    void evict(){
        // delete the value corresponding to the key that is least recent
        keyIt.erase(LRU.back());
        keyVal.erase(LRU.back());
        LRU.pop_back();
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

