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
        std::cin>>pom;
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
        std::cin>>pom;
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
    print_meni("Izvjestaji o kupcima","lista_kupaca","dummy1","dummy2");
    std::string pom;
    do
    {
        std::cout<<">";
        std::cin>>pom;
        if(pom=="lista_kupaca"||pom=="lk"||pom=="l")lista_kupaca_izvjestaj_trgovac(out,k);
    }while(pom!="lista_kupaca"&&pom!="lk"&&pom!="l");
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
	s2 = "";
	s3 = "DATUM      ";
	s4 = "OPERACIJA";
	s5 = "SIFRA";
	s6 = "KORISNICKO IME";
	std::cout << std::setw(8) << s1 << " " << s2 << std::setw(16) << s3 << std::setw(20) << s4
		<< std::setw(7) << s5 << std::setw(15) << s6 << std::endl;
	while (in.good())
	{
		in >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7;
		std::cout << s1 << " " << s2 << s3 << std::setw(20) << s4
			<< std::setw(7) << s5 << std::setw(15) << s6 << std::endl;
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
		if (kor.get_sifra() != "END"&&kor.get_ime() != "GOST")
			std::cout << kor;
	}
	print_line();
	in.close();
}
void dodavanje_naloga_admin(std::ostream &out, Korisnik k)
{
	std::string streamstring = "korisnici.txt";
	std::ifstream i(streamstring, std::ifstream::in);
	std::ofstream o(streamstring, std::ofstream::app);
	log(k, "dodavanje"); 
	Korisnik kor;
	/**TREBA OVO STREDTI - NIJE GOTOVO**/
}
void brisanje_naloga_admin(std::ostream &out, Korisnik k) { log(k, "brisanje"); out << "brisanje_naloga_admin" << std::endl; }
void izmjena_naloga_admin(std::ostream &out, Korisnik k) { log(k, "izmjena"); out << "izmjena_naloga_admin" << std::endl; }