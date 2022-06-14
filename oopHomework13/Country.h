#pragma once

class Country {
	string countryName = "";
	Location location;
	string president;
	string continent;
	size_t cityCount;
public:
	forward_list<City> cities;

	Country(string countryName, Location location, string president, string continent, size_t cityCount)
	{
		this->countryName = countryName;
		this->location = location;
		this->president = president;
		this->continent = continent;
		this->cityCount = cityCount;
	}
	friend ostream& operator<<(ostream& output, const Country& c);

	bool operator<(const Country& other)
	{
		if (countryName < other.countryName)
			return true;
		return false;
	}

	bool operator>(const Country& other)
	{
		if (countryName > other.countryName)
			return true;
		return false;
	}
};
ostream& operator<<(ostream& output, const Country& c)
{
	cout << "\nCountry: " << c.countryName << endl << "Location: " << c.location << endl << "President: " << c.president << endl << "Continent: " << c.continent << endl;
	cout << "=====Cities=====" << endl;
	for (auto i = c.cities.begin(); i != c.cities.end(); ++i)
		cout << ' ' << *i;

	return output;
}