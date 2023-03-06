#include <iostream>
#include <algorithm>
class Fraction
{
private:
	int* pa;
	int* pb;
	Fraction& reduce();
public:
	//Констурктор по умолчанию
	Fraction();
	// Конструктор с параметрами
	Fraction(int x, int y);
	// Конструктор копирования
	Fraction(const Fraction& fraction);
	// Деструктор 
	~Fraction();
	// Сумма
	Fraction operator+(Fraction fraction);
	// Произведение
	Fraction operator*(Fraction fraction);
	// Частное
	Fraction operator/(Fraction fraction);
	// Разность  
	Fraction operator-(Fraction fraction);

	// Равенство 
	bool operator==(Fraction fraction);
	// Сравнение
	bool operator<(Fraction fraction);

	// Оператор присваивания 
	Fraction& operator=(Fraction& fraction);

	friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
	friend std::istream& operator>>(std::istream& in, Fraction& fraction);

};
