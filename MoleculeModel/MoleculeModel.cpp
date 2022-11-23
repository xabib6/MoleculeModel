#include <iostream>
#include <string>
#include "Molecule.h"



using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	Molecule molecule;
	Atom atom1(2, 9, 3);
	Atom atom2(1, 1, 1);
	Atom atom3(7, 7, 8);
	Atom atom4(1, 1, 1);
	Atom atom5(2, 9, 3);
	molecule.AddAtom(atom1);
	molecule.AddAtom(atom2);
	molecule.AddAtom(atom3);
	molecule.AddAtom(atom4);
	molecule.AddAtom(atom5);
	molecule.ShowMoleculeInfo();
	cout << "========================\n\n";

	molecule.FindSameAtoms();
}

