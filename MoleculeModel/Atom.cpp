#include "Atom.h"
#include <iostream>
using namespace std;
void Atom::ShowAtomInfo()
{
	cout << "Протонов: " << _protons << "\nНейтронов: "<< _neutrons <<"\nЭлектроная оболочка:" << _electronShell  << endl;
}

Atom::Atom()
{
	_electronShell = 0;
	_neutrons = 0;
	_protons = 0;
	_mass = 0;
}

Atom::Atom(int protons, int neutrons, int electronShell)
{
	_protons = protons;
	_neutrons = neutrons;
	_electronShell = electronShell;
	_mass = _neutrons + _protons;
}

