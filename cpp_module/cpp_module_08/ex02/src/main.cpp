#include "MutantStack.hpp"

int main() {
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);

        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    {
        MutantStack<char> mstack;
        mstack.push('a');
        mstack.push('b');
        mstack.push('c');
        mstack.push('d');
        mstack.push('e');
        MutantStack<char>::reverse_iterator rit = mstack.rbegin();
        MutantStack<char>::reverse_iterator rite = mstack.rend();
        ++rit;
        --rit;
        while (rit != rite) {
            std::cout << *rit << std::endl;
            ++rit;
        }
    }
    return 0;
}
