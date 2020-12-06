#include "Field.h"

Field::Field()
{
	mData[0] = "   |   |   ";
	mData[1] = "---+---+---";
	mData[2] = "   |   |   ";
	mData[3] = "---+---+---";
	mData[4] = "   |   |   ";
}

bool Field::Insert(const char val, const std::uint8_t raw, const std::uint8_t column)
{
	std::uint8_t realRaw = raw;
	std::uint8_t realColumn = column;
	ToRealCoordinates(realRaw, realColumn);

	if (IsEmpty(realRaw, realColumn))
	{
		mData.at(realRaw).at(realColumn) = val;
		return true;
	}
	return false;
}

char Field::GetValue(const std::uint8_t raw, const std::uint8_t column)
{
	std::uint8_t realRaw = raw;
	std::uint8_t realColumn = column;
	ToRealCoordinates(realRaw, realColumn);
	return mData.at(realRaw).at(realColumn);
}

bool Field::IsEmpty(const std::uint8_t raw, const std::uint8_t column)
{
	if (mData.at(raw).at(column) == ' ')
		return true;
	else
	return false;
}

void Field::ToRealCoordinates(std::uint8_t& raw, std::uint8_t& column)
{
	/*
	*	0 -> 0
	*   1 -> 2
	*   2 -> 4
	*/
	raw <<= 1;
	//column
	/*
		0 -> 4*0 + 1
		1 -> 4*1 + 1
		2 -> 4*2 + 1
	*/
	column = (column << 2) + 1;
}

std::ostream& operator<<(std::ostream& os, const Field& field)
{
	for (auto& it : field.mData)
		std::cout << it << std::endl;
	return os;
}
