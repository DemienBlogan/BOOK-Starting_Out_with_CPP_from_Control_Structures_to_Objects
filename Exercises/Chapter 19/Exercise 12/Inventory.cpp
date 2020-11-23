#include "Inventory.h"

Inventory::Inventory(int serialNum, int lotNum, const std::string& manufactDate)
	: serialNum(0), lotNum(0), manufactDate()
{
	SetSerialNum(serialNum);
	SetLotNum(lotNum);
	SetManufactDate(manufactDate);
}

void Inventory::SetSerialNum(int serialNum)
{
	if (serialNum >= 0)
		this->serialNum = serialNum;
}

void Inventory::SetLotNum(int lotNum)
{
	if (lotNum >= 0)
		this->lotNum = lotNum;
}

void Inventory::SetManufactDate(const std::string& manufactDate)
{
	this->manufactDate = manufactDate;
}