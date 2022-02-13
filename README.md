- [Introduction of STL](#ios)
    - [Introduction of Templates](#iotemplate)
        - [Template Function](#ftemplate)
        - [Template class](#ctemplate)

# Introduction of STL
## Introduction of Template
### Template Function
why we need to use template? suppose to, you want take of square one number and you define below function for this job.
```cpp
int square(int x) {
    return x * x;
}
```
when you call this function in the main function with integer parameter every is seem okey.
```cpp
cout<< square(5);
output : 25
```
however later on ı want to compute square of 5.5
```cpp
cout<< square(5.5);
output : 25
```
this output is wrong because square function only works with integer. solving
for this problem we have to make copy square fuction and change the type to double. 
```cpp
double square(double x) {
    return x * x;
}
```
when we call again square function with 5.5, output is true. this code gets your job is done but in a very inconvenient way
```cpp
cout<< square(5.5);
output : 30.25
```
suppose the later on ı wan to computing square of a long or square of a float or square of a complex.
I have to make a duplicate of the square function for each one of the data type. 
This make ouk code ugly and we do not want that and this is why we need a template.
with template we only need one of the square function code. for this  we need to do square 
function is make template

```cpp
template <typename T>
T square(T x) {
    return x * x;
}
```
later on  we can call sqaure function different two way for double or another any type.
for example
<strong>first way</strong>
```cpp
cout<< square(1.5);
output : 2.25
```
<strong>second way</strong>
```cpp
cout<< square<double>(5.5);
output : 2.25
```
when we square function is  invoked T is replaced with  double for above code.
Another thing to note is : with template function you do not have to specifically 
tell the compiler the data type. The data type can be inferred from the parameter.


Template has a side-effect called code bloat. square<int>(5) and square<double>(5.5) 
function are actually differen square functions. In other words they occupy their own 
space in the final program image. so if we use the square template function on a 
lot of different data types the code size will be bloated.

### Template class
we defining a template class for keep a big array for one each type
```cpp
template <typename T>
class Mvector {
public:
    Mvector() : size(0) {};
    void push(T x){ arr[size] = x; size++; }
    void print() const { 
        for(int i=0;i<size;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
private:
    T arr[1000];
    int size;
};
```
in main function we declaring Mvector for int type and  push 3 values in to Mvector
```cpp
Mvector<int> mv;
mv.push(5);
mv.push(10);
mv.push(15);
cout<<"Mvector<int> :";
mv.print();

output : Mvector<int> :5 10 15
```

<strong>One difference betwwen a class template and function template is, function template 
can infer the data type from parameter  so you do not have to eplicitily tell the compiler 
what is the data type but for class template you have specifically tell the compiler 
what is the data type.</strong>




