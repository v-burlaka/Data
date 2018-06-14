#ifndef IDESERIALIZATOR_HPP
#define IDESERIALIZATOR_HPP

#include <string>

#include "Structs.hpp"

class IDeserializator
{
public:
	IDeserializator() {}
	~IDeserializator() = default;

	virtual sMainInfo execute() = 0;
	virtual void setURL(const std::string& URL) = 0;

private:
	virtual void baseCoord() = 0;
	virtual void emptyBlocks() = 0;
	virtual void mainTranscalancy() = 0;
	virtual void anotherTranscalancy() = 0;
	virtual void heatCoefficient() = 0;
	virtual void holeHeatCoefficient() = 0;
	virtual void coordNQ() = 0;
	virtual void flatNp() = 0;
	virtual void temperature() = 0;
};

#endif // !IDESERIALIZATOR_HPP
