#include "../api/CCUBDeserializator.hpp"

CCUBDeserializator::CCUBDeserializator()
   : mReader()
   , isURLValid(false)
{}

CCUBDeserializator::CCUBDeserializator(const std::string& URL)
   : mReader(URL)
   , isURLValid(false)
{
   isURLValid = mReader.is_open();
}

CCUBDeserializator::~CCUBDeserializator()
{
   mReader.close();
}

bool CCUBDeserializator::setURL(const std::string& URL)
{
   mReader.open(URL);
   isURLValid = mReader.is_open();
}

bool CCUBDeserializator::getIsValid() const
{
   return isURLValid;
}

void CCUBDeserializator::baseCoord(sMainInfo& mainInfo) const
{

}

void CCUBDeserializator::emptyBlocks(sMainInfo& mainInfo) const
{

}

void CCUBDeserializator::mainTranscalancy(sMainInfo& mainInfo) const
{

}

void CCUBDeserializator::anotherTranscalancy(sMainInfo& mainInfo) const
{

}

void CCUBDeserializator::heatCoefficient(sMainInfo& mainInfo) const
{

}

void CCUBDeserializator::holeHeatCoefficient(sMainInfo& mainInfo) const
{

}

void CCUBDeserializator::coordNQ(sMainInfo& mainInfo) const
{

}

void CCUBDeserializator::flatNp(sMainInfo& mainInfo) const
{

}

void CCUBDeserializator::temperature(sMainInfo& mainInfo) const
{

}
