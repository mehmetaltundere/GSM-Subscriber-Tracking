@echo off
echo GSM Takip Sistemi Derleniyor...
gcc *.c -o gsm_sistemi.exe
if %ERRORLEVEL% EQU 0 (
    echo Derleme basarili! Calistiriliyor...
    gsm_sistemi.exe
) else (
    echo Derleme hatasi olustu! Lutfen GCC yuklu oldugundan emin olun.
    pause
)
