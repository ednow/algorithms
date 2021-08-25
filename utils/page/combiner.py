from typing import List
import abc
import re

class Data:
    def __init__(self, data="", key=0):
        self.key: int = key
        self.data: str = data

    def set_key(self, key: int):
        self.key = key

    def set_data(self, data: str):
        self.data = data

    def get_data(self):
        return self.data

    def get_key(self):
        return self.key


class AbstractPreprocess(metaclass=abc.ABCMeta):
    @abc.abstractmethod
    def do_preprocess(self, data: Data):
        pass


class Replace(AbstractPreprocess):
    def __init__(self, toBeReplace: str, replaceTo: str):
        self.toBeReplace = toBeReplace
        self.replaceTo = replaceTo

    def do_preprocess(self, data: Data):
        data.set_data(re.sub(self.toBeReplace, self.replaceTo, data.get_data()))

    def __str__(self):
        return f"<Replace (toBeReplace: {self.toBeReplace}, replaceTo: {self.replaceTo})>"


class Configuration:
    def __init__(self):
        self.joiner = "\n"
        self.preprocessors: List[AbstractPreprocess] = []

    def set_joiner(self, joiner: str):
        self.joiner = joiner

    def get_joiner(self) -> str:
        return self.joiner

    def add_preprocessor(self, preprocessor):
        self.preprocessors.append(preprocessor)


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

        return joiner.join([i.data for i in sorted(self.data, key=lambda x:x.key)])