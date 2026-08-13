ENV_NAME = Pacman
VENV_PATH=./$(ENV_NAME)/bin/python3
NAME_SCRIPT=pac-man.py
MAZE_GEN=lib

.SILENT:

all: run

install:
	python3 -m venv $(ENV_NAME)
	./$(ENV_NAME)/bin/pip3 -q install -r requirements.txt 

run: install
	PYGAME_HIDE_SUPPORT_PROMPT=hide $(VENV_PATH) $(NAME_SCRIPT) config.json
	rm -rf .env

debug: install
	$(VENV_PATH) -m pdb $(NAME_SCRIPT) config.json

clean:
	rm -rf .mypy_cache	*/.mypy_cache */*/.mypy_cache
	rm -rf __pycache__ */__pycache__ */*/__pycache__
	rm -rf build dist pac-man.spec
	rm -rf $(ENV_NAME)

lint: install
	./$(ENV_NAME)/bin/flake8 . --exclude $(ENV_NAME) --exclude $(MAZE_GEN)
	./$(ENV_NAME)/bin/mypy --exclude $(ENV_NAME) __exclude $(MAZE_GEN) . --warn-return-any --warn-unused-ignores --ignore-missing-imports --disallow-untyped-defs --check-untyped-defs

lint-strict: install
	./$(ENV_NAME)/bin/flake8 . --exclude $(ENV_NAME) --exclude $(MAZE_GEN) 
	./$(ENV_NAME)/bin/mypy --strict --exclude $(MAZE_GEN) . --ignore-missing-imports 

tests: install
	PYGAME_HIDE_SUPPORT_PROMPT=hide ./$(VENV_PATH) -m unittest discover -s Test -p "test_*.py"

build: install
	./$(ENV_NAME)/bin/pyinstaller --onefile pac-man.py

.PHONY: all install run debug clean lint lint-strict

