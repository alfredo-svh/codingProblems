string appendAndDelete(string s, string t, int k) {
    int steps=0;

    //s: the initial string
    //t: the desired string 

    //CASE1: equal size
    if(s.size()==t.size()){
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                steps = (s.size()-i)*2;
                break;
            }
        }

    }
    //CASE2: s>t
    else if(s.size()>t.size()){
        for(int i=0;i<t.size();i++){
            if(s[i]!=t[i]){
                steps = (s.size()-i)+t.size()-i;
                break;
            }
        }

        if(steps==0){
            steps = s.size()-t.size();
        }
    }
    //CASE3: s<t
    else{
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                steps = (s.size()-i)+t.size()-i;
                break;
            }
        }

        if(steps==0){
            steps = t.size()-s.size();
        }
    }

    if(steps==k || (steps<k && ((k-steps)%2==0 || k>=t.size()*2)))
        return "Yes";
    return "No";

}
