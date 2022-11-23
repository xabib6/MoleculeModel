#pragma once
#include "Molecule.h"
static class Controller
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
		char input;
		while (true)
		{
			cout << "=====================================" << endl;

			cout << "Список команд: \n1)Добавить атом. \n2)Создать молекулу. \n" <<
				"3)Удалить молекулу. \n4)Выбрать молекулу. \n5)Показать отчёт по месторождению. \n" <<
				"6)Завершить работу. " << endl;

			cout << "=====================================" << endl << endl;

			cin >> input;
			switch (input)
			{
			case '1':
				int protons, neutrons, electronShell;
				Atom atom = Atom(protons, neutrons, electronShell);
				_molecule.AddAtom(atom);
				break;
			case '2':				
				_molecule.ShowMoleculeInfo();				
				break;
			case '3':
				cout << "Какой атом удалить?" << endl;
				cin >> input;
				_molecule.RemoveAtomAt(int(input));
				break;
			case '4':
				_molecule.FindSameAtoms();
				break;
			case '5':
				return;
			case '6':
				_molecule = Molecule();
			default:
				cout << "Такой команды не существует!" << endl;
			}

		}
	};

	
};