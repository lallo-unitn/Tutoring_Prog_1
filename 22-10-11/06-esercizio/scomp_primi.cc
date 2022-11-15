#include <iostream>
using namespace std;

bool isPrimeNumber(int ); 
int main(){

	int num, div=2;
	bool flag= true;
	cin >> num;
	while(num!=1){
		flag=true;
		if(num%div == 0){
			num/=div;
			cout << " " << div;
		}
		else{
			while(flag==true){
    			div++;
    			if(isPrimeNumber(div)){
    				flag=false;
    			}
    		}
		}
	}

	return 0;
}


bool isPrimeNumber(int n){
	bool isPrime=true; 
	if (n == 0 || n == 1) {
        isPrime = false;
    }
    else {
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    return isPrime;

}