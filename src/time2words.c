#include "time2words.h"
#include "string.h"

static const char* const ONES[] = {
  "null",
  "en",
  "to",
  "tre",
  "fire",
  "fem",
  "seks",
  "syv",
  "åtte",
  "ni",
};

static const char* const TEENS[] ={
  "",
  "elleve",
  "tolv",
  "tretten",
  "fjorten",
  "femten",
  "seksten",
  "sytten",
  "atten",
  "nitten"
};

static const char* const TENS[] = {
  "",
  "ti\n",
  "tjue\n",
  "tretti\n",
  "førti\n",
  "femti\n",
  "seksti",
};

static const char* SEPERATOR = " ";

static size_t append_number(char* words, int num) {
  int tens_val = num / 10 % 10;
  int ones_val = num % 10;

  size_t len = 0;

  if (tens_val > 0) {
    if (tens_val == 1 && num != 10) {
      strcat(words, TEENS[ones_val]);
      return strlen(TEENS[ones_val]);
    }
    strcat(words, TENS[tens_val]);
    len += strlen(TENS[tens_val]);
  }

  if (ones_val > 0 || num == 0) {
    strcat(words, ONES[ones_val]);
    len += strlen(ONES[ones_val]);
  }
  return len;
}

static size_t append_string(char* buffer, const size_t length, const char* str) {
  strncat(buffer, str, length);

  size_t written = strlen(str);
  return (length > written) ? written : length;
}

void fuzzy_time_to_words(int hours, int minutes, char* words, size_t length) {
  int fuzzy_hours = hours;
  int fuzzy_minutes = minutes;

  size_t remaining = length;
  memset(words, 0, length);

  remaining -= append_number(words, fuzzy_hours);  
  remaining -= append_string(words, remaining, SEPERATOR);
  remaining -= append_number(words, fuzzy_minutes);
  
  
}
