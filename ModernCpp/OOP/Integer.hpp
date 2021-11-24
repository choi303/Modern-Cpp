#pragma once

class Integer {
	int* m_pInt;
public:
	//Default constructor
	Integer();

	//Parameterized constructor
	Integer(int value);

	//Copy constructor
	Integer(const Integer& obj);

	//Move constructor
	Integer(Integer&& obj);
	
	//Copy assignment
	Integer& operator=(const Integer& obj);

	//Move assignment
	Integer& operator=(Integer&& obj);

	//Sum operator
	//Integer operator+(Integer obj) const;
	Integer& operator++();
	Integer operator++(int);
	bool operator ==(const Integer& obj) const;
	bool operator !=(const Integer& obj) const;

	void operator()();
	explicit operator int();

	int GetValue() const;
	void SetValue(int value);
	~Integer();
private:
	friend class Printer;
};

class Printer {

};