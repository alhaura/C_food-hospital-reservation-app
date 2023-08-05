#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

void menumakanan();
void carimakanan();
void carinamamakanan();
void order();
void reservasi(void);
void namareservasi(void);
void jadwaldokter(void);
void reservasi(void);
void pendaftaran(void);
void carireservasi(void);
void hapusreservasi(void);
void cls();
void cekPassword();
int mainmenu();
int payment();
int mainmakanan();
int mainreservasi(void);

int dokter, hari, jam, nama, urut, i=-1, j, k=1, n, x, hitung, ok, valid=0;
char jawab = 0;

const char *display_dokter[]= {"", "Sp Cardiothorax", "Sp Anak", "Sp Bedah", "Sp THT", "Sp KK", "Dokter Hewan"};
const char *display_hari[] = {"", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
const char *display_jam[] = {"", "09.00 - 12.00", "13.00 - 15.00", "15.00 - 17.00", "17.00 - 19.00", "19.00 - 21.00"};
int antre[7][7][6] = {0};
char lanjut, str[25][25], temp[25];


void gotoxy(short x, short y){
	COORD position = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

typedef struct{
	int urut[10], dokter[7], hari[7], jam[6];
}hospital; hospital data[100];

struct patient{
	char jeniskelamin;
	char nama[20];
	char nomorhp[15];
	char alamat[30];
	char email[30];
};
struct patient  pa,temp_c;

struct dataPengguna{
	char username[255];
	char password[255];
};

struct passwordRumit{
	char password[30];
	char keyword[30];
	char passwordNew[30];
};

struct order
{
    int number_of_food;
    int cost;
} p[10000];

typedef struct TreeNode {
    int data;
    struct TreeNode* left, *right;
    int is_leaf;
}TreeNode;

int main(void) {
	int i, x, pilihan;
  	struct dataPengguna a1;
  	login(i, x, a1);
  	system("CLS");
  	mainmenu(i, pilihan, x);
	return 0;
}

int mainmenu(int i, int pilihan, int x){
	char title[28] = "Selamat Datang di Menu Utama";
	char mainmenu[31] = "Pilih menu yang kamu inginkan: ";
	do{
		A:
			for(i = 0; i < 28; i++){
				Sleep(30);
				printf("%c", title[i]);
			}
			printf("\n\n");
  			for(i = 0; i < 31; i++){
  				Sleep(30);
  				printf("%c", mainmenu[i]);
			}
    		printf("\n1. Pesan Makanan");
    		printf("\n2. Reservasi Dokter");
    		printf("\n3. Keluar");
    		printf("\n\nPilihan : ");
    		scanf("%d", &pilihan);
    		if(pilihan == 1){
	  			Sleep(1000);
	  			printf("\nAnda akan diarahkan ke menu pemesanan makanan\n");
	  			system("PAUSE");
      			system("cls");
      			mainmakanan();
    		}
    		else if(pilihan == 2){
	  			Sleep(1000);
	  			printf("\nAnda akan diarahkan ke menu reservasi makanan\n");
				system("PAUSE");
      			system("cls");
      			mainreservasi();
    		}
    		else if(pilihan == 3){
     			return 0;
    		}
    		else{
    			goto A;
			}
	}while(pilihan < 1 || pilihan > 3 || x == -1);
}
//fitur signup & login
void signup(int i, int x){
	char title[20] = "Masukkan data anda";
  	char id[50] = "Username : Password : ";
  	struct  dataPengguna a1;
  
  	for(i = 0; i < 18; i++){
    	Sleep(10);
    	printf("%c", title[i]);
  	}
  	printf("\n\n");
  	for(i = 0; i <  11; i++){ //untuk print username
  		Sleep(10);
    	printf("%c", id[i]);
  	}
  
  	fflush(stdin);
  	scanf("%[^\n]s", &a1.username);
  
  	for(i = 11; i < 24; i++){ //untuk print password
        Sleep(10);
        printf("%c", id[i]);
  	}
	int flag = 0;
  	for(i = 0; flag == 0; i++ ){
    	a1.password[i] = getch();
    
    	if(a1.password[i] != 13 && a1.password[i] != 8){
      		printf("*"); 
    	}	
		else if(a1.password[i] == 13){
			flag = 1;
		}
    	else{
      		putch('\b');
      		putch(' ');
      		putch('\b');
      		i--;
    }continue;
        
  }
  	printf("\n");
  	printf("Data anda sudah tersimpan\n");
	system("PAUSE");
	system("CLS");
  	login(i,x, a1);
}

int login(int i, int x, struct dataPengguna a1){
  	char title[69] = "Selamat datang di Program Pemesanan Makanan dan Pengecekan Kesehatan!";
	char id[50] = "Username : Password : ";
	char username[30];
	char password[30];
  	
	for(i = 0; i < 69; i++){ //untuk print judul
    	Sleep(10);
    	printf("%c", title[i]);
  	}
  	printf("\n\ntekan 0 untuk sign up");
	printf("\ntekan 1 untuk login");
  	printf("\ntekan 2 untuk masuk ke Password Center");
  	printf("\ntekan 3 untuk panduan");
  	printf("\n\nMasukkan pilihan anda: "); //memasukkan kepemilikkan akun
  	scanf("%d", &x);
    
  	if(x == 1){ //apabila pengguna sudah memiliki akun
  		int validate = 0;
	  	while(validate == 0){
    		system("PAUSE");
    		system("CLS");
      
      		for(i = 0; i < 69; i++){
      			Sleep(10);
    			printf("%c", title[i]);
  			}
	  		printf("\n\n");
	  		for(i = 0; i <  11; i++){ //untuk print username
	    		Sleep(10);
	    		printf("%c", id[i]);
	  		}
	  
	  		fflush(stdin);
	  		scanf("%[^\n]s", &username);
	  		
	  		for(i = 11; i < 24; i++){ //untuk print password
	    		Sleep(10);
	    		printf("%c", id[i]);
	  		}
	  		int flag = 0;
	  		for(i = 0; flag == 0; i++ ){
	    		password[i] = getch();
	    
	    		if(password[i] != 13 && password[i] != 8){
	      			printf("*"); 
	    		}
				else if(password[i] == 13){
					flag = 1;
				}
	    		else{
	      			putch('\b');
	      			putch(' ');
	      			putch('\b');
	      			i--;
	    		}continue;
	        
	  		}
	  	if(strcmp(a1.username, username) == 0 && strcmp(a1.password, password) == 0){
	  		printf("\nlogin berhasil!");
	  		validate = 1;
		}
		else{
			printf("\nusername atau password salah!\n");
			system("PAUSE");
			system("CLS");
			login(i,x,a1);
		}
		printf("\n");
		system("PAUSE");
	  	system("CLS");
		}
  	}
    
  	else if(x == 0){
    	system("PAUSE");
    	system("CLS");
		signup(i, x); //apabila pengguna belum memiliki akun
  	}
  	else if(x == 2){
    	system("PAUSE");
    	system("CLS");
    	passwordCenter(i, x, a1);
	}
    else if(x == 3 ){
    	system("CLS");
    	printf("Anda perlu sign up terlebih dahulu untuk menggunakan program reservasi.");
    	printf("\nTekan 0 untuk melakukan sign up");
    	printf("\nTekan 1 untuk melakukan login");
    	printf("\nTekan 2 untuk mengakses menu Password Center");
    	printf("\nPassword Center memiliki menu untuk enkripsi password dan pengecekkan kekuatan password\n");
    	system("PAUSE");
    	system("CLS");
    	login(i, x, a1);
	}
	
  	else{
    	system("CLS");
    	login(i, x, a1);
  	}
}

int passwordCenter(int i, int x, struct dataPengguna a1){ //password center merupakan tempat konsultasi password yang aman
	int choice;
	char title[20] = "Password Help Center";
	
	for(i = 0; i < 20; i++){
		Sleep(30);
		printf("%c", title[i]);
	}
	printf("\nAdakah yang bisa kami bantu?");
	printf("\n\n1. Ide password unik");
	printf("\n2. Cek kekuatan password");
	printf("\n0. Kembali ke login");
	printf("\n\nPilih jasa yang kamu inginkan: ");
	scanf("%d", &choice);
	
	switch(choice){
		case 0: system("CLS");
				login(i, x, a1);
			    return 1;
		case 1: passwordUnik();
			    return 1;
		case 2: cekPassword();
			    return 1;
		default:printf("\nPilihan kamu tidak valid!");
			    system("PAUSE");
			    system("CLS");
			    passwordCenter(i, x, a1);
			    return 0;
	}
}

int passwordUnik(){
	int i, x;
	struct passwordRumit a2;
	struct dataPengguna a1;
	
	for(i = 0; i < 29; i++){
		a2.password[i] = '\0';
		a2.keyword[i] = '\0';
		a2.passwordNew[i] = '\0';
	}
	system("PAUSE");
	system("CLS");
	printf("Masukkan password kamu (maks 30 karakter) ");
	
	int flag = 0;
	printf("\nPassword: ");
	for(i = 0; flag == 0; i++ ){
    	a2.password[i] = getch();
    	if(a2.password[i] != 13 && a2.password[i] != 8){
      		printf("*"); 
    	}	
		else if(a2.password[i] == 13){
			flag = 1;
		}
    	else{
      		putch('\b');
      		putch(' ');
      		putch('\b');
      		i--;
    	}continue;
	}
	printf("\nPassword yang kamu masukkan: %s\n", a2.password);
	
	int flag1 = 0;
	printf("Masukkan keyword: ");
	for(i = 0; flag1 == 0; i++ ){
    	a2.keyword[i] = getch();
    	if(a2.keyword[i] != 13 && a2.keyword[i] != 8){
    		printf("*"); 
    	}	
		else if(a2.keyword[i] == 13){
			flag1 = 1;
		}
    	else{
      		putch('\b');
      		putch(' ');
      		putch('\b');
      		i--;
    	}continue;
	}
	printf("\nKeyword yang kamu masukkan adalah %s", a2.keyword);
	fflush(stdin);
	for(i = 0; i < strlen(a2.password); i++){
    	a2.passwordNew[i] = a2.password[i] + (a2.keyword[i] - 97);
        i++;

        if(i == strlen(a2.keyword)){
			i = 0;	
		}
    }
    printf("\n\nPassword baru: ");
    for(i = 0; i < strlen(a2.passwordNew)-1; i++){
    	printf("%c", a2.passwordNew[i]);
	}
	printf("\n\n");
	system("PAUSE");
	system("CLS");
	login(i, x, a1);
}

void cekPassword(){
	int i, x;
	struct  dataPengguna a1;
	char title[19] = "Masukkan password: ";
	char password[10] = {0};
	int passStrength [5] = {0};
	
	system("PAUSE");
	system("CLS");
	
	printf("Fitur Pengecekkan Variasi Karakter Password\n");
	printf("\nPoinmu akan bertambah apabila password kamu menandung: ");
	printf("\nhuruf kecil, huruf besar, angka, dan simbol\n");
	printf("banyaknya karakter yang harus dimasukkan adalah 10\n\n");
	
	for(i = 0; i < 19; i++){
		Sleep(30);
		printf("%c", title[i]);
	}
	int flag = 0;
	for(i = 0; flag == 0; i++ ){
    	a1.password[i] = getch();
    	if(a1.password[i] != 8 && a1.password[i] != 13) 
			printf("*");
		else if(a1.password[i] == 13){
			flag = 1;
		}
    	else{
      		putch('\b');
      		putch(' ');
      		putch('\b');
      		i--;
    	}continue;
	}
	printf("\nPassword kamu adalah %s", a1.password);
	for(i = 0; i < strlen(a1.password); i++){
        if(a1.password[i] >= 97 && a1.password[i] <= 122) //karakter berupa lowercase
        	passStrength[0]++;
        else if(a1.password[i] >= 65 && a1.password[i] <= 90) //karakter berupa uppercase
        	passStrength[1]++;
    	else if(a1.password[i] >= 48 && a1.password[i] <= 57) //karakter berupa angka
    		passStrength[2]++;
    	else if((a1.password[i] >= 33 && a1.password[i]) <= 47 ||
				(a1.password[i] >= 58 && a1.password[i]) <= 64 ||
				(a1.password[i] >= 91 && a1.password[i]) <= 96 ||
				(a1.password[i] >= 123 && a1.password[i]) <= 126) //karakter berupa simbol
    		passStrength[3]++;
    }
    
    for(i = 0; i < 4; i++ ){
    	if(passStrength[i] > 0){
    		passStrength[4]++;
		}
	}
	
	printf("\nNilai keunikan password kamu adalah %d%", passStrength[4]-1);
	printf("\n\nKeterangan: ");
	printf("\n1 Password kamu tidak variatif!");
	printf("\n2 Password kamu kurang variatif!");
	printf("\n3 Password kamu cukup variatif!");
	printf("\n4 Password kamu sangat variatif!\n");
	
	system("PAUSE");
	system("CLS");
	
	login(i, x, a1);
}

int mainreservasi (void){
	int i, x, pilihan;
	char title[33] = "RESERVASI DOKTER RS SEHAT BAHAGIA";
	
	printf("\n\n\t");
	for(i = 0; i < 33; i++){
		Sleep(30);
		printf("%c", title[i]);
	}
	printf ("\n\n1. Pendaftaran Reservasi Dokter");
	printf ("\n2. Menambahkan Reservasi Dokter");
	printf ("\n3. Mencari Reservasi");
	printf ("\n4. Menghapus Reservasi");
  	printf ("\n5. Kembali ke Menu Sebelumnya");
	printf ("\n\nMasukkan Pilihan Menu: ");
	scanf ("%d", &n);
	
	if (n == 1){
		Sleep(2);
		cls();
		pendaftaran();
		mainreservasi();
		cls();
	}
	else if (n == 2){
		Sleep(2);
		cls();
  		namareservasi();
		jadwaldokter();
			reservasi();
		}
	else if (n == 3){
		Sleep(2);
		cls();
  		carireservasi();
		}
  	else if (n == 4){
		Sleep(2);
		cls();
  		hapusreservasi();
	}
	else if (n == 5){
		Sleep(2);
		system("PAUSE");
		system("CLS");
  		mainmenu(i, pilihan, x); 
  	}
	else{
		printf ("\t\nMasukkan angka yang sesuai di menu!!");
		Sleep(2);
  		cls();
		mainreservasi();
	}
	return 0;
}

void namareservasi(){
	printf("Berapa reservasi yang ingin dibuat: ");
	scanf("%d", &hitung);

   	puts("Masukkan nama yang akan direservasi : ");
   	for(i = 0; i <= hitung; i++)
    	gets(str[i]);
   	for(i = 0; i <= hitung; i++)
    	for(j = i + 1; j <= hitung; j++){
        	if(strcmp(str[i], str[j])>0){
            	strcpy(temp, str[i]);
            	strcpy(str[i], str[j]);
            	strcpy(str[j], temp);
         	}
      	}
	Sleep(1000);
	cls();
   	printf("Apakah nama berikut yang sudah anda input benar? :\n");
   	for(i = 0; i <= hitung; i++)
      	puts(str[i]);
}

//Reservasi dokter
void jadwaldokter(void){  
	printf("\n\t=====================================================================\n");
	printf("\t|                 JADWAL DOKTER RS. SEHAT BAHAGIA                    |\n");
  	printf("\t=====================================================================\n");
  	printf("\t|     Pilihan    |     Dokter Spesialis    |       Hari Praktek      |\n");
  	printf("\t=====================================================================\n");
  	printf("\t|        1       |   Sp Cardiothorax       |   Senin, Rabu, Jum'at   |\n");
  	printf("\t|        2       |   Sp Anak               |   Senin - Sabtu         |\n");
  	printf("\t|        3       |   Sp Bedah              |   Selasa, Rabu, Sabtu   |\n");
  	printf("\t|        4       |   Sp THT                |   Senin - Jum'at        |\n");
  	printf("\t|        5       |   Sp KK                 |   Senin - Jum'at        |\n");
  	printf("\t|        6       |   Dokter Hewan          |   Senin - Sabtu         |\n");
  	printf("\t=====================================================================\n\n");

  	printf("Pastikan Anda mengingat hari praktek dokter yang ingin Anda tuju pada saat reservasi! \n\n");
  	system("PAUSE");
  	system("CLS");
  	reservasi();
}

void reservasi(void){
  	int i, pilihan, x;
	i=n;

	lanjut = 'y';
	for(j = 0 ; lanjut != 'n' ; j++){
		printf("Pilih Spesialis Dokter:\n");
		printf("\n\t===========================================\n");
		printf("\t|     Pilihan    |     Dokter Spesialis   |\n");
		printf("\t===========================================\n");
		printf("\t|        1       |   Sp Cardiothorax      |\n");
		printf("\t|        2       |   Sp Anak              |\n");  
  		printf("\t|        3       |   Sp Bedah             |\n");
  		printf("\t|        4       |   Sp THT               |\n");
  		printf("\t|        5       |   Sp KK                |\n");
  		printf("\t|        6       |   Dokter Hewan         |\n");
  		printf("\t===========================================\n");
		printf("> ");
		scanf("%d", &dokter);
    	if (dokter<1 || dokter>6){
    		printf("Nomor yang Anda masukkan salah, silahkan masukkan kembali : ");
    		scanf("%d", &dokter);
    	}
    	Sleep(1000);
  		cls();
	
		printf("\nPilih Hari:\n");
		printf("\n\t========================================\n");
		printf("\t|     Pilihan    |     Hari Praktek    |\n");
		printf("\t========================================\n");
  		printf("\t|        1       |        Senin        |\n");
 		printf("\t|        2       |        Selasa       |\n");
 		printf("\t|        3       |        Rabu         |\n");
 		printf("\t|        4       |        Kamis        |\n");
  		printf("\t|        5       |        Jum'at       |\n");
  		printf("\t|        6       |        Sabtu        |\n");
  		printf("\t========================================\n");
  		printf(">  ");
		scanf("%d", &hari);
    	if (hari<1 || hari>6){
    		printf("Nomor yang Anda masukkan salah, silahkan masukkan kembali : ");
    		scanf("%d", &hari);
    	}
	
		Sleep(1000);
  		cls();
  	
		printf("\nPilih Waktu:\n");
		printf("\n\t=========================================\n");
		printf("\t|     Pilihan    |      Waktu Praktek   |\n");
		printf("\t=========================================\n");
    	printf("\t|        1       |      09.00 - 12.00   |\n");
    	printf("\t|        2       |      13.00 - 15.00   |\n");
    	printf("\t|        3       |      15.00 - 17.00   |\n");
    	printf("\t|        4       |      17.00 - 19.00   |\n");
    	printf("\t|        5       |      19.00 - 21.00   |\n");
    	printf("\t=========================================\n");
    	printf(">  ");
		scanf("%d", &jam);
    	if (jam<1 || jam>5){
    		printf("Nomor yang Anda masukkan salah, silahkan masukkan kembali : ");
    		scanf("%d", &dokter);
   		}
	
		antre[dokter][hari][jam]++;
		data[i].dokter[j] = dokter;
		data[i].hari[j] = hari;
		data[i].jam[j] = jam;
		data[i].urut[j] = antre[dokter][hari][jam];
	
		printf("\nMencetak kartu antrian...\n");
		sleep(2);
		system("cls");
    
		printf("\n\t===================================\n");
   		printf("\t Nomor Urutan: %d				 \n", data[i].urut[j]);
    	printf("\t===================================\n");
    	printf("\t Dokter Spesialis: %s			 \n", display_dokter[data[i].dokter[j]]);
    	printf("\t Hari\t\t: %s					 \n", display_hari[data[i].hari[j]]);
    	printf("\t Jam\t\t: %s						\n", display_jam[data[i].jam[j]]);
    	printf("\t===================================\n");
	
		printf("\nApakah anda ingin melanjutkan untuk memilih jadwal? (y/n) ");
		scanf(" %c", &lanjut);
		if (lanjut == 'n'){
    		printf("Dikarenakan reservasi jadwal dokter ini masih bersifat BETA, maka belum ada tarif yang dikenakan untuk biaya reservasi. \nSemoga cepat sembuh dan terimakasih telah menggunakan jasa reservasi dokter kami!\n");
  			sleep(5);
  			printf ("\nTekan tombol apa saja untuk kembali ke menu utama....");
  			getch();
			system("CLS");
			mainreservasi();
		}
		else{
			Sleep(1000);
  			cls();
			reservasi();
		}
	}
}

void pendaftaran(void){
	char jawab;
	FILE*ek;
	ek=fopen("Record.dat","a");
	printf("\n\n\t\t\tAdd Patients Record \n");
	
	A:
		printf("\nNama Pendaftar: ");
		scanf("%s", pa.nama);
		pa.nama[0] = toupper(pa.nama[0]);
		if(strlen(pa.nama)>20 || strlen(pa.nama)<2){
			printf("\nInvalid. Nama terlalu panjang");
			goto A;
		}
		else{
			for (x=0; x < strlen(pa.nama); x++){
				if (isalpha(pa.nama[x])){
					valid = 1;
				}
				else{
					valid = 0;
					break;
				}
			}
			if(!valid){
				printf("\nNama tidak dapat terbaca oleh sistem, mohon input kembali");
				goto A;
			}
		}
		do{
   			printf("\nJenis Kelamin[L/P]: ");
			scanf(" %c", &pa.jeniskelamin);
			if(toupper(pa.jeniskelamin)=='L' || toupper(pa.jeniskelamin)=='P'){
				ok = 1;
			}
			else{
				ok = 0;
			}
        	if(!ok){
    			printf("\nMohon input 'L' untuk Laki-Laki dan 'P' untuk perempuan!");
    		}
		}while(!ok);
	
	do{
		B:
			printf("\nAlamat Domisili: ");
			scanf("%s",pa.alamat);
			pa.alamat[0]=toupper(pa.alamat[0]);
	   		if(strlen(pa.alamat)>20||strlen(pa.alamat)<4){
				printf("\n\t Alamat tidak dapat dibaca sistem, mohon input ulang");
				goto B;
			}	
	}while(!valid);
	do{	
		C:
		printf("\nNomor Telepon: ");
		scanf("%s",pa.nomorhp);
		
		if(strlen(pa.nomorhp)>11||strlen(pa.nomorhp)!=11){
			printf("\n\t Nomor telepon tidak dapat dibaca sistem, mohon input ulang");
			goto C;
		}
		else{
			for (x=0; x < strlen(pa.nomorhp); x++){
				if (!isalpha(pa.nomorhp[x]))	{
				valid=1;
				}
				else{
					valid=0;
					break;
				}
			}
				if(!valid){
					printf("\nNomor telepon tidak dapat dibaca sistem, mohon input ulang");
					goto C;
				}
		}
	}while(!valid);
	
	do{
		D:
		printf("\nEmail : ");
		scanf("%s",pa.email);
		if (strlen(pa.email)>30||strlen(pa.email)<8){
	    	printf("\n\t Tidak dapat dibaca sistem. Alamat email harus berada dalam range 8-30 karakter");
	    	goto D;
		}
	}while(valid = 0);{
		valid = 0;
		}
    fprintf(ek,"%s %c %s %s %s \n", &pa.nama, &pa.jeniskelamin, &pa.alamat, &pa.nomorhp, &pa.email);
    printf("\n\n\t Nama Anda sudah direkam dalam sistem ...");
    fclose(ek);
    
    loop:
    	printf("\n\n\tApakah Anda ingin menambahkan pendaftar lain?? [Y/N]: ");
    	scanf("%c", &jawab);
    	if (toupper(jawab) == 'Y'){
			pendaftaran();
		}
    	else if(toupper(jawab)=='N'){
			printf("\n\tTerimakasih\n");
			system("PAUSE");
			system("CLS");
    		mainreservasi();
		}
   		else{
        	goto loop;
    	}
}

void carireservasi(void){
	char nam[20];
	int found=0;
	system("cls");
	FILE *ek, *ft;
	ft=fopen("temp_file2.dat","w+");
	ek=fopen("Record.dat","r");
	
	printf("\n\n\tMencari daftar reservasi....\n");
	gotoxy(12,8);
	
	printf("\n Masukkan nama pendaftar reservasi: ");
	scanf("%s",nam);
	
	fflush(stdin);
	nam[0]=toupper(nam[0]);

	while(fscanf(ek,"%s %c %s %s %s \n", pa.nama, &pa.jeniskelamin, pa.alamat, pa.nomorhp, pa.email)!=EOF){ 
			if(strcmp(pa.nama, nam) == 0){
			
			gotoxy(1,15);
			printf("Nama");
			gotoxy(25,15);
			printf("Kelamin");
			gotoxy(45,15);
			printf("Alamat");
			gotoxy(64,15);
			printf("Nomor Telepon");
			gotoxy(85,15);
			printf("Email\n");
			printf("=================================================================================================================");
		
			gotoxy(1,18);
			printf("%s",pa.nama);
			gotoxy(25,18);
			printf("%c",&pa.jeniskelamin);
			gotoxy(45,18);
			printf("%s",pa.alamat);
			gotoxy(64,18);
			printf("%s",pa.nomorhp);
			gotoxy(85,18);
			printf("%s",pa.email);
			printf("\n");
			break;
		}
	} if(strcmp(pa.nama, nam) != 0){
		gotoxy(5,10);
		printf("Tidak ada reservasi atas nama tersebut di sistem!");
		getch();
		mainreservasi();
	}fclose(ek);

	loop2:
		getch();
		printf("\n\n\tApakah Anda ingin mencari reservasi lain? [Y/N]");
	    scanf(" %c", &jawab);
	    	if (toupper(jawab)=='Y'){
	    		system("cls");
	        	carireservasi();
	    	}
			else if(toupper(jawab)=='N'){
			printf("\n\t Thank you");
	    	getch();
	    	system("cls");
			mainreservasi();
	    	}
			else{
	    	printf("\n\tMasukkan menu lain\n");
	    	goto loop2;
	    	}
}

void hapusreservasi(void){
	char nam[20];
	int found=0;
	system("cls");
	FILE *ek, *ft;
	ft=fopen("temp_file2.dat","w+");
	ek=fopen("Record.dat","r");
	
	printf("\n\n\tHapus Reservasi... \n");
	gotoxy(12,8);
	printf("\nMasukkan nama pendaftar reservasi: ");
	scanf("%s", nam);
	fflush(stdin);
	nam[0]=toupper(nam[0]);
	
	while (fscanf(ek,"%s %c %s %s %s \n", &pa.nama, &pa.jeniskelamin, &pa.alamat, &pa.nomorhp, &pa.email)!=EOF){
		if (strcmp(pa.nama, nam)!=0)
			fprintf(ft,"%s %c %s %s %s \n", &pa.nama, &pa.jeniskelamin, &pa.alamat, &pa.nomorhp, &pa.email);
		else{
			printf("%s %c %s %s %s \n", &pa.nama, &pa.jeniskelamin, &pa.alamat, &pa.nomorhp, &pa.email);
			found=1;
		}
	}
	if(found==0){
		printf("\n\n\tTidak ada reservasi atas nama tersebut di sistem...");
		getch();
		system("PAUSE");
		system("CLS");
		mainreservasi();
	}
	else{
		fclose(ek);
		fclose(ft);
		remove("Record.dat");
		rename("temp_file2.dat","Record.dat");
		printf("\n\n\tReservasi telah berhasil dihapus");
		getch();
		system("PAUSE");
		system("CLS");
		mainreservasi();
	}
}
  
//bagian menu makanan

int mainmakanan (){
  	int i, n, x, pilihan;
  	char title[17] = "PEMESANAN MAKANAN";
  	printf("\n\n\t");
	for(i = 0; i < 17; i++ ){
  		Sleep(30);
		printf("%c", title[i]);
	  }
	printf ("\n\n1. Memesan Makanan");
	printf ("\n2. Mengecek Kode Item Makanan");
	printf ("\n3. Mengecek Nomor Antrian");
	printf("\n4. Kembali ke Menu Utama");
	printf ("\n\nMasukkan Pilihan : ");
	scanf ("%d", &n);
	
	if (n == 1){
		Sleep(1000);
  		cls();
		order();
		payment();
  		main();	
	}
	
	else if (n == 2){
		Sleep(1000);
  		cls();
		carinamamakanan();
    	menumakanan();
      	system("PAUSE");
      	system("CLS");
    	mainmakanan();
	}
	
	else if (n == 3){
		Sleep(1000);
  		cls();
		nomorantrian();
      	system("PAUSE");
      	system("CLS");
    	mainmakanan();	
	}
	else if(n == 4){
		system("PAUSE");
		system("CLS");
		mainmenu(i, pilihan, x);
	}
	else{
		printf ("\t\nMasukkan Pilihan Yang Sesuai!!");
		Sleep(1000);
  		cls();
		main();
	}
	return 0;
}

void cls()
{
    system("cls");
}

void menumakanan ()
{
	printf("\n\t=============================================================================\n");
  	printf("\t|                                 MENU                                      |\n");
  	printf("\t=============================================================================\n");
  	printf("\t|      Kode Item     |  Makanan & Minuman |      Ukuran      |   Harga(Rp)  |\n");
  	printf("\t=============================================================================\n");
  	printf("\t|         1          | Nasi Goreng        | M/L              | 20/25        |\n");
  	printf("\t|         2          | Bakso              | 4/6/8 pcs        | 15/22/30     |\n");
  	printf("\t|         3          | Ayam Goreng        | 1/4/10 pcs       | 10/40/100    |\n");
  	printf("\t|         4          | Soto Ayam          | M/L              | 20/25        |\n");
 	printf("\t|         5          | Soto Betawi        | M/L              | 25/30        |\n");
 	printf("\t|         6          | Gudeg              | M/L              | 20/25        |\n");
  	printf("\t|         7          | Jahe Merah         | 250ml            | 15           |\n");
  	printf("\t|         8          | Kopi Hitam         | 250ml            | 15           |\n");
  	printf("\t|         9          | Teh Manis          | 250ml            | 10           |\n");
  	printf("\t|         10         | Badak              | 250/500ml        | 15/30        |\n");
  	printf("\t=============================================================================\n");
}

void carinamamakanan (){
	char key [100];
	int i;
	int j;
	int pos=-1;
	int count=0;
	
	char namamakanan [10][100]= {"Nasi Goreng", "Bakso", "Ayam Goreng", "Soto Ayam", "Soto Betawi", "Gudeg", "Jahe Merah", "Kopi Hitam", "Teh Manis", "Badak"};  

	printf ("Masukkan Nama Makanan yang ingin dicari	: ");
	getchar();
	gets (key);
	
	for (i=0 ; i<10 ; i++){
		if (strcmp(key, namamakanan[i]) == 0){
			printf ("\n%s ditemukan pada kode item %d", key, i+1);
			break;
		}
	}
	
	if (i == 10){
		printf ("\n%s tidak ditemukan");
	}
}

TreeNode* make_treenode(int data) {
    TreeNode* node = (TreeNode*) calloc (1, sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    node->is_leaf = 1;
    return node;
}
 
TreeNode* insert_bst(TreeNode* root, int data) {
    if (!root) {
        root = make_treenode(data);
        return root;
    }
    else {
        TreeNode* node = make_treenode(data);
        TreeNode* temp = root;
        while (temp) {
            if (temp->is_leaf) {
                if (temp->data > data) {
                    temp->left = node;
                    temp->is_leaf = 0;
                    break;
                }
                else {
                    temp->right = node;
                    temp->is_leaf = 0;
                    break;
                }
            }
            else {
                if (temp->data > data) {
                    if (temp->left == NULL) {
                        temp->left = node;
                        break;
                    }
                    temp = temp->left;
                }
                else {
                    if (temp->right == NULL) {
                        temp->right = node;
                        break;
                    }
                    temp = temp->right;
                }
            }
        }
    }
    return root;
}
 
int search_bst(TreeNode* root, int target) {
    if (!root)
        return 0;
    if (root->data == target)
        return 1;
    else if (root->data > target)
        return search_bst(root->left, target);
    else
        return search_bst(root->right, target);
    return 0;
}
 
TreeNode* get_inorder_successor(TreeNode* node) {
    TreeNode* temp = node->right;
    while(temp->left) {
        temp = temp->left;
    }
    return temp;
}
 
TreeNode* delete_bst(TreeNode* root, int target) { //untuk menghapus elemen
    if (!root)
        return root;
    else {
        TreeNode* temp = root;
        if (temp->data > target) {
            root->left = delete_bst(root->left, target);
        }
        else if (temp->data < target) {
            root->right = delete_bst(root->right, target);
        }
        else {
            if (temp->left == NULL) {
                TreeNode* del_node = temp;
                temp = temp->right;
                del_node->right = NULL;
                free(del_node);
                return temp;
            }
            else if (temp->right == NULL) {
                TreeNode* del_node = temp;
                temp = temp->left;
                del_node->left = NULL;
                free(del_node);
                return temp;
            }
            else {
                TreeNode* inorder_successor = get_inorder_successor(temp);
                temp->data = inorder_successor->data;
                root->right = delete_bst(root->right, inorder_successor->data);
            }
        }
        return root;
    }
}
 
void free_bst(TreeNode* root) {
    if (!root)
        return;
    free_bst(root->left);
    free_bst(root->right);
    free(root);
}
 
void print_search(TreeNode* root, int target) {
    if (search_bst(root, target) == 1) { //logika bila elemen yang dicari ditemukan
        printf("Antrian : %d Ditemukan!\n", target);
    }
    else { //logika ketika elemen yang dicari tidak ditemukan
        printf("Antrian : %d Kode Tidak Ditemukan!\n", target);
    }
}
 
void print_bst(TreeNode* root) { //fungsi untuk print root dari tree
    if (!root)
        return;
    print_bst(root->left);
    printf("%d -> ", root->data);
    print_bst(root->right);
}

int nomorantrian() 
{
	TreeNode* root = make_treenode(12); //memasukkan elemen nomor antrean
    root = insert_bst(root, 45);
    root = insert_bst(root, 24);
    root = insert_bst(root, 22);
    root = insert_bst(root, 78);
    root = insert_bst(root, 9);
    root = insert_bst(root, 89);
    root = insert_bst(root, 29);
    root = insert_bst(root, 34);
    root = insert_bst(root, 2);
    printf("\n");
    
    int ch, num, del, find, pilihan;
    int x = 1;
    
    do{
    	A:
    		print_bst(root);
    		printf ("\nPilih Menu Di Bawah Ini : \n");
    		printf ("\n1. Masukkan Nomor Antrian");
    		printf ("\n2. Menghapus Nomor Antrian");
    		printf ("\n3. Mencari Nomor Antrian");
    		printf ("\n0. Kembali\n");
    		printf ("\nPilihan : ");
    		scanf ("%d", &ch);
    
    		switch (ch){
    			case 1 :
					printf ("\nMasukkan Nomor Antrian Yang Ingin Dimasukkan : ");
    				scanf ("%d", &num);
    				root = insert_bst(root, num);
    				print_bst(root);
    				B:
						printf ("\n\nJika Ingin Kembali Ke Menu Sebelumnya Ketik 1");
						printf ("\nPilihan : ");
						scanf ("%d", &pilihan);
						if(pilihan == 1){
							system("PAUSE");
							system("CLS");
							goto A;
						}
						else{
							system("PAUSE");
							system("CLS");
							goto B;
						}
    				Sleep(1000);
  					cls();
    	    		break;
    	
    			case 2 :
    				printf ("\nMasukkan Nomor Antrian Yang Ingin Dihapus : ");
    				scanf ("%d", &del);
    				root = delete_bst(root, del);
    				print_bst(root);
    				system("PAUSE");
					system("CLS");
					goto A;
    				break;
    	
    			case 3 :
    				printf ("\nMasukkan Nomor Antrian Yang Ingin Dicari : ");
    				scanf ("%d", &find);
      				print_search(root, find);
      				print_bst(root);
      				printf("\n");
      				system("PAUSE");
					system("CLS");
					goto A;	
					break;
		
				case 0 :
    				Sleep(1000);
  					cls();
  					mainmakanan ();
  					x = 0;
    				break;			
			
				default :
					break;	
			}
	
	}while (x == 1);
	
    return 0;
}

void order(){
	int n, in, qu;
  	int order_count=0;

  	p[order_count].cost = 0;
  	p[order_count].number_of_food = 0;

  	level:
  	menumakanan();
  	printf ("\tBerapa banyak item yang ingin Anda beli : ");
  	scanf ("%d", &n);

  	Sleep(1000);
  	cls();
    
  	while (n--){
    	menumakanan();
    	printf ("\tMasukkan kode item : ");
    	scanf ("%d", &in);
    
    	Sleep(1000);
  		cls();
    
		switch(in){
      		case 1: {
	        	printf("\n\t==================================================\n");
	        	printf("\t|                  Nasi Goreng                   |\n");
	        	printf("\t==================================================\n");
	        	printf("\t|   No.  |     Ukuran    |          Harga        |\n");
	        	printf("\t==================================================\n");
	        	printf("\t|   1    |       M       |         Rp20.000      |\n");
	        	printf("\t|   2    |       L       |         Rp25.000      |\n");
	        	printf("\t==================================================\n");
	        	printf("\tMasukkan Ukuran Nasi Goreng : ");
	        	int i;
	        	scanf ("%d", &i);
	        	getchar();        
	        	printf("\tMasukkan Jumlah             : ");
	        	scanf ("%d", &qu);
	        	getchar();
        
        	p[order_count].number_of_food +=qu;
        	if (i==1) {
          		p[order_count].cost += (20*qu);
        	}
        	else{
          		p[order_count].cost += (25*qu);
        	}
  		  	Sleep(1000);
  		  	cls();
        	break;
        }
      
      	case 2 :{
        	printf("\n\t==================================================\n");
        	printf("\t|                    Bakso                       |\n");
        	printf("\t==================================================\n");
        	printf("\t|   No.  |     Ukuran    |          Harga        |\n");
        	printf("\t==================================================\n");
        	printf("\t|   1    |      4 pcs    |         Rp15.000      |\n");
        	printf("\t|   2    |      6 pcs    |         Rp22.000      |\n");
        	printf("\t|   3    |      8 pcs    |         Rp30.000      |\n");
        	printf("\t==================================================\n");
        	printf("\tMasukkan Ukuran Bakso      : ");
        	int i;
        	scanf ("%d", &i);
        	getchar();        
        	printf("\tMasukkan Jumlah          : ");
        	scanf ("%d", &qu);
        	getchar();

        	p[order_count].number_of_food +=qu;
        	if (i==1) {
          		p[order_count].cost += (15*qu);
        	}
        	else if (i==2){
          		p[order_count].cost += (22*qu);
        	}
        	else {
          		p[order_count].cost += (30*qu);
        	}
    		Sleep(1000);
  			cls();
        	break;
      	}
      
      	case 3 :{	
        	printf("\n\t==================================================\n");
        	printf("\t|                Ayam Goreng                     |\n");
        	printf("\t==================================================\n");
        	printf("\t|   No.  |     Ukuran    |          Harga        |\n");
        	printf("\t==================================================\n");
        	printf("\t|   1    |      1 pcs    |         Rp10.000      |\n");
        	printf("\t|   2    |      4 pcs    |         Rp40.000      |\n");
        	printf("\t|   3    |      10 pcs   |         Rp100.000     |\n");
        	printf("\t==================================================\n");
        	printf("\tMasukkan Ukuran Ayam Goreng    : ");
        	int i;
        	scanf ("%d", &i);
        	getchar();        
        	printf("\tMasukkan Jumlah              : ");
        	scanf ("%d", &qu);
        	getchar();

        	p[order_count].number_of_food +=qu;
        	if (i==1) {
          		p[order_count].cost += (10*qu);
        	}
       		else if (i==2) {
          		p[order_count].cost += (40*qu);
        	}
        	else{
          		p[order_count].cost += (100*qu);
        	}
    		Sleep(1000);
  			cls();
        	break;
      	}
      
    	case 4 :{
        	printf("\n\t==================================================\n");
        	printf("\t|                  Soto Ayam                     |\n");
        	printf("\t==================================================\n");
        	printf("\t|   No.  |     Ukuran    |          Harga        |\n");
        	printf("\t==================================================\n");
        	printf("\t|   1    |       M       |         Rp20.000      |\n");
        	printf("\t|   2    |       L       |         Rp25.000      |\n");
        	printf("\t==================================================\n");
        	printf("\tMasukkan Ukuran Soto Ayam   : ");
        	int i;
        	scanf ("%d", &i);
        	getchar();        
        	printf("\tMasukkan Jumlah           : ");
        	scanf ("%d", &qu);
        	getchar();

        	p[order_count].number_of_food +=qu;
        	if (i==1) {
          		p[order_count].cost += (15*qu);
        	}
        	else{
          		p[order_count].cost += (25*qu);
        	}
    		Sleep(1000);
  			cls();
        	break;
      	}
      
    	case 5 :{
	        printf("\n\t==================================================\n");
	        printf("\t|                  Soto Betawi                   |\n");
	        printf("\t==================================================\n");
	        printf("\t|   No.  |     Ukuran    |          Harga        |\n");
	        printf("\t==================================================\n");
	        printf("\t|   1    |       M       |         Rp25.000      |\n");
	        printf("\t|   2    |       L       |         Rp30.000      |\n");
	        printf("\t==================================================\n");
	        printf("\tMasukkan Ukuran Soto Betawi   : ");
	        int i;
	        scanf ("%d", &i);
	        getchar();        
	        printf("\tMasukkan Jumlah             : ");
	        scanf ("%d", &qu);
	        getchar();

        	p[order_count].number_of_food +=qu;
        	if (i==1){
          		p[order_count].cost += (25*qu);
        	}
        	else {
          		p[order_count].cost += (30*qu);
        	}
    		Sleep(1000);
  			cls();
        	break;
      	}
      
    	case 6 :{
	        printf("\n\t==================================================\n");
	        printf("\t|                     Gudeg                      |\n");
	        printf("\t==================================================\n");
	        printf("\t|   No.  |     Ukuran    |          Harga        |\n");
	        printf("\t==================================================\n");
	        printf("\t|   1    |       M       |         Rp20.000      |\n");
	        printf("\t|   2    |       L       |         Rp25.000      |\n");
	        printf("\t==================================================\n");
	        printf("\tMasukkan Ukuran Gudeg      : ");
	        int i;
	        scanf ("%d", &i);
	        getchar();        
	        printf("\tMasukkan Jumlah          : ");
	        scanf ("%d", &qu);
	        getchar();

        	p[order_count].number_of_food +=qu;
        	if (i==1) {
          		p[order_count].cost += (20*qu);
        	}
        	else {
          		p[order_count].cost += (25*qu);
        	}
    		Sleep(1000);
  			cls();
        	break;
      	}
      
    	case 7 : {
	        printf("\n\t==================================================\n");
	        printf("\t|                   Jahe Merah                   |\n");
	        printf("\t==================================================\n");
	        printf("\t|         Ukuran         |          Harga        |\n");
	        printf("\t==================================================\n");
	        printf("\t|         250 ml         |         Rp15.000      |\n");
	        printf("\t==================================================\n");       
	        printf("\tMasukkan Jumlah             :  ");
	        scanf ("%d", &qu);
	        getchar();
	
	        p[order_count].number_of_food +=qu;
	        p[order_count].cost += (15*qu);
	    	Sleep(1000);
	  		cls();
	        break;
      	}
      
    	case 8 : {
	        printf("\n\t==================================================\n");
	        printf("\t|                   Kopi Hitam                   |\n");
	        printf("\t==================================================\n");
	        printf("\t|         Ukuran         |          Harga        |\n");
	        printf("\t==================================================\n");
	        printf("\t|         250 ml         |         Rp15.000      |\n");
	        printf("\t==================================================\n");       
	        printf("\tMasukkan Jumlah             :  ");
	        scanf ("%d", &qu);
	        getchar();
	
	
	        p[order_count].number_of_food +=qu;
	        p[order_count].cost += (15*qu);
	    	Sleep(1000);
	  		cls();
	        break;
      	}
      
    	case 9 : {
	        printf("\n\t==================================================\n");
	        printf("\t|                    Teh Manis                   |\n");
	        printf("\t==================================================\n");
	        printf("\t|         Ukuran         |          Harga        |\n");
	        printf("\t==================================================\n");
	        printf("\t|         250 ml         |         Rp10.000      |\n");
	        printf("\t==================================================\n");       
	        printf("\t Masukkan Jumlah             :  ");
	        scanf ("%d", &qu);
	        getchar();
	
	        
	        p[order_count].number_of_food +=qu;
	        p[order_count].cost += (10*qu);
	    	Sleep(1000);
	  		cls();
	        break;
      	}
      
    	case 10 :{
	        printf("\n\t==================================================\n");
	        printf("\t|                     Badak                      |\n");
	        printf("\t==================================================\n");
	        printf("\t|   No.  |     Ukuran    |          Harga        |\n");
	        printf("\t==================================================\n");
	        printf("\t|   1    |     250 ml    |         Rp15.000      |\n");
	        printf("\t|   2    |     300 ml    |         Rp30.000      |\n");
	        printf("\t==================================================\n");
	        printf("\tMasukkan Ukuran Badak      : ");
	        int i;
	        scanf ("%d", &i);
	        getchar();        
	        printf("\t| Masukkan Jumlah          : ");
	        scanf ("%d", &qu);
	        getchar();
      
        	p[order_count].number_of_food +=qu;
        	if (i==1) {
          		p[order_count].cost += (10*qu);
        	}
        	else {
          		p[order_count].cost += (20*qu);
        	}
    		Sleep(1000);
  			cls();
        	break;
     	}
      
    	default : {
        	printf ("Pastikan Kode Item yang dimasukkan sudah benar\n");
        	n++;
      }
    }
  }

	char temp;
  	printf("\tApakah anda ingin memesan makanan lagi?(y/n) : ");
  	scanf("%c", &temp);
	if (temp == 'y' || temp == 'Y')
	goto level;
	Sleep(1000);
	cls();
  
	printf("\n\t==================================================\n"); 
	printf("\t|                 Detail Pemesanan               |\n");
	printf("\t==================================================\n");
	printf("\t|    Total Item     |           %d                |\n",p[order_count].number_of_food);
	printf("\t|    Total Harga    |       Rp %d.000.00         |\n",p[order_count].cost);
	printf("\t==================================================\n");
	order_count ++;
}

int payment()
{
  	int pilihan, x;
	int sistem_pembayaran;	
  	int kartu_kredit;
  	int uangdigital;
  	char pass[20],p=' ';
  	int j=0;
	
	while (1){
    	printf("\t|                Metode Pembayaran               |\n");
    	printf("\t==================================================\n");
    	printf("\t|    1     |            Uang Digital             |\n");
    	printf("\t|    2     |            Kartu Kredit             |\n");
    	printf("\t==================================================\n");	  
    	printf("\tPilih Sistem Pembayaran      : ");   
    	scanf("%d", &sistem_pembayaran);
    
	    if(sistem_pembayaran==1){
			printf("\n\tMasukkan Nomor Uang Digital : ");
			scanf("%d", &uangdigital);
		  	Sleep(2000);
		  	printf("\n\tPesanan akan kami proses, Terima Kasih...");
		  	Sleep(2000);
		  	cls();
			mainmakanan();
	      	return 0;
		}
		else if(sistem_pembayaran==2){
			printf("\n\tMasukkan nomor kartu kredit  : ");
			scanf("%d", &kartu_kredit);
			printf("\tMasukkan pin kartu kredit    : ");
			p=' '; j=0;
	        while(j<20){
	        	pass[j]=getch();
	          	p=pass[j];
	          	if(p=='\r') {
				  break;
				}
	          	else {
					printf("*");
				}
	            j++;
	        }
	        pass[j]='\0';
			
		  	Sleep(2000);
		  	printf("\n\n\tPesanan akan kami proses, Terima Kasih...");
		  	Sleep(2000);
		  	cls();
	      	mainmenu(i,pilihan, x);
			return 0;
		}
		else{
	      	printf ("Masukkan pilihan yang valid");
		  	Sleep(1000);
		  	cls();
	  	}
	}
}
