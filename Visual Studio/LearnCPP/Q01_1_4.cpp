#include <iostream>

int main() {
	int salePrice = 0;
	int salary = 0;

	while (true) {
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		std::cin >> salePrice;

		if (salePrice == -1)
			break;

		salary = (salePrice*0.12) + 50;
		std::cout << "�̹� �� �޿�: " << salary << std::endl;
	}
	std::cout << "���α׷��� �����մϴ�." << std::endl;
	return 0;
}