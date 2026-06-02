from abc import ABC, abstractmethod
from typing import Any, Protocol


class ExportPlugin(Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...


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

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for proc in self.processors:
            values = []
            for i in range(nb):
                try:
                    values.append(proc.output())
                except IndexError as e:
                    print(f"Exception caught: {e}")
            plugin.process_output(values)


class CSVExport():
    def process_output(self, data: list[tuple[int, str]]) -> None:
        values = [element[1] for element in data]
        result = ", ".join(values)
        print("CSV Output:")
        print(result)


class JSONExport():
    def process_output(self, data: list[tuple[int, str]]) -> None:
        data_json = {}
        for element in data:
            key = 'item_'+str(element[0])
            data_json[key] = element[1]
        print("JSON Output:")
        print(data_json)


if __name__ == "__main__":
    print("=== Code Nexus - Data Pipeline ===")
    print()
    print("Initialize Data Stream...")
    print()
    print("== DataStream statistics ==")

    data_stream = DataStream()
    data_stream.print_processors_stats()
    print("Register Processor")
    print()
    numeric_proc = NumericProcessor()
    text_proc = TextProcessor()
    log_proc = LogProcessor()
    data_stream.register_processor(numeric_proc)
    data_stream.register_processor(text_proc)
    data_stream.register_processor(log_proc)
    list_stream = list(("Hello world", [3.14, -1, 2.71],
                        [{'log_level': 'WARNING', 'log_message':
                          'Telnet access! Use ssh instead'},
                         {'log_level': 'INFO',
                            'log_message': 'User wil is connected'}],
                        42, ["Hi", "five"]))
    print(f"Send first batch of data on stream: {list_stream}")
    data_stream.process_stream(list_stream)
    print("== DataStream statistics ==")
    data_stream.print_processors_stats()
    print()
    print("Send 3 processed data from each processor to a CSV plugin :")
    data_stream.output_pipeline(3, CSVExport())

    print()
    print("== DataStream statistics ==")
    data_stream.print_processors_stats()

    print()
    print()
    list_stream = list((21, ["I love AI", "LLMs are Wonderful",
                        "Stay healthy"],
                        [{'log_level': 'ERROR', 'log_message':
                          '500 server crash'},
                         {'log_level': 'NOTICE',
                            'log_message': 'Certificate expires in 10 days'}],
                        [32, 42, 64, 84, 128, 168], "World hello"))
    print(f"Send another batch of data: {list_stream}")
    data_stream.process_stream(list_stream)
    print("== DataStream statistics ==")
    data_stream.print_processors_stats()
    print()
    print("Send 5 processed data from each processor to a CSV plugin :")
    data_stream.output_pipeline(5, JSONExport())

    print()
    print("== DataStream statistics ==")
    data_stream.print_processors_stats()
