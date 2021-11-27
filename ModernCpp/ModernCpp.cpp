// Learning file for Modern/Generic C++ 11/14/17

// Copyright(c) 2021 Choi

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this softwareand associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :

// The above copyright noticeand this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#include <iostream>
#include <string>
using namespace std;
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING 1;

// BASIC LANGUAGE FACILITIES

/*

//_____UNIFORM INITIALIZATION_____


int main()
{
	int a1; //Uninitialized

	int a2 = 0; //Copy initialize

	int a3(5); //Direct initialization

	string s1; //Uninitialized string

	string s2("Modern-Cpp"); //Direct initialization of string

	char d1[8]; //Uninitalized
	char d2[8] = { '\0' }; //Copy initialize
	char d3[8] = { 'a', 'b', 'c', 'd' }; //Aggregate initialization
	char d4[8] = { "abcd" };

	int b1{}; //Value initialization
	int b2(); //Most vexing parse
	int b3{ 5 }; //Direct initialization

	int b4 = 0; //Copy initialization

	char e1[8]{}; //Value initialization
	char e2[8]{ "Hello" }; //Direct initialization

	int* p1 = new int{}; //Value initialization in memory heap
	char* p2 = new char[8]{}; //Value initialization in memory heap

	return 0;
}

/*

1. Value initialization => T obj{};
2. Direction initialization => T obj{v};
3. Copy initialization => T obj = v;

*/

/*

1. It forces initialization
2. You can use direct initialization for array types
3. It prevents narrowing conversions
4. Uniform syntax for all types

*/

/*
//_____POINTERS_____

int Add(int* a, int* b);

int main()
{
	int* a = new int(1);
	int* b = new int(2);
	cout << Add(a, b);
	return 0;
}


int Add(int* a, int* b)
{
	int* sum = new int(*a + *b);
	int& result = *sum;
	return result;
}

*/

/*

//_____REFERENCE_____




void Add(int a, int b, int& result);

int main()
{
	//Referent
	int x = 10; //x = 10
	//Reference
	int& ref = x;

	int y = 20; //x = 20
	ref = y;
	cout << "x: " << x
		<< endl;
	cout << "ref: " << ref
		<< endl;

	int& result = x;
	Add(x, x, result); //x = 40
	cout << "new result: "
		<< result;

	return 0;
}

void Add(int a, int b, int& result)
{
	int sum = a + b;
	result = sum;
}

*/

/*
//_____REFERENCES VS POINTERS_____


void Swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void Swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void Print(int* ptr) {
	if (ptr == nullptr)
		return;

	cout << *ptr << endl;
}


int main()
{
	int a = 5, b = 10;
	Swap(a, b);
	cout << "a: " << a
		<< endl;
	cout << "b: " << b
		<< endl;

	int x = 5;
	Print(nullptr);

	return 0;
}

*/

/*
_____CONST QUALIFER_____

/*
// IN POINTER
void Print(int* ptr) {
	if(ptr !=  nullptr)
	cout << *ptr << endl;
	*ptr = 700;
}

int main() {
	const int CHUNK_SIZE = 512;
	const int* const ptr = &CHUNK_SIZE;
	//*ptr = 1;
	int x = 10;
	//ptr = &x;
	//*ptr = 1;
	Print(&x);
	cout << "main->x" << x
		<< endl;
	return 0;
}

// IN REFERENCES

void Print(const int& ref) {
	cout << ref <<
		endl;
}

int main() {
	const int x = 5;
	//Print(x);
	Print(1);
	return 0;
}

*/

/*
_____PRACTICING ON CONST QUALIFER_____

int main() {
	//Try to modify x1 & x2 and see the compilation output
	int x = 5;
	const int MAX = 12;
	int& ref_x1 = x;
	const int& ref_x2 = x;
	ref_x1 = 4;
	//ref_x2 = 5; ERROR: Expression must be a modifiable lvalue

	//Try to modify the pointer(e.g.ptr1) and the pointee value(e.g. * ptr1)
	const int* ptr1 = &x;
	int* const ptr2 = &x;
	const int* const ptr3 = &x;
	//*ptr1 = &x; ERROR: Expression must be a modifiable lvalue
	ptr1 = &MAX;
	*ptr2 = 4;
	//ptr2 = &MAX; ERROR: Expression must be a modifiable lvalue
	
	//Find which declarations are valid. If invalid, correct the declaritons
	const int* ptr3 = &MAX;
	//int* ptr4 = &MAX; ERROR: Values are not match
	const int* ptr4 = &MAX;

	return 0;
}

*/

/*

____AUTO SPECIFIER____

int Sum(int x, int y) {
	return x + y;
}

int main() {
	//Always need an initializer
	auto i = 10;
	auto j = 5;
	auto sum = i + j;
	auto sum2 = i + 4.3f;

	auto result = Sum(i, j);
	static auto y = 2;
	const int x = 10;
	const auto var = x;
	auto& var1 = x;
	auto* ptr = &x;
	auto list = { 1,2,3,4 };

	return 0;
}

*/

/*

_____RANGE BASED FOR LOOP_____

int main() {
	int arr[] = {1,2,3,4,5};
	/*for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	for (const auto& x : arr) {
		cout << x << " ";
	}
	cout << "\n";
	for (auto x : { 1,2,3,4 }) {
		cout << x << " ";
	}

	/*const int* beg = begin(arr);
	const int* end = end(arr);

	auto&& range = arr;
	auto begin = begin(range);
	auto end = end(range);

	for (; begin != end; ++begin) {
		auto v = *begin;
	}

	//while (beg != end) {
	//	cout << *beg << ' ';
	//	++beg;
	//}

	return 0;
}
*/

/*

_____INLINE FUNCTIONS_____

inline int Square(int x) {
	return x * x;
}
//#define Square(x) x*x

int main() {
	int val = 5;
	int result = Square(val + 1);
	cout << result << endl;
	return 0;
}
*/

