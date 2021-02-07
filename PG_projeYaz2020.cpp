/*
   Ad....................................:  Fatmanur Kýlýç
   Numara................................:  B140910008
   Grup..................................:  1A
   Ödev No...............................:  1
*/
#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class insaatMalzemeleri {
public:
	string UrunNo;
	int Birim;
	int BirimFiyati;
	string Markasi;
	string UrunAdi;
	string tutucu = "ÿ";
	string _satir;

	void UrunEkle()
	{
		ofstream DosyaYaz;
		DosyaYaz.open("insaatMalzemeleri.txt", ios::app);
		DosyaYaz << UrunNo << " " << UrunAdi << ' ' << Birim << ' '
			<< BirimFiyati << ' ' << Markasi << "\n";
		DosyaYaz.close();
	}

	void UrunSil(string _UrunNO)
	{
		string temp[100];
		ifstream dosyaoku("insaatMalzemeleri.txt");
		string satir = "";
		int sayac = 0;
		if (dosyaoku.is_open()) {
			while (getline(dosyaoku, satir))
			{
				temp[sayac] = satir;
				sayac++;
			}
			dosyaoku.close();
		}

		for (int j = 0; j < sayac; j++)
		{
			tutucu = temp[j].find(_UrunNO, 0);

			if (tutucu != "ÿ")
			{
				for (int k = j; k < sayac - 1; k++)
				{
					temp[k] = temp[k + 1];
				}
				temp[sayac - 1] = "";
				break;
			}
		}

		ofstream DosyaYaz;
		DosyaYaz.open("insaatMalzemeleri.txt", ios::out);
		for (int i = 0; i < sayac-1; i++)
		{
			DosyaYaz << temp[i] << "\n";
		}
		DosyaYaz.close();
	}

	int UrunAra(string _UrunNO)
	{
		
		ifstream dosyaoku("insaatMalzemeleri.txt");
		string satir = "";
		int sayac = 0;
		if (dosyaoku.is_open()) {
			while (getline(dosyaoku, satir))
			{
				tutucu = satir.find(_UrunNO, 0);
				if (tutucu != "ÿ")
				{
					_satir = satir;
					break;
				}
			}
			dosyaoku.close();
		}
		if (tutucu != "ÿ")
			return 1;
		else
			return 0;
	}

	void Rapor()
	{
		ifstream dosyaoku("insaatMalzemeleri.txt");
		string satir = "";

		if (dosyaoku.is_open()) {
			while (getline(dosyaoku, satir))
			{
				cout << satir << endl;
			}
			dosyaoku.close();
		}
	}
};

class projeler
{
public:
	string ProjeNo;
	string ProjeYurutucuFirma;
	string ProjeAdi;
	string ProjeSorumlusu;
	string ProjeKontroloru;
	string tutucu = "ÿ";
	string _satir;

	void UrunEkle()
	{
		ofstream DosyaYaz;
		DosyaYaz.open("projeler.txt", ios::app);
		DosyaYaz << ProjeNo << " " << ProjeAdi << ' ' << ProjeYurutucuFirma << ' ' << ProjeSorumlusu << ' ' << ProjeKontroloru << "\n";
		DosyaYaz.close();
	}

	void UrunSil(string _UrunNO)
	{
		string temp[100];
		ifstream dosyaoku("projeler.txt");
		string satir = "";
		int sayac = 0;
		if (dosyaoku.is_open()) {
			while (getline(dosyaoku, satir))
			{
				temp[sayac] = satir;
				sayac++;
			}
			dosyaoku.close();
		}

		for (int j = 0; j < sayac; j++)
		{
			tutucu = temp[j].find(_UrunNO, 0);

			if (tutucu != "ÿ")
			{
				for (int k = j; k < sayac - 1; k++)
				{
					temp[k] = temp[k + 1];
				}
				temp[sayac - 1] = "";
				break;
			}
		}

		ofstream DosyaYaz;
		DosyaYaz.open("projeler.txt", ios::out);
		for (int i = 0; i < sayac - 1; i++)
		{
			DosyaYaz << temp[i] << "\n";
		}
		DosyaYaz.close();
	}

