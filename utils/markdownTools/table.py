import pandas as pd
from io import StringIO


class TableReader:
    def __init__(self, string):
        self.table_string = string

    def to_pandas(self) -> pd.DataFrame:
        table = pd.read_csv(StringIO(self.table_string), sep="|")
        table.drop(table.index[[0]], axis=0, inplace=True)
        table.drop(table.columns[[0, len(table.columns) - 1]], axis=1, inplace=True)
        return table
