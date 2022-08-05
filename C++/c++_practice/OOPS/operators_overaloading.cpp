#include <bits/stdc++.h>

using namespace std;

// # include vector
# define ll long long
# define pb push_back


class Fraction{
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

    Fraction operator+(Fraction const &f2){
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x*numerator+y*f2.numerator;

        Fraction fnew(num,lcm);
        fnew.simplify();
        return fnew;

    }
    //pre -increment
    Fraction& operator++(){
        numerator = numerator + denominator;
        simplify();
        
        return *this;
    }

    //post - increment
    Fraction operator++(int){
        Fraction Fnew(numerator, denominator);
        Fnew.simplify();

        numerator = numerator + denominator;
        simplify();
        return Fnew;
    }


    Fraction& operator+=(Fraction const &f2 ){

        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        numerator = x*numerator+y*f2.numerator;
        denominator = lcm;
        simplify();
        return *this;


    }
};


int main(){

    Fraction f1(10,2);
    // Fraction f2(15,4);

   /*
    // Fraction f3 = f1 +f2 ; 
    ++(++f1); //ye 6/1 dega because pehle increment k baad new buffer memory m return karega
    // jiska address kuch aur dusra increment uss address pe hoga , copy na create karne k liye
    // hum reference pass karenge;
    f1.print();

    */

    Fraction f3 = f1++;
    f1.print();
    f3.print();
    // f2.print();
    // f3.print();
}