/*
_____FUNCTION POINTER_____

void Print(int count, char ch) {
	for (int i = 0; i < count; ++i) {
		cout << ch;
	}
	cout << endl;
}

void EndMessage() {
	cout << "End of program." << endl;
}

int main() {
	atexit(EndMessage);
	Print(5, '#');
	void(*pfn) (int, char) = &Print;
	//(*pfn)(8, '@');
	pfn(5, '+');
	pfn(7, '+');

	return 0;
}
*/

/*
_____NAMESAPCE_____

namespace Avg {
	float Calculate(float x, float y) {
		return (x + y) / 2;
	}
}

namespace Basic {
	float Calculate(float x, float y) {
		return x + y;
	}
}

int main() {
	using Avg::Calculate;
	Calculate(3.9f, 8.2f);
	
	Basic::Calculate(2.0f, 2.0f);

	return 0;
}
*/

// BASIC LANGUAGE FACILITIES END


//DYNAMIC MEMORY ALLOCATION

/*
_____DYNAMIC MEMORY ALLOCATION_____


extern "C"
{
	#include <stdio.h>
	#include <stdlib.h>
}

template<typename T>
void deletePtr(T* ptr)
{
	delete ptr;
	ptr = nullptr;
}

template<typename T>
void freePtr(T* ptr)
{
	free(ptr);
	ptr = nullptr;
}

template<typename T>
void freePtrArray(T* ptr)
{
	delete[] ptr;
	ptr = nullptr;
}

//Dynamic memory allocation in C
void Malloc() {
	int* p = reinterpret_cast<int*>(calloc(1, sizeof(int)));
	if (p == NULL) {
		printf("Failed to allocate memory\n");
		return;
	}
	*p = 5;
	printf("%d", *p);
	freePtr(p);
}

//Dynamic memory allocation in C++
void New() {
	int* p = new int(5);
	*p = 6;
	std::cout << *p << std::endl;
	deletePtr(p);
}

void NewArrays() {
	int* p = new int[5];
	for (int i = 0; i < 5; ++i) {
		p[i] = i;
	}
	freePtrArray(p);
}

int main() {
	
	New();

	return 0;
}
*/

// DYNAMIC MEMORY ALLOCATION END


// OBJECT ORIENTED PROGRAMMING BASICS



//_____CONTRUSTOR & DESTRUCTOR & OOP BASICS_____

/*
#include "OOP/Car.hpp"
#include "OOP/Integer.hpp"

int main() {
	Car car(5);
	car.FillFuel(6);
	car.Accelerate();
	car.Accelerate();
	car.Accelerate();
	car.Accelerate();
	car.Dashboard();

	Car c1, c2;
	car.Dashboard();
	car.ShowCount();

	Integer i = 5;
	cout << i.GetValue() << std::endl;

	return 0;
}
*/

/*
_____STRUCTURE VS CLASS_____

struct Point {
	int x;
	int y;
};

void DrawLine(int x1, int y1, int x2, int y2) {

}

void DrawLine(Point start, Point end) {
	std::cout << start.x << std::endl;
}

int main() {
	return 0;
}
*/

// OBJECT ORIENTED PROGRAMMING BASICS END


// MOVE SEMANTICS


/*
_____L-VALUES, R-VALUES, R-VALUE REFERENCES_____


int Add(int x, int y) {
	return x + y;
}

int& Transform(int& x) {
	x *= x;
	return x;
}

int main() {
	//x,y & z are l-values & 5, 10, & 8 are r-values
	int x = 5;
	int y = 10;
	int z = 8;

	//Expression returns r-value
	int result = (x + y) * z;

	//Expression returns l-value
	++x = 6;

	return 0;
}
*/

/*
_____MOVE & COPY CONTRUCTORS_____

#include "OOP/Integer.hpp"

Integer Add(const Integer& a,
	const Integer& b)
{
	Integer temp;
	temp.SetValue(a.GetValue() + b.GetValue());
	return temp;
}

int main() {
	Integer a(1), b(3);
	a.SetValue(Add(a, b).GetValue());

	return 0;
}
*/

/*
_____RULE OF 5 & 0_____

#include "OOP/Integer.hpp"

class Number {
	Integer m_Value{};
public:
	Number(int value) :m_Value{ value } {

	}
	Number(const Number&) = default;
	Number& operator=(const Number& obj) = default;
	Number(Number && n) :m_Value{std::move(n.m_Value)} {
	}
	Number& operator=(Number&&) = default;
	~Number() = default;
};

Number CreateNumber(int num) {
	Number n{ num };
	return n;
}

int main() {
	Number n1{ 1 };
	auto n2{ n1 };
	n2 = n1;

	auto n3{ CreateNumber(3) };
	n3 = CreateNumber(3);
}
*/

/*
_____COPY ELISION_____

#include "OOP/Integer.hpp"

Integer Add(int a, int b) {
	return Integer(a + b);
}

int main() {
	Integer a = 3; //Integer a = Integer(3)
	return 0;
}
*/

/*
_____STD::MOVE FUNCTION_____

#include "OOP/Integer.hpp"

void Print(Integer val) {

}

int main() {
	Integer a(1);
	//auto b{ std::move(a) };
	Print(std::move(a));
	a.SetValue(5);
	std::cout << a.GetValue() << std::endl;

	return 0;
}
*/

// MOVE SEMANTICS END

// OPERATOR OVERLOADING

/*
_____OPERATOR OVERLOADING BASICS_____

#include "OOP/Integer.hpp"

Integer operator+(const Integer& a, const Integer& b) {
	Integer temp;
	temp.SetValue(a.GetValue() + b.GetValue());
	return temp;
}

int main() {
	Integer a(1), b(3);
	//Sum operator
	Integer sum = a + b;
	if(a == b)
	sum++;
	std::cout << sum.GetValue() << std::endl;

	//Copy assigment
	Integer c;
	c = a;
	std::cout << c.GetValue() << std::endl;

	Integer sum2 = a + 5;
	std::cout << sum2 << std::endl;

	cin >> a;
	std::cout << "A is: " << a << std::endl;
}
*/

