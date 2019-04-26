#include "NameCardBuilder.h"


// ���� ���Կ� �� ��ҵ��� �����ϴ� �޼���� �Դϴ�.
void NameCardBuilder::SetName(std::string name) { this->name = name; }
void NameCardBuilder::SetPosition(std::string position) { this->position = position; }

void NameCardBuilder::SetCompanyName(std::string companyName) { this->companyName = companyName; }
void NameCardBuilder::SetCompanyAddress(std::string address) { companyAddress = address; }

void NameCardBuilder::SetTelNumber(std::string tel) { this->tel = tel; }
void NameCardBuilder::SetFaxNumber(std::string fax) { this->fax = fax; }
void NameCardBuilder::SetEmailAddress(std::string email) { this->email = email; }




// �ȿ��� ������ ������ ������ ���� �����ݴϴ�.
NameCard NameCardBuilder::GetNameCard() 
{ 
	return NameCard(name,position,companyName,companyAddress,tel,fax,email); 
}