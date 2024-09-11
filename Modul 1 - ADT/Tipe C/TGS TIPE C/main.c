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
		printf("\n\n\t==++ KLINIK ATMAMEDIKA ++==");
		printf("\n\n\t[1]. Input Dokter");
		printf("\n\t[2]. Tampil Dokter");
		printf("\n\t[3]. Perbarui Dokter");
		printf("\n\t[4]. Hapus Dokter");
		printf("\n\t[5]. Sorting Dokter Level (DESC), Nama (A-Z) [Bonus]");
		printf("\n\t[0]. Keluar Program");
		printf("\n\n\t[TUGAS]");
		printf("\n\t[6]. Pindah Perawat");
		printf("\n\t[7]. Hitung Total Gaji");

		
		printf("\n\t>>> "); scanf("%d", &menu);
		
		switch(menu)
		{
			case 1:
				if(isFullDirektur(daftarDirektur))
					printf("\n\n\tDaftar Dokter Sudah Penuh (Max [%d])",maxDirektur);
				else
				{
					indexDirektur = findEmptyDirektur(daftarDirektur);
					do
					{
						printf("\n\n\tMasukkan Nama Dokter\t\t\t: "); fflush(stdin); gets(tempNama);
						
						if(isEmptyString(tempNama))
							printf("\n\t[!] Nama Dokter tidak boleh kosong atau - [!]\n\n");
							
					}while(isEmptyString(tempNama));
					
					
					do
					{
						printf("\tMasukkan ID Dokter\t\t\t: "); fflush(stdin); gets(tempNIP);
						
						if(isEmptyString(tempNIP))
							printf("\n\t[!] ID Dokter tidak boleh kosong atau - [!]\n\n");
							
						else if(!isUniqueNIP(daftarDirektur, tempNIP))
							printf("\n\t[!] ID Dokter harus unik (tidak boleh sama dengan Dokter lain) [!]\n\n");
						
					}while(isEmptyString(tempNIP) || !isUniqueNIP(daftarDirektur, tempNIP));
					
					do
					{
						printf("\tMasukkan Tipe Dokter 1-3\t\t: "); scanf("%d", &tempLevelMinimarket);
						
						if(tempLevelMinimarket < 1 || tempLevelMinimarket > 3)
							printf("\n\t[!] Tipe hanya boleh Tipe 1 - 3\n\n");
						
					}while(tempLevelMinimarket < 1 || tempLevelMinimarket > 3);
					
					printf("\n\t[+] Berhasil membuat Dokter baru!\n");
					daftarDirektur[indexDirektur] = createDirektur(tempNama, tempNIP, tempLevelMinimarket);
					
					printf("\n\t\tMasukkan Nama Perawat Pertama untuk Dokter %s : ", daftarDirektur[indexDirektur].nama); fflush(stdin); gets(tempNama);
					if(strlen(tempNama)>0 && strcmpi(tempNama, "-")!=0)
					{
						printf("\t\tMasukkan jam kerja Perawat : "); scanf("%d", &tempJamKerja);
					
						daftarDirektur[indexDirektur].karyawan[0] = createKaryawan(tempNama, daftarDirektur[indexDirektur].levelMinimarket, tempJamKerja);
						
						printf("\n\t[+] Berhasil membuat Perawat baru untuk Dokter %s!", daftarDirektur[indexDirektur].nama);
					}
					else
						printf("\n\t[+] Tidak Membuat Perawat baru untuk Dokter %s!", daftarDirektur[indexDirektur].nama);
						
					printf("\n\n\t\tMasukkan Nama Perawat Kedua untuk Dokter %s : ", daftarDirektur[indexDirektur].nama); fflush(stdin); gets(tempNama);
					if(strlen(tempNama)>0 && strcmpi(tempNama, "-")!=0)
					{
						printf("\t\tMasukkan jam kerja Perawat : "); scanf("%d", &tempJamKerja);
					
						daftarDirektur[indexDirektur].karyawan[1] = createKaryawan(tempNama, daftarDirektur[indexDirektur].levelMinimarket, tempJamKerja);
						
						printf("\n\t[+] Berhasil membuat Perawat baru untuk Dokter %s!", daftarDirektur[indexDirektur].nama);
					}
					else
						printf("\n\t[+] Tidak Membuat Perawat baru untuk Dokter %s!", daftarDirektur[indexDirektur].nama);
						
						
					
				}	
			break;
				
			case 2:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar Dokter Masih Kosong");
				else
					tampilData(daftarDirektur);
					
			break;
			
			case 3:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar Dokter Masih Kosong");
				else
				{
				 	printf("\n\n\tMasukkan ID Dokter yang akan di perbarui : "); fflush(stdin); gets(tempNIP);
					indexDirektur = findNIP(daftarDirektur, tempNIP);
					
					if(indexDirektur == -1) 
						printf("\n\n\t[!] Dokter Tidak Ditemukan");
					else
					{
						do
						{
							printf("\n\n\tMasukkan Nama Dokter : "); fflush(stdin); gets(tempNama);
							
							if(isEmptyString(tempNama))
								printf("\n\t[!] Nama Dokter tidak boleh kosong atau - [!]\n\n");
								
						}while(isEmptyString(tempNama));
						
						do
						{
							printf("\tMasukkan ID Dokter : "); fflush(stdin); gets(tempNIP);
							
							if(isEmptyString(tempNIP))
								printf("\n\t[!] ID Dokter tidak boleh kosong atau - [!]\n\n");
							
							else if(!isUniqueNIP(daftarDirektur, tempNIP))
								printf("\n\t[!] ID Dokter harus unik (tidak boleh sama dengan direktur lain) [!]\n\n");
							
						}while(isEmptyString(tempNIP) || !isUniqueNIP(daftarDirektur, tempNIP));
						
						do
						{
							printf("\tMasukkan Tipe Dokter 1-3: "); scanf("%d", &tempLevelMinimarket);
							
							if(tempLevelMinimarket < 1 || tempLevelMinimarket > 3)
								printf("\n\t[!] Tipe hanya boleh tipe 1 - 3\n\n");
							
						}while(tempLevelMinimarket < 1 || tempLevelMinimarket > 3);
						
						printf("\n\t[+] Berhasil mengupdate Dokter baru!\n");
						daftarDirektur[indexDirektur] = updateDirektur(daftarDirektur[indexDirektur], tempNama, tempNIP, tempLevelMinimarket);
					}
				}
			break;
			
			case 4:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar Dokter Masih Kosong");
				else
				{
					printf("\n\n\tMasukkan ID Dokter yang akan di hapus : "); fflush(stdin); gets(tempNIP);
					indexDirektur = findNIP(daftarDirektur, tempNIP);
					if(indexDirektur == -1) 
						printf("\n\n\t[!] Dokter Tidak Ditemukan");
					else
					{
						
						daftarDirektur[indexDirektur] = createDirektur("-", "-", 0);
						printf("\n\t[+] Berhasil menghapus Dokter!");
					}			
				}
			break;
			
			case 5:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar Dokter Masih Kosong");
				else
				{
					sortDirektur(daftarDirektur);
					printf("\n\t[+] Berhasil sortir Dokter!");
				}
			break;
			
			case 6://Tugas
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar Dokter Masih Kosong");
				else
				{
					printf("\n\n\tMasukkan ID Dokter yang dipindahkan perawatnya : "); fflush(stdin); gets(tempNIP);
					indexDirektur = findNIP(daftarDirektur, tempNIP);
					if(indexDirektur == -1) 
						printf("\n\n\t[!] Dokter Tidak Ditemukan");
					else
					{
						if(isEmptyKaryawan(daftarDirektur, indexDirektur)) //cek Dokter yang dicari punya Perawat atau tidak
							printf("\n\n\t[!] Dokter ini tidak Memiliki Perawat");
						else
						{
							printf("\n\n\tMasukkan nama dari Perawat yang akan dipindahkan : "); fflush(stdin); gets(tempNama); //cari Perawat yang mau dipindahkan
							if(findKaryawan(daftarDirektur, indexDirektur, tempNama)!=-1)
							{
								indexKaryawan = findKaryawan(daftarDirektur, indexDirektur, tempNama);
								printf("\n\n\tMasukkan ID Dokter yang dimasukkan perawatnya : "); fflush(stdin); gets(tempNIP); //cek NIP yang mau dimasukkin
								indexDirektur2 = findNIP(daftarDirektur, tempNIP);
								
								if(indexDirektur2 == -1) 
									printf("\n\n\t[!] Dokter Tidak Ditemukan");
								else
								{
									if(isFullKaryawan(daftarDirektur, indexDirektur2)){ // cek yang dimasukkin kalau sudah punya atau belum
										printf("\n\n\t[!] Dokter ini sudah memiliki dua Perawat");
									}
									else
									{
										indexKaryawan2 = findEmptyKaryawan(daftarDirektur,indexDirektur2);
										daftarDirektur[indexDirektur2].karyawan[indexKaryawan2] = pindahKaryawan(daftarDirektur[indexDirektur].karyawan[indexKaryawan], daftarDirektur[indexDirektur2].levelMinimarket);
										daftarDirektur[indexDirektur].karyawan[indexKaryawan] = createKaryawan("", 0, 0);
										printf("\n\n\t[+] Berhasil memindahkan Perawat");
									}
								}
							}
							else
								printf("\n\n\t[!] Perawat Tidak Ditemukan");
						}
					}
				}
			break;
			
			case 7:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar Dokter Masih Kosong");
				else
				{
					tampilData(daftarDirektur);
					totalGaji = hitungGaji(daftarDirektur);
					printf("\n\n\tTotal Gaji seluruh Dokter dan Perawat\t: Rp%.2f", totalGaji);
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
