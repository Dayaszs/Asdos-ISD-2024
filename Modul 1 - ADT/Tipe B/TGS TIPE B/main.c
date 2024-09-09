#include "header.h"

int main(int argc, char *argv[]) {
	
	int menu, indexDirektur, indexDirektur2, indexKaryawan, indexKaryawan2;
	Direktur daftarDirektur[maxDirektur];
	
	String tempNama, tempNIP;
	int tempLevelMinimarket, tempJamKerja;
	float totalGaji, bayar;
	
	initDirektur(daftarDirektur);
	
	do
	{
		system("cls");
		printf("\n\n\t==++ TIMNAS BREAKDANCE INDONESIA ++==");
		printf("\n\n\t[1]. Input Pelatih");
		printf("\n\t[2]. Tampil Pelatih");
		printf("\n\t[3]. Perbarui Pelatih");
		printf("\n\t[4]. Hapus Pelatih");
		printf("\n\t[5]. Sorting Pelatih Senioritas (DESC), Nama (A-Z) [Bonus]");
		printf("\n\t[0]. Keluar Program");
		printf("\n\n\t[TUGAS]");
		printf("\n\t[6]. Pindah Atlet");
		printf("\n\t[7]. Hitung Total Gaji");

		
		printf("\n\t>>> "); scanf("%d", &menu);
		
		switch(menu)
		{
			case 1:
				if(isFullDirektur(daftarDirektur))
					printf("\n\n\tDaftar Pelatih Sudah Penuh (Max [%d])",maxDirektur);
				else
				{
						indexDirektur = findEmptyDirektur(daftarDirektur);
					do
					{
						printf("\n\n\tMasukkan Nama Pelatih\t\t\t\t: "); fflush(stdin); gets(tempNama);
						
						if(isEmptyString(tempNama))
							printf("\n\t[!] Nama Pelatih tidak boleh kosong atau - [!]\n\n");
							
					}while(isEmptyString(tempNama));
					
					
					do
					{
						printf("\tMasukkan Nomor Induk Pelatih\t\t\t: "); fflush(stdin); gets(tempNIP);
						
						if(isEmptyString(tempNIP))
							printf("\n\t[!] NIP Pelatih tidak boleh kosong atau - [!]\n\n");
							
						else if(!isUniqueNIP(daftarDirektur, tempNIP))
							printf("\n\t[!] NIP Pelatih harus unik (tidak boleh sama dengan pelatih lain) [!]\n\n");
						
					}while(isEmptyString(tempNIP) || !isUniqueNIP(daftarDirektur, tempNIP));
					
					do
					{
						printf("\tMasukkan total tahun melatih Pelatih (minimal 1 tahun) \t: "); scanf("%d", &tempLevelMinimarket);
						
						if(tempLevelMinimarket < 1)
							printf("\n\t[!] total tahun melatih harus lebih dari 0\n\n");
						
					}while(tempLevelMinimarket < 1);
					
					printf("\n\t[+] Berhasil membuat pelatih baru!\n");
					daftarDirektur[indexDirektur] = createDirektur(tempNama, tempNIP, tempLevelMinimarket);
					
					printf("\n\t\tMasukkan Nama Atlet pertama untuk pelatih %s : ", daftarDirektur[indexDirektur].nama); fflush(stdin); gets(tempNama);
					if(strlen(tempNama)>0 && strcmpi(tempNama, "-")!=0)
					{
						printf("\t\tMasukkan jam latihan atlet : "); scanf("%d", &tempJamKerja);
					
						daftarDirektur[indexDirektur].karyawan[0] = createKaryawan(tempNama, daftarDirektur[indexDirektur].levelMinimarket, tempJamKerja);
						
						printf("\n\t[+] Berhasil membuat atlet baru untuk pelatih %s!", daftarDirektur[indexDirektur].nama);
					}
					else
						printf("\n\t[+] Tidak Membuat atlet baru untuk pelatih %s!", daftarDirektur[indexDirektur].nama);
						
						printf("\n\n\t\tMasukkan Nama Atlet kedua untuk pelatih %s : ", daftarDirektur[indexDirektur].nama); fflush(stdin); gets(tempNama);
					if(strlen(tempNama)>0 && strcmpi(tempNama, "-")!=0)
					{
						printf("\t\tMasukkan jam latihan atlet : "); scanf("%d", &tempJamKerja);
					
						daftarDirektur[indexDirektur].karyawan[1] = createKaryawan(tempNama, daftarDirektur[indexDirektur].levelMinimarket, tempJamKerja);
						
						printf("\n\t[+] Berhasil membuat atlet baru untuk pelatih %s!", daftarDirektur[indexDirektur].nama);
					}
					else
						printf("\n\t[+] Tidak Membuat atlet baru untuk pelatih %s!", daftarDirektur[indexDirektur].nama);
						
						
					
				}	
			break;
				
			case 2:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar pelatih Masih Kosong");
				else
					tampilData(daftarDirektur);
					
			break;
			
			case 3:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar pelatih Masih Kosong");
				else
				{
				 	printf("\n\n\tMasukkan NIP direktur yang akan di perbarui : "); fflush(stdin); gets(tempNIP);
					indexDirektur = findNIP(daftarDirektur, tempNIP);
					
					if(indexDirektur == -1) 
						printf("\n\n\t[!] Direktur Tidak Ditemukan");
					else
					{
						do
						{
							printf("\n\n\tMasukkan Nama Pelatih : "); fflush(stdin); gets(tempNama);
							
							if(isEmptyString(tempNama))
								printf("\n\t[!] Nama pelatih tidak boleh kosong atau - [!]\n\n");
								
						}while(isEmptyString(tempNama));
						
						do
						{
							printf("\tMasukkan Nomor Induk Pegawai Pelatih : "); fflush(stdin); gets(tempNIP);
							
							if(isEmptyString(tempNIP))
								printf("\n\t[!] NIP pelatih tidak boleh kosong atau - [!]\n\n");
							
							else if(!isUniqueNIP(daftarDirektur, tempNIP))
								printf("\n\t[!] NIP pelatih harus unik (tidak boleh sama dengan pelatih lain) [!]\n\n");
							
						}while(isEmptyString(tempNIP) || !isUniqueNIP(daftarDirektur, tempNIP));
						
						do
						{
							printf("\tMasukkan total tahun melatih Pelatih (minimal 1 tahun) \t: "); scanf("%d", &tempLevelMinimarket);
							
							if(tempLevelMinimarket < 1)
								printf("\n\t[!] total tahun melatih harus lebih dari 0\n\n");
							
						}while(tempLevelMinimarket < 1);
						
						printf("\n\t[+] Berhasil mengupdate pelatih baru!\n");
						daftarDirektur[indexDirektur] = updateDirektur(daftarDirektur[indexDirektur], tempNama, tempNIP, tempLevelMinimarket);
					}
				}
			break;
			
			case 4:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar pelatih Masih Kosong");
				else
				{
					printf("\n\n\tMasukkan NIP pelatih yang akan di hapus : "); fflush(stdin); gets(tempNIP);
					indexDirektur = findNIP(daftarDirektur, tempNIP);
					if(indexDirektur == -1) 
						printf("\n\n\t[!] pelatih Tidak Ditemukan");
					else
					{
						
						daftarDirektur[indexDirektur] = createDirektur("-", "-", 0);
						printf("\n\t[+] Berhasil menghapus pelatih!");
					}			
				}
			break;
			
			case 5:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar pelatih Masih Kosong");
				else
				{
					sortDirektur(daftarDirektur);
					printf("\n\t[+] Berhasil sortir pelatih!");
				}
			break;
			
			case 6://Tugas
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar pelatih Masih Kosong");
				else
				{
					printf("\n\n\tMasukkan NIP pelatih yang dipindahkan atletnya : "); fflush(stdin); gets(tempNIP);
					indexDirektur = findNIP(daftarDirektur, tempNIP);
					if(indexDirektur == -1) 
						printf("\n\n\t[!] Pelatih Tidak Ditemukan");
					else
					{
						if(isEmptyKaryawan(daftarDirektur, indexDirektur)) //cek direktur yang dicari punya karyawan atau tidak
							printf("\n\n\t[!] Pelatih ini tidak Memiliki Atlet");
						else
						{
							printf("\n\n\tMasukkan nama dari atlet yang akan dipindahkan : "); fflush(stdin); gets(tempNama); //cari karyawan yang mau dipindahkan
							if(findKaryawan(daftarDirektur, indexDirektur, tempNama)!=-1)
							{
								indexKaryawan = findKaryawan(daftarDirektur, indexDirektur, tempNama);
								printf("\n\n\tMasukkan NIP pelatih yang dimasukkan atletnya : "); fflush(stdin); gets(tempNIP); //cek NIP yang mau dimasukkin
								indexDirektur2 = findNIP(daftarDirektur, tempNIP);
								
								if(indexDirektur2 == -1) 
									printf("\n\n\t[!] Pelatih Tidak Ditemukan");
								else
								{
									if(isFullKaryawan(daftarDirektur, indexDirektur2)){ // cek yang dimasukkin kalau sudah punya atau belum
										printf("\n\n\t[!] Pelatih ini sudah memiliki dua atlet");
									}
									else
									{
										indexKaryawan2 = findEmptyKaryawan(daftarDirektur,indexDirektur2);
										daftarDirektur[indexDirektur2].karyawan[indexKaryawan2] = pindahKaryawan(daftarDirektur[indexDirektur].karyawan[indexKaryawan], daftarDirektur[indexDirektur2].levelMinimarket);
										daftarDirektur[indexDirektur].karyawan[indexKaryawan] = createKaryawan("", 0, 0);
										printf("\n\n\t[+] Berhasil memindahkan atlet");
									}
								}
							}
							else
								printf("\n\n\t[!] Pelatih Tidak Ditemukan");
						}
					}
				}
			break;
			
			case 7:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar Pelatih Masih Kosong");
				else
				{
					tampilData(daftarDirektur);
					totalGaji = hitungGaji(daftarDirektur);
					printf("\n\n\tTotal Gaji seluruh Pelatih dan Atlet\t: Rp%.2f", totalGaji);
				}
				break;
			
			case 0:
				printf("\n\tDhiaz Juan Richard Lagarense == 220711695 == Siap Menyantap ISD");
			break;
				
			default:
				printf("\n\t[!] Menu tidak tersedia");
			break;
			
		} getch();
		
	}while(menu!=0);
	return 0;
}