/*
_____OPERATOR OVERLOADING SMART POINTER BASICS_____

#include "OOP/Integer.hpp"
#include <memory>

class IntPtr {
	Integer* m_p;
public:
	IntPtr(Integer* p) : m_p(p) {

	}
	~IntPtr() {
		delete m_p;
	}
	Integer* operator->() {
		return m_p;
	}
	Integer& operator*() {
		return *m_p;
	}
};

void Process(std::shared_ptr<Integer> ptr) {
	std::cout << ptr->GetValue() << std::endl;
}

void CreateInteger() {
	std::shared_ptr<Integer> p(new Integer);
	p->SetValue(3);

	Process(p);
	std::cout << p->GetValue() << std::endl;
}

int main() {
	CreateInteger();
	return 0;
}
*/

/*
_____TYPE CONVERSIONS_____

#include "OOP/Integer.hpp"

void Print(const Integer& a) {
	
}

class Product {
	Integer m_Id;
public:
	Product(const Integer& id): m_Id(id) {
		std::cout << "Product(const Integer&)" << std::endl;
		//m_Id = id;
	}
	~Product() {
		std::cout << "~Product()" << std::endl;
	}
};

int main() {
	int a = 5, b = 2;
	float f = static_cast<float>(a) / b;
	char* p = reinterpret_cast<char*>(&a);
	const int x = 1;
	int* p1 = const_cast<int*>(&x);
	std::cout << f << std::endl;
	
	Integer a1{ 5 };
	//Initialization
	Integer a2 = 5;
	Print(5);
	//Assignment
	a1 = 7;
	int x1 = static_cast<int>(a1);

	Integer c;
	//Assignment
	c = 6;

	std::cout << c.GetValue() << std::endl;

	Product p(5);

	return 0;
}
*/

// OPERATOR OVERLOADING


// MEMORY MANAGEMENT PART II

/*
_____RAW    POINTER_____
_____UNIQUE POINTER_____
_____SHARED POINTER_____

#include "OOP/Integer.hpp"
#include <memory>

class Project {
	std::string m_Name;
public:
	void SetName(const std::string& name) {
		m_Name = name;
	}

	void ShowProjectDetails() const {
		std::cout << "[Project Name]" << m_Name
			<< m_Name << std::endl;
	}
};

class Employee {
	std::shared_ptr<Project> m_pProject{};
public:
	void SetProject(std::shared_ptr<Project>& prj) {
		m_pProject = std::move(prj);
	}
	const std::shared_ptr<Project>& GetProject() const {
		return m_pProject;
	}
};

void ShowInfo(const std::shared_ptr<Employee>& emp) {
	std::cout << "Employee project details:";
	emp->GetProject()->ShowProjectDetails();
}

void Display(Integer* p) {
	if (!p) {
		return;
	}
	std::cout << p->GetValue() << std::endl;
}

Integer* GetPointer(int value) {
	Integer* p = new Integer{value};
	return p;
}

void Store(std::unique_ptr<Integer>& p) {
	std::cout << "Storing data into a file:" << p->GetValue() << std::endl;
}

void Operate(int value) {
	std::unique_ptr<Integer> p{ GetPointer(value) };
	if (p == nullptr) {
		p.reset(new Integer{ value });
	}
	p->SetValue(100);
	Display(p.get());
	//delete p.get();
	//p = nullptr;
	p.reset(new Integer{});
	*p = __LINE__;
	Display(p.get());
	Store(p);
	*p = 200;
}

int main() {
	Operate(5);

	std::shared_ptr<Project> prj{ new Project{} };
	prj->SetName("Video Decoder");
	std::shared_ptr<Employee> e1{ new Employee{} };
	e1->SetProject(prj);
	std::shared_ptr<Employee> e2{ new Employee{} };
	e2->SetProject(prj);
	std::shared_ptr<Employee> e3{ new Employee{} };
	e3->SetProject(std::move(prj));

	e3.reset(new Employee{});
	if (e3) {
		//VALID
	}
	else
	{
		//NOT VALID
	}

	ShowInfo(e1);
	ShowInfo(e2);
	prj->ShowProjectDetails();

}
*/

/*
_____WEAK OWNERSHIP_____
_____WEAK   POINTER_____

class Printer {
	std::weak_ptr<int> m_pValue{};
public:
	void SetValue(std::weak_ptr<int> p) {
		m_pValue = p;
	}
	void Print() {
		if (m_pValue.expired())
		{
			std::cout << "Resource is no longer available"
				<< std::endl;
			return;
		}
		auto sp = m_pValue.lock();
		std::cout << "Value is:" << *sp
			<< std::endl;
		std::cout << "Ref count:" << sp.use_count()
			<< std::endl;
	}
};

int main() {
	Printer prn;
	int num{};
	std::cin >> num;
	std::shared_ptr<int> p{ new int{ num } };
	prn.SetValue(p);
	if (*p > 10) {
		p = nullptr;
	}
	prn.Print();
	return 0;
}

*/

/*
_____CIRCULAR REFERENCES_____

class Employee;

class Project {
public:
	std::shared_ptr<Employee> m_emp;
	Project() {
		std::cout << "Project()" << std::endl;
	}
	~Project() {
		std::cout << "~Project()" << std::endl;
	}
};
class Employee {
public:
	std::weak_ptr<Project> m_prj;
	Employee() {
		std::cout << "Employee()" << std::endl;
	}
	~Employee() {
		std::cout << "~Employee()" << std::endl;
	}
};

int main() {
	std::shared_ptr<Employee> emp{ new Employee{} };
	std::shared_ptr<Project> prj{ new Project{} };

	emp->m_prj = prj;
	prj->m_emp = emp;
}
*/

/*
_____DELETER____

struct Free {
	void operator()(int* p) {
		free(p);
		std::cout << "pointer freed" << std::endl;
	}
};

void MallocFree(int* p) {
	free(p);
	std::cout << "pointer freed" << std::endl;
}

int main() {
	std::shared_ptr<int> p{ (int*)malloc(4), MallocFree };
	*p = 100;
	std::cout << *p << std::endl;
}
*/

/*
_____DYNAMIC ARRAYS_____

#include <cstdlib>

//Creating Deleter
void Deleter(int a[]) {
	delete[] a;
	a = nullptr;
	std::cout << "Deleted" << std::endl;
}

int main() {
	std::unique_ptr<int[], void(*)(int*)> p{ new int[5]{1,2,3,4,5}, Deleter };
	p[0] = 10;

}
*/

