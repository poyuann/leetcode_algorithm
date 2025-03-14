class LFUCache {

    private:
        int capacity, minfreq;
        list<pair<int, int>> recent;
        unordered_map<int, list<pair<int, int>>::iterator> pos;
        unordered_map<int, int> freq;
        
        void update(int key) {
            int &freq_tmp = freq[key];
            freq_tmp += 1;
        }
        
    public:
        LFUCache(int capacity) : capacity(capacity), minfreq(1) {}
        
        int get(int key) {
            if (pos.find(key) != pos.end()) {
                update(key);
                return pos[key]->second;
            }
            return -1;
        }
        
        void put(int key, int value) {
            if (pos.find(key) != pos.end()) {
                update(key);
                return;
            }
            else if (recent.size() >= capacity) {
                pos.erase(recent.back().first);
                recent.pop_back();
            }    
            
            recent.push_front({ key, value });
            pos[key] = recent.begin();
            freq[key] = 1;
        }
    };
    
    
    /**
     * Your LFUCache object will be instantiated and called as such:
     * LFUCache* obj = new LFUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */