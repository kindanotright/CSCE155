//THIS DID NOT PASS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
#include "rss.h"
 
Rss * createEmptyRss() {
  return createRss("", "", 0, "");
}
 
Rss * createRss(const char * title, const char * link, const char * date, const char * description) {
  Rss *feed = (Rss *)malloc(sizeof(Rss) * 1);
 
  feed->title = (char *)malloc(sizeof(char) * (strlen(title) + 1));
  strcpy(feed->title, title);
 
  feed->link = (char *)malloc(sizeof(char) * (strlen(link) + 1));
  strcpy(feed->link, link);
 
  feed->description = (char *)malloc(sizeof(char) * (strlen(description) + 1));
  strcpy(feed->description, description);
 
  feed->date = (char *)malloc(sizeof(char) * (strlen(date) + 1));
  strcpy(feed->date, date);
 
  return feed;
}
 
void initRss(Rss *feed, const char* title,
                        const char* link,
                        const char* date,
                        const char* description) {
  feed->title = (char*)malloc(sizeof(char) * (strlen(title) +1));
  strcpy(feed->title, title);
 
  feed->link = (char *)malloc(sizeof(char) * (strlen(link) + 1));
  strcpy(feed->link, link);
 
  feed->date = (char *)malloc(sizeof(char) * (strlen(date) + 1));
  strcpy(feed->date, date);
 
  feed->description = (char *)malloc(sizeof(char) * (strlen(description) + 1));
  strcpy(feed->description, description);
 
  return;
}
 
char *rssToString(const Rss *feed) {
  if (feed == NULL) {
    char *result = (char*)malloc(sizeof(char) * 7);
    strcpy(result, "(null)");
    return result;
  }
  int n = strlen(feed->title) + strlen(feed->link) + strlen(feed->description) + 8 +10 +
  (2 + 2 + 2 + 1) + 1;
 
  char *resultStr = (char *)malloc(sizeof(char) * n);
 
  sprintf(resultStr, "%s, %s, %s, %s", feed->title, feed->link, feed->description, feed->date);
 
  return resultStr;
}
 
void printRss(const Rss * feed) {
  char *str = rssToString(feed);
  printf("%s\n", str);
  free(str);
  return;
}
