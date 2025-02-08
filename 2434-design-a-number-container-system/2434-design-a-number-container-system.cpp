class NumberContainers {
public:

    unordered_map<int,int>mapping;
    unordered_map<int,set<int>>mappi;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mapping.find(index)!=mapping.end()){
            int prev=mapping[index];
            mappi[prev].erase(index);
            if(mappi[prev].empty()){
                mappi.erase(prev);
            }
        }
        mapping[index]=number;
        mappi[number].insert(index);
    }
    
    int find(int number) {
        if(mappi.find(number)!=mappi.end()){
        return *mappi[number].begin();
        }
        
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */