#include <iostream>

int main() 
{
	std::cout << "merhaba dunya!" << std::endl; 
}

// C in C++

/*
	undefined behavior
	unspecified behavior
		implemantation defined 
*/


/*
	implicit int
	C'de geri dönüş değeri int kabul edilecek. C++'da syntax hatası
	NOT: C'de de geçerliliğini yetirdi.
	func(int x)
	{
		return x + 5;
	}

*/

/*
	C -old-style function definitions
	
	func(a, b, c)
	double a, b, c;
	{
		return a + b + c;
	}

*/

// implicit function declaration
int main() 
{
	func(1, 2, 3); // tanımlanmasa bile C'de geçerli C++ geçersiz
}

//

int foo(); // parametre değişkeni hakkında bilgi vermiyoruz
int bar(void); // parametre değikeni yok

int main() 
{
	// C'de 
	foo(21, 56, 78); // C'de geçerli C++'da geçersiz
	bar(21, 31, 12); // C ve C++ geçersiz
}

// 
int foo() 
{
	// return olmaması C'de geçerli C++'da geçersiz
	printf("emre");
}

/*
	parametre değişkeleri (formal parametre)
	void func(int x, int y)
	
	argument (actual parametre)
	func(a, b) 

*/

/*
	C de karakter sabitleri int C++'da char türündedir 
	'A' 
	'\n'
	
	10 > 5 bu ifadenin türü C'de int C++'da bool

*/


int main() 
{
	char c1 = 10;
	char c2 = 20;
	
	c1 + c2 // int
	
}