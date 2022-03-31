all:
	gcc app.c -o app
	gcc cntnr.c -o cntnr
	./app
	./cntnr ./app
	./cntnr ./app with some args
	python3 app.py
	./cntnr python3 app.py