#ifndef CCUBSERIALIZATOR_HPP
#define CCUBSERIALIZATOR_HPP

#include "ISerializator.hpp"

class CCUBSerializator : public ISerializator
{
public:
	CCUBSerializator();
	~CCUBSerializator();

	virtual void setURL(const std::string& URL) override;
	virtual void execute(const sMainInfo& info) const override;
private:
	virtual void baseCoord(const sBaseCoord& info) const override;
	virtual void emptyBlocks(const std::vector<sBlockCoord> info) const override;
	virtual void mainTranscalancy(const double& transcalancy) const override;
	virtual void anotherTranscalancy(const std::vector<sBoxInfo>& info) const override;
	virtual void heatCoefficient(const std::vector<double>& coefficients) const override;
	virtual void holeHeatCoefficient(const std::vector<double>& coefficients) const override;
	virtual void coordNQ(const std::vector<sBoxInfo>& info) const override;
	virtual void flatNp(const int count) const override;
	virtual void temperature(const double& temp) const override;

private:
	std::string mURL;
};

#endif // !CCUBSERIALIZATOR_HPP
