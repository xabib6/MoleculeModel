#pragma once
#include "Atom.h"
class Molecule
{
private:
	Atom* _atoms;
	int _atomsCount;
	int _totalEnergy;
	int _mass;
public:
	void ShowMoleculeInfo();
	void AddAtom(Atom newAtom);
	void RemoveAtomAt(int chosenAtom);
	void FindSameAtoms();
	Molecule();
	~Molecule();
};