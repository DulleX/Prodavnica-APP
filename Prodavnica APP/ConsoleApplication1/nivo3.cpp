#include "stdafx.h"
#include "funkcije.h"
/************************************************************************************************/
//TRECI NIVO
void aktivnosti_statistika_admin(std::ostream &out, Korisnik k)
{
	log(k, "aktivnosti");
	std::string instring = "log.txt";
	std::ifstream in(instring, std::ifstream::in);
	
	print_line();
	std::string s1, s2, s3, s4, s5, s6, s7;
	int w1 = 8, w2 = 3, w3 = 13, w4 = 19, w5 = 6, w6 = 16;
	s1 = "VRIJEME";
	s2 = "DAN";
	s3 = "DATUM";
	s4 = "OPERACIJA";
	s5 = "SIFRA";
	s6 = "KOR.IME";
	std::cout << "|" << std::setw(w1) << s1 << "|" << std::setw(w2) << s2 << std::setw(w3) << s3 << "|"
		<< std::setw(w4) << s4 << "|" << std::setw(w5) << s5 << "|" << std::setw(w6) << s6 << "|" << std::endl;
	print_line();
	while (in.good())
	{
		in >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7;
		if (in.good())
			std::cout << "|" << s1 << "|" << std::setw(w2) << s2 + " " << s3 << "|"
			<< std::setw(w4) << s4 << "|" << std::setw(w5) << s5 << "|" << std::setw(w6) << s6 << "|" << std::endl;
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
	Korisnik kor("SIFRA", "IME", "PREZIME", "KOR.IME", "LOZINKA", "ZADUZENJE");
	std::cout << kor;
	
	print_line();
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
	--n;
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
void brisi_datoteku_definisanje_parametara_admin(std::ostream &out, Korisnik k, std::string s)
{
	std::ofstream temp(s, std::ofstream::out);
	temp.close();
	if (s == "log.txt")log(k, "br_dat_log");
	else if (s == "proizvodi.txt")log(k, "br_dat_pro");
	else if (s == "korisnici.txt")log(k, "br_dat_kor");
}
void pregled_proizvoda_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "pregled");
	std::string instring = "proizvodi.txt";
	std::ifstream in(instring, std::ifstream::in);


	print_line();
	Proizvod pro;
	zaglavlje(std::cout);

	print_line();
	while (in.good())
	{
		in >> pro;
		if (in.good())
			std::cout << pro;
	}
	print_line();
	in.close();
}
void dodavanje_proizvoda_trgovac(std::ostream &out, Korisnik k)
{ 
	log(k, "dodavanje");
	std::string streamstring = "proizvodi.txt";
	std::ifstream i(streamstring, std::ifstream::in);
	std::ofstream o(streamstring, std::ofstream::app);

	std::string temp;
	std::string sifra = "";
	std::string naziv = "";
	std::string scijena = "";
	std::string skolicina = "";
	double cijena = 0;
	double kolicina = 0;

	std::cout << "Sifra: ";
	do
	{
		if (sifra != "")
			std::cout << "     >";
		std::getline(std::cin, sifra);
	} while (sifra.length() != 6 || isnotnumeric(sifra));
	std::cout << "Naziv: ";
	std::getline(std::cin, naziv);
	std::cout << "Cijena: ";
	do
	{
		if (scijena != "")
			std::cout << "     >";
		std::getline(std::cin, scijena);
		cijena = stod(scijena);
	} while (isnotdouble(scijena));
	std::cout << "Kolicina: ";
	do
	{
		if (skolicina != "")
			std::cout << "     >";
		std::getline(std::cin, skolicina);
		kolicina = stod(skolicina);
	} while (isnotdouble(skolicina));

	Proizvod novi(sifra, naziv, cijena, kolicina);

	Proizvod pro;
	bool vec_postoji = 0;
	while (i.good() && !vec_postoji)
	{
		i >> pro;
		if (pro.get_sifra() == sifra)
		{
			vec_postoji = 1;
			print_line();
			std::cout << "PROIZVOD SA ISTOM SIFROM VEC POSTOJI!!!" << std::endl;
			print_line();
			i.close();
		}
	}
	i.close();
	if (!vec_postoji)
		novi.out(o);
	o.close();
}
void brisanje_proizvoda_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "brisanje");
	std::string streamstring = "proizvodi.txt";
	std::ifstream i(streamstring, std::ifstream::in);

	std::string sifra = "";

	std::cout << "Sifra: ";
	do
	{
		if (sifra != "")
			std::cout << "     >";
		std::getline(std::cin, sifra);
	} while (sifra.length() != 6 || isnotnumeric(sifra));

	Proizvod niz[1000];
	Proizvod pro;
	int n = 0;
	bool postoji = false;
	while (i.good())
	{
		i >> pro;
		if (pro.get_sifra() != "")
		{
			niz[n] = pro;
			if (niz[n].get_sifra() == sifra)
				postoji = true;
			++n;
		}
	}
	i.close();
	if (postoji)
	{
		std::ofstream o(streamstring, std::ofstream::out);
		for (int j = 0; j < n; ++j)
			if ((niz[j].get_sifra() != sifra))
				niz[j].out(o);
		o.close();
	}
	else
		std::cout << "PROIZVOD SA ZADATOM SIFROM NE POSTOJI!!!" << std::endl;
}
void izmjena_proizvoda_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "izmjena");
	std::string streamstring = "proizvodi.txt";
	std::ifstream i(streamstring, std::ifstream::in);

	std::string temp;
	std::string sifra = "";
	std::string naziv = "";
	std::string scijena = "";
	std::string skolicina = "";
	double cijena = 0;
	double kolicina = 0;

	std::cout << "Sifra: ";
	do
	{
		if (sifra != "")
			std::cout << "     >";
		std::getline(std::cin, sifra);
	} while (sifra.length() != 6 || isnotnumeric(sifra));
	std::cout << "Naziv: ";
	std::getline(std::cin, naziv);
	std::cout << "Cijena: ";
	do
	{
		if (scijena != "")
			std::cout << "     >";
		std::getline(std::cin, scijena);
		cijena = stod(scijena);
	} while (isnotdouble(scijena));
	std::cout << "Kolicina: ";
	do
	{
		if (skolicina != "")
			std::cout << "     >";
		std::getline(std::cin, skolicina);
		kolicina = stod(skolicina);
	} while (isnotdouble(skolicina));

	Proizvod pro;
	Proizvod niz[1000];
	Proizvod novi(sifra, naziv, cijena, kolicina);

	int n = 0;
	bool postoji = false;
	while (i.good())
	{
		i >> pro;
		if (pro.get_sifra() != "")
		{
			niz[n] = pro;
			if ((niz[n].get_sifra() == sifra))
				postoji = true;
			++n;
		}
	}
	--n;
	i.close();
	if (postoji)
	{
		std::ofstream o(streamstring, std::ofstream::out);
		for (int j = 0; j < n; ++j)
		{
			if ((niz[j].get_sifra() != sifra))
				niz[j].out(o);
			else
				novi.out(o);
		}
		o.close();
	}
	else
		std::cout << "PROIZVOD SA ZADATOM SIFROM NE POSTOJI!!!" << std::endl;
}

