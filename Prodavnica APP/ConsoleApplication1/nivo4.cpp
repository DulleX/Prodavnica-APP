#include "stdafx.h"
#include "funkcije.h"
/***********************************************************************************************/
//CETVRTI NIVO - SAMO IZVJESTAJI
void trenutno_svi_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k,"trenutno");
	print_naziv_menija("Svi proizvodi - trenutno");
	print_line();
}
void sedmicno_svi_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k,"sedmicno");
	print_naziv_menija("Svi proizvodi - sedmicno");
	print_line();
}
void mjesecno_svi_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k,"mjesecno");
	print_naziv_menija("Svi proizvodi - mjesecno");
	print_line();
}
void godisnje_svi_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k,"godisnje");
	print_naziv_menija("Svi proizvodi - godisnje");
	print_line();
}
void trenutno_jedan_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k,"trenutno");
	print_naziv_menija("Jedan proizvod - trenutno");
	print_line();
}
void sedmicno_jedan_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k,"sedmicno");
	print_naziv_menija("Jedan proizvod - sedmicno");
	print_line();
}
void mjesecno_jedan_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k,"mjesecno");
	print_naziv_menija("Jedan proizvod - mjesecno");
	print_line();
}
void godisnje_jedan_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k,"godisnje");
	print_naziv_menija("Jedan proizvod - godisnje");
	print_line();
}
void lista_kupaca_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k,"svi_kupci");
	print_naziv_menija("Pregled kupaca");
	print_line();
}
/************************************************************************************************/