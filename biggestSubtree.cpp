#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define l(x) ((x)*2+1)
#define r(x) ((x)*2+2)

using namespace std;

long sum(int pos, vector<long> arr){
    long s=0;

    if(l(pos) < arr.size())
        s+=sum(l(pos), arr);
    if(r(pos) < arr.size())
        s+=sum(r(pos), arr);
    
    if(arr[pos]>0)
        return s + arr[pos];
    else
        return s;
    
}

string solution(vector< long > arr) {
    //empty or only single node tree
    if(arr.size()<2)
        return "";
    //base case: only 2 nodes in tree
    if(arr.size()==2){
        if(arr[1]>0)
            return "Left";
        else
            return "";
    } 
    
    //gets total of left subtree
    long left = sum(1, arr);
    //gets total of right subtree
    long right = sum(2, arr);
    
    if(left==right)
        return "";
    if(left > right)
        return "Left";
    return "Right";
}
