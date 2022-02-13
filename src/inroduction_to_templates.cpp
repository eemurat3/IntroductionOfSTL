/**
 * ____________________________________________
 * @file inroduction_to_templates.cpp
 * @brief basic example about of template
 * @author Murat Kaymaz  <>
 * @version  0.1
 * @date 2022-02-10
 * @copyright2022 Murat Kaymaz
 * ____________________________________________
 */

#include <iostream>

using namespace std;


/**
 * @brief computing  square of int value
 *
 * @Param x : int value
 *
 * @Returns return square of x   
 */
//int square(int x) {
//    return x * x;
//}
/******* for scenario 1 ****************/
/**
 * @brief computing  square of double value
 *
 * @Param x : double value
 *
 * @Returns return square of x   
 */
//double square(double x) {
//    return x * x;
//}

template <typename T>
T square(T x) {
    return x * x;
} 


/**
 * @brief keeps a big array for one each type
 *
 * @tparam T parameter type for keeps in big array
 */
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
int main() {
    cout<<"square(int) 5 : "<<square(5)<<endl;
    cout<<"square(double) 5.5 : "<<square(5.5)<<endl;
    cout<<"square<double> 1.5 : "<<square<double>(1.5)<<endl;

    Mvector<int> mv;
    mv.push(5);
    mv.push(10);
    mv.push(15);
    cout<<"Mvector<int> :";
    mv.print();

    return 0;
}

