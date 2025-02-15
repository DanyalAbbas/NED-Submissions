#include <iostream>
using namespace std;

class DynamicArray
{
    private:
        int CurrentSize;
        int MaxSize;
        int *array;

        void resize(void)
        {
            int *temp = MaxSize > 0 ? new int[MaxSize + 2*MaxSize] : new int;

            for (int i = 0; i < CurrentSize; i++)
                temp[i] = array[i];
            
            delete[] array;

            MaxSize += MaxSize > 0 ? MaxSize * 2 : 1;
            array = temp;
       
        }

    public:
        DynamicArray(int size = 0)
        {
            CurrentSize = 0;
            MaxSize = size;
            array = MaxSize > 0 ? new int[MaxSize] : NULL;
            
        }

        void push(int val)
        {
            if (CurrentSize == MaxSize)
                {resize();}
            
            array[CurrentSize] = val;
            CurrentSize++;
        }

        int size(void) {return CurrentSize;}

};

int main()
{
    DynamicArray ob1;
    cout<<ob1.size()<<endl;
    ob1.push(10);
    cout<<ob1.size()<<endl;
    ob1.push(10);
    cout<<ob1.size()<<endl;
    ob1.push(10);
    ob1.push(10);
    cout<<ob1.size()<<endl;
    ob1.push(10);
    // ob1.push(10);
    cout<<ob1.size()<<endl;
}