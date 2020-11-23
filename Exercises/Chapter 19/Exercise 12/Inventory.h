#pragma once
#include <string>

class Inventory
{
private:
	int serialNum;
	int lotNum;
	std::string manufactDate;

public:
	Inventory(int serialNum = 0, int lotNum = 0, const std::string& manufactDate = std::string());

	void SetSerialNum(int serialNum);
	void SetLotNum(int lotNum);
	void SetManufactDate(const std::string& manufactDate);

	int GetSerialNum() const { return serialNum; }
	int GetLotNum() const { return lotNum; }
	std::string GetManufactDate() const { return manufactDate; }
};