# GSM Subscriber Tracking System / GSM Abone Takip Sistemi

A modular C-based system for managing and analyzing GSM subscriber data.
GSM abone verilerini yönetmek ve analiz etmek için modüler C tabanlı takip sistemi.

## 🚀 Features / Özellikler
- **Modular Architecture / Modüler Mimari**: Clean separation of concerns (Models, Utils, Subscriber Management, Reporting). 
- **Cross-Platform / Çapraz Platform**: Works on Windows, Linux, and macOS (Bölge ve platform bağımsız çalışma).
- **Subscriber Operations / Abone İşlemleri**: Add, Delete, Edit, and Search subscribers.
- **Reporting & Analytics / Raporlama ve Analiz**: 
  - Operator transition reports (Yearly).
  - Subscriber loyalty analytics.
  - Package/Campaign usage statistics.
- **Pre-loaded Dataset / Hazır Veri Seti**: Includes 100 sample records for testing.

## 📁 Project Structure / Proje Yapısı
- `main.c`: Entry point / Giriş noktası.
- `models.c/h`: Data structures and dataset / Veri yapıları ve veri seti.
- `subs.c/h`: Subscriber logic / Abone mantığı.
- `reports.c/h`: Analysis logic / Analiz mantığı.
- `utils.c/h`: Helper functions & UI / Yardımcı fonksiyonlar ve arayüz.
- `common.h`: Global definitions / Global tanımlar.

## 🛠 Compilation / Derleme
To compile the project, use the provided `derle.bat` file (Windows) or use GCC:
Projeyi derlemek için `derle.bat` dosyasını (Windows) kullanabilir veya GCC ile manuel derleyebilirsiniz:

```bash
# Manual compilation / Manuel derleme
gcc *.c -o gsm_system
./gsm_system
```

## 📜 License / Lisans
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
Bu proje MIT Lisansı ile lisanslanmıştır - detaylar için [LICENSE](LICENSE) dosyasına göz atın.

## 👨‍💻 Author / Geliştirici
**Yiğit Mehmet ALTUNDERE**

---
*Developed as a professional portfolio project.*
*Profesyonel portfolyo projesi olarak geliştirilmiştir.*
