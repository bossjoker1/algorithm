package main

// 能种就种
func canPlaceFlowers(flowerbed []int, n int) bool {
    for i := 0 ; i < len(flowerbed);{
        if flowerbed[i] == 1{
            i += 2
        }else if flowerbed[i] == 0 && (i == len(flowerbed) - 1 || flowerbed[i+1] == 0){
            n --
            i +=2
        }else{
            i += 3
        }
        if n <= 0{
            return true
        }
    }
    return false
}