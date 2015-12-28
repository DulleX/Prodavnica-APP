#include "stdafx.h"
#include "funkcije.h"
/************************************************************************************************/
//TRECI NIVO
void lokacija_baze_podataka_definisanje_parametara_admin(std::ostream &out, Korisnik k)
    {log(k,"lokacija_bp");out<<"lokacija_baze_podataka_definisanje_parametara_admin"<<std::endl;}

void pregled_proizvoda_trgovac(std::ostream &out, Korisnik k){log(k,"pregled");out<<"pregled_proizvoda_trgovac"<<std::endl;}
void dodavanje_proizvoda_trgovac(std::ostream &out, Korisnik k){log(k,"dodavanje");out<<"dodavanje_proizvoda_trgovac"<<std::endl;}
void brisanje_proizvoda_trgovac(std::ostream &out, Korisnik k){log(k,"brisanje");out<<"brisanje_proizvoda_trgovac"<<std::endl;}
void izmjena_proizvoda_trgovac(std::ostream &out, Korisnik k){log(k,"izmjena");out<<"izmjena_proizvoda_trgovac"<<std::endl;}

void racun_prodaja_trgovac(std::ostream &out, Korisnik k){log(k,"racun");out<<"racun_prodaja_trgovac"<<std::endl;}

void pregled_kupaca_trgovac(std::ostream &out, Korisnik k){log(k,"pregled");out<<"pregled_kupaca_trgovac"<<std::endl;}
void dodavanje_kupaca_trgovac(std::ostream &out, Korisnik k){log(k,"dodavanje");out<<"dodavanje_kupaca_trgovac"<<std::endl;}
void brisanje_kupaca_trgovac(std::ostream &out, Korisnik k){log(k,"brisanje");out<<"brisanje_kupaca_trgovac"<<std::endl;}
void izmjena_kupaca_trgovac(std::ostream &out, Korisnik k){log(k,"izmjena");out<<"izmjena_kupaca_trgovac"<<std::endl;}

void svi_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
    log(k,"svi_proizvodi");
    print_meni("Izvjestaji o svim proizvodima","trenutno","sedmicno","mjesecno","godisnje");
    std::string pom;
    do
    {
        std::cout<<">";
		std::getline(std::cin, pom);
        if(pom=="trenutno"||pom=="tren"||pom=="t")trenutno_svi_proizvodi_izvjestaj_trgovac(out,k);
        else if(pom=="sedmicno"||pom=="sedm"||pom=="s")sedmicno_svi_proizvodi_izvjestaj_trgovac(out,k);
        else if(pom=="mjesecno"||pom=="mje"||pom=="m")mjesecno_svi_proizvodi_izvjestaj_trgovac(out,k);
        else if(pom=="godisnje"||pom=="god"||pom=="g")godisnje_svi_proizvodi_izvjestaj_trgovac(out,k);
        else std::cout<<"GRESKA U UNOSU!!!"<<std::endl;
    }while(pom!="trenutno"&&pom!="tren"&&pom!="t"&&pom!="sedmicno"&&pom!="sedm"&&pom!="s"&&
           pom!="mjesecno"&&pom!="mje"&&pom!="m"&&pom!="godisnje"&&pom!="god"&&pom!="g");
}
void jedan_proizvod_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
    log(k,"jedan_proizvod");
    print_meni("Izvjestaji o pojedinacnom proizvodu","trenutno","sedmicno","mjesecno","godisnje");
    std::string pom;
    do
    {
        std::cout<<">";
		std::getline(std::cin, pom);
        if(pom=="trenutno"||pom=="tren"||pom=="t")trenutno_jedan_proizvodi_izvjestaj_trgovac(out,k);
        else if(pom=="sedmicno"||pom=="sedm"||pom=="s")sedmicno_jedan_proizvodi_izvjestaj_trgovac(out,k);
        else if(pom=="mjesecno"||pom=="mje"||pom=="m")mjesecno_jedan_proizvodi_izvjestaj_trgovac(out,k);
        else if(pom=="godisnje"||pom=="god"||pom=="g")godisnje_jedan_proizvodi_izvjestaj_trgovac(out,k);
        else std::cout<<"GRESKA U UNOSU!!!"<<std::endl;
    }while(pom!="trenutno"&&pom!="tren"&&pom!="t"&&pom!="sedmicno"&&pom!="sedm"&&pom!="s"&&
           pom!="mjesecno"&&pom!="mje"&&pom!="m"&&pom!="godisnje"&&pom!="god"&&pom!="g");
}
void svi_kupci_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
    log(k,"svi_kupci");
    print_meni("Izvjestaji o kupcima","lista kupaca","","");
    std::string pom;
    do
    {
        std::cout<<">";
		std::getline(std::cin, pom);
        if(pom=="lista kupaca"||pom=="lk"||pom=="l")lista_kupaca_izvjestaj_trgovac(out,k);
		else std::cout << "GRESKA U UNOSU!!!" << std::endl;
    }while(pom!="lista kupaca"&&pom!="lk"&&pom!="l");
}
/************************************************************************************************/
void aktivnosti_statistika_admin(std::ostream &out, Korisnik k)
{
	log(k, "aktivnosti");
	std::string instring = "log.txt";
	std::ifstream in(instring, std::ifstream::in);
	
	print_line();
	std::string s1, s2, s3, s4, s5, s6, s7;
	s1 = "VRIJEME";
	s2 = "DAN";
	s3 = "DATUM   ";
	s4 = "OPERACIJA    ";
	s5 = "SIFRA";
	s6 = "KORISNICKO IME";
	std::cout << std::setw(8) << s1 << std::setw(4) << s2 << std::setw(13) << s3 << std::setw(20) << s4
		<< std::setw(7) << s5 << std::setw(16) << s6 << std::endl;
	print_line();
	while (in.good())
	{
		in >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7;
		if(in.good())
			std::cout << s1 << " " << std::setw(4) << s2 + " " << s3 << std::setw(20) << s4
				<< std::setw(7) << s5 << std::setw(16) << s6 << std::endl;
	}
	print_line();
	in.close();
}

