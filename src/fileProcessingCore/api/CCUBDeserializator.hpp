#ifndef CCUBDESERIALIZATOR_HPP
#define CCUBDESERIALIZATOR_HPP

#include"../api/IDeserializator.hpp"
#include <fstream>

class CCUBDeserializator : public IDeserializator
{
public:
   CCUBDeserializator();
   explicit CCUBDeserializator(const std::string& URL);

   virtual ~CCUBDeserializator();

   virtual bool setURL(const std::string& URL) override;
   virtual bool getIsValid() const override;

   virtual void baseCoord(sMainInfo& mainInfo) const;
   virtual void emptyBlocks(sMainInfo& mainInfo) const;
   virtual void mainTranscalancy(sMainInfo& mainInfo) const;
   virtual void anotherTranscalancy(sMainInfo& mainInfo) const;
   virtual void heatCoefficient(sMainInfo& mainInfo) const;
   virtual void holeHeatCoefficient(sMainInfo& mainInfo) const;
   virtual void coordNQ(sMainInfo& mainInfo) const;
   virtual void flatNp(sMainInfo& mainInfo) const;
   virtual void temperature(sMainInfo& mainInfo) const;

private:
   std::ifstream mReader;
   bool isURLValid;
};



#endif // CCUBDESERIALIZATOR_HPP
