package main

// 库函数使用
func largestGoodInteger(num string) string {
    for c := '9'; c >= '0'; c--{
        s := strings.Repeat(string(c), 3)
        if strings.Contains(num, s){
            return s
        }
    }
    return ""
}