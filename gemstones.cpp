using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {
    map<char, int> rocks;
    map<char,int>::iterator it;
    int gems=0;
    char temp;

    for(int i=97;i<=122;i++){
        rocks.insert(pair<char,int>((char)i,0));
    }

    for(int i=0;i<arr.size();i++){
        sort(arr[i].begin(), arr[i].end());
        temp='A';
        for(int j=0;j<arr[i].size();j++){
            if(temp!=arr[i][j]){
                rocks[arr[i][j]]++;
            }
            temp=arr[i][j];
        }

    }

    for(it=rocks.begin();it!=rocks.end();it++){
        if(it->second==arr.size())
            gems++;
    }


    return gems;

}
