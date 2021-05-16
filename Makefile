# MacTex distribution http://www.tug.org/mactex/

all: phraseology 23322 121pw

23322: C150_23322/preflight.dvi

121pw: PA28-151_121PW/preflight.dvi PA28-151_121PW/flight.dvi PA28-151_121PW/maneuvers.dvi

phraseology: phraseology/phraseology.dvi

%.dvi: %.tex
	latex  -output-directory=`dirname $?` $?

clean:
	find . -name '*.aux' -or -name '*.dvi' -or -name '*.log' | xargs rm