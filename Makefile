#
# This Makefile is used for clear up
# dirty file of compiler
#

clear: assembly
	rm -rf *.s
	rm -rf src/*.s

assembly: compiler
	rm -rf *.su
	rm -rf src/*.su

compiler:
	rm -rf *.out
	rm -rf src/*.out