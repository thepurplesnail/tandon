#include <iostream>
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
            temp.all_cents = amount1.all_cents + amount2.all_cents;
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
            return all_cents/100;
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

int main() {
    Money cost, tax, total;
    cout << "Enter amount of money: ";
    cin >> cost;
    cout << "Enter amount of tax: ";
    cin >> tax;
    total = cost + tax;
    cout << "cost = ";
    cout << cost << endl;
    cout << "tax = ";
    cout << tax << endl;
    cout << "total = ";
    cout << total << endl;
    return 0;
}