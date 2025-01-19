#include <iostream>
#include <cmath>
using namespace std;


float calculate_SurfaceArea(float r)
{
    return 4*M_PI*pow(r,2);
}

float calculate_Volume(float r)
{
    return (1.3333333)*M_PI*pow(r,3);
}

int main()
{
    float surface, volume;
    surface = calculate_SurfaceArea(5);
    volume = calculate_Volume(5);
    
    cout<<surface<<endl;
    cout<<volume<<endl;
}