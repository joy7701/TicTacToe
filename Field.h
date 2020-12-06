#ifndef FIELD_H
#define FIELD_H

#include <stdint.h>
#include <array>
#include <string>
#include <iostream>

class Field
{
public:
	Field();
	bool Insert(const char val, const std::uint8_t raw, const std::uint8_t column);
	char GetValue(const std::uint8_t raw, const std::uint8_t column);
	friend std::ostream& operator<<(std::ostream& os, const Field& field);
	
private:
	std::array<std::string, 5> mData;
	bool IsEmpty(const std::uint8_t raw, const std::uint8_t column);
	void ToRealCoordinates(std::uint8_t& raw, std::uint8_t& column);
};

#endif /*FIELD_H*/
