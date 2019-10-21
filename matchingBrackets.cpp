#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Given a string of angle brackets, write a function that adds angle
	brackets to the beginning and end to make all angle brackets match.
*/

string solution(string angles) {
    string res="";
    int diff=0;
    int beg=0;
    
    for(int i=0;i<angles.size();i++){
        if(angles[i]=='>'){
            if (diff==0)
                beg++;
            else
                diff--;
        }
        else
           diff++;
    }
    
    while(beg!=0){
        res += '<';
        beg--;
    }
    
    res+=angles;
    
    while(diff!=0){
        res+='>';
        diff--;
    }
    
    return res;
}
