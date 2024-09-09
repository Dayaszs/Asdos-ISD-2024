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
	temp.totalGaji = levelMinimarket * 4000000;
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
	
	for(i=0; i<maxDirektur; i++)
		if(strcmpi(direktur[i].nama,"-")!=0) //kalau tidak kosong akan di outputkan
		{
			jumlahKaryawan = 1;
			printf("\n\n\t\t===++ Data Dokter ke-%d ++===", i+1);
			printf("\n\tNama Dokter\t\t: %s", direktur[i].nama);
			printf("\n\tID Dokter\t\t: %s", direktur[i].NIP);
			
			if(direktur[i].levelMinimarket == 1)
				printf("\n\tTipe Dokter\t\t: Junior");
			else if(direktur[i].levelMinimarket == 2)
				printf("\n\tTipe Dokter\t\t: Senior");
			else if(direktur[i].levelMinimarket == 3)
				printf("\n\tTipe Dokter\t\t: Utama");	
				
			printf("\n\tTotal Gaji Dokter\t: Rp%.2f", direktur[i].totalGaji);
			
			if(!isEmptyKaryawan(direktur, i))
			{
				for(j=0;j<maxKaryawan;j++)
				{
					if(strcmpi(direktur[i].karyawan[j].nama,"-")!=0 && strcmpi(direktur[i].karyawan[j].nama,"")!=0)
					{
						printf("\n\n\t\t\t===++ Data Perawat ke-%d ++===", jumlahKaryawan++);
						printf("\n\t\tNama Perawat\t\t: %s", direktur[i].karyawan[j].nama);
						printf("\n\t\tJam Kerja Perawat\t: %d", direktur[i].karyawan[j].jamKerja);
						printf("\n\t\tGaji Perawat\t\t: Rp%.2f", direktur[i].karyawan[j].totalGaji);
					}
					
				}
			}
			else
				printf("\n\n\t\t[*] Dokter ini tidak memiliki Perawat");
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
	temp.totalGaji = levelMinimarket * 4000000;
	
	
	for(j=0;j<maxKaryawan;j++)
	{
		if(levelMinimarket==1)
			temp.karyawan[j].totalGaji = temp.karyawan[j].jamKerja * 200000;
		else if(levelMinimarket==2)
			temp.karyawan[j].totalGaji = temp.karyawan[j].jamKerja * 300000;
		else if(levelMinimarket==3)
			temp.karyawan[j].totalGaji = temp.karyawan[j].jamKerja * 400000;
	}

	
	return temp;
}

Karyawan createKaryawan(String nama, int levelMinimarket ,int jamKerja)
{
	Karyawan temp;
	
	strcpy(temp.nama, nama);
	temp.jamKerja = jamKerja;
	if(levelMinimarket==1)
		temp.totalGaji = jamKerja * 200000;
	else if(levelMinimarket==2)
		temp.totalGaji = jamKerja * 300000;
	else if(levelMinimarket==3)
		temp.totalGaji = jamKerja * 400000;
	
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
	
	if(levelMinimarket==1)
		temp.totalGaji = temp.jamKerja * 200000;
	else if(levelMinimarket==2)
		temp.totalGaji = temp.jamKerja * 300000;
	else if(levelMinimarket==3)
		temp.totalGaji = temp.jamKerja * 400000;
		
	return temp;
}
