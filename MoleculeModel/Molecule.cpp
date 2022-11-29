#include "Molecule.h"

void Molecule::ShowMoleculeInfo()
{
	if (_atomsCount == 0)
	{
		cout << "В молекуле нет атомов." << endl;
		return;
	}
	cout << "Атомов в молекуле: " << _atomsCount << endl;
	for (int i = 0; i < _atomsCount; i++)
	{
		cout <<"Атом " << i + 1 << ':' << endl;
		_atoms[i].ShowAtomInfo();
		cout << endl;
	}
	cout << "Масса молекулы: " << _mass << endl;
	cout << "Суммарная энергия: " << _totalEnergy << endl;
}

void Molecule::AddAtom(Atom newAtom)
{
	Atom* newAtoms = new Atom[_atomsCount + 1];
	for (int i = 0; i < _atomsCount; i++)
	{
		newAtoms[i] = _atoms[i];
	}
	newAtoms[_atomsCount] = newAtom;
	_atomsCount++;

	_mass += newAtom.Mass;
	_totalEnergy += newAtom.ElectronShell;

	delete[] _atoms;
	_atoms = newAtoms;
}

void Molecule::RemoveAtomAt(int chosenAtom)
{
	if (_atomsCount == 0)
	{
		cout << "В молекуле нет атомов." << endl;
		return;
	}
	if (chosenAtom < 1 || chosenAtom > _atomsCount)
	{
		cout << "Выбранного атома не существует! " << endl;
		return;
	}	

	Atom* newAtoms = new Atom[_atomsCount - 1];
	int removal = 0;
	for (int i = 0; i < _atomsCount-1; i++)
	{		
		if (i == chosenAtom - 1)
			removal = 1;
		newAtoms[i] = _atoms[i+removal];
	}	
	_atomsCount--;
	_mass -= _atoms[chosenAtom-1].Mass;
	_totalEnergy -= _atoms[chosenAtom-1].ElectronShell;

	delete[] _atoms;
	_atoms = newAtoms;

	cout << "Атом удалён." << endl;
}

void Molecule::FindSameAtoms()
{
	if (_atomsCount == 0)
	{
		cout << "В молекуле нет атомов." << endl;
		return;
	}
	bool* isCounted = new bool[_atomsCount];
	bool hasSameAtoms = false;
	for (int i = 0; i < _atomsCount; i++)
	{
		isCounted[i] = false;
	}	
	
	for (int i = 0; i < _atomsCount; i++)
	{		
		int sameAtomsCount = 1;
		if (!isCounted[i])
		{
			for (int j = i+1; j < _atomsCount; j++)
			{
				if (_atoms[i] == _atoms[j] && !isCounted[j])
				{
					isCounted[i] = true;
					isCounted[j] = true;					
					sameAtomsCount += 1;					
				}
			}
			if (sameAtomsCount > 1)
			{
				hasSameAtoms = true;
				_atoms[i].ShowAtomInfo();
				cout << "Количество атомов в молекуле: " << sameAtomsCount << endl << endl;				
			}
		}
	}
	if (!hasSameAtoms)
	{
		cout << "В молекуле нет одинаковых атомов." << endl;
	}
}

Molecule::Molecule()
{
	_atomsCount = 0;
	_mass = 0;
	_totalEnergy = 0;
	_atoms = NULL;
}

Molecule::~Molecule()
{
	delete[] _atoms;
}
