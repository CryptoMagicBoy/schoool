all: clean log0 log1 log2 log3 log4

log0:
	sudo goaccess ../04/log_0.log --log-format=COMBINED -o stats0.html
    
log1:
	sudo goaccess ../04/log_1.log --log-format=COMBINED -o stats1.html

log2:
	sudo goaccess ../04/log_2.log --log-format=COMBINED -o stats2.html
    
log3:
	sudo goaccess ../04/log_3.log --log-format=COMBINED -o stats3.html
    
log4:
	sudo goaccess ../04/log_4.log --log-format=COMBINED -o stats4.html
    
clean:
	rm -rf *.html
