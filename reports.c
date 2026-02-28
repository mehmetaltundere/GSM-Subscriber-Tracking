#include "reports.h"
#include "common.h"
#include "models.h"
#include "utils.h"

// Operator transition report / Operatör gecis raporu
void gecisRapor() {
    int sene, k;
    int bulunan = 0;
    
    printf("Report Year / Rapor Yili (e.g. 2024): ");
    scanf("%d", &sene);
    bufferSil();
    
    boya(RENK_BILGI);
    printf("\n=== %d OPERATOR TRANSITIONS / GECISLER ===\n", sene);
    boya(RENK_VARSAYILAN);
    
    for(k=0; k<kayitAdet; k++) {
        if(strlen(kisiler[k].eski_op1) > 1 && strcmp(kisiler[k].eski_op1, "Yok") != 0 && kisiler[k].op1_bitis.yil == sene) {
            printf("%s %s: %s --> %s\n", 
                kisiler[k].isim, kisiler[k].soyisim, kisiler[k].eski_op1, kisiler[k].op_ad);
            bulunan++;
        }
    }
    if(bulunan == 0) printf("No transitions found / Kayit bulunamadi.\n");
}

// Loyalty analysis / Sadakat analizi
void sadiklar() {
    int k, m;
    char firmalar[50][15];
    int toplamlar[50] = {0};
    int firmaSayisi = 0;
    
    boya(RENK_BILGI);
    printf("\n=== LOYALTY REPORT / SADAKAT ANALIZI ===\n");
    boya(RENK_VARSAYILAN);
    
    // Find subscribers who never changed operator / Hiç operatör degistirmeyenleri bul
    for(k=0; k<kayitAdet; k++) {
        if(kisiler[k].eski_op1[0] == '\0' || strcmp(kisiler[k].eski_op1, "Yok") == 0) {
            int mevcutMu = 0;
            for(m=0; m<firmaSayisi; m++) {
                if(strcmp(firmalar[m], kisiler[k].op_ad) == 0) {
                    toplamlar[m]++;
                    mevcutMu = 1;
                    break;
                }
            }
            if(!mevcutMu && firmaSayisi < 50) {
                strcpy(firmalar[firmaSayisi], kisiler[k].op_ad);
                toplamlar[firmaSayisi] = 1;
                firmaSayisi++;
            }
        }
    }
    
    for(k=0; k<firmaSayisi; k++) {
        printf("%-15s: %d Abone/Subscribers\n", firmalar[k], toplamlar[k]);
    }
}

// Package usage statistics / Paket kullanim istatistikleri
void paketStat() {
    char paketler[20][30];
    int kullanim[20] = {0};
    int paketSayisi = 0;
    int k, m;
    
    boya(RENK_BILGI);
    printf("\n--- PACKAGE STATS / PAKET ISTATISTIKLERI ---\n");
    boya(RENK_VARSAYILAN);
    
    for(k=0; k<kayitAdet; k++) {
        int mevcut = 0;
        for(m=0; m<paketSayisi; m++) {
            if(strcmp(paketler[m], kisiler[k].kampanya) == 0) {
                kullanim[m]++;
                mevcut = 1;
                break;
            }
        }
        if(!mevcut && paketSayisi < 20) {
            strcpy(paketler[paketSayisi], kisiler[k].kampanya);
            kullanim[paketSayisi] = 1;
            paketSayisi++;
        }
    }
    
    // Sort and display / Sirala ve goster
    for(k=0; k<paketSayisi; k++)
        printf("%d. %-20s : %d Users/Kullanici\n", k+1, paketler[k], kullanim[k]);
}
