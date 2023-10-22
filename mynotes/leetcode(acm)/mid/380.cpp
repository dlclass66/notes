//需要一个unordered_map 存储值和下标的映射，一个vector存储值，一个size记录当前的大小
//主要难点是删除 直接erase 后续下标会失效 采用与最后一个交换然后删除最后一个元素的方法


class RandomizedSet {
private:
    int size;
    vector<int> mvec;
    unordered_map<int, int> mmap;
public:
    RandomizedSet()
    : size(0)
    {

    }
    
    bool insert(int val) {
        if(mmap.find(val) != mmap.end()){
            return false;
        } else {
            size++;
            mvec.push_back(val);
            mmap[val] = size - 1;
        }
        return true;
    }
    
    bool remove(int val) {
        if(mmap.find(val) == mmap.end()){
            return false;
        } else {
            int j = mvec[size - 1];
            mmap[j] = mmap[val];
            mvec[mmap[val]] = j;
            mvec.pop_back();
            size--;
            mmap.erase(val);
        }
        return true;
    }
    
    int getRandom() {
        int i = rand() % size;
        return mvec[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */