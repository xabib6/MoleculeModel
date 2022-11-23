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

			cout << "Список команд: \n1)Добавить атом. \n2)Показать информацию о молекуле. \n" <<
				"3)Удалить атом. \n4)Показать одинаковые атомы.  \n5)Удалить все атомы. \n" <<
				"6)Завершить работу. " << endl;

			cout << "=====================================" << endl << endl;

			cin >> input;
			switch (input)
			{
			case '1':
				int protons, neutrons, electronShell;
				cout << "Введите количество протонов: ";
				cin >> protons;
				cout << "Введите количество нейтронов: ";
				cin >> neutrons;
				cout << "Введите электронную оболочку: ";
				cin >> electronShell;
				atom = Atom(protons, neutrons, electronShell);
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
				_molecule = Molecule();				
			case '6':
				return;
			default:
				cout << "Такой команды не существует!" << endl;
			}

		}
	};

	
};