/*
_____MAKE FUNCTIONS_____


#include <cstdlib>
#include <memory>

class Point {
public:
	Point(int x, int y) {

	}
};

int main() {
	//std::unique_ptr<int> p{ new int{5} };
	auto p = std::make_unique<int>(5);
	auto pt = std::make_unique<Point>(3, 5);

	auto pArr = std::make_unique<int[]>(5);
}
*/
// MEMORY MANAGEMENT PART II END



// MORE C++ GOODIES

/*
_____ENUMS & SCOPED ENUMS_____

enum class Color: long{RED=5, GREEN, BLUE};

void FillColor(Color color) {
	//Fill background with some color
	switch (color)
	{
	case Color::RED:
		cout << "RED" << endl;
		break;
	case Color::GREEN:
		cout << "GREEN" << endl;
		break;
	case Color::BLUE:
		cout << "BLUE" << endl;
		break;
	default:
		break;
	}
}

enum TrafficLight : char{RED = 'c', GREEN, YELLOW };

int main() {
	Color c = Color::RED;
	FillColor(c);
	FillColor(Color::GREEN);
	FillColor(static_cast<Color>(2));
	int x = static_cast<int>(Color::RED);
	return 0;
}
*/

/*
_____RAW STRINGS_____

extern "C"{ 
#include <cstring>
}

const char* Combine(const char* pFirst,
	const char* pLast) {
	char* fullname = new char[strlen(pFirst) +
		strlen(pLast) + 1];
	strcpy(fullname, pFirst);
	strcat(fullname, pLast);

	return fullname;
}

void UsingStdString() {
	//Initialize & assign
	std::string s = "Hello";
	s = "Hello";

	//Access
	s[0] = 'W';
	char ch = s[0];

	cout << s << endl;
	cin >> s;
	getline(cin, s);

	//Size
	s.length();

	//Insert & concatenate
	string s1{ "Hello" }, s2{ "World" };
	s = s1 + s2;

	s += s1;

	s.insert(6, "World");

	//Comparison
	if (s1 == s2) {

	}
	else if (s1 > s2) {

	}

	//Removal
	s.erase();
	s.erase(0, 5);
	s.clear();

	//Search
	auto pos = s.find("World", 0);
	if (pos != string::npos) {
		//Found
	}
}

string Combine(const string& first, const string& second) {
	string fullname = std::move(first + second);
	return fullname;
}

std::string ToUpper(const std::string& str) {
	string output;
	for (size_t i = 0; i < str.length(); i++) {
		output += toupper(str[i]);
	}
	return output;
}

std::string ToLower(const std::string& str)
{
	string output;
	for (size_t i = 0; i < str.length(); i++) {
		output += tolower(str[i]);
	}
	return output;
}

int main() {
	//char first[10];
	//char last[10];
	//cin.getline(first, 10);
	//cin.getline(last, 10);
	//
	//const char* pFullname = Combine(first, last);

	//cout << pFullname << endl;

	//delete[] pFullname;
	//pFullname = nullptr;
	
	string first;
	string last;

	getline(cin, first);
	getline(cin, last);

	string fullname = Combine(first, last);
	printf("%s", fullname.c_str());

	cout << fullname << endl;

	string first1 = "Choi";
	string last1 = "303";

	string name{ "Choi 303" };
	cout << ToLower(name) << endl;

	return 0;
}
*/

/*
_____STRING STREAMS_____

#include <sstream>

int main() {
	//int a{ 5 }, b{ 6 };
	//int sum = a + b;
	//stringstream ss;
	//ss << "Sum of " << a << " & " << "is :"
	//	<< sum << endl;
	//string s = ss.str();
	//cout << s << endl;
	//ss << sum;
	//auto ssum = to_string(sum);
	//cout << ssum << endl;

	string data = "12 89 21";
	int a;
	stringstream ss;
	ss.str(data);
	while (!ss.fail()) {
		cout << a << endl;
	}

	return 0;
}
*/

/*
_____USER-DEFINED LITERALS

class Distance {
	long double m_Kilometres;
public:
	Distance(long double km) : m_Kilometres{ km } {

	}
	long double GetKm() const {
		return m_Kilometres;
	}
	void SetKm(long double val) {
		m_Kilometres = val;
	}
};

Distance operator""_mi(long double val) {
	return Distance{ val * 1.6 };
}
int main() {
	Distance dist{ 32.0_mi };
}
*/

/*
_____CONSTANT EXPRESSIONS_____

constexpr int GetNumber() {
	return 42;
}
constexpr int Add(int x, int y) {
	return x + y;
}
constexpr int Max(int x, int y) {
	if (x > y) 
		return x;
	return y;
}

int main() {
	constexpr int i = GetNumber();
	int arr[i];

	const int j = GetNumber();
	int arr1[j];

	return 0;
}
*/

/*
_____INITIALIZER LIST (C++11)_____

extern "C" {
#include <cassert>
}

class Bag {
	int arr[10];
	int m_Size{};
public:
	Bag(std::initializer_list<int> values) {
		assert(values.size() < 10);
		auto it = values.begin();
		while (it != values.end()) {
			Add(*it);
			++it;
		}
	}
	void Add(int value) {
		assert(m_Size < 10);
		arr[m_Size++] = value;
	}
	void Remove() {
		--m_Size;
	}
	int operator[](int index) {
		return arr[index];
	}
	int GetSize() const {
		return m_Size;
	}
};

void Print(initializer_list<int> values) {
	for (auto x : values) {
		cout << x << " ";
	}
}

int main() {
	int x{ 0 };
	float y{ 3 };
	int arr[5]{ 3,1,3,8,2 };
	string s{ "Hello C++" };
	initializer_list<int> data = { 1,2,3,4 };
	auto values = { 1,2,3,4 };

	Bag b{ 3,1,8 };
	for (int i = 0; i < b.GetSize(); ++i) {
		cout << b[i] << " ";
	}

	Print({ 8,2,6,7 });
	return 0;
}
*/

