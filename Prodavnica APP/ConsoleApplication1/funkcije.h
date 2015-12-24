#pragma once

#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

#define SIRINA_LINIJE 70
//using namespace std;

class korisnik
{
    std::string sifra;
    std::string ime;
    std::string prezime;
    std::string korisnicko_ime;
    std::string lozinka;
    std::string zaduzenje;
public:
    korisnik(int i=0){sifra=ime=prezime=korisnicko_ime=lozinka=zaduzenje="0";}
    korisnik(const std::string sifra):sifra(sifra){}
    std::string get_sifra(){return sifra;}
    std::string get_ime(){return ime;}
    std::string get_prezime(){return prezime;}
    std::string get_korisnicko_ime(){return korisnicko_ime;}
    std::string get_lozinka(){return lozinka;}
    std::string get_zaduzenje(){return zaduzenje;}

    void set_sifra(std::string a){sifra.clear();sifra=a;}
    void set_ime(std::string a){ime.clear();ime=a;}
    void set_prezime(std::string a){prezime.clear();prezime=a;}
    void set_korisnicko_ime(std::string a){korisnicko_ime.clear();korisnicko_ime=a;}
    void set_lozinka(std::string a){lozinka.clear();lozinka=a;}
    void set_zaduzenje(std::string a){zaduzenje.clear();zaduzenje=a;}

    void nema(std::string ki, std::string l){sifra.clear();ime.clear();prezime.clear();korisnicko_ime.clear();lozinka.clear();zaduzenje.clear();
                    sifra="-NEMA-";ime=korisnicko_ime=ki;prezime=lozinka=l;zaduzenje="0";}

    friend std::istream &operator>>(std::istream &in, korisnik &k);
    friend std::ostream &operator<<(std::ostream &out, const korisnik &k);
};
void program(std::string);

/************************************************************************************************/
/**METODE KLASE I PRIJATELJSKE FUNKCIJE**/
std::istream &operator>>(std::istream &in, korisnik &k);
std::ostream &operator<<(std::ostream &out, const korisnik &k);
/************************************************************************************************/
/**OSNOVNE FUNKCIJE**/
void print_line();
void print_line(int sirina_linije);
void print_naziv_menija(std::string s);
void ispisi_vrijeme(std::ostream &out); //ova funkcija je malo teza za shvatiti posto koristi time.h biblioteku
void log(korisnik k, std::string s);
/************************************************************************************************/
/**ISPISI MENI**/
void print_meni(std::string naziv_menija, std::string opcija1, std::string opcija2);
void print_meni(std::string naziv_menija, std::string opcija1, std::string opcija2, std::string opcija3);
void print_meni(std::string naziv_menija, std::string opcija1, std::string opcija2, std::string opcija3, std::string opcija4);
/************************************************************************************************/
/**PITANJE**/
void print_pitanje(std::string pitanje);
void print_pitanje(std::string pitanje, std::string odgovor);
void print_pitanje(std::string pitanje, std::string odgovor1, std::string odgovor2);
void print_pitanje(std::string pitanje, std::string odgovor1, std::string odgovor2, std::string odgovor3);
void print_pitanje(std::string pitanje, std::string odgovor1, std::string odgovor2, std::string odgovor3, std::string odgovor4);
void print_pitanje(std::string pitanje, std::string odgovor1, std::string odgovor2, std::string odgovor3, std::string odgovor4, std::string odgovor5);

/************************************************************************************************/
/**DEKLARACIJE**/
void program(std::string);
/************************************************************************************************/
//NULTI NIVO
korisnik login(std::string);
void glavni_meni(std::ostream &, korisnik);
/************************************************************************************************/
//PRVI NIVO
void admin_meni(std::ostream &, korisnik);
void trgovac_meni(std::ostream &, korisnik);
void kupac_meni(std::ostream &, korisnik);
/************************************************************************************************/
//DRUGI NIVO
void statistika_admin(std::ostream &, korisnik);
void nalozi_admin(std::ostream &, korisnik);
void definisanje_parametara_admin(std::ostream &, korisnik);

void upravljanje_proizvodima_trgovac(std::ostream &, korisnik);
void prodaja_trgovac(std::ostream &, korisnik);
void kupci_trgovac(std::ostream &, korisnik);
void izvjestaji_trgovac(std::ostream &, korisnik);

void pregled_proizvoda_kupac(std::ostream &, korisnik);
void jedan_proizvod_kupac(std::ostream &, korisnik);
/************************************************************************************************/
//TRECI NIVO
void aktivnosti_statistika_admin(std::ostream &, korisnik);

void pregled_naloga_admin(std::ostream &, korisnik);
void dodavanje_naloga_admin(std::ostream &, korisnik);
void brisanje_naloga_admin(std::ostream &, korisnik);
void izmjena_naloga_admin(std::ostream &, korisnik);

void lokacija_baze_podataka_definisanje_parametara_admin(std::ostream &, korisnik);

void pregled_proizvoda_trgovac(std::ostream &, korisnik);
void dodavanje_proizvoda_trgovac(std::ostream &, korisnik);
void brisanje_proizvoda_trgovac(std::ostream &, korisnik);
void izmjena_proizvoda_trgovac(std::ostream &, korisnik);

void racun_prodaja_trgovac(std::ostream &, korisnik);

void pregled_kupaca_trgovac(std::ostream &, korisnik);
void dodavanje_kupaca_trgovac(std::ostream &, korisnik);
void brisanje_kupaca_trgovac(std::ostream &, korisnik);
void izmjena_kupaca_trgovac(std::ostream &, korisnik);

void svi_proizvodi_izvjestaj_trgovac(std::ostream &, korisnik);
void jedan_proizvod_izvjestaj_trgovac(std::ostream &, korisnik);
void svi_kupci_izvjestaj_trgovac(std::ostream &, korisnik);
/************************************************************************************************/
//CETVRTI NIVO - SAMO IZVJESTAJI
void trenutno_svi_proizvodi_izvjestaj_trgovac(std::ostream &, korisnik);
void sedmicno_svi_proizvodi_izvjestaj_trgovac(std::ostream &, korisnik);
void mjesecno_svi_proizvodi_izvjestaj_trgovac(std::ostream &, korisnik);
void godisnje_svi_proizvodi_izvjestaj_trgovac(std::ostream &, korisnik);

void trenutno_jedan_proizvodi_izvjestaj_trgovac(std::ostream &, korisnik);
void sedmicno_jedan_proizvodi_izvjestaj_trgovac(std::ostream &, korisnik);
void mjesecno_jedan_proizvodi_izvjestaj_trgovac(std::ostream &, korisnik);
void godisnje_jedan_proizvodi_izvjestaj_trgovac(std::ostream &, korisnik);

void lista_kupaca_izvjestaj_trgovac(std::ostream &, korisnik);
