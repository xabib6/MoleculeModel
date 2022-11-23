#include "Atom.h"
#include <iostream>
using namespace std;
void Atom::ShowAtomInfo()
{
	cout << "��������: " << _protons << "\n���������: "<< _neutrons <<"\n���������� ��������:" << _electronShell  << endl;
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

