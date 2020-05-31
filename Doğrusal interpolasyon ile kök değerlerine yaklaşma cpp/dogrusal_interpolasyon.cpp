/*
	Name: Bilgisayar Bilimlerinde Nümerik Analiz 
	Author: Beytullah topuz 
	Date: 03.05.20 15:30
	Description: verilen fonksiyonun doðrusal iterpolasyon metodu ile hesaplanmasý 
*/

#include<bits/stdc++.h>
#include<math.h>

using namespace std;

double tmpA,tmpB;//geçici a ve b deðerleri
double AN[50];
double BN[50];//tablo için gerekli kayýt etme iþlemleri 
double XN[50];
int counter=1;// iteraston sayisi

double f(double x){ // f(x) fonksiyonu....
	return (pow(x,3))-(2*(pow(x,2)))-5;
}
bool kokVarmiKontrol(double a,double b){ //sonuc 1 ise iterasyýna geçilir
	if(f(a)*f(b)<0)
		return true;
	else
		return false;
}
double iterasyon(double n,double a,double b){ //return xn;
	return (a*f(b)-b*f(a))/(f(b)-f(a));
}

bool isDurma(double xn){//kurma koþulu
	if(abs(2.69064744-xn)<0.01){
		return true; //Sart saglandiðinda 1 deðeri gönderir durmasu-ý lazým
	}else return false;//þart saðlanmadý iterasyona devam.....
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
	tmpA = AB[0];//globaldeki geçici deðiskemden verileri çekeceðiz;
	tmpB = AB[1];
}
double start(double a, double b){//programý baþlat
	double kok=0;
	AN[counter] = a;
	BN[counter] = b;
	XN[counter] = kok;
	if(!kokVarmiKontrol(a,b))
		return kok;
	else{//iterasyonu yaptýr
		kok = iterasyon(counter++,a,b);// kok = xn deðeri bulundu;
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
