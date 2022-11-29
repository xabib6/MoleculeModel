#pragma once
#include <string>
#include <iostream>
using namespace std;

class Atom
{
private:
	int _neutrons;
	int	_protons;
public:	
	int ElectronShell;
	int Mass;
	bool operator == (const Atom &other)
	{
		return _neutrons == other._neutrons && _protons == other._protons && ElectronShell == other.ElectronShell;
	}	
	void ShowAtomInfo();
	Atom();
	Atom(int neutrons, int protons, int electronShell);
};


