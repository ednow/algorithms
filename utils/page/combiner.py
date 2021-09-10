from __future__ import annotations
from typing import List, Iterable
import abc
import re


class Data:
    def __init__(self, data="", key=0):
        self.key: int = key
        self.data: str = data

    def set_key(self, key: int):
        self.key = key
        return self

    def set_data(self, data: str):
        self.data = data

    def get_data(self):
        return self.data

    def get_key(self):
        return self.key

    def preprocess(self, preprocessor: AbstractPreprocess):
        """
        使用一个预处理函数对自己进行预处理
        :param preprocessor: 一个preprocessor
        """
        preprocessor.do_preprocess(self)
        return self

    def __iadd__(self, other: Data):
        self.set_data(self.get_data() + other.get_data())
        return self


class AbstractPreprocess(metaclass=abc.ABCMeta):
    @abc.abstractmethod
    def do_preprocess(self, data: Data) -> Data:
        pass


class Replace(AbstractPreprocess):
    """
    使用re来替换
    """
    def __init__(self, toBeReplace: str, replaceTo: str):
        self.toBeReplace = toBeReplace
        self.replaceTo = replaceTo

    def do_preprocess(self, data: Data):
        data.set_data(re.sub(self.toBeReplace, self.replaceTo, data.get_data(), flags=re.DOTALL))
        return data

    def __str__(self):
        return f"<Replace (toBeReplace: {self.toBeReplace}, replaceTo: {self.replaceTo})>"


class Prefix(AbstractPreprocess):
    """添加前缀"""
    def __init__(self, prefix: str):
        self.prefix = prefix

    def do_preprocess(self, data: Data):
        data.set_data(self.prefix + data.get_data())
        return data

    def __str__(self):
        return f"<Prefix (prefix: {self.prefix})>"


class Suffix(AbstractPreprocess):
    """添加后缀"""
    def __init__(self, suffix: str):
        self.suffix = suffix

    def do_preprocess(self, data: Data):
        data.set_data(data.get_data() + self.suffix)
        return data

    def __str__(self):
        return f"<Suffix (suffix: {self.suffix})>"


class Chain:
    """
    可以录制一系列动作并重现
    """
    def __init__(self, *args):
        self.preprocessors: Iterable[AbstractPreprocess] = args

    def __call__(self, data: Data):
        for preprocessor in self.preprocessors:
            preprocessor.do_preprocess(data)
        return data


class Configuration:
    """
    实例配置类
    """
    def __init__(self):
        self.joiner = "\n"
        self.preprocessors: List[AbstractPreprocess] = []
        self.postprocessors: List[AbstractPreprocess] = []

    def set_joiner(self, joiner: str):
        self.joiner = joiner

    def get_joiner(self) -> str:
        return self.joiner

    def add_preprocessor(self, preprocessor):
        """对每一个加进去的string都做处理"""
        self.preprocessors.append(preprocessor)
        return self

    def add_post_processor(self, preprocessor):
        """合并之后处理"""
        self.postprocessors.append(preprocessor)
        return self


class Combiner:
    def __init__(self, configuration: Configuration = None):
        self.data: List[Data] = []
        if configuration is None:
            self.configuration = Configuration()
        else:
            self.configuration = configuration

    def set_configuration(self, configuration: Configuration):
        self.configuration = configuration

    def add_next_string(self, string: str) -> Data:
        """
        添加下一个需要合并内容
        :param string: 内容
        """
        data = Data(string)
        self.data.append(data)
        return data

    def combine(self) -> str:
        """
        合并现在的数据
        """
        joiner = self.configuration.get_joiner()

        # 做预处理
        for preprocess in self.configuration.preprocessors:
            for data in self.data:
                preprocess.do_preprocess(data)

        # 合并
        combined_str = joiner.join([i.data for i in sorted(self.data, key=lambda x:x.key)])
        result = Data(combined_str)

        # 做后处理
        for preprocess in self.configuration.postprocessors:
            preprocess.do_preprocess(result)

        return result.get_data()
