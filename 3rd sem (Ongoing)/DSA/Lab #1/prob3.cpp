#include<iostream>
using namespace std;

class MedianFinder{
	private:
		int arr[50000];
		int size;
	public:
		MedianFinder() : size(0) {}
		
		void addnum(int num)
        {
			int i=size-1;
			while(i>=0 && arr[i]>num)
            {
				arr[i+1]=arr[i];
				i--;
			}
			arr[i+1]=num;
			size++;
		}
		
		double findmedian()
        {
			if(size%2==1) {return arr[(size/2)];}
			else
            {
				int mid=size/2;
				return(arr[mid-1]+arr[mid])/(double)2;
			}
		}
};

int main(void)
{
	MedianFinder mf;
	cout<<"Enter numbers to find median (-1 to stop): "<<endl;
    int num;
    do
    {
    	cin>>num;
    	mf.addnum(num);
    } while (num!=-1);
    
	cout<<"median: " << mf.findmedian()<<endl;
	return 0;
}