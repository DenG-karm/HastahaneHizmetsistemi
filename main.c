#include <ctype.h>
#include <stdio.h>
#include <string.h>
struct hastahane {
    char name[50];
    char sehir[50];
    int yataklar;
    float fiyat;
    float puan;
    int yorumlar;
};
struct hasta{
    char name[50];
    int yas;
};
void hastahaneyazdır(struct hastahane hast) {
    printf("Hastahane ismi : %s\n",hast.name);
    printf("Sehir : %s\n",hast.sehir);
    printf("Toplam yatak sayisi : %d\n",hast.yataklar);
    printf("Yatak basi fiyat : %f\n",hast.fiyat);
    printf("Puan : %f\n",hast.puan);
    printf("Yorumlar : %d\n",hast.yorumlar);
    printf("\n");
}
void  fiyatagoresirala(struct hastahane hastahaneler[],int n) {
    for (int i = 0; i < n-1; i++  ) {
        for ( int j = 0; j<n-i-1; j++) {
            if (hastahaneler[j].fiyat > hastahaneler[j+1].fiyat) {
                struct hastahane temp = hastahaneler[j];
                hastahaneler[j] = hastahaneler[j+1];
                hastahaneler[j+1] = temp;
            }
        }
    }
}
void ismegoresirala(struct hastahane hastahaneler[],int n) {
    for (int i = 0; i < n-1; i++) {
        for ( int j = 0; j<n-i-1; j++) {
            if (strcmp(hastahaneler[j].name, hastahaneler[j+1].name) > 0) {
                struct hastahane temp = hastahaneler[j];
                hastahaneler[j] = hastahaneler[j+1];
                hastahaneler[j+1] = temp;
            }
        }
    }
}
void puanagoresirala(struct hastahane hastahaneler[],int n) {
    for (int i = 0; i < n-1; i++) {
        for ( int j = 0; j<n-i-1; j++) {
            if (hastahaneler[j].puan * hastahaneler[j].yorumlar < hastahaneler[j+1].puan * hastahaneler[j+1].yorumlar) {
                struct hastahane temp = hastahaneler[j];
                hastahaneler[j] = hastahaneler[j+1];
                hastahaneler[j+1] = temp;
            }
        }
    }
}
void sehiricihastahaneyazdır(struct hastahane hastahaneler[]) {
    char sehir[50];
    int hastahanebul=0;
    printf("Bir sehir ismi seciniz:(X,Y,Z)");
    scanf("%s",sehir);
    printf("Hastane %s sehrinin icindedir.",sehir);
    for (int i = 0; i<5; i++) {
        if (strcasecmp(hastahaneler[i].sehir, sehir) == 0) {
            printf("Hastahane  ismi == %s\n",hastahaneler[i].name);
            printf("Sehir == %s\n",hastahaneler[i].sehir);
            printf("Toplam yataklar == %d\n",hastahaneler[i].yataklar);
            printf("Yatak basi fiyat == %f\n",hastahaneler[i].fiyat);
            printf("Puan == %f\n",hastahaneler[i].puan);
            printf("Yorumlar == %d\n",hastahaneler[i].yorumlar);
            printf("\n");
            hastahanebul++;
        }
    }
    if (hastahanebul==0) {
        printf("\n%s sehrinde boyle bir hastahane bulunamadi..",sehir);
    }
}
void yataklaragoresirala(struct hastahane hastahaneler[],int n) {
    for (int i = 0; i < n-1; i++) {
        for ( int j = 0; j<n-i-1; j++) {
            if (hastahaneler[i].yataklar < hastahaneler[j+1].yataklar) {
                struct hastahane temp = hastahaneler[j];
                hastahaneler[j] = hastahaneler[j+1];
                hastahaneler[j+1] = temp;
            }
        }
    }
}
void hastaciz(struct hasta hasta) {
    printf("Hasta ismi : %s\n",hasta.name);
    printf("Hasta yasi :  %d\n",hasta.yas);
    printf("\n");
}
int main() {
    struct hastahane hastahaneler[5]
    ={ { "Hastahene A","Istanbul",100,250.0,4.5,100}
        ,{ "Hastahene B","Eskisehir",150,200.0,4.2,80}
        ,{ "Hastahene C","Corum",200,180.0,4.0,120}
        ,{ "Hastahene D","Izmir",80,300.0,4.8,90}
        ,{ "Hastahene E","Ankara",120,220.0,4.6,110}
    };
    struct hasta hastalar[5][3] = { { { "Eylul", 35 },
                                         { "Mehmet", 45 },
                                         { "Atakan", 28 } },
                                       { { "Recep", 62 },
                                         { "Aslı", 18 },
                                         { "Gulzade", 55 } },
                                       { { "Zafer", 50 },
                                         { "Rasim", 30 },
                                         { "Pelin", 40 } },
                                       { { "Ahmet", 22 },
                                         { "Aslan", 38 },
                                         { "Papatya", 60 } },
                                       { { "Ayca", 28 },
                                         { "Yagmur", 48 },
                                         { "Kadir", 33 } } };
    int n = 5;
    int secim;
    char sehir[50];
    do {
        printf("\n************HASTAHANE GIRIS SISTEMI************\n");
        printf("1.Hastahane verilerini goster\n");
        printf("2.Hastahane hasta verilerini goster\n");
        printf("3.Hastahane yatak fiyatlarina gore sirala\n");
        printf("4.Mevcut yatak sayisina gore sirala\n");
        printf("5.Hastahane isimlerine gore sirala\n");
        printf("6.Hastahane puanina ve yorumlarina gore sirala\n");
        printf("7.Belirli bir sehirde ki hastahaneleri sirala\n");
        printf("8.Cikis\n\n");
        printf("Lutfen seciminizi giriniz:");
        scanf("%d",&secim);
        switch (secim) {
            case 1:
                printf("Hastahane verileri yukleniyor:..\n\n");
            for (int i = 0; i<n; i++) {
                hastahaneyazdır(hastahaneler[i]);
            }
            break;
            case 2:
                printf("Hasta verileri yukleniyor:..\n\n");
            for (int i = 0; i<n; i++) {
                printf("Hastahane: %s\n",hastahaneler[i].name);
                for (int j = 0; j<3; j++) {
                    hastaciz(hastalar[i][j]);
                }
            }
            break;
            case 3:
                printf("Hastahaneler yatak fiyatlarina gore siralaniyor..\n\n");
            yataklaragoresirala(hastahaneler, n);
            for (int i = 0; i<n; i++) {
                hastahaneyazdır(hastahaneler[i]);
            }
            break;
            case 4:
                printf("Mevcut yatak sayisina gore hastahaneler siralaniyor..\n\n");
            yataklaragoresirala(hastahaneler, n);
            for (int i = 0; i<n; i++) {
                hastahaneyazdır(hastahaneler[i]);
            }
            break;
            case 5:
                printf("Hastahaneler isimlerine gore siralaniyor..\n\n");
            ismegoresirala(hastahaneler, n);
            for (int i = 0; i<n; i++) {
                hastahaneyazdır(hastahaneler[i]);
            }
            break;
            case 6:
                printf("Hastahaneler puan ve yorumlarina gore siralaniyor..\n\n");
            puanagoresirala(hastahaneler, n);
            for (int i = 0; i<n; i++) {
                hastahaneyazdır(hastahaneler[i]);
            }
            break;
            case 7:
                sehiricihastahaneyazdır(hastahaneler);
            break;
            case 8:
                printf("Programdan cikis yapiliyor..");
            break;
            default:
                printf("Gecersiz secim lutfen gecerli bir secim yapiniz..");
        }
    }while (secim != 8);
    return 0;
}