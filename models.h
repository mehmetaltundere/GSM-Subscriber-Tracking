#ifndef MODELS_H
#define MODELS_H

typedef struct { 
    int gun; 
    int ay; 
    int yil; 
} date;

typedef struct {
    char tc_no[12];
    char isim[20];
    char soyisim[30];
    char yas[4];
    char adres[100];
    char tel_no[15];
    date ilk_tarih;
    char op_ad[15];
    date tarife_bas;
    date tarife_son;
    char kampanya[30];
    char eski_op1[15];
    date op1_baslangic;
    date op1_bitis;
    char eski_op2[15];
    date op2_baslangic;
    date op2_bitis;
} abone;

extern abone kisiler[];
extern int kayitAdet;

#endif
