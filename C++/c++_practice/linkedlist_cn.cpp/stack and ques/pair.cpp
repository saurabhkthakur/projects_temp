#include <bits/stdc++.h>

using namespace std;
template <typename T, typename V>
class Pair{
    T x;
    V y;

    public:

        void setX(T x){
            this->x = x;
        }

        T getX(){
            return x;
        }

        void setY(V y){
            this->y = y;
        }

        V getY(){
            return y;
        }

};





int main(){

    Pair<int,Pair<int,int>> P1;

    P1.setX(11);
     cout << P1.getX() << endl;
    Pair<int,int> P2;
    P2.setX(5);
    P2.setY(14);
    P1.setY(P2);
    cout << P2.getX() << " " << P2.getY() << endl;
    cout << P1.getX() << " " << P1.getY().getX() << " " << P1.getY().getY() << endl;

    return 0; 
}