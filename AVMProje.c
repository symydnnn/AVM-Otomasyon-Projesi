#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

typedef struct{
	char kullanici_adi[20];
	char TCKimlik[12];
	char adsoyad[30];
	char cinsiyet[10];
	char Sifre[15];
	char calistigiMagaza[30];
	int yas;
	float maas;
	char Dogrulama[20];
	char DogumGunu[10];
    struct IndirimKarti{
    	float Puan;
	} IndirimKarti;
	struct{
		char Sikayet[100];
		char Oneri[100];
	}SikayetveOneri;
	struct{
		char E_Posta[50];
	}Iletisim;
	struct{
		int tatilsayisi;
		int tatiller[365][3];
	}tatil;
}Personel;

typedef struct{
	char kullanici_adi[20];
	char TCKimlik[12];
	char adsoyad[30];
	char cinsiyet[10];
	char Sifre[10];
	int yas;
	float maas;
	char Dogrulama[20];
	char DogumGunu[10];
    struct{
    	float Puan[10];	
	} IndirimKarti;
	struct{
		char E_Posta[50];
	}Iletisim;
}Yonetici;

typedef struct {
	char *Magazaper;
	char Magazakimlik[50];
	char Magazaisim[50];
	char Sektor[50];
	char KimlikSorgulama[50];
	int sec;
	struct {
	    float Satis[12];
	}Gelir;
	struct{
	    float Kira;
	    float alan;
    	struct {
		  	float Toptan[12];
		  	float Elektrik;
		  	float Dogalgaz;
		  	float Su;
		}Fatura;
	    float Toplam;	
	}Gider;	
	struct{
		int *boyut;
		int magazasayisi[1000];
		int tipadet[1];
	}Yapi;	
	struct{
		int tatilsayisi;
		int tatiller[365][3];
		int aydinlatmaderecesi;
	}saatler;
}Magaza;
	
typedef struct{
	char kullanici_adi[20];
	char KimlikNo[12];
	char Ad[20];
	char Soyad[20];
	char Sifre[15];
	char Dogrulama[20];
	char DogumGunu[10];
    struct{
    	float Puan;	
	} IndirimKarti;
	struct{
		char Sikayet[100];
		char Oneri[100];
	}SikayetveOneri;
	struct{
		char Telefon[14];
		char E_Posta[50];
	}Iletisim;
}Musteri;

typedef struct{
	char kampanyakodu[100];
	char kampanyaadi[100];
	char kampanyabilgi[100];
}kmp;

typedef struct{
	int maxkisi;
	int minkisi;	
}gc;
	
	kmp kampanya;
	Personel per;
	Yonetici yon;
	Magaza Boyut;
	Musteri cust;
	gc kisi;
	
void AnaMenu();
void indirkartSayfa();
void yogunlukHesap();
void puanGirdi();
int secim=0;
void MusteriEkran();
void MusteriKayit();
void SifremiUnuttum();
void SikayetVeOneri();
void MusteriGiris();
void MusteriKayitSil();
void MusteriBilgileri(char ARA[]);
void MusteriAnasayfa();
void MagazaMusterileri();
void SikayetVeOneriGoster();
void PersonelKayit();
void SifremiUnuttum2();
void SikayetVeOneri2();
void PersonelSayfa();
void PersonelGiris();
void PersonelKayitSil();
void PersonelBilgileri(char ARA[]);
void PersonelAnasayfa();
void MagazaPersonelleri();
void SikayetVeOneriGoster2();
void MagazaMenu();
void MagazayiGoster();
void MagazaKiralama();
void MagazaKayit();
void MagazaYapilandirma();
void isiklandirma();
void tatiller();
void YonetimKayit();
void YonetimKayitSil();
void YonetimAnasayfa();
void PersonelEkran();
void izingunleri();
void KampanyaEkle();
void KampanyaSil();
void KampanyaGoruntulemeMusteri();
void KampanyaGoruntulemePersonel();
void KampanyaAnaSayfa();
void puanGirdi();
void yogunlukHesap();

int main(){
	setlocale(LC_ALL,"Turkish");
    AnaMenu();
}

void MusteriSayisi()
{
	FILE *kisisayisi=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\KisiSayisi\\kisisayisi.txt","w+");
	int i;
	for(i=0;i<80;i++){printf("_");}printf("\n");
	printf("      PANDEMÝ KOÞULLARI ÝÇÝN AVM YOÐUNLUÐU\n");
	for(i=0;i<80;i++){printf("_");}printf("\n");
	printf("AVM için maksimum kapasite giriþi yapýnýz: ");
	scanf("%d",&kisi.maxkisi);
	printf("AVM için minimum kapasite giriþi yapýnýz: ");
	scanf("%d",&kisi.minkisi);
	fwrite(&kisi,sizeof(kisi),1,kisisayisi);
	fclose(kisisayisi);
	printf("AVM'ye %d maksimum kiþi %d minimum kiþi girebilir.\n\n",kisi.maxkisi,kisi.minkisi);	
	printf("AVM Yönetim Sayfasýna Yeniden yönlendiriliyorsunuz...\n");
	sleep(4);
	YonetimAnasayfa();
}

void yogunlukHesap()
{
	int i, j, s;
	int k=4;
	int l=7;
	int diziH[7];
	long int **matris;
	int degis;
	degis = time(NULL);
	srand(degis);
	float gunlukortaHepsi=0;
	float gunlukortHafta=0;
	
	FILE *kisisayisi=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\KisiSayisi\\kisisayisi.txt","r");
	if(kisisayisi==NULL){
		printf("\n\nMAÐAZA HENÜZ AÇILMAMIÞTIR.\nYayýn Akýþýný Takip edebilmek için Maðaza Yönetimiyle iletiþime geçiniz.\nAna Menüye tekrar yönlendiriliyorsunuz...\n");
		sleep(5);
		AnaMenu();
	}
	else{
		while(fread(&kisi,sizeof(kisi),1,kisisayisi)==1){
			system("cls");
			printf("\nYAYIN AKIÞ SAYFASI\n");
		
		
		for(i=0;i<50;i++){ printf("_");} printf("\n");
		printf("Sondan kaç hafta görüntülensin ? (en fazla 7)_(varsayýlan 4): ");
		scanf("%d",&k);
	
		matris = (long int **)malloc( l * sizeof(long int) );
		if( matris == NULL){
			printf("Maalesef Yetersiz bellek!");}
			for( i = 0; i < l; i++ ){
				matris[i] = (long int *)malloc( k * sizeof(long int) );
				if( matris[i] == NULL)
				printf("Maalesef Yetersiz bellek!");
			}
			for(i=0;i<50;i++){ printf("_");} printf("\n");
			for(i=0;i<k;i++){
				for(j=0;j<7;j++){
					matris[i][j]=rand()%(1000-kisi.minkisi)+kisi.minkisi;
					if(matris[i][j]>kisi.maxkisi){
						matris[i][j]=kisi.maxkisi;
						printf(" %d  ",matris[i][j]);
					}
					else{
						printf(" %d  ",matris[i][j]);
					}
				}
				printf("\n");
			}
			for(i=0;i<50;i++){ printf("_");} printf("\n");
			printf("\n");
			for(i=0;i<50;i++){ printf("_");} printf("\n");
			
			printf("Haftalara göre günlük yoðunluk ortalamasý:\n");
			for(i=0;i<k;i++){
				for(j=0;j<7;j++){
					gunlukortHafta+=(float)(matris[i][j]);
				}
			gunlukortHafta=gunlukortHafta/7;
			gunlukortHafta=gunlukortHafta/10;
			printf("%d) hafta :  %%%.2f  ",(i+1), gunlukortHafta);
			printf("\n");
			gunlukortHafta=0;
			}
			printf("\n");
			printf("Toplam günlük yoðunluk ortalamasý:");
			
			for(i=0;i<k;i++){
				for(j=0;j<7;j++){
					gunlukortaHepsi+=(float)(matris[i][j]);	
				}	
			}
			printf("\n");
			gunlukortaHepsi=( gunlukortaHepsi/(k*7) );
			gunlukortaHepsi=gunlukortaHepsi/10;
			printf("Genel ortalama: %%%.2f\n",gunlukortaHepsi);
			
			for(i=0;i<50;i++){ printf("_");} printf("\n");
	
			printf("\n\nÇýkmak için E, yeniden bakmak için H giriniz: ");
			fflush(stdin);
			if(toupper(getch())== 'H'){
				printf("\n\n");
				yogunlukHesap();
			}
			else if(toupper(getch())== 'E'){
				printf("\n\n");
			}
			sleep(1);
			exit(1);
	    }
	}
}


void KampanyaEkle(){
	int i;
	system("cls");
	for(i=0;i<100;i++){ printf("_");} printf("\n");
	printf("\n           KAMPANYA EKLEME EKRANI\n");
	for(i=0;i<100;i++) {printf("_");} printf("\n");
	a:
	printf("\nKampanya kodunu oluþturun: ");
		scanf("%s",kampanya.kampanyakodu);
   		strcat(kampanya.kampanyakodu,".txt");
    	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\";
    	strcat(dosyauzantisi,kampanya.kampanyakodu);
		FILE *kampanyadosya=fopen(dosyauzantisi,"r");
		if(kampanyadosya==NULL){
			fclose(kampanyadosya);
			kampanyadosya=fopen(dosyauzantisi,"w");
			printf("Kampanyaya baþlýk giriniz: ");
			fflush(stdin);
			gets(kampanya.kampanyaadi);
			printf("Kampanya bilgileri giriniz(Boþluk yerine _ kullanýnýz): ");
			fflush(stdin);
			gets(kampanya.kampanyabilgi);
			printf("Kampanyanýn Durumunu belirleyiniz.\n[1] Kampanya Personeller için ise\n[2] Kampanya Genele Açýk ise\nGiriniz: ");
			scanf("%d",&i);
			fwrite(&kampanya,sizeof(kampanya),1,kampanyadosya);
			fclose(kampanyadosya);
			printf("\nKampanyanýz oluþturulmuþtur!\n Ana Menüye yönlendiriliyorsunuz...\n\n");
			
			if(i==1){
				FILE *kampanyaozel=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiOzel.txt","a+");
				fwrite(&kampanya,sizeof(kampanya),1,kampanyaozel);
				fclose(kampanyaozel);
			}
			else if(i==2){
				FILE *kampanyagenel=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiGenel.txt","a+");
				fwrite(&kampanya,sizeof(kampanya),1,kampanyagenel);
				fclose(kampanyagenel);
			}
			
			YonetimAnasayfa();
		}
		else{
			printf("Ayný Ýsimde Bir Kampanya Bulunmaktadýr.\n[1] Kampanya Menüye Dönmek için\n[2] Yeni bir kampanya oluþturmak için\nGiriniz: ");
			scanf("%d",&secim);
			if(secim==1){
				fclose(kampanyadosya);
				KampanyaAnaSayfa();
			}
			else if(secim==2){
				goto a;
			}
		}	
}


