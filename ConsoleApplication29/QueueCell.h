#include "Cell.h"
#pragma once
class QueueCell
{
	Cell* cell;
	QueueCell* address;
public:
	QueueCell(Cell* cell, QueueCell* address)
	{
		this->address = address;
		this->cell = cell;
	}
	QueueCell* GetAddress()
	{
		return address;
	}

	void SetAddress(QueueCell* address)
	{
		this->address = address;
	}

	Cell* GetCell()
	{
		return cell;
	}
	void SetAddress(Cell* cell)
	{
		this->cell = cell;
	}

};

