#include "CSerializer.hpp"
#include <iostream>

CSerializator::CSerializator() 
	: mSerializator  (std::make_unique<CCUBSerializator>())
	, mDeserializator(std::make_unique<CCUBDeserializator>())
{
}

CSerializator::~CSerializator()
{
	mSerializator.reset();
	mDeserializator.reset();
}

void CSerializator::serialize(const sMainInfo & info, const std::string & URL) const
{
	mSerializator->setURL(URL);
	mSerializator->execute(info);
}

sMainInfo CSerializator::deserialize(const std::string URL) const
{
	mDeserializator->setURL(URL);
	return mDeserializator->execute();
}
