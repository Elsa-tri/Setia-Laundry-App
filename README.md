# Aplikasi Kasir Setia Laundry (CLI) 
Aplikasi kasir laundry berbasis Command Line Interface (CLI) yang dibangun 
menggunakan bahasa C++. Proyek ini dirancang untuk mendemonstrasikan penerapan 
penanganan input yang kokoh (robust input validation), pemrograman modular (fungsi), 
serta manipulasi string untuk format mata uang (Indonesia). 

## Fitur Utama 
 Validasi Input Angka: Mencegah aplikasi crash atau infinite loop jika pengguna salah 
memasukkan huruf pada input angka (Berat, Jumlah Pakaian, Menu). 
 Validasi Input Huruf: Otomatis mengubah input menjadi huruf kapital (`toupper`) dan 
membersihkan antrean memori (buffer flushing) jika pengguna mengetik teks terlalu 
panjang. 
 Format Ribuan Otomatis: Mengubah tampilan nominal uang mentah menjadi 
berformat titik ribuan standar Indonesia (misal: `35000` menjadi `35.000`). 
 Sistem Diskon & Layanan Spesial: Perhitungan otomatis untuk Member (Gold & Silver), 
Pelanggan Baru, serta penanganan batasan berat minimal untuk Layanan Spesial (Express 
& Kilat). 

## Teknologi yang Digunakan 
 Bahasa Pemrograman: C++ 
 Pustaka Standar: `<iostream>`, `<string>`, `<cctype>`, `<iomanip>`, `<sstream>`, `<algorithm>` 

##  Cara Menjalankan Proyek 
1. Clone repository ini atau unduh file `ApkLaundry.cpp`. 
2. Buka menggunakan IDE favoritmu (misal: Dev-C++, Code::Blocks, atau VS Code). 
3. Pastikan kompiler mendukung standar minimal C++11 atau gunakan pustaka 
`<sstream>` untuk fungsi `formatRibuan`. 
4. Compile dan Run programnya! 
