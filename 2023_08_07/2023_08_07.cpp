//  scoped enum
enum class Pos : unsigned char {On, Off, Hold, Standby}; 

/*
Sırasıyla:
	name lookup
	context control
	access control
*/

int main() 
{
	int printf = 10;
	printf("emre"); // sytnax hatası
	::printf("emre"); // geçerli
}
//

enum class Color {Blue, Red, Purple, White, Black};
enum class TrafficColor {Red, Yellow, Green};
int main() 
{
	// syntax hatası yok
	Color::Blue;
	TrafficColor::Red;
	
	Color mycolar{ Color:: Red};
	int ival = mycolar; // syntax hatası 
}

//
enum class Color {Blue, Red, Purple, White, Black}; 
void func() 
{
	using enum Color; // C++20
	Color c1; = Red;
	c1++; // geçersiz
}

// type-cast operatorler 
/*
	C dilinde
		(target type)expr
		(int)dval
		(double)ival
		 
type-cast operatorler:
	static_cast
	const_cast
	reinterpret_cast
	dynamic_cast
	
	xxx_cast<type>(expr)
*/

// static_cast
int main() 
{
	int x = 10;
	int y = 30;
	double dval = static_cast<double>(x) / y; 
}

// const_cast
int main() 
{
	const int x{ 56 };
	const int *xp = &x;
	int *ptr = const_cast<int *>(xp);
}