void KampanyaGoruntulemeMusteri(){
	FILE *kampanyagenel=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiGenel.txt","r");
	if(kampanyagenel==NULL){
		printf("Henüz bir kampanya bulunmamaktadýr.\nAna Menüye Yönlendiriliyorsunuz...\n");
		fclose(kampanyagenel);
		sleep(1);
		MusteriAnasayfa();
	}
	else{
		while(fread(&kampanya,sizeof(kampanya),1,kampanyagenel)==1){
		
		printf("%s\n",kampanya.kampanyaadi);
		printf("%s\n\n",kampanya.kampanyabilgi);
		fclose(kampanyagenel);
		}
		printf("Ana Menüye Dönmek için [1]\nGiriniz: ");
		scanf("%d",&secim);
		if(secim==1){
			AnaMenu();
		}
	}
	
	system("cls");
}

void KampanyaGoruntulemePersonel(){
	int i;
	FILE *kampanyaozel=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiOzel.txt","r");
	FILE *kampanyagenel=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiGenel.txt","r");
	if(kampanyaozel==NULL && kampanyagenel==NULL){
		printf("Henüz bir kampanya bulunmamaktadýr.\nAna Menüye Yönlendiriliyorsunuz...\n");
		fclose(kampanyaozel);
		fclose(kampanyagenel);
		sleep(1);
		AnaMenu();
	}
	else{
		printf("PERSONELLERE AÝT KAMPANYALAR: \n");
		for(i=0;i<50;i++){ printf("_");} printf("\n");
		while(fread(&kampanya,sizeof(kampanya),1,kampanyaozel)==1){
		
		printf("%s\n",kampanya.kampanyaadi);
		printf("%s\n\n",kampanya.kampanyabilgi);
		}
		printf("\n\n");
		printf("GENELE AÇIK KAMPANYALAR: \n");
		for(i=0;i<50;i++){ printf("_");} printf("\n");
		while(fread(&kampanya,sizeof(kampanya),1,kampanyagenel)==1){
		printf("%s\n",kampanya.kampanyaadi);
		printf("%s\n\n",kampanya.kampanyabilgi);
		}
		fclose(kampanyagenel);
		fclose(kampanyaozel);
		printf("Ana Menüye Dönmek için [1]\nGiriniz: ");
		scanf("%d",&secim);
		if(secim==1){
			AnaMenu();
		}
	}
	system("cls");
}

void KampanyaAnaSayfa(){
	int i;
	for(i=0;i<50;i++){ printf("_");} printf("\n");
	printf("\n     KAMPANYA SAYFASI\n");
	for(i=0;i<50;i++) {printf("_");} printf("\n");
	x:
	printf("[1] Kampanyalarý Görüntülemek\n[2] Kampanya Kaydý Oluþturmak\n[3] Kampanya Silmek\n[5] Puan girmek\nGiriniz: ");
	scanf("%d",&secim);
	switch(secim){
		case 1:
			KampanyaGoruntulemePersonel();
			break;
		case 2: 
			KampanyaEkle();
			break;
		case 3:
			KampanyaSil();
			break;
		case 4:
			puanGirdi();
			break;
		default: 
		printf("Yanlýþ giriþ yaptýnýz. Tekrar seçim yapmak için yönlendiriliyorsunuz...\n");
		goto x;
	}
}


