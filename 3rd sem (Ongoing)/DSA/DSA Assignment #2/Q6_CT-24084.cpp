#include <bits/stdc++.h>
using namespace std;


class Stack
{
    int *min_st;
    int min_size;
    int size;
    int capacity;
    int *st;

    public:
    Stack(int s=0) : capacity(s), size(0), min_size(0)
    {
        st = new int[s];
        min_st = new int[10];
    }
    
    void push(int val)
    {
        if (isFull())
            resize();
        st[size++] = val;

        if (min_size == 0 || val <= min_st[min_size - 1])
            min_st[min_size++] = val;
    }

    int pop()
    {
        if (isEmpty())
            throw runtime_error("stack empty");
        
        if (st[size - 1] == min_st[min_size - 1])
            min_size--;

        return st[size--];
    }
    
    void resize()
    {
        int *temp = capacity > 0 ? new int[capacity*2] : new int[1];
        for (int i = 0; i<capacity; i++)
            temp[i] = st[i];
        capacity = capacity > 0 ? capacity*2 : 1;
        
        delete[] st;
        st = temp;
    }

    bool isFull() {return capacity == size;}
    bool isEmpty() {return size == 0;}
    int minimum() {return min_size != 0 ? min_st[min_size-1] : throw runtime_error("nuhuh");}

    ~Stack()
    {
        delete[] st;
        delete[] min_st;
    }
};


int main()
{
    Stack st = Stack(10);
    st.push(200);
    st.push(2);
    st.push(3);
    st.push(10);
    st.push(1);
    cout<<st.minimum()<<endl;
    st.pop();
    cout<<st.minimum()<<endl;

}