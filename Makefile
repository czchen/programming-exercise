.PHONY:=build

build:
	find . -name "*.rs" -execdir rustc {} \;

