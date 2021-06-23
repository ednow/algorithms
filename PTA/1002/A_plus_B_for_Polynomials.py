import unittest
from typing import Dict


def rectify_str(_str: str) -> Dict:
    """
    给定一个题目定义的多项式字符串,将其放到一个dict中{幂，系数}
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

    if len(data.keys()) > 0:
        return f"{len(data.keys())} {' '.join(map(str ,sum(zip(data.keys(), data.values()), ())))}"
    else:
        return "0"


def cal_poly(a: Dict, b: Dict):
    """
    计算两项多项式的和，结果保留两位小数
    :param a: 由{幂:系数}组成的Dict
    :param b: 由{幂:系数}组成的Dict
    """
    result = {}
    a_keys = list(a.keys())
    b_keys = list(b.keys())
    for e in range(max(a_keys + b_keys) + 1):
        if (e in a_keys) and (e in b_keys):
            c = round(a[e] + b[e], 1)
            if c != 0:
                result[e] = c
        elif e in a_keys:
            result[e] = a[e]
        elif e in b_keys:
            result[e] = b[e]
    return result


def summit():
    print(rectify_data(cal_poly(rectify_str(input()), rectify_str(input()))), end='')


class Test(unittest.TestCase):
    def test_solution(self):
        assert "3 2 1.5 1 2.9 0 3.2" == rectify_data(cal_poly(rectify_str("2 1 2.4 0 3.2"), rectify_str("2 2 1.5 1 0.5")))
        assert "0" == rectify_data(cal_poly(rectify_str("1 2 -1"), rectify_str("1 2 1")))


if __name__ == '__main__':
    summit()
