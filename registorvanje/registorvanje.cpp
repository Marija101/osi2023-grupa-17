
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;



















































































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
		std::fstream datoteka("radnikPodaciRegistracija.txt", std::ios::in | std::ios::out | std::ios::app);


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
	ifstream file("radnikPodaciAktiviraniRegistracija.txt");

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

		fstream filee("radnikPodaciPrijaveZavrsniRegistracija.txt", std::ios::in | std::ios::out | std::ios::app);

		if (filee.is_open())
		{

			int br = 0;
			string sadrzajFajlaa = "";

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
			ofstream fileee("radnikPodaciPrijaveZavrsniRegistracija.txt", std::ios::trunc);
			string aaa = "aAA";
			if (fileee.is_open())
			{








				fileee.close();

			}
			else
				cout << "Nije otvorena";



			ofstream fileeee("radnikPodaciPrijaveZavrsniRegistracija.txt");

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

	cout << "Izaberite opciju: 1.aktivacija naloga | 2.brisanje naloga" << endl;
	cin >> opcija;

	if (opcija == 1)
	{
		ifstream file("radnikPodaciRegistracija.txt");
		ofstream filee("radnikPodaciAktiviraniRegistracija.txt", ofstream::out);
		ofstream fileee("radnikPodaciPrijaveZavrsniRegistracija.txt");
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
		ofstream fileee("radnikPodaciPrijaveZavrsniRegistracija.txt", std::ios::trunc);
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
					cout << "Prijavljeni ste kao: " << pronadjeniKorisnik.korisnickoIme << endl;
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
	return sifra == "12345aa";
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




void platiDadzbine(string korisnickoIme)
{

	cout << "Spisak obaveza koje morate platiti:" << endl;
	cout << "Naknada za javne puteve" << endl;
	cout << "Uplata polise osiguranja" << endl;
	cout << "Porez za upotrebu vozila" << endl;
	cout << "Stiker naljepnica" << endl;
	cout << "Eko taksa" << endl;
	cout << "Uplata za Auto-moto savez" << endl;
	cout << "Naknada za tehnicki pregled" << endl;
	
	cout << "Unesite broj kartice (16 cifara)" << endl;
	string brojKartice;

	cin >> brojKartice;
	while (brojKartice.size() != 16)
	{
		cout << "Neispravan broj kartice, unesite ponovo" << endl;
		cin >> brojKartice;
	}
	cout << "Unesite pin kartice (4 cifara)" << endl;
	string pin;

	cin >> pin;
	while (pin.size() != 4)
	{
		cout << "Neispravan pin kartice, unesite ponovo" << endl;
		cin >> pin;
	}

	
	ofstream datotekaDadzbine("datotekaDadzbine.txt", std::ios::app);

	



	if (datotekaDadzbine.is_open())
	{
		datotekaDadzbine << korisnickoIme << endl;
		datotekaDadzbine.close();
	}
	else
		cout << "Nije otvorena datoteka";

	cout << "Platili ste dadzbine"<<endl;
	cout << "Unesite 3 za povratak nazad" << endl;

}

bool postojiLiKorisnickoImeZaKazne(string korisnickoIme, ifstream *file)
{
	
	
		std::string line;
		bool flag = 0;

		while (flag == 0 && getline(*file, line) )
		{

			if (line == korisnickoIme)
				flag = 1;

			

		}
		

		if (flag == 1)
			return 1;
		else
			return 0;
		

		
		
	

}

void platiKazne(string korisnickoIme)
{

	ifstream file("kazne.txt");

	if (file.is_open())
	{
		std::string line;// Čitanje svake linije iz datoteke i ispis na ekran




		if (postojiLiKorisnickoImeZaKazne(korisnickoIme, &file))
		{


			getline(file, line);

			istringstream iss(line);
			string prvaRijec;


			// Čitanje prve riječi iz stringstream-a
			iss >> prvaRijec;



			if (prvaRijec == "Kazna")
			{
				cout << "Kazne: " << endl;
				cout << line << endl;
			}


			while (getline(file, line) && prvaRijec == "Kazna") // ovo je da bi zaustavilo kad dodje do username od sl korisnika
			{



				istringstream iss(line);
				iss >> prvaRijec;
				if (prvaRijec == "Kazna")// ovo je da ne ispisuje username
					cout << line << endl;
			}
			cout << "Unesite broj kartice (16 cifara)" << endl;
			string brojKartice;

			cin >> brojKartice;
			while (brojKartice.size() != 16)
			{
				cout << "Neispravan broj kartice, unesite ponovo" << endl;
				cin >> brojKartice;
			}
			cout << "Unesite pin kartice (4 cifara)" << endl;
			string pin;

			cin >> pin;
			while (pin.size() != 4)
			{
				cout << "Neispravan pin kartice, unesite ponovo" << endl;
				cin >> pin;
			}


			ofstream datotekaDadzbine("placeneKazne.txt", std::ios::app);





			if (datotekaDadzbine.is_open())
			{
				datotekaDadzbine << korisnickoIme << endl;
				datotekaDadzbine.close();
			}
			else
				cout << "Nije otvorena datoteka";

			cout << "Platili ste Kazne" << endl;
			cout << "Unesite 3 za povratak nazad" << endl;
		}
		else
		{
			cout << "Nemate kazne" << endl<<"Unesite 3 za povratak nazad"<<endl;
		}

		file.close();
	}
	else
		cout << "Greska kod otvaranja datoteke";
	

	// Čitanje svake linije iz datoteke i ispis na ekran
	
	// Zatvaranje datoteke
	






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
		if (proveriKorisnikaDatoteke("radnikPodaciPrijaveZavrsniRegistracija.txt", sifra, pronadjeniKorisnik))
		{
			/*if (pronadjeniKorisnik.adminStatus == "admin") {
				cout << "Pronadjen admin korisnik u radnicima!" << endl;
			}
			else {
				cout << "Pronadjen obican korisnik u radnicima!" << endl;
			}*/
		}
		else {
			cout << "Korisnik nije pronadjen u radnicima!" << endl;
		}
	}
	else if (sifraSamoSlova(sifra)) {
		if (proveriKorisnikaDatoteke("osi2023-grupa-17/klijentPodaci.txt", sifra, pronadjeniKorisnik)) 
		{
			/*if (pronadjeniKorisnik.adminStatus == "admin") {
				cout << "Pronadjen admin korisnik u klijentima!" << endl;
			}
			else {
				cout << "Pronadjen obican korisnik u klijentima!" << endl;
			}*/
			int opcija;
			cout << "Izaberite opciju: 5. Plati dadzbine | 3. Nazad | 6. Pregled i placanje kazni" << endl;
			cin >> opcija;

			while (opcija != 3)
			{
				
				if (opcija == 5)
				{
					
					platiDadzbine(pronadjeniKorisnik.korisnickoIme);


				}

				if (opcija == 6)
				{
					platiKazne(pronadjeniKorisnik.korisnickoIme);
				}

				cin >> opcija;



			}
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

