#include <iostream>

using namespace std;
int weighCoins(int coin[], int low, int high);
int findCoin(int coin[], int low, int high);
int main(){

int n = 100;

int coin[n];
int low = 0;
int high = (n-1);

for(int i= low; i <= high; i++){
	coin[i] = 1;
}

coin[71] = 2;

cout << findCoin(coin, low, high) << endl;

return 0;

}

int findCoin(int coin[], int low, int high){

if(high == low){
	return high;
}
else if(low == (high-1)){
	if(coin[high] > coin[low])
		return high;
	else
		return low;
}else if(low == (high -2)){
	if(coin[high] >coin[high-1])
		return high;
	else if(coin[high-1] > coin[low])
		return (high-1);
	else
		return low;

}
else{

int thirdsOfDifference =((high+1)-low)/3;
int lowMid = low +thirdsOfDifference;
int highMid = low + (thirdsOfDifference * 2);
int sumLow = 0;
int sumMid = 0;
	

	sumLow = weighCoins(coin, low, lowMid);
	sumMid = weighCoins(coin, lowMid, highMid);

	if(sumLow == sumMid)
		findCoin(coin, highMid, high);
	else if(sumLow > sumMid)
		findCoin(coin, low, lowMid-1);
	else
		findCoin(coin, lowMid, highMid-1);
}

}

int weighCoins(int coin[], int low, int high){
	int sum = 0;
	for(int i=low; i<high; i++){
	sum+= coin[i];
}
	return sum;


}
