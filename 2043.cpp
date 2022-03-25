#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h>
using namespace std;


/** Function
 * 
 * 
 * */
class Bank {
public:
    Bank(vector<long long>& balance) {
        this->bank = balance;
    }
    // 转账
    bool transfer(int account1, int account2, long long money) {
        if(!living(account1) || !living(account2))
            return false;
        if(bank[account1-1] < money)
            return false;
        bank[account1-1] -= money;
        bank[account2-1] += money;
        return true;
    }
    // 存款
    bool deposit(int account, long long money) {
        if(!living(account))
            return false;
        bank[account-1] += money;
        return true;
    }
    // 取款
    bool withdraw(int account, long long money) {
        if(!living(account))
            return false;
        if(bank[account-1] < money)
            return false;
        bank[account-1] -= money;
        return true;
    }
    bool living(int account){
        if(account <= 0 || account > bank.size())
            return false;
        return true;
    }
    vector<long long> bank;
};


int main(){
    vector<long long>balance={10,100,20,50,30};
    Bank* b = new Bank(balance);
    cout<< boolalpha<<b->withdraw(3,10)<<endl;
    cout<< boolalpha<<b->transfer(5,1,20)<<endl;
    cout<< boolalpha<<b->deposit(5,20)<<endl;
    cout<< boolalpha<<b->transfer(3,4,15)<<endl;
    cout<< boolalpha<<b->withdraw(10,50)<<endl;
}