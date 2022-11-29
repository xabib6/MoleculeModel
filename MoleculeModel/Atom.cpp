#include "Atom.h"
#include <iostream>
using namespace std;
void Atom::ShowAtomInfo()
{
	cout << "Протонов: " << _protons << "\nНейтронов: "<< _neutrons <<"\nЭлектроная оболочка:" << ElectronShell  << endl;
}

Atom::Atom()
{
	ElectronShell = 0;
	_neutrons = 0;
	_protons = 0;
	Mass = 0;
}

Atom::Atom(int protons, int neutrons, int electronShell)
{
	_protons = protons;
	_neutrons = neutrons;
	ElectronShell = electronShell;
	Mass = _neutrons + _protons;
}

