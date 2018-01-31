#include <iostream>

using namespace std;

int findCoin(int coin[], int coinSize);
int main(){

int coin[100];

for (int i=0; i<100; i++){
	coin[i] = 1;
}

coin[88] = 7;

int coinSize = sizeof(coin)/sizeof(int);

cout << findCoin(coin, coinSize) << endl;

return 0;
}

int findCoin(int coin[], int coinSize){

if(coinSize == 1){
	return coin[0];
}
else if(coinSize == 2 && coin[0] > coin[1]){
	return coin[0];
}
else if(coinSize % 3 == 0){
	int a[coinSize/3];
	int b[coinSize/3];
	int c[coinSize/3];
	int sumA = 0;
	int sumB = 0;
	int sumC = 0;
	for(int i=0; i<coinSize; i++){
		if(i < coinSize/3){
			a[i] = coin[i];
			sumA += coin [i];
		}
		if(i >= coinSize/3 && i < (coinSize/3 *2)){
			b[i-(coinSize/3)] = coin[i];
			sumB += coin[i];
		}
		if(i >= (coinSize/3 *2)){
			c[i-(coinSize/3*2)] = coin[i];
			sumC += coin[i];
		}
}
if(sumA > sumB && sumA > sumC)
	findCoin(a, (coinSize/3));
else if(sumB > sumC)
	findCoin(b, (coinSize/3));
else
	findCoin(c, (coinSize/3));


}

else if(coinSize % 3 == 1){
	int a[coinSize/3];
	int b[coinSize/3];
	int c[coinSize/3 + 1];
	int sumA = 0;
	int sumB = 0;
	int sumC = 0;
	for(int i=0; i<coinSize; i++){
		if(i < coinSize/3){
			a[i] = coin[i];
			sumA += coin[i];
		}
		if(i >= coinSize/3 && i < (coinSize/3 *2)){
			b[i-(coinSize/3)] = coin[i];
			sumB += coin[i];
		}
		if(i >= (coinSize/3 *2)){
			c[i-(coinSize/3*2)] = coin[i];
			sumC += coin[i];
		}
}
if(sumA > sumB)
	findCoin(a, (coinSize/3));
else if(sumB > sumA)
	findCoin(b, (coinSize/3));
else
	findCoin(c, (coinSize/3+1));

}

else if(coinSize % 3 == 2){
	int a[coinSize/3+1];
	int b[coinSize/3+1];
	int c[coinSize/3];
	int sumA = 0;
	int sumB = 0;
	int sumC = 0;
	for(int i=0; i<coinSize; i++){
		if(i < coinSize/3 + 1){
			a[i] = coin[i];
			sumA += coin[i];
		}
		if(i >= coinSize/3 + 1 && i < (coinSize/3 *2+2)){
			b[i-(coinSize/3+1)] = coin[i];
			sumB += coin[i];
		}
		if(i >= (coinSize/3 *2 + 2)){
			c[i-(coinSize/3+2)] = coin[i];
			sumC += coin[i];
		}
}
if(sumA > sumB)
	findCoin(a, (coinSize/3+1));
else if(sumB > sumA)
	findCoin(b, (coinSize/3+1));
else
	findCoin(c, (coinSize/3));

}

else
return -1;

}

