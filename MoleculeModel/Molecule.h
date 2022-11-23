#pragma once
#include "Atom.h"
class Molecule
{
private:
	Atom* atoms;
	int _length;
	int _totalEnergy;
	int _mass;
	/*Молекула вещества.Молекула атомы нуклоны(протон,
		нейтрон), электроны.Между атомами существуют связи
		различных энергий, связь реализуется посредством
		взаимодействия электронных оболочек атомов.Реализовать
		операции : определение суммарной энергии взаимодействия
		атомов, массы молекулы, суммарной массы нуклонов и
		электронов, числа атомов одного типа в молекуле.*/
public:
	void ShowMoleculeInfo();
	void AddAtom(Atom newAtom);
	void RemoveAtomAt(int chosenAtom);
	void FindSameAtoms();
	Molecule();
};