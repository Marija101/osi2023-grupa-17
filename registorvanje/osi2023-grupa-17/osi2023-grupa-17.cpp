
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

















































struct Termin
{
	std::string datum;
	std::string vrijeme;
};

bool provjeri_termin(const std::string& imeDatoteke, const Termin& noviTermin)
{
	std::ifstream datoteka(imeDatoteke);
	if (datoteka.is_open())
	{
		std::string datum, vrijeme;
		while (datoteka >> datum >> vrijeme)
		{
			if (datum == noviTermin.datum && vrijeme == noviTermin.vrijeme)
			{
				datoteka.close();
				return true;
			}
		}
		datoteka.close();
		return false;
	}
	else
		std::cout << "Nije moguce otvoriti datoteku" << std::endl;
}


void dodaj_termin_u_datoteku(const std::string& imeDatoteke, Termin& noviTermin)
{
	while (provjeri_termin(imeDatoteke, noviTermin))
	{
		std::cout << "Termin je zauzet, nije moguce dodati termin" << std::endl;

		std::cout << "Unesite drugi datum (dan.mjesec.godina): ";
		std::cin >> noviTermin.datum;
		std::cout << "Unesi drugo vrijeme (sat:minut): ";
		std::cin >> noviTermin.vrijeme;


	}

	std::ofstream datoteka(imeDatoteke, std::ios::app);
	if (datoteka.is_open())
	{
		datoteka << noviTermin.datum << " " << noviTermin.vrijeme << std::endl;
		std::cout << "Termin uspjesno dodan." << std::endl;
		datoteka.close();
	}
}

void unos_termina()
{
	Termin noviTermin;
	std::cout << "Unesi datum (dan.mjesec.godina): ";
	std::cin >> noviTermin.datum;
	std::cout << "Unesite vrijeme (sat::minut): ";
	std::cin >> noviTermin.vrijeme;

	const std::string imeDatoteke = "termini.txt";
	dodaj_termin_u_datoteku(imeDatoteke, noviTermin);
}


void ispisi_sve_termine(const std::string& imeDatoteke)
{
	std::ifstream datoteka(imeDatoteke);
	if (datoteka.is_open())
	{
		std::string linija;
		while (std::getline(datoteka, linija))
		{
			std::cout << linija << std::endl;
		}
		datoteka.close();
	}
	else
		std::cout << "Nije moguce otvoriti datoteku!" << std::endl;
}

void obrisi_termin(const std::string& imeDatoteke, const std::string& terminZaBrisanje)
{
	std::ifstream ulaz(imeDatoteke);
	if (!ulaz.is_open())
		std::cout << "Nije moguce otvoriti datoteku" << std::endl;
	std::vector<std::string> linije;
	std::string linija;
	while (std::getline(ulaz, linija))
	{
		if (linija != terminZaBrisanje)
		{
			linije.push_back(linija);
		}
	}
	ulaz.close();

	std::ofstream izlaz(imeDatoteke);
	if (!izlaz.is_open())
		std::cout << "Nije moguce otvoriti datoteku" << std::endl;
	for (const std::string& novaLinija : linije)
	{
		izlaz << novaLinija << std::endl;
	}
	izlaz.close();
}

void upravljanje_terminima()
{
	int opcija;
	do
	{
		std::cout << "Izaberite opciju: \n 1.Ispis termina\n 2.Brisanje termina" << std::endl;
		std::cin >> opcija;
		std::string terminZaBrisanje;

		switch (opcija)
		{
		case 1:
			ispisi_sve_termine("termini.txt");
			break;

		case 2:
			ispisi_sve_termine("termini.txt");
			std::cout << "Unesite termin koji zelite da obrisete: ";
			std::cin.ignore();
			std::getline(std::cin, terminZaBrisanje);
			obrisi_termin("termini.txt", terminZaBrisanje);
			std::cout << "Termin uspjesno obrisan" << std::endl;
			break;

		case 3:
			std::cout << "Izlaz iz programa" << std::endl;
			break;

		default:
			std::cout << "Nepostojeca opcija. Molimo odaberite ponovo." << std::endl;
		}
	} while (opcija != 3);

}

































bool validacija(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (!isdigit(s[i]) && !isalpha(s[i]))
			return 0;

	return 1;

}




bool imaLiCifara(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]))
			return 0;
	return 1;

}

bool validacijaZaSifru(string s)
{
	int slovo = 0;
	int broj = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]))
			broj++;
		if (isalpha(s[i]))
			slovo++;
		if (slovo > 0 && isdigit(s[i]))
			return 0;
		if (broj > 0 && isalpha(s[i]))
			return 0;
	}

	return 1;

}


