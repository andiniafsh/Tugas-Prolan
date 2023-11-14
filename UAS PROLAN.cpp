#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>

struct WCU {
	char fnama[20];
	int tahun;
	int paper;
	int staff;
};

int partisiPaper(struct WCU a[20], int low, int high){
	struct WCU temp;
	int i = (low - 1); // index dari elemen ynag lebih kecil dan mengindikasikan posisi 
						//pivot yang benar sejauh ini
	for(int j = low; j<=(high-1);j++){
		//j adalah indeks array
		if(a[j].paper < a[high].paper) {
			i++;
			temp = a[i]; 
			a[i] = a[j];
			a[j] = temp;
		}
	}
	// memindahkan pivot di posisi yang benar
	temp = a[i+1];
	a[i+1] = a[high];
	a[high] = temp;
	return (i+1);
}

void quickSortPaper(struct WCU a[20], int low, int high){
	if(low<high) {
		/* fix adalah index dari partisi, a[fix] skrng sudah di posisi yang benar*/
		int fix = partisiPaper(a, low, high);
		
		quickSortPaper(a, low, fix-1); // sebelum fix
		quickSortPaper(a, fix+1,high); // sesudah fix
		
	}
}

int partisiStaff(struct WCU a[20], int low, int high){
	struct WCU temp;
	int i = (low - 1); // index dari elemen ynag lebih kecil dan mengindikasikan posisi 
						//pivot yang benar sejauh ini
	for(int j = low; j<=(high-1);j++){
		//j adalah indeks array
		if(a[j].staff < a[high].staff) { //(a[high].staff sebagai pivot
			i++;
			temp = a[i]; 
			a[i] = a[j];
			a[j] = temp;
		}
	}
	// memindahkan pivot di posisi yang benar
	temp = a[i+1];
	a[i+1] = a[high];
	a[high] = temp;
	return (i+1);
}

void quickSortStaff(struct WCU a[20], int low, int high){
	if(low<high) {
		/* fix adalah index dari partisi, a[fix] skrng sudah di posisi yang benar*/
		int fix = partisiStaff(a, low, high);
		
		quickSortStaff(a, low, fix-1); //sebelum fix
		quickSortStaff(a, fix+1,high); //sesudah fix
		
	}
}

int partisiTahun(struct WCU a[20], int low, int high){
	struct WCU temp;
	int i = (low - 1); // index dari elemen ynag lebih kecil dan mengindikasikan posisi 
						//pivot yang benar sejauh ini
	for(int j = low; j<=(high-1);j++){
		//j adalah indeks array
		if(a[j].tahun < a[high].tahun) { //(a[high].staff sebagai pivot
			i++;
			temp = a[i]; 
			a[i] = a[j];
			a[j] = temp;
		}
	}
	// memindahkan pivot di posisi yang benar
	temp = a[i+1];
	a[i+1] = a[high];
	a[high] = temp;
	return (i+1);
}

void quickSortTahun(struct WCU a[20], int low, int high){
	if(low<high) {
		/* fix adalah index dari partisi, a[fix] skrng sudah di posisi yang benar*/
		int fix = partisiTahun(a, low, high);
		
		quickSortTahun(a, low, fix-1); //sebelum fix
		quickSortTahun(a, fix+1,high); //sesudah fix
		
	}
}


