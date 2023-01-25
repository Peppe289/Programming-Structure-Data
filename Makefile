#
# This Makefile is used for clear up
# dirty file of compiler
#

clear: assembly
	rm -rf *.s

assembly: compiler
	rm -rf *.su

compiler:
	rm -rf *.out