#ifndef ISERIALIZATOR_HPP
#define ISERIALIZATOR_HPP

#include <string>

#include "../api/Structs.hpp"

class ISerializator
{
public:
	ISerializator();
	virtual ~ISerializator() = default;

	virtual void setURL(const std::string& URL) = 0;
	virtual void execute(const sMainInfo& info) const = 0;

private:
	virtual void baseCoord(const sBaseCoord& info) const = 0;
	virtual void emptyBlocks(const std::vector<sBlockCoord> info) const = 0;
	virtual void mainTranscalancy(const double& transcalancy) const = 0;
	virtual void anotherTranscalancy(const std::vector<sBlockCoord>& info, const std::vector<double>& transcalancy) const = 0;
	virtual void heatCoefficient(const std::vector<double>& coefficients) const = 0;
	virtual void holeHeatCoefficient(const std::vector<double>& coefficients) const = 0;
	virtual void coordNQ(const std::vector<sBlockCoord>& info, const std::vector<double>& NQ) const = 0;
	virtual void flatNp(const int count) const = 0;
	virtual void temperature(const double& temp) const = 0;
};

#endif // !ISERIALIZATOR_HPP
