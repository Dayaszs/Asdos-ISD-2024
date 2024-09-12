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
	if (levelMinimarket > 0 && levelMinimarket < 4)
		temp.totalGaji = 4000000;
	else if(levelMinimarket > 3 && levelMinimarket < 7)
		temp.totalGaji = 5000000;
	else if(levelMinimarket > 6)
		temp.totalGaji = 6000000;
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
	int i,j, jumlahKaryawan,manajer=1;
	
	for(i=0; i<maxDirektur; i++)
		if(strcmpi(direktur[i].nama,"-")!=0) //kalau tidak kosong akan di outputkan
		{
			jumlahKaryawan = 1;
			printf("\n\n\t\t===++ Data Manajer ke-%d ++===", manajer++);
			printf("\n\tNama Manajer\t\t: %s", direktur[i].nama);
			printf("\n\tNIP Manajer\t\t: %s", direktur[i].NIP);
			
			if(direktur[i].levelMinimarket > 0 && direktur[i].levelMinimarket < 4)
				printf("\n\tTipe Manajer\t\t: Manajer Junior (%d tahun)", direktur[i].levelMinimarket);
			else if(direktur[i].levelMinimarket > 3 && direktur[i].levelMinimarket < 7)
				printf("\n\tTipe Manajer\t\t: Manajer Senior (%d tahun)", direktur[i].levelMinimarket);
			else if(direktur[i].levelMinimarket > 6)
				printf("\n\tTipe Manajer\t\t: Manajer Utama (%d tahun)", direktur[i].levelMinimarket);	
				
			printf("\n\tTotal Gaji Manajer\t: Rp%.2f", direktur[i].totalGaji);
			
			if(!isEmptyKaryawan(direktur, i))
			{
				for(j=0;j<maxKaryawan;j++)
				{
					if(strcmpi(direktur[i].karyawan[j].nama,"-")!=0 && strcmpi(direktur[i].karyawan[j].nama,"")!=0)
					{
						printf("\n\n\t\t\t===++ Data Trainee ke-%d ++===", jumlahKaryawan++);
						printf("\n\t\tNama Trainee\t\t: %s", direktur[i].karyawan[j].nama);
						printf("\n\t\tJam Latihan Trainee\t: %d", direktur[i].karyawan[j].jamKerja);
						printf("\n\t\tGaji Trainee\t\t: Rp%.2f", direktur[i].karyawan[j].totalGaji);
					}
					
				}
			}
			else
				printf("\n\n\t\t[*] Manajer ini tidak memiliki artis");
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
	if (levelMinimarket > 0 && levelMinimarket < 4)
		temp.totalGaji = 4000000;
	else if(levelMinimarket > 3 && levelMinimarket < 7)
		temp.totalGaji = 5000000;
	else if(levelMinimarket > 6)
		temp.totalGaji = 6000000;
	
	
	for(j=0;j<maxKaryawan;j++)
	{
		if(levelMinimarket>0 && levelMinimarket<4)
			temp.karyawan[j].totalGaji = temp.karyawan[j].jamKerja * 50000;
		else if(levelMinimarket>3 && levelMinimarket<7)
			temp.karyawan[j].totalGaji = temp.karyawan[j].jamKerja * 70000;
		else if(levelMinimarket>6)
			temp.karyawan[j].totalGaji = temp.karyawan[j].jamKerja * 90000;
	}

	
	return temp;
}

Karyawan createKaryawan(String nama, int levelMinimarket ,int jamKerja)
{
	Karyawan temp;
	
	strcpy(temp.nama, nama);
	temp.jamKerja = jamKerja;
	if(levelMinimarket>0 && levelMinimarket<4)
		temp.totalGaji = jamKerja * 50000;
	else if(levelMinimarket>3 && levelMinimarket<7)
		temp.totalGaji = jamKerja * 70000;
	else if(levelMinimarket>6)
		temp.totalGaji = jamKerja * 90000;
	
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
	
	if(levelMinimarket>0 && levelMinimarket<4)
		temp.totalGaji = temp.jamKerja * 50000;
	else if(levelMinimarket>3 && levelMinimarket<7)
		temp.totalGaji = temp.jamKerja * 70000;
	else if(levelMinimarket>6)
		temp.totalGaji = temp.jamKerja * 90000;
		
	return temp;
}
