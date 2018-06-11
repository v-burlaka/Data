#ifndef IDESERIALIZATOR_HPP
#define IDESERIALIZATOR_HPP

#include <string>

struct sMainInfo;

class IDeserializator
{
public:
   IDeserializator() {}
   virtual ~IDeserializator() = 0;

   virtual bool setURL(const std::string& URL) = 0;
   virtual bool getIsValid() const = 0;

private:
   virtual void baseCoord(sMainInfo& mainInfo) const = 0;
   virtual void emptyBlocks(sMainInfo& mainInfo) const = 0;
   virtual void mainTranscalancy(sMainInfo& mainInfo) const = 0;
   virtual void anotherTranscalancy(sMainInfo& mainInfo) const = 0;
   virtual void heatCoefficient(sMainInfo& mainInfo) const = 0;
   virtual void holeHeatCoefficient(sMainInfo& mainInfo) const = 0;
   virtual void coordNQ(sMainInfo& mainInfo) const = 0;
   virtual void flatNp(sMainInfo& mainInfo) const = 0;
   virtual void temperature(sMainInfo& mainInfo) const = 0;
};
#endif // IDESERIALIZATOR_HPP

IDeserializator::~IDeserializator()
{

}
