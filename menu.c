#include "menu.h"
#include "common.h"
#include "utils.h"
#include "subs.h"
#include "reports.h"

// Subscriber Management Menu / Abone Yonetim Menusu
void veriMenu() {
    int tercih;
    do {
        boya(RENK_UYARI);
        printf("\nSUBSCRIBER OPERATIONS / KAYIT ISLEMLERI\n");
        boya(RENK_VARSAYILAN);
        printf("1. Add / Ekle\n2. Delete / Sil\n3. Edit / Duzenle\n4. Search / Ara\n0. Back / Don\nChoice: ");
        scanf("%d", &tercih);
        bufferSil();
        
        if(tercih == 1) ekle();
        else if(tercih == 2) sil();
        else if(tercih == 3) duzenle();
        else if(tercih == 4) ara();
    } while(tercih != 0);
}

// Reports & Analysis Menu / Rapor ve Analiz Menusu
void raporMenu() {
    int tercih;
    do {
        boya(RENK_UYARI);
        printf("\nREPORTS & ANALYTICS / RAPORLAR\n");
        boya(RENK_VARSAYILAN);
        printf("1. Transitions / Gecisler\n2. Loyalty / Sadakat\n3. Packages / Paketler\n0. Back / Don\nChoice: ");
        scanf("%d", &tercih);
        bufferSil();
        
        if(tercih == 1) gecisRapor();
        else if(tercih == 2) sadiklar();
        else if(tercih == 3) paketStat();
    } while(tercih != 0);
}
