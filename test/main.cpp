#include <iostream>

void printR(){};
template <typename T,typename... Args>
void printR(T t,Args... args){
    std::cout << t  << " ";
    printR(args...);
}

int main(){
    printR(1,2,"*","123");

    return 0 ;
}
