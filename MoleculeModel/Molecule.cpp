#include "Molecule.h"

void Molecule::ShowMoleculeInfo()
{
	for (int i = 0; i < _length; i++)
	{
		atoms[i].ShowAtomInfo();
		cout << "==============================\n";
	}
	cout << "Масса молекулы: " << _mass << endl;
	cout << "Суммарная энергия: " << _totalEnergy << endl;
}

void Molecule::AddAtom(Atom newAtom)
{
	Atom* newAtoms = new Atom[_length + 1];
	for (int i = 0; i < _length; i++)
	{
		newAtoms[i] = atoms[i];
	}
	newAtoms[_length] = newAtom;
	_length++;

	_mass += newAtom._mass;
	_totalEnergy += newAtom._electronShell;

	delete[] atoms;
	atoms = newAtoms;
}

void Molecule::RemoveAtomAt(int chosenAtom)
{
	if (chosenAtom < 1 || chosenAtom > _length)
	{
		cout << "Выбранного атома не существует! " << endl;
		return;
	}	

	Atom* newAtoms = new Atom[_length - 1];
	int removal = 0;
	for (int i = 0; i < _length-1; i++)
	{		
		if (i == chosenAtom - 1)
			removal = 1;
		newAtoms[i] = atoms[i+removal];
	}	
	_length--;
	_mass -= atoms[chosenAtom-1]._mass;
	_totalEnergy -= atoms[chosenAtom-1]._electronShell;

	delete[] atoms;
	atoms = newAtoms;
}

void Molecule::FindSameAtoms()
{
	bool* isCounted = new bool[_length];

	for (int i = 0; i < _length; i++)
	{
		isCounted[i] = false;
	}	

	for (int i = 0; i < _length; i++)
	{
		int sameAtomsCount = 1;
		if (!isCounted[i])
		{
			for (int j = i+1; j < _length; j++)
			{
				if (atoms[i] == atoms[j] && !isCounted[j])
				{
					isCounted[i] = true;
					isCounted[j] = true;
					sameAtomsCount += 1;
				}
			}
			if (sameAtomsCount > 1)
			{
				cout << "==============================" << endl;
				cout << "Характеристики атома: " << endl;
				atoms[i].ShowAtomInfo();
				cout << "Количество атомов в молекуле: " << sameAtomsCount << endl;
				cout << "==============================" << endl;
			}
		}
	}
}

Molecule::Molecule()
{
	_length = 0;
	_mass = 0;
	_totalEnergy = 0;
	atoms = NULL;
}
