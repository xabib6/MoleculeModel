#pragma once
#include "Molecule.h"
class Controller
{
private:
	Molecule _molecule;
public:
	Controller()
	{
		_molecule = Molecule();
	}
	void Manager()
	{
		Atom atom = Atom(0, 0, 0);
		char input;
		while (true)
		{
			cout << "=====================================" << endl;

			cout << "������ ������: \n1)�������� ����. \n2)�������� ���������� � ��������. \n" <<
				"3)������� ����. \n4)�������� ���������� �����.  \n5)������� ��� �����. \n" <<
				"6)��������� ������. " << endl;

			cout << "=====================================" << endl << endl;

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
				cin >> input;
				_molecule.RemoveAtomAt(int(input));
				break;
			case '4':
				_molecule.FindSameAtoms();
				break;
			case '5':
				_molecule = Molecule();				
			case '6':
				return;
			default:
				cout << "����� ������� �� ����������!" << endl;
			}

		}
	};

	
};