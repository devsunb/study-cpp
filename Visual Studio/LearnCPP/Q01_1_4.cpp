#include <iostream>

int main() {
	int salePrice = 0;
	int salary = 0;

	while (true) {
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		std::cin >> salePrice;

		if (salePrice == -1)
			break;

		salary = (salePrice*0.12) + 50;
		std::cout << "이번 달 급여: " << salary << std::endl;
	}
	std::cout << "프로그램을 종료합니다." << std::endl;
	return 0;
}