/*
_____DYNAMIC ARRAY STD::VECTOR_____

#include <vector>

int main() {
	int arr[10];
	int* ptr = new int[10];
	for (int i = 0; i < 10; ++i) {
		ptr[i] = i * 10;
	}

	vector<int> data{ 1,2,3 };
	for (int i = 0; i < 5; ++i) {
		data.push_back(i * 10);
	}
	//Access
	data[0] = 100;
	for (auto x : data) {
		cout << x << " ";
	}
	auto it = data.begin();
	++it;

	--it;

	it = it + 5;

	//Delete
	it = data.begin();
	data.erase(it);
	cout << endl;
	for (auto x : data) {
		cout << x << " ";
	}

	//Insert
	it = data.begin() + 5;
	data.insert(it, 500);

	return 0;
}
*/

/*
_____UNION BASICS_____

union Test {
	int x;
	char ch;
	double d;
	Test() :ch{ 'a' } {
		cout << "__FUNCSIG__" << endl;
	}
	~Test() {
		cout << "__FUNCSIG__" << endl;
	}
};

int main() {
	cout << sizeof(Test) << endl;
	Test t;
	cout << t.ch << endl;
	t.x = 1000;
	cout << t.ch << endl;
}
*/
// MORE C++ GOODIES END

// OBJECT ORIENTED PROGRAMMING

/*
____INHERITANCE & COMPOSITION

class Animal {
public:
	void Eat() {
		cout << "Animal eating" << endl;
	}
	void Run() {
		cout << "Animal running" << endl;
	}
	void Speak() {
		cout << "Animal speaking" << endl;
	}
};

class Dog : public Animal {
public:
	void Eat() {
		cout << "Dog eating meat" << endl;
	}
	void Speak() {
		cout << "Dog barking" << endl;
	}
};

int main() {
	Dog d;
	d.Eat();
	d.Run();
	d.Speak();

	return 0;
}
*/

/*
_____ACCOUNT & SAVING CLASSES_____
_____VIRTUAL KEYWORD & VIRTUAL MECHANISM_____
_____INHEARTING CONSTRUCTOR_____

#include "OOP/Account.hpp"
#include "OOP/Savings.hpp"
#include "OOP/Checking.hpp"
#include "OOP/Transaction.hpp"

int main() {
	Account* acc = new Savings("Bob", 100, 0.05f);
	//Transact(acc);

	delete acc;
	return 0;
}
*/

/*
_____OVERRIDE & FINAL SPECIFIER_____

class Zip final {
public:
	Zip() {

	}
	void Compress(const std::string& filename) {

	}
	void PrintStatistics() {

	}
	~Zip() {
		//release resources
	}
};

#pragma region Override
class Document {
public:
	virtual void Serialize(float version) {
		std::cout << "Document::Serialize" << std::endl;
	}
};
class Text : public Document {
public:
	void Serialize(float version) override {
		std::cout << "Text::Serialize" <<
			std::endl;
	}
};
#pragma endregion
class RichText : public Text {
public:
	void Serialize(float verison) override final {
		cout << "RichText::Serialize" << endl;
	}
};

int main() {
	Text t;
	Document& doc = t;
	doc.Serialize(1.2f);

	return 0;
}
*/

/*
_____OBJECT SLICING_____
_____DOWN   CASTING_____

#include "OOP/Savings.hpp"
#include "OOP/Checking.hpp"
#include "OOP/Transaction.hpp"
int main() {
	Checking ch("Bob", 100.0f);
	Account* pAccount = &ch;

	//Down-cast
	Checking* pChecking = static_cast<Checking*>(
		pAccount
		);
	return 0;
}
*/

/*
_____TYPEID OPERATOR_____

#include "OOP/Checking.hpp"
#include "OOP/Transaction.hpp"
#include "OOP/Savings.hpp"
#include <typeinfo>

int main() {
	Savings ch("Bob", 100.0f, 0.05f);
	//Transact(&ch);

	int i{};
	float f{};
	const type_info& ti = typeid(ch);
	if (ti == typeid(ch))
	{
		cout << "class Savings"	<< endl;
	} else {
		cout << "not class Savings" << endl;
	}
	return 0;
}
*/

/*
_____DYNAMIC_CAST OPERATOR_____

#include "OOP/Checking.hpp"
#include "OOP/Transaction.hpp"
#include "OOP/Savings.hpp"
#include <typeinfo>

int main() {
	Checking ch("Bob", 100);
	Transact(&ch);

	return 0;
}
*/

/*
_____ABSTRACT CLASS_____

class Zip final {
public:
	Zip() {

	}
	void Compress(const std::string& filename) {

	}
	void PrintStatistics() {

	}
	~Zip() {
		//release resources
	}
};

#pragma region Override
class Document {
public:
	virtual void Serialize(float version) {
		std::cout << "Document::Serialize" << std::endl;
	}
};
class Text : public Document {
public:
	void Serialize(float version) override {
		std::cout << "Text::Serialize" <<
			std::endl;
	}
};

class RichText : public Text {
public:
	void Serialize(float verison) override final {
		cout << "RichText::Serialize" << endl;
	}
};

class XML : public Document {
public:
	void Serialize(float verison) override final {
		cout << "XML::Serialize" << endl;
	}
};

void Write(Document* p) {
	p->Serialize(1.1f);
}
#pragma endregion

int main() {
	XML xml;
	Write(&xml);

	return 0;
}
*/
// OBJECT ORIENTED PROGRAMMING END

// EXCEPTION HANDLING