void racun_prodaja_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "racun");
	std::string streamstring = "proizvodi.txt";
	std::ifstream i(streamstring, std::ifstream::in);

	Proizvod niz[1000];
	Proizvod racun[1000];

	int n = 0;
	while (i.good())
	{
		i >> niz[n];
		racun[n] = niz[n];
			++n;
	}
	--n;
	for (int i = 0; i < 1000; ++i)
		racun[i].set_kolicina(0.0);
	
	std::string temp = "";
	do
	{
		std::string sifra = "";
		std::string skolicina = "";
		double kolicina = 0;

		std::cout << "Unesite podatke o proizvodu: " << std::endl;
		std::cout << "Sifra: ";
		do
		{
			if (sifra != "")
				std::cout << "     >";
			std::getline(std::cin, sifra);
		} while (sifra.length() != 6 || isnotnumeric(sifra));
		std::cout << "Kolicina: ";
		do
		{
			if (skolicina != "")
				std::cout << "     >";
			std::getline(std::cin, skolicina);
			kolicina = stod(skolicina);
		} while (isnotdouble(skolicina));

		bool postoji = false;
		for (int i = 0; i < n && !postoji; ++i)
			if (niz[i].get_sifra() == sifra)
			{
				racun[i].set_kolicina(kolicina);
				racun[i].set_cijena(niz[i].get_cijena()*kolicina);
				niz[i].set_kolicina(niz[i].get_kolicina() - kolicina);
				postoji = true;
				if (niz[i].get_kolicina() < 0)
				{
					niz[i].set_kolicina(niz[i].get_kolicina() + kolicina);
					std::cout << "PREMALA KOLICINA PROIZVODA!!!" << std::endl;
				}
			}
		if(!postoji)
			std::cout << "PROIZVOD SA ZADATOM SIFROM NE POSTOJI!!!" << std::endl;
		print_pitanje("Ima li vise proizvoda", "da", "ne");
		getline(std::cin, temp);
	} while (temp != "ne"&&temp != "n");
	i.close();
	print_line();
	
	std::ofstream o(streamstring, std::ofstream::out);
	zaglavlje(std::cout);
	print_line();
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		niz[i].out(o);
		if (racun[i].get_kolicina()>0)
		{
			std::cout << racun[i];
			sum += racun[i].get_cijena();
		}
	}
	print_line();
	std::cout << std::setw(54) << std::fixed << std::setprecision(2) << sum << "|" << std::defaultfloat << std::endl;
	print_line();
	o.close();
}

