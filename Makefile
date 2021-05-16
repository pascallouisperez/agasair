# MacTex distribution http://www.tug.org/mactex/

all: phraseology 121pw

121pw: preflight.dvi flight.dvi maneuvers.dvi

phraseology: phraseology.dvi

%.dvi: %.tex
	latex $?

clean:
	find . -name '*.aux' -or -name '*.dvi' -or -name '*.log' | xargs rm
