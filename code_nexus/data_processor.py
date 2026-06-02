from abc import ABC, abstractmethod
from typing import Any


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
        if (isinstance(data, list)):
            return all(isinstance(value, (int, float)) for value in data)
        elif isinstance(data, (int, float)):
            return True
        else:
            return False

    def ingest(self, data: Any) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        if isinstance(data, list):
            for value in data:
                self.array_data.append((self.count, str(value)))
                self.count += 1
        else:
            self.array_data.append((self.count, str(data)))
            self.count += 1


class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if (isinstance(data, list)):
            return all(isinstance(value, str) for value in data)
        elif isinstance(data, str):
            return True
        else:
            return False

    def ingest(self, data: Any) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")
        if isinstance(data, list):
            for value in data:
                self.array_data.append((self.count, str(value)))
                self.count += 1
        else:
            self.array_data.append((self.count, str(data)))
            self.count += 1


class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, list):
            return all(
                isinstance(d, dict) and
                all(isinstance(key, str) and isinstance(value, str)
                    for key, value in d.items())
                for d in data)
        elif isinstance(data, dict):
            return all(isinstance(key, str) and isinstance(value, str)
                       for key, value in data.items())
        else:
            return False

    def ingest(self, data: Any) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")
        if isinstance(data, list):
            for data_dict in data:
                log_message = ": ".join(data_dict.values())
                self.array_data.append((self.count, log_message))
                self.count += 1
        else:
            log_message = ": ".join(data.values())
            self.array_data.append((self.count, log_message))
            self.count += 1


if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===")
    print()

    print("Testing Numeric Processor")
    numeric = NumericProcessor()
    print(f"Trying to validate input '42': {numeric.validate(42)}")
    print(f"Trying to validate input 'Hello': {numeric.validate("Hello")}")

    print("Test invalid ingestion of string 'foo' without prior validation :")
    try:
        numeric.ingest("foo")
    except ValueError as e:
        print(f"Got exception: {e}")
    numeric_list = list((1, 2, 3, 4, 5))
    print(f"Processing data: {numeric_list}")
    numeric.ingest(numeric_list)
    print("Extracting 3 values...")
    for i in range(3):
        try:
            key, value = numeric.output()
            print(f"Numeric value {key}: {value}")
        except ValueError as e:
            print(f"Got exception: {e}")
            break

    print("Testing Text Processor")
    text = TextProcessor()
    print(f"Trying to validate input '42': {numeric.validate(42)}")

    # text_list = list(('Hello','Nexus','World'))
    text_list = ['Hello', 'Nexus', 'World']
    print(f"Processing data: {text_list}")
    text.ingest(text_list)
    key, value = text.output()
    print("Extracting 1 value...")
    print(f"Numeric value {key}: {value}")

    print("Testing Log Processor")
    log = LogProcessor()
    print(f"Trying to validate input 'Hello': {numeric.validate(42)}")
    log_list = [{'log_level': 'NOTICE', 'log_message':
                'Connection to server', },
                {'log_level': 'ERROR', 'log_message':
                'Unauthorized access!!'}]
    print(f"Processing data: {log_list}")
    log.ingest(log_list)
    print("Extracting 2 values...")
    for i in range(2):
        try:
            key, value = log.output()
            print(f"log value {key}: {value}")
        except ValueError as e:
            print(f"Got exception: {e}")
            break
