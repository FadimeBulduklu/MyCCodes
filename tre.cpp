#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Agac {
	int eleman;
	struct Agac *sag, *sol;
} Agaclar;

Agaclar *kok=NULL;
int toplam=0;

Agaclar *DegerAl() {
	Agaclar *yeni;
	yeni=(Agaclar *)malloc(sizeof(Agaclar));
	printf("\nsayi: ");
	scanf("%d",&(yeni->eleman));
	yeni->sag=NULL;
	yeni->sol=NULL;
	return yeni;
}

void ekle(Agaclar *yeni) {
	Agaclar *gecici,*bironceki;
	if(kok==NULL){
		kok=yeni;
	}
	else {
		gecici=kok;
		while(gecici!=NULL) {
			bironceki=gecici;
			if (yeni->eleman<gecici->eleman)
				gecici=gecici->sol;
			else
				gecici=gecici->sag;
		}
		if (yeni->eleman<bironceki->eleman)
			bironceki->sol=yeni;
		else
			bironceki->sag=yeni;
	}
}



void ekle_rec(Agaclar *agackok ,Agaclar *yeni) {
	if(kok==NULL) kok=yeni;
	else {
		if(yeni->eleman < agackok->eleman) {
			if(agackok->sol==NULL)
				agackok->sol=yeni;
			else
				ekle_rec(agackok->sol,yeni);
		} else {
			if(agackok->sag==NULL)
				agackok->sag=yeni;
			else
				ekle_rec(agackok->sag,yeni);
		}
	}
}


Agaclar *arama_rec(Agaclar *kok,int aranan) {
	if (kok==NULL)
		return NULL;
	if (aranan<kok->eleman)
		return arama_rec(kok->sol,aranan);
	else if (aranan>kok->eleman)
		return arama_rec(kok->sag,aranan);
	else return kok;
}


Agaclar *arama(int aranan) {
	Agaclar *gecici=kok;
	while(gecici!=NULL) {
		if(gecici->eleman==aranan) return gecici;
		else if(aranan<gecici->eleman) gecici=gecici->sol;
		else gecici=gecici->sag;
	}
	return NULL;
}


Agaclar * enkucuk(Agaclar *gecici) {
	if (gecici->sol==NULL) return gecici;
	else enkucuk(gecici->sol);
}



Agaclar * enbuyuk(Agaclar *kok) {
	while(kok->sag!=NULL)
		kok=kok->sag;
	return kok;
}


Agaclar * enbuyuk_re(Agaclar *gecici) {
	if (gecici->sag==NULL)
		return gecici;
	return enbuyuk_re(gecici->sag);
}


void inlistele(Agaclar*kok) {
	if(kok!=NULL) {
		inlistele(kok->sol);
		printf("%d",kok->eleman);
		toplam+=kok->eleman;
		inlistele(kok->sag);
	}
}


void prelistele(Agaclar*kok) {
	if(kok!=NULL) {
		printf("%d",kok->eleman);
		prelistele(kok->sol);
		prelistele(kok->sag);
	}
}


void postlistele(Agaclar*kok) {
	if(kok!=NULL) {
		postlistele(kok->sol);
		postlistele(kok->sag);
		printf("%d",kok->eleman);
	}
}



int yukseklik(Agaclar *kok){
	if(kok==NULL){
		return 0;
	}
	else{
		int sag=0,sol=0;
		sol=yukseklik(kok->sol);
		sag=yukseklik(kok->sag);
		if(sol>sag) return sol+1;
		else return sag+1;
	}
}


int hesapla1(Agaclar *kok){
	if(kok->sag!=NULL){
		kok=kok->sag;
		while(kok->sol!=NULL){
			kok=kok->sol;
		}
		return kok->eleman;
	}
	else -1;
}

int hesapla2(Agaclar *kok){
	if(kok->sol!=NULL){
		while(kok->sag!=NULL){
			kok=kok->sag;
		}
		return kok->eleman;
	}
	else return -1;
}

void iki_cocuklular(Agaclar *gecici){
	if(kok==NULL){
		iki_cocuklular(kok->sag);
		iki_cocuklular(kok->sol);
		if(kok->sag!=NULL && kok->sol!=NULL){
			printf("%d",kok->eleman);
		}
	}
}

int sumOfNodes(Agaclar *kok, int k){

	if(kok==NULL) return 0;
	if(k==0) return kok->eleman;

	return (sumOfNodes(kok->sol,k-1)+sumOfNodes(kok->sag,k-1));
}

int main()	{
	Agaclar *yeni,*bul,*ekucuk,*ebuyuk;
	int eleman,aranan,sil,tut;
	char secim;
	while(1) {
		printf("\n1-Ekleme\n2-Listeleme\n3-iki cocuklular\n5-Enkucuk\n6-Enbuyuk\n7-yukseklik\n8-kokun saginin en kucugu ile en buyugu arasindaki fark\n9-Cikis");
		scanf("%c",&secim);
		switch(secim) {
			case '1':
				yeni=DegerAl();
				ekle(yeni);
				break;
			case '2':
				printf("inorder: ");
				inlistele(kok);
				printf("%d",toplam);
				printf("\npreorder: ");
				prelistele(kok);
				printf("\npostorder: ");
				postlistele(kok);
				break;
			case '3':
					//iki_cocuklular(kok);	
					printf("%d",sumOfNodes(kok,3));
				break;
			case '5':
				if(kok!=NULL){
					ekucuk=enkucuk(kok);
					printf("\nAgacin En kucuk Elemani=%d",ekucuk->eleman);
				}
				else puts("\nBos Liste...");
				break;
			case '6':
				if(kok!=NULL) {
					ebuyuk=enbuyuk(kok);
					printf("\n Agacin En buyuk Elemani=%d",ebuyuk->eleman);
				} 
				else puts("\nBos Liste...");
				break;
			case '7':
				printf("yukseklik: ");
				printf("%d",yukseklik(kok));
				break;
			case '8':
				if(hesapla1(kok)!=-1 && hesapla2(kok)!=-1 ){
					int h1=hesapla1(kok),h2=hesapla2(kok);
					printf("aralarýndaki fark= %d",h1-h2);
				}
				else printf("degerlerden biri eksik.");
				break;
			case '9':
				exit(0);
		}
	}
}
