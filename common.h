#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Platform Detection / Platform Tespiti
#ifdef _WIN32
    #include <windows.h>
    #define PLATFORM_WINDOWS
#else
    #include <strings.h>
    #define PLATFORM_UNIX
    #define stricmp strcasecmp
#endif

#define MAKSIMUM 1000

// Color Codes / Renk Kodlari
#ifdef PLATFORM_WINDOWS
    #define RENK_HATA 12
    #define RENK_UYARI 14
    #define RENK_BASARI 10
    #define RENK_BILGI 11
    #define RENK_VARSAYILAN 7
#else
    // ANSI Escape Codes for Linux/macOS
    #define ANSI_RED     "\x1b[31m"
    #define ANSI_GREEN   "\x1b[32m"
    #define ANSI_YELLOW  "\x1b[33m"
    #define ANSI_CYAN    "\x1b[36m"
    #define ANSI_RESET   "\x1b[0m"
    
    #define RENK_HATA 1
    #define RENK_UYARI 2
    #define RENK_BASARI 3
    #define RENK_BILGI 4
    #define RENK_VARSAYILAN 0
#endif

#endif
