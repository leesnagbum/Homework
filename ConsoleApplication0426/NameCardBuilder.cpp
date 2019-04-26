#include "NameCardBuilder.h"


// 만들어낼 명함에 들어갈 요소들을 설정하는 메서드들 입니다.
void NameCardBuilder::SetName(std::string name) { this->name = name; }
void NameCardBuilder::SetPosition(std::string position) { this->position = position; }

void NameCardBuilder::SetCompanyName(std::string companyName) { this->companyName = companyName; }
void NameCardBuilder::SetCompanyAddress(std::string address) { companyAddress = address; }

void NameCardBuilder::SetTelNumber(std::string tel) { this->tel = tel; }
void NameCardBuilder::SetFaxNumber(std::string fax) { this->fax = fax; }
void NameCardBuilder::SetEmailAddress(std::string email) { this->email = email; }




// 안에서 설정한 값으로 명함을 만들어서 보내줍니다.
NameCard NameCardBuilder::GetNameCard() 
{ 
	return NameCard(name,position,companyName,companyAddress,tel,fax,email); 
}