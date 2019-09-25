string number(int n){
    string prefix="";

    if(n>=50){
        prefix="fifty ";
        n-=50;
    }else if(n>=40){
        prefix="forty ";
        n-=40;
    }
    else if(n>=30){
        prefix="thirty ";
        n-=30;
    }
    else if(n>=20){
        prefix="twenty ";
        n-=20;
    }

    switch(n){
        case 1:
            return prefix + "one";
        case 2:
            return prefix + "two";
        case 3:
            return prefix + "three";
        case 4:
            return prefix + "four";
        case 5:
            return prefix + "five";
        case 6:
            return prefix + "six";
        case 7:
            return prefix + "seven";
        case 8:
            return prefix + "eight";
        case 9:
            return prefix + "nine";
        case 10:
            return "ten";
        case 11:
            return "eleven";
        case 12:
            return "twelve";
        case 13:
            return "thirteen";
        case 14:
            return "fourteen";
        case 15:
            return "fifteen";
        case 16:
            return "sixteen";
        case 17:
            return "seventeen";
        case 18:
            return "eighteen";
        case 19:
            return "nineteen";
        default:
            return prefix;
    }
}

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    string toPast = "past";
    string min = " minutes ";

    //special cases
    if(m==0)
        return number(h) + " o' clock";
    if(m==30)
        return "half past " + number(h);

    //set to or past
    if(m>30){
        toPast="to";
        h++;
        m= 60-m;
    }

    //main
    if(m==15 || m==45)
        return "quarter " + toPast + " " + number(h);
    else{
        if(m==1)
            min = " minute ";
        return number(m) + min + toPast + " " + number(h);
    }

}
