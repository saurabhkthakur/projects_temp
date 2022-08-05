#include <bits/stdc++.h>

using namespace std;

// # include vector
# define ll long long
# define pb push_back

class Fraction {
    private:
        int numerator;
        int denominator;

    public:

        Fraction(){

        }
        Fraction(int numerator, int denominator){
            this -> numerator = numerator;
            this -> denominator = denominator;
        }
    
    void print() const{
        cout << this -> numerator << "/" << denominator << endl;
    }

    void simplify(){
        int gcd = 1;
        int j = min(numerator,denominator);

        for(int i =1; i<=j;i++){
            if(numerator % i == 0 && denominator % i == 0){
                gcd=i;
            }
        }

        numerator = numerator/gcd;
        denominator = denominator/gcd;

    }

    void add(Fraction const &f2){
         int lcm = denominator * f2.denominator;
         int x = lcm/ denominator;
         int y = lcm/ f2.denominator;

         this->numerator = x*numerator+ y*f2.numerator;
         this->denominator = lcm;

         simplify();


    }
};


int main(){


    Fraction f1(10,2);
    Fraction f2(15,4);

    // generally we need to mark const function to those function who does not change object
    Fraction const f3;
    f3.print();

    f1.add(f2);
    f1.print();
    f2.print();
    return 0;
}