void pregled_kupaca_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "pregled");
	std::string instring = "korisnici.txt";
	std::ifstream in(instring, std::ifstream::in);


	print_line();
	Korisnik kor("SIFRA", "IME", "PREZIME", "KOR.IME", "LOZINKA", "ZADUZENJE");
	std::cout << kor;

	print_line();
	while (in.good())
	{
		in >> kor;
		if (kor.get_ime() != "GOST"&&kor.get_zaduzenje() == "kupac"&&in.good())
			std::cout << kor;
	}
	print_line();
	in.close();
}
void dodavanje_kupaca_trgovac(std::ostream &out, Korisnik k)
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
	std::string zaduzenje = "kupac";

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

	Korisnik novi(sifra, ime, prezime, korisnicko_ime, lozinka, zaduzenje);

	Korisnik kor;
	bool vec_postoji = 0;
	while (i.good() && !vec_postoji)
	{
		i >> kor;
		if (kor.get_sifra() == sifra)
		{
			vec_postoji = 1;
			print_line();
			std::cout << "KUPAC SA ISTOM SIFROM VEC POSTOJI!!!" << std::endl;
			print_line();
			i.close();
		}
		else if (kor.get_korisnicko_ime() == korisnicko_ime)
		{
			vec_postoji = 1;
			print_line();
			std::cout << "KUPAC SA ISTOM KORISNICKIM IMENOM VEC POSTOJI!!!" << std::endl;
			print_line();
			i.close();
		}
	}
	i.close();
	if (!vec_postoji)
		novi.out(o);
	o.close();
}
void brisanje_kupaca_trgovac(std::ostream &out, Korisnik k)
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
			if ((niz[n].get_sifra() == sifra) && (niz[n].get_korisnicko_ime() == korisnicko_ime) &&
				(niz[n].get_zaduzenje() == "kupac"))
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
		std::cout << "KUPAC SA ZADATIM KORISNICKIM IMENOM I SIFROM NE POSTOJI!!!" << std::endl;
}
void izmjena_kupaca_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "izmjena");
	std::string streamstring = "korisnici.txt";
	std::ifstream i(streamstring, std::ifstream::in);

	std::string sifra = "";
	std::string ime = "";
	std::string prezime = "";
	std::string korisnicko_ime = "";
	std::string lozinka = "";
	std::string zaduzenje = "kupac";

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
			if ((niz[n].get_sifra() == sifra) && (niz[n].get_korisnicko_ime() == korisnicko_ime) && 
				(niz[n].get_zaduzenje() == "kupac"))
				postoji = true;
			++n;
		}
	}
	--n;
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
		std::cout << "KUPAC SA ZADATIM KORISNICKIM IMENOM I SIFROM NE POSTOJI!!!" << std::endl;
}
/************************************************************************************************************************/
void svi_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "svi_proizvodi");
	print_meni("Izvjestaji o svim proizvodima", "trenutno", "sedmicno", "mjesecno", "godisnje");
	std::string pom;
	do
	{
		std::cout << ">";
		std::getline(std::cin, pom);
		if (pom == "trenutno" || pom == "tren" || pom == "t")trenutno_svi_proizvodi_izvjestaj_trgovac(out, k);
		else if (pom == "sedmicno" || pom == "sedm" || pom == "s")sedmicno_svi_proizvodi_izvjestaj_trgovac(out, k);
		else if (pom == "mjesecno" || pom == "mje" || pom == "m")mjesecno_svi_proizvodi_izvjestaj_trgovac(out, k);
		else if (pom == "godisnje" || pom == "god" || pom == "g")godisnje_svi_proizvodi_izvjestaj_trgovac(out, k);
		else std::cout << "GRESKA U UNOSU!!!" << std::endl;
	} while (pom != "trenutno"&&pom != "tren"&&pom != "t"&&pom != "sedmicno"&&pom != "sedm"&&pom != "s"&&
		pom != "mjesecno"&&pom != "mje"&&pom != "m"&&pom != "godisnje"&&pom != "god"&&pom != "g");
}
void jedan_proizvod_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "jedan_proizvod");
	print_meni("Izvjestaji o pojedinacnom proizvodu", "trenutno", "sedmicno", "mjesecno", "godisnje");
	std::string pom;
	do
	{
		std::cout << ">";
		std::getline(std::cin, pom);
		if (pom == "trenutno" || pom == "tren" || pom == "t")trenutno_jedan_proizvodi_izvjestaj_trgovac(out, k);
		else if (pom == "sedmicno" || pom == "sedm" || pom == "s")sedmicno_jedan_proizvodi_izvjestaj_trgovac(out, k);
		else if (pom == "mjesecno" || pom == "mje" || pom == "m")mjesecno_jedan_proizvodi_izvjestaj_trgovac(out, k);
		else if (pom == "godisnje" || pom == "god" || pom == "g")godisnje_jedan_proizvodi_izvjestaj_trgovac(out, k);
		else std::cout << "GRESKA U UNOSU!!!" << std::endl;
	} while (pom != "trenutno"&&pom != "tren"&&pom != "t"&&pom != "sedmicno"&&pom != "sedm"&&pom != "s"&&
		pom != "mjesecno"&&pom != "mje"&&pom != "m"&&pom != "godisnje"&&pom != "god"&&pom != "g");
}
void svi_kupci_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "svi_kupci");
	print_meni("Izvjestaji o kupcima", "lista kupaca", "", "");
	std::string pom;
	do
	{
		std::cout << ">";
		std::getline(std::cin, pom);
		if (pom == "lista kupaca" || pom == "lk" || pom == "l")lista_kupaca_izvjestaj_trgovac(out, k);
		else std::cout << "GRESKA U UNOSU!!!" << std::endl;
	} while (pom != "lista kupaca"&&pom != "lk"&&pom != "l");
}
/************************************************************************************************************************/
/**KRAJ**/