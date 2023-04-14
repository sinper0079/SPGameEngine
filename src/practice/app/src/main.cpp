#include <sge_core\base\sge_base.h>

namespace week1 {
using namespace sge;
#define TEST(...)   do{   PrintFuc(  __VA_ARGS__); } while(false) 
using namespace std;
template<class... Args>
void PrintFuc(Args&&... args) { //see why && in later chapter
	cout << sizeof...(args) << endl;
}

void PrintStrView(StrView sth) {
	TempString SthStr(sth);
	SGE_LOG(SthStr.c_str());
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




	clsA.print();
	TEST(1,1,2);
	
	char* c ="haha";

	PrintStrView(c);
	
	return 0;
}
