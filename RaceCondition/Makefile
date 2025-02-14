atomic: fix_by_atomic.cpp
	g++-14 fix_by_atomic.cpp -o atomic

fix: fix_by_mutex.cpp
	g++-14 fix_by_mutex.cpp -o fix_race

rc: race_condition.cpp
	g++-14 race_condition.cpp -o rc

my: fix_by_myatomic.cpp
	g++-14 fix_by_myatomic.cpp -o myatomic

time_my: my
	time ./myatomic > my.txt

time_atomic: atomic
	time ./atomic > atomic.txt

time_fix: fix
	time ./fix_race > fix.txt

time_rc: rc
	time ./rc > rc.txt

clean:
	rm rc.txt fix.txt atomic.txt atomic fix_race rc myatomic my.txt