/*
_____EXCEPTION HANDLING BASICS_____
_____EXCEPTION CATCH BLOCKS_____
extern "C" {
	_Check_return_ _Ret_maybenull_ _Post_writable_byte_size_(_Size)
		_ACRTIMP _CRTALLOCATOR _CRT_JIT_INTRINSIC _CRTRESTRICT _CRT_HYBRIDPATCHABLE
		void* __cdecl malloc(
			_In_ _CRT_GUARDOVERFLOW size_t _Size
		);
}

int ProcessRecords(int count) {
	if (count < 10)
		throw std::out_of_range("Count should be greater than 10");

	int* pArray = (int*)malloc(count * sizeof(int));
	if (pArray == nullptr) {
		throw std::runtime_error("Failed to allocate memory");
	}
	for (int i = 0; i < count; ++i) {
		pArray[i] = i;
	}
	free(pArray);

	return 0;
}

int main() {
	try {
		ProcessRecords(std::numeric_limits<int>::max());
		//ProcessRecords(5);
	}
	//catch (std::runtime_error& ex) {
	//	cout << ex.what() << endl;
	//}
	//catch (std::out_of_range& ex) {
	//	cout << ex.what() << endl;
	//}
	//catch (std::bad_alloc& ex) {
	//	cout << ex.what() << endl;
	//}
	catch (std::exception& ex) {
		cout << ex.what() << endl;
	}
	catch (...) {
		cout << "Unknown Exception" << endl;
	}
	return 0;
}
*/

/*
_____STACK UNWINDING_____

#include <memory>
#include <vector>

class Test {
public:
	Test() { cout << "Test():Acquire resources" << endl; }
	~Test() { cout << "~Test():Release resources" << endl; }
};

void ProcessRecords(int count) {
	std::unique_ptr<Test> t(new Test);
	if (count < 10)
		throw std::out_of_range("Count should be greater than 10");

	std::vector<int> p;
	p.reserve(count);
	std::vector<int> pArray;
	pArray.reserve(count);
	for (int i = 0; i < count; ++i) {
		pArray[i] = i;
	}
}

int main() {
	try {
		ProcessRecords(5);
	}
	catch (runtime_error& ex) {
		cout << ex.what() << endl;
	}
	catch (out_of_range& ex) {
		cout << ex.what() << endl;
	}
	catch (bad_alloc& ex) {
		cout << ex.what() << endl;
	}
}
*/

/*
_____NESTED EXCEPTIONS_____

#include <memory>
#include <vector>
#include <random>

class Test {
public:
	Test() { cout << "Test():Acquire resources" << endl; }
	~Test() { cout << "~Test():Release resources" << endl; }
};

void ProcessRecords(int count) {
	std::unique_ptr<Test> t(new Test);
	if (count < 10)
		throw std::out_of_range("Count should be greater than 10");

	std::vector<int> p;
	p.reserve(count);
	std::vector<int> pArray;
	pArray.reserve(count);
	for (int i = 0; i < count; ++i) {
		pArray[i] = i;
	}

	int errors{};
	std::default_random_engine eng;
	std::bernoulli_distribution dist;
	for (int i = 0; i < count; ++i) {
		try {
			cout << "Processing record # : " << i << " ";
			if (!dist(eng)) {
				throw std::runtime_error("Could not process the record");
			}
			cout << endl;
		}
		catch (runtime_error& ex) {
			cout << "[ERROR " << ex.what() << "]" <<
				endl;
			if (errors > 4) {
				runtime_error err("Too many errors.");
				ex = err;
				throw;
			}
		}
	}
}

int main() {
	try {
		ProcessRecords(5);
	}
	catch (runtime_error& ex) {
		cout << ex.what() << endl;
	}
	catch (out_of_range& ex) {
		cout << ex.what() << endl;
	}
	catch (bad_alloc& ex) {
		cout << ex.what() << endl;
	}
}
*/

/*
_____ CONSTRUCTOR & DESTRUCTOR_____

#include <memory>
#include <vector>

class A {
public:
	A() {
		cout << "A()" << endl;
	}
	~A() {
		cout << "~A()" << endl;
	}
};

class B {
public:
	B() {
		cout << "B()" << endl;
	}
	~B() {
		cout << "~B()" << endl;
	}
};

class Test {
	std::unique_ptr<A> pa{};
	B b{};
	std::unique_ptr<int> pInt{};
	std::string pStr{};
	std::vector<int> pArr{};
public:
	Test() {
		cout << "Test():Acquire resources" << endl; 
		pa.reset(new A);
		//pa = new A;
		//pInt = new int;
		//pStr = new char[1000];
		//pArr = new int[50000];
	}
	~Test() {
		cout << "~Test():Release resources" << endl; 
		//delete pa;
		//delete pInt;
		//delete[] pStr;
		//delete[] pArr;
	}
};

int main() {
	try {
		Test t;
		throw runtime_error{ "Exception" };
	}
	catch (runtime_error& ex) {
		cout << ex.what() << endl;
	}

	return 0;
}
*/

/*
//____NOEXCEPT KEYWORD_____

inline constexpr void Test(int x) {
	if(x < 10)
	throw exception{"X's value should be more than ten."};
}

int Sum(int x, int y) noexcept(noexcept(Test(x))) {
	Test(x); //Assumed function can't throw an exception but does.
	return x + y;
}

int main() {
	try {
		Test(5);
	}
	catch (exception x) {
		cout << x.what() << endl;
	}
}
*/

// EXCEPTION HANDLING END

// FILE INPUT & OUTPUT

/*
_____RAW STRING LITERALS (C++ 11)_____

int main() {
	string filename{ R"(C:\temp\newfile.txt)" };
	cout << filename << endl;
	string message{R"MSG(C++ introduced filesystem API"(In C++17)")MSG"};
	cout << message << endl;

	return 0;
}
*/

/*
_____FILE SYSTEM INTRODUCED IN C++ 17_____

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING 1;
#include <experimental/filesystem>

int main() {
	using namespace experimental::filesystem;
	path p{ "D:/Projects/Github/Modern-Cpp/README.md" };
	if (p.has_filename()) {
		cout << p.filename() << endl;
	}
	for (const auto& x : p) {
		cout << x << endl;
	}

	directory_iterator beg{ p };
	directory_iterator end{};
	while (beg != end) {
		cout << *beg << endl;
		++beg;
	}
}
*/

