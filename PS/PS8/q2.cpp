#include <iostream>
#include <string>
using namespace std;

template <typename T, typename U>
class Pair 
{
	public:
    	Pair(T first, U second) : first(first), second(second) {}
    	T getFirst() const { return first; }
    	void setFirst(T value) { first = value; }
    	U getSecond() const { return second; }
    	void setSecond(U value) { second = value; }
	
	private:
    	T first;
    	U second;
};

int main() 
{
    Pair<char, char> p('A', 'B');
    cout << "First is " << p.getFirst() << endl;
    p.setFirst('Z');
    cout << "First changed to " << p.getFirst() << endl;
    cout << "The pair is: " << p.getFirst() << ", " << p.getSecond() << endl;

    Pair<int, string> p2(34, "Bill");
    Pair<string, int> p3("Bill", 34);
    cout << "The pair is: " << p2.getFirst() << ", " << p2.getSecond() << endl;
    
    return 0;
}

