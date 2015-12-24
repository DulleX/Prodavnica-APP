#include "stdafx.h"
#include "funkcije.h"
/************************************************************************************************/
//DRUGI NIVO
void statistika_admin(std::ostream &out, korisnik k)
{
    log(k,"statistika");
    print_meni("Statistika","aktivnosti","dummy1","dummy2");
    std::string pom;
    do
    {
        std::cout<<">";
        std::cin>>pom;
        if(pom=="aktivnosti"||pom=="akt"||pom=="a")aktivnosti_statistika_admin(out,k);
    }while(pom!="aktivnosti"&&pom!="akt"&&pom!="a");
}
void nalozi_admin(std::ostream &out, korisnik k)
{
    log(k,"nalozi");
    print_meni("Nalozi","pregledaj","dodaj","brisi","izmjeni");
    std::string pom;
    do
    {
        std::cout<<">";
        std::cin>>pom;
        if(pom=="pregledaj"||pom=="pregl"||pom=="p")pregled_naloga_admin(out,k);
        else if(pom=="dodaj"||pom=="dod"||pom=="d")dodavanje_naloga_admin(out,k);
        else if(pom=="brisi"||pom=="br"||pom=="b")brisanje_naloga_admin(out,k);
        else if(pom=="izmjeni"||pom=="izm"||pom=="i")izmjena_naloga_admin(out,k);
        else std::cout<<"GRESKA U UNOSU!!!"<<std::endl;
    }while(pom!="pregledaj"&&pom!="pregl"&&pom!="p"&&pom!="dodaj"&&pom!="dod"&&pom!="d"&&
           pom!="brisi"&&pom!="br"&&pom!="b"&&pom!="izmjeni"&&pom!="izm"&&pom!="i");
}
void definisanje_parametara_admin(std::ostream &out, korisnik k)
{
    log(k,"definisanje_parametara");
    print_meni("Definisanje parametara","lokacija baze podataka","dummy1","dummy2");
    std::string pom;
    do
    {
        std::cout<<">";
        std::cin>>pom;
        if(pom=="lokacija_baze_podataka"||pom=="lokacija_bp"||pom=="lokbp"||pom=="lbp"||pom=="l")
            lokacija_baze_podataka_definisanje_parametara_admin(out,k);
    }while(pom!="lokacija_baze_podataka"&&pom!="lokacija_bp"&&pom!="lokbp"&&pom!="lbp"&&pom!="l");
}

void upravljanje_proizvodima_trgovac(std::ostream &out, korisnik k)
{
    log(k,"upravljanje_proizvodima");
    print_meni("Proizvodi","pregledaj","dodaj","brisi","izmjeni");
    std::string pom;
    do
    {
        std::cout<<">";
        std::cin>>pom;
        if(pom=="pregledaj"||pom=="pregl"||pom=="p")pregled_proizvoda_trgovac(out,k);
        else if(pom=="dodaj"||pom=="dod"||pom=="d")dodavanje_proizvoda_trgovac(out,k);
        else if(pom=="brisi"||pom=="br"||pom=="b")brisanje_proizvoda_trgovac(out,k);
        else if(pom=="izmjeni"||pom=="izm"||pom=="i")izmjena_proizvoda_trgovac(out,k);
        else std::cout<<"GRESKA U UNOSU!!!"<<std::endl;
    }while(pom!="pregledaj"&&pom!="pregl"&&pom!="p"&&pom!="dodaj"&&pom!="dod"&&pom!="d"&&
           pom!="brisi"&&pom!="br"&&pom!="b"&&pom!="izmjeni"&&pom!="izm"&&pom!="i");
}
void prodaja_trgovac(std::ostream &out, korisnik k)
{
    log(k,"prodaja");
    print_meni("Prodaja","racun","dummy1","dummy2");
    std::string pom;
    do
    {
        std::cout<<">";
        std::cin>>pom;
        if(pom=="racun"||pom=="rac"||pom=="r")racun_prodaja_trgovac(out,k);
    }while(pom!="racun"&&pom!="rac"&&pom!="r");
}
void kupci_trgovac(std::ostream &out, korisnik k)
{
    log(k,"kupci");
    print_meni("Kupci","pregledaj","dodaj","brisi","izmjeni");
    std::string pom;
    do
    {
        std::cout<<">";
        std::cin>>pom;
        if(pom=="pregledaj"||pom=="pregl"||pom=="p")pregled_kupaca_trgovac(out,k);
        else if(pom=="dodaj"||pom=="dod"||pom=="d")dodavanje_kupaca_trgovac(out,k);
        else if(pom=="brisi"||pom=="br"||pom=="b")brisanje_kupaca_trgovac(out,k);
        else if(pom=="izmjeni"||pom=="izm"||pom=="i")izmjena_kupaca_trgovac(out,k);
        else std::cout<<"GRESKA U UNOSU!!!"<<std::endl;
    }while(pom!="pregledaj"&&pom!="pregl"&&pom!="p"&&pom!="dodaj"&&pom!="dod"&&pom!="d"&&
           pom!="brisi"&&pom!="br"&&pom!="b"&&pom!="izmjeni"&&pom!="izm"&&pom!="i");
}
void izvjestaji_trgovac(std::ostream &out, korisnik k)
{
    log(k,"izvjestaji");
    print_meni("Izvjestaji","svi proizvodi","jedan proizvod","svi_kupci");
    std::string pom;
    do
    {
        std::cout<<">";
        std::cin>>pom;
        if(pom=="svi_proizvodi"||pom=="spro"||pom=="sp")svi_proizvodi_izvjestaj_trgovac(out,k);
        else if(pom=="jedan_proizvod"||pom=="jpro"||pom=="jp")jedan_proizvod_izvjestaj_trgovac(out,k);
        else if(pom=="svi_kupci"||pom=="skup"||pom=="kp"||pom=="kupci"||pom=="kup"||pom=="k")svi_kupci_izvjestaj_trgovac(out,k);
        else std::cout<<"GRESKA U UNOSU!!!"<<std::endl;
    }while(pom!="svi_proizvodi"&&pom!="spro"&&pom!="sp"&&
           pom!="jedan_proizvod"&&pom!="jpro"&&pom!="jp"&&
           pom!="svi_kupci"&&pom!="skup"&&pom!="kp"&&
           pom!="kupci"&&pom!="kup"&&pom!="k");
}

void pregled_proizvoda_kupac(std::ostream &out, korisnik k)
{
    log(k,"pregled_svih_proizvoda");
    trenutno_jedan_proizvodi_izvjestaj_trgovac(out,k);
}

void jedan_proizvod_kupac(std::ostream &out, korisnik k)
{
    log(k,"pregled_jednog_proizvoda");
    trenutno_svi_proizvodi_izvjestaj_trgovac(out,k);
}
