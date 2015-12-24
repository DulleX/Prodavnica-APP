#include "stdafx.h"
#include "funkcije.h"
/************************************************************************************************/
//TRECI NIVO
void aktivnosti_statistika_admin(std::ostream &out, korisnik k){log(k,"aktivnosti");out<<"aktivnosti_statistika_admin"<<std::endl;}

void pregled_naloga_admin(std::ostream &out, korisnik k){log(k,"pregled");out<<"pregled_naloga_admin"<<std::endl;}
void dodavanje_naloga_admin(std::ostream &out, korisnik k){log(k,"dodavanje");out<<"dodavanje_naloga_admin"<<std::endl;}
void brisanje_naloga_admin(std::ostream &out, korisnik k){log(k,"brisanje");out<<"brisanje_naloga_admin"<<std::endl;}
void izmjena_naloga_admin(std::ostream &out, korisnik k){log(k,"izmjena");out<<"izmjena_naloga_admin"<<std::endl;}

void lokacija_baze_podataka_definisanje_parametara_admin(std::ostream &out, korisnik k)
    {log(k,"lokacija_bp");out<<"lokacija_baze_podataka_definisanje_parametara_admin"<<std::endl;}

void pregled_proizvoda_trgovac(std::ostream &out, korisnik k){log(k,"pregled");out<<"pregled_proizvoda_trgovac"<<std::endl;}
void dodavanje_proizvoda_trgovac(std::ostream &out, korisnik k){log(k,"dodavanje");out<<"dodavanje_proizvoda_trgovac"<<std::endl;}
void brisanje_proizvoda_trgovac(std::ostream &out, korisnik k){log(k,"brisanje");out<<"brisanje_proizvoda_trgovac"<<std::endl;}
void izmjena_proizvoda_trgovac(std::ostream &out, korisnik k){log(k,"izmjena");out<<"izmjena_proizvoda_trgovac"<<std::endl;}

void racun_prodaja_trgovac(std::ostream &out, korisnik k){log(k,"racun");out<<"racun_prodaja_trgovac"<<std::endl;}

void pregled_kupaca_trgovac(std::ostream &out, korisnik k){log(k,"pregled");out<<"pregled_kupaca_trgovac"<<std::endl;}
void dodavanje_kupaca_trgovac(std::ostream &out, korisnik k){log(k,"dodavanje");out<<"dodavanje_kupaca_trgovac"<<std::endl;}
void brisanje_kupaca_trgovac(std::ostream &out, korisnik k){log(k,"brisanje");out<<"brisanje_kupaca_trgovac"<<std::endl;}
void izmjena_kupaca_trgovac(std::ostream &out, korisnik k){log(k,"izmjena");out<<"izmjena_kupaca_trgovac"<<std::endl;}

void svi_proizvodi_izvjestaj_trgovac(std::ostream &out, korisnik k)
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
void jedan_proizvod_izvjestaj_trgovac(std::ostream &out, korisnik k)
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
void svi_kupci_izvjestaj_trgovac(std::ostream &out, korisnik k)
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
