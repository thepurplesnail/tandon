#include <iostream>
#include <vector>
using namespace std;

int digit_to_int(char c){
    return ( static_cast<int>(c) - static_cast<int>('0') );
}
class Money {
    public:
        friend Money operator +(const Money& amount1, const Money& amount2){
            Money temp;
            temp.all_cents = amount1.all_cents + amount2.all_cents;
            return temp;
        };
        friend Money operator -(const Money& amount1, const Money& amount2){
            Money temp;
            temp.all_cents = amount1.all_cents - amount2.all_cents;
            return temp;
        };
        friend Money operator -(const Money& amount){
            Money temp;
            temp.all_cents = -amount.all_cents;
            return temp;
        };
        friend bool operator ==(const Money& amount1, const Money& amount2){
            return (amount1.all_cents == amount2.all_cents);
        };
        friend bool operator <(const Money& amount1, const Money& amount2){
            return amount1.all_cents < amount2.all_cents;
        };
        Money(long dollars, int cents){
            this -> all_cents = dollars * 100 + cents;
        };
        Money(long dollars){
            this -> all_cents = dollars * 100;
        };
        Money(){
            this->all_cents = 0;
        };
        double get_value() const{
            return all_cents*.01;
        };
        friend istream& operator >> (istream& ins, Money& amount) {
            char one_char, decimal_point, digit1, digit2;
            long dollars;
            int cents;
            bool negative;

            ins >> one_char;
            if (one_char == '-'){
                negative = true;
                ins >> one_char; // read '$'
            } else
                negative = false;
            ins >> dollars >> decimal_point >> digit1 >> digit2;
            if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)) {
                cout << "Error illegal form for money input\n";
                exit(1);
            }
            cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
            amount.all_cents = dollars * 100 + cents;
            if (negative)
                amount.all_cents = -amount.all_cents;
            return ins;
        };
        friend ostream& operator << (ostream& outs, const Money& amount) {
            long positive_cents, dollars, cents;
            positive_cents = labs(amount.all_cents);
            dollars = positive_cents/100;
            cents = positive_cents%100;
            
            if (amount.all_cents < 0)
                outs << "- $" << dollars << '.';
            else
                outs << "$" << dollars << '.';
            
            if (cents < 10)
                outs << '0';
            outs << cents;
            return outs;
        }
    private:
        long all_cents;
};

class Check {
    int checkNumber;
    bool isCashed;
    Money checkAmount;
    public:
        Check(){};
        Check(int checkNumber, bool isCashed) {
            this->checkNumber = checkNumber;
            this->isCashed = isCashed;
        }
        friend istream& operator >> (istream& ins, Check& check) {
            int checkNumber;
            Money checkAmount;
            bool isCashed;
            ins >> checkNumber >> checkAmount >> isCashed;
            check.checkNumber = checkNumber;
            check.checkAmount = checkAmount;
            check.isCashed = isCashed;
            return ins;
        }
        friend ostream& operator << (ostream& outs, const Check& check) {
            outs << "Check Number: " << check.checkNumber << " with amount: " << check.checkAmount;
            return outs;
        }
        bool isEndOutputCheck() {
            Money m(0, 0);
            return !isCashed && checkAmount == m && !checkNumber;
        }
        bool isCashedCheck() {
            return isCashed;
        }
        Money getCheckAmount() {
            return checkAmount;
        }
};

int main() {
    Check c;
    Money deposit;
    bool isEndOfOutput = false;
    bool isEndOfDeposit = false;
    vector<Check> cashedV;
    vector<Check> uncashedV;
    Money depositSum, cashedSum, uncashedSum, oldBalance, newBalance, bankBalance, difference;
    cout << "Please enter the check number, dollar amount on check, and whether or not the check has been cashed (1 = YES 0 = NO)" << endl;
    cout << "Example: 9 $40.89 1" << endl;
    while (!isEndOfOutput) {
        cin >> c;
        isEndOfOutput = c.isEndOutputCheck();
        if (!isEndOfOutput) {
            if (c.isCashedCheck()) {
                cashedSum = cashedSum + c.getCheckAmount();
                cashedV.push_back(c);
            }
            else {
                uncashedSum = uncashedSum + c.getCheckAmount();
                uncashedV.push_back(c);
            }
        }
    }
    cout << "The sum of the cashed checks is:" << endl; 
    cout << cashedSum << endl;
    cout << "The sum of the uncashed checks is:" << endl; 
    cout << uncashedSum << endl;

    cout << "Please enter the deposits (end deposit input by typing $0.00):" << endl;
    while (!isEndOfDeposit) {
        cin >> deposit;
        if (deposit.get_value() == 0) {
            isEndOfDeposit = true;
        } else {
            depositSum = depositSum + deposit;
        }
    }
    cout << "The sum of the deposits is:" << endl;
    cout << depositSum << endl;

    cout << "Please enter the prior balance amount:" << endl;
    cin >> oldBalance;

    cout << "Please enter the new balance amount according to account holder:" << endl;
    cin >> newBalance;

    bankBalance = oldBalance + depositSum - cashedSum;
    cout << "The balance according to the bank which includes only cleared checks is: " << bankBalance << endl;
    difference = newBalance - bankBalance;
    if (difference.get_value() < 0) difference = -difference;
    cout << "The difference between the account holders balance of " << newBalance << " and bank balance of " << bankBalance << " is: " << difference << endl;

    cout << "The cashed checks are:" << endl;
    for (Check c : cashedV) cout << c << endl;

    cout << "The uncashed checks are:" << endl;
    for (Check c : uncashedV) cout << c << endl;
}