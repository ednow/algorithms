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
    :param data: 由{幂:系数}组成的Dict
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


if __name__ == '__main__':
    summit()
