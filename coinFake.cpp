#include <iostream>

using namespace std;

int findCoin(int coin[], int low, int high);
int main(){

int coin[100];
int low = 0;
int high = 99;

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
	
	for(int i = low; i<= high; i++){
		if(i < lowMid)
			sumLow += coin[i];
		else if(i >=lowMid && i < highMid)
			sumMid += coin[i];
		}
	if(sumLow == sumMid)
		findCoin(coin, highMid, high);
	else if(sumLow > sumMid)
		findCoin(coin, low, lowMid-1);
	else
		findCoin(coin, lowMid, highMid-1);
}

}
