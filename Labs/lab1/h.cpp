// prime or not
#include<iostream>

using namespace std;

string prime(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return "NO";
        }
    }
    return "YES";
}

int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << "NO";
        return 0;
    }
    cout << prime(n);
    return 0;
}