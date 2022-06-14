#pragma once
struct Location {
	string longitude;
	string latitude;

	Location() = default;
	Location(string longitude, string latitude)
	{
		this->longitude = longitude;
		this->latitude = latitude;
	}

};
ostream& operator<<(ostream& output, const Location& l)
{
	cout << l.longitude << " . " << l.latitude;
	return output;
}