/*
_____FILE I/O BASICS_____

#include <fstream>
void Write() {
	ofstream out{ "data.txt" };
	out << "Hello world" << endl;
	out << 10 << endl;
	out.close();
}
void Read() noexcept(false) {
	ifstream input{ "data.txt" };
	if (!input.is_open()) {
		throw exception{ "Could not open the file." };
		return;
	}
	string message;
	getline(input, message);
	int value{};
	input >> value;
	if (input.eof()) {
		throw exception{ "End of file encountered." };
	}
	if (input.good()) {
		cout << "I/O operations are successful" << endl;
	}
	else {
		throw exception{ "Some I/O operations failed" };
	}
	input.setstate(ios::failbit);
	input.clear();
	input.close();
	cout << message << ":" << value << endl;
}

int main() {
	try {
		Write();
		Read();
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	catch (...) {
		cout << "Unknown Exception" << endl;
	}

	return 0;
}
*/

/*
_____COPY UTILITY_____

#include <fstream>
#include <experimental/filesystem>

int main() {

	try
	{
		using namespace experimental::filesystem;
		path source(current_path());
		source /= "Source.cpp";

		path dest(current_path());
		dest /= "Copy.cpp";

		ifstream input{ source };
		if (!input) {
			throw exception{ "Source file not found." };
			return -1;
		}
		ofstream output{ dest };

		string line;
		while (!getline(input, line).eof()) {
			output << line << endl;
		}
		input.close();
		output.close();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}
*/

/*
_____CHARACTER IO & SEEKING_____

#include <fstream>

void Write() {
	ofstream out("test.txt");
	if (!out) {
		throw exception{ "Could not open the file for writing" };
		return;
	}
	string message{ "C++ was invented by Bjarne" };
	for (char ch : message) {
		out.put(ch);
	}
	out.seekp(5);
	out.put('#');
}

void Read() {
	ifstream input("test.txt");
	if (!input) {
		throw exception{ "Source file not found." };
		return;
	}
	input.seekg(10, ios::beg);
	cout << "Current position is: " << input.tellg() <<
		endl;
	char ch{};
	while (input.get(ch)) {
		cout << ch << endl;
	}
}

void UsingFstream() {
	fstream stream{"file.txt"};
	if (!stream) {
		cout << "FILE DOES NOT EXIST. CREATING ONE..." <<
			endl;
		ofstream out{ "file.txt" };
		out.close();
		stream.open("file.txt");
	}
	stream << "Hello World" << endl;
	stream.seekg(0);
	string line;
	getline(stream, line);
	cout << line << endl;
}

int main() {

	try
	{
		UsingFstream();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch (...) {
		cout << "Unknown exception" << endl;
	}

	return 0;
}
*/

#include <fstream>

/*
_____IO BINRAY_____

int main() {
	ofstream textstream{ "data" };
	textstream << 12345678;

	ofstream binstream{ "binary", ios::binary | ios::out };
	int num{ 12345678 };
	binstream.write(reinterpret_cast<const char*>(&num), sizeof(num));

	ifstream input{ "binary", ios::binary | ios::in };
	input.read((char*)&num, sizeof(num));
	return 0;
}
 */

// FILE INPUT & OUTPUT END

// TEMPLATES

/*
//_____TEMPLATES BASICS_____

template<typename T>
inline constexpr T Max(T x, T y) {
	return x > y ? x : y;
}
template<typename T>
inline constexpr T Add(T x, T y) {
	return x + y;
}
template<typename T>
inline constexpr T ArraySum(T* pArr, T arrSize) {
	T sum = 0;
	for (T i = 0; i < arrSize; i++) {
		sum += pArr[i];
	}
	return sum;
}

int main() {
	int a = 4;
	int* pArr = new int[a]{ 1,2,3,4 };
	cout << ArraySum(pArr, a) << endl;

	delete[] pArr;
	pArr = nullptr;

	return 0;
}
*/

/*
_____TEMPLATE ARGUMENT DEDUCATION_____

template<typename T>
inline constexpr T Max(T x, T y) noexcept {
	cout << typeid(T).name() << endl;
	return x > y ? x : y;
}

int main() {
	Max(static_cast<float>(3), 5.5f);
	Max<double>(3, 6.2);
	int(*pfn)(int, int) = Max;


	return 0;
}
*/

/*
//_____Explicit Specialization_____

//Primary Template
template<typename T>
inline constexpr T Max(T x, T y) noexcept {
	cout << typeid(T).name() << endl;
	return x > y ? x : y;
}

//Explicit Instantiation
template char Max(char x, char y);

//Explicit Specialization
template<> inline constexpr const char* Max(const char* x, const char* y) {
	cout << "Max<const char*>()" << endl;
	return strcmp(x, y) > 0 ? x : y;
}

int main() {
	const char* b{ "B" };
	const char* a{ "A" };
	auto s = Max(a, b);
	cout << s << endl;

	return 0;
}
*/

/*
_____NON-TYPE TEMPLATE ARGUMENTS_____

template<int size>
inline constexpr void Print() noexcept {
	char buffer[size];
	cout << size << endl;
}
//template<typename T>
//inline constexpr T Sum(T* pArr, int size) {
//	T sum{};
//	for (int i = 0; i < size; ++i) {
//		sum += pArr[i];
//	}
//	return sum;
//}

template<typename T, int size>
inline constexpr T Sum(T(&parr)[size]) {
	T sum{};
	for (int i = 0; i < size; ++i) {
		sum += parr[i];
	}
	return sum;
}

int main() {
	int arr[]{ 3,1,9,7 };
	//int(&ref)[5] = arr;
	int sum = Sum(arr);
	cout << sum << endl;
 
	return 0;
}
*/

/*
_____PERFECT FORWARDING_____

#include "OOP/Integer.hpp"

class Employee {
	string m_Name;
	Integer m_Id;
public:
	template<typename T1, typename T2>
	Employee(T1&& name, T2&& id) :
		m_Name{ std::forward<T1>(name) },
		m_Id{ std::forward<T2>(id) } {

	}
};
template<typename T1, typename T2>
Employee* Create(T1&& a, T2&& b) {
	return new Employee(std::forward<T1>(a), 
		std::forward<T2>(b));
}

int main() {
	//Employee emp{ "Choi", Integer{100} };
	Integer val{ 100 };
	Employee emp3{ string{"Choi"}, val };

	return 0;
}
*/

