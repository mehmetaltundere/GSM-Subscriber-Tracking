#include "subs.h"
#include "common.h"
#include "utils.h"

// Count total records in the dataset / Veri setindeki toplam kayit sayisini hesaplar
void say() {
    int s;
    kayitAdet = 0;
    for(s=0; s<MAKSIMUM; s++) {
        if(kisiler[s].tc_no[0] != '\0') kayitAdet++;
        else break;
    }
}

// Search by ID / TC No ile abone bulur
int tcBul(char no[]) {
    int k;
    for(k=0; k<kayitAdet; k++) {
        if(strcmp(kisiler[k].tc_no, no) == 0) return k;
    }
    return -1;
}

// Search by Phone / Telefon No ile abone bulur
int telBul(char no[]) {
    int k;
    for(k=0; k<kayitAdet; k++) {
        if(strcmp(kisiler[k].tel_no, no) == 0) return k;
    }
    return -1;
}

// Display subscriber details / Abone detaylarini gosterir
void detay(int y) {
    boya(RENK_BILGI);
    printf("TC No: %s\n", kisiler[y].tc_no);
    boya(RENK_VARSAYILAN);
    printf("Name/Ad: %s %s\n", kisiler[y].isim, kisiler[y].soyisim);
    printf("Age/Yas: %s\n", kisiler[y].yas);
    printf("Address/Adres: %s\n", kisiler[y].adres);
    printf("Phone/Tel: %s\n", kisiler[y].tel_no);
    printf("Reg. Date/Kayit: %d/%d/%d\n", kisiler[y].ilk_tarih.gun, kisiler[y].ilk_tarih.ay, kisiler[y].ilk_tarih.yil);
    boya(RENK_BASARI);
    printf("Operator: %s\n", kisiler[y].op_ad);
    boya(RENK_VARSAYILAN);
    printf("Campaign/Paket: %s\n", kisiler[y].kampanya);
}

// Add new subscriber / Yeni abone kaydi ekler
void ekle() {
    boya(RENK_UYARI);
    printf("\n=== ADD NEW SUBSCRIBER / YENI KAYIT ===\n");
    boya(RENK_VARSAYILAN);
    
    if(kayitAdet >= MAKSIMUM) {
        printf("Hata: Sistem dolu! / Error: System full!\n");
        return;
    }
    
    // Implementation with validations... / Dogrulamali uygulama...
    // (Existing logic kept with bilingual prompts)
    while(1) {
        char tcTemp[20];
        printf("TC No (11 digits): ");
        fgets(tcTemp, 20, stdin);
        duzelt(tcTemp);
        bufferSil();
        
        if(rakamMi(tcTemp) != 0 || strlen(tcTemp) != 11) {
            boya(RENK_HATA); printf("Hata: 11 Rakam giriniz! / Error: Enter 11 digits!\n"); boya(RENK_VARSAYILAN);
            continue;
        }
        if(tcBul(tcTemp) != -1) {
            boya(RENK_HATA); printf("Kayit mevcut! / Record exists!\n"); boya(RENK_VARSAYILAN);
            continue;
        }
        strcpy(kisiler[kayitAdet].tc_no, tcTemp);
        break;
    }
    
    printf("Name/Ad: "); fgets(kisiler[kayitAdet].isim, 20, stdin); duzelt(kisiler[kayitAdet].isim);
    printf("Surname/Soyad: "); fgets(kisiler[kayitAdet].soyisim, 30, stdin); duzelt(kisiler[kayitAdet].soyisim);
    printf("Age/Yas: "); scanf("%s", kisiler[kayitAdet].yas); bufferSil();
    printf("Address/Adres: "); fgets(kisiler[kayitAdet].adres, 100, stdin); duzelt(kisiler[kayitAdet].adres);
    
    // Operator and Date info...
    printf("Operator: "); fgets(kisiler[kayitAdet].op_ad, 15, stdin); duzelt(kisiler[kayitAdet].op_ad);
    printf("Phone/Tel: "); fgets(kisiler[kayitAdet].tel_no, 15, stdin); duzelt(kisiler[kayitAdet].tel_no);
    
    printf("Start Date/Baslangic (D M Y): ");
    scanf("%d %d %d", &kisiler[kayitAdet].tarife_bas.gun, &kisiler[kayitAdet].tarife_bas.ay, &kisiler[kayitAdet].tarife_bas.yil);
    bufferSil();
    
    kayitAdet++;
    boya(RENK_BASARI);
    printf("\nRecord added! / Kayit eklendi! (%d)\n", kayitAdet);
    boya(RENK_VARSAYILAN);
}

// Delete record / Kayit silme
void sil() {
    char kimlik[12];
    int konum, x;
    boya(RENK_UYARI);
    printf("\n=== DELETE RECORD / KAYIT SIL ===\n");
    boya(RENK_VARSAYILAN);
    
    printf("TC No to delete: "); scanf("%s", kimlik); bufferSil();
    
    konum = tcBul(kimlik);
    if(konum == -1) {
        printf("Bulunamadi / Not found.\n");
        return;
    }
    
    detay(konum);
    if(sorEH("Confirm delete? / Silmeyi onayla?")) {
        for(x = konum; x < kayitAdet - 1; x++) kisiler[x] = kisiler[x+1];
        kayitAdet--;
        printf("Deleted / Silindi.\n");
    }
}

// Edit existing record / Bilgi guncelleme
void duzenle() {
    char numara[15];
    int konum, islem;
    boya(RENK_UYARI);
    printf("\n=== EDIT RECORD / DUZENLE ===\n");
    boya(RENK_VARSAYILAN);
    
    printf("Phone No: "); fgets(numara, 15, stdin); duzelt(numara); bufferSil();
    
    konum = telBul(numara);
    if(konum == -1) {
        printf("Not found / Bulunamadi.\n");
        return;
    }
    
    detay(konum);
    printf("\n1. Address / Adres\n2. Operator\n3. Package / Paket\nChoice: ");
    scanf("%d", &islem); bufferSil();
    
    if(islem == 1) {
        printf("New Address: "); fgets(kisiler[konum].adres, 100, stdin); duzelt(kisiler[konum].adres);
    } else if(islem == 2) {
        printf("New Operator: "); fgets(kisiler[konum].op_ad, 15, stdin); duzelt(kisiler[konum].op_ad);
    }
    
    printf("Updated! / Guncellendi!\n");
}

// Search for subscribers / Abone arama
void ara() {
    int islem, k;
    char aranan[30];
    int sonuc = 0;
    boya(RENK_UYARI);
    printf("\n=== SEARCH / ARAMA ===\n");
    boya(RENK_VARSAYILAN);
    
    printf("1. ID Search / TC ile Ara\n2. Name Search / Isimle Ara\nChoice: ");
    scanf("%d", &islem); bufferSil();
    
    if(islem == 1) {
        printf("ID/TC: "); scanf("%s", aranan); bufferSil();
        for(k=0; k<kayitAdet; k++) {
            if(strcmp(kisiler[k].tc_no, aranan) == 0) { 
                detay(k); sonuc = 1; break; 
            }
        }
    } else if(islem == 2) {
        printf("Name/Isim: "); fgets(aranan, 30, stdin); duzelt(aranan);
        for(k=0; k<kayitAdet; k++) {
            if(stricmp(kisiler[k].isim, aranan) == 0 || stricmp(kisiler[k].soyisim, aranan) == 0) {
                detay(k); sonuc = 1;
            }
        }
    }
    if(!sonuc) printf("Aranan bulunamadi / Not found.\n");
}
