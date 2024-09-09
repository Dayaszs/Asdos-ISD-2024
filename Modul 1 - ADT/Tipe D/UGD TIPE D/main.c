#include "header.h"

int main(int argc, char *argv[]) {
	
	int menu, indexDirektur, indexDirektur2;
	Direktur daftarDirektur[maxDirektur];
	
	String tempNama, tempNIP;
	int tempLevelMinimarket, tempJamKerja;
	float totalGaji, bayar;
	
	initDirektur(daftarDirektur);
	
	do
	{
		system("cls");
		printf("\n\n\t==++ UNIVERSITAS MAJU MUNDUR ++==");
		printf("\n\n\t[1]. Input Dosen");
		printf("\n\t[2]. Tampil Dosen");
		printf("\n\t[3]. Perbarui Dosen");
		printf("\n\t[4]. Hapus Dosen");
		printf("\n\t[5]. Sorting Dosen Senioritas (DESC), Nama (A-Z) [Bonus]");
		printf("\n\t[0]. Keluar Program");
		
		printf("\n\t>>> "); scanf("%d", &menu);
		
		switch(menu)
		{
			case 1:
				if(isFullDirektur(daftarDirektur))
					printf("\n\n\tDaftar Dosen Sudah Penuh (Max [%d])",maxDirektur);
				else
				{
						indexDirektur = findEmptyDirektur(daftarDirektur);
					do
					{
						printf("\n\n\tMasukkan Nama Dosen\t\t\t\t: "); fflush(stdin); gets(tempNama);
						
						if(isEmptyString(tempNama))
							printf("\n\t[!] Nama Dosen tidak boleh kosong atau - [!]\n\n");
							
					}while(isEmptyString(tempNama));
					
					
					do
					{
						printf("\tMasukkan Nomor Induk Dosen\t\t\t: "); fflush(stdin); gets(tempNIP);
						
						if(isEmptyString(tempNIP))
							printf("\n\t[!] NIP Dosen tidak boleh kosong atau - [!]\n\n");
							
						else if(!isUniqueNIP(daftarDirektur, tempNIP))
							printf("\n\t[!] NIP Dosen harus unik (tidak boleh sama dengan Dosen lain) [!]\n\n");
						
					}while(isEmptyString(tempNIP) || !isUniqueNIP(daftarDirektur, tempNIP));
					
					do
					{
						printf("\tMasukkan total tahun mengajar Dosen (minimal 1 tahun) \t: "); scanf("%d", &tempLevelMinimarket);
						
						if(tempLevelMinimarket < 1)
							printf("\n\t[!] total tahun mengajar harus lebih dari 0\n\n");
						
					}while(tempLevelMinimarket < 1);
					
					printf("\n\t[+] Berhasil membuat Dosen baru!\n");
					daftarDirektur[indexDirektur] = createDirektur(tempNama, tempNIP, tempLevelMinimarket);
					
					printf("\n\t\tMasukkan Nama Asisten untuk Dosen %s : ", daftarDirektur[indexDirektur].nama); fflush(stdin); gets(tempNama);
					if(strlen(tempNama)>0 && strcmpi(tempNama, "-")!=0)
					{
						printf("\t\tMasukkan jam kerja Asisten : "); scanf("%d", &tempJamKerja);
					
						daftarDirektur[indexDirektur].karyawan = createKaryawan(tempNama, daftarDirektur[indexDirektur].levelMinimarket, tempJamKerja);
						
						printf("\n\t[+] Berhasil membuat Asisten baru untuk Dosen %s!", daftarDirektur[indexDirektur].nama);
					}
					else
						printf("\n\t[+] Tidak Membuat Asisten baru untuk Dosen %s!", daftarDirektur[indexDirektur].nama);
					
				}	
			break;
				
			case 2:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar Dosen Masih Kosong");
				else
					tampilData(daftarDirektur);
					
			break;
			
			case 3:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar Dosen Masih Kosong");
				else
				{
				 	printf("\n\n\tMasukkan NIP Dosen yang akan di perbarui : "); fflush(stdin); gets(tempNIP);
					indexDirektur = findNIP(daftarDirektur, tempNIP);
					
					if(indexDirektur == -1) 
						printf("\n\n\t[!] Dosen Tidak Ditemukan");
					else
					{
						do
						{
							printf("\n\n\tMasukkan Nama Dosen : "); fflush(stdin); gets(tempNama);
							
							if(isEmptyString(tempNama))
								printf("\n\t[!] Nama Dosen tidak boleh kosong atau - [!]\n\n");
								
						}while(isEmptyString(tempNama));
						
						do
						{
							printf("\tMasukkan Nomor Induk Pegawai Dosen : "); fflush(stdin); gets(tempNIP);
							
							if(isEmptyString(tempNIP))
								printf("\n\t[!] NIP Dosen tidak boleh kosong atau - [!]\n\n");
							
							else if(!isUniqueNIP(daftarDirektur, tempNIP))
								printf("\n\t[!] NIP Dosen harus unik (tidak boleh sama dengan Dosen lain) [!]\n\n");
							
						}while(isEmptyString(tempNIP) || !isUniqueNIP(daftarDirektur, tempNIP));
						
						do
						{
							printf("\tMasukkan total tahun mengajar Dosen (minimal 1 tahun) \t: "); scanf("%d", &tempLevelMinimarket);
							
							if(tempLevelMinimarket < 1)
								printf("\n\t[!] total tahun mengajar harus lebih dari 0\n\n");
							
						}while(tempLevelMinimarket < 1);
						
						printf("\n\t[+] Berhasil mengupdate Dosen baru!\n");
						daftarDirektur[indexDirektur] = updateDirektur(tempNama, tempNIP, tempLevelMinimarket, daftarDirektur[indexDirektur].karyawan);
					}
				}
			break;
			
			case 4:
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar Dosen Masih Kosong");
				else
				{
					printf("\n\n\tMasukkan NIP Dosen yang akan di hapus : "); fflush(stdin); gets(tempNIP);
					indexDirektur = findNIP(daftarDirektur, tempNIP);
					if(indexDirektur == -1) 
						printf("\n\n\t[!] Dosen Tidak Ditemukan");
					else
					{
						daftarDirektur[indexDirektur] = createDirektur("-", "-", 0);
						printf("\n\t[+] Berhasil menghapus Dosen!");
					}			
				}
			break;
			
			case 5: // BONUS
				if(isEmptyDirektur(daftarDirektur))
					printf("\n\n\t[!] Daftar Dosen Masih Kosong");
				else
				{
					sortDirektur(daftarDirektur);
					printf("\n\t[+] Berhasil sortir Dosen!");
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
