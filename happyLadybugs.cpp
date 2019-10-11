string happyLadybugs(string b) {
    map<char, int> count;

    for(int i=0;i<b.size();i++){
        if(count.insert(pair<char, int> (b[i], 1)).second == false)
            count[b[i]]++;
    }

    if(count.count('_') == 0){
        for(int i=0;i<b.size();i++){
            if(!isHappy(b, i))
                return "NO";
        }
        return "YES";
    }

    for(auto &x : count){
        if(x.first!='_' && x.second==1)
            return "NO";
    }

    return "YES";
}
