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


class DataStream():
    def __init__(self):
        self.processors = []

    def register_processor(self, proc: DataProcessor) -> None:
        self.processors.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
        for element in stream:
            for proc_element in self.processors:
                if proc_element.validate(element):
                    proc_element.ingest(element)
                    break
            else:
                print(
                    f"DataStream error - Cant't "
                    f"process element in stream: {element}")

    def print_processors_stats(self) -> None:
        if not self.processors:
            print("No processor found, no data")
        for element in self.processors:
            print(f"{type(element).__name__}: total "
                  f"{element.count} items processed, "
                  f"remaining {len(element.array_data)} on processor")


if __name__ == "__main__":
    print("=== Code Nexus - Data Stream ===")
    print()

    print("Initialize Data Stream...")
    print("== DataStream statistics ==")

    data_stream = DataStream()
    data_stream.print_processors_stats()
    print("Register Numeric Processor")
    print()
    numeric_proc = NumericProcessor()

    list_stream = list(("Hello world", [3.14, -1, 2.71],
                        [{'log_level': 'WARNING', 'log_message':
                          'Telnet access! Use ssh instead'},
                         {'log_level': 'INFO',
                          'log_message': 'User wil is connected'}],
                        42, ["Hi", "five"]))
    print()
    print(f"Send first batch of data on stream: {list_stream}")
    data_stream.register_processor(numeric_proc)
    data_stream.process_stream(list_stream)
    print("== DataStream statistics ==")
    data_stream.print_processors_stats()
    print()

    text_proc = TextProcessor()
    log_proc = LogProcessor()
    data_stream.register_processor(log_proc)
    data_stream.register_processor(text_proc)

    print("Registering other data processors")
    print("Send the same batch again")
    print("== DataStream statistics ==")
    data_stream.process_stream(list_stream)
    data_stream.print_processors_stats()

    print()
    print("Consume some elements from the"
          " data processors: Numeric 3, Text 2, Log 1")
    for i in range(1):
        log_proc.output()
    for i in range(2):
        text_proc.output()
    for i in range(3):
        numeric_proc.output()
    print("== DataStream statistics ==")
    data_stream.print_processors_stats()
