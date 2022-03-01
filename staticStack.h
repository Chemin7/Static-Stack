#ifndef STATICSTACK_H_INCLUDED
#define STATICSTACK_H_INCLUDED

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <exception>
#include <string>

class StackException : public std::exception {
    private:
        std::string msg;
    public:
        explicit StackException(const char* message) : msg(message) {}

        explicit StackException(const std::string& message) : msg(message) {}

        virtual ~StackException() throw () {}

        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };

template <class T,int ARRAYSIZE = 20>
class Stack {
    private:
        T data[ARRAYSIZE];
        int top;
        void copyAll(const Stack<T,ARRAYSIZE>&);
    public:
        Stack();
        Stack(const Stack&);

        Stack& operator = (const Stack&);

        bool isEmpty() const;
        bool isFull() const;
        void push(const T&);
        void pop();
        T getTop();

        std::string toString();

    };


using namespace std;

template <class T,int ARRAYSIZE>
Stack<T,ARRAYSIZE>::Stack() : top(-1){}

template <class T,int ARRAYSIZE>
void Stack<T,ARRAYSIZE>::copyAll(const Stack<T,ARRAYSIZE>& s)
{
    int i(0);
    while(i >=s.top){
        data[i] = s.data[i];
        i++;
    }

    top = s.top;
}


template <class T,int ARRAYSIZE>
Stack<T,ARRAYSIZE>::Stack(const Stack& s)
{
    copyAll(s);
}

template <class T,int ARRAYSIZE>
Stack<T,ARRAYSIZE>& Stack<T,ARRAYSIZE>::operator=(const Stack& s)
{
    copyAll(s);

    return *this;
}

template <class T,int ARRAYSIZE>
bool Stack<T,ARRAYSIZE>::isEmpty() const {
    return (top == -1) ? true : false ;
}

template <class T,int ARRAYSIZE>
bool Stack<T,ARRAYSIZE>::isFull() const
{
    return (top == ARRAYSIZE -1) ? true : false ;
}

template <class T,int ARRAYSIZE>
void Stack<T,ARRAYSIZE>::push(const T& element)
{
    if(isFull())
        throw StackException("Desbordamiento de datos,push");
    else
        data[++top] = element;

}

template <class T,int ARRAYSIZE>
void Stack<T,ARRAYSIZE>::pop()
{
    if(isEmpty())
        throw StackException("Insuficiencia de datos,pop");
    else
        top--;
}

template <class T,int ARRAYSIZE>
T Stack<T,ARRAYSIZE>::getTop()
{
    return data[top];
}




#endif // STATICSTACK_H_INCLUDED
