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
		printf("\n\n\t==++ MINIMARKET ATMAGROUP ++==");
		printf("\n\n\t[1]. Input Direktur");
		printf("\n\t[2]. Tampil Direktur");
		printf("\n\t[3]. Perbarui Direktur");
		printf("\n\t[4]. Hapus Direktur");
		printf("\n\t[5]. Sorting Direktur Level (DESC), Nama (A-Z) [Bonus]");
		printf("\n\t[0]. Keluar Program");
		printf("\n\n\t[TUGAS]");
		printf("\n\t[6]. Pindah Karyawan");
		printf("\n\t[7]. Hitung Total Gaji");

		
		printf("\n\t>>> "); scanf("%d", &menu);
		
		switch(menu)
		{
			case 1:
				if(isFullDirektur(daftarDirektur))
					printf("\n\n\tDaftar Direktur Sudah Penuh (Max [%d])",maxDirektur);
				else
				{
					indexDirektur = findEmptyDirektur(daftarDirektur);
					do
					{
						printf("\n\n\tMasukkan Nama Direktur\t\t\t: "); fflush(stdin); gets(tempNama);
						
						if(isEmptyString(tempNama))
							printf("\n\t[!] Nama Direktur tidak boleh kosong atau - [!]\n\n");
							
					}while(isEmptyString(tempNama));
					
					
					do
					{
						printf("\tMasukkan Nomor Induk Pegawai Direktur\t: "); fflush(stdin); gets(tempNIP);
						
						if(isEmptyString(tempNIP))
							printf("\n\t[!] NIP direktur tidak boleh kosong atau - [!]\n\n");
							
						else if(!isUniqueNIP(daftarDirektur, tempNIP))
							printf("\n\t[!] NIP direktur harus unik (tidak boleh sama dengan direktur lain) [!]\n\n");
						
					}while(isEmptyString(tempNIP) || !isUniqueNIP(daftarDirektur, tempNIP));
					
					do
					{
						printf("\tMasukkan level minimarket Direktur 1-3\t: "); scanf("%d", &tempLevelMinimarket);
						
						if(tempLevelMinimarket < 1 || tempLevelMinimarket > 3)
							printf("\n\t[!] Level minimarket hanya boleh level 1 - 3\n\n");
						
					}while(tempLevelMinimarket < 1 || tempLevelMinimarket > 3);
					
					printf("\n\t[+] Berhasil membuat direktur baru!\n");
					daftarDirektur[indexDirektur] = createDirektur(tempNama, tempNIP, tempLevelMinimarket);
					
					printf("\n\t\tMasukkan Nama Karyawan Pertama untuk direktur %s : ", daftarDirektur[indexDirektur].nama); fflush(stdin); gets(tempNama);
					if(strlen(tempNama)>0 && strcmpi(tempNama, "-")!=0)
					{
						printf("\t\tMasukkan jam kerja Karyawan : "); scanf("%d", &tempJamKerja);
					
						daftarDirektur[indexDirektur].karyawan[0] = createKaryawan(tempNama, daftarDirektur[indexDirektur].levelMinimarket, tempJamKerja);
						
						printf("\n\t[+] Berhasil membuat Karyawan baru untuk direktur %s!", daftarDirektur[indexDirektur].nama);
					}
					else
						printf("\n\t[+] Tidak Membuat Karyawan baru untuk direktur %s!", daftarDirektur[indexDirektur].nama);
						
					printf("\n\n\t\tMasukkan Nama Karyawan Kedua untuk direktur %s : ", daftarDirektur[indexDirektur].nama); fflush(stdin); gets(tempNama);
					if(strlen(tempNama)>0 && strcmpi(tempNama, "-")!=0)
					{
						printf("\t\tMasukkan jam kerja Karyawan : "); scanf("%d", &tempJamKerja);
					
						daftarDirektur[indexDirektur].karyawan[1] = createKaryawan(tempNama, daftarDirektur[indexDirektur].levelMinimarket, tempJamKerja);
						
						printf("\n\t[+] Berhasil membuat Karyawan baru untuk direktur %s!", daftarDirektur[indexDirektur].nama);
					}
					else
						printf("\n\t[+] Tidak Membuat Karyawan baru untuk direktur %s!", daftarDirektur[indexDirektur].nama);
						
						
					
				}	
			break;
				
			case 2:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar direktur Masih Kosong");
				else
					tampilData(daftarDirektur);
					
			break;
			
			case 3:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar direktur Masih Kosong");
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
							printf("\n\n\tMasukkan Nama Direktur : "); fflush(stdin); gets(tempNama);
							
							if(isEmptyString(tempNama))
								printf("\n\t[!] Nama Direktur tidak boleh kosong atau - [!]\n\n");
								
						}while(isEmptyString(tempNama));
						
						do
						{
							printf("\tMasukkan Nomor Induk Pegawai Direktur : "); fflush(stdin); gets(tempNIP);
							
							if(isEmptyString(tempNIP))
								printf("\n\t[!] NIP direktur tidak boleh kosong atau - [!]\n\n");
							
							else if(!isUniqueNIP(daftarDirektur, tempNIP))
								printf("\n\t[!] NIP direktur harus unik (tidak boleh sama dengan direktur lain) [!]\n\n");
							
						}while(isEmptyString(tempNIP) || !isUniqueNIP(daftarDirektur, tempNIP));
						
						do
						{
							printf("\tMasukkan level minimarket Direktur 1-3: "); scanf("%d", &tempLevelMinimarket);
							
							if(tempLevelMinimarket < 1 || tempLevelMinimarket > 3)
								printf("\n\t[!] Level minimarket hanya boleh level 1 - 3\n\n");
							
						}while(tempLevelMinimarket < 1 || tempLevelMinimarket > 3);
						
						printf("\n\t[+] Berhasil mengupdate direktur baru!\n");
						daftarDirektur[indexDirektur] = updateDirektur(daftarDirektur[indexDirektur], tempNama, tempNIP, tempLevelMinimarket);
					}
				}
			break;
			
			case 4:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar direktur Masih Kosong");
				else
				{
					printf("\n\n\tMasukkan NIP direktur yang akan di hapus : "); fflush(stdin); gets(tempNIP);
					indexDirektur = findNIP(daftarDirektur, tempNIP);
					if(indexDirektur == -1) 
						printf("\n\n\t[!] Direktur Tidak Ditemukan");
					else
					{
						
						daftarDirektur[indexDirektur] = createDirektur("-", "-", 0);
						printf("\n\t[+] Berhasil menghapus direktur!");
					}			
				}
			break;
			
			case 5:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar direktur Masih Kosong");
				else
				{
					sortDirektur(daftarDirektur);
					printf("\n\t[+] Berhasil sortir direktur!");
				}
			break;
			
			case 6://Tugas
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar direktur Masih Kosong");
				else
				{
					printf("\n\n\tMasukkan NIP direktur yang dipindahkan karyawannya : "); fflush(stdin); gets(tempNIP);
					indexDirektur = findNIP(daftarDirektur, tempNIP);
					if(indexDirektur == -1) 
						printf("\n\n\t[!] Direktur Tidak Ditemukan");
					else
					{
						if(isEmptyKaryawan(daftarDirektur, indexDirektur)) //cek direktur yang dicari punya karyawan atau tidak
							printf("\n\n\t[!] Direktur ini tidak Memiliki Karyawan");
						else
						{
							printf("\n\n\tMasukkan nama dari karyawan yang akan dipindahkan : "); fflush(stdin); gets(tempNama); //cari karyawan yang mau dipindahkan
							if(findKaryawan(daftarDirektur, indexDirektur, tempNama)!=-1)
							{
								indexKaryawan = findKaryawan(daftarDirektur, indexDirektur, tempNama);
								printf("\n\n\tMasukkan NIP direktur yang dimasukkan karyawannya : "); fflush(stdin); gets(tempNIP); //cek NIP yang mau dimasukkin
								indexDirektur2 = findNIP(daftarDirektur, tempNIP);
								
								if(indexDirektur2 == -1) 
									printf("\n\n\t[!] Direktur Tidak Ditemukan");
								else
								{
									if(isFullKaryawan(daftarDirektur, indexDirektur2)){ // cek yang dimasukkin kalau sudah punya atau belum
										printf("\n\n\t[!] Direktur ini sudah memiliki dua Karyawan");
										printf("\n\n\t%d",isFullKaryawan(daftarDirektur, indexDirektur2));
									}
									else
									{
										indexKaryawan2 = findEmptyKaryawan(daftarDirektur,indexDirektur2);
										daftarDirektur[indexDirektur2].karyawan[indexKaryawan2] = pindahKaryawan(daftarDirektur[indexDirektur].karyawan[indexKaryawan], daftarDirektur[indexDirektur2].levelMinimarket);
										daftarDirektur[indexDirektur].karyawan[indexKaryawan] = createKaryawan("", 0, 0);
										printf("\n\n\t[+] Berhasil memindahkan karyawan");
									}
								}
							}
							else
								printf("\n\n\t[!] Karyawan Tidak Ditemukan");
						}
					}
				}
			break;
			
			case 7:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar direktur Masih Kosong");
				else
				{
					tampilData(daftarDirektur);
					totalGaji = hitungGaji(daftarDirektur);
					printf("\n\n\tTotal Gaji seluruh direktur dan karyawan\t: Rp%.2f", totalGaji);
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
