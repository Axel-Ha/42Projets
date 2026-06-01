from abc import ABC, abstractmethod
from typing import List,Any,Dict


class DataProcessor(ABC):
    def __init__(self):
        self.array_data = []
        self.count = 0
    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass
    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass
    def output(self) -> tuple[int, str]:
        return self.array_data.pop(0)


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if(isinstance(data,list)):
           all(isinstance(value,int) or isinstance(value,float) for value in data)
        elif isinstance(data,int) or isinstance(data,float):
            return True
        else:
            return False

    def ingest(self, data: List[int | float]) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        if isinstance(data,list):
            for value in data:
                self.array_data.append((self.count, str(value)))
                self.count += 1
        else:
            self.array_data.append((self.count, str(data)))
            self.count += 1


class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if(isinstance(data,list)):
           all(isinstance(value,str) for value in data)
        elif isinstance(data,str):
            return True
        else:
            return False

    def ingest(self, data: List[str]) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")
        if isinstance(data,list):
            for value in data:
                self.array_data.append((self.count, str(value)))
                self.count += 1
        else:
            self.array_data.append((self.count, str(data)))
            self.count += 1


class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if(isinstance(data,list)):
           all(isinstance(value,Dict[str,str])for value in data)
        elif isinstance(data,int) or isinstance(data,float):
            return True
        else:
            return False

    def ingest(self, data: List[Dict[str, str]]) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")
        if isinstance(data, list):
            for data_dict in data:
                for key, value in data_dict.items():
                    self.array_data.append((self.count,key,value))
        else:
            for key, value in data.items():
                self.array_data.append((self.count,key,value))


if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===")
    print()

    print("Testing Numeric Processor")
    numeric = NumericProcessor()
    print(f"Trying to validate input 42: {numeric.validate(42)}")
    print(f"Trying to validate input Hello: {numeric.validate("Hello")}")

