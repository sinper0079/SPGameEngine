

namespace week1 {
using namespace sge;
#define TEST(...)   do{   PrintFuc(  __VA_ARGS__); } while(false) 
using namespace std;
template<class... Args>
void PrintFuc(Args&&... args) { //see why && in later chapter, as I rmb is fwd sth
	cout << sizeof...(args) << endl;
}

class Optr {

public:

	Optr() = default;
	Optr( int a ) : _a(a){} // : _a(a) set member variables 
	Optr operator+(const Optr& r) const { return Optr(_a + r._a); }

  int _a = 1;
};


void PrintStrView(StrView sth) {
	TempString SthStr(sth);
	SGE_LOG(SthStr.c_str());
}

void testStringView() {
	char a[] = "let me try sth";
	char* b ="haha";
	StrView str(a, 5); //pointer + size
	SGE_LOG("test {}", str);
}


class ClassA{
public:
	inline void print(){SGE_LOG("TEST");}
};






void week1(){
	int a = 10;
	do {
		SGE_LOG("TEST");
		a--;
	}while (a>0);

}
}
using namespace week1;
int main() {
	//SGE_LOG("TEST");
	using Base = ClassA;

	//week1::week1();
	Base clsA;

	Optr OptrA; 
	Optr OptrB;
	Optr OptrC = OptrA + OptrB;

	SGE_LOG("test {}", OptrC._a);

	clsA.print();
	TEST(1,1,2);
	
	char* c ="haha";
	testStringView();
	PrintStrView(c);
	
	return 0;
}
