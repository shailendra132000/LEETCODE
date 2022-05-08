class NestedIterator {
private:
    vector<int> arr;
    int idx = 0;
public:
    void push_list(vector<NestedInteger> &nestedList){
        int n = nestedList.size();
        for(int i=0;i<n;i++){
            if(nestedList[i].isInteger())
                arr.push_back(nestedList[i].getInteger());
            else
                push_list(nestedList[i].getList());
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) { 
        push_list(nestedList); 
    }
    
    int next() { 
        return arr[idx++]; 
    }
    
    bool hasNext() { 
        return idx < arr.size(); 
    }
};