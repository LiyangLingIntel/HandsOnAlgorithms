# 题目来源: nowcoder.com
"""
Q3. 
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
"""
# 这里要特别注意~找到任意重复的一个值并赋值到duplication[0]
# 函数返回True/False
def duplicate(numbers, duplication):
    # 不做鲁棒性检测
    num_dict = {}
    for num in numbers:
        if num in num_dict:
            duplication[0] = num
            return True
        num_dict[num] = None
    return False

def duplicate_c_style(numbers, duplication):
    # 不做鲁棒性检测
    for i in range(len(numbers)):
        while numbers[i] != i:
            if numbers[i] == numbers[numbers[i]]:
                duplication[0] = numbers[i]
                return True
            tmp = numbers[i]
            numbers[i], numbers[tmp] = numbers[tmp], numbers[i]
        return False
    return False


"""
Q4.
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
"""
# array 二维列表
def find(target, array):
    rows = len(array)
    cols = len(array[0])

    row_start, row_end = 0, rows - 1
    col_start, col_end = 0, cols - 1
    while row_end >= row_start and col_end >= col_start:
        if array[row_start][col_end] == target:
            return True
        if array[row_start][col_end] > target:
            col_end -= 1
        else:
            row_start += 1
    return False