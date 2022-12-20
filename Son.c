#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//STRUCT YAPILARI

struct Telefon
{
    int urunKodu;
    char marka[20];
    char isim[50];
    int fiyat;
    char ozellik[500];

}telefonlar[14];

struct Bilgisayar
{
    int urunKodu;
    char marka[20];
    char isim[50];
    int fiyat;
    char ozellik[500];
    
}bilgisayarlar[15];

struct Tablet
{
    int urunKodu;
    char marka[20];
    char isim[50];
    int fiyat;
    char ozellik[500];
    
}tabletler[10];

//FONKSİYON İMZALARI
void fiyataGoreGetir();
void sepete_Ekle();
void sepetiGoster();
void tumunusirala();
void markaSirala();
int indirimOyunu();
void toplamTutarYazdir();
void tutarHesapla();


//Sepetteki ürünlere kodları aracılığıyla erişmek için dizi kullandık.
int sepettekiUrunler[20];
int k=0;
int sayac=0;
//Sepetteki ürünlerin fiyatları toplamı için kullandığımız değişken
int toplamTutar=0;


int main()
{
    //STRUCT İÇİNDEKİ ALANLARA DOSYA OKUMA YOLUYLA DEĞER ATAMASI

    //Telefonların değer ataması
    FILE *dosya1;

    if((dosya1=fopen("TELEFONLAR.txt","r"))!=NULL)
    {
        for(int i=0;i<14;i++)
        {
            fscanf(dosya1,"%d",&telefonlar[i].urunKodu);
            fscanf(dosya1,"%s",&telefonlar[i].marka);
            fscanf(dosya1,"%s",&telefonlar[i].isim);
            fscanf(dosya1,"%d",&telefonlar[i].fiyat);
        }
    }

    else
    {
        printf("Dosya bulunamadi");
    }

    fclose(dosya1);

    //Bilgisayarların değer ataması

    FILE *dosya3;
    
    if((dosya3=fopen("bilgisayarlar.txt","r"))!=NULL)
    {
        for (int i=0;i<15;i++)
        {
            fscanf(dosya3,"%d",&bilgisayarlar[i].urunKodu);
            fscanf(dosya3,"%s",&bilgisayarlar[i].marka);
            fscanf(dosya3,"%s",&bilgisayarlar[i].isim);
            fscanf(dosya3,"%d",&bilgisayarlar[i].fiyat);    
        }
            
    }
    
    else
    {
        printf("Dosya bulunamadi");
    }

    fclose(dosya3);

    //Tabletlerin değer ataması

    FILE *dosya2;

    if((dosya2=fopen("tabletler.txt","r"))!=NULL)
    {
        for (int  i =0; i < 10; i++)
        {
            fscanf(dosya2,"%d",&tabletler[i].urunKodu);
            fscanf(dosya2,"%s",&tabletler[i].marka);
            fscanf(dosya2,"%s",&tabletler[i].isim);
            fscanf(dosya2,"%d",&tabletler[i].fiyat);
        }
            
    }

    else
    {
        printf("Dosya bulunamadi");
    }

    fclose(dosya2);

    int menusecim=0;

    printf("\n\n                               -----------------------------------------------------------------\n");
    printf("                               |             <  404 TEKNOSTORE'A HOSGELDINIZ  >               |");
    printf("\n                               -----------------------------------------------------------------\n\n");

    do
    {
        printf("\n\n======================================================== MENU ========================================================\n");
        printf("1-) Tum urunleri gormek icin 1'i tuslayiniz.\n\n");
        printf("2-) Istediginiz markanin urunlerini gormek icin 2'yi tuslayaniz.\n\n");
        printf("3-) Belirlediginiz fiyat araligindaki urunleri gormek icin 3'u tuslayiniz.\n\n");
        printf("4-) Sepetinize urun eklemek icin 4'u tuslayiniz.\n\n");
        printf("5-) Sepetinizi goruntulemek icin 5'i tuslayiniz.\n\n");
        printf("6-) Odenecek tutari goruntulemek icin 6'yi tuslayiniz.\n\n");
        printf("7-) Indirim oyununu oynamak icin 7'yi tuslayiniz\n\n");
        printf("8-) Cikmak icin opsiyonlar disinda herhangi bir sayi tuslayiniz.\n\n ");
        printf("======================================================================================================================\n\n");
        scanf("%d",&menusecim);
        
        switch (menusecim)
        {
            case 1:
                tumunusirala();
        
            break;

            case 2:
                markaSirala();
            
            break;

            case 3:
                fiyataGoreGetir();

            break;

            case 4:
                sepete_Ekle();    

            break;

            case 5:
                sepetiGoster();
            
            break;

            case 6:
                toplamTutarYazdir();
            break;

            case 7:
                indirimOyunu();
            break;

        }

    } while (menusecim==1 || menusecim==2 || menusecim==3 || menusecim==4 || menusecim==5 || menusecim==6 || menusecim==7);
    
   
    printf("\nYine bekleriz efenim :)");
    
    return 0;
}

