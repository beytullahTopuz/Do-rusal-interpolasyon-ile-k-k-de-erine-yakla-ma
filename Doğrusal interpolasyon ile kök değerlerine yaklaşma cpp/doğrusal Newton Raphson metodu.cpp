/*
	Name:Bilgisayar Bilimlerinde Nümerik Analiz
	Author: Beytullah topuz 1180505035 
	Date: 03.05.20 20:01
	Description: verilen fonksiyonun doðrusal Newton Raphson metodu ile hesaplanmasý 
*/

#include<bits/stdc++.h>
#include<math.h>

using namespace std;
int counter = 0;
double XN1[50];
double XN[50];

double f(double x){ // f(x) fonksiyonu....
	return (pow(x,3))-(2*(pow(x,2)))-5;
}

double f2(double x){// f' tütevi fonksiyonu 
	return (3*pow(x,2))-(4*x);
}

bool kokVarmiKontrol(double a,double b){ //sonuc 1 ise iterasyýna geçilir
	if(f(a)*f(b)<0)
		return true;
	else
		return false;
}

double iterasyon(double xn){
	return (xn)-(f(xn)/f2(xn));
}

bool isDurma(double xn1,double xn){
	if((abs(xn1-xn))<(0.01)){
		return 1;//dur;
	}else return 0;//þart saglandi iterasyona devem edilmeli;	
}

// start sablatýlmadan 1 defa kök vvarmý kontrol mutlaka yapýlmalýdýr
double start(double a,double b){
	double kok = a;
	double kok1;
	kok1 = iterasyon(kok);
	XN1[counter] = kok1;
	XN[counter] = kok;
	counter++;

	if(!isDurma(a,kok1)){//iterasyona devam
		start(kok1,a);
	}else{//dur
		return kok1;
	}
	
}

int main(){
	if(kokVarmiKontrol(2,3))
		cout<<"sonuc : "<<start(2,3)<<endl;
	//cout<<counter;iteras
	cout<<"iterasyon   --     Xn --       Xn+1    HATA"<<endl;
	for(int i=0;i<counter;i++){
		cout<<i+1<<"    -   -  --    "<<XN[i]<<" -----   "<<XN1[i]<<"   ----  "<<"0.01"<<endl;
	} 
	
	
	return 0;
}
