import unittest
from typing import Dict


def rectify_str(_str: str) -> Dict:
    """
    给定一个题目定义的多项式字符串,将其放到一个dict中{幂:系数}
    :param _str: 题目定义的多项式字符串
    """
    result = {}
    numbers = _str[2:].split()
    for i in range(0, len(numbers) - 1, 2):
        result[int(numbers[i])] = float(numbers[i + 1])
    return result


def rectify_data(data: Dict) -> str:
    """
    将求解用的数据结构，转换为题目定义的多项式字符串
    :param data: 求解用的数据结构
    """
    data = {k: data[k] for k in sorted(data.keys(), reverse=True)}

    if len(data) > 0:
        numbers = map(
            lambda x: f'{x:.1f}' if isinstance(x, float) else str(x),
            sum(zip(data.keys(), data.values()), ())
        )
        return f"{len(data)} {' '.join(numbers)}"
    else:
        return "0"


def cal_poly(a: Dict, b: Dict) -> Dict:
    """
    计算两项多项式的和，结果保留1位小数
    :param a: 由{幂:系数}组成的Dict
    :param b: 由{幂:系数}组成的Dict
    """
    result = {}
    a_keys = list(a.keys())
    b_keys = list(b.keys())
    for e in set(a_keys + b_keys):
        if (e in a_keys) and (e in b_keys):
            c = a[e] + b[e]
            if c != 0:
                result[e] = c
        elif e in a_keys:
            if 0 != a[e]:
                result[e] = a[e]
        elif e in b_keys:
            if 0 != b[e]:
                result[e] = b[e]
    return result


def summit():
    print(rectify_data(cal_poly(rectify_str(input()), rectify_str(input()))), end='')


class Test(unittest.TestCase):
    def test_solution(self):
        testCases = [
            ["3 2 1.5 1 2.9 0 3.2", "2 1 2.4 0 3.2", "2 2 1.5 1 0.5"],
            ["0", "1 2 -1", "1 2 1"],  # 某个测试点的输出格式错误的测试数据
            ["1 1 -1.0", "1 2 0", "1 1 -1"],  # 极端情况1, 解决了, 但未过测试点1
            ["0", "1 1 0", "1 2 0"],  # 极端情况1, 解决了, 但未过测试点1
            # 极端情况2, 64位整型溢出, 解决了, 但未过测试点1
            ["1 18446744073709551616 1.0", "1 18446744073709551616 0.5", "1 18446744073709551616 0.5"],
            # 测试点1
            ["1 2 0.6", "1 1 0", "1 2 0.59"]
        ]

        for answer, a, b in testCases:
            result = rectify_data(cal_poly(rectify_str(a), rectify_str(b)))
            assert answer == result, f"{answer}, {result}"


if __name__ == '__main__':
    summit()