void pregled_naloga_admin(std::ostream &out, Korisnik k)
{
	log(k, "pregled");
	std::string instring = "korisnici.txt";
	std::ifstream in(instring, std::ifstream::in);

	print_line();
	Korisnik kor;
	
	while (in.good())
	{
		in >> kor;
		if (kor.get_ime() != "GOST"&&in.good())
			std::cout << kor;
	}
	print_line();
	in.close();
}
void dodavanje_naloga_admin(std::ostream &out, Korisnik k)
{
	log(k, "dodavanje"); 
	std::string streamstring = "korisnici.txt";
	std::ifstream i(streamstring, std::ifstream::in);
	std::ofstream o(streamstring, std::ofstream::app);
	
	std::string sifra = "";
	std::string ime = "";
	std::string prezime = "";
	std::string korisnicko_ime = "";
	std::string lozinka = "";
	std::string zaduzenje = "";

	std::cout << "Sifra: ";
	do
	{
		if (sifra != "")
			std::cout << "     >";
		std::getline(std::cin, sifra);
	} while (sifra.length() != 6 || isnotnumeric(sifra));
	std::cout << "Ime: ";
	std::getline(std::cin, ime);
	std::cout << "Prezime: ";
	std::getline(std::cin, prezime);
	std::cout << "Korisnicko ime: ";
	std::getline(std::cin, korisnicko_ime);
	std::cout << "Lozinka: ";
	std::getline(std::cin, lozinka);
	std::cout << "Zaduzenje ( admin, trgovac, kupac ): ";
	do
	{
		if (zaduzenje != "")
			std::cout << "     >";
		std::getline(std::cin, zaduzenje);
		if (zaduzenje == "a")zaduzenje = "admin";
		else if (zaduzenje == "t")zaduzenje = "trgovac";
		else if (zaduzenje == "k")zaduzenje = "kupac";
	} while (zaduzenje != "admin"&&zaduzenje != "trgovac"&&zaduzenje != "kupac");

	Korisnik novi(sifra, ime, prezime, korisnicko_ime, lozinka, zaduzenje);

	Korisnik kor;
	bool vec_postoji = 0;
	while (i.good()&&!vec_postoji)
	{
		i >> kor;
		if (kor.get_sifra() == sifra)
		{
			vec_postoji = 1;
			print_line();
			std::cout << "KORISNIK SA ISTOM SIFROM VEC POSTOJI!!!" << std::endl;
			print_line();
			i.close();
		}
		else if (kor.get_korisnicko_ime() == korisnicko_ime)
		{
			vec_postoji = 1;
			print_line();
			std::cout << "KORISNIK SA ISTOM KORISNICKIM IMENOM VEC POSTOJI!!!" << std::endl;
			print_line();
			i.close();
		}
	}
	i.close();
	if (!vec_postoji)
		novi.out(o);
	o.close();
}
void brisanje_naloga_admin(std::ostream &out, Korisnik k)
{
	log(k, "brisanje");
	std::string streamstring = "korisnici.txt";
	std::ifstream i(streamstring, std::ifstream::in);

	std::string sifra = "";
	std::string korisnicko_ime = "";

	std::cout << "Sifra: ";
	do
	{
		if (sifra != "")
			std::cout << "     >";
		std::getline(std::cin, sifra);
	} while (sifra.length() != 6 || isnotnumeric(sifra));
	std::cout << "Korisnicko ime: ";
	std::getline(std::cin, korisnicko_ime);

	Korisnik niz[100];
	Korisnik kor;
	int n = 0;
	bool postoji = false;
	while (i.good())
	{
		i >> kor;
		if (kor.get_sifra() != "")
		{
			niz[n] = kor;
			if ((niz[n].get_sifra() == sifra) && (niz[n].get_korisnicko_ime() == korisnicko_ime))
				postoji = true;
			++n;
		}
	}
	i.close();
	if (postoji)
	{
		std::ofstream o(streamstring, std::ofstream::out);
		for (int j = 0; j < n; ++j)
			if ((niz[j].get_sifra() != sifra) || (niz[j].get_korisnicko_ime() != korisnicko_ime))
				niz[j].out(o);
		o.close();
	}
	else
		std::cout << "KORISNIK SA ZADATIM KORISNICKIM IMENOM I SIFROM NE POSTOJI!!!" << std::endl;
}
void izmjena_naloga_admin(std::ostream &out, Korisnik k) 
{
	log(k, "izmjena");
	std::string streamstring = "korisnici.txt";
	std::ifstream i(streamstring, std::ifstream::in);

	std::string sifra = "";
	std::string ime = "";
	std::string prezime = "";
	std::string korisnicko_ime = "";
	std::string lozinka = "";
	std::string zaduzenje = "";

	std::cout << "Sifra: ";
	do
	{
		if (sifra != "")
			std::cout << "     >";
		std::getline(std::cin, sifra);
	} while (sifra.length() != 6 || isnotnumeric(sifra));
	std::cout << "Ime: ";
	std::getline(std::cin, ime);
	std::cout << "Prezime: ";
	std::getline(std::cin, prezime);
	std::cout << "Korisnicko ime: ";
	std::getline(std::cin, korisnicko_ime);
	std::cout << "Lozinka: ";
	std::getline(std::cin, lozinka);
	std::cout << "Zaduzenje ( admin, trgovac, kupac ): ";
	do
	{
		if (zaduzenje != "")
			std::cout << "     >";
		std::getline(std::cin, zaduzenje);
		if (zaduzenje == "a")zaduzenje = "admin";
		else if (zaduzenje == "t")zaduzenje = "trgovac";
		else if (zaduzenje == "k")zaduzenje = "kupac";
	} while (zaduzenje != "admin"&&zaduzenje != "trgovac"&&zaduzenje != "kupac");

	Korisnik niz[100];
	Korisnik kor;
	Korisnik novi(sifra, ime, prezime, korisnicko_ime, lozinka, zaduzenje);

	int n = 0;
	bool postoji = false;
	while (i.good())
	{
		i >> kor;
		if (kor.get_sifra() != "")
		{
			niz[n] = kor;
			if ((niz[n].get_sifra() == sifra) && (niz[n].get_korisnicko_ime() == korisnicko_ime))
				postoji = true;
			++n;
		}
	}
	i.close();
	if (postoji)
	{
		std::ofstream o(streamstring, std::ofstream::out);
		for (int j = 0; j < n; ++j)
		{
			if ((niz[j].get_sifra() != sifra) || (niz[j].get_korisnicko_ime() != korisnicko_ime))
				niz[j].out(o);
			else
				novi.out(o);
		}
		o.close();
	}
	else
		std::cout << "KORISNIK SA ZADATIM KORISNICKIM IMENOM I SIFROM NE POSTOJI!!!" << std::endl;
}