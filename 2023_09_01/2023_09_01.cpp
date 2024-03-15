// Bir Fighter hayatta kalan diğer dövüşcülerden yardım isticek
 
 class Fighter 
 {
 public:
				
	 Fighter() 
	 {
		 
		 fvec_.push_back(this);
	 }	
	 Fighter(std::string name, int age); name_(std::move(name)) , age_(age)  
	 {
		 
		  fvec_.push_back(this);
	 }
	 
	 ~Fighter() 
	 {
		 
		 //std::erase(fvec_, this);
		 if (auto iter = std::find(fvec_.begin(), fvec_.end(), this); iter != fvec_.end()) 
		 {
			 fvec_.erase(iter);
		 }
		 
		 else 
		 {
			 
			 std::cer << "this pointer cannot be found in the container\n";
		 }
		 
	 }
	 Fighter(const Fighter&) = delete;
	 Fighter& operator=(const Fighter&) = delete;
	 
	 
	 void ask_for_help() 
	 {
		 std::cout << "yetisin basım belada... \n";
		 for(auto p: fvec_) 
		 {
			 if ( p!= this && p->get_age > 15) 
			 {
				 std::cout << p->get_name() << " ";
			 }
		 }
	 };
	 
	 std::string get_name() const {return name_ ;};
	 int get_age() const {return age_ ;}};
	 
 private:
		std::string name_;
		int age_{0};
		inline static std::vector<Fighter* > fvec_;
	 
 };
 
 int main() 
 {
	 Fighter f1{"Emre" , 50};
	 Fighter f2{"Mehmet", 25);
	 Fighter f3{"Necati", 19};
	 
	 
	 auto p1 {new Fighter("ganoş", 23)};
	
	 f3.ask_for_help();
	 delete p1;
	 
	 f1.ask_for_help();
	 
	 f3.call_fighters_for_help();
	 
 }
 
 
 
 
 // delegating ctor ( modern cpp )
 
/*
	cogu zaman sınıfların ctor'ları overload ediliyor
	ancak overload edilen ctor'ların bazen ortak bir kodu oluyor.
	Unutmayınız ki kod tekrarı her türlü belayı beraberinde getirir
	eski Cpp'de ctor'ların ortak bir kodu bir fonksiyon şekline tanımlanıyor
	ve ctor'lar bu fonksiyon çağrıyordu

*/

class Myclass 
{
	public:
		Myclass(int) : Myclass(x, x, x)
		{
			//common_code();
		};
		
		Myclass(int, int) :  Myclass(x, x, 0)
		{
			
		}
		Myclass(int, int, int) : mx(x), my(y), mz(z)
		{
			//common_code();
			
			//belki ortak kod
			
		};
		Myclass(const char *p) :Myclass(std::atio(p))
		{
			//common_code();
			
		};
		
	private:
		common_code();
		int mx, my, mz;
		
}


//friend bildirimleri

/*
	friend bildirimleri (hemen her zaman sınıfın kendi kodlarına veriliyor)
	
	sınıfın
		a) global fonksiyonları (free functions)
		b) yardımcı türler
*/


class Myclass 
{
	public:
		// friend bildirim private veya public yapılabilir. Bir fark yok
		friend void ff(Myclass); 
	private:
		int mx{};
		void foo(Myclass);	
};

void ff(Myclass m) 
{
	m.foo();
	Myclass myc;
	myc.mx = 5;
	// private olmasına rağmen eriştik
}

//===================================

class Myclass 
{
	public:
		// hidden friend
		friend void bar(Myclass, int x ) 
		{
			return x * x; // bu fonksiyon class'ın memberi değil
		} 
	private:
		int mx{};
		void foo(Myclass);	
};

//===================================
class Erg 
{
	public: 
		Erg(int);
		void foo(int);
};
class Nec 
{
	private:
		friend void Erg::foo(int);
		friend Erg::Erg(int); // ctor friend'Lik verebiliriz.
		int mx;
}