/*
_____VARIADIC TEMPLATES_____

#include "OOP/Integer.hpp"

void Print() {
	cout << endl;
}

template<typename T, typename... Params>
//Function parameter pack
void Print(T&& a, Params&&... args) {
	std::cout << a;
	if (sizeof...(args) != 0) {
		cout << ",";
	}
	Print(forward<Params>(args)...);
}

int main() {
	//Print({ 1, 2.5, 3, 4 });
	Integer val{ 1 };
	Print(0, val, Integer{ 2 });

	return 0;
}
*/

/*
_____CLASS TEMPLATES_____

template<typename T, int size>
class Stack {
	T m_Buffer[512];
	int m_Top{ -1 };
public:
	Stack() = default;
	Stack(const Stack& obj) {
		m_Top = obj.Top;
		for (int i = 0; i < m_Top; ++i) {
			m_Buffer[i] = obj.m_Buffer[i];
		}
	}
	void Push(const T& elem) {
		m_Buffer[++m_Top] = elem;
	}
	void Pop();
	const T& Top() const {
		return m_Buffer[m_Top];
	}
	bool IsEmpty() {
		return m_Top == -1;
	}
	static Stack Create();
};

template<typename T, int size>
void Stack<T, size>::Pop() {
	--m_Top;
}

template<typename T, int size>
Stack<T, size> Stack<T, size>::Create() {
	return Stack<T, size>();
}

int main() {
	Stack<float, 10> s = Stack<float, 10>::Create();
	s.Push(3);
	s.Push(1);
	s.Push(6);
	s.Push(9);

	while (!s.IsEmpty()) {
		cout << s.Top() << " ";
		s.Pop();
	}

	return 0;
}
*/

/*
_____CLASS TEMPLATE EXPLICIT SPECIALIZATION_____

#include <vector>

template<typename T>
class PrettyPrinter {
	T* m_pData;
public:
	PrettyPrinter(T* data) : m_pData(data) {

	}
	void Print() {
		cout << "{" << *m_pData << "}" << endl;
	}
	T* GetData() {
		return m_pData;
	}
};
template<>
void PrettyPrinter<std::vector<int>>::Print() {
	cout << "{";
	for (const auto& x : *m_pData) {
		cout << x;
	}
	cout << "}";
}

//template<>
//class PrettyPrinter<std::vector<int>> {
//	std::vector<int>* m_pData;
//public:
//	PrettyPrinter(std::vector<int>* data) : m_pData(data) {
//
//	}
//	void Print() {
//		cout << "{";
//		for (const auto& x : *m_pData) {
//			cout << x;
//		}
//		cout << "}";
//	}
//	std::vector<int>* GetData() {
//		return m_pData;
//	}
//};

int main() {
	//int data = 5;
	//float f = 8.2f;
	//PrettyPrinter<int> p1(&data);
	//p1.Print();
	//PrettyPrinter<float> p2(&f);
	//p2.Print();

	char* p{ "Hello world" };
	PrettyPrinter<char> p3(p);
	p3.Print();
	char* pData = p3.GetData();
	std::vector<int> v{ 1,2,3,4,5 };
	PrettyPrinter<std::vector<int>> pv(&v);

	return 0;
}
*/

/*
_____CLASS TEMPLATE PARTIAL SPECIALIZATION_____

#include <vector>

template<typename T, int columns>
class PrettyPrinter {
	T* m_pData;
public:
	PrettyPrinter(T* data) : m_pData(data) {

	}
	void Print() {
		cout << "Columns: " << columns << endl;
		cout << "{" << *m_pData << "}" << endl;
	}
	T* GetData() {
		return m_pData;
	}
};

template<typename T>
class PrettyPrinter<T, 80> {
	T* m_pData;
public:
	PrettyPrinter(T* data) : m_pData(data) {

	}
	void Print() {
		cout << "Using 80 Columns: " << columns << endl;
		cout << "{" << *m_pData << "}" << endl;
	}
	T* GetData() {
		return m_pData;
	}
};

int main() {
	int data = 800;
	PrettyPrinter<int, 40> p{ &data };
	p.Print();

	return 0;
}
*/

/*
_____TYPEDEF, TYPE ALIAS & ALIAS TEMPLATES_____

const char* GetErrorMessage(int errorNo) {
	return "Empty";
}

typedef const char* (*PFN)(int);
using PFN = const char* (*)(int);
void ShowError(PFN pfn) {

}

int main() {
	
	PFN pfn = GetErrorMessage;
	ShowError(pfn);
	return 0;
}
*/

/*
_____TYPE TRAITS_____

template<typename T>
void Check(T&&) {
	cout << std::boolalpha;
	cout << "Is reference?" << is_reference<T>::value <<
		endl;

	cout << "After removeing: " <<
		is_reference<typename remove_reference<T>::type>::value << endl;
}

int main() {
	Check(5);
	int value{};
	Check(value);

	return 0;
}
*/

/*
_____STATIC EXPRESSIONS_____

int main() {
	static_assert(sizeof(void*) != 4, "Compile in 64-bit mode only");

	return 0;
}
*/

// TEMPLATES END

// LAMBDA EXPRESSIONS (CPP 11)

/*
_____FUNCTION POINTERS_____

using Comparator = bool(*)(int, int);
template<typename T, int size>
void Sort(T(&arr)[size], Comparator comp) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (comp(arr[j], arr[j + 1])) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

bool Comp(int x, int y) {
	return x > y;
}

bool Comp1(int x, int y) {
	return x < y;
}

int main() {
	int arr[]{ 1,6,8,4,0 };
	for (auto x : arr) {
		cout << x << " ";
	}
	cout << endl;
	Sort(arr, Comp1);
	for (auto x : arr) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
*/

/*
_____LAMBDA EXPRESSIONS_____
*/

template<typename T>
inline constexpr auto Max = [](T x, T y)->T {
	if (x > y)
		return x;
	else
		return y;
};
template<typename T>
inline constexpr auto Greater = [](T x, T y)->T {
	if (x > y)
		return true;
	else
		return false;
};

int main() {
	
	cout << Max<int>(5, 2) << endl;
	cout << Greater<int>(5, 3) << endl;
	return 0;
}

// LAMBDA EXPRESSIONS (CPP 11) END