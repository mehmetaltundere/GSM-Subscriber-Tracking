#include "utils.h"
#include "common.h"

// Colorize console output / Konsol ciktisini renklendirir
void boya(int d) {
#ifdef PLATFORM_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), d);
#else
    switch(d) {
        case RENK_HATA:   printf(ANSI_RED); break;
        case RENK_BASARI: printf(ANSI_GREEN); break;
        case RENK_UYARI:  printf(ANSI_YELLOW); break;
        case RENK_BILGI:  printf(ANSI_CYAN); break;
        default:          printf(ANSI_RESET); break;
    }
#endif
}

// Clear console / Ekranı temizler
void temizle() {
#ifdef PLATFORM_WINDOWS
    system("cls");
#else
    system("clear");
#endif
}

// Clear input buffer / Giris tamponunu temizler
void bufferSil() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Remove trailing newline / Satir sonu karakterini temizler
void duzelt(char *m) {
    int b = strlen(m);
    if(b > 0 && m[b-1] == '\n') m[b-1] = '\0';
}

// Check if string contains only digits / String sadece rakam mi iceriyor?
int rakamMi(char *g) {
    int i;
    for(i = 0; g[i] != '\0'; i++) {
        if(!isdigit(g[i])) return 1;
    }
    return 0;
}

// Check if string contains only letters / String sadece harf mi iceriyor?
int harfMi(char *g) {
    int i;
    for(i = 0; g[i] != '\0'; i++) {
        if(!isalpha(g[i]) && g[i] != ' ') return 1;
    }
    return 0;
}

// Simple date validation / Basit tarih dogrulama
int tarihGecerliMi(int gun, int ay, int yil) {
    if(ay < 1 || ay > 12) return 0;
    if(yil < 1900 || yil > 2100) return 0;
    if(gun < 1) return 0;
    
    int gunler[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(ay == 2 && gun == 29) {
        // Leap year check / Artik yil kontrolu
        if((yil % 4 == 0 && yil % 100 != 0) || (yil % 400 == 0)) return 1;
        return 0;
    }
    
    if(gun > gunler[ay-1]) return 0;
    return 1;
}

// Compare two dates / İki tarihi karsilastirir
int tarihKucukMu(int g1, int a1, int y1, int g2, int a2, int y2) {
    if(y1 != y2) return (y1 < y2);
    if(a1 != a2) return (a1 < a2);
    return (g1 < g2);
}

// Get yes/no input / Evet/Hayir sorusu sorar
int sorEH(char *s) {
    char c[10];
    while(1) {
        printf("%s (evet/hayir - yes/no): ", s);
        fgets(c, 10, stdin);
        duzelt(c);
        if(stricmp(c, "evet") == 0 || stricmp(c, "yes") == 0) return 1;
        if(stricmp(c, "hayir") == 0 || stricmp(c, "no") == 0) return 0;
        boya(RENK_HATA);
        printf("Gecersiz cevap! / Invalid answer!\n");
        boya(RENK_VARSAYILAN);
    }
}
