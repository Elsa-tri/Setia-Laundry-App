#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <algorithm>
#include <sstream>

using namespace std;

string formatRibuan(double nominal);
double validasiInputAngka(string teks);
char validasiInputHuruf(string teks);

int main(){
	
	int jumlahPakaian = 0, noJenisLayanan = 0, noLayananSpesial = 0;
	
	char antarJemput, pewangiPremium, member, pelangganBaru;
	
	string namaJenisLayanan, namaLayananSpesial, namaDiskon, teks;
	
	double berat = 0.0, hargaSatuan = 0.0, hargaPokok = 0.0, hargaLayananSpesial = 0.0, 
			hargaAntarJemput = 0.0, hargaPewangiPremium = 0.0, diskon = 0.0, 
			totalSebelumDiskon = 0.0, totalBayar = 0.0;
			
	bool invalid = false;
		
	cout << "===================================== Apk Laundry =====================================\n" <<endl;
	//Input Berat
	teks = "Berat (kg): ";
	do {
		berat = validasiInputAngka(teks);
		invalid = (berat <= 0);
		if(invalid) cout << "Input tidak valid!!\n";
	} while(invalid);
	cout << "_______________________________________________________________________________________\n" << endl;
	
	//Input Jumlah Pakaian
	teks = "Jumlah Pakaian (pcs): ";
	do{
		jumlahPakaian = (int)validasiInputAngka(teks);
		invalid = (jumlahPakaian <= 0);
		if(invalid) cout << "Input tidak valid!!\n";
	} while(invalid);
	cout << "_______________________________________________________________________________________\n" << endl;
	
	//Input Jenis Layanan
	cout << "[CK = 1 | CS = 2 | S = 3 | DC = 4 ]"<<endl;
	teks = "Jenis Layanan (1 - 4) : ";		
	do{
		noJenisLayanan = (int)validasiInputAngka(teks);
		invalid = (noJenisLayanan < 1 || noJenisLayanan > 4);
		if(invalid) cout << "Input tidak valid!!\n";
	  } while(invalid);
	cout << "_______________________________________________________________________________________\n" << endl;
	
	//Input Layanan Spesial
	cout << "[ Tidak = 0 | Express = 1 | Kilat = 2 ] "<<endl;
	teks = "Layanan spesial [ 0 | 1 | 2 ] : ";
	 do{
		noLayananSpesial = (int)validasiInputAngka(teks);
		invalid = (noLayananSpesial < 0 || noLayananSpesial > 2);
		
		if(invalid)	cout << "Input tidak valid!!\n";
		else
		{	
			invalid = (noLayananSpesial != 0 && berat < 3);
			if(invalid) cout << "!! Berat tidak sampai 3 kg !!\n";
		}
	} while(invalid);
	cout << "_______________________________________________________________________________________\n" << endl;
		
	//Input Antar-Jemput
	teks = "Antar-Jemput [ y | n ]: ";
	do{
		antarJemput = validasiInputHuruf(teks);
		invalid = (antarJemput != 'Y' && antarJemput != 'N');
	} while(invalid);
	cout << "_______________________________________________________________________________________\n" << endl;
		
	//Input Pewangi Premium
	teks = "Pewangi Premium [ y | n ]: ";
	do{
		pewangiPremium = validasiInputHuruf(teks);
		invalid = (pewangiPremium != 'Y' && pewangiPremium != 'N');
	} while(invalid);
	cout << "_______________________________________________________________________________________\n" << endl;
	
	//Input Member	
	teks = "Member [ S | G ] / [N = tidak] : ";	
	do{
		member = validasiInputHuruf(teks);
		invalid = (member != 'S' && member != 'G' && member != 'N');
	} while(invalid);
	cout << "_______________________________________________________________________________________\n" << endl;	
	
	//Input Pelanggan Baru
	teks = "Pelanggan Baru [ y | n ] :";
	do{
		pelangganBaru = validasiInputHuruf(teks);	
		invalid = (pelangganBaru != 'Y' && pelangganBaru != 'N');
	} while(invalid);	
	
	//Proses 		
	switch(noJenisLayanan){
		case 1: 
			namaJenisLayanan = "Cuci Kering";
			hargaSatuan = 8000;
			hargaPokok = hargaSatuan * berat; break;
		case 2:
			namaJenisLayanan = "Cuci Setrika";
			hargaSatuan = 12000;
			hargaPokok = hargaSatuan * berat; break;
		case 3:
			namaJenisLayanan = "Setrika";
			hargaSatuan = 5000;
			hargaPokok = hargaSatuan * berat;  break;
		case 4:
			namaJenisLayanan = "Dry Clean";
			hargaSatuan = 35000; 
			hargaPokok = hargaSatuan * jumlahPakaian; break;			
	}
	
		switch (noLayananSpesial){
			case 1:
				namaLayananSpesial = "Express";
				hargaLayananSpesial = hargaPokok * 80/100.0;
				break;
			case 2:
				namaLayananSpesial = "Kilat";
				hargaLayananSpesial = hargaPokok * 150/100.0;
				break;
			default :
				namaLayananSpesial = "Tidak Ada";
				hargaLayananSpesial = 0.0;
		}
		
		if(antarJemput == 'Y'){
			if(berat <= 10){
				hargaAntarJemput = 35000.0;
			}		
		}
		if(pewangiPremium == 'Y'){
			hargaPewangiPremium = berat * 3000.0;
		}
		
		//Hitung Total Sebelum Diskon
		totalSebelumDiskon = hargaPokok + hargaLayananSpesial + hargaAntarJemput + hargaPewangiPremium;
		
		//Hitung Diskon
		// IF Pelanggan Baru && Member --> Pilih Satu Diskon
		if(pelangganBaru == 'Y'){
			namaDiskon = "Pelanggan Baru";
			diskon = totalSebelumDiskon * 18 / 100.0;
		}
		else if(member == 'G'){
			namaDiskon ="Member Gold";
			diskon = totalSebelumDiskon * 10 / 100.0;
		}
		else if(member == 'S'){
			namaDiskon ="Member Silver";
			diskon = totalSebelumDiskon * 5 / 100.0;
		}
		//Hitung Total Setelah Diskon
		totalBayar = totalSebelumDiskon - diskon;
	
	//Tampilan Hasil
	cout << fixed << setprecision(0);	
	cout << endl;
	cout << "======================================================================================" << endl;
	cout << "                                     SETIA LAUNDRY                                    " << endl;
	cout << "======================================================================================" << endl << endl;
	cout << "Berat              : " << berat << " kg" <<endl<<endl;
	cout << "Jumlah Pakaian     : " << jumlahPakaian << " pcs" <<endl<<endl;
	cout << "Jenis Layanan      : " << namaJenisLayanan <<endl<<endl;
	cout << "Harga Pokok        : Rp" << formatRibuan(hargaPokok) <<endl<<endl;
	cout << "Layanan Spesial    : Rp" << formatRibuan(hargaLayananSpesial) 
								  << " (" << namaLayananSpesial << ")"<< endl<<endl;
	cout << "Pewangi Premium    : Rp" << formatRibuan(hargaPewangiPremium) <<endl<<endl;
	cout << "Antar-Jemput       : Rp" << formatRibuan(hargaAntarJemput) << endl<<endl;
	cout << "Pelanggan Baru     : " << pelangganBaru <<endl<<endl;
	cout << "Status Member      : " << member <<endl<<endl;
	cout << "Diskon             : Rp" << formatRibuan(diskon)
								<<  "  (Diskon " << namaDiskon << ")" << endl;
	cout << "\n======================================================================================\n";
	cout << "Total Bayar        : Rp" << formatRibuan(totalBayar) <<endl;
	cout << "=======================================================================================\n";
	return 0;
}

//Fungsi Validasi Input Angka
double validasiInputAngka(string teks){
	double input = 0.0;
	while(true){
		cout << teks;
		if(!(cin >> input)){
			cout << "Input harus berupa angka !!\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else { return input; }
	}
				
}
//Fungsi Validasi Input Huruf
char validasiInputHuruf (string teks){
	char input;
	cout << teks;
	cin >> input;	
	cin.ignore(10000, '\n');
	return toupper(input);
}
//Fungsi Format Nominal Uang
string formatRibuan(double nominal){
	stringstream ss;
	ss << (long long) nominal;
	string strNominal = ss.str();
	string hasil = "";
	int hitung = 0;
	//Sisipkan titik dari digit paling belakang
	for (int i = strNominal.length() - 1; i >= 0; i--){
		hasil += strNominal[i];
		hitung++;
		if(hitung % 3 == 0 && i!= 0){
			hasil += ".";
		}
	}
	//Balikkan kembali strinnya
	reverse(hasil.begin(), hasil.end());
	return hasil;
}
