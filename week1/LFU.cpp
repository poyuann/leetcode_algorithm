class LFUCache {
    private:
        int capacity, minFreq;
        unordered_map<int, pair<int, int>> keyToValFreq; 
        unordered_map<int, list<int>> freqToList;
        unordered_map<int, list<int>::iterator> keyToIter; 
    
    public:
        LFUCache(int capacity) : capacity(capacity), minFreq(0) {}
        
        int get(int key) {
            if (keyToValFreq.find(key) == keyToValFreq.end()) {
                return -1;
            }
            updateFrequency(key);
            return keyToValFreq[key].first;
        }
        
        void put(int key, int value) {
            if (capacity == 0) return;
            
            if (keyToValFreq.find(key) != keyToValFreq.end()) {
                keyToValFreq[key].first = value;
                updateFrequency(key);
                return;
            }
            
            if (keyToValFreq.size() >= capacity) {
                evict();
            }
            
            keyToValFreq[key] = {value, 1};
            freqToList[1].push_front(key);
            keyToIter[key] = freqToList[1].begin();
            minFreq = 1;
        }
        
    private:
        void updateFrequency(int key) {
            int freq = keyToValFreq[key].second;
            keyToValFreq[key].second++;
            
            freqToList[freq].erase(keyToIter[key]);
            if (freqToList[freq].empty()) {
                freqToList.erase(freq);
                if (minFreq == freq) {
                    minFreq++;
                }
            }
            
            freqToList[freq + 1].push_front(key);
            keyToIter[key] = freqToList[freq + 1].begin();
        }
        
        void evict() {
            int keyToRemove = freqToList[minFreq].back();
            freqToList[minFreq].pop_back();
            if (freqToList[minFreq].empty()) {
                freqToList.erase(minFreq);
            }
            keyToValFreq.erase(keyToRemove);
            keyToIter.erase(keyToRemove);
        }
    };
    