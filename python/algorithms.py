import copy
from itertools import product, combinations


class AlgoSort(object):
    """
    Implement common sort algorithms in cpp style
    """

    # 选择排序
    @staticmethod
    def select_sort(nums: list, reversed=False) -> list:
        """
        复杂度: O(n^2), 需要 N^2/2 次比较和 N 次交换
        思想: 从数组中选择最小元素，将它与数组的第一个元素交换位置。再从数组剩下的元素中选择出最小的元素，将它与数组的第二个元素交换位置。不断进行这样的操作，直到将整个数组排序。
        """

        compare = (lambda x, y: x < y) if reversed else (lambda x, y: x > y)

        N = len(nums)
        for i in range(N):
            min_id = i
            for j in range(i + 1, N):
                if compare(nums[min_id], nums[j]):
                    min_id = j
            nums[i], nums[min_id] = nums[min_id], nums[i]

        return nums

    # 冒泡排序
    @staticmethod
    def bubble_sort(nums: list, reversed: bool = False) -> list:
        """
        复杂度: O(n^2), 
        思想: 从左到右不断交换相邻逆序的元素，在一轮的循环之后，可以让未排序的最大元素上浮到右侧。
             在一轮循环中，如果没有发生交换，那么说明数组已经是有序的，此时可以直接退出。
        """

        compare = (lambda x, y: x < y) if reversed else (lambda x, y: x > y)

        N = len(nums)
        is_sorted = False
        for i in range(N)[::-1]:
            if is_sorted:
                break
            is_sorted = True
            for j in range(i):
                if compare(nums[j], nums[j + 1]):
                    is_sorted = False
                    nums[j], nums[j + 1] = nums[j + 1], nums[j]

        return nums

    # 插入排序
    @staticmethod
    def insert_sort(nums: list, reversed: bool = False) -> list:
        """
        复杂度: O(n) ~ O(n^2), 平均需要 N^2/4 比较以及 N^2/4 次交换
        思想: 每次都将当前元素插入到左侧已经排序的数组中，使得插入之后左侧数组依然有序。个人理解是反向的冒泡.
        """
        compare = (lambda x, y: x < y) if reversed else (lambda x, y: x > y)

        N = len(nums)
        for i in range(1, N):
            for j in range(1, i + 1)[::-1]:
                if compare(nums[j - 1], nums[j]):
                    nums[j], nums[j - 1] = nums[j - 1], nums[j]
                else:
                    break

        return nums

    @staticmethod
    def __get_interval(N: int, interv: int = 3) -> int:
        h = 1
        while (h < N // 3):
            h = interv * h + 1
        return h

    @staticmethod
    def shell_sort(nums: list, reversed: bool = False):
        """
        复杂度: 小于 O(n^2), N 的若干倍乘于递增序列的长度	
        思想: 基于插入排序, 但是调整为对间隔 h 的序列进行排序, 通过交换不相邻的元素，每次可以将逆序数量减少大于 1, 不断减小 h，最后令 h=1，就可以使得整个数组是有序的.
        """
        compare = (lambda x, y: x < y) if reversed else (lambda x, y: x > y)

        N = len(nums)
        h = AlgoSort.__get_interval(N)
        while (h >= 1):
            for i in range(h, N):
                for j in range(h, i + 1, h)[::-1]:
                    if compare(nums[j - h], nums[j]):
                        nums[j], nums[j - h] = nums[j - h], nums[j]
                    else:
                        break
            h //= 3
        return nums

    # 归并排序
    @staticmethod
    def __merge_subsort(nums: list,
                        left: int,
                        right: int,
                        reversed: bool = False):
        if right <= left:
            return

        mid = (left + right) // 2
        AlgoSort.__merge_subsort(nums, left, mid, reversed)
        AlgoSort.__merge_subsort(nums, mid + 1, right, reversed)
        AlgoSort.__merge(nums, left, mid, right, reversed)

    @staticmethod
    def __merge(nums: list,
                left: int,
                mid: int,
                right: int,
                reversed: bool = False):

        compare = (lambda x, y: x < y) if reversed else (lambda x, y: x > y)
        aux = nums[:]
        i = left
        j = mid + 1

        for k in range(left, right + 1):
            # 先判断左右两部分是否已经遍历完, 是的话直接存储剩下的部分
            if i > mid:
                nums[k] = aux[j]
                j += 1
            elif j > right:
                nums[k] = aux[i]
                i += 1
            # 比较左右两个部分的元素, 把符合要求的先存到结果list里
            elif compare(aux[i], aux[j]):
                nums[k] = aux[j]
                j += 1
            else:
                nums[k] = aux[i]
                i += 1

    @staticmethod
    def merge_sort(nums: list, reversed: bool = False) -> list:
        """
        复杂度: O(nlogn)
        思想: 将数组分成两部分，分别进行排序，然后归并起来
        """

        N = len(nums)
        AlgoSort.__merge_subsort(nums, 0, N - 1, reversed)
        return nums

    # 快速排序
    @staticmethod
    def __quick_subsort(nums: list,
                        start_id: int,
                        end_id: int,
                        reversed: bool = False):

        if start_id < end_id:
            compare = (lambda x, y: x < y) if reversed else (
                lambda x, y: x > y)

            flag = nums[start_id]
            i, j = start_id + 1, end_id

            while i < j:
                while compare(flag, nums[i]) and (i < end_id):
                    i += 1
                while compare(nums[j], flag) and (j > start_id):
                    j -= 1
                if i >= j:
                    break
                nums[i], nums[j] = nums[j], nums[i]
            nums[start_id], nums[j] = nums[j], nums[start_id]

            AlgoSort.__quick_subsort(nums, start_id, j - 1, reversed)
            AlgoSort.__quick_subsort(nums, j + 1, end_id, reversed)
        return nums

    @staticmethod
    def quick_sort(nums: list, reversed=False) -> list:
        """
        复杂度: O(nlogn), 平均时间是归并排序的一半
        思想: 通过一个切分元素将数组分为两个子数组，左子数组小于等于切分元素，右子数组大于等于切分元素，将这两个子数组排序也就将整个数组排序
        """
        N = len(nums)
        AlgoSort.__quick_subsort(nums, 0, N - 1, reversed)
        return nums


if __name__ == "__main__":

    li = [5, 1, 3, 7, 12, 0, 999, -8]
    print(AlgoSort.select_sort(li))
    li = [5, 1, 3, 7, 12, 0, 999, -8]
    print(AlgoSort.bubble_sort(li))
    li = [5, 1, 3, 7, 12, 0, 999, -8]
    print(AlgoSort.insert_sort(li))
    li = [5, 1, 3, 7, 12, 0, 999, -8]
    print(AlgoSort.shell_sort(li))
    li = [5, 1, 3, 7, 12, 0, 999, -8]
    print(AlgoSort.merge_sort(li))
    li = [5, 1, 3, 7, 12, 0, 999, -8]
    print(AlgoSort.quick_sort(li))