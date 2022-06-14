#pragma once

class City {
	string name;
	Location location = { "","" };
	size_t population;
	bool isCapital;

public:
	City(string name, Location location, size_t population, bool isCapital)
	{
		this->name = name;
		this->location = location;
		this->population = population;
		this->isCapital = isCapital;
	}

	friend ostream& operator<<(ostream& output, const City& c);
};
ostream& operator<<(ostream& output, const City& c)
{
	cout << "\nName: " << c.name << endl << "Location: " << c.location << endl << "Population: " << c.population << endl << "Is it capital: " << c.isCapital << endl;
	return output;
}