void indirkartSayfa()
{
	int i;
	int a=0;
	char kullaniciC[20];
	char kullaniciM[20];
	char kullaniciP[20];
	char dosyauzantisiM[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\";
	char dosyauzantisiP[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
    
    for(i=0;i<50;i++){ printf("_");} printf("\n");
	printf("\nAVM KART SAYFASINA HOÞ GELDÝNÝZ\n\n");
	
	printf("Kullanýcý adýnýzý girerek güncel puan durumunuzu görebilirsiniz: ");
	scanf("%s",kullaniciC);
	printf("\n");
	
	strcpy(kullaniciM, kullaniciC);
	strcpy(kullaniciP, kullaniciC);
	
    strcat(kullaniciM,".txt");
    strcat(dosyauzantisiM,kullaniciM);
    strcat(kullaniciP,".txt");
    strcat(dosyauzantisiP,kullaniciP);
    
    FILE *dosya1=fopen(dosyauzantisiM,"r");
    FILE *dosya2=fopen(dosyauzantisiP,"r");
	if( dosya1 == NULL && dosya2 == NULL){
		printf("\tKaydýnýz yok veya silinmiþtir.\n");
		Sleep(3);
		fclose(dosya1);
		fclose(dosya2);
		system("cls");
		AnaMenu();
	}
	else if( dosya1 != NULL){
		fseek(dosya1,6*sizeof(cust),SEEK_SET);
		fread(&cust,sizeof(cust),1,dosya1);
		printf("\tMevcut ParaPuanýnýz: %.2f\n",cust.IndirimKarti.Puan);
		fclose(dosya1);
	}
	else if( dosya2 != NULL){
		fread(&per,sizeof(per),1,dosya2);
		fseek(dosya2,16*sizeof(per),SEEK_SET);
		printf("\tMevcut ParaPuanýnýz: %.2f\n",per.IndirimKarti.Puan);
		fclose(dosya2);
	}
	else{
		printf("\tHem müþteri hem personal kaydýnýz olamaz !");
		Sleep(3);
		system("cls");
		AnaMenu();
	}
	printf("\n");
	fclose(dosya1);
	fclose(dosya2);
	sleep(2);
	printf("not:\n");
	printf("Kaydý olmayan müþteri veya personelin puanlarý silinir.\n");
	printf("Süreye tabi puanlar kullanýlmadýðýnda silinir.\n");
	printf("Zamaný geçmiþ kampanyalardan puan alýnamaz ve faydalanýlamaz.\n\n");
	sleep(4);
	AnaMenu();
}


void AnaMenu(){
	system("cls");
	system("color F3");
	int i;
    for(i=0;i<120;i++){printf("_");}printf("\n");
	printf("%45sHOÞ GELDÝNÝZ!\n","");
	for(i=0;i<120;i++){printf("_");}printf("\n");
	printf("MÜÞTERÝ SAYFASI ÝÇÝN [1]\t YÖNETÝM SAYFASI ÝÇÝN [2]\t PERSONEL SAYFASI ÝÇÝN [3]\t YAYIN AKIÞI [4]\n");
	for(i=0;i<120;i++){printf("_");}printf("\nGiriniz:");
	scanf("%d",&secim);
	switch(secim){
		case 1: 
			MusteriEkran();
			break;
		case 2: YonetimAnasayfa();
			break;
		case 3: PersonelEkran();
			break;
		case 4: yogunlukHesap();
			break;
		default:
			printf("Uygun Deðer Girmediniz.\n Ana Menüye Yönlendiriliyorsunuz...\n");
			sleep(1);
			AnaMenu();
	}
}

void MusteriSayfa(){
	system("cls");
	int i,j;
    for(i=0;i<120;i++){printf("_");
    }
	printf("\n");
	for(i=0;i<120;i++){ printf("_");} printf("\n");
	printf(">|%78s%37s|<\n","    MARUN AVM MÜÞTERÝ SAYFASI     ","");
    for(i=0;i<120;i++){printf("_");
	 }
    printf("\n");
	
	printf("MÜÞTERÝLER[1]\t MÜÞTERÝ ÝNDÝRÝM KARTI BÝLGÝ GÜNCELLEME[2] ÞÝKAYET ÖNERÝLER[3]\tYÖNETÝM ANA SAYFA[4]\n");
	for(i=0;i<120;i++){ printf("_");} printf("\n");
	printf("\nÝþlem seçimi:");scanf("%d",&secim);
	switch(secim){
		case 1:
			MagazaMusterileri();
			break;
		case 2:
			indirkartSayfa();
			break;
		case 3:
            SikayetVeOneriGoster();
			break;
		case 4:
			YonetimAnasayfa();
			break;
		default:
			MusteriSayfa();
	}
}

void YonetimAnasayfa(){
	int i,j;
	int arasecim;
	char sifre[10];
	y:
		system("cls");
	system("color B0");
	for(j=0;j<2;j++){
		for(i=0;i<120;i++){printf("_");}
	   printf("\n");}
	printf("%48s   YÖNETÝM SAYFASI\n","");
	for(j=0;j<2;j++){
	    for(i=0;i<120;i++){printf("_");}
	   	printf("\n");}
	printf("\nYÖNETÝCÝ GÝRÝÞÝ [1]\tYÖNETÝCÝ KAYDI [2]\tYÖNETÝCÝ KAYIT SÝL [3]\tAVM ANA MENÜ [4]\n");	
	for(i=0;i<120;i++){printf("_");}printf("\n");
	printf("Ýþlem seçimi:");scanf("%d",&secim);
	switch(secim){
		case 1:
			x:
			printf("\nKullanýcý Adýnýzý Giriniz: ");
			scanf("%s",yon.kullanici_adi);
			strcat(yon.kullanici_adi,".txt");
			char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Yonetim\\"; 
			strcat(dosyauzantisi,yon.kullanici_adi);
			FILE *yonetim = fopen(dosyauzantisi,"r");
			if(yonetim==NULL){
				printf("Kayýt Bulunamadý.\nTekrar denemek için [1]\nAna Menü için [2]\nGiriniz");
				scanf("%d",&secim);
				if(secim==1)goto x;
				else if(secim==2) goto y; 
			}
			else{
				printf("þifre giriniz:");
				fflush(stdin);
				gets(sifre);
				while(fread(&yon,sizeof(yon),1,yonetim)==1){
					if(strcmp(sifre,yon.Sifre)==0){
						system("cls");
						for(i=0;i<120;i++){	printf("_");}
						printf("\nHOÞ GELDÝNÝZ!\n");
						for(i=0;i<120;i++){	printf("_");}
						printf("[1] Müþteri Ýþlemleri\n[2] Personel Ýþlemleri\n[3] Maðaza iþlemleri\n[4] AVM Yoðunluk görüntüleme \n[5] Tatil Günleri Giriþi\n[6] Kampanya iþlemleri \n[7] Kaydý Sil \n[8] AVM'nin Pandemi Uygunluðu \n");
						for(i=0;i<120;i++){	printf("_");}
						printf("Giriniz: ");scanf("%d",&arasecim);
				        switch(arasecim){
					    case 1: MusteriSayfa();
					    break;
					    case 2: PersonelSayfa();
					    break;
					    case 3: 
						    printf("\n[1] Maðaza Yapýlandýrma Ýþlemleri\n[2] Maðaza Bilgilerini Gösterme\n[3] Maðaza Kayýtlanmasý\nGiriniz:");
						    scanf("%d",&arasecim);
						    if(arasecim==1)
							  MagazaYapilandirma();
						    else if(arasecim==2)
							   MagazayiGoster();
						    else if(arasecim==3)
						       MagazaKayit();
						break;
					    case 4: yogunlukHesap();
					    	break;
						case 5: tatiller();
					    	break;
					    case 6: KampanyaAnaSayfa();
					    	break;
						case 7: YonetimKayitSil();
					    	break;
					    case 8: MusteriSayisi();
					    	break;
				       }
					}
					else{
						printf("Kullanýcý adý ve ya þifre hatalýdýr...\n\n");
						goto x;
					}
				}	
			}
			break;
		case 2: YonetimKayit();
		break;
		case 3:YonetimKayitSil();
		break;
		case 4: AnaMenu();
		break;
		default:
			printf("Uygun Deðer girmediniz.\n\n Ana Menüye Yönlendiriliyorsunuz...\n");
			sleep(1);
			YonetimAnasayfa();
			break;
	}
}

void YonetimKayit(){
	int i;
	system("cls");
	printf("               YÖNETÝCÝ KAYIT EKRANI\n");
	for(i=0;i<50;i++){ printf("_");}
    printf("\n");
	char sifre[10];
	a:
    printf("KULLANICI ADI GÝRÝNÝZ : ");
    scanf("%s",yon.kullanici_adi);
    strcat(yon.kullanici_adi,".txt");
    char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Yonetim\\";
    strcat(dosyauzantisi,yon.kullanici_adi);
	FILE *yonetimd=fopen(dosyauzantisi,"r");
	    if(yonetimd==NULL){
	    	fclose(yonetimd);
		     FILE *yonetimd=fopen(dosyauzantisi,"w+");
	    	do{
				printf("ÞÝFRE GÝRÝNÝZ (þifre 6-10 karakter arasý olmalýdýr) : ");
				scanf("%s",&sifre);
				}while(strlen(sifre)<6);
			k:
				printf("ÞÝFREYÝ TEKRAR GÝRÝNÝZ(ilk girilen þifre ile ayný olmalýdýr) : ");
				scanf("%s",yon.Sifre);
				if(strcmp(sifre,yon.Sifre)!=0){
						goto k;
				}
         fflush(stdin);
    	 printf("ADI SOYADI : ");
	     fflush(stdin);
	     gets(yon.adsoyad);
	     printf("TC KÝMLÝK NO : ");
	     scanf("%s",yon.TCKimlik);
	     printf("CÝNSÝYET : ");
	     scanf("%s",yon.cinsiyet);
	     printf("YAÞ : ");
	     scanf("%d",&yon.yas);
	     printf("MAAÞ : ");
	     scanf("%f",&yon.maas);
	     printf("DOÐRULAMA SORUSU (örn.Anne kýzlýk soyadý ilk ve son hanesi) ? : ");
	     scanf("%s",yon.Dogrulama);
	     printf("E-POSTA ADRESÝ : ");
	     scanf("%s",yon.Iletisim.E_Posta);
	     printf("DOÐUM GÜNÜ (gg/aa/yyyy) : ");
	     scanf("%s",yon.DogumGunu);
	     fwrite(&yon,sizeof(yon),1,yonetimd);
	     fclose(yonetimd);  
	}
	else{
	     printf("Bu kullanýcý adý kullanýlmaktadýr. Tekrar deneyiniz\n");
	     goto a;
	}
	fclose(yonetimd);
	printf("Kaydýnýz baþarýyla gerçekleþtirilmiþtir.\n");
	YonetimAnasayfa();	
}
void YonetimKayitSil(){
	int a=0;
	char kullanici[20],sifre[10];
	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Yonetim\\";
    	printf("KULLANICI ADI GÝRÝNÝZ:");
    	scanf("%s",kullanici);
    	strcat(kullanici,".txt");
    	strcat(dosyauzantisi,kullanici);
    	FILE *yonetimd=fopen(dosyauzantisi,"r");
	 if(yonetimd==NULL){
	 	printf("KAYIT BULUNMAMAKTADIR.");
	 }
	 else{
	 	printf("ÞÝFRE GÝRÝNÝZ:");
		 scanf("%s",sifre);
	 	while(fread(&yon,sizeof(yon),1,yonetimd)==1){
	 		if(strcmp(sifre,yon.Sifre)==0){
	 			a=1;
			 }
	     }
	  }
	  if(a==0){
		printf("Kullanýcý adý ya da þifre hatalý.\nKayýt Bulunamadý.");
	     }
	 else {
		printf("Ýlgili hesap kayýtlardan silinmiþtir.");
		fclose(yonetimd);
		remove(dosyauzantisi);
	    }
	  fclose(yonetimd);
	  sleep(2);
	  YonetimAnasayfa();
}


void MusteriEkran(){
	system("cls");
	system("color 74");
	int i,j;
	char ara[12];
	
	for(j=0;j<2;j++){
	    for(i=0;i<120;i++){printf("_");}
	   printf("\n");}
	printf("%70s%38s\n","MARUN AVM  MÜÞTERÝ  ","");
	for(j=0;j<2;j++){
		for(i=0;i<120;i++){printf("_");}
		printf("\n");}
	
	printf("%80s\n","[1]ÜYE OL\t[2]GÝRÝÞ YAP\t[3]ÞÝFREMÝ UNUTTUM\t[4]KAYIT SÝL\t[5]AVM SAYFASI");
	for(i=0;i<120;i++){printf("_");}
	printf("\nSEÇ:");
	scanf("%d",&secim);
	switch(secim){
		case 1:
			MusteriKayit();
		    break;
		case 2:
			MusteriGiris();
		    break;
		case 3:
			SifremiUnuttum();
			break;
		case 4:
			MusteriKayitSil();
			break;
		case 5:
		    AnaMenu();
		    break;
		default:
			printf("Uygun deger giriniz! \n");
			MusteriEkran();
	}
}

void MusteriGiris(){
	int i;
	system("cls");
	printf("                 GÝRÝÞ YAP\n");
	for(i=0;i<50;i++){printf("_");}
	printf("\n");
	char kullaniciadi2[20],sifre2[10];
	printf("kullanýcý adý:");
	fflush(stdin);
	gets(kullaniciadi2);
	printf("þifre");
	fflush(stdin);
	gets(sifre2);
	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\";
    strcat(kullaniciadi2,".txt");
    strcat(dosyauzantisi,kullaniciadi2);
	FILE *dd=fopen(dosyauzantisi,"r");
	if(dd==NULL)
	{
		printf("Dosya bulunamadi - Herhangi bir kayit yok");
		sleep(2);
		MusteriEkran();
	}
	else
	{
		while(fread(&cust,sizeof(cust),1,dd)==1)
		{
			if(strcmp(sifre2,cust.Sifre)==0)
			{
				printf("Giris Basarili ");
				sleep(2);
				MusteriAnasayfa();
			}
			else{
				printf("Giris Basarisiz ");
				fclose(dd);
			    sleep(1);
			    MusteriEkran();
			}
		}
	}
	
}
void SifremiUnuttum(){
	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\";
	char  kullanici[10],alternatif[20];
	printf("KULLANICI ADI GÝRÝNÝZ:");
    scanf("%s",kullanici);
    strcat(kullanici,".txt");
    strcat(dosyauzantisi,kullanici);
	FILE *dd=fopen(dosyauzantisi,"r");
	int k=0; 
	if(dd!=NULL){	
		  printf("Doðrulama sorusu cevabý:");scanf("%s",&alternatif);
		  while(fread(&cust,sizeof(cust),1,dd)==1){
	        if(strcmp(alternatif,cust.Dogrulama)==0){
	        k=1;
	      	printf("ÞÝFRENÝZ: %s\n",cust.Sifre);
	      	sleep(1);
		  } 
		}
    } 
	if(k==0){
		printf("Böyle bir kayýt bulunmamaktadýr.Kullanýcý adý ya da þifre giriþi hatalý olabilir.\n");
		sleep(1);
	}    		
	else if(dd==NULL){
		printf("...Dosya bulunamadý...");
		sleep(1);
	}
	fclose(dd);
	MusteriEkran();
}
void MusteriKayitSil(){
	int a=0;
	char kullanici[20],sifre[10];
	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\";
    printf("KULLANICI ADI GÝRÝNÝZ:");
    scanf("%s",kullanici);
    strcat(kullanici,".txt");
    strcat(dosyauzantisi,kullanici);
    FILE *dd=fopen(dosyauzantisi,"r");
    FILE *must=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\müþteriler.txt","r");
    FILE *temp=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\geçici.txt","a");
	 if(dd==NULL||must==NULL){
	 	printf("KAYIT BULUNMAMAKTADIR.");
	 }
	 else{
	 	printf("ÞÝFRE GÝRÝNÝZ:");scanf("%s",sifre);
	 	while(fread(&cust,sizeof(cust),1,dd)==1){
	 		if(strcmp(sifre,cust.Sifre)==0){
	 			a=1;
			 }
			 while(fread(&cust,sizeof(cust),1,must)==1){
	     	    if(strcmp(kullanici,cust.kullanici_adi)!=0){
	     	    	fwrite(&cust,sizeof(cust),1,temp);
	     	    	
				 }
		     }
	     }
	  }
	  if(a==0){
		printf("Kullanýcý adý ya da þifre hatalý.\nBöyle Bir Müþteri Kayýtlarda Bulunamadý.");
	     }
	 else {
		printf("Ýlgili hesap kayýtlardan silinmiþtir.");
		fclose(dd);
		fclose(must);
		fclose(temp);
		remove(dosyauzantisi);
	    remove("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\müþteriler.txt");
	    rename("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\geçici.txt","C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\müþteriler.txt");
	    }
	  fclose(dd);
	  sleep(2);
	  MusteriEkran();
}
void MusteriAnasayfa(){
	system("cls");
	int i,j;
	char ara[12];
	
	for(j=0;j<2;j++){
	    for(i=0;i<100;i++){printf("_");
	   }
	   printf("\n");
	}
	printf("_%60s%38s_\n","   MARUN AVM MÜÞTERÝ ANASAYFASINA HOÞGELDÝNÝZ     ","");for(j=0;j<2;j++){
	    for(i=0;i<100;i++){printf("_");
	   }
	   printf("\n");
	}
	printf("MÜÞTERÝ BÝLGÝLERÝ[1]%78s\nÝNDÝRÝM KARTI ÝÞLEMLERÝ[2]%72s\nÞÝKAYET VE ÖNERÝLER[3]%76s\nKAMPANYALAR[4]%76s\nÇIKIÞ[5]%90s\n","","","","","");
	for(i=0;i<100;i++){printf("_");
	   }
    printf("\n");
    printf("Ýþlem Seçimi:");scanf("%d",&secim);
    system("cls");
    switch(secim){
    	case 1:
    		printf("TC NO:");scanf("%s",ara);
    	    MusteriBilgileri(ara);
    		break;
    	case 2:
            indirkartSayfa();
    		break;
    	case 3:
    		SikayetVeOneri();
    		break;
    	case 4:
    		KampanyaGoruntulemeMusteri();
    		break;
    	case 5:
    		printf("ÇIKIÞ YAPMIÞ BULUNMAKTASINIZ...");
    		MusteriEkran();
    		break;
    	default:
    		printf("Lütfen uygun bir iþlem numarasý seçiniz..");
    		MusteriAnasayfa();
	}
}
void MusteriKayit(){
	int i;
	system("cls");
	printf("               MUSTERÝ KAYIT EKRANI\n");
	for(i=0;i<50;i++){ printf("_");}
    printf("\n");
	char sifre[10];
	a:
    printf("KULLANICI ADI GÝRÝNÝZ:");
    scanf("%s",cust.kullanici_adi);
    strcat(cust.kullanici_adi,".txt");
    char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\";
    strcat(dosyauzantisi,cust.kullanici_adi);
	FILE *dd=fopen(dosyauzantisi,"r");
	    if(dd==NULL){
	    	fclose(dd);
		     FILE *ff=fopen(dosyauzantisi,"a+");
		     FILE *must=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\müþteriler.txt","a+");
		     fwrite(&cust,sizeof(cust),1,must);
		     fclose(must);
	    	do{
					printf("ÞÝFRE GÝRÝNÝZ (þifre 6-10 karakter arasý olmalýdýr):");
					scanf("%s",&sifre);
				}while(strlen(sifre)<6);
			k:
				printf("ÞÝFREYÝ TEKRAR GÝRÝNÝZ(ilk girilen þifre ile ayný olmalýdýr):");
				scanf("%s",cust.Sifre);
				if(strcmp(sifre,cust.Sifre)!=0){
						goto k;
				}
         fflush(stdin);
	     printf("ÞÝFRENÝZ:");
    	 puts(cust.Sifre);
	     printf("MÜÞTERÝ KÝMLÝK NUMARASI:");
	     scanf("%s",cust.KimlikNo);
	     printf("MÜÞTERÝ ADI:");
	     scanf("%s",cust.Ad);
	     printf("MÜÞTERÝ SOYADI:");
	     scanf("%s",cust.Soyad);
	     printf("DOÐRULAMA SORUSU(örn.Anne kýzlýk soyadý ilk ve son hanesi) ?:");
	     scanf("%s",cust.Dogrulama);
	     printf("MÜÞTERÝ DOÐUM GÜNÜ (gg/aa/yyyy):");
	     scanf("%s",cust.DogumGunu);
	     printf("TELEFON:");
	     scanf("%s",cust.Iletisim.Telefon);
	     printf("E-POSTA ADRESÝ:");
	     scanf("%s",cust.Iletisim.E_Posta);
	     fwrite(&cust,sizeof(cust),1,ff);
	     fclose(ff);
	}
	else{
	     printf("Bu kullanýcý adý kullanýlmaktadýr. Tekrar deneyiniz\n");
	     goto a;
	}
	fclose(dd);	
	MusteriEkran();
}

void MusteriBilgileri(char ARA[]){
	int i;
	char kullanici2[20];
	for(i=0;i<100;i++){printf("_");}
	printf("\n");
	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\";
	printf("KULLANICI ADI GÝRÝNÝZ:");
    scanf("%s",kullanici2);
    strcat(kullanici2,".txt");
    strcat(dosyauzantisi,kullanici2);
	FILE *dd=fopen(dosyauzantisi,"r");
	if(dd != NULL){
		    while(fread(&cust,sizeof(cust),1,dd)==1){
		    	if(strcmp(ARA,cust.KimlikNo)==0){
				    do{
	                 printf("MÜÞTERÝ TC KÝMLÝK NO:%s\n",cust.KimlikNo);
                     printf("MÜÞTERÝ ADI:%s \n",cust.Ad);
                     printf("MÜÞTERÝ SOYADI:%s\n",cust.Soyad);
	                 printf("MÜÞTERÝ DOÐUM GÜNÜ:%s \n",cust.DogumGunu);
	                 printf("MÜÞTERÝ TELEFON:%s\n",cust.Iletisim.Telefon);
	                 printf("MÜÞTERÝ E-POSTA:%s\n",cust.Iletisim.E_Posta);
	                 for(i=0;i<100;i++){printf("_");}
	                 printf("\nAnasayfa için 1(bir)i giriniz:");
	                 scanf("%d",&secim);
					}while(secim!=1);
					MusteriAnasayfa();
				 }
	             else{
	             	printf("KAYIT BULUNAMADI\n");
	             	sleep(1);
	             	MusteriAnasayfa();
				 }
			}
		fclose(dd);
		secim=0;
		MusteriAnasayfa();
	}
	else{
		printf("Kayýt yok\n");
		sleep(1);
		MusteriAnasayfa();
	}
}

void MagazaMusterileri(){
	system("cls");
	int i;
	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\";
    FILE *must=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\müþteriler.txt","r");
	printf("%60sTÜM MÜÞTERÝLER(Müþteri dosyalarý)\n","");
	for(i=0;i<120;i++){printf("_");}printf("\n");
	while(fread(&cust,sizeof(cust),1,must)==1){
		printf("%s\n",cust.kullanici_adi);
	}
	for(i=0;i<120;i++){printf("_");}printf("\n");
	fclose(must);
	y:
	printf("MÜÞTERÝLERDE ARA[1]\t MÜÞTERÝ SAYFASINA GÝT[2]\n Seçim:");
	scanf("%d",&secim);
	switch(secim){
		case 1:
				printf("KULLANICI ADI GÝRÝNÝZ:"); 
                scanf("%s",cust.kullanici_adi);
                strcat(cust.kullanici_adi,".txt");
                strcat(dosyauzantisi,cust.kullanici_adi);
	            FILE *dd=fopen(dosyauzantisi,"r");
                if(dd==NULL){
    	             printf("DOSYA BULUNMAMAKTADIR.KAYIT OLUÞTURUNUZ!");
            	}
	            else{
		             if(fread(&cust,sizeof (cust),1,dd)==1){
		                 printf("\nMÜÞTERÝ DOSYASI:%s",cust.kullanici_adi);
	                     printf("\nMÜÞTERÝ TC KÝMLÝK NO:%s",cust.KimlikNo);
                         printf("\nMÜÞTERÝ ADI-SOYADI:%s %s",cust.Ad,cust.Soyad);
	                     printf("\nMÜÞTERÝ DOÐUM GÜNÜ:%s",cust.DogumGunu);
	                     printf("\nMÜÞTERÝ TELEFON:%s",cust.Iletisim.Telefon);
	                     printf("\nMÜÞTERÝ E-POSTA:%s",cust.Iletisim.E_Posta);
	                }   
	                 else{
	    	             printf("böyle bir müþteri bulunmamaktadýr.\n");
		            }
	             }
                 do{
		         printf("\nMÜÞTERÝ SAYFA ÝÇÝN 1(BÝR)'Ý TUÞLAYINIZ:");scanf("%d",&secim);
	             }while(secim!=1);
	             fclose(dd);  
	             MusteriSayfa();
	             break;
	     case 2:
		     MusteriSayfa();
			 break;
		 default:
		     printf("uygun bir deðer giriniz.\n");
		     goto y;   
	}	
}
void SikayetVeOneriGoster(){
	char gec;
	int i;
	system("cls");
	printf("\n     ÞÝKAYET VE ÖNERÝ BÝLDÝRÝLERÝ\n");
	for(i=0;i<50;i++){ printf("_");} printf("\n");
    printf("[1]ÞÝKAYET\n[2]ÖNERÝLER\n");
    printf("görüntülemek istediðiniz seçeneði seçiniz:");scanf("%d",&secim);
	char dosyauzantisi1[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\sikayet.txt";
	FILE *sikayet=fopen(dosyauzantisi1,"r");
	char dosyauzantisi2[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\oneri.txt";
	FILE *oneri=fopen(dosyauzantisi2,"r");
    switch(secim){
		case 1:
			printf("ÞÝKAYETLER\n");
			for(i=0;i<50;i++){printf("_");}printf("\n");
			while(fread(&cust,sizeof(cust),1,sikayet)==1){
			printf("%s\t",cust.kullanici_adi);
		    printf("%s\n",cust.SikayetveOneri.Sikayet);}
		    secim=0;
		    printf("\nGeri Dönmek için bir tuþa basýn.\n");
		    gec=getch();
			MusteriSayfa();	
		    break;
		case 2:
			printf("ÖNERÝLER\n");
			for(i=0;i<50;i++){printf("_");}printf("\n");
			while(fread(&cust,sizeof(cust),1,oneri)==1){
			printf("%s\t",cust.kullanici_adi);
			printf("%s\n",cust.SikayetveOneri.Oneri);}
			secim=0;
			printf("\nGeri Dönmek için bir tuþa basýn.\n");
		    gec=getch();
			MusteriSayfa();
			break;
	}
	fclose(sikayet);
	fclose(oneri);
}
void SikayetVeOneri(){
	system("cls");
	int i;
	printf("\n     ÞÝKAYET VE ÖNERÝLER\n");
	for(i=0;i<50;i++){ printf("_");} printf("\n");
    char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\";
	printf("[1]ÞÝKAYET\n[2]ÖNERÝLER\n");
	printf("Ýþlem seçimi:");scanf("%d",&secim);
	switch (secim){
		case 1:
			strcat(dosyauzantisi,"sikayet.txt");
			FILE *sikayet=fopen(dosyauzantisi,"a+");
		    fflush(stdin);
			printf("Maðazamýzla ilgili þikayetinizi belirtiniz:");
			gets(cust.SikayetveOneri.Sikayet);
			fwrite(&cust,sizeof(cust),1,sikayet) ;
			fclose(sikayet);
			printf("Þikayetiniz iletilmiþtir.Ýyi günler dileriz.\n");
			sleep(3);
			MusteriAnasayfa();
			break;
		case 2:
			strcat(dosyauzantisi,"oneri.txt");
			FILE *oneri=fopen(dosyauzantisi,"a+");
		    fflush(stdin);
			printf("Daha  iyi bir hizmet için önerileriniz...\n");
			gets(cust.SikayetveOneri.Oneri);
			fwrite(&cust,sizeof(cust),1,oneri);
			fclose(oneri);
			printf("Öneriniz iletilmiþtir.Ýyi günler dileriz...\n");
			sleep(3);
			MusteriAnasayfa();
			break;
		default:
			printf("Uygun  bir tercih giriniz...\n");
			MusteriAnasayfa();
	}
}

void PersonelSayfa(){
	system("cls");
	int i,j;
    for(i=0;i<100;i++){printf("_");
    }
	printf("\n");
	
	printf(">|%59s%37s|<\n","    MARUN AVM PERSONEL SAYFASI     ","");
    for(i=0;i<100;i++){printf("_");
	 }
    printf("\n");
	
	printf("PERSONELLER[1]\t PERSONEL ÝNDÝRÝM KARTI GÖRÜNTÜLEME[2] ÞÝKAYET ÖNERÝLER[3]\tYÖNETÝM ANA SAYFA[4]\n");
	printf("\nÝþlem seçimi:");scanf("%d",&secim);
	switch(secim){
		case 1:
			MagazaPersonelleri();
			break;
		case 2:
			indirkartSayfa();
			break;
		case 3:
            SikayetVeOneriGoster2();
			break;
		case 4:
			YonetimAnasayfa();
			break;
		default:
			PersonelSayfa();
	}
}
void PersonelEkran(){
	system("cls");
	system("color E5");
	int i,j;
	char ara[12];
	
	for(j=0;j<2;j++){
	    for(i=0;i<120;i++){printf("_");
	   }
	   printf("\n");
	}
	printf("%70s%38s\n","   MARUN AVM PERSONEL  ","");for(j=0;j<2;j++){
	    for(i=0;i<120;i++){printf("_");
	   }
	   printf("\n");
	}
	
	printf("%80s","[1]ÜYE OL\t[2]GÝRÝÞ YAP\t[3]ÞÝFREMÝ UNUTTUM\t[4]KAYIT SÝL\t[5]AVM SAYFASI\n","");
	for(i=0;i<120;i++){printf("_");
	   }printf("\nSEÇÝM:");
	scanf("%d",&secim);
	switch(secim){
		case 1:
			PersonelKayit();
		    break;
		case 2:
			PersonelGiris();
		    break;
		case 3:
			SifremiUnuttum2();
			break;
		case 4:
			PersonelKayitSil();
			break;
		case 5:
		    AnaMenu();
		    break;
		default:
			printf("Uygun deger giriniz! \n");
			PersonelEkran();
	}
}

void PersonelGiris(){
    int i;
	system("cls");
	printf("                 GÝRÝÞ YAP\n");
	for(i=0;i<50;i++){printf("_");}
	printf("\n");
	char kullaniciadi2[20],sifre2[10];
	printf("Kullanýcý adý : ");
	fflush(stdin);
	gets(kullaniciadi2);
	printf("Þifre : ");
	fflush(stdin);
	gets(sifre2);
	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
    strcat(kullaniciadi2,".txt");
    strcat(dosyauzantisi,kullaniciadi2);
	FILE *dosya=fopen(dosyauzantisi,"r");
	if(dosya==NULL)
	{
		printf("Dosya bulunamadi\nHerhangi bir kayit yok");
		sleep(1);
		PersonelEkran();
	}
	else
	{
		while(fread(&per,sizeof(per),1,dosya)==1)
		{
			if(strcmp(sifre2,per.Sifre)==0)
			{
				printf("Giriþ Baþarýlý.\n");
				sleep(1);
				PersonelAnasayfa();
			}
			else{
				printf("Giriþ Baþarýsýz.\nTekrar giriþ için yönlendiriliyorsunuz...\n");
				fclose(dosya);
			    sleep(2);
			    PersonelEkran();
			}
		}
	}
	
}
void SifremiUnuttum2(){
	int i;
	system("cls");
	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
	char  kullanici[10],alternatif[20];
	printf("\n         ÞÝFREMÝ GÖRÜNTÜLE\n");
	for(i=0;i<50;i++){printf("_");}printf("\n");
	printf("KULLANICI ADI GÝRÝNÝZ:");
    scanf("%s",kullanici);
    strcat(kullanici,".txt");
    strcat(dosyauzantisi,kullanici);
	FILE *dosya=fopen(dosyauzantisi,"r");
	int k=0; 
	if(dosya!=NULL){	
		  printf("Doðrulama sorusu cevabý:");
		  scanf("%s",&alternatif);
		  while(fread(&per,sizeof(per),1,dosya)==1){
	        if(strcmp(alternatif,per.Dogrulama)==0){
	        k=1;
	      	printf("ÞÝFRENÝZ: %s\n",per.Sifre);
	      	sleep(1);
		  } 
		}
    } 
	if(k==0){
		printf("Böyle bir kayýt bulunmamaktadýr.\nKullanýcý adý ya da þifre giriþi hatalý olabilir.\n");
		sleep(2);
	}    		
	else if(dosya==NULL){
		printf("Dosya bulunamadý.\nPersonel ekranýna yönlendiriliyorsunuz...\n");
		sleep(2);
	}
	fclose(dosya);
	PersonelEkran();
}
void PersonelKayitSil(){
	int a=0;
	int i;
	system("cls");
	char kullanici[20],sifre[10];
	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
	for(i=0;i<50;i++){printf("_");}printf("\n");
	printf("        PERSONEL KAYIT SÝLME EKRANI\n");
	for(i=0;i<50;i++){printf("_");}printf("\n");
	
    printf("KULLANICI ADI GÝRÝNÝZ:");
    scanf("%s",kullanici);
    strcat(kullanici,".txt");
    strcat(dosyauzantisi,kullanici);
    FILE *dosya=fopen(dosyauzantisi,"r");
    FILE *person=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\calisanlar.txt","r");
    FILE *gecici=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\gecicii.txt","a");
	 if(dosya==NULL||gecici==NULL){
	 	printf("KAYIT BULUNMAMAKTADIR.");
	 }
	 else{
	 	printf("ÞÝFRE GÝRÝNÝZ:");scanf("%s",sifre);
	 	while(fread(&per,sizeof(per),1,dosya)==1){
	 		if(strcmp(sifre,per.Sifre)==0){
	 			a=1;
			 }
			 while(fread(&per,sizeof(per),1,person)==1){
	     	    if(strcmp(kullanici,per.kullanici_adi)!=0){
	     	    	fwrite(&per,sizeof(per),1,gecici);	
				 }
		     }
	     }
	  }
	  if(a==0){
		printf("Kullanýcý adý ya da þifre hatalý.\nBöyle Bir Personel Kayýtlarda Bulunamadý.");
	     }
	 else {
		printf("Ýlgili hesap kayýtlardan silinmiþtir.");
		fclose(dosya);
		fclose(person);
		fclose(gecici);
		remove(dosyauzantisi);
	    remove("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\calisanlar.txt");
	    rename("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\gecicii.txt","C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\calisanlar.txt");
	    }
	  fclose(dosya);
	  sleep(2);
	 PersonelEkran();
}
void PersonelAnasayfa(){
	system("cls");
	int i,j;
	char ara[12];
	
	for(j=0;j<2;j++){
	    for(i=0;i<100;i++){printf("_");
	   }
	   printf("\n");
	}
	printf("_%60s_","   MARUN AVM PERSONEL ANASAYFASINA HOÞGELDÝNÝZ     ","");for(j=0;j<2;j++){
	    for(i=0;i<100;i++){printf("_");
	   }
	   printf("\n");
	}
	printf("PERSONEL BÝLGÝLERÝ[1]%78s\nPERSONEL ÝZÝN GÜNLERÝ[2]%72s\nÝNDÝRÝM KARTI ÝÞLEMLERÝ[3]%72s\nÞÝKAYET VE ÖNERÝLER[4]%76s\nKAMPANYALAR [5]%72s\nÇIKIÞ[6]%90s\n","","","","","");
	for(i=0;i<100;i++){printf("_");
	   }
    printf("\n");
    printf("Ýþlem Seçimi:");
	scanf("%d",&secim);
    system("cls");
    switch(secim){
    	case 1:
    		printf("Aranacak personele ait TC No:");
			scanf("%s",ara);
    	    PersonelBilgileri(ara);
    		break;
    	case 2:
    		izingunleri();
    		break;
    	case 3:
    		indirkartSayfa();
    		break;
    	case 4:
    		SikayetVeOneri2();
    		break;
    	case 5:
    		KampanyaGoruntulemePersonel();
    		break;
    	case 6:
    		printf("ÇIKIÞ YAPILMIÞTIR");
    		PersonelEkran();
    		break;
    	default:
    		printf("Lütfen uygun bir iþlem numarasý seçiniz..");
    		PersonelAnasayfa();
	}
}
void PersonelKayit(){
	int i;
	system("cls");
	for(i=0;i<50;i++){printf("_");}printf("\n");
	printf("               PERSONEL KAYIT EKRANI\n");
	for(i=0;i<50;i++){ printf("_");}
    printf("\n");
	char sifre[10];
	b:
	printf("PERSONELÝN ÇALIÞTIÐI MAÐAZA KÝMLÝÐÝ: ");
	scanf("%s",Boyut.Magazakimlik);
    strcat(Boyut.Magazakimlik,".txt");
  	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Magazalar\\";
    strcat(dosyauzantisi,Boyut.Magazakimlik);	
	FILE *magaza =fopen(dosyauzantisi,"r");
	if(magaza==NULL){
		printf("Maðaza Kimliði Yanlýþtýr.\n");
		fclose(magaza);
		goto b;
	}
	else{
		magaza=fopen(dosyauzantisi,"a");

	a:
    printf("KULLANICI ADI GÝRÝNÝZ : ");
    scanf("%s",per.kullanici_adi);
    strcat(per.kullanici_adi,".txt");
    char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
    strcat(dosyauzantisi,per.kullanici_adi);
	FILE *dosya=fopen(dosyauzantisi,"r");
	    if(dosya==NULL){
	    	fclose(dosya);
		     FILE *fdosya=fopen(dosyauzantisi,"a+");
		     FILE *person=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\calisanlar.txt","a+");
	         fwrite(&per,sizeof(per),1,person);
		     fclose(person);
	    	do{
					printf("ÞÝFRE GÝRÝNÝZ (þifre 6-10 karakter arasý olmalýdýr) : ");
					scanf("%s",&sifre);
				}while(strlen(sifre)<6);
			k:
				printf("ÞÝFREYÝ TEKRAR GÝRÝNÝZ(ilk girilen þifre ile ayný olmalýdýr) : ");
				scanf("%s",per.Sifre);
				if(strcmp(sifre,per.Sifre)!=0){
						goto k;
				}
         fflush(stdin);
    	 printf("PERSONEL ADI SOYADI : ");
	     fflush(stdin);
	     gets(per.adsoyad);
	     printf("PERSONEL TC KÝMLÝK NO : ");
	     scanf("%s",per.TCKimlik);
	     printf("CÝNSÝYET : ");
	     scanf("%s",per.cinsiyet);
	     printf("YAÞ : ");
	     scanf("%d",&per.yas);
	     Boyut.Magazaper=per.adsoyad;
		 fwrite(&Boyut,sizeof(Boyut),1,magaza);
		 fclose(magaza);
	     printf("PERSONEL MAAÞ : ");
	     scanf("%f",&per.maas);
	     printf("DOÐRULAMA SORUSU (örn.Anne kýzlýk soyadý ilk ve son hanesi) ? : ");
	     scanf("%s",per.Dogrulama);
	     printf("E-POSTA ADRESÝ : ");
	     scanf("%s",per.Iletisim.E_Posta);
	     printf("PERSONEL DOÐUM GÜNÜ (gg/aa/yyyy) : ");
	     scanf("%s",per.DogumGunu);
	     fwrite(&per,sizeof(per),1,fdosya);
	     fclose(fdosya);  
	}
	else{
	     printf("Bu kullanýcý adý kullanýlmaktadýr. Tekrar deneyiniz\n");
	     sleep(2);
	     goto a;
	}
	fclose(dosya);	
	sleep(2);
	PersonelEkran();}
}
void PersonelBilgileri(char ARA[]){
	int i;
	system("cls");
	for(i=0;i<50;i++){printf("_");}printf("\n");
	printf("          PERSONEL BÝLGÝSÝ\n");
	for(i=0;i<50;i++){printf("_");}printf("\n");
	char kullanici2[20];
	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
	printf("KULLANICI ADI GÝRÝNÝZ:");
    scanf("%s",kullanici2);
    for(i=0;i<100;i++){printf("_");}
    printf("\n");
    strcat(kullanici2,".txt");
    strcat(dosyauzantisi,kullanici2);
	FILE *dosya=fopen(dosyauzantisi,"r");
	if(dosya != NULL){
		    while(fread(&per,sizeof(per),1,dosya)==1){
		    	if(strcmp(ARA,per.TCKimlik)==0){
				    do{
				    	printf("PERSONEL ADI SOYADI : %s\n",per.adsoyad);
	     				printf("PERSONEL TC KÝMLÝK NO : %s\n",per.TCKimlik);
	     				printf("CÝNSÝYET : %s\n",per.cinsiyet);
	     				printf("YAÞ : %d\n",per.yas);
	    				printf("PERSONEL MAAÞ : %.2f TL\n",per.maas);
	    				printf("DOÐRULAMA SORUSU CEVABI : %s\n",per.Dogrulama);
	    				printf("E-POSTA ADRESÝ : %s\n",per.Iletisim.E_Posta);
	     				printf("PERSONEL DOÐUM GÜNÜ (gg/aa/yyyy) : %s\n",per.DogumGunu);
	     				printf("\nÝZÝNLÝ OLDUÐU GÜNLER:\n");
	     				if(per.tatil.tatilsayisi>0){
	     				for(i=0;i<per.tatil.tatilsayisi;i++){
							printf("%d.0%d.%d  \n",per.tatil.tatiller[i][0],per.tatil.tatiller[i][1],per.tatil.tatiller[i][2]);}}
						else{
							printf("Personel Ýzin Günlerini Kullanmamýþtýr.\n");
						}
	                 for(i=0;i<100;i++){printf("_");}
	                 printf("\nAnasayfa için 1(bir)i giriniz:");
	                 scanf("%d",&secim);
					}while(secim!=1);
					fclose(dosya);
					PersonelAnasayfa();
				 }
	             else{
	             	printf("KAYIT BULUNAMADI\n");
	             	sleep(1);
	             	PersonelAnasayfa();
				 }
			}
		fclose(dosya);
		secim=0;
		PersonelAnasayfa();
	}
	else{
		printf("Kayýt yok\n");
		sleep(1);
		PersonelAnasayfa();
	}
}
void izingunleri(){
	system("cls");
	int i;
	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
	for(i=0;i<50;i++){printf("_");}printf("\n");
	printf("            PERSONEL ÝZÝN GÝRÝÞÝ\n");
	for(i=0;i<50;i++){printf("_");}printf("\n");
	printf("KULLANICI ADI GÝRÝNÝZ:"); 
    scanf("%s",per.kullanici_adi);
    strcat(per.kullanici_adi,".txt");
    strcat(dosyauzantisi,per.kullanici_adi);
	FILE *dosya=fopen(dosyauzantisi,"r");
    if(dosya==NULL){
    	printf("KULLANICI BULUNMAMAKTADIR.KAYIT OLUÞTURUNUZ!");
    	sleep(1);
    	PersonelEkran();
	}
	else{
		fclose(dosya);
		FILE *fdosya=fopen(dosyauzantisi,"w");
			int i;
			printf("\n ÝZÝN GÜNLERÝ\n____________________________\n");
			x:
			printf("Kaç izin günü kullanacaðýnýzý giriniz: ");
			scanf("%d",&per.tatil.tatilsayisi);
		if(per.tatil.tatilsayisi>30){
			printf("30 Günden fazla Ýzin kullanýlamaz.\nTekrar yönlendiriliyorsunuz.\n\n\n");
			goto x;
		}
		else{
		
			per.tatil.tatiller[per.tatil.tatilsayisi][3];
		
		for(i=0;i<per.tatil.tatilsayisi;i++){
		printf("%d. Ýzin Giriþi:\n",i+1);
		printf("Gününü girin: ");
		scanf("%d",&per.tatil.tatiller[i][0]);
		printf("Ayýný girin: ");
		scanf("%d",&per.tatil.tatiller[i][1]);
		printf("Yýlýný girin: ");
		scanf("%d",&per.tatil.tatiller[i][2]);
		printf("\n");}
	
	printf("Seçilmiþ Olan Ýzin Günleri\n");
	for(i=0;i<per.tatil.tatilsayisi;i++){
		printf("%d.0%d.%d  \n",per.tatil.tatiller[i][0],per.tatil.tatiller[i][1],per.tatil.tatiller[i][2]);} //gun.ay.yil
	printf("\n\n");	
	fflush(stdin);
	fwrite(&per,sizeof(per),1,dosya);
	fclose(dosya);
	printf("Personel ekranýna Yönlendiriliyorsunuz...\n\n");
	sleep(2);
	PersonelAnasayfa();
	}
	}
}

void MagazaPersonelleri(){
	system("cls");
	int i;
	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
    FILE *person=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\calisanlar.txt","r");
    for(i=0;i<50;i++){printf("_");}printf("\n");
	printf("    TÜM PERSONELLER(Personel dosyalarý)   \n");
	for(i=0;i<50;i++){printf("_");}printf("\n");
	while(fread(&per,sizeof(per),1,person)==1){
		printf("%s\n",per.kullanici_adi);
	}
	fclose(person);
	y:
	printf("PERSONELLERDE ARA[1]\t PERSONEL SAYFASINA GÝT[2]\n Seçim:");
	scanf("%d",&secim);
	switch(secim){
		case 1:
				printf("KULLANICI ADI GÝRÝNÝZ:"); 
                scanf("%s",per.kullanici_adi);
                strcat(per.kullanici_adi,".txt");
                strcat(dosyauzantisi,per.kullanici_adi);
	            FILE *dosya=fopen(dosyauzantisi,"r");
                if(dosya==NULL){
    	             printf("DOSYA BULUNMAMAKTADIR.KAYIT OLUÞTURUNUZ!");
            	}
	            else{
		             if(fread(&per,sizeof (per),1,dosya)==1){
		             	printf("PERSONEL ADI SOYADI : %s\n",per.adsoyad);
						printf("PERSONEL TC KÝMLÝK NO : %s\n",per.TCKimlik);
						printf("CÝNSÝYET : %s\n",per.cinsiyet);
	  					printf("YAÞ : %d\n",per.yas);
	  					printf("ÇALIÞTIÐI MAÐAZA : %s\n",per.calistigiMagaza);
	    				printf("PERSONEL MAAÞ : %.2f TL\n",per.maas);
	    				printf("DOÐRULAMA SORUSU CEVABI : %s\n",per.Dogrulama);
	    				printf("E-POSTA ADRESÝ : %s\n",per.Iletisim.E_Posta);
	     				printf("PERSONEL DOÐUM GÜNÜ (gg/aa/yyyy) : %s\n",per.DogumGunu);
	     				printf("\nÝZÝNLÝ OLDUÐU GÜNLER:\n");
	     				if(per.tatil.tatilsayisi>0){
	     				for(i=0;i<per.tatil.tatilsayisi;i++){
							printf("%d.0%d.%d  \n",per.tatil.tatiller[i][0],per.tatil.tatiller[i][1],per.tatil.tatiller[i][2]);}}
						else{
							printf("Personel Ýzin Günlerini Kullanmamýþtýr.\n");
						}
	                }   
	                 else{
	    	             printf("Böyle bir personel bulunmamaktadýr.\n");
		            }
	             }
                 do{
		         printf("\nPERSONEL SAYFA ÝÇÝN 1(BÝR)'Ý TUÞLAYINIZ:");scanf("%d",&secim);
	             }while(secim!=1);
	             fclose(dosya);  
	             PersonelSayfa();
	             break;
	     case 2:
		     PersonelSayfa();
			 break;
		 default:
		     printf("uygun bir deðer giriniz.\n");
		     goto y;
			 break;   

	}	
}
void SikayetVeOneriGoster2(){
	int i;
	char gec;
	system("cls");
	printf("    PERSONEL ÞÝKAYET VE ÖNERÝ BÝLDÝLERÝ\n________________________________________________\n");
    printf("\n[1]ÞÝKAYET\t[2]ÖNERÝLER\n\n");
    printf("görüntülemek istediðiniz seçeneði seçiniz:");scanf("%d",&secim);
	char dosyauzantisi1[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\sikayet.txt";
	FILE *sikayet=fopen(dosyauzantisi1,"r");
	char dosyauzantisi2[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\oneri.txt";
	FILE *oneri=fopen(dosyauzantisi2,"r");
    switch(secim){
		case 1:
			printf("     ÞÝKAYETLER\n");
			for(i=0;i<50;i++){printf("_");}printf("\n");
			while(fread(&per,sizeof(per),1,sikayet)==1){
		    printf("%s\n",per.SikayetveOneri.Sikayet);}
		    secim=0;
		    printf("\nGeri Dönmek için bir tuþa basýn.\n");
		    gec=getch();
			PersonelSayfa();	
		    break;
		case 2:
			printf("     ÖNERÝLER\n");
			for(i=0;i<50;i++){printf("_");}printf("\n");
			while(fread(&per,sizeof(per),1,oneri)==1){
			printf("%s\n",per.SikayetveOneri.Oneri);}
			secim=0;
			printf("\nGeri Dönmek için bir tuþa basýn.\n");
		    gec=getch();
			PersonelSayfa();
			break;
		default:
			printf("Uygun bir seçim yapýnýz!\n");
			sleep(2);
			SikayetVeOneriGoster2();
	}
	fclose(sikayet);
	fclose(oneri);
}
void SikayetVeOneri2(){
	system("cls");
	printf("\n PERSONEL ÞÝKAYET ÖNERÝ SAYFASI\n______________________________________________\n");
    char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\";
	printf("[1]ÞÝKAYET\t[2]ÖNERÝLER\n\n");
	printf("Ýþlem seçimi:");
	scanf("%d",&secim);
	switch (secim){
		case 1:
			strcat(dosyauzantisi,"sikayet.txt");
			FILE *sikayet=fopen(dosyauzantisi,"a+");
		    fflush(stdin);
			printf("Maðazamýzla ilgili þikayetinizi belirtiniz:");
			gets(per.SikayetveOneri.Sikayet);
			fwrite(&per,sizeof(per),1,sikayet) ;
			fclose(sikayet);
			sleep(2);
			PersonelAnasayfa();
			break;
		case 2:
			strcat(dosyauzantisi,"oneri.txt");
			FILE *oneri=fopen(dosyauzantisi,"a+");
		    fflush(stdin);
			printf("Daha  iyi bir hizmet için önerileriniz...\n");
			gets(per.SikayetveOneri.Oneri);
			fwrite(&per,sizeof(per),1,oneri);
			fclose(oneri);
			sleep(2);
			PersonelAnasayfa();
			break;
		default:
			printf("Uygun  bir tercih giriniz...\n");
			sleep(1);
			PersonelAnasayfa();
	}  
}
void KampanyaSil(){
	int i;
	char kampanyakodu[50];
	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\";
	for(i=0;i<100;i++){ printf("_");} printf("\n");
    printf("\nKampanyayý Silmek Ýçin Kampanya Kodunu Tekrar Giriniz: ");
    scanf("%s",kampanyakodu);
    strcat(kampanyakodu,".txt");
    strcat(dosyauzantisi,kampanyakodu);
    FILE *kampanyadosya=fopen(dosyauzantisi,"r");
	if(kampanyadosya==NULL){
	 	printf("KAYIT BULUNMAMAKTADIR.");
	 	sleep(3);
	 	YonetimAnasayfa();
	}
	else{
		while(fread(&kampanya,sizeof(kampanya),1,kampanyadosya)==1){
		printf("[1] Kampanya Genele Açýk ise\n[2] Personeller için ise\nGiriniz: ");
		scanf("%d",&secim);
		if(secim==1){
			FILE *kampanyagenel=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiGenel.txt","r");
			FILE *temp1=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\geçici.txt","a");
			if(strcmp(kampanyakodu,kampanya.kampanyakodu)!=0){
				fwrite(&kampanya,sizeof(kampanya),1,temp1);
				fclose(temp1);
				fclose(kampanyagenel);
				remove(dosyauzantisi);
				remove("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiGenel.txt");
				rename("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\geçici.txt","C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiGenel.txt");
				}
		}
		else if(secim==2){
			FILE *kampanyaozel=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiOzel.txt","r");
			FILE *temp2=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\geçicii.txt","a");
			if(strcmp(kampanyakodu,kampanya.kampanyakodu)!=0){
				fwrite(&kampanya,sizeof(kampanya),1,temp2);
				fclose(temp2);
				fclose(kampanyaozel);	
				remove(dosyauzantisi);
				remove("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiOzel.txt");
				rename("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\geçici.txt","C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Kampanyalar\\KampanyaBilgiOzel.txt");
				}
		}
		}			
	}
	printf("Ýlgili hesap kayýtlardan silinmiþtir.\nKampanya Menüsüne Yönlendiriliyorsunuz...\n");
	sleep(2);
	KampanyaAnaSayfa();
}
	
void tatiller(){
	system("cls");
	FILE *tatildosya=fopen("tatiller.txt","ab+");
	int i;
		for(i=0;i<50;i++){printf("_");} printf("\n");
		printf("\n        AVM TATÝL TAKVÝMÝ\n");
		for(i=0;i<50;i++){printf("_");} printf("\n\n");
		printf("Yýl içindeki tatil sayýsýný girin: ");
		scanf("%d",&Boyut.saatler.tatilsayisi);
		Boyut.saatler.tatiller[Boyut.saatler.tatilsayisi][3];
	for(i=0;i<Boyut.saatler.tatilsayisi;i++){
		printf("%d. Tatil gününü giriniz:\n",i+1);
		printf("Tatil gününü girin: ");
		scanf("%d",&Boyut.saatler.tatiller[i][0]);
		printf("Tatil ayýný girin: ");
		scanf("%d",&Boyut.saatler.tatiller[i][1]);
		printf("Tatil yýlýný girin: ");
		scanf("%d",&Boyut.saatler.tatiller[i][2]);
		printf("\n");}
	
	printf("AVM Tatil Günleri\n");
	for(i=0;i<Boyut.saatler.tatilsayisi;i++){
		printf("%d.0%d.%d  \n",Boyut.saatler.tatiller[i][0],Boyut.saatler.tatiller[i][1],Boyut.saatler.tatiller[i][2]);} //gun.ay.yil
	printf("\n\n");	
	fflush(stdin);
	fwrite(&Boyut,sizeof(Boyut),1,tatildosya);
	fclose(tatildosya);
	printf("Yönetim sayfasýna geri yönlendiriliyorsunuz...\n");
	sleep(2);
	YonetimAnasayfa();
}
	
void isiklandirma(){
	system("cls");
	FILE *tatildosya=fopen("tatiller.txt","r");
	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Magazalar\\";
	strcat(dosyauzantisi,Boyut.Magazakimlik);
	FILE *id=fopen(dosyauzantisi,"wb+");
	
	time_t time_1970;
	struct tm* time_detay;
	time_1970 = time(NULL);
	int isik,i,secim,tm,anasecim, gun,ay,yil,derece,say;
	
	time_detay = localtime(&time_1970);
	printf("Tarih: %.2d.%.2d.%4d\n", time_detay->tm_mday, time_detay->tm_mon+1, time_detay->tm_year+1900);
	printf("Saat : %.2d:%.2d\n\n", time_detay->tm_hour, time_detay->tm_min);
	for(i=0;i<50;i++){printf("_");} printf("\n");
	printf("\n\n    IÞIKLANDIRMA MENÜSÜ\n");
	for(i=0;i<50;i++){printf("_");} printf("\n");
	
	gun=time_detay->tm_mday;
	ay= time_detay->tm_mon+1;
	yil=time_detay->tm_year+1900;
	
	if(tatildosya==NULL){
		fclose(tatildosya);
		printf("Henüz Yönetici tarafýndan çalýþma günleri atanmadý.\nAVM Yönetimiyle iletiþime geçiniz.\n");
		sleep(3);
		AnaMenu();
	}
	else{
		fread(&Boyut,sizeof(Boyut),1,tatildosya);
		printf("[1] Iþýklandýrmayý belirlemek için\n[2] Çýkýþ yapmak için\nGiriniz: ");
		scanf("%d",&anasecim);
		if(anasecim==1){
			for(i=0;i<=Boyut.saatler.tatilsayisi;i++){
				if(Boyut.saatler.tatiller[i][0]==gun&&Boyut.saatler.tatiller[i][1]==ay&&Boyut.saatler.tatiller[i][2]==yil){ 
					Boyut.saatler.aydinlatmaderecesi=0;
					printf("AVM Tatil günündedir.\n");
					say=0;
				}
			}
			if(say!=0){
				do{
					printf("Maðazanýzýn ne kadar aydýnlatýlmasý istediðini giriniz (Yüzde): ");
					scanf("%d",&Boyut.saatler.aydinlatmaderecesi);	
					printf("\n\nMaðazanýnn aydýnlatmasý yüzde %d olarak ayarlanmýþtýr.\n\n", Boyut.saatler.aydinlatmaderecesi);
					fwrite(&Boyut,sizeof(Boyut),1,id);
					fclose(id);
					printf("[1] Aydýnlatmayý Deðiþtirmek için\n[2] Cýkýþ yapmak için\nGiriniz: ");
					scanf("%d",&secim);
				}
				while(secim==1);
				sleep(2);
				YonetimAnasayfa();
			}
		}
		else if(anasecim=2){
			Boyut.saatler.aydinlatmaderecesi=0;
			printf("Yönetim sayfasýna yönlnediriliyorsunuz...\n\n");
			sleep(2);
			fwrite(&Boyut,sizeof(Boyut),1,id);
			fclose(id);
			YonetimAnasayfa();
		}
	}
	fclose(tatildosya);
}
	
void MagazaYapilandirma(){
	system("cls");
	FILE *yapidosya=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Magazalar\\magazayapilandirma.txt","w+");
	int i, n;
	for(i=0;i<100;i++){printf("_");}printf("\n");
	printf("\n      MAÐAZA YAPILANDIRMA SAYFASI \n");
	for(i=0;i<100;i++){printf("_");}printf("\n");
	printf("AVM'deki magazalardaki boyut tip sayisi\n(AVM'de bulunan magaza boyutlarinin kac farkli tipte oldugunun sayisi)\nGiriniz: ");
	scanf("%d",&Boyut.Yapi.tipadet);
		Boyut.Yapi.boyut=(int *)malloc(sizeof(int)*Boyut.Yapi.tipadet[0]);	
	
	back:	
	for(n=0;n<Boyut.Yapi.tipadet[0];n++){
		printf("%d. maðaza metrekare boyudunu giriniz: ",n+1);
		scanf("%d",&Boyut.Yapi.boyut[n]);
		if(Boyut.Yapi.boyut[n]>1000){
			printf("Üst Limiti Aþtýnýz.\nMetrekare Giriþ Ekranýna Yeniden Yönlendiriliyorsunuz.\n\n");
			goto back;}
		printf("  %d metrekarelik magazanýn adet sayýsýný girin: ",Boyut.Yapi.boyut[n]);
		scanf("%d",&Boyut.Yapi.magazasayisi[n]);}
	
	printf("\n\n");
	fwrite(&Boyut,sizeof(Boyut),1,yapidosya);
	fclose(yapidosya);
	printf("\nYapýlandýrma iþleminiz baþarýyla tamamlanmýþtýr\n");
	sleep(2);
	YonetimAnasayfa();
}
void MagazaKayit(){
	system("cls");
	int i;
	for(i=0;i<100;i++){printf("_");}printf("\n");
	printf("       MAÐAZA KAYIT MENÜSÜ\n");
	for(i=0;i<100;i++){printf("_");}printf("\n");
	a:
	printf("Maðazanýza Kimlik Giriniz\n(Maðaza kimliði oluþtururken ingilizce harfler kullanýnýz)\nKimlik Oluþturunuz: ");
	scanf("%s",Boyut.Magazakimlik);
	strcat(Boyut.Magazakimlik,".txt");
	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Magazalar\\";
	strcat(dosyauzantisi,Boyut.Magazakimlik);
	FILE *magaza = fopen(dosyauzantisi,"r");
	if(magaza==NULL){
		fclose(magaza);
		magaza=fopen(dosyauzantisi,"w");
		
		printf("Maðazanýz oluþturulmuþtur. Bilgilerinizi %s dosyasýndan ulaþabilirsiniz.\n\nMagaza Kiralama Menüsüne Yönlendiriliyorsunuz...\n\n",Boyut.Magazakimlik);
		sleep(2);
		fwrite(&Boyut,sizeof(Boyut),1,magaza);
		fclose(magaza);
		MagazaKiralama();
		printf("\nMaðaza Kayýtlanma Ýþlemleriniz baþarýyla tamamlanmýþtýr.\n");
		sleep(2);
		YonetimAnasayfa();}
	else{
		printf("Ayný Magaza Kimliðinden Bulunmaktadýr.\nYeni bir kimlik için tekrar yönlendiriliyorsunuz..\n\n");
		sleep(1);
		goto a;
	}
}
    
void MagazaKiralama(){
	system("cls");
	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Magazalar\\";
	strcat(dosyauzantisi,Boyut.Magazakimlik);
	FILE *magaza=fopen(dosyauzantisi,"wb+");
	FILE *yapidosya=fopen("C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Magazalar\\magazayapilandirma.txt","r");
	if(yapidosya==NULL){
		printf("\nMaðaza Yapýlandýrmasý yapýlmamýþtýr. Yönetim ile iletiþime geçiniz!\n\n");
		fclose(magaza);
		sleep(2);
		AnaMenu();}
	else{
		float elektrik,su,dogalgaz;
		int yonlendirici, i, m, say,s, cevap;
		float kira,toplam,alan;
		for(i=0;i<100;i++){printf("_");}printf("\n");
		printf("                 MAÐAZA KÝRALAMA MENÜSÜ\n");
		for(i=0;i<100;i++){printf("_");}printf("\n");
		while(fread(&Boyut,sizeof(Boyut),1,yapidosya)==1){
			printf("Maðaza Adýný Giriniz: ");
		fflush(stdin);
		gets(Boyut.Magazaisim);
		printf("Maðazanýn çalýþma sektörünü girin: ");
		fflush(stdin);
		gets(Boyut.Sektor);
		printf("\n\n");
			for(s=0;s<Boyut.Yapi.tipadet[0];s++){
				printf("%d metrekarelik maðaza seçimi için [%d]\n",Boyut.Yapi.boyut[s],s);
			}
		}
		in:
		printf("Ýstediðiniz maðaza boyut seçimini giriniz: ");
		scanf("%d",&s);
		if(Boyut.Yapi.boyut[s]<=1000){
			if(Boyut.Yapi.boyut[s]<45){
				alan=Boyut.Yapi.boyut[s];
				kira=alan;							
				kira*=138.5;}	
			else if(45<=Boyut.Yapi.boyut[s]&&Boyut.Yapi.boyut[s]<400){
				alan=Boyut.Yapi.boyut[s];
				kira=alan;				
				kira*=200;}		
			else{
				alan=Boyut.Yapi.boyut[s];
				kira=alan;				
				kira*=273.5;}
			
			elektrik=alan*1.92;
			su=alan*2.53;
			dogalgaz=alan*2.98;
			toplam=kira+dogalgaz+elektrik+su+dogalgaz;
	
			if(Boyut.Yapi.magazasayisi[s]==0){
				printf("Þu anda mevcut boyuttaki magazalar doludur.\nTekrar seçim yapmak için [1]\nAna menüye dönmek için [2]");
				scanf("%d",&cevap);
				if(cevap==1){
					printf("\n");
					goto in;}
				else{
					goto tb;}
			}
			else{
				printf("\n%.f metrekarelik alan tahsis edilebilir.\n",alan);
				printf("Maðazanýzýn Aylýk Kira Bedeli: %.2f\n",kira);
				printf("Þu anda bulunan maðaza: %d adet\n\n",Boyut.Yapi.magazasayisi[s]);
				printf("Dogalgaz Tutarý: %.2f\n",dogalgaz);
				printf("Elektrik Tutarý: %.2f\n",elektrik);
				printf("Su Tutarý: %.2f\n\n",su);
				printf("Toplam Gider: %.2f\n\n",toplam);
	
				printf("\n[1] Maðazayý Kiralamak\n[2] Kiralama Menüsüne Dönmek\n[3] Maðaza Menüsüne Dönmek\nÝþleminizi Giriniz: ");
 				scanf("%d",&cevap);
 				if(cevap==1){
 					Boyut.Gider.Kira=kira;
 					Boyut.Gider.alan=alan;
 					Boyut.Gider.Fatura.Elektrik=elektrik;
 					Boyut.Gider.Fatura.Su=su;
 					Boyut.Gider.Fatura.Dogalgaz=dogalgaz;
 					Boyut.Gider.Toplam=toplam;
					printf("%.f metrekarelik maðazanýz %.3f kira bedeliyle tahsis edilmiþtir.\n",Boyut.Gider.alan,Boyut.Gider.Kira);
					Boyut.Yapi.magazasayisi[s]-=1;
					say=1;		
					fwrite(&Boyut,sizeof(Boyut),1,magaza);
					fclose(magaza);
					printf("[1] Ana Menüye Dönmek için\n[2] Yönetim Menüsüne Dönmek için\nGiriniz: ");
					scanf("%d",&yonlendirici);
					if(yonlendirici==1){
						AnaMenu();
					}
					else if(yonlendirici==1){
						YonetimAnasayfa();
					}
				}
				else if(cevap==2){
					tb:
					printf("\n");
					say=0;
					goto in;	
				}
				else{
					if(say==1){
						printf("%.f metrekarelik alan kiralanmýþtýr.\n",Boyut.Gider.alan);
						printf("Kira Bedeli: %.3f",Boyut.Gider.Kira);
					}
					else{
						Boyut.Gider.Kira=0;
						Boyut.Gider.Toplam=0;
						Boyut.Gider.Fatura.Dogalgaz=0;
						Boyut.Gider.Fatura.Elektrik=0;
 						Boyut.Gider.Fatura.Su=0;
					}
				}
			}
		}
	}
	printf("\nKayýtlanma Menüsünden Çýkýyorsunuz...\n");
	fclose(yapidosya);
}

void MagazayiGoster(){
	system("cls");
	int i;
	for(i=0;i<100;i++){printf("_");}printf("\n");
	printf("  MAÐAZA BÝLGÝLERÝ GÖRÜNTÜLEME SAYFASI\n");
	for(i=0;i<100;i++){printf("_");}printf("\n");
	int secim,arasecim;
	b:
	printf("\nMaðaza Kimliðinizi Giriniz: ");
	scanf("%s",Boyut.Magazakimlik);
	strcat(Boyut.Magazakimlik,".txt");
	char dosyauzantisi[100]="C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Magazalar\\";
	strcat(dosyauzantisi,Boyut.Magazakimlik);
	FILE *magaza = fopen(dosyauzantisi,"r");
	FILE *id=fopen(dosyauzantisi,"r");
	FILE *tatildosya=fopen("tatiller.txt","r");
	if(magaza==NULL){
		fclose(magaza);
		printf("\n\nMaðaza kimlik numarasý geçersizdir.\n\n[1] Maðaza Kayýt Menüsü\n[2] Tekrar Giriþ Yapma\n[3] Ana Menüye Dönmek\nGiriniz: ");
		scanf("%d",&secim);
		if(secim==1){
			MagazaKayit();}
		else if(secim==2){
			goto b;}
		else{
			AnaMenu();}
	}
	else{
		if(fread(&Boyut,sizeof(Boyut),1,magaza)==1){
		printf("\n\nHoþgeldiniz!\n");
		x:
		for(i=0;i<100;i++){printf("_");}printf("\n");
		printf("[1] Maðazanýzýn Gider Kayýtlarýný Görme\n[2] Iþýklandýrma Ayarlarý\n[3] Maðaza Deðiþikliði\nGiriniz: ");
		scanf("%d",&secim);
			switch(secim){
				case 1:
					if(Boyut.Gider.alan>0){
						printf("\n\n");
						printf("MAÐAZA ADI: %s\n",Boyut.Magazaisim);
						printf("MAÐAZA SEKTÖRÜ: %s\n",Boyut.Sektor);
						for(i=0;i<80;i++){printf("_");}printf("\n");
						printf("GÝDERLER:\n");
						printf("Maðaza boyutu: %.f\n",Boyut.Gider.alan);
						printf("Maðaza kirasý: %.2f\n",Boyut.Gider.Kira);
						printf("Doðalgaz Tutarý: %.2f\n",Boyut.Gider.Fatura.Dogalgaz);
						printf("Elektrik Tutarý: %.2f\n",Boyut.Gider.Fatura.Elektrik);
						printf("Su Tutarý: %.2f\n\n",Boyut.Gider.Fatura.Su);
						printf("Toplam Gider: %.2f\n\n",Boyut.Gider.Toplam);
						fclose(magaza);
						printf("[1] Geri dönmek için\n[2] Ana Menüye Çýkmak için\nGiriniz: ");
						scanf("%d",&arasecim);
						if(arasecim==1) goto x;
						else if(arasecim) AnaMenu();}
					else{
						printf("\nKaydýnýz oluþturulmuþtur fakat mevcut bir maðazanýz bulunmamaktadýr\nMaðaza Kiralama menüsüne yönlendiriliyorsunuz...\n");
						fclose(magaza);
						sleep(3);
						MagazaKiralama();}
					break;
				case 2:
					if(id==NULL){
						printf("\nHenüz tarafýnýzdan ýþýklandýrmanýz belirlenmemiþtir.\nIþýklandýrma Menüsüne Yönlendiriliyorsunuz...\n\n");
						fclose(magaza);
						sleep(1);
						isiklandirma();}
					else{
						fread(&Boyut,sizeof(Boyut),1,id);
						if(Boyut.saatler.aydinlatmaderecesi>0){
							printf("\nMaðazanýn aydýnlatmasý yüzde %d olarak ayarlanmýþtýr.\n\n",Boyut.saatler.aydinlatmaderecesi);
							for(i=0;i<100;i++){printf("_");}printf("\n");
							printf("[1] Deðiþiklik için\n[2] Çýkýþ yapmak için\nGiriniz: ");
							scanf("%d",&secim);
								if(secim==1){
									fclose(magaza);
									isiklandirma();}
							}
						else{
							printf("Maðaza kapalýdýr.\n[1] Açýlýþ için\n[2] Çýkýþ yapmak için\nGiriniz: ");
							scanf("%d",&secim);
								if(secim==1){
									fclose(magaza);
									isiklandirma();}
						}
					}	
					break;
				case 3:
					remove(dosyauzantisi);
					FILE *magaza = fopen(dosyauzantisi,"w");
					MagazaKiralama();
					fwrite(&Boyut,sizeof(Boyut),1,magaza);
					fclose(magaza);
					YonetimAnasayfa();
				break;
			}
		}
		else{
			printf("\nMevcut kaydýnýz iþleme geçirilememiþtir.\n[1] Ana Menüye Dönme\n[2] Kiralama Menüsü\n Giriniz:");
			scanf("%d",&secim);
			if(secim==1)
				AnaMenu();
			else if(secim==2)
				fclose(magaza);
				MagazaKayit();	
		}
		fclose(magaza);
	}
}
void MagazaMenu(){
	system("cls");
	FILE *yapidosya=fopen("magazayapilandirma.txt","r");
	int secim, arasecim, i;
	
	for(i=0;i<100;i++){printf("_");}printf("\n");
	printf("\n           MAÐAZA MENÜSÜ\n");
	for(i=0;i<100;i++){printf("_");}printf("\n");
	b:
	printf("[1] Maðaza görüntüleme\n[2] Maðaza Kaydý Oluþturma\n[3] Ana Menüye Dönme\n");
	for(i=0;i<100;i++){printf("_");}printf("\n");
	printf("Giriniz: ");
	scanf("%d",&secim);
	switch(secim){
		case 1:
			MagazayiGoster();
			break;
		case 2:
			if(yapidosya==NULL){
				printf("Henüz yönetici tarafýndan maðaza yapýlandýrýlmasý oluþturulmamýþtýr.\nAVM Yönetimiyle iletiþime geçiniz.\n");
				sleep(1);
				AnaMenu();}
			else{
				MagazaKayit();}
			break;
		case 3:
			AnaMenu();
			break;
		default:
			printf("Uygun Deðer Girmediniz.\nAna Menüye Yönlendiriliyorsunuz...\n");
			sleep(2);
			MagazaMenu();
		}
	fclose(yapidosya);
}

void puanGirdi(){
	int v=0,i;
	char dosyauzantisi[100];
	char kullaniciKont[100];
	FILE *dd;
	m:
	system("cls");
	for(i=0;i<100;i++){printf("_");}printf("\n");
	printf("        PUAN GÜNCELLEME EKRANI\n");
	for(i=0;i<100;i++){printf("_");}printf("\n");
	printf("[1] Müþteri Puaný\n[2] Personel Puaný\nGiriniz: ");
	scanf("%d",&v);
	if(v==1){
		printf("\nMüþterinin Kullanýcý Adýný Girin: ");
		scanf("%s",kullaniciKont);
		strcat(kullaniciKont,".txt");
		strcpy(dosyauzantisi,"C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Musteriler\\");
		strcat(dosyauzantisi,kullaniciKont);
		fflush(stdin);
		dd=fopen(dosyauzantisi,"r+");
		fseek(dd,6*sizeof(cust),SEEK_SET);
		printf("Puan yazýnýz: ");
		scanf("%s",&cust.IndirimKarti.Puan);
		fwrite(&cust,sizeof(cust),1,dd);
		fclose(dd);
		fflush(stdin);
	}
	else if(v==2){
		printf("\nPersonelin Kullanýcý Adýný Girin: ");
		scanf("%s",kullaniciKont);
		strcat(kullaniciKont,".txt");
		strcpy(dosyauzantisi,"C:\\Users\\ÞEYMA\\Desktop\\AVM-Otomasyon-Projesi\\AVM\\Personeller\\");
		strcat(dosyauzantisi,kullaniciKont);
		fflush(stdin);
		dd=fopen(dosyauzantisi,"r+");
		fseek(dd,sizeof(per)*16,SEEK_SET);
		printf("Puan yazýnýz: ");
		scanf("%d",&per.IndirimKarti.Puan);
		fwrite(&per,sizeof(per),1,dd);
		fclose(dd);
		fflush(stdin);	
	}
	else{
		printf("Hatalý Girdiniz");
		v=0;
		goto m;
	}
	printf("\n\nÇýkmak için E, yeniden bakmak için H giriniz: ");
	fflush(stdin);
	if(toupper(getch())== 'H'){
		printf("\n\n");
		puanGirdi();
	}
	else if(toupper(getch())== 'E'){
		printf("\n\n");
		YonetimAnasayfa();
	}
}
