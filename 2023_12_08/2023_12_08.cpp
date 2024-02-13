//input output operations  

/*
	cout ve cin bir sınıf nesnesidir.


					ios_base
				
				basic_ios<c, t> ios
				
		basic_istream		basic_ostream
			istream				ostream
			
					basic_iostream
*/

int main() 
{
	using namespace std;
	
	cout << "mert sirakaya\n";
	operator<<(cout, "mert sirakaya\n");
	
	cout << 'A';  //--A
	operator<<(cout, 'A'); // char  --A
	cout.operator << ('A'); // int  --65
}


class ostream
{
	public:
		ostream& operation<<(int);
		ostream& operation<<(double);
		ostream& operation<<(float);	
		
		ostream& operation<<(ostream&(*)(ostream&)); // function pointer
};
// global fonksiyonlar
operator<<(ostream&, const char*);
operator<<(ostream&, char);

/*
		format state
		on-off flags
	
		on			off 		default
	true-false		1/0			  off
	showpos
	uppercase

*/

// ios::boolalpha
int main() 
{
	using namespace std;
	cout << true << false << "\n"; // 10
	cout.setf(ios::boolalpha);
	cout.setf(cout.flags() | ios::boolalpha);
	cout << true << false << "\n"; // truefalse
	
	
	if (cout.flags() & ios::boolalpha) 
	{
		cout << "true false olarak yazar\n";
	}
	else
	{
		cout < "1 0 olarak yazar\n";
	}
	
	cout.flags(cout.flags() & ~ios::boolalpha);
	cout.unsetf(ios::boolalpha);
	
	cout << true << false << "\n"; // 10
}

//ios::showpoint

int main() 
{
	using namespace std;
	
	double dval = 4.;
	cout << dval << "\n"; // 4
	cout.setf(ios::showpoint);
	cout << dval << "\n"; // 4.0000000000	
}

/*
	Gerçek sayıların gösterimi
	a) fixed    		ios::fixed
	b) scientific 		ios::scientific
	c) büyüklüğüne bağlı

*/

int main() 
{
	 cout.setf(ios:fixed, ios::floatfield);
	 cout << "ios: :fixed : " << (cout. .flags (() & ios::fixed ? "set" " : "unset") << "\n";
	 cout << "ios::scientific: " << (cout.flags() & ios::scientific? "set" : "unset") << "\n";
	 cout << 7324.72345 << "\n";
	 cout << 8732480245453.872345<< "\n";

}

// ostream manipulator

class ostream 
{
	public:
		ostream& operator<<(int);
		ostream& operator<<(double);
		ostream& operator<<(ostream&(*fp)(ostream&))
		{
			return fp(*this);
		}
		// cout << endl  end fonksiyonuna cout göndermiş oluyoruz
};

///////

std::ostream& Boolalpha(std::ostream& os) 
{
	os.setf(std::ios::boolalpha);
	return os;
}
std::ostream& NoBoolalpha(std::ostream& os) 
{
	os.unsetf(std::ios::boolalpha);
	return os;
}

int main() 
{
	std::cout << Boolalpha << (10 > 5) << NoBoolalpha << (10 > 5=;
	
	std::cout << std::boolalpha << (10 > 5) << std::noboolalpha << (10 > 5=;
}


////////

std::ostream& dline(std::ostream& os) 
{
	return os << "\n----------------------------";
}

int main() 
{
	cout << 12 << dline << dline << 23.5 << "emre";
}