int main () {
	int  j = -1; //buat loop struct baru di sorrting
	int pil;
	char again; // untuk mengulang pilihan menu
	FILE *modul1;
	
	printf("===================================\n");
	printf("===PROGRAM MENAMPILAKAN DATA WCU===\n");
	printf("===================================\n");
	printf("1. Menampilkan keseluruhan data WCU\n");
	printf("2. Menampilkan Program Informasi Statistik\n");
	printf("3. Menampilkan hasil sorting data WCU\n");
	printf("4. Melakukan Search Data WCU\n");
	in:
	printf("Masukkan Tahun pilihan Anda (1-4): ");
	scanf("%d", &pil);
	
	if (pil == 1){
					// buka file untuk ditulis
			modul1 = fopen ("WCU.txt", "w");
			if (modul1 == NULL) {
				fprintf(stderr, "\n File Error");
				exit(1);
			}
			struct WCU DataWCU[100] = {
				{"IPB", 2020, 9212, 17424},
				{"IPB", 2021, 9172, 19692},
				{"IPB", 2022, 2476, 23760},
				{"ITB", 2020, 10804, 13326},
				{"ITB", 2021, 11226, 13650},
				{"ITB", 2022, 2300, 16038},
				{"ITS", 2020, 7290, 9354},
				{"ITS", 2021, 7730, 10038},
				{"ITS", 2022, 1806, 9720},
				{"UNAIR", 2020, 15118, 26754},
				{"UNAIR", 2021, 10870, 26646},
				{"UNAIR", 2022, 2726, 26520},
				{"UB", 2020, 8446, 18012},
				{"UB", 2021, 8248, 18756},
				{"UB", 2022, 1508, 19488},
				{"UNDIP", 2020, 8804, 15804},
				{"UNDIP", 2021, 7794, 21336},
				{"UNDIP", 2022, 1672, 23982},
				{"UGM", 2020, 13926, 29124},
				{"UGM", 2021, 14852, 28950},
				{"UGM", 2022, 3780, 30540}
			};
			
			// menulis struct ke dalam file
			for(int i=0;i<=20;i++){
				fwrite (&DataWCU[i], sizeof(struct WCU), 1, modul1);
			}
			
			if(fwrite != 0)
				printf("konten berhasil tertulis!\n");
			else 
				printf("error!\n");
			
			// Menutup file
			fclose (modul1);
			
			FILE *mdl1;
			struct WCU data[100];
			mdl1 = fopen ("WCU.txt", "r");
			if (mdl1 == NULL) {
			fprintf(stderr, "\n ERROR dalam membuka file\n");
			exit (1);
			}
			
			// membaca konten file sampai akhir file 
			while(fread(&data, sizeof(struct WCU), 1, modul1)){
				printf ("nama = %s, tahun = %i, jumlah paper = %i, jumlah staff = %i\n", 
				data[0].fnama, data[0].tahun, data[0].paper, data[0].staff);
			}
			
			fclose (mdl1);
	}
	else if(pil==2){
							// buka file untuk ditulis
				modul1 = fopen ("WCU.txt", "w");
				if (modul1 == NULL) {
					fprintf(stderr, "\n File Error");
					exit(1);
				}
				struct WCU DataWCU[100] = {
					{"IPB", 2020, 9212, 17424},
					{"IPB", 2021, 9172, 19692},
					{"IPB", 2022, 2476, 23760},
					{"ITB", 2020, 10804, 13326},
					{"ITB", 2021, 11226, 13650},
					{"ITB", 2022, 2300, 16038},
					{"ITS", 2020, 7290, 9354},
					{"ITS", 2021, 7730, 10038},
					{"ITS", 2022, 1806, 9720},
					{"UNAIR", 2020, 15118, 26754},
					{"UNAIR", 2021, 10870, 26646},
					{"UNAIR", 2022, 2726, 26520},
					{"UB", 2020, 8446, 18012},
					{"UB", 2021, 8248, 18756},
					{"UB", 2022, 1508, 19488},
					{"UNDIP", 2020, 8804, 15804},
					{"UNDIP", 2021, 7794, 21336},
					{"UNDIP", 2022, 1672, 23982},
					{"UGM", 2020, 13926, 29124},
					{"UGM", 2021, 14852, 28950},
					{"UGM", 2022, 3780, 30540}
				};
				
				// menulis struct ke dalam file
				for(int i=0;i<=20;i++){
					fwrite (&DataWCU[i], sizeof(struct WCU), 1, modul1);
				}
				
				if(fwrite != 0)
					printf("konten berhasil tertulis!\n");
				else 
					printf("error!\n");
				
				// Menutup file
				fclose (modul1);
				
				FILE *mdl1;
				struct WCU data[100];
				mdl1 = fopen ("WCU.txt", "r");
				if (mdl1 == NULL) {
				fprintf(stderr, "\n ERROR dalam membuka file\n");
				exit (1);
				}
				
				// membaca konten file sampai akhir file 
				while(fread(&data, sizeof(struct WCU), 1, modul1)){
					printf ("nama = %s, tahun = %i, jumlah paper = %i, jumlah staff = %i\n", 
					data[0].fnama, data[0].tahun, data[0].paper, data[0].staff);
				}
				
				fclose (mdl1);
				int cho;
				printf("===============================================\n");
				printf("<<<<<<<<<<Program Informasi Statistik>>>>>>>>>>\n");
				printf("Masukkan pilihan Anda: ");
				printf("\n1.Rata-rata paper dan Staff berdasarkan tahun\n");
				printf("\n2.Data terbesar dan terkecil dari paper berdasarkan tahun\n");
				printf("\n3.Data terbanyak dan tersedikit dari staff berdasarkan tahun\n");
				scanf("%d", &cho);
				
				if(cho==1){
					//MEAN
			    
				int pil,info, jumlah_paper=0, jumlah_staff, rata_paper, rata_staff, banyak_data;
				printf("Masukkan Tahun pilihan Anda: ");
				printf("\n1.2022  ||2. 2021 ||3.  2020\n");
				scanf("%d", &pil);
				
				switch(pil){
					case 1:
						for(int i=1;i<=20;i++){
						if (DataWCU[i].tahun==2022){
							jumlah_paper=jumlah_paper+DataWCU[i].paper;
							rata_paper=jumlah_paper/7;
							jumlah_staff=jumlah_staff+DataWCU[i].staff;
							rata_staff=jumlah_staff/7;
						}
					}
						printf("Jumlah total keseluruhan paper Tahun 2022 =  %i \n", jumlah_paper);
						printf("Jumlah total keseluruhan Staff Tahun 2022 =  %i\n", jumlah_staff);
						printf("Mean Paper=  %i\n", rata_paper);
						printf("Mean Staff=  %i", rata_staff);
						break;
					case 2:
						for(int i=1;i<=20;i++){
						if (DataWCU[i].tahun==2021){
							jumlah_paper=jumlah_paper+DataWCU[i].paper;
							rata_paper=jumlah_paper/7;
							jumlah_staff=jumlah_staff+DataWCU[i].staff;
							rata_staff=jumlah_staff/7;
						}
					}
						printf("Jumlah total keseluruhan paper Tahun 2022 =  %i \n", jumlah_paper);
						printf("Jumlah total keseluruhan Staff Tahun 2022 =  %i\n", jumlah_staff);
						printf("Mean Paper=  %i\n", rata_paper);
						printf("Mean Staff=  %i", rata_staff);
						break;
					case 3:
						for(int i=1;i<=20;i++){
						if (DataWCU[i].tahun==2020){
							jumlah_paper=jumlah_paper+DataWCU[i].paper;
							rata_paper=jumlah_paper/7;
							jumlah_staff=jumlah_staff+DataWCU[i].staff;
							rata_staff=jumlah_staff/7;
						}
					}
						printf("Jumlah total keseluruhan paper Tahun 2022 =  %i \n", jumlah_paper);
						printf("Jumlah total keseluruhan Staff Tahun 2022 =  %i\n", jumlah_staff);
						printf("Mean Paper=  %i\n", rata_paper);
						printf("Mean Staff=  %i", rata_staff);
						break;
					default:
						printf("Error! pilihan is not correct");
				}
			}
				else if(cho==2){
					int pil;
					printf("Masukkan Tahun pilihan Anda: ");
					printf("\n1.2020  ||2. 2021 ||3.  2022\n");
					scanf("%d", &pil);
						//Data terbanyak dan terkecil paper
					int max_paper=DataWCU[0].paper&&DataWCU[0].tahun;
					int min_paper=DataWCU[0].paper;
					
					if (pil==1){
						//maksimal
						for(int i=0; i<=20; i++){
							if (DataWCU[i].tahun==2020){
								if(DataWCU[i].paper >= max_paper){
									max_paper=DataWCU[i].paper;
								}
							}
						}
						printf("\nData paper terbesar tahun 2020: %d",max_paper);
						//minimal
						for(int i=0; i<=20; i++){
							if (DataWCU[i].tahun==2020){
								if(DataWCU[i].paper <=min_paper){
									min_paper=DataWCU[i].paper;
								}
							}
						}
						printf("\nData paper terkecil tahun 2020: %d",min_paper);
					}
					else if (pil==2){
						//maksimal
						for(int i=0; i<=20; i++){
							if (DataWCU[i].tahun==2021){
								if(DataWCU[i].paper >= max_paper){
									max_paper=DataWCU[i].paper;
								}
							}
						}
						printf("\nData paper terbesar tahun 2021: %d",max_paper);
						//minimal
						for(int i=0; i<=20; i++){
							if (DataWCU[i].tahun==2021){
								if(DataWCU[i].paper <=min_paper){
									min_paper=DataWCU[i].paper;
								}
							}
						}
						printf("\nData paper terkecil tahun 2021: %d",min_paper);
					}
					else if (pil==3){
						//maksimal
						for(int i=0; i<=20; i++){
							if(DataWCU[i].tahun==2022){
								if(DataWCU[i].paper >= max_paper){
									max_paper=DataWCU[i].paper;
								}
							}
						}
						printf("\nData paper terbesar tahun 2022: %d",max_paper);
						//minimal
						for(int i=0; i<=20; i++){
							if (DataWCU[i].tahun==2022){
								if(DataWCU[i].paper <=min_paper){
									min_paper=DataWCU[i].paper;
								}
							}
						}
						printf("\nData paper terkecil tahun 2022: %d",min_paper);
					}
					else{
						printf("Error! pilihan is not correct");
					}
				}
				
				else if(cho==3){
					int pil;
					printf("Masukkan Tahun pilihan Anda: ");
					printf("\n1.2020  ||2. 2021 ||3.  2022\n");
					scanf("%d", &pil);
						
					//Data terbanyak dan terkecil staff
					int max_staff=DataWCU[0].staff&&DataWCU[0].tahun;
					int min_staff=DataWCU[0].staff;
					
					if (pil==1){
						//maksimal
						int max_staff=DataWCU[0].staff;
						for(int i=0; i<=20; i++){
							if (DataWCU[i].tahun==2020){
								if(DataWCU[i].staff >= max_staff){
									max_staff = DataWCU[i].staff;
								}
							}
						}
						printf("\nData staff terbanyak tahun 2020: %d",max_staff);
						//minimal
						int min_staff=DataWCU[0].staff;
						for(int i=0; i<=20; i++){
							if (DataWCU[i].tahun==2020){
								if(DataWCU[i].staff <=min_staff){
									min_staff = DataWCU[i].staff;
								}
							}
						}
						printf("\nData staff tersedikit tahun 2020: %d",min_staff);	
					}
					else if(pil==2){
						//maksimal
						int max_staff=DataWCU[0].staff;
						for(int i=0; i<=20; i++){
							if (DataWCU[i].tahun==2021){
								if(DataWCU[i].staff >= max_staff){
									max_staff = DataWCU[i].staff;
								}
							}
						}
						printf("\nData staff terbanyak tahun 2021: %d",max_staff);
						//minimal
						int min_staff=DataWCU[0].staff;
						for(int i=0; i<=20; i++){
							if (DataWCU[i].tahun==2021){
								if(DataWCU[i].staff <=min_staff){
									min_staff = DataWCU[i].staff;
								}
							}
						}
						printf("\nData staff tersedikit tahun 2021: %d",min_staff);	
					}
					else if(pil==3){
						//maksimal
						int max_staff=DataWCU[0].staff;
						for(int i=0; i<=20; i++){
							if (DataWCU[i].tahun==2022){
								if(DataWCU[i].staff >= max_staff){
									max_staff = DataWCU[i].staff;
								}
							}
						}
						printf("\nData staff terbanyak tahun 2022: %d",max_staff);
						//minimal
						int min_staff=DataWCU[0].staff;
						for(int i=0; i<=20; i++){
							if (DataWCU[i].tahun==2022){
								if(DataWCU[i].staff <=min_staff){
									min_staff = DataWCU[i].staff;
								}
							}
						}
						printf("\nData staff tersedikit tahun 2022: %d",min_staff);
					}
					else{
						printf("Error! pilihan is not correct");
					}
				}
				
				fclose (mdl1);
	}
	else if (pil==3){
				int  j = -1; //buat loop struct baru di sorrting
				FILE *modul1;
				
				// buka file untuk ditulis
				modul1 = fopen ("WCU.txt", "w");
				if (modul1 == NULL) {
					fprintf(stderr, "\n File Error");
					exit(1);
				}
				struct WCU DataWCU[100] = {
					{"IPB", 2020, 9212, 17424},
					{"IPB", 2021, 9172, 19692},
					{"IPB", 2022, 2476, 23760},
					{"ITB", 2020, 10804, 13326},
					{"ITB", 2021, 11226, 13650},
					{"ITB", 2022, 2300, 16038},
					{"ITS", 2020, 7290, 9354},
					{"ITS", 2021, 7730, 10038},
					{"ITS", 2022, 1806, 9720},
					{"UNAIR", 2020, 15118, 26754},
					{"UNAIR", 2021, 10870, 26646},
					{"UNAIR", 2022, 2726, 26520},
					{"UB", 2020, 8446, 18012},
					{"UB", 2021, 8248, 18756},
					{"UB", 2022, 1508, 19488},
					{"UNDIP", 2020, 8804, 15804},
					{"UNDIP", 2021, 7794, 21336},
					{"UNDIP", 2022, 1672, 23982},
					{"UGM", 2020, 13926, 29124},
					{"UGM", 2021, 14852, 28950},
					{"UGM", 2022, 3780, 30540}
				};
				
				// menulis struct ke dalam file
				for(int i=0;i<=20;i++){
					fwrite (&DataWCU[i], sizeof(struct WCU), 1, modul1);
				}
				
				if(fwrite != 0)
					printf("konten berhasil tertulis!\n");
				else 
					printf("error!\n");
				
				// Menutup file
				fclose (modul1);
				
				FILE *mdl1;
				struct WCU data[100];
				mdl1 = fopen ("WCU.txt", "r");
				if (mdl1 == NULL) {
				fprintf(stderr, "\n ERROR dalam membuka file\n");
				exit (1);
				}
				
				// membaca konten file sampai akhir file 
				while(fread(&data, sizeof(struct WCU), 1, modul1)){
					printf ("nama = %s, tahun = %i, jumlah paper = %i, jumlah staff = %i\n", 
					data[0].fnama, data[0].tahun, data[0].paper, data[0].staff);
				}
				
				fclose (mdl1);
	
				int pilih;
				int thn;
				quickSortPaper(DataWCU, 0, 20);
				printf("\nMau sorting paper atau jumlah staff?(paper=1, staff=2?): "); scanf("%i", &pilih);
				if(pilih==1){
					printf("\nMau sorting paper keseluruhan atau tahun 2020, 2021, 2022? (seluruh=1, 2020=2, 2021=3, 2022=4?): "); 
					scanf("%i", &thn);
					switch(thn){
						case 1:
								printf("========================================================================\n");
						    	printf("||    Jumlah Paper  ||   Nama     ||      Tahun       ||  Jumlah Staff ||\n");
						    	printf("========================================================================\n");
							for (int i = 0; i<=20; i++){
								printf("      %i             %s               %i                   %i        \n", 
										DataWCU[i].paper, DataWCU[i].fnama, DataWCU[i].tahun, DataWCU[i].staff);
							}
							
						break;
							case 2:
							struct WCU staff20[6];
							for(int i=0; i<=20; i++){
								if(DataWCU[i].tahun==2020){
									j++;
									staff20[j] = DataWCU[i];
								}
							}
								printf("========================================================================\n");
						    	printf("||    Jumlah Paper  ||   Nama     ||      Tahun       ||  Jumlah Staff ||\n");
						    	printf("========================================================================\n");
							for (int i = 0; i<=6;i++){
								printf("      %i             %s               %i                   %i        \n", 
								staff20[i].paper, staff20[i].fnama, staff20[i].tahun, staff20[i].staff);
							}
						break;
						case 3:
							struct WCU staff21[6];
							for(int i=0; i<=20; i++){
								if(DataWCU[i].tahun==2021){
									j++;
									staff21[j] = DataWCU[i];
								}
							}
								printf("========================================================================\n");
						    	printf("||    Jumlah Paper  ||   Nama     ||      Tahun       ||  Jumlah Staff ||\n");
						    	printf("========================================================================\n");
							for (int i=0; i<=6;i++){
								printf("      %i             %s               %i                   %i        \n", 
								staff20[i].paper, staff20[i].fnama, staff20[i].tahun, staff20[i].staff);
							}
						break;
						case 4:
							struct WCU staff22[6];
							for(int i=0; i<=20; i++){
								if(DataWCU[i].tahun==2022){
									j++;
									staff22[j] = DataWCU[i];
								}
							}
								printf("========================================================================\n");
						    	printf("||    Jumlah Paper  ||   Nama     ||      Tahun       ||  Jumlah Staff ||\n");
						    	printf("========================================================================\n");
							for (int i = 0; i<=6;i++){
								printf("      %i             %s               %i                   %i        \n", 
								staff20[i].paper, staff20[i].fnama, staff20[i].tahun, staff20[i].staff);
							}
						break;
						default:
							printf("Inputan salah!!!!");
						
						}
					}
					else if (pilih==2){
					quickSortStaff(DataWCU, 0, 20);
					printf("\nMau sorting staff keseluruhan atau tahun 2020, 2021, 2022? (seluruh=1, 2020=2, 2021=3, 2022=4?): "); scanf("%i", &thn);
					switch(thn){
						case 1:
								printf("========================================================================\n");
						    	printf("||   Jumlah Staff     ||      Nama     ||     Tahun   ||  Jumlah Paper ||\n");
						    	printf("========================================================================\n");
								for (int i = 0; i<=20; i++){
								printf("      %i             %s               %i                   %i        \n",  
								DataWCU[i].staff, DataWCU[i].fnama, DataWCU[i].tahun, DataWCU[i].paper);
							}
						break;
						case 2:
							struct WCU staff20[6];
							for(int i=0; i<=20; i++){
								if(DataWCU[i].tahun==2020){
									j++;
									staff20[j] = DataWCU[i];
								}
							}
								printf("========================================================================\n");
						    	printf("||   Jumlah Staff     ||      Nama     ||     Tahun   ||  Jumlah Paper ||\n");
						    	printf("========================================================================\n");
							for (int i = 0; i<=6;i++){
								printf("      %i             %s               %i                   %i        \n",  
								DataWCU[i].staff, DataWCU[i].fnama, DataWCU[i].tahun, DataWCU[i].paper);
							}
						break;
						case 3:
							struct WCU staff21[6];
							for(int i=0; i<=20; i++){
								if(DataWCU[i].tahun==2021){
									j++;
									staff21[j] = DataWCU[i];
								}
							}
								printf("========================================================================\n");
						    	printf("||   Jumlah Staff     ||      Nama     ||     Tahun   ||  Jumlah Paper ||\n");
						    	printf("========================================================================\n");
							for (int i=0; i<=6;i++){
								printf("      %i             %s               %i                   %i        \n",  
								DataWCU[i].staff, DataWCU[i].fnama, DataWCU[i].tahun, DataWCU[i].paper);
							}
						break;
						case 4:
							struct WCU staff22[6];
							for(int i=0; i<=20; i++){
								if(DataWCU[i].tahun==2022){
									j++;
									staff22[j] = DataWCU[i];
								}
							}
								printf("========================================================================\n");
						    	printf("||   Jumlah Staff     ||      Nama     ||     Tahun   ||  Jumlah Paper ||\n");
						    	printf("========================================================================\n");
							for (int i = 0; i<=6;i++){
								printf("      %i             %s               %i                   %i        \n",  
								DataWCU[i].staff, DataWCU[i].fnama, DataWCU[i].tahun, DataWCU[i].paper);
							}
						break;
						default:
							printf("Inputan salah!!!!");
						
						}
					}
			
				else{
					printf("Inputan salah!!!!");
				}
			
				return 0;
	}
	else if (pil==4){
				int  j = -1; //buat loop struct baru di sorrting
				FILE *modul1;
				
				// buka file untuk ditulis
				modul1 = fopen ("WCU.txt", "w");
				if (modul1 == NULL) {
					fprintf(stderr, "\n File Error");
					exit(1);
				}
				struct WCU DataWCU[100] = {
					{"IPB", 2020, 9212, 17424},
					{"IPB", 2021, 9172, 19692},
					{"IPB", 2022, 2476, 23760},
					{"ITB", 2020, 10804, 13326},
					{"ITB", 2021, 11226, 13650},
					{"ITB", 2022, 2300, 16038},
					{"ITS", 2020, 7290, 9354},
					{"ITS", 2021, 7730, 10038},
					{"ITS", 2022, 1806, 9720},
					{"UNAIR", 2020, 15118, 26754},
					{"UNAIR", 2021, 10870, 26646},
					{"UNAIR", 2022, 2726, 26520},
					{"UB", 2020, 8446, 18012},
					{"UB", 2021, 8248, 18756},
					{"UB", 2022, 1508, 19488},
					{"UNDIP", 2020, 8804, 15804},
					{"UNDIP", 2021, 7794, 21336},
					{"UNDIP", 2022, 1672, 23982},
					{"UGM", 2020, 13926, 29124},
					{"UGM", 2021, 14852, 28950},
					{"UGM", 2022, 3780, 30540}
				};
				
				// menulis struct ke dalam file
				for(int i=0;i<=20;i++){
					fwrite (&DataWCU[i], sizeof(struct WCU), 1, modul1);
				}
				
				if(fwrite != 0)
					printf("konten berhasil tertulis!\n");
				else 
					printf("error!\n");
				
				// Menutup file
				fclose (modul1);
				
				FILE *mdl1;
				struct WCU data[100];
				mdl1 = fopen ("WCU.txt", "r");
				if (mdl1 == NULL) {
				fprintf(stderr, "\n ERROR dalam membuka file\n");
				exit (1);
				}
				
				// membaca konten file sampai akhir file 
				while(fread(&data, sizeof(struct WCU), 1, modul1)){
					printf ("nama = %s, tahun = %i, jumlah paper = %i, jumlah staff = %i\n", 
					data[0].fnama, data[0].tahun, data[0].paper, data[0].staff);
				}
				
				fclose (mdl1);
				printf("\nHasil sorting data berdasarkan tahun");
				quickSortTahun(DataWCU, 0, 20);
				printf("\n");
				for (int i = 0; i<=20; i++){
								printf("nama = %s, tahun = %i, jumlah paper = %i, jumlah staff = %i\n", 
								DataWCU[i].fnama, DataWCU[i].tahun, DataWCU[i].paper, DataWCU[i].staff);
							}
				int n=21;
				int f=0;
				int m;
				int i=0;
				m=sqrt(n);
				int target;
				printf("\nMasukkan tahun yang ingin dicari (2020/2021/2022): ");
				scanf("%i", &target);
				while(DataWCU[m].tahun <= target && m < n) {
					i=m;
					m += sqrt(n);
					if(m>n-1){ // kalau m melebihi ukuran array
						m=n;
					}
				}
				
				for(int x=0; x<=m; x++){ //linier search
					if(DataWCU[x].tahun==target){
						printf("\n\nYang dicari ada di index : %i \nnama = %s \ntahun = %i \npaper = %i \nstaff = %i"
						, x, DataWCU[x].fnama, DataWCU[x].tahun, DataWCU[x].paper, DataWCU[x].staff);
						f=1;
					}
				}
				if(f==0){
					printf("Tidak ditemukan");
				}
			
				return 0;
	}
	else {
		printf("Error! pilihan is not correct");
	}
	printf ("\nApakah Anda Ingin Melanjutkan Pilihan Menu Lagi ? (Y/N) ");
					scanf ("%s", &again);
					    
					if (again=='y' || again=='Y'){ 
						goto in;
					} 
			        else {
						return 0;
			        }
}
	
