// ConsoleApplication0426.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include "pch.h"
#include <iostream>
#include <string>

#include <conio.h>

#define getch() _getch()


// 명함 클래스 관련
#include "NameCardBuilder.h"
#include "NameCard.h"

// 휴대전화 클래스
#include "HandPhone.h"


using namespace std;

void TestNameCardPrint(NameCard& target)
{
	std::cout << "TestNameCardPrint 호출\n";
	std::cout << "====== [" << target.GetName() << "의 명함] ======\n";
	std::cout << "회사명 : " << target.GetCompanyName() << "\n";
	std::cout << "이  름 : " << target.GetName() << "\n";
	std::cout << "직  급 : " << target.GetPosition() << "\n";
	std::cout << " TEL   : " << target.GetTelNumber() << "\n";
	std::cout << " FAX   : " << target.GetFaxNumber() << "\n";
	std::cout << "Email  : " << target.GetEmail() << "\n";
	std::cout << "회사명 : " << target.GetCompanyAddress() << "\n\n\n";

	std::cout.flush();
}

int main()
{
	// ===========================================================================================================
	// ========================================= 명함 관련 처리 예시 =============================================
	// ===========================================================================================================
	
	// 기존 방식대로라면, 읽기전용 데이터들을 많이 담아둘수록, 기본 생성자를 사용하기 어려워지며
	// 각 읽기 전용인 데이터들의 성격에 따라 생성시에 초기화해주어야 하므로 인수가 강제될 가능성이 매우 높습니다.
	// 또한 생성시에 초기화 해야할 매개변수들이 많을수록 인수는 많아지며 그 순서를 지켜서 생성자에 넣어야할 것입니다.
	// 명함의 예시는 딱 그것과 일치합니다. 현재의 명함은 아래의 방식대로 초기화 해야할 것입니다:
	NameCard notUsedBuilderCard("김아무개", "취준생", "", "", "010-1234-5678", "", "hellkorea@hanmail.net");


	// 하지만 빌더와 함께라면 이 부담감을 줄여줄 수 있습니다. 아래의 예시에서 확인하여주십시오.
	// 빌더 클래스를 따로 만들어주어야 하는 귀찮음이 발생할 수 있고,
	// 메모리적으로도 불이익이 있을 수 있지만 개발시에 편의를 제공하는 것 자체는 사실입니다.
	// 필요에 따라 적절히 사용하여 주십시오.
	NameCardBuilder builder;

	// 빌더 클래스는 위의 생성자 방식과 다르게 인수의 순서를 강제하지 않습니다.
	builder.SetCompanyAddress("강남 어딘가의 지점");
	builder.SetCompanyName("넥슨");
	builder.SetEmailAddress("chosenone@gmail.com");
	builder.SetTelNumber("010-9987-2235");
	builder.SetFaxNumber("02-1234-5678");
	builder.SetName("김성공");
	builder.SetPosition("대리");


	// 빌더로 생성시에는 빌더의 반환 함수를 이용하면 됩니다: 현재의 반환함수는 GetNameCard().
	NameCard fromBuilder = builder.GetNameCard();

	cout << "명함 클래스 테스트 존" << endl;

	// 빌더로 생성한 것과 생성자로 생성된 녀석에 대해 
	// Getter를 이용해 데이터를 뽑아올수 있는가를 테스트하는 영역입니다.
	// TestNameCardPrint(NameCard&) 에서는 NameCard 내의 Print()와 비슷한 동작이지만,
	// Getter를 이용해 데이터를 뽑아올수 있는가를 보여줍니다.
	cout << "===============================================" << endl;
	cout << "TestNameCardPrint를 이용해 테스트를 진행합니다." << endl;
	TestNameCardPrint(notUsedBuilderCard);
	TestNameCardPrint(fromBuilder);


	cout << "\n\n\n===============================================" << endl;
	cout << "스스로 가지고 있는 Print()를 이용해 테스트를 진행합니다." << endl;
	notUsedBuilderCard.Print();
	fromBuilder.Print();




	cout << "==================================================" << endl;
	cout << "==================================================" << endl;
	cout << "엔터를 누르시면 핸드폰 클래스 테스트를 진행합니다." << endl;
	cout << "==================================================" << endl;
	cout << "==================================================" << endl;


	getchar();



	// ===========================================================================================================
	// ======================================= 핸드폰 클래스 테스트존 ============================================
	// ===========================================================================================================


	//										해당 코드는 자동 처리로 제공해드리지 않습니다.
	//										대신 직접 테스트 할 수 있는 코드를 마련했습니다.
	//										(죄송합니다. 이건 너무 귀찮아서..)


	HandPhone hp("SG-501", "짭성", "BLACK", true, 50, 800);
	std::string targetName;
	HandPhone::SimpleSoftware soft;

	while (true)
	{
		system("cls");
		hp.PrintStatus();

		// 인터페이스
		cout << "\n\n\n===================================" << endl;
		cout << "p : Power" << endl;
		cout << "q : Volume Up" << endl;
		cout << "w : Volume Down" << endl;

		cout << "z : Install New Software" << endl;
		cout << "x : Delete Software" << endl;

		cout << "c : Software Execution" << endl;

		cout << "v : Software Terminate" << endl;
		cout << "b : Software All Terminate" << endl;

		cout << "\n` : EXIT" << endl;



		switch (getch())
		{
		case 'p': hp.TogglePower(); break;

		case 'q': hp.VolumeUp(); break;
		case 'w': hp.VolumeDown(); break;

		case 'z': 
			cout << "설치하실 소프트웨어의 이름과 용량, 사용시 메모리 점유량을 공백으로 구분하여 입력하여주십시오. : ";
			cin >> soft.name;
			cin >> soft.softwareSize >> soft.ramUsage;

			hp.InstallSoftware(soft);
			break;
		case 'x': 
			cout << "삭제하실 소프트웨어의 이름? : ";
			cin >> targetName;
			hp.DeleteSoftware(targetName);
			break;
		case 'c': 
			cout << "실행하실 소프트웨어의 이름? : ";
			cin >> targetName;
			hp.SoftwareExecution(targetName);
			break;
		case 'v': 
			cout << "중단하실 소프트웨어의 이름? : ";
			cin >> targetName;
			hp.SoftwareTerminate(targetName);
			break;
		case 'b': hp.SoftwareTerminate(); break;
		case '`': return 0;
		default: break;
		}

	}




	getchar(); // 처리된 내용을 확인하기 위해 더미키 입력 요구를 두어 일시정지 하는 용도입니다.
	return 0; // 보통 main에서 정상종료시에는 0을 반환해주는 것이 관례입니다.
}