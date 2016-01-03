#include "Korisnik.h"
#include "Proizvod.h"
/************************************************************************************************/
/**OSNOVNE FUNKCIJE**/
void print_line();
void print_line(int sirina_linije);
void print_naziv_menija(std::string s);
void ispisi_vrijeme(std::ostream &out); //ova funkcija je malo teza za shvatiti posto koristi time.h biblioteku
void log(Korisnik k, std::string s);
bool isnotnumeric(std::string s);
bool isnotdouble(std::string s);
/************************************************************************************************/
/**ISPISI MENI**/
void print_meni(std::string naziv_menija, std::string opcija1);
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
//NULTI NIVO
void program(std::string);
Korisnik login(std::string);
void glavni_meni(std::ostream &, Korisnik);
/************************************************************************************************/
//PRVI NIVO
void admin_meni(std::ostream &, Korisnik);
void trgovac_meni(std::ostream &, Korisnik);
void kupac_meni(std::ostream &, Korisnik);
/************************************************************************************************/
//DRUGI NIVO
void statistika_admin(std::ostream &, Korisnik);
void nalozi_admin(std::ostream &, Korisnik);
void definisanje_parametara_admin(std::ostream &, Korisnik);

void upravljanje_proizvodima_trgovac(std::ostream &, Korisnik);
void prodaja_trgovac(std::ostream &, Korisnik);
void kupci_trgovac(std::ostream &, Korisnik);
void izvjestaji_trgovac(std::ostream &, Korisnik);

void pregled_proizvoda_kupac(std::ostream &, Korisnik);
void jedan_proizvod_kupac(std::ostream &, Korisnik);
/************************************************************************************************/
//TRECI NIVO
void aktivnosti_statistika_admin(std::ostream &, Korisnik);

void pregled_naloga_admin(std::ostream &, Korisnik);
void dodavanje_naloga_admin(std::ostream &, Korisnik);
void brisanje_naloga_admin(std::ostream &, Korisnik);
void izmjena_naloga_admin(std::ostream &, Korisnik);

void brisi_datoteku_definisanje_parametara_admin(std::ostream &, Korisnik, std::string);

void pregled_proizvoda_trgovac(std::ostream &, Korisnik);
void dodavanje_proizvoda_trgovac(std::ostream &, Korisnik);
void brisanje_proizvoda_trgovac(std::ostream &, Korisnik);
void izmjena_proizvoda_trgovac(std::ostream &, Korisnik);

void racun_prodaja_trgovac(std::ostream &, Korisnik);

void pregled_kupaca_trgovac(std::ostream &, Korisnik);
void dodavanje_kupaca_trgovac(std::ostream &, Korisnik);
void brisanje_kupaca_trgovac(std::ostream &, Korisnik);
void izmjena_kupaca_trgovac(std::ostream &, Korisnik);

void svi_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);
void jedan_proizvod_izvjestaj_trgovac(std::ostream &, Korisnik);
void svi_kupci_izvjestaj_trgovac(std::ostream &, Korisnik);
/************************************************************************************************/
//CETVRTI NIVO - SAMO IZVJESTAJI
void trenutno_svi_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);
void sedmicno_svi_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);
void mjesecno_svi_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);
void godisnje_svi_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);

void trenutno_jedan_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);
void sedmicno_jedan_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);
void mjesecno_jedan_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);
void godisnje_jedan_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);

void lista_kupaca_izvjestaj_trgovac(std::ostream &, Korisnik);
/************************************************************************************************/