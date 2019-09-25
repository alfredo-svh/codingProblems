int equalizeArray(vector<int> arr) {
    int max=0;
    map<int, int> myMap;

    for(unsigned i=0;i<arr.size();i++){
        if((myMap.insert(pair<int,int>(arr[i],1))).second==false)
            myMap[arr[i]]++;
    }

    for(auto& x: myMap)
        if(x.second > max)
            max=x.second;

    return arr.size()-max;
}