	int UrunAra(string _UrunNO)
	{

		ifstream dosyaoku("projeler.txt");
		string satir = "";
		int sayac = 0;
		if (dosyaoku.is_open()) {
			while (getline(dosyaoku, satir))
			{
				tutucu = satir.find(_UrunNO, 0);
				if (tutucu != "ÿ")
				{
					_satir = satir;
					break;
				}
			}
			dosyaoku.close();
		}
		if (tutucu != "ÿ")
			return 1;
		else
			return 0;
	}

	void Rapor()
	{
		ifstream dosyaoku("projeler.txt");
		string satir = "";

		if (dosyaoku.is_open()) {
			while (getline(dosyaoku, satir))
			{
				cout << satir << endl;
			}
			dosyaoku.close();
		}
	}
};

class hakedis
{
public:
	string ProjeNo;
	string MalzemeNo;
	int HakedisDonemi;
	string kullanilanUrun;
	int KullanilanAdet;
	string BirimFiyat;
	int ToplamTutar;
	int tempiBirimFiyat;
	string tutucu = "ÿ";

	void HakedisEkle()
	{
		int sonuc;
		sonuc = donstringToInt(BirimFiyat);
		sonuc = sonuc * KullanilanAdet;
		ofstream DosyaYaz;
		DosyaYaz.open("hakedis.txt", ios::app);
		DosyaYaz << ProjeNo << " " << HakedisDonemi << ' ' << kullanilanUrun << ' ' << KullanilanAdet << ' ' << BirimFiyat << ' ' << sonuc << "\n";
		DosyaYaz.close();

		KullanilanUrunSil(MalzemeNo , KullanilanAdet);
	}

	int donstringToInt(string sayi)
	{ //
		int carpim = 1, sonuc = 0, temp;
		for (int i = sayi.length() - 1; i >= 0; i--)
		{
			temp = sayi[i] - 48;
			sonuc += temp * carpim;
			carpim = carpim * 10;
		}
		return sonuc;
	}

	void KullanilanUrunSil(string _UrunNO, int _KullanilanAdet)
	{
		string tutucu = "ÿ";
		string temp[100];
		ifstream dosyaoku("insaatMalzemeleri.txt");
		string satir = "";
		int sayac = 0;
		if (dosyaoku.is_open()) {
			while (getline(dosyaoku, satir))
			{
				temp[sayac] = satir;
				sayac++;
			}
			dosyaoku.close();
		}

		for (int j = 0; j < sayac; j++) //
		{
			tutucu = temp[j].find(_UrunNO, 0);

			if (tutucu != "ÿ")
			{
				int indexDizi[4];
				indexDizi[0] =temp[j].find(" ", 0);
				for (int i = 1; i < 4; i++) // Textden ürün adý ve birim fiyat bulunur
				{
					indexDizi[i] = temp[j].find(" ", indexDizi[i - 1] + 1);
				}
				string birimfiyat;
				int indexsayisi;
				indexsayisi = indexDizi[2] - (indexDizi[3] - indexDizi[2]);
				birimfiyat = temp[j].substr(indexsayisi, (indexDizi[3] - indexDizi[2]));
				tempiBirimFiyat = donstringToInt(birimfiyat) - _KullanilanAdet; //
				string str = to_string(tempiBirimFiyat);

				if (birimfiyat.length() == str.length()) // Ýndex sayýsý eþit olanlar güncellendi
				{
					for (int k = 0; k < birimfiyat.length(); k++)
					{
						temp[j][indexDizi[1] + 1 + k] = str[k];
					}
				}
				else
				{
					for (int k = 0; k < str.length(); k++)
					{
						temp[j][indexDizi[1] + 1 + k] = str[k];
					}

					for (int t = indexDizi[1] + 1 + str.length(); t < temp[j].length(); t++)
					{
						temp[j][t] = temp[j][t + 1];
					}

					temp[j][temp->length()] = ' ';
				}
				break;
			}
		}

		ofstream DosyaYaz;
		DosyaYaz.open("insaatMalzemeleri.txt", ios::out);
		for (int i = 0; i < sayac - 1; i++)
		{
			DosyaYaz << temp[i] << "\n";
		}
		DosyaYaz.close();
	}

