#ifndef CCUBDESERIALIZATOR_HPP
#define CCUBDESERIALIZATOR_HPP

#include "IDeserializator.hpp"
#include "Helper.hpp"

class CCUBDeserializator : public IDeserializator
{
public:
	CCUBDeserializator();
	~CCUBDeserializator();

	virtual sMainInfo execute() override;
   virtual void setURL(const std::string& URL) override;

private:
	virtual void baseCoord() override;
	virtual void emptyBlocks() override;
	virtual void mainTranscalancy() override;
	virtual void anotherTranscalancy() override;
	virtual void heatCoefficient() override;
	virtual void holeHeatCoefficient() override;
	virtual void coordNQ() override;
	virtual void flatNp() override;
	virtual void temperature() override;

	void writeBuffer();
	double writeNumber(int& index) const;
	void toNextString(int& index);
	void toNextDigit(int& index);
	void fillEmptyBlocks(std::vector<sBlockCoord>& vector, int& index);
   void fillEmptyBoxes(std::vector<sBoxInfo> &vector, int& index);
	void debug();
	
	std::string mURL;
	std::string mBuffer;
	sMainInfo mMainInfo;
};

#endif // !CCUBDESERIALIZATOR_HPP