void Erg::foo(int x) 
{
	Nec necx;
	
	necx.mx = x; // private eriştil
}


/*
	Bir sınıf bir başka sınıfa "frined"lik verebilir.
	Bu durumda friend bildirime konu sınıf incomplite type olabilir
*/


class Nec 
{	
	private:
		friend class Erg; // Erg bildirimi olmaması rağmen friend'Lik verdik
}

/*
	A sınıf'ı B sınıfına friend'Lik verirse A sınıfı B'nin private
	bölümüne erişemez
	
	A B'ye friend'lik vermiş olsun
	B C'ye friend'Lik vermiş olsun
	C A'nın private bölümüne erişemez
	yani frinedlik geçişken değildir.
*/


/*
	Base sınıfından Der sınıfı kalıtım yoluuyla elde edilmiş olsun.
	Base sınıfı global foo işlevine friend'lik vermiş olsun.
	foo işlevi Der sınıfın private bölümüne erişemez
	
*/


/*
	bazen ihtiyaç olsa da bir sınıf kendi seçilmiş öğeleri için
	bir başka kodda friend'lik veremez
	
	Böyle durumarda bazı idioms/ techniques kullanabilir
	- attorney
*/


//operator overloading 1.22

/*
	operator function
		free function
		non-static member function
		
	run time maliyeti yok tamamen derleme zamanında çalışır
	
	genel kurallar
	================
	
	1) keyfi isimlendirme yok. isim operator anahtar sözcüğünü içerecek
	operator+
	operator!
	operator++
	operator==
	
	2) olmayan bir operator overload edilemez
	a @ b // böyle bir operator olmadığı için @ ile yapamayız
	
	3) operandlar en az birinin user defined olmalı
	
	4)  global operator function ya da member operator function olmalı
	
	5) her operator overload edilemiyor. Dilin kuralları bazı opearatörlerin
		overload edilmesini yasaklıyor
		
		bunlar:
		. operatorü overload edilemiyor
		? : (ternarny operator overload edilemiyor)
		sizeof operator overlaod edilemiyor
		.* operatörü (C'de olmayan Cpp dilinde olan bir operator)
		typeid operatoru
	
	6) Bazı operatorler yalnızca member operator function overload edililr
		function call operator (fonksiyon çağrı operator)
		subscript operator a[b]
		assignment operators
		tür dönüştürme operatorleri
		-> arrow operator
	
	7) bir istisna hariç operator fonksiyonları "default arguman" alamıyor
		function call operator
	 
		
	8) Bu mekanizmada operatör öncelik seviyesi ve operator öncelik yönü değiştirilemiyor
	
		Mesela,
		a * b + c > 10
		((a * b ) + c) > 10  normali böyle öncelik değiştirilemiyor.
	
	9) Bütün operatör fonksiyonları isimleriyle çağırılabiliyor.
		
		Mesela,
		
		a) a + b  ya da operator+(a + b)  
		
		b)	class Myclass 
			{
				
			};
			
			main() 
			{
				Myclass a, b, c;
				a = b; // a.operator(b)
			}
			
	  10) Bu mekanizmada ile operatörlerin "arity" sini değişitiremeyiz
	  
	  arity ==> operator unary ya da binary olmasına
	  
	  a > b // binary çünkü 2 variable aldı
	  !a // unary tek variable aldı
	  
	  bool operator >(Myclass); // hatalı tek parametre var
	  bool operator >(Myclass, Myclass); // hata yok
	  bool operator >(Myclass, Myclass, Myclass); // hatalı 3 parametre var
	 
	  
	11) Eğer member operator functions ise
		
		a > b  myclass::operator>;
			   a.operator>(b);   // yani sol operator this'i alır
			   
     class Myclass {
		 
		 public:
			bool operator>(Myclass)const;
			//burda hata olmaz çünkü sol operand this'tir
			bool operator>(Myclass,Myclass)const; // hatalıdır
			
			bool operator!()const; // this operand olarak kullanılır sadece
			bool operator!(Myclass)const; // hatalıdır
	 }
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
*/

















