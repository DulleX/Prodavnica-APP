#include "stdafx.h"
#include "Korisnik.h"
/************************************************************************************************/
/**PRIJATELJSKE FUNKCIJE**/
std::istream &operator>>(std::istream &in, Korisnik &k)
{
	in >> k.sifra >> k.ime >> k.prezime >> k.korisnicko_ime >> k.lozinka >> k.zaduzenje;
	return in;
}
std::ostream &operator<<(std::ostream &out, const Korisnik &k)
{
	int w = 10;
	int wsifre = 7;
	out << "|" << std::setw(wsifre) << k.sifra << "|" << std::setw(w) << k.ime << "|" << std::setw(w) << k.prezime << "|"
		<< std::setw(w) << k.korisnicko_ime << "|" << std::setw(w) << k.lozinka << "|" << std::setw(w) << k.zaduzenje << "|" << std::endl;
	return out;
}
/************************************************************************************************/