// выражение записывается посимвольно в стек, в нём считается баланс скобок "(" и "["
#include <iostream>
using namespace std;

template <typename TElement>
struct TNode {
    TElement data;
    TNode <TElement> *next;

    TNode (TElement newData, TNode <TElement> *nextNode) {
        data = newData;
        next = nextNode;
    }
};

template <typename TElement>
class stackInList {
private:
    unsigned int sizeOfStack;
    TNode <TElement> *currentTop;

public:
    stackInList() {
        sizeOfStack = 0;
        currentTop = NULL;
    }

    ~stackInList() {
        while (size())
            pop();
    }

    void push (const TElement element) {
        TNode <TElement> *node = new TNode <TElement> (element, currentTop);
        sizeOfStack++;
        currentTop = node;
    }

    void pop() {
        sizeOfStack--;
        TNode <TElement> *node    = currentTop;
        currentTop = currentTop->next;
        delete node;
    }

    TElement top () {
        return currentTop->data;
    }

    unsigned int size() {
        return sizeOfStack;
    }
};


int main(){
	stackInList <char>stack;
	char symb;
	while (cin>>symb){
		stack.push(symb);
		if (isspace(cin.peek()))
		{
			if (cin.get()=='\n')
				break;	
			}
			else
				break;
	}
	cout<<stack.size();
	return 0;
}