void registracija()
{
	string ime;
	string prezime;
	string username;
	string sifra;

	cout << "Unesite sifru (samo slova ili samo brojevi, sifra mora da ima najmanje 6 a najvise 12 karaktera): " << endl;

	int i = 0;

	cin >> sifra;


	while (sifra.length() < 6 || sifra.length() > 12 || validacija(sifra) == 0 || validacijaZaSifru(sifra) == 0)
	{
		cout << "ponovo unesite sifru" << endl;
		cin >> sifra;
	}

	if (imaLiCifara(sifra) == 0)
	{
		std::fstream datoteka("radnikPodaci.txt", std::ios::in | std::ios::out | std::ios::app);


		if (datoteka.is_open())
		{


			datoteka.seekp(0, std::ios::end);



			datoteka << sifra << endl;
			cout << "unesite ime: ";
			cin >> ime;

			datoteka << ime << endl;
			cout << "unesite prezime: ";

			cin >> prezime;
			datoteka << prezime << endl;



			cout << "unesite korisnicko ime (dozvoljena su samo slova i cifre, broj karaktera mora biti 6-12): ";

			cin >> username;
			while (validacija(username) == 0 || username.length() < 6 || username.length() > 12)
			{
				cout << "Neispravno korisnicko ime unesite ga ponovo: " << endl;
				cin >> username;
			}

			datoteka << username << endl;

			datoteka.close();
		}

		else
			cout << "Datoteka nije otvorena";
	}
	else
	{
		std::fstream datoteka("klijentPodaci.txt", std::ios::in | std::ios::out | std::ios::app);


		if (datoteka.is_open())
		{


			datoteka.seekp(0, std::ios::end);



			datoteka << sifra << endl;
			cout << "unesite ime: ";
			cin >> ime;

			datoteka << ime << endl;
			cout << "unesite prezime: ";

			cin >> prezime;
			datoteka << prezime << endl;

			cout << "unesite korisnicko ime (dozvoljena su samo slova i cifre, broj karaktera mora biti 6-12): ";

			cin >> username;
			while (validacija(username) == 0 || username.length() < 6 || username.length() > 12)
			{
				cout << "Neispravno korisnicko ime unesite ga ponovo: " << endl;
				cin >> username;
			}

			datoteka << username << endl;

			datoteka.close();
		}
		else
			cout << "Datoteka nije otvorena";
	}

	cout << "Registrovani ste na sistem" << endl;

}


void brisanjeIzDatoteke()
{
	ifstream file("radnikPodaciAktivirani.txt");

	if (file.is_open())
	{
		cout << "Spisak usernames:" << endl;
		int brojacRedova = 0;
		string sadrzajFajla;
		while (getline(file, sadrzajFajla))
		{
			brojacRedova++;
			
			if (brojacRedova % 4 == 0)
				cout << sadrzajFajla << endl;
		}

		cout << "Unesite username koji zelite da obrisete: " << endl;
		string username;
		cin >> username;

		fstream filee("radnikPodaciPrijaveZavrsni.txt", std::ios::in | std::ios::out | std::ios::app);

		if (filee.is_open())
		{
			
			int br = 0;
			string sadrzajFajlaa="";
			
			// Ponovo otvaranje fajla za citanje, kako bi se vratili na početak
			file.clear();
			file.seekg(0, ios::beg);
			
			
			filee.seekg(0, ios::end);
			

			if (filee.tellg() == 0)
			{
				
				while (getline(file, sadrzajFajlaa))
				{
					
					filee << sadrzajFajlaa << endl;
					
				}
			}

			
			
			filee.seekg(0, ios::beg);
			
			
			
			vector<string> sadrzajIzDatoteke;


			while (getline(filee, sadrzajFajlaa) && !filee.eof())
			{
				
				br++;
				sadrzajIzDatoteke.push_back(sadrzajFajlaa);

				

			}filee.close();
			ofstream fileee("radnikPodaciPrijaveZavrsni.txt", std::ios::trunc);
			string aaa = "aAA";
			if (fileee.is_open())
			{

				
				
				


				

				fileee.close();

			}
			else
				cout << "Nije otvorena";

			

			ofstream fileeee("radnikPodaciPrijaveZavrsni.txt");
			
			if (fileeee.is_open())
			{
				
				int j = 3;
				for (size_t i = 0; i < sadrzajIzDatoteke.size(); i++)
				{
					
					if (sadrzajIzDatoteke[j] == username)
					{
						
						i = i + 3;
						


					}
					else
					{
						
						fileeee << sadrzajIzDatoteke[i] << endl;
					}
					if (i == j)
						j = j + 4;


				}

				







				fileeee.close();

			}
			else
				cout << "Nije otvorena";

			
			
		}
		else
		{
			cout << "Greska pri otvaranju izlazne datoteke." << endl;
		}

		file.close();
	}
	else
	{
		cout << "Greska pri otvaranju ulazne datoteke." << endl;
	}
}
void upravljanjeNalozima()
{
	int opcija;

	cout << "Izaberite opciju: 1.aktivacija naloga | 2.brisanje naloga"<<endl;
	cin >> opcija;

	if (opcija == 1)
	{
		ifstream file("radnikPodaci.txt");
		ofstream filee("radnikPodaciAktivirani.txt", ofstream::out);
		ofstream fileee("radnikPodaciPrijaveZavrsni.txt");
		if (file.is_open() && filee.is_open() && fileee.is_open())
		{
			string sadrzajFajla;
			while (getline(file, sadrzajFajla))
			{
				filee << sadrzajFajla << endl;
				fileee << sadrzajFajla << endl;
			}


			file.close();
			filee.close();
			fileee.close();
		}
		else
			cout << "Greska";
	}
	
	else if (opcija == 2)
	{
		ofstream fileee("radnikPodaciPrijaveZavrsni.txt", std::ios::trunc);
		if (fileee.is_open())
		{








			fileee.close();

		}
		else
			cout << "Nije otvorena";

			brisanjeIzDatoteke();

			
		


	}





}
struct Korisnik {
	string sifra;
	string ime;
	string prezime;
	string korisnickoIme;
	string adminStatus;
};

