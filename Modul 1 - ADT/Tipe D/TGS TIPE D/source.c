#include "header.h"

void initDirektur(Direktur direktur[])
{
	int i,j;
	
	for(i=0;i<maxDirektur;i++)
	{
		strcpy(direktur[i].nama,"-");
		strcpy(direktur[i].NIP,"-");
		direktur[i].totalGaji=0.0;
		direktur[i].levelMinimarket=0;
	}
		
}

bool isFullDirektur(Direktur direktur[]) 
{
	int i;
	
	for(i=0; i<maxDirektur; i++)
		if(strcmpi(direktur[i].nama,"-")==0) 
			return false;
				
	return true;
}

bool isEmptyDirektur(Direktur direktur[]) 
{
	int i;
	
	for(i=0; i<maxDirektur; i++)
		if(strcmpi(direktur[i].nama,"-")!=0) 
			return false;
				
	return true;
}

int findEmptyDirektur(Direktur direktur[])
{
	int i;
	
	for(i=0; i<maxDirektur; i++)
		if(strcmpi(direktur[i].nama,"-")==0) 
			return i;
				
	return -1;
}

Direktur createDirektur(String nama, String NIP, int levelMinimarket)
{
	Direktur temp;
	int j;
	
	strcpy(temp.nama, nama);
	strcpy(temp.NIP, NIP);
	temp.levelMinimarket = levelMinimarket;
	if (levelMinimarket > 0 && levelMinimarket < 8)
		temp.totalGaji = 3000000;
	else if(levelMinimarket > 7 && levelMinimarket < 16)
		temp.totalGaji = 4000000;
	else if(levelMinimarket > 15)
		temp.totalGaji = 5000000;
	for(j=0;j<maxKaryawan;j++)
	{
		strcpy(temp.karyawan[j].nama,"-");
	}
	
	
	return temp;
}

bool isEmptyString(String varString)
{
	if(strcmpi(varString,"")==0 || strcmpi (varString,"-")==0)
		return true;
	else
		return false;
}

bool isUniqueNIP(Direktur direktur[], String NIP)
{
	int i,j;
	
	for(i=0; i<maxDirektur; i++)
	{
		if(strcmpi(direktur[i].NIP,NIP)==0) return false;
	}
	
	return true;
}

void tampilData(Direktur direktur[])
{
	int i,j, jumlahKaryawan;
	int jumlahDosen=1;
	
	for(i=0; i<maxDirektur; i++)
		if(strcmpi(direktur[i].nama,"-")!=0) //kalau tidak kosong akan di outputkan
		{
			jumlahKaryawan = 1;
			printf("\n\n\t\t===++ Data Dosen ke-%d ++===", jumlahDosen++);
			printf("\n\tNama Dosen\t\t: %s", direktur[i].nama);
			printf("\n\tNIP Dosen\t\t: %s", direktur[i].NIP);
			
			if(direktur[i].levelMinimarket > 0 && direktur[i].levelMinimarket < 8)
				printf("\n\tTipe Dosen\t\t: Dosen Junior (%d tahun)", direktur[i].levelMinimarket);
			else if(direktur[i].levelMinimarket > 7 && direktur[i].levelMinimarket < 16)
				printf("\n\tTipe Dosen\t\t: Dosen Senior (%d tahun)", direktur[i].levelMinimarket);
			else if(direktur[i].levelMinimarket > 15)
				printf("\n\tTipe Dosen\t\t: Dosen Utama (%d tahun)", direktur[i].levelMinimarket);	
				
			printf("\n\tTotal Gaji Dosen\t: Rp%.2f", direktur[i].totalGaji);
			
			if(!isEmptyKaryawan(direktur, i))
			{
				for(j=0;j<maxKaryawan;j++)
				{
					if(strcmpi(direktur[i].karyawan[j].nama,"-")!=0 && strcmpi(direktur[i].karyawan[j].nama,"")!=0)
					{
						printf("\n\n\t\t\t===++ Data Asisten ke-%d ++===", jumlahKaryawan++);
						printf("\n\t\tNama Asisten\t\t: %s", direktur[i].karyawan[j].nama);
						printf("\n\t\tJam Kerja Asisten\t: %d", direktur[i].karyawan[j].jamKerja);
						printf("\n\t\tGaji Asisten\t\t: Rp%.2f", direktur[i].karyawan[j].totalGaji);
					}
					
				}
			}
			else
				printf("\n\n\t\t[*] Dosen ini tidak memiliki asisten");
		}
}

int findNIP(Direktur direktur[], String NIP)
{
	int i;
	for(i=0; i<maxDirektur; i++)
		if(strcmpi(direktur[i].NIP,NIP)==0) return i;
	
	return -1;
}

