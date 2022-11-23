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

Atom::Atom(int neutrons, int protons, int electronShell)
{
	_neutrons = neutrons;
	_protons = protons;
	_electronShell = electronShell;
	_mass = _neutrons + _protons;
}

