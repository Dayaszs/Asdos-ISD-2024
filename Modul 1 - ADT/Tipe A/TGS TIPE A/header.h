#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>
#define maxDirektur 5
#define maxKaryawan 2
typedef char String[50];

//Minimarket
typedef struct
{
	String nama;
	float totalGaji;
	int jamKerja;
}Karyawan;

typedef struct{
	String nama;
	String NIP;
	int levelMinimarket;
	float totalGaji;
	Karyawan karyawan[maxKaryawan];
}Direktur;


void initDirektur(Direktur direktur[]); // inisialisasi direktur menjadi kosong semua
bool isFullDirektur(Direktur direktur[]); // Mengecek array direktur full atau tidak
bool isEmptyDirektur(Direktur direktur[]); // Mengecek array direktur kosong atau tidak
int findEmptyDirektur(Direktur direktur[]); // mencari index array direktur yang kosong
Direktur createDirektur(String nama, String NIP, int levelMinimarket); // membuat satu instans direktur
Karyawan createKaryawan(String nama, int levelMinimarket, int jamKerja); // membuat satu instans karyawan
bool isEmptyString(String varString); // cek variabel string kosong atau -
bool isUniqueNIP(Direktur direktur[], String NIP);// cek keunikan NIP direktur


Direktur updateDirektur(Direktur direkturLama,String nama, String NIP, int levelMinimarket); //update direktur
void tampilData(Direktur direktur[]);// tampil semua data direktur yang tidak kosong
int findNIP(Direktur direktur[], String NIP);// mencari NIP sesuai inputan


bool isEmptyKaryawan(Direktur direktur[], int indexDirektur);
bool isFullKaryawan(Direktur direktur[], int indexDirektur);
int findKaryawan(Direktur direktur[], int indexDirektur, String nama);
int findEmptyKaryawan(Direktur direktur[], int indexDirektur);
void sortDirektur(Direktur direktur[]);// sorting level, kalau sama pakai nama
float hitungGaji(Direktur direktur[]);// hitung gaji
Karyawan pindahKaryawan(Karyawan karyawanLama, int levelMinimarket);






