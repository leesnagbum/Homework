#pragma once

#include "pch.h"

#include <string>
#include <vector>


// BSGJ: 이 간단한 수정본에서는
//
// 현실세계의 명함에 맞게 만들고 수정이 안되게,
// 그리고 명함을 제조할 수 있는 장치(빌더)를 만들고,
// 멤버변수를 몇가지 수정하려 합니다.



class NameCard
{
public:
	// 기본 생성자는 사용하지 않으며, 동적 할당이 일어나지 않기에 소멸자는 기본으로 사용할 수 있습니다.
	NameCard() = delete;
	~NameCard() = default;

	// 생성시에는 모든 멤버 변수가 결정되어야 합니다.
	// 그러나 모든 멤버의 순서를 지켜야 하는 것은 사용자에게 고통일 수 있습니다. 이를 빌더가 보완합니다.
	NameCard(std::string name, std::string position, std::string companyName, std::string companyAddress,
		std::string tel, std::string fax, std::string email);

	// 들어있는 정보들을 보기 쉽게 std::cout 객체를 이용해 종합적으로 출력합니다.
	void Print() const;

	

	// Getter들입니다. 변수 대신 이것을 노출시키고, 
	// Setter를 제공하지 않는 것으로
	// 각 변수들을 읽기전용처럼 사용할 수 있습니다.
	std::string GetName() const;
	std::string GetPosition() const;

	std::string GetCompanyName() const;
	std::string GetCompanyAddress() const;

	std::string GetTelNumber() const;
	std::string GetFaxNumber() const;
	std::string GetEmail() const;




private:
	// 이 명함은 이름, 전화번호, 이메일, 팩스번호, 주소, 회사명, 직급을 담으려고 합니다.
	std::string name;
	std::string position;

	std::string companyName;
	std::string companyAddress;
	
	std::string tel;
	std::string fax;
	std::string email;
};