void sortDirektur(Direktur direktur[])
{
	int i, j;
	Direktur temp;
	
	for(i=0; i<maxDirektur-1; i++)
	{
		for(j=i+1; j<maxDirektur; j++)
		{
			if(direktur[i].levelMinimarket < direktur[j].levelMinimarket) // sorting level dulu
			{
				temp = direktur[i];
				direktur[i] = direktur[j];
				direktur[j] = temp;
			}
			else if(direktur[i].levelMinimarket == direktur[j].levelMinimarket) // kalau level sama terus nama
			{
				if(strcmpi(direktur[i].nama,direktur[j].nama)>0)
				{
					temp = direktur[i];
					direktur[i] = direktur[j];
					direktur[j] = temp;
				}
			}
		}
			
	}
}

Direktur updateDirektur(Direktur direkturLama, String nama, String NIP, int levelMinimarket){

	Direktur temp;
	temp = direkturLama;
	int j;
	
	strcpy(temp.nama, nama);
	strcpy(temp.NIP, NIP);
	temp.levelMinimarket = levelMinimarket;
	if (levelMinimarket > 0 && levelMinimarket < 8)
		temp.totalGaji = 3000000;
	else if(levelMinimarket > 7  && levelMinimarket < 16)
		temp.totalGaji = 4000000;
	else if(levelMinimarket > 15)
		temp.totalGaji = 5000000;
	
	
	for(j=0;j<maxKaryawan;j++)
	{
		if(levelMinimarket>0 && levelMinimarket<8)
			temp.karyawan[j].totalGaji = temp.karyawan[j].jamKerja * 100000;
		else if(levelMinimarket>7 && levelMinimarket<16)
			temp.karyawan[j].totalGaji = temp.karyawan[j].jamKerja * 150000;
		else if(levelMinimarket>15)
			temp.karyawan[j].totalGaji = temp.karyawan[j].jamKerja * 200000;
	}

	
	return temp;
}

Karyawan createKaryawan(String nama, int levelMinimarket ,int jamKerja)
{
	Karyawan temp;
	
	strcpy(temp.nama, nama);
	temp.jamKerja = jamKerja;
	if(levelMinimarket>0 && levelMinimarket<8)
		temp.totalGaji = jamKerja * 100000;
	else if(levelMinimarket>7 && levelMinimarket<16)
		temp.totalGaji = jamKerja * 150000;
	else if(levelMinimarket>15)
		temp.totalGaji = jamKerja * 200000;
	
	return temp;
}

float hitungGaji(Direktur direktur[])
{
	int i,j;
	float total=0;
	for(i=0;i<maxDirektur;i++)
	{
		if(strcmpi(direktur[i].nama,"-")!=0)
		{
			total +=direktur[i].totalGaji;
			for(j=0;j<maxKaryawan;j++)
			{
				if(strcmpi(direktur[i].karyawan[j].nama,"-")!=0)
					total += direktur[i].karyawan[j].totalGaji;
			}
		}
	}
	return total;
}

bool isEmptyKaryawan(Direktur direktur[], int indexDirektur){
	int i;
	for(i=0;i<maxKaryawan;i++){
		if(strcmpi(direktur[indexDirektur].karyawan[i].nama,"-")!=0)
			return false;
	}
	return true;
}

bool isFullKaryawan(Direktur direktur[], int indexDirektur){
	int i;
	for(i=0;i<maxKaryawan;i++){
		if(strcmpi(direktur[indexDirektur].karyawan[i].nama,"-")==0 || strcmpi(direktur[indexDirektur].karyawan[i].nama,"")==0)
			return false;
	}
	return true;
}

int findKaryawan(Direktur direktur[], int indexDirektur, String nama){
	int i;
	for(i=0;i<maxKaryawan;i++){
		if(strcmpi(direktur[indexDirektur].karyawan[i].nama,nama)==0)
			return i;
	}
	return -1;	
}

int findEmptyKaryawan(Direktur direktur[], int indexDirektur){
	int i;
	for(i=0;i<maxKaryawan;i++){
		if(strcmpi(direktur[indexDirektur].karyawan[i].nama,"-")==0)
			return i;
	}
	return -1;	
}

Karyawan pindahKaryawan(Karyawan karyawanLama, int levelMinimarket){
	Karyawan temp = karyawanLama;
	
	if(levelMinimarket>0 && levelMinimarket<8)
		temp.totalGaji = temp.jamKerja * 10000;
	else if(levelMinimarket>7 && levelMinimarket<16)
		temp.totalGaji = temp.jamKerja * 150000;
	else if(levelMinimarket>15)
		temp.totalGaji = temp.jamKerja * 200000;
		
	return temp;
}
