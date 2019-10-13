#include <type_traits>
#include <iostream>

template <class T>
typename std::enable_if<std::is_array<T>::value,void>::type print(T& value){
    for(auto a: value)
        std::cout << a << " ";
    std::cout << std::endl;
}

template <class T>
typename std::enable_if<std::is_pointer<T>::value,void>::type print(T& value){
    std::cout << "pointer:" << value << std::endl;
}

int main(){

    int a[5] = {1,2,3,4,5};
    print(a);
    int *b = new int [10];
    print(b);
    delete[] b;
    return 0;
}