	void UrunGuncelle(string _UrunNO, string yeniAdet)
	{
		string tutucu = "ÿ";
		string temp[100];
		ifstream dosyaoku("insaatMalzemeleri.txt");
		string satir = "";
		int sayac = 0;
		if (dosyaoku.is_open()) {
			while (getline(dosyaoku, satir))
			{
				temp[sayac] = satir;
				sayac++;
			}
			dosyaoku.close();
		}

		for (int j = 0; j < sayac; j++) //
		{
			tutucu = temp[j].find(_UrunNO, 0);

			if (tutucu != "ÿ")
			{
				int indexDizi[4];
				indexDizi[0] = temp[j].find(" ", 0);
				for (int i = 1; i < 4; i++) // Textden ürün adý ve birim fiyat bulunur
				{
					indexDizi[i] = temp[j].find(" ", indexDizi[i - 1] + 1);
				}
				string birimfiyat;
				int indexsayisi;
				indexsayisi = indexDizi[2] - (indexDizi[3] - indexDizi[2]);
				birimfiyat = temp[j].substr(indexsayisi, (indexDizi[3] - indexDizi[2]));

				if (birimfiyat.length() == yeniAdet.length()) // Ýndex sayýsý eþit olanlar güncellendi
				{
					for (int k = 0; k < birimfiyat.length(); k++)
					{
						temp[j][indexDizi[1] + 1 + k] = yeniAdet[k];
					}
				}
				else
				{
					for (int k = 0; k < yeniAdet.length(); k++)
					{
						temp[j][indexDizi[1] + 1 + k] = yeniAdet[k];
					}

					for (int t = indexDizi[1] + 1 + yeniAdet.length(); t < temp[j].length(); t++)
					{
						temp[j][t] = temp[j][t + 1];
					}

					temp[j][temp->length()] = ' ';
				}
				break;
			}
		}

		ofstream DosyaYaz;
		DosyaYaz.open("insaatMalzemeleri.txt", ios::out);
		for (int i = 0; i < sayac - 1; i++)
		{
			DosyaYaz << temp[i] << "\n";
		}
		DosyaYaz.close();
	}

	void UrunListele(string _UrunNO)
	{
		ifstream dosyaoku("hakedis.txt");
		string satir = "";

		if (dosyaoku.is_open()) {
			while (getline(dosyaoku, satir))
			{
				tutucu = satir.find(_UrunNO, 0);
				if (tutucu != "ÿ")
				{
					cout << satir << endl;;
				}
			}
			dosyaoku.close();
		}
	}
};