bool proveriKorisnikaDatoteke(const string& datoteka, const string& sifra, Korisnik& pronadjeniKorisnik) {
	ifstream korisnikDatoteka(datoteka);

	if (korisnikDatoteka.is_open()) {
		
		bool flag = 0;
		int i = 0;
		string linija;
		while (getline(korisnikDatoteka, pronadjeniKorisnik.sifra))
		{
			if (i % 4 == 0 && flag == 0)
			{
				if (pronadjeniKorisnik.sifra == sifra)
				{
					flag = 1;
	
					getline(korisnikDatoteka, pronadjeniKorisnik.ime);
					getline(korisnikDatoteka, pronadjeniKorisnik.prezime);
					getline(korisnikDatoteka, pronadjeniKorisnik.korisnickoIme);
					cout <<"Prijavljeni ste kao: " << pronadjeniKorisnik.korisnickoIme<<endl;
					return true;
				}

			}
			i++;
			
			
			

			
			
		}

		korisnikDatoteka.close();
	}
	else {
		cout << "Greska prilikom otvaranja datoteke: " << datoteka << endl;
	}

	return false;
}

bool jeAdmin(const string& sifra) {
	return sifra == "12345a";
}

bool sifraSamoCifre(const string& sifra) {
	for (char karakter : sifra) {
		if (!isdigit(karakter)) {
			return false;
		}
	}
	return true;
}

bool sifraSamoSlova(const string& sifra) {
	for (char karakter : sifra) {
		if (!isalpha(karakter)) {
			return false;
		}
	}
	return true;
}

void prijavaKorisnika(const string& sifra, const string& datoteka) {
	Korisnik pronadjeniKorisnik;
	int opcija;

	if (jeAdmin(sifra)) {
		cout << "Prijavljeni ste kao admin!" << endl;
		cout << "Izaberite opciju: 4. upravljanje nalozima | 3. odjava" << endl;
		cin >> opcija;
		while (opcija != 3)
		{
			if (opcija == 4)

				upravljanjeNalozima();

			cout << "Unesite 3 za vracanje nazad" << endl;
			cin >> opcija;

		}
	}
	else if (sifraSamoCifre(sifra)) {
		if (proveriKorisnikaDatoteke("radnikPodaciPrijaveZavrsni.txt", sifra, pronadjeniKorisnik)) 
		{
			/*if (pronadjeniKorisnik.adminStatus == "admin") {
				cout << "Pronadjen admin korisnik u radnicima!" << endl;
			}
			else {
				cout << "Pronadjen obican korisnik u radnicima!" << endl;
			}*/
			int opcija;
			std::cout << "Izaberite opciju: \n 1.Unos termina\n 2.Upravljanje terminima" << std::endl;
			std::cin >> opcija;
			if (opcija == 1)
				unos_termina();
			if (opcija == 2)
				upravljanje_terminima();

		}
		else {
			cout << "Korisnik nije pronadjen u radnicima!" << endl;
		}
	}
	else if (sifraSamoSlova(sifra)) {
		if (proveriKorisnikaDatoteke("klijentPodaci.txt", sifra, pronadjeniKorisnik)) {
			/*if (pronadjeniKorisnik.adminStatus == "admin") {
				cout << "Pronadjen admin korisnik u klijentima!" << endl;
			}
			else {
				cout << "Pronadjen obican korisnik u klijentima!" << endl;
			}*/
		}
		else {
			cout << "Korisnik nije pronadjen u klijentima!" << endl;
		}
	}
	else {
		cout << "Pogresna sifra! Radnikova sifra treba sadrzavati samo cifre, a klijentova samo slova." << endl;
	}
}



int main()
{

























































































	int opcija;
	cout << "Izaberite opciju: 1. registracija na sistem | 2.prijava | 3.odjava" << endl;
	cin >> opcija;

	while (opcija != 3)
	{
		if (opcija == 1)

			registracija();
		if (opcija == 2)
		{
			string sifra;
			string username;
			cout << "Unesite username: ";
			cin >> username;
			cout << "Unesite sifru: ";
			cin >> sifra;

			prijavaKorisnika(sifra, "klijentPodaci.txt");

			
		}
		cin >> opcija;



	}
}

