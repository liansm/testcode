#include <stdio.h>

//
//如果spinlock本来就是1, 返回值为1
//如果spinlock本来是0, 返回值为0，同时spinlock交换为1, 代表lock成功
//
static inline int __xchg(int* spinlock ,int new_val)
{
    int ret;
    __asm__ __volatile__
    (
         "xchgl %0, %1"
          : "=r"(ret), "=m"(*spinlock)
          : "0"(new_val), "m"(*spinlock)
         : "memory"
    );
   return ret;
}


void test_xchg()
{
    int spinlock = 0; 
//    int spinlock = 1; 

    int ret = __xchg(&spinlock, 1);
    
    printf("ret = %d \n", ret);

    return;
}

int main()
{
    test_xchg();

    return 0;
}