int main(int argc, char* argv[]) 
{
	insaatMalzemeleri malzeme;
	projeler proje;
	hakedis hakedis;

	string silinecekurun;
	// insaatmalzemeleri.txt dosyasýnda yer alancak alanlar
	int secim, secimUrun, secimProje, secimHakedis;
	string UrunNO;
	string UrunAd;
	int Birim;
	string Marka;
	int BirimFiyat;

	//projeler.txt dosyasýnda yer alacak alanlar
	string ProjeNO;
	string ProjeAd;
	string ProjeYurutucuFirma;
	string ProjeSorumlusu;
	string ProjeKontroloru;

	//muayene.txt dosyasýnda yer alacak alanlar
	string ProjeNo;
	int HakedisDonemi;
	string kullanilanUrun;
	int KullanilanAdet;
	int ToplamTutar;

	string kontrol, devam = "e";
	string adet;

	while (true)
	{
		system("cls");
		cout << " Ne yapmak istiyorsunuz ? " << endl;
		cout << " 1- Malzeme Islemleri " << endl;
		cout << " 2- Proje Islemleri " << endl;
		cout << " 3- Hakedis " << endl;
		cout << " 4- Programdan cikis " << endl;
		cout << " Seciminiz : " ;
		cin >> secim;

		switch (secim)
		{
		case 1:
			cout << "\n 1- Urun Ekleme " << endl;
			cout << " 2- Urun Silme " << endl;
			cout << " 3- Urun Arama " << endl;
			cout << " 4- Raporlama " << endl;
			cout << " Seciminiz : ";
			cin >> secimUrun;

			switch (secimUrun)
			{
			case 1:
				cout << "\n Urun NO :"; cin >> UrunNO;
				cout << "\n Urun Adi:"; cin >> UrunAd;
				cout << "\n Urun Adedi :"; cin >> Birim;
				cout << "\n Urun Adet Fiyati :"; cin >> BirimFiyat;
				cout << "\n Urun Markasi :"; cin >> Marka;

				if (malzeme.UrunAra(UrunNO) == 0)
				{
					malzeme.UrunNo = UrunNO;
					malzeme.UrunAdi = UrunAd;
					malzeme.Birim = Birim;
					malzeme.BirimFiyati = BirimFiyat;
					malzeme.Markasi = Marka;

					malzeme.UrunEkle();

					cout << "dosyaya yazim tamamlandi. ";
				}
				else
					cout << "Bu urun no mevcut.";
				cout << "\nDevam (d) :"; cin >> kontrol;
			case 2:
				cout << "\n Silmek istediginiz urun nosunu giriniz :"; cin >> UrunNO;
				if (malzeme.UrunAra(UrunNO) == 1)
				{
					malzeme.UrunSil(UrunNO);

					cout << "Urun silme basarili. ";
				}
				else
					cout << " Boyle bir urun mevcut degil.";
				cout << "\nDevam (d) :"; cin >> kontrol;
			case 3:
				cout << "\n Bulmak istediginiz urun nosunu giriniz :"; cin >> UrunNO;
				if (malzeme.UrunAra(UrunNO) == 1)
				{
					cout << malzeme._satir;
				}
				else
					cout << " Boyle bir urun mevcut degil.";
				cout << "\nDevam (d) :"; cin >> kontrol;
			case 4:
				malzeme.Rapor();
				cout << "\nDevam (d) :"; cin >> kontrol;
			default:
				break;
			}
			break;
		case 2:
			cout << "\n 1- Proje Ekleme " << endl;
			cout << " 2- Proje Silme " << endl;
			cout << " 3- Proje Arama " << endl;
			cout << " 4- Raporlama " << endl;
			cout << " Seciminiz : ";
			cin >> secimProje;

			switch (secimProje)
			{
			case 1:
				cout << "\n Proje NO :"; cin >> ProjeNO;
				cout << "\n Proje Adi:"; cin >> ProjeAd;
				cout << "\n Proje Yurutucu Firma :"; cin >> ProjeYurutucuFirma;
				cout << "\n Proje Sorumlusu :"; cin >> ProjeSorumlusu;
				cout << "\n Proje Kontoloru :"; cin >> ProjeKontroloru;

				if (proje.UrunAra(UrunNO) == 1)
				{
					proje.ProjeNo = ProjeNO;
					proje.ProjeAdi = ProjeAd;
					proje.ProjeYurutucuFirma = ProjeYurutucuFirma;
					proje.ProjeSorumlusu = ProjeSorumlusu;
					proje.ProjeKontroloru = ProjeKontroloru;

					proje.UrunEkle();

					cout << "dosyaya yazim tamamlandi. ";
				}
				else
					cout << "Bu proje no mevcut.";
				cout << "\nDevam (d) :"; cin >> kontrol;
			case 2:
				cout << "\n Silmek istediginiz proje nosunu giriniz :"; cin >> ProjeNO;
				if (proje.UrunAra(ProjeNO) == 1)
				{
					proje.UrunSil(ProjeNO);

					cout << "Urun silme basarili. ";
				}
				else
					cout << " Boyle bir urun mevcut degil.";
				cout << "\nDevam (d) :"; cin >> kontrol;
			case 3:
				cout << "\n Bulmak istediginiz proje nosunu giriniz :"; cin >> UrunNO;
				if (proje.UrunAra(ProjeNO) == 1)
				{
					cout << proje._satir;
				}
				else
					cout << " Boyle bir urun mevcut degil.";
				cout << "\n Devam etmek istiyor musunuz ? (e/h) :"; cin >> kontrol;
				break;
			case 4:
				proje.Rapor();
				cout << "\n Devam etmek istiyor musunuz ? (e/h) :"; cin >> kontrol;
			default:
				break;
			}
			break;
		case 3:
			cout << "\n Proje NO :"; cin >> ProjeNO;

			if (proje.UrunAra(ProjeNO) == 1)
			{
				cout << " 1- Hakedis Hesapla " << endl;
				cout << " 2- Hakedis Listele " << endl;
				cout << " 3- Urun Guncelleme " << endl;
				cout << " Seciminiz : ";
				cin >> secimHakedis;

				switch (secimHakedis)
				{
				case 1:
					cout << "\n Hakedis Donemi (1,2,3) :"; cin >> HakedisDonemi;

					cout << "\n Proje :" << endl;
					cout << proje._satir << endl;
					cout << "\n Malzemeler :" << endl;
					malzeme.Rapor();
					while (devam == "e")
					{
						cout << "\n Kullanilan urun no :"; cin >> kullanilanUrun;
						cout << "\n Kullanilan urun adedi :"; cin >> KullanilanAdet;
						if (malzeme.UrunAra(kullanilanUrun) == 1)
						{
							int indexDizi[4];
							indexDizi[0] = malzeme._satir.find(" ", 0);
							for (int i = 1; i < 4; i++) // Textden ürün adý ve birim fiyat bulunur
							{
								indexDizi[i] = malzeme._satir.find(" ", indexDizi[i - 1] + 1);
							}
							string birimfiyat;
							UrunAd= malzeme._satir.substr(indexDizi[0], indexDizi[1] - indexDizi[0]);
							birimfiyat = malzeme._satir.substr(indexDizi[2] + 1, indexDizi[3]  - indexDizi[2] - 1);

							// Class yapýsýna ekleniyor
							hakedis.ProjeNo = ProjeNO;
							hakedis.HakedisDonemi = HakedisDonemi;
							hakedis.kullanilanUrun = UrunAd;
							hakedis.KullanilanAdet = KullanilanAdet;
							hakedis.BirimFiyat = birimfiyat;
							hakedis.MalzemeNo = kullanilanUrun;
							hakedis.HakedisEkle();
							cout << "\n Urun eklemek istiyor musunuz ? (e/h) :"; cin >> devam;
						}
						else
						{
							cout << " Boyle bir urun mevcut degil.";
						}

						cout << "\n Devam etmek istiyor musunuz ? (e/h) :"; cin >> kontrol;
					}

					cout << "\n Devam etmek istiyor musunuz ? (e/h) :"; cin >> kontrol;

				case 2:
					hakedis.UrunListele(ProjeNO);

					cout << "\n Devam etmek istiyor musunuz ? (e/h) :"; cin >> kontrol;
					break;
				case 3 :
					malzeme.Rapor();
					cout << "\n Urun No :"; cin >> kullanilanUrun;
					cout << "\n Yeni Adet sayisi :"; cin >> adet;
					hakedis.UrunGuncelle(kullanilanUrun, adet);
					cout << "\n Devam etmek istiyor musunuz ? (e/h) :"; cin >> kontrol;
				case 4:
					exit(0);
				default:
					break;
				}
				
				cin >> kontrol;
			}
			else
				cout << " Boyle bir urun mevcut degil.";

			cout << "\n Devam etmek istiyor musunuz ? (e/h) :"; cin >> kontrol;
			break;

		case 4:
			exit(0);
			break;
		default:
			break;
		}
		if (kontrol == "h")
			exit(0);
	}

  	system("PAUSE");
	return EXIT_SUCCESS;
}
