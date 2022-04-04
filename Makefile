.PHONY: test clean

all: build test

build:
	gcc tests/app.c -o app
	gcc cntnr.c -o cntnr

test:
	pytest

clean:
	rm app cntnr
