## 函数指针

**函数的类型只由它的返回值和参数表决定**

```c++
#include <iostream>
using namespace std;
int add(int a,int b){
return (a+b);
}
typedef int (* func)(int ,int ) ;
//func 为函数指针， 指向 返回值为int类型，输入参数列表为（int， int）的函数

void main(){
 func f = add;
 int n = f(1,2);
 cout << n << endl;
}

// output: 3
```

