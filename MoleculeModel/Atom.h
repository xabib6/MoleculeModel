#pragma once
#include <string>
#include <iostream>
using namespace std;

class Atom
{
public:
	int _neutrons;
	int	_protons;
	int _electronShell;
	int _mass;
	bool operator == (const Atom &other)
	{
		return _neutrons == other._neutrons && _protons == other._protons && _electronShell == other._electronShell;
	}

	
	void ShowAtomInfo();

	Atom();
	Atom(int neutrons, int protons, int electronShell);

};


