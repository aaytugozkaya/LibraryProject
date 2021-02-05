#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <fstream>
#include <iostream> 
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;



int main()
{
	char cevap = 'e';
	int secim1, secim2, secim3;
	//kullanıcı bölümü
	string kullaniciadi, sifre, kullaniciadi1, sifre1;
	//okuyucu bilgisi
	string Ad, Soyad, Doğumtarihi, gorevi, TC, uyeno, telefonno;
	int kitapsayisi;
	//kitap bilgileri
	string ISBN, kitapismi, yazaradi, yazarsoyadi, konu, tur, sayfasayisi;
	//ödünç dosya
	string odunctarihi, donustarihi;
	string Aranantc;
	string arananisbn;

	

baslangic:
	do
	{
		cout << "   Ne yapmak istiyorsunuz ? " << endl;
		cout << "   1) Giris yap. " << endl;
		cout << "   2) Kayit ol. " << endl;
		cin >> secim1;
	} while (secim1 != 1 && secim1 != 2);

	if (secim1 == 1)
	{
		cout << "Kullanici adi :" << endl; cin >> kullaniciadi1;
		cout << "Sifre :" << endl; cin >> sifre1;
		ifstream DosyaOku("kullanici.txt");

		DosyaOku >> kullaniciadi >> sifre;
		system("CLS");

		if (kullaniciadi == kullaniciadi1 && sifre == sifre1) {

		menudonus:
			cout << "======================================================= " << endl;
			time_t now = time(0);
			char* dt = ctime(&now);
			tm* gmtm = gmtime(&now); dt = asctime(gmtm);
			cout << "Giris yapilan saat :" << dt << endl;
			cout << "===	Ne yapmak istersiniz?	===" << endl;
			cout << "1-	Okuyucu kaydi" << endl;
			cout << "2-	Okuyucu kaydi guncelleme" << endl;
			cout << "3-	Okuyucu silme" << endl;
			cout << "4-	Okuyucu uzerindeki kitaplar listesi" << endl;
			cout << "5-	Okuyucu kitap odunc alma" << endl;
			cout << "6-	Okuyucu kitap geri dondurme" << endl;
			cout << "7-	Kitap ekleme" << endl;
			cout << "8-	Kitap silme" << endl;
			cout << "9-	Kitap duzeltme" << endl;
			cout << "10-     Cikis " << endl;
			cout << "======================================================= " << endl;
			cin >> secim2;
		}while (secim2 != 1 && secim2 != 2 && secim2 != 3 && secim2 != 4 && secim2 != 5 && secim2 != 6 && secim2 != 7 && secim2 != 8 && secim2 != 9 && secim2 != 10);

		if (secim2 == 1) {
			ofstream DosyaYaz;
			DosyaYaz.open("okuyucu.txt", ios::app);
			
			do
			{
				cout << "\n TC'nizi giriniz.      :"; cin >> TC;
				cout << "\n Adınızı giriniz.      :"; cin >> Ad;
				cout << "\n Soyadınızı giriniz.     :"; cin >> Soyad;
				cout << "\n Uye numaranızı giriniz.      :"; cin >> uyeno;
				cout << "\n Telefon numaranızı giriniz.     :"; cin >> telefonno;
				cout << "\n Dogum tarihinizi giriniz.   :"; cin >> Doğumtarihi;
				cout << "\n Goreviniz nedir?      :"; cin >> gorevi;
				cout << "\n Alabilecegi kiap sayisi      :"; cin >> kitapsayisi;



				DosyaYaz << "\n" << TC << " " << Ad << ' ' << Soyad << ' ' << uyeno << ' ' << telefonno << ' ' << Doğumtarihi << ' ' << gorevi << ' ' << kitapsayisi << ' ';


				cout << "\n baska kayit yapacak misin?(e/h) "; cin >> cevap;
			} while (!(cevap == 'h'));
			DosyaYaz.close();
			cout << "dosyaya yazim tamamlandi. " << endl;
			system("CLS");
			goto menudonus;
		}


		if (secim2 == 2) {

			cout << "Kayit guncellemek istediginiz kisinin TC'sini giriniz."; cin >> Aranantc;
			ifstream DosyaOku("okuyucu.txt");
			ofstream DosyaYaz("okuyucu.tmp");
			while (!DosyaOku.eof())
			{
				DosyaOku >> TC >> Ad >> Soyad >> uyeno >> telefonno >> Doğumtarihi >> gorevi >> kitapsayisi;
				if (Aranantc == TC) {
					cout << "\n dosyadaki kayit \n";
					cout << TC << endl;
					cout << Ad << endl;
					cout << Soyad << endl;
					cout << uyeno << endl;
					cout << telefonno << endl;
					cout << Doğumtarihi << endl;
					cout << gorevi << endl;
					cout << kitapsayisi << endl;
					cout << "\n Kayıt icin yeni degerler girisi \n";
					cout << "TC                 :  " ; cin >> TC;
					cout << "Ad                 :  " ;cin >> Ad;
					cout << "Soyad              :  " ;cin >> Soyad;
					cout << "Uye numarasi       :  " ;cin >> uyeno;
					cout << "Telefon numarasi   :  " ;cin >> telefonno;
					cout << "Doğumtarihi        :  " ;cin >> Doğumtarihi;
					cout << "Gorevi             :  " ;cin >> gorevi;
					cout << "Kitap sayisi       :  " ;cin >> kitapsayisi;

					DosyaYaz << TC << ' ' << Ad << ' ' << Soyad << ' ' << uyeno << ' ' << telefonno << ' ' << Doğumtarihi << ' ' << gorevi << ' ' << kitapsayisi << "\n";
					cout << "Kayit güncellendi." << endl;



				}
				else
				{ 
					DosyaYaz << "\n" << TC << ' ' << Ad << ' ' << Soyad << ' ' << uyeno << ' ' << telefonno << ' ' << Doğumtarihi << ' ' << gorevi << ' ' << kitapsayisi;
				}

				DosyaYaz.close();
				DosyaOku.close();
				remove("okuyucu.txt");
				rename("okuyucu.tmp", "okuyucu.txt");
			}

			goto menudonus;


		}


		if (secim2 == 3) {

			cout << " silinecek kisi tc :";cin >> Aranantc;
			ifstream DosyaOku("okuyucu.txt");
			ofstream DosyaYaz("okuyucu.tmp");
			while (!DosyaOku.eof())
			{
				DosyaOku >> TC >> Ad >> Soyad >> uyeno >> telefonno >> Doğumtarihi >> gorevi >> kitapsayisi;

				if (Aranantc == TC)
				{
					cout << "\n dosyadaki kayit \n";
					cout << TC << endl;
					cout << Ad << endl;
					cout << Soyad << endl;
					cout << uyeno << endl;
					cout << telefonno << endl;
					cout << Doğumtarihi << endl;
					cout << gorevi << endl;
					cout << kitapsayisi << endl;
				}
				else
				{ 
					DosyaYaz << "\n"  << TC << ' ' << Ad << ' ' << Soyad << ' ' << uyeno << ' ' << telefonno << ' ' << Doğumtarihi << ' ' << gorevi << ' ' << kitapsayisi ;
				}
				DosyaYaz.close();
				DosyaOku.close();
				remove("okuyucu.txt");
				rename("okuyucu.tmp", "okuyucu.txt");
				cout << "kisi basariyla kaldirildi." << endl;
				goto menudonus;
			}
		}


		if (secim2 == 4) {
			ifstream DosyaOku("Odunc.txt");
			while (!DosyaOku.eof())
			{
				DosyaOku >> ISBN >> TC >> odunctarihi >> donustarihi;
				cout << "Kisinin Tcsini giriniz."; cin >> Aranantc;

				if (Aranantc == TC) {
					cout << TC << "'ye verilen kitaplar" << endl;
					cout << "\n dosyadaki kayit \n";
					cout << ISBN << endl;
					cout << odunctarihi << endl;
					cout << donustarihi << endl;

				}
			
			}
			DosyaOku.close();
			goto menudonus;
		}


		if (secim2 == 5) {

			ofstream DosyaYaz;
			DosyaYaz.open("Odunc.txt", ios::app);
			cout << "\n Odunc Bilgileri    \n";
			cout << "\n ISBN               :"; cin >> ISBN;
			cout << "\n TC                 :"; cin >> TC;
			cout << "\n Odunc Tarihi       :"; cin >> odunctarihi;
			cout << "\n Donus Tarihi       :"; cin >> donustarihi;

			DosyaYaz << ISBN << " " << TC << ' ' << odunctarihi << ' ' << donustarihi << "\n";
			DosyaYaz.close();
			goto menudonus;
		}


		if (secim2 == 6) {
			cout << " Geri verilecek kitap ISBN";cin >> arananisbn;
			ifstream DosyaOku("Odunc.txt");
			ofstream DosyaYaz("Odunc.tmp");
			while (!DosyaOku.eof())
			{
				DosyaOku >> ISBN >> TC >> odunctarihi >> donustarihi;

				if (arananisbn == ISBN) {
					cout << "\n dosyadaki kayit \n";
					cout << ISBN << endl;
					cout << odunctarihi << endl;
					cout << donustarihi << endl;
				}
				else
				{  
					DosyaYaz << "\n" << ISBN << " " << TC << ' ' << odunctarihi << ' ' << donustarihi ;
				}
			}
			DosyaYaz.close();
			DosyaOku.close();
			remove("Odunc.txt");
			rename("Odunc.tmp", "Odunc.txt");
			cout << "Kitap basariyla geri verildi." << endl;

			goto menudonus;
		}


		if (secim2 == 7) { 
			ofstream DosyaYaz;
			DosyaYaz.open("kitaplar.txt", ios::app);

			do
			{
				cout << "\n ISBN giriniz           :"; cin >> ISBN;
				cout << "\n Kitap adını giriniz    :"; cin >> kitapismi;
				cout << "\n Yazar adini girniz     :"; cin >> yazaradi;
				cout << "\n Yazar soyadini giriniz :"; cin >> yazarsoyadi;
				cout << "\n Kitap konusu           :"; cin >> konu;
				cout << "\n Kitap türü             :"; cin >> tur;
				cout << "\n Kitabın sayfa sayısı   :"; cin >> sayfasayisi;




				DosyaYaz << "\n" << ISBN << " " << kitapismi << ' ' << yazaradi << ' ' << yazarsoyadi << ' ' << konu << ' ' << tur << ' ' << sayfasayisi << ' ';


				cout << "\n baska kayit yapacak misin?(e/h) "; cin >> cevap;
			} while (!(cevap == 'h'));
			DosyaYaz.close();
			cout << "dosyaya yazim tamamlandi. " << endl;
			goto menudonus;


		}


		if (secim2 == 8) { 

			cout << " silinecek kitabin ISBN  :";cin >> arananisbn;
			ifstream DosyaOku("kitaplar.txt");
			ofstream DosyaYaz("kitaplar.tmp");
			while (!DosyaOku.eof())
			{
				DosyaOku >> ISBN >> kitapismi >> yazaradi >> yazarsoyadi >> konu >> tur >> sayfasayisi;

				if (arananisbn == ISBN) {
					cout << "\n dosyadaki kayit \n";
					cout << ISBN << endl;
					cout << kitapismi << endl;
					cout << yazaradi << endl;
					cout << yazarsoyadi << endl;
					cout << konu << endl;
					cout << tur << endl;
					cout << sayfasayisi << endl;

				}
				else
				{  
					DosyaYaz << "\n" << ISBN << " " << kitapismi << ' ' << yazaradi << ' ' << yazarsoyadi << ' ' << konu << ' ' << tur << ' ' << sayfasayisi << ' ';
				}
			}
			DosyaYaz.close();
			DosyaOku.close();
			remove("kitaplar.txt");
			rename("kitaplar.tmp", "kitaplar.txt");
			cout << "kitap basariyla kaldirildi." << endl;

			goto menudonus;
		}



		if (secim2 == 9) { 
			cout << " GÜncellenecek kitabin ISBN  :";cin >> arananisbn;
			ifstream DosyaOku("kitaplar.txt");
			ofstream DosyaYaz("kitaplar.tmp");
			while (!DosyaOku.eof())
			{
				DosyaOku >> ISBN >> kitapismi >> yazaradi >> yazarsoyadi >> konu >> tur >> sayfasayisi;
				if (arananisbn == ISBN) {
					cout << "\n dosyadaki kayit \n";
					cout << ISBN << endl;
					cout << kitapismi << endl;
					cout << yazaradi << endl;
					cout << yazarsoyadi << endl;
					cout << konu << endl;
					cout << tur << endl;
					cout << sayfasayisi << endl;
					cout << "\n Kayıt icin yeni degerler girisi \n";
					cout << "\n ISBN giriniz           :"; cin >> ISBN;
					cout << "\n Kitap adını giriniz    :"; cin >> kitapismi;
					cout << "\n Yazar adini girniz     :"; cin >> yazaradi;
					cout << "\n Yazar soyadini giriniz :"; cin >> yazarsoyadi;
					cout << "\n Kitap konusu           :"; cin >> konu;
					cout << "\n Kitap türü             :"; cin >> tur;
					cout << "\n Kitabın sayfa sayısı   :"; cin >> sayfasayisi;

					DosyaYaz << ISBN << " " << kitapismi << ' ' << yazaradi << ' ' << yazarsoyadi << ' ' << konu << ' ' << tur << ' ' << sayfasayisi << ' ' << "\n";
					cout << "Kayit güncellendi." << endl;
				}
				else
				{  
					DosyaYaz << "\n" << ISBN << " " << kitapismi << ' ' << yazaradi << ' ' << yazarsoyadi << ' ' << konu << ' ' << tur << ' ' << sayfasayisi << ' ';
				}
				DosyaYaz.close();
				DosyaOku.close();
				remove("kitaplar.txt");
				rename("kitaplar.tmp", "kitaplar.txt");
			}
			goto menudonus;

		}


		if (secim2 == 10) { 
			system("CLS");
			time_t now = time(0);
			char* dt = ctime(&now);
			tm* gmtm = gmtime(&now); dt = asctime(gmtm);
			cout << "Cikis yapilan saat :" << dt << endl;
			exit(1);
		}

	}



	if (secim1 == 2) {  
		ofstream DosyaYaz("kullanici.txt");
		cout << "Kullanici Adi: ";cin >> kullaniciadi;
		cout << "Sifre :"; cin >> sifre;
		DosyaYaz << kullaniciadi << " " << sifre << "\n";
		cout << "Kullanici basariyla olusturuldu." << endl;

		DosyaYaz.close();
		goto baslangic;
	}







}




