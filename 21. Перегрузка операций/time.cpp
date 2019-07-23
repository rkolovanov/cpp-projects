#include "time.h"

ui calc_seconds(ui s) {
	if (s >= 86400) {
		s = s - (86400 * (s / 86400));
	}

	return s;
}

time::time(void){
	seconds = 0;
}

time::time(ui s) {
	if (s >= 86400) {
		s = s - (86400 * (s / 86400));
	}

	seconds = s;
}

time::time(ui h, ui m, ui s) {
	if (h > 23 || m >= 60 || s >= 60) {
		ui secs = h * 60 * 60 + m * 60 + s;
		seconds = calc_seconds(secs);
		return;
	} 

	seconds = h * 60 * 60 + m * 60 + s;
}

short time::getTime(char c) {
	const char* time;
	short s, m, h;

	h = seconds / (60 * 60);
	m = seconds % (60 * 60) / 60;
	s = seconds % (60 * 60) % 60;

	if (c == 'h')
		return h;
	if (c == 'm')
		return m;
	if (c == 's')
		return s;
}

time time::operator+(const time& t) const {
	time result;

	result.seconds = calc_seconds(seconds + t.seconds);

	return result;
}

std::ostream& operator<<(std::ostream& os, time& t) {
	os << t.getTime('h') << ":" << t.getTime('m') << ":" << t.getTime('s');
	return os;
}

time::~time()
{
}
