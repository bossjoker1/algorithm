def fib(n):
    ''' 函数定义'''
    a , b = 0, 1
    
    while a < n:
        print(a, end=",")
        a, b = b, a + b
    print
      

def main():
    print('hello world')
    b = ['first', 'second', 'third']
    for i in b:
        print(i, end="") # 不换行
    print()
    put = int(input("请输入你的数字："))
    print(put)
    
    print("输入多个整数：")
    l = list(map(int, input().split()))
    print(l)
    
    fib(10)

# 仅当执行的是该脚本时，才运行main函数
if __name__ == '__main__':
    main()