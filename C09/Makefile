MAKEFLAGS += --silent	# Silence makefile [Commented by default]

all : ex00 ex01 ex02

ex00:
	@make -C ./ex00
	@echo "\033[0;32m>>>>>>>>> Running btc\033[0m"
	@cd ./ex00 && ./btc input.txt
	@cd .. && echo

ex01:
	@make -C ./ex01
	@echo "\033[0;32m>>>>>>>>> Running RPN\033[0m"
	@./ex01/RPN
	@echo



ex02:
	@make -C ./ex02
	@echo "\033[0;32m>>>>>>>>> Running PmergeMe\033[0m"
	@./ex02/PmergeMe
	@echo


clean:
	@make -C ./ex00 clean
	@make -C ./ex01 clean
	@make -C ./ex02 clean

.PHONY: clean ex00 ex01 ex02
