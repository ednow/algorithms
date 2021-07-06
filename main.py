import unittest
import importlib
import os
import sys
import json
from io import StringIO
from utils.Exception import *

my_name = 'PTA'
my_spec = importlib.util.spec_from_loader(my_name, loader=None)
my_module = importlib.util.module_from_spec(my_spec)
# my_code = ""
with open(os.path.join("PTA", "PTA1061", "Dating.py"), "r", encoding="utf-8") as f:
    my_code = f.read()

with open(os.path.join("PTA", "PTA1061", "data.json"), encoding="utf-8", mode="r") as f:
    testCases = json.load(f)

exec(my_code, my_module.__dict__)
sys.modules['my_module'] = my_module

with open(os.path.join("PTA", "PTA1061", "config.json"), encoding="utf-8", mode="r") as f:
    config = json.load(f)

if any(list(config.values())):
    testCases = list(filter(lambda x: x["id"] == config["testCaseId"], testCases))

for idx, testCase in enumerate(testCases):
    a, answer = testCase["data"], testCase["answer"]
    sys.stdin = StringIO(a)
    f = StringIO()
    stdoutBackup = sys.stdout
    sys.stdout = f
    my_module.summit()
    assert answer == f.getvalue(), repr(f"error in id={testCase['id']},expected:{answer}, however:{f.getvalue()}")
    sys.stdout = stdoutBackup
    print(f"pass:id = {testCase['id']}")

