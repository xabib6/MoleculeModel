#include "Molecule.h"

void Molecule::ShowMoleculeInfo()
{
	cout << "Атомов в молекуле: " << _atomCount << endl;
	for (int i = 0; i < _atomCount; i++)
	{
		atoms[i].ShowAtomInfo();
		cout << endl;
	}
	cout << "Масса молекулы: " << _mass << endl;
	cout << "Суммарная энергия: " << _totalEnergy << endl;
}

void Molecule::AddAtom(Atom newAtom)
{
	Atom* newAtoms = new Atom[_atomCount + 1];
	for (int i = 0; i < _atomCount; i++)
	{
		newAtoms[i] = atoms[i];
	}
	newAtoms[_atomCount] = newAtom;
	_atomCount++;

	_mass += newAtom._mass;
	_totalEnergy += newAtom._electronShell;

	delete[] atoms;
	atoms = newAtoms;
}

void Molecule::RemoveAtomAt(int chosenAtom)
{
	if (chosenAtom < 1 || chosenAtom > _atomCount)
	{
		cout << "Выбранного атома не существует! " << endl;
		return;
	}	

	Atom* newAtoms = new Atom[_atomCount - 1];
	int removal = 0;
	for (int i = 0; i < _atomCount-1; i++)
	{		
		if (i == chosenAtom - 1)
			removal = 1;
		newAtoms[i] = atoms[i+removal];
	}	
	_atomCount--;
	_mass -= atoms[chosenAtom-1]._mass;
	_totalEnergy -= atoms[chosenAtom-1]._electronShell;

	delete[] atoms;
	atoms = newAtoms;
}

void Molecule::FindSameAtoms()
{
	bool* isCounted = new bool[_atomCount];

	for (int i = 0; i < _atomCount; i++)
	{
		isCounted[i] = false;
	}	

	for (int i = 0; i < _atomCount; i++)
	{
		int sameAtomsCount = 1;
		if (!isCounted[i])
		{
			for (int j = i+1; j < _atomCount; j++)
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
	_atomCount = 0;
	_mass = 0;
	_totalEnergy = 0;
	atoms = NULL;
}
