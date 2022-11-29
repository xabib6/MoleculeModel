#pragma once
#include "Molecule.h"
class MoleculeManager
{
private:
	Molecule _molecule;
public:
	MoleculeManager()
	{
		_molecule = Molecule();
	}
	void Start()
	{
		Atom atom;
		char input;
		while (true)
		{
			cout << "=====================================" << endl;
			cout << "������ ������: \n1)�������� ����. \n2)�������� ���������� � ��������. \n" <<
				"3)������� ����. \n4)�������� ���������� �����.  \n5)������� ��� �����. \n" <<
				"6)��������� ������. " << endl;
			cout << "=====================================" << endl;

			cin >> input;
			switch (input)
			{
			case '1':
				int protons, neutrons, electronShell;
				cout << "������� ���������� ��������: ";
				cin >> protons;
				cout << "������� ���������� ���������: ";
				cin >> neutrons;
				cout << "������� ����������� ��������: ";
				cin >> electronShell;
				atom = Atom(protons, neutrons, electronShell);
				_molecule.AddAtom(atom);
				break;
			case '2':				
				_molecule.ShowMoleculeInfo();				
				break;
			case '3':
				cout << "����� ���� �������?" << endl;
				int chosenAtom;
				cin >> chosenAtom;
				_molecule.RemoveAtomAt(chosenAtom);
				break;
			case '4':
				_molecule.FindSameAtoms();
				break;
			case '5':
				_molecule = Molecule();	
				break;
			case '6':
				return;
			default:
				cout << "����� ������� �� ����������!" << endl;
			}

		}
	};	
};