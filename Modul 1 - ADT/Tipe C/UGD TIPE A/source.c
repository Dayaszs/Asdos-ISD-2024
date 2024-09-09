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
	strcpy(temp.karyawan.nama,"-");
	
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
	int i;
	
	for(i=0; i<maxDirektur; i++)
		if(strcmpi(direktur[i].nama,"-")!=0) //kalau tidak kosong akan di outputkan
		{
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
			
			if(strcmpi(direktur[i].karyawan.nama,"-")!=0)
			{
				printf("\n\n\t\t\t===++ Data Perawat ++===");
				printf("\n\t\tNama Perawat\t\t: %s", direktur[i].karyawan.nama);
				printf("\n\t\tJam Kerja Perawat\t: %d", direktur[i].karyawan.jamKerja);
				printf("\n\t\tGaji Perawat\t\t: Rp%.2f", direktur[i].karyawan.totalGaji);
			}
			else
				printf("\n\n\t\t[*] Dokter ini tidak memiliki perawat");
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

Direktur updateDirektur(String nama, String NIP, int levelMinimarket, Karyawan karyawan)
{
	Direktur temp;
	int j;
	
	strcpy(temp.nama, nama);
	strcpy(temp.NIP, NIP);
	temp.levelMinimarket = levelMinimarket;
	temp.totalGaji = levelMinimarket * 4000000;
	
	temp.karyawan = karyawan;
	if(levelMinimarket==1)
		temp.karyawan.totalGaji = temp.karyawan.jamKerja * 200000;
	else if(levelMinimarket==2)
		temp.karyawan.totalGaji = temp.karyawan.jamKerja * 300000;
	else if(levelMinimarket==3)
		temp.karyawan.totalGaji = temp.karyawan.jamKerja * 400000;
	
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
	int i;
	float total=0;
	for(i=0;i<maxDirektur;i++)
	{
		if(strcmpi(direktur[i].nama,"-")!=0)
		{
			total +=direktur[i].totalGaji;
			if(strcmpi(direktur[i].karyawan.nama,"-")!=0)
				total += direktur[i].karyawan.totalGaji;
		}
	}
	return total;
}
