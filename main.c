#include "common.h"
#include "models.h"
#include "utils.h"
#include "subs.h"
#include "menu.h"

/* 
 * Main Entry Point / Ana Giris Noktasi 
 * GSM Subscriber Tracking System / GSM Abone Takip Sistemi
 */
int main() {
    int tercih;
    
    // Turkish localization / Turkce karakter destegi
    setlocale(LC_ALL, "Turkish");
    
    temizle(); // Clear screen / Ekran temizle
    say();     // Initial count / Acilistaki kayit sayimi
    
    boya(RENK_BASARI);
    printf("GSM Takip Sistemi Acildi. (%d Kayit)\n", kayitAdet);
    boya(RENK_VARSAYILAN);
    
    // Application Loop / Uygulama Dongusu
    do {
        boya(RENK_BILGI);
        printf("\nANA MENU / MAIN MENU\n");
        boya(RENK_VARSAYILAN);
        printf("1. Kayit Islemleri / Subscriber Operations\n");
        printf("2. Rapor Islemleri / Reporting Operations\n");
        printf("0. Cikis / Exit\n");
        printf("Secim / Choice: ");
        
        if(scanf("%d", &tercih) != 1) {
            bufferSil();
            continue;
        }
        bufferSil();
        
        if(tercih == 1) veriMenu();
        else if(tercih == 2) raporMenu();
        
    } while(tercih != 0);

    return 0;
}
