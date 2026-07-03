
VENV_PATH=./venv/bin/python3

install:
	python -m venv venv
	./venv/bin/pip install flake8 mypy build
run: 
	$(VENV_PATH) a_maze_zing.py config.txt

debug:
	$(VENV_PATH) -m pdb a_maze_zing.py config.txt

clean:
	rm -rf .mypy_cache	
	rm -rf __pycache__

lint: 
	./venv/bin/flake8 .
	./venv/bin/mypy . --warn-return-any --warn-unused-ignores --ignore-missing-imports --disallow-untyped-defs --check-untyped-defs

lint-strict:
	./venv/bin/flake8 .
	./venv/bin/mypy --strict .

.PHONY: install run debug clean lint lint-strict