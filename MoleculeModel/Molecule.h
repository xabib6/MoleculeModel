#pragma once
#include "Atom.h"
class Molecule
{
private:
	Atom* atoms;
	int _atomCount;
	int _totalEnergy;
	int _mass;

public:
	void ShowMoleculeInfo();
	void AddAtom(Atom newAtom);
	void RemoveAtomAt(int chosenAtom);
	void FindSameAtoms();
	Molecule();
};