

#include <stdio.h>
#include <conio.h>

struct Kisi{
	char ad[25];
	char soyad[25];
	int yas;
	char telno[12];//05001112233
	
};
void menu_bas();
void print_rehber(struct Kisi *);
void kisi_ekle(struct Kisi *);
void dosyaya_kaydet(struct Kisi*);
void dosyadan_oku(struct Kisi*);
int main(){
	int secim, flag = 0;
	
	struct Kisi rehber[50];
	rehber[0].yas = -1;
	dosyadan_oku(rehber);
	
	while(flag == 0){
	    menu_bas();
	    scanf("%d", &secim);
	
	    switch(secim){
		    case 1:
			    print_rehber(rehber);
			    break;
		    case 2:
			    kisi_ekle(rehber);
			    break;
			case 9:
				flag = 1;
				dosyaya_kaydet(rehber);
				printf("Cikmak icin bir tusa basiniz");
				break;
		    default:
			    printf("Yanlis secim yaptiniz!\n");
			 
	    }
	    getch();
	}

	return 0;
}
void dosyadan_oku(struct Kisi *rehber){
	FILE *hedef_dosya = fopen("veritabani.txt","r+");
	if(hedef_dosya == NULL)
	    return;
	
	int s;
	for(s=0; s<50; s++){
		fscanf(hedef_dosya, "%s %s %d %s\n",rehber[s].ad, rehber[s].soyad, &(rehber[s].yas), rehber[s].telno);
		if(feof(hedef_dosya))
		break;
		
	}
	rehber[s+1].yas = -1;
	
	
}
void dosyaya_kaydet(struct Kisi *rehber){
	FILE *hedef_dosya = fopen("veritabani.txt", "w+");
	
	int s;
	for(s = 0; s < 50; s++){
		if(rehber[s].yas == -1)
		    break;
		    
		
	   fprintf(hedef_dosya,"%s %s %d %s\n",rehber[s].ad,rehber[s].soyad, rehber[s].yas, rehber[s].telno);
		
	}
	
	fclose(hedef_dosya);
	

}
void print_rehber(struct Kisi *rehber){
	int s;
	for(s = 0; s < 50; s++){
		if(rehber[s].yas == -1)
		    break;
		    
		
	
		printf("%d- %s\t%s\t%d\t%s\n", s+1, rehber[s].ad, rehber[s].soyad, rehber[s].yas, rehber[s].telno);
		
	}
	
}
void kisi_ekle(struct Kisi *rehber){
	int s;
	for(s = 0;s < 50; s++){
		if(rehber[s].yas == -1)
		break;
	}
	
	printf("Kisinin adi:");
	scanf("%s",rehber[s].ad);
	printf("Soyadi: ");
	scanf("%s", rehber[s].soyad);
	printf("Yasi: ");
	scanf("%d", &(rehber[s].yas));
	printf("Numarasi: ");
	scanf("%s", rehber[s].telno);
	
	rehber[s+1].yas = -1;
	
	printf("Kisi basariyla eklendi!");
	
	
}
void menu_bas(){
	printf("Telefon Rehberi Menusu\n");
	printf("----------------------------\n\n");
	printf("1- Tum Kisileri Yazdir\n");
	printf("2- Rehbere Kisi Ekle\n");
	printf("9- Programi Sonlandir\n");
	printf("\nSeciminizi Giriniz: ");
}	

	
	
