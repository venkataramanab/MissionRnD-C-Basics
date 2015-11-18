/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
#define NULL '\0'
int check_month(int month1, int month2) {
	if ((month1 > 0) && (month1 < 13) && (month2>0) && (month2 < 13)) {
		return 1;
	}
	else {
		return 0;
	}
}
int check_year(int year1, int year2) {
	if ((year1 > 0) && (year1 < 10000) && (year2>0) && (year2 < 10000)) {
		return 1;
	}
	else {
		return 0;
	}
}
int check_format(char a, char b) {
	if ((a == b) && (a == '-')) {
		return 1;
	}
	else {
		return 0;
	}
}
int check_day(int day1, int month1, int day2, int month2, int year1, int year2) {
	if ((((month1 == 1) || (month1 == 3) || (month1 == 5) || (month1 == 7) || (month1 == 8) || (month1 == 10) || (month1 == 12)) && (day1 <= 31) && (day1>0))
		|| (((month1 == 4) || (month1 == 6) || (month1 == 9) || (month1 == 11)) && (day1 <= 30) && (day1 >= 1))
		|| ((month1 == 2) && (year1 % 4 == 0) && (year1 % 100 != 0) && (day1 <= 29) && (day1>0))
		|| ((month1 == 2) && (year1 % 4 == 0) && (year1 % 100 == 0) && (year1 % 400 == 0) && (day1 <= 29) && (day1>0))
		|| ((month1 == 2) && (day1 < 2) && (day1>0))) {
		if ((((month2 == 1) || (month2 == 3) || (month2 == 5) || (month2 == 7) || (month2 == 8) || (month2 == 10) || (month2 == 12)) && (day2 <= 31) && (day2 > 0))
			|| (((month2 == 4) || (month2 == 6) || (month2 == 9) || (month2 == 11)) && (day2 <= 30) && (day2 >= 1))
			|| ((month2 == 2) && (year2 % 4 == 0) && (year2 % 100 != 0) && (day2 <= 29) && (day2 > 0))
			|| ((month2 == 2) && (year2 % 4 == 0) && (year2 % 100 == 0) && (year2 % 400 == 0) && (day2 <= 29) && (day2 > 0))
			|| ((month2 == 2) && (day2 <= 28) && (day2 > 0))) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}
int isOlder(char *dob1, char *dob2) {
	int i;
	int year1 = 0, year2 = 0;
	int month1 = 0, month2 = 0;
	int day1 = 0, day2 = 0;
	for (i = 0; dob1[i] != NULL; i++);
	int len1 = i;
	for (i = 0; dob2[i] != NULL; i++);
	int len2 = i;
	if ((len1 == len2) && (len1 == 10)) {
		if (check_format(dob1[2], dob2[5])) {
			for (i = 6; i < 10; i++) {
				if (((dob1[i] - '0') >= 0) && ((dob1[i] - '0') <= 9)) {
					year1 = year1 * 10 + (dob1[i] - '0');
				}
				else {
					return -1;
				}
			}
			for (i = 6; i < 10; i++) {
				if (((dob2[i] - '0') >= 0) && ((dob2[i] - '0') <= 9)) {
					year2 = year2 * 10 + (dob2[i] - '0');
				}
				else {
					return -1;
				}
			}
			if (check_year(year1, year2)) {
				for (i = 3; i < 5; i++) {
					if (((dob1[i] - '0') >= 0) && ((dob1[i] - '0') <= 9)) {
						month1 = month1 * 10 + (dob1[i] - '0');
					}
					else {
						return -1;
					}
				}
				for (i = 3; i < 5; i++) {
					if (((dob2[i] - '0') >= 0) && ((dob2[i] - '0') <= 9)) {
						month2 = month2 * 10 + (dob2[i] - '0');
					}
					else {
						return -1;
					}
				}
				if (check_month(month1, month2)) {
					for (i = 0; i < 2; i++) {
						if (((dob1[i] - '0') >= 0) && ((dob1[i] - '0') <= 9)) {
							day1 = day1 * 10 + (dob1[i] - '0');
						}
						else {
							return -1;
						}
					}
					for (i = 0; i < 2; i++) {
						if (((dob2[i] - '0') >= 0) && ((dob2[i] - '0') <= 9)) {
							day2 = day2 * 10 + (dob2[i] - '0');
						}
						else {
							return -1;
						}
					}
					if (check_day(day1, month1, day2, month2, year1, year2)) {
						if (year1 < year2) {
							return 1;
						}
						else if (year1>year2) {
							return 2;
						}
						else {
							if (month1 < month2) {
								return 1;
							}
							else if (month1>month2) {
								return 2;
							}
							else {
								if (day1 > day2) {
									return 2;
								}
								else if (day1 < day2) {
									return 1;
								}
								else {
									return 0;
								}
							}
						}
					}
					else {
						return -1;
					}
				}
				else {
					return -1;
				}
			}
			else {
				return -1;
			}
		}
	}
	else {
		return -1;
	}
}