//FONKSİYONLAR

void fiyataGoreGetir()
{
    int baslangic,bitis;
    printf("Fiyat arastirmasi yapmak istediginiz araligi giriniz (baslangic-bitis):\n");
    scanf("%d%d",&baslangic,&bitis);

    if(baslangic>bitis)
    {
        printf("\n\nBaslangic degeri bitis degerinden buyuk olamaz!!!");
    }

    else
    {
        printf("Hangi kategoride fiyat arastirmasi yapmak istediginizi secin:\n1-Telefon 2-Bilgisayar 3-Tablet:");
        int secim;
        scanf("%d",&secim);

        switch(secim)
        {
            case 1:

                for(int i=0;i<14;i++)
                {
                    if(baslangic<telefonlar[i].fiyat && telefonlar[i].fiyat<bitis)
                    {
                        printf("%d %s %s %d\n",telefonlar[i].urunKodu,telefonlar[i].marka,telefonlar[i].isim,telefonlar[i].fiyat);
                    }
                }

            break;

            case 2:

                for(int i=0;i<15;i++)
                {
                    if(baslangic<bilgisayarlar[i].fiyat && bilgisayarlar[i].fiyat<bitis)
                    {
                        printf("%d %s %s %d\n",bilgisayarlar[i].urunKodu,bilgisayarlar[i].marka,bilgisayarlar[i].isim,bilgisayarlar[i].fiyat);
                    }
                }

            break;

            case 3:
            
                for(int i=0;i<10;i++)
                {
                    if(baslangic<tabletler[i].fiyat && tabletler[i].fiyat<bitis)
                    {
                        printf("%d %s %s %d\n",tabletler[i].urunKodu,tabletler[i].marka,tabletler[i].isim,tabletler[i].fiyat);
                    }
                }

            break;
        }
    } 
} 

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void sepete_Ekle()
{
    
    int ksecim = 0;
    int kod;
    int syc01=0;//Girilen degerin dogru olup olmadıgını kontrol etmek icin konulan sayac

    do // do-while yapısı kullancının istediği kadar ürünü sepete eklemesini sağlar
    {
        printf("\n\nSepete eklemek istediginiz urunun kodunu giriniz:\n");
        scanf("%d",&kod);

        printf("\n");

            //Bu üç for yapısının amacı kullanıcının girdiği kod ile ürünlerin kodlarının eşleşme durumunu kontrol eder
            for (int i = 0; i < 14 ; i++) 
            {
                if (telefonlar[i].urunKodu == kod)
                {
                    syc01++;
                }
                
            }

            for (int i = 0; i < 15 ; i++)
            {
                if (bilgisayarlar[i].urunKodu == kod)
                {
                    syc01++;
                }
                    
                }
        
            for (int i = 0; i < 10 ; i++)
            {
                if (tabletler[i].urunKodu == kod)
                {
                    syc01++;
                }
                    
            }

        //Karar mekanizmaları sayesinde kullanıcı tarafından girilen kodun doğruluğu veya yanlışlığına göre yapılacak işlemler belirlenir
        if (syc01==0)
        {
            printf("Yanlis urun kodu girdiniz.Lutfen tekrar deneyiniz");
            syc01=0;
        }
        else if (syc01 > 0)
        
        {
            if(k==19)
            {
            printf("Daha fazla urun ekleyemezsiniz.\n");
            }

            else
            {
                sepettekiUrunler[k]=kod;
                k++;
                sayac++;//Sepetteki ürün sayısı
            }

            printf("\n\nSepete urun eklemege devam etmek icin herhangi bir sayi tuslayiniz , sepetten cikmak icin 2'yi tuslayiniz.\n");
            scanf("%d",&ksecim);
            syc01=0;
        }

    }while (ksecim != 2 && k <= 19);

    tutarHesapla();
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void sepetiGoster()
{
    
    if (sayac >= 1)//Sepette ürün yoksa kullanıcıya uyarı yapan karar yapısı
    {  
        printf("\n\nSepetinizdeki Urunler:\n\n");
        
        for(int i=0;i<sayac;i++)//Sepetteki ürün sayısı kadar tarama yapılması için burda sayac değişkeni kullanıldı
        {
            //Bu üç for yapısında kullanıcının sepete eklemek için girdiği kod ile struct yapılarına atanmış ürün kodları karşılaştırılır,kodlar eşleşirse yazdırılır
            for(int k=0;k<14;k++)
            {
                if(sepettekiUrunler[i]==telefonlar[k].urunKodu)
                {
                    printf("%d %s %s %d\n",telefonlar[k].urunKodu,telefonlar[k].marka,telefonlar[k].isim,telefonlar[k].fiyat);
                    
                }
            }

            for(int k=0;k<15;k++)
            {
                if(sepettekiUrunler[i]==bilgisayarlar[k].urunKodu)
                {
                    printf("%d %s %s %d\n",bilgisayarlar[k].urunKodu,bilgisayarlar[k].marka,bilgisayarlar[k].isim,bilgisayarlar[k].fiyat);
                    
                }
            }

            for(int k=0;k<10;k++)
            {
                if(sepettekiUrunler[i]==tabletler[k].urunKodu)
                {
                    printf("%d %s %s %d\n",tabletler[k].urunKodu,tabletler[k].marka,tabletler[k].isim,tabletler[k].fiyat);
                    
                }
            }
        }
    }

    else
    {
        printf("\nSepetinizde urun bulunmamaktadir.Lutfen urun ekleyin.\n");
    }

    
    printf("\n\nOdenecek tutar:%d\n\n",toplamTutar);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void tumunusirala()//Envanterdeki ürünleri for yapısı sayesinde struct yapılarındaki dizileri tarayarak listeler
{
    printf("\n\n------------------------------------------------------------\n\n");
    printf("Butun Urunler : \n\n");
    printf("------------------------------------------------------------\n\n");

    for (int a = 0; a < 15; a++)
    {
        printf("%d %s %s %d\n",bilgisayarlar[a].urunKodu,bilgisayarlar[a].marka,bilgisayarlar[a].isim,bilgisayarlar[a].fiyat);
    }

    printf("\n\n------------------------------------------------------------\n\n");

    for (int b = 0; b < 10; b++)
    {
        printf("%d %s %s %d\n",tabletler[b].urunKodu,tabletler[b].marka,tabletler[b].isim,tabletler[b].fiyat);           
    }

    printf("\n\n------------------------------------------------------------\n\n\n\n");

    for (int i = 0; i < 14; i++)
    {
        printf("%d %s %s %d\n",telefonlar[i].urunKodu,telefonlar[i].marka,telefonlar[i].isim,telefonlar[i].fiyat);
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void markaSirala()
{
    int no=0;//Kullancının seçimini tutan değişken

    do
    {
        printf("\n\nListelemek istediginiz urunlerin markasini giriniz:\n\n");
        printf("1-Apple 2-Huawei 3-Samsung 4-Lenovo 5-Xiaomi\n\n"); 
        scanf("%d",&no);

        switch (no)//Seçilen markaya göre belirlenen case'e girer,for yapıısı yardımıyla structtaki bilgiler yazdırılır
        {
            case 1:

                printf("\n");
                for (int i = 0; i < 14 ; i++)
                {
                    if (!strcmp(telefonlar[i].marka,"Apple"))//strcmp FONKSİYONU İÇERİSİNDEKİ İKİ STRİNG İFADE AYNIYSA 0 DEĞERİNİ DÖNDÜRÜR.İF BLOĞUNA GİREBİLMESİ İÇİN DEĞİLİNİ ALDIK.
                    {
                        printf("%d %s %s %d\n",telefonlar[i].urunKodu,telefonlar[i].marka,telefonlar[i].isim,telefonlar[i].fiyat);
                    }
                }

                for (int i = 0; i < 15 ; i++)
                {
                    if (!strcmp(bilgisayarlar[i].marka,"Apple"))
                    {
                        printf("%d %s %s %d\n",bilgisayarlar[i].urunKodu,bilgisayarlar[i].marka,bilgisayarlar[i].isim,bilgisayarlar[i].fiyat);
                    }
                }
        
                for (int i = 0; i < 10 ; i++)
                {
                    if (!strcmp(tabletler[i].marka,"Apple"))
                    {
                        printf("%d %s %s %d\n",tabletler[i].urunKodu,tabletler[i].marka,tabletler[i].isim,tabletler[i].fiyat);
                    }
                }
        
            break;

            case 2:

                printf("\n");
                for (int i = 0; i < 14 ; i++)
                {
                    if (!strcmp(telefonlar[i].marka,"Huawei"))
                    {
                        printf("%d %s %s %d\n",telefonlar[i].urunKodu,telefonlar[i].marka,telefonlar[i].isim,telefonlar[i].fiyat);
                    }
                }

                for (int i = 0; i < 15 ; i++)
                {
                    if (!strcmp(bilgisayarlar[i].marka,"Huawei"))
                    {   
                        printf("%d %s %s %d\n",bilgisayarlar[i].urunKodu,bilgisayarlar[i].marka,bilgisayarlar[i].isim,bilgisayarlar[i].fiyat);
                    }
                }
        
                for (int i = 0; i < 10 ; i++)
                {
                    if (!strcmp(tabletler[i].marka,"Huawei"))
                    {
                        printf("%d %s %s %d\n",tabletler[i].urunKodu,tabletler[i].marka,tabletler[i].isim,tabletler[i].fiyat);
                    }
                }
        
            break;
        
            case 3:

                printf("\n");
                for (int i = 0; i < 14 ; i++)
                {
                    if (!strcmp(telefonlar[i].marka,"Samsung"))
                    {
                        printf("%d %s %s %d\n",telefonlar[i].urunKodu,telefonlar[i].marka,telefonlar[i].isim,telefonlar[i].fiyat);
                    }
                }
        
                for (int i = 0; i < 15 ; i++)
                {
                    if (!strcmp(bilgisayarlar[i].marka,"Samsung"))
                    {
                        printf("%d %s %s %d\n",bilgisayarlar[i].urunKodu,bilgisayarlar[i].marka,bilgisayarlar[i].isim,bilgisayarlar[i].fiyat);
                    }
                }
        
                for (int i = 0; i < 10 ; i++)
                {
                    if (!strcmp(tabletler[i].marka,"Samsung"))
                    {
                        printf("%d %s %s %d\n",tabletler[i].urunKodu,tabletler[i].marka,tabletler[i].isim,tabletler[i].fiyat);
                    }
                }
        
            break;
            
            case 4:
             
                printf("\n");
                for (int i = 0; i < 14 ; i++)
                {   
                    if (!strcmp(telefonlar[i].marka,"Lenovo"))
                    {
                        printf("%d %s %s %d\n",telefonlar[i].urunKodu,telefonlar[i].marka,telefonlar[i].isim,telefonlar[i].fiyat);
                    }    
                }
        
                for (int i = 0; i < 15 ; i++)
                {
                    if (!strcmp(bilgisayarlar[i].marka,"Lenovo"))
                    {
                        printf("%d %s %s %d\n",bilgisayarlar[i].urunKodu,bilgisayarlar[i].marka,bilgisayarlar[i].isim,bilgisayarlar[i].fiyat);
                    }
                }
        
                for (int i = 0; i < 10 ; i++)
                {
                    if (!strcmp(tabletler[i].marka,"Lenovo"))
                    {
                        printf("%d %s %s %d\n",tabletler[i].urunKodu,tabletler[i].marka,tabletler[i].isim,tabletler[i].fiyat);
                    }   
                }
        
            break;
        
            case 5:
                
                printf("\n");
                for (int i = 0; i < 14 ; i++)
                {
                    if (!strcmp(telefonlar[i].marka,"Xiaomi"))
                    {
                        printf("%d %s %s %d\n",telefonlar[i].urunKodu,telefonlar[i].marka,telefonlar[i].isim,telefonlar[i].fiyat);
                    }
            
                }

                for (int i = 0; i < 15 ; i++)
                {
                    if (!strcmp(bilgisayarlar[i].marka,"Xiaomi"))
                    {
                        printf("%d %s %s %d\n",bilgisayarlar[i].urunKodu,bilgisayarlar[i].marka,bilgisayarlar[i].isim,bilgisayarlar[i].fiyat);
                    }
                }
        
                for (int i = 0; i < 10 ; i++)
                {
                    if (!strcmp(tabletler[i].marka,"Xiaomi"))
                    {
                        printf("%d %s %s %d\n",tabletler[i].urunKodu,tabletler[i].marka,tabletler[i].isim,tabletler[i].fiyat);
                    }
                }
        
            break;
        
            default:

                printf("\nLutfen 1-5 arasinda bir deger giriniz !!!\n");
    
            break;
        }

    } while (no>5);    
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void toplamTutarYazdir()
{
    printf("Toplam odenecek tutar:%d",toplamTutar);
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int indirimOyunu()
{

    int kul=0,bil=0;

    if (sayac > 0)
    {
        while (kul<3 && bil<3)//İki taraftan biri kazanana kadar bloğu döndüren yapı
    {
        //Bilgisayardan random tas,kagıt,makas alınıyor
        char sonuc[10];
        
        int scm=0;//max=3,min=1,
        srand(time(NULL));
        //scm bilgisayarın rasgele atadığı değer
        scm = (rand()%3) +1;

        if (scm==1)
        {
            strcpy(sonuc,"Tas");
        }

        else if (scm==2)
        {
            strcpy(sonuc,"Kagit");
        }

        else if (scm==3)
        {
            strcpy(sonuc,"Makas");
        }
        
        //Kullanıcıdan alınan değerin (cd) bilgisayardan alınan değer ile karşılaştırıyor
        char cd[2];

        do
        {
            printf("\n\n------------------------------------------------------------\n\n");
            printf("Tas icin T veya t yi tuslayiniz\n");
            printf("Kagit icin K veya k yi tuslayiniz\n");
            printf("Makas icin M veya m yi tuslayiniz");
            printf("   =  ");
            scanf("%s", cd);

            if (cd[0]!='T' && cd[0]!='t' && cd[0]!='K' && cd[0]!='k' && cd[0]!='M' && cd[0]!='m')//Farklı karakter girilince uyarı yapan yapı
            {
                printf("\nHatali harf girdiniz yeniden deneyiniz !!!");
            }

        } while (cd[0]!='T' && cd[0]!='t' && cd[0]!='K' && cd[0]!='k' && cd[0]!='M' && cd[0]!='m');//Farklı karakter girilince başa dönen yapı

            printf("\n\n");

            //Switch case yapısı ile kullanıcıdan alınan durumun sonucu tespit edilir
            switch (cd[0])
            {
                //Taş
                case 'T' :
                case 't' :
                    if (scm==1)
                    {
                        printf("Bilgisayar = %s \n Kulllanici = %c\n" , sonuc , cd[0]);
                        printf("Berabere\n\n");
                    }

                    else if (scm==2)
                    {
                        printf("Bilgisayar = %s \n Kulllanici = %c\n" , sonuc , cd[0]);
                        printf("Bilgisayar Kazandi\n\n");
                        bil++;
                    }

                    else if (scm==3)
                    {
                        printf("Bilgisayar = %s \n Kulllanici = %c\n" , sonuc , cd[0]);
                        printf("Kullanici Kazandi\n\n");
                        kul++;
                    }
                    break;
                    
                    
                //Kagıt
                case 'K' :
                case 'k' :
                    if (scm==1)
                    {
                        printf("Bilgisayar = %s \n Kulllanici = %c\n" , sonuc ,cd[0]);
                        printf("Kullanici Kazandi\n\n");
                        kul++;
                    }

                    else if (scm==2)
                    {
                        printf("Bilgisayar = %s \n Kulllanici = %c\n" , sonuc ,cd[0]);
                        printf("Berabere\n\n");
                    }

                    else if (scm==3)
                    {
                        printf("Bilgisayar = %s \n Kulllanici = %c\n" , sonuc ,cd[0]);
                        printf("Bilgisayar Kazandi\n\n");
                        bil++;
                    }
                    break;
                    
                    //Makas
                case 'M' :
                case 'm' :
                    if (scm==1)
                    {
                        printf("Bilgisayar = %s \n Kulllanici = %c\n" , sonuc ,cd[0]);
                        printf("Bilgisayar Kazandi\n\n");
                        bil++;
                    }

                    else if (scm==2)
                    {
                        printf("Bilgisayar = %s \n Kulllanici = %c\n" , sonuc ,cd[0]);
                        printf("Kullanici Kazandi\n\n");
                        kul++;
                    }
                    
                    else if (scm==3)
                    {
                        printf("Bilgisayar = %s \n Kulllanici = %c\n" , sonuc ,cd[0]);
                        printf("Berabere\n\n");
                    }
                    
                break;
                    
            }
        printf("Skor : ");
        printf("Bilgisayar = %d     ",bil);
        printf("Kullanici = %d",kul);
    }

        if (bil==3)
        {
            printf("\n\n\nKAYBETTINIZ :( \n\n\n");
        }
        else if (kul==3)
        {
            printf("\n\n\nKAZANDINIZ :) \n\n\n");
            //void rndmindirim(){

            //Toplam uygulanan indirim tutarı = tindirim
            float indirim=0; 
            int tutar=toplamTutar,indirimlifiyat=0;
            int max=30,min=5;

            srand(time(NULL));
            //Max ile min aralığında rasgele bir değeri rasgele değişkenine atar 
            int rastgele = rand()%(max-min+1)+min;

            //Uygulanacak olan indirim tutarı belirleniyor
            indirim = (tutar*rastgele)/100;
            indirimlifiyat = tutar-indirim;

            printf("\n------------------------------------------------------------\n\n");
            printf("Indirimsiz Tutar = %d\n",tutar);
            printf("Indirim orani  = %d\n",rastgele);
            printf("Indirim tutari = %2.f\n",indirim);
            printf("Odenecek tutar = %d\n  ",indirimlifiyat);
            printf("\n------------------------------------------------------------\n");
            
            toplamTutar=indirimlifiyat;
        }

    }

    else
    printf("\nSepetinizde urun olmadan oyunu oynayamazsiniz.\n\n");
    
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void tutarHesapla()
{
    toplamTutar = 0;
    for(int i=0;i<sayac;i++)
    {
            for(int k=0;k<14;k++)
            {
                if(sepettekiUrunler[i]==telefonlar[k].urunKodu)
                {
                    toplamTutar+=telefonlar[k].fiyat;
                }
            }

            for(int k=0;k<15;k++)
            {
                if(sepettekiUrunler[i]==bilgisayarlar[k].urunKodu)
                {
                    toplamTutar+=bilgisayarlar[k].fiyat;
                }
            }

            for(int k=0;k<10;k++)
            {
                if(sepettekiUrunler[i]==tabletler[k].urunKodu)
                {
                    toplamTutar+=tabletler[k].fiyat;
                }
            }
    }  
}

