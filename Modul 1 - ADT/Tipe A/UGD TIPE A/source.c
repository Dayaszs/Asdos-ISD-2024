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
	temp.totalGaji = levelMinimarket * 1500000;
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
	int i, banyak_direktur=1;
	
	for(i=0; i<maxDirektur; i++)
		if(strcmpi(direktur[i].nama,"-")!=0 && strcmpi(direktur[i].nama,"")!=0) //kalau tidak kosong akan di outputkan
		{
			printf("\n\n\t\t===++ Data Direktur ke-%d ++===", banyak_direktur++);
			printf("\n\tNama Direktur\t\t: %s", direktur[i].nama);
			printf("\n\tNIP Direktur\t\t: %s", direktur[i].NIP);
			
			if(direktur[i].levelMinimarket == 1)
				printf("\n\tLevel Minimarket\t: Kecil");
			else if(direktur[i].levelMinimarket == 2)
				printf("\n\tLevel Minimarket\t: Sedang");
			else if(direktur[i].levelMinimarket == 3)
				printf("\n\tLevel Minimarket\t: Besar");	
				
			printf("\n\tTotal Gaji Direktur\t: Rp%.2f", direktur[i].totalGaji);
			
			if(strcmpi(direktur[i].karyawan.nama,"-")!=0)
			{
				printf("\n\n\t\t\t===++ Data Karyawan ++===");
				printf("\n\t\tNama Karyawan\t\t: %s", direktur[i].karyawan.nama);
				printf("\n\t\tJam Kerja Karyawan\t: %d", direktur[i].karyawan.jamKerja);
				printf("\n\t\tGaji Karyawan\t\t: Rp%.2f", direktur[i].karyawan.totalGaji);
			}
			else
				printf("\n\n\t\t[*] Direktur ini tidak memiliki karyawan");
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
			if((direktur[i].levelMinimarket < direktur[j].levelMinimarket) && strcmpi(direktur[j].nama,"-")!=0) // sorting level dulu
			{
				temp = direktur[i];
				direktur[i] = direktur[j];
				direktur[j] = temp;
			}
			else if(direktur[i].levelMinimarket == direktur[j].levelMinimarket) // kalau level sama terus nama
			{
				if(strcmpi(direktur[i].nama,direktur[j].nama)>0 && strcmpi(direktur[j].nama,"-")!=0)
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
	temp.totalGaji = levelMinimarket * 1500000;
	
	temp.karyawan = karyawan;
	if(levelMinimarket==1)
		temp.karyawan.totalGaji = temp.karyawan.jamKerja * 100000;
	else if(levelMinimarket==2)
		temp.karyawan.totalGaji = temp.karyawan.jamKerja * 150000;
	else if(levelMinimarket==3)
		temp.karyawan.totalGaji = temp.karyawan.jamKerja * 200000;
	
	return temp;
}

Karyawan createKaryawan(String nama, int levelMinimarket ,int jamKerja)
{
	Karyawan temp;
	
	strcpy(temp.nama, nama);
	temp.jamKerja = jamKerja;
	if(levelMinimarket==1)
		temp.totalGaji = jamKerja * 100000;
	else if(levelMinimarket==2)
		temp.totalGaji = jamKerja * 150000;
	else if(levelMinimarket==3)
		temp.totalGaji = jamKerja * 200000;
	
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
