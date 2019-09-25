//#include <bits/stdc++.h>
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//string ltrim(const string &);
//string rtrim(const string &);


#define CREATED 0
#define FINALIZED 1
#define PAID 2
/*
 * Complete the 'calculate_total_owed' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY actions as parameter.
 */

int id;
string currency;
int amount;

struct Invoice{
        int Amount;
        string Currency;
        int Status;
};

void parse(string in){
    size_t pos;
    size_t pos2;

    if(in[0]=='P'){
        id = stoi(in.substr(8));
        return;
    }
    
    //currency
    pos = in.find("y=");
    pos+=2;
    currency = in.substr(pos);

    //id
    pos = in.find("id=");
    pos+=3;
    pos2=in.find("&");
    id=stoi(in.substr(pos, pos2-pos));
    
    //amount
    pos = in.find("t=");
    pos+=2;
    pos2=in.find_last_of('&');
    amount = (stoi(in.substr(pos,pos2-pos)))*100;
}

int calculate_total_owed(vector<string> actions) {
    int total = 0;
    unordered_map<int, Invoice> invoices;

    for(int i=0;i<actions.size();i++){
        //parse -> update id, currency, amount
        parse(actions[i]);

        if(actions[i][0]=='C'){
            //create Invoice instance
            Invoice invoice = {amount, currency, CREATED};
            invoices.insert(pair<int, Invoice>(id, invoice));
            if(currency == "USD"){
                total+=amount;
            }
        }
        else if(actions[i][0]=='F'){
            if(invoices[id].Status==CREATED){
                total-=invoices[id].Amount;
                invoices[id].Amount = amount;
                invoices[id].Currency = currency;
                invoices[id].Status = FINALIZED;
                if(currency == "USD"){
                    total+=amount;
                }
            }
        }
        else{
            if(invoices[id].Status==FINALIZED){
                invoices[id].Status = PAID;
                if(invoices[id].Currency == "USD"){
                    total-=invoices[id].Amount;
                }
            }
        }
    }

    return total;
}

int main(void){
    vector<string> actions;

    actions.push_back("CREATE: id=22&amount=60&currency=USD");
    actions.push_back("CREATE: id=22&amount=60&currency=USD");
    //actions.push_back("FINALIZE: id=22&amount=80&currency=USD");
    //actions.push_back("PAY: id=22");


    cout << calculate_total_owed(actions) <<  endl;
}
