#pragma once
#include "Cell.h"
class Tree
{
	Cell* cell;
public:
	Cell* getCell()
	{
		return cell;
	}
	Tree()
	{
		cell = new Cell("Я", 1, nullptr);
		cell->setRight(new Cell("мама", 2, cell));
		cell->setLeft(new Cell("папа", 3, cell));

		cell->getRight()->setRight(new Cell("бабушка по маминой линии", 4, cell->getRight()));
		cell->getRight()->setLeft(new Cell("дедушка по маминой линии", 5, cell->getRight()));

		cell->getLeft()->setRight(new Cell("бабушка по папиной линии", 6, cell->getLeft()));
		cell->getLeft()->setLeft(new Cell("дедушка по папиной линии", 7, cell->getLeft()));

		cell->getRight()->getRight()->setRight(new Cell("прадедушка", 9, cell->getRight()->getRight()));
		cell->getRight()->getRight()->setLeft(new Cell("прабабушка", 8, cell->getRight()->getRight()));

		cell->getRight()->getLeft()->setRight(new Cell("прадедушка", 9, cell->getRight()->getLeft()));
		cell->getRight()->getLeft()->setLeft(new Cell("прабабушка", 8, cell->getRight()->getLeft()));

		cell->getLeft()->getRight()->setRight(new Cell("прадедушка", 9, cell->getLeft()->getRight()));
		cell->getLeft()->getRight()->setLeft(new Cell("прабабушка", 8, cell->getLeft()->getRight()));

		cell->getLeft()->getLeft()->setRight(new Cell("прадедушка", 9, cell->getLeft()->getLeft()));
		cell->getLeft()->getLeft()->setLeft(new Cell("прабабушка", 8, cell->getLeft()->getLeft()));
	}

	void DeepSearch(Cell* cell,int number)
	{
		//std::cout << cell->getNum() << " ";
		if (number==cell->getNum()&& cell->getWasHere()==false)
		{
			std::cout <<cell->getInfo() << std::endl;
		}
		cell->setWasHere(true);
		if (cell->getLeft()!=nullptr && cell->getLeft()->getWasHere()==false)
		{
			DeepSearch(cell->getLeft(), number);
		}
		else if (cell->getRight() != nullptr && cell->getRight()->getWasHere() == false)
		{
			DeepSearch(cell->getRight(), number);
		}
		else if(cell->getParent() != nullptr)
		{
			DeepSearch(cell->getParent(), number);
		}
	}
};

