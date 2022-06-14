#include <iostream>
#include<forward_list>
using namespace std;
#include"BinarySearchTree.h"
#include"Location.h"
#include"City.h"
#include"Country.h"

void main() {
	cout << boolalpha;
	BinarySearchTree<Country> countries;
	Country tr("Turkey", {"5","10"}, "Recep Taip", "Europe", 3);

	tr.cities.push_front(City("Istanbul", { "4","4" }, 738787, false));
	tr.cities.push_front(City("Ankara", { "5","4" }, 538787, true));
	tr.cities.push_front(City("Izmir", { "4","5" }, 238787, false));

	Country az("Azerbaijan", { "8","15" }, "Ilham Aliyev", "Asia", 4);
	az.cities.push_front(City("Baku", { "4","5" }, 238787, true));
	az.cities.push_front(City("Ganja", { "4","5" }, 238787, false));
	az.cities.push_front(City("Sumgayit", { "4","5" }, 238787, false));
	az.cities.push_front(City("Nakhchivan", { "4","5" }, 238787, false));

	Country ru("Russia", { "30","4" }, "Putin", "Asia", 2);
	ru.cities.push_front(City("Moskva", { "4","5" }, 238787, true));
	ru.cities.push_front(City("Novosibirsk", { "4","5" }, 238787, false));

	countries.insert(tr);
	countries.insert(az);
	countries.insert(ru);

	countries.inOrder();
}


