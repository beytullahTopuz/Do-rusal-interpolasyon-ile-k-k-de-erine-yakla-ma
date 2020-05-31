/*
	Name: Bilgisayar Bilimlerinde N�merik Analiz 
	Author: Beytullah topuz 
	Date: 03.05.20 15:30
	Description: verilen fonksiyonun do�rusal iterpolasyon metodu ile hesaplanmas� 
*/

#include<bits/stdc++.h>
#include<math.h>

using namespace std;

double tmpA,tmpB;//ge�ici a ve b de�erleri
double AN[50];
double BN[50];//tablo i�in gerekli kay�t etme i�lemleri 
double XN[50];
int counter=1;// iteraston sayisi

double f(double x){ // f(x) fonksiyonu....
	return (pow(x,3))-(2*(pow(x,2)))-5;
}
bool kokVarmiKontrol(double a,double b){ //sonuc 1 ise iterasy�na ge�ilir
	if(f(a)*f(b)<0)
		return true;
	else
		return false;
}
double iterasyon(double n,double a,double b){ //return xn;
	return (a*f(b)-b*f(a))/(f(b)-f(a));
}

bool isDurma(double xn){//kurma ko�ulu
	if(abs(2.69064744-xn)<0.01){
		return true; //Sart saglandi�inda 1 de�eri g�nderir durmasu-� laz�m
	}else return false;//�art sa�lanmad� iterasyona devam.....
}


double yeniAralikBelirleme(double xn,double a,double b){
	double AB[2];//a,b

	if(f(a)*f(xn)<0){//kok var [a,xn]
		AB[0] = a;
		AB[1] = xn;
	}else if(f(xn)*f(b)<0){
		AB[0] = xn;
		AB[1] = b;
	}else{//kok yok
		return -1;
	} 
	tmpA = AB[0];//globaldeki ge�ici de�iskemden verileri �ekece�iz;
	tmpB = AB[1];
}
double start(double a, double b){//program� ba�lat
	double kok=0;
	AN[counter] = a;
	BN[counter] = b;
	XN[counter] = kok;
	if(!kokVarmiKontrol(a,b))
		return kok;
	else{//iterasyonu yapt�r
		kok = iterasyon(counter++,a,b);// kok = xn de�eri bulundu;
		if(!isDurma(kok)){// devam et  
			if(yeniAralikBelirleme(kok,a,b) != -1){
				start(tmpA,tmpB);	
			}
		}else{//durdu;
			AN[counter] = a;
			BN[counter] = b;
			XN[counter] = kok;
			return kok;
		}
	}
}

int main(){

	cout<<"Bulunan yaklasik kok degeri : "<<start(2,3)<<endl<<endl;
	
	cout<<"iterasyon  -- an       --      bn    --     xn  "<<endl;//tablo hali
	for(int i=1;i<counter+1;i++){
		cout<<i<<"     --     "<<AN[i]<<"   --   "<<BN[i]<<"   --  "<<XN[i]<<endl;
	}
	return 0;
}
