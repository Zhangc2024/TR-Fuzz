#include <iostream>
#include <string>
using namespace std;

int main() {
char destBuf[1024],srcBuf[1024];
string s1 = "This string is fair short.";
srcBuf[0]='\0';
strncpy(destBuf, &srcBuf[s1.find("abc")